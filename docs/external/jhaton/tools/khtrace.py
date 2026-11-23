"""Deterministic writer for the repository-owned KHTRACE 1.0 format."""

from __future__ import annotations

import os
import struct
import zlib
from enum import IntEnum
from pathlib import Path


_HEADER_SIZE = 32
_MAX_FILE_SIZE = 64 * 1024 * 1024
_MAX_PAYLOAD_SIZE = 16 * 1024 * 1024
_MAX_RECORD_COUNT = 1_000_000
_VU_MEMORY_SIZE = 16 * 1024
_LOCAL_MEMORY_SIZE = 4 * 1024 * 1024


class TraceRecordType(IntEnum):
    """Record identifiers defined by KHTRACE 1.0."""

    PROVENANCE = 0
    FRAME_INFO = 1
    REFERENCE_IMAGE = 2
    GS_REGISTER_WRITE = 0x10
    GIF_PACKET = 0x11
    VIF_STREAM = 0x12
    VU_PROGRAM = 0x13
    VU_STATE = 0x14
    LOCAL_MEMORY = 0x15


def _require_u32(value: int, name: str) -> int:
    if not isinstance(value, int) or isinstance(value, bool):
        raise TypeError(f"{name} must be an integer")
    if not 0 <= value <= 0xFFFFFFFF:
        raise ValueError(f"{name} must fit in an unsigned 32-bit integer")
    return value


def _require_u64(value: int, name: str) -> int:
    if not isinstance(value, int) or isinstance(value, bool):
        raise TypeError(f"{name} must be an integer")
    if not 0 <= value <= 0xFFFFFFFFFFFFFFFF:
        raise ValueError(f"{name} must fit in an unsigned 64-bit integer")
    return value


def _payload_bytes(value: bytes | bytearray | memoryview, name: str = "payload") -> bytes:
    if not isinstance(value, (bytes, bytearray, memoryview)):
        raise TypeError(f"{name} must be bytes-like")
    try:
        return bytes(value)
    except (TypeError, ValueError) as error:
        raise TypeError(f"{name} must be a contiguous byte sequence") from error


def _fixed_text(value: str, size: int, name: str) -> bytes:
    if not isinstance(value, str):
        raise TypeError(f"{name} must be a string")
    try:
        encoded = value.encode("ascii")
    except UnicodeEncodeError as error:
        raise ValueError(f"{name} must contain only printable ASCII") from error
    if not encoded or any(byte < 0x20 or byte > 0x7E for byte in encoded):
        raise ValueError(f"{name} must be nonempty printable ASCII")
    if len(encoded) >= size:
        raise ValueError(f"{name} must be at most {size - 1} ASCII bytes")
    return encoded + bytes(size - len(encoded))


def _is_canonical_fixed_text(value: bytes) -> bool:
    try:
        terminator = value.index(0)
    except ValueError:
        return False
    return (
        terminator != 0
        and all(0x20 <= byte <= 0x7E for byte in value[:terminator])
        and not any(value[terminator:])
    )


def _build_provenance(
    game: str,
    scenario: str,
    capture_tool: str,
    frame_index: int,
) -> bytes:
    game_field = _fixed_text(game, 16, "game")
    scenario_field = _fixed_text(scenario, 48, "scenario")
    capture_tool_field = _fixed_text(capture_tool, 32, "capture_tool")
    return b"".join(
        (
            game_field,
            scenario_field,
            capture_tool_field,
            struct.pack("<I", _require_u32(frame_index, "frame_index")),
            bytes(28),
        )
    )


def _build_frame_info(width: int, height: int) -> bytes:
    width = _require_u32(width, "width")
    height = _require_u32(height, "height")
    if not 1 <= width <= 2048 or not 1 <= height <= 2048:
        raise ValueError("width and height must each be in the range 1..2048")
    return struct.pack("<IIII", width, height, 0, 0)


def build_vu_program(
    upload_offset: int,
    code: bytes | bytearray | memoryview,
) -> bytes:
    """Build a VU micro-memory upload payload."""

    upload_offset = _require_u32(upload_offset, "upload_offset")
    code_bytes = _payload_bytes(code, "code")
    size = len(code_bytes)
    if (
        size < 8
        or size > _VU_MEMORY_SIZE
        or size % 8 != 0
        or upload_offset % 8 != 0
        or upload_offset > _VU_MEMORY_SIZE - size
    ):
        raise ValueError("VU program upload range is invalid")
    return struct.pack("<II", upload_offset, size) + code_bytes


def build_local_memory(
    offset: int,
    data: bytes | bytearray | memoryview,
) -> bytes:
    """Build a GS local-memory upload payload."""

    offset = _require_u32(offset, "offset")
    data_bytes = _payload_bytes(data, "data")
    size = len(data_bytes)
    if (
        size < 32
        or size > _LOCAL_MEMORY_SIZE
        or size % 32 != 0
        or offset % 32 != 0
        or offset > _LOCAL_MEMORY_SIZE - size
    ):
        raise ValueError("local-memory upload range is invalid")
    return struct.pack("<II", offset, size) + data_bytes


def build_gs_register_write(register: int, value: int) -> bytes:
    """Build one canonical 16-byte GS register-write entry."""

    if not isinstance(register, int) or isinstance(register, bool):
        raise TypeError("register must be an integer")
    if not 0 <= register <= 0xFF:
        raise ValueError("register must fit in an unsigned 8-bit integer")
    return struct.pack("<B7xQ", register, _require_u64(value, "value"))


def _coerce_record_type(record_type: TraceRecordType | int) -> TraceRecordType:
    if not isinstance(record_type, int) or isinstance(record_type, bool):
        raise TypeError("record_type must be a TraceRecordType or integer")
    try:
        return TraceRecordType(record_type)
    except ValueError as error:
        raise ValueError(f"unknown trace record type: {record_type!r}") from error


def _validate_payload(
    record_type: TraceRecordType,
    payload: bytes,
    width: int,
    height: int,
) -> None:
    size = len(payload)
    if size > _MAX_PAYLOAD_SIZE:
        raise ValueError("record payload exceeds 16 MiB")

    if record_type is TraceRecordType.PROVENANCE:
        if size != 128:
            raise ValueError("Provenance payload must be 128 bytes")
        if not _is_canonical_fixed_text(payload[0:16]):
            raise ValueError("invalid Provenance game field")
        if not _is_canonical_fixed_text(payload[16:64]):
            raise ValueError("invalid Provenance scenario field")
        if not _is_canonical_fixed_text(payload[64:96]):
            raise ValueError("invalid Provenance capture-tool field")
        if any(payload[100:128]):
            raise ValueError("nonzero Provenance reserved bytes")
    elif record_type is TraceRecordType.FRAME_INFO:
        if size != 16:
            raise ValueError("FrameInfo payload must be 16 bytes")
        payload_width, payload_height, pixel_format, reserved = struct.unpack("<IIII", payload)
        if not 1 <= payload_width <= 2048 or not 1 <= payload_height <= 2048:
            raise ValueError("FrameInfo dimensions out of range")
        if pixel_format != 0:
            raise ValueError("unsupported FrameInfo pixel format")
        if reserved != 0:
            raise ValueError("nonzero FrameInfo reserved field")
    elif record_type is TraceRecordType.REFERENCE_IMAGE:
        if size != width * height * 4:
            raise ValueError("ReferenceImage size does not match FrameInfo")
    elif record_type is TraceRecordType.GS_REGISTER_WRITE:
        if size == 0 or size % 16 != 0:
            raise ValueError("GS register writes must be nonempty 16-byte entries")
        for entry_offset in range(0, size, 16):
            if any(payload[entry_offset + 1 : entry_offset + 8]):
                raise ValueError(
                    f"nonzero GS register entry padding at payload offset {entry_offset + 1}"
                )
    elif record_type is TraceRecordType.GIF_PACKET:
        if size == 0 or size % 16 != 0:
            raise ValueError("GIF packet must be nonempty and 16-byte aligned")
    elif record_type is TraceRecordType.VIF_STREAM:
        if size == 0 or size % 4 != 0:
            raise ValueError("VIF stream must be nonempty and 4-byte aligned")
    elif record_type is TraceRecordType.VU_PROGRAM:
        if size < 8:
            raise ValueError("VU program header is truncated")
        offset, code_size = struct.unpack_from("<II", payload)
        if code_size != size - 8:
            raise ValueError("VU program code size mismatch")
        if (
            code_size < 8
            or code_size > _VU_MEMORY_SIZE
            or code_size % 8 != 0
            or offset % 8 != 0
            or offset > _VU_MEMORY_SIZE - code_size
        ):
            raise ValueError("VU program upload range is invalid")
    elif record_type is TraceRecordType.VU_STATE:
        if size != 672:
            raise ValueError("VU state payload must be 672 bytes")
    elif record_type is TraceRecordType.LOCAL_MEMORY:
        if size < 8:
            raise ValueError("local-memory header is truncated")
        offset, data_size = struct.unpack_from("<II", payload)
        if data_size != size - 8:
            raise ValueError("local-memory data size mismatch")
        if (
            data_size < 32
            or data_size > _LOCAL_MEMORY_SIZE
            or data_size % 32 != 0
            or offset % 32 != 0
            or offset > _LOCAL_MEMORY_SIZE - data_size
        ):
            raise ValueError("local-memory upload range is invalid")


class TraceWriter:
    """Accumulate and serialize a single KHTRACE 1.0 capture."""

    def __init__(
        self,
        game: str,
        scenario: str,
        capture_tool: str,
        frame_index: int,
        width: int,
        height: int,
    ) -> None:
        provenance = _build_provenance(game, scenario, capture_tool, frame_index)
        frame_info = _build_frame_info(width, height)
        self._width = width
        self._height = height
        self._records: list[tuple[TraceRecordType, bytes]] = [
            (TraceRecordType.PROVENANCE, provenance),
            (TraceRecordType.FRAME_INFO, frame_info),
        ]
        self._reference_set = False

    def add_record(
        self,
        record_type: TraceRecordType | int,
        payload: bytes | bytearray | memoryview,
    ) -> None:
        """Append a validated non-structural record."""

        checked_type = _coerce_record_type(record_type)
        if checked_type in (TraceRecordType.PROVENANCE, TraceRecordType.FRAME_INFO):
            raise ValueError(f"{checked_type.name} is emitted automatically")
        if checked_type is TraceRecordType.REFERENCE_IMAGE:
            raise ValueError("use set_reference_rgba() to emit ReferenceImage")
        if len(self._records) >= _MAX_RECORD_COUNT:
            raise ValueError("record count exceeds limit")
        checked_payload = _payload_bytes(payload)
        _validate_payload(checked_type, checked_payload, self._width, self._height)
        self._records.append((checked_type, checked_payload))

    def set_reference_rgba(self, data: bytes | bytearray | memoryview) -> None:
        """Append the frame's required RGBA8 reference image exactly once."""

        if self._reference_set:
            raise ValueError("ReferenceImage has already been set")
        checked_payload = _payload_bytes(data, "data")
        _validate_payload(
            TraceRecordType.REFERENCE_IMAGE,
            checked_payload,
            self._width,
            self._height,
        )
        if len(self._records) >= _MAX_RECORD_COUNT:
            raise ValueError("record count exceeds limit")
        self._records.append((TraceRecordType.REFERENCE_IMAGE, checked_payload))
        self._reference_set = True

    def build(self) -> bytes:
        """Return the complete immutable KHTRACE byte stream."""

        if not self._reference_set:
            raise ValueError("missing required ReferenceImage record")
        if len(self._records) > _MAX_RECORD_COUNT:
            raise ValueError("record count exceeds limit")

        file_size = _HEADER_SIZE
        reference_count = 0
        for index, (record_type, payload) in enumerate(self._records):
            if index == 0 and record_type is not TraceRecordType.PROVENANCE:
                raise ValueError("record 0 must be Provenance")
            if index == 1 and record_type is not TraceRecordType.FRAME_INFO:
                raise ValueError("record 1 must be FrameInfo")
            _validate_payload(record_type, payload, self._width, self._height)
            if record_type is TraceRecordType.REFERENCE_IMAGE:
                reference_count += 1
            record_size = 16 + len(payload)
            file_size += record_size + (-record_size % 8)
            if file_size > _MAX_FILE_SIZE:
                raise ValueError("trace exceeds 64 MiB limit")
        if reference_count != 1:
            raise ValueError("trace must contain exactly one ReferenceImage record")

        output = bytearray(
            struct.pack(
                "<8sHBBHHIIII",
                b"KHTRACE\0",
                0x1A2B,
                1,
                0,
                _HEADER_SIZE,
                0,
                file_size,
                len(self._records),
                0,
                0,
            )
        )
        for record_type, payload in self._records:
            output.extend(
                struct.pack(
                    "<IIII",
                    int(record_type),
                    len(payload),
                    zlib.crc32(payload) & 0xFFFFFFFF,
                    0,
                )
            )
            output.extend(payload)
            output.extend(bytes(-len(output) % 8))

        file_crc = zlib.crc32(output) & 0xFFFFFFFF
        struct.pack_into("<I", output, 24, file_crc)
        return bytes(output)


def write_trace(path: str | os.PathLike[str], writer: TraceWriter) -> None:
    """Build and write a complete trace to *path*."""

    if not isinstance(writer, TraceWriter):
        raise TypeError("writer must be a TraceWriter")
    Path(path).write_bytes(writer.build())


__all__ = [
    "TraceRecordType",
    "TraceWriter",
    "build_gs_register_write",
    "build_local_memory",
    "build_vu_program",
    "write_trace",
]
