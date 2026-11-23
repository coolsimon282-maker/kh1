#!/usr/bin/env python3
"""Standard-library client for PCSX2's PINE socket protocol."""

from __future__ import annotations

import argparse
import os
from pathlib import Path
import socket
import struct
import sys
from typing import Optional, Sequence, Union


MAX_REQUEST_SIZE = 650_000
MAX_RESPONSE_SIZE = 450_000
FALLBACK_SOCKET_PATH = "/tmp/pcsx2.sock"

READ8 = 0x00
READ16 = 0x01
READ32 = 0x02
READ64 = 0x03
WRITE8 = 0x04
WRITE16 = 0x05
WRITE32 = 0x06
WRITE64 = 0x07
VERSION = 0x08
SAVE_STATE = 0x09
LOAD_STATE = 0x0A
TITLE = 0x0B
GAME_ID = 0x0C
UUID = 0x0D
GAME_VERSION = 0x0E
STATUS = 0x0F

_SUCCESS = 0x00
_FAILURE = 0xFF
_UINT32_LIMIT = 1 << 32
_READ_COMMANDS = {1: READ8, 2: READ16, 4: READ32, 8: READ64}
_WRITE_COMMANDS = {1: WRITE8, 2: WRITE16, 4: WRITE32, 8: WRITE64}

PathLike = Union[str, os.PathLike[str]]


class PineError(RuntimeError):
    """A PINE connection, framing, command, or result error."""


def _default_socket_path() -> str:
    runtime_dir = os.environ.get("XDG_RUNTIME_DIR")
    if runtime_dir:
        return os.path.join(runtime_dir, "pcsx2.sock")
    return FALLBACK_SOCKET_PATH


def _check_uint(name: str, value: int, bits: int) -> None:
    if not isinstance(value, int) or isinstance(value, bool):
        raise ValueError(f"{name} must be an integer")
    if value < 0 or value >= (1 << bits):
        raise ValueError(f"{name} must fit in an unsigned {bits}-bit integer")


def _check_guest_range(address: int, size: int) -> None:
    _check_uint("address", address, 32)
    if not isinstance(size, int) or isinstance(size, bool):
        raise ValueError("size must be an integer")
    if size < 0:
        raise ValueError("size must not be negative")
    if size > _UINT32_LIMIT - address:
        raise ValueError(
            f"guest range 0x{address:08x}+0x{size:x} exceeds 32-bit address space"
        )


class PineClient:
    """Persistent PINE client; enter the context or call ``connect`` first."""

    def __init__(self, socket_path: Optional[PathLike] = None, timeout: Optional[float] = 5.0):
        self.socket_path = os.fspath(socket_path) if socket_path is not None else _default_socket_path()
        self.timeout = timeout
        self._socket: Optional[socket.socket] = None

    def __enter__(self) -> "PineClient":
        return self.connect()

    def __exit__(self, exc_type: object, exc: object, traceback: object) -> None:
        self.close()

    def connect(self) -> "PineClient":
        """Open a new connection, replacing any existing connection."""
        self.close()
        connection = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        try:
            connection.settimeout(self.timeout)
            connection.connect(self.socket_path)
        except (OSError, TypeError, ValueError) as error:
            connection.close()
            raise PineError(f"could not connect to PINE socket {self.socket_path!r}: {error}") from error
        self._socket = connection
        return self

    def close(self) -> None:
        connection, self._socket = self._socket, None
        if connection is not None:
            try:
                connection.close()
            except OSError:
                pass

    def _connected_socket(self) -> socket.socket:
        if self._socket is None:
            raise PineError("PINE socket is closed; call connect() explicitly")
        return self._socket

    def _transport_error(self, message: str, error: Optional[BaseException] = None) -> PineError:
        self.close()
        if error is None:
            return PineError(message)
        return PineError(f"{message}: {error}")

    def _recv_exact(self, size: int, part: str) -> bytes:
        connection = self._connected_socket()
        data = bytearray(size)
        view = memoryview(data)
        offset = 0
        while offset < size:
            try:
                received = connection.recv_into(view[offset:])
            except OSError as error:
                raise self._transport_error(
                    f"PINE {part} receive failed at offset {offset} of {size}", error
                ) from error
            if received == 0:
                raise self._transport_error(
                    f"PINE socket closed during {part} at offset {offset} of {size}"
                )
            offset += received
        return bytes(data)

    def _exchange(
        self,
        commands: bytes,
        *,
        command_name: str,
        expected_result_size: Optional[int],
    ) -> bytes:
        connection = self._connected_socket()
        request_size = 4 + len(commands)
        if not commands:
            raise PineError("refusing to send an empty PINE command packet")
        if request_size > MAX_REQUEST_SIZE:
            raise PineError(
                f"PINE {command_name} request is {request_size} bytes; maximum is {MAX_REQUEST_SIZE}"
            )
        request = struct.pack("<I", request_size) + commands
        try:
            connection.sendall(request)
        except OSError as error:
            raise self._transport_error(f"PINE {command_name} send failed", error) from error

        header = self._recv_exact(4, f"{command_name} response header")
        response_size = struct.unpack("<I", header)[0]
        if response_size < 5:
            raise self._transport_error(
                f"malformed PINE {command_name} response length {response_size}; minimum is 5"
            )
        if response_size > MAX_RESPONSE_SIZE:
            raise self._transport_error(
                f"oversized PINE {command_name} response length {response_size}; "
                f"maximum is {MAX_RESPONSE_SIZE}"
            )

        body = self._recv_exact(response_size - 4, f"{command_name} response body")
        status = body[0]
        result = body[1:]
        if status == _FAILURE:
            raise PineError(f"PINE {command_name} failed with status 0xff")
        if status != _SUCCESS:
            raise self._transport_error(
                f"malformed PINE {command_name} response status 0x{status:02x}"
            )
        if expected_result_size is not None and len(result) != expected_result_size:
            raise self._transport_error(
                f"PINE {command_name} result size mismatch at response offset 5: "
                f"expected {expected_result_size}, got {len(result)}"
            )
        return result

    def _string_command(self, opcode: int, name: str) -> str:
        result = self._exchange(bytes((opcode,)), command_name=name, expected_result_size=None)
        if len(result) < 4:
            raise self._transport_error(
                f"PINE {name} string length is truncated at response offset 5"
            )
        length = struct.unpack_from("<I", result)[0]
        encoded = result[4:]
        if length != len(encoded):
            raise self._transport_error(
                f"PINE {name} string size mismatch at response offset 5: "
                f"declared {length}, got {len(encoded)}"
            )
        if not encoded or encoded[-1] != 0:
            raise self._transport_error(
                f"PINE {name} string is not NUL-terminated at response offset {8 + len(encoded)}"
            )
        if b"\0" in encoded[:-1]:
            raise self._transport_error(
                f"PINE {name} string contains an embedded NUL at response offset "
                f"{9 + encoded[:-1].index(0)}"
            )
        try:
            return encoded[:-1].decode("utf-8")
        except UnicodeDecodeError as error:
            raise self._transport_error(
                f"PINE {name} returned invalid UTF-8 at response offset {9 + error.start}"
            ) from error

    def version(self) -> str:
        return self._string_command(VERSION, "version")

    def title(self) -> str:
        return self._string_command(TITLE, "title")

    def game_id(self) -> str:
        return self._string_command(GAME_ID, "game ID")

    def uuid(self) -> str:
        return self._string_command(UUID, "UUID")

    def game_version(self) -> str:
        return self._string_command(GAME_VERSION, "game version")

    def status(self) -> int:
        result = self._exchange(bytes((STATUS,)), command_name="status", expected_result_size=4)
        return struct.unpack("<I", result)[0]

    def save_state(self, slot: int) -> None:
        _check_uint("slot", slot, 8)
        self._exchange(
            bytes((SAVE_STATE, slot)),
            command_name=f"save state slot {slot}",
            expected_result_size=0,
        )

    def load_state(self, slot: int) -> None:
        _check_uint("slot", slot, 8)
        self._exchange(
            bytes((LOAD_STATE, slot)),
            command_name=f"load state slot {slot}",
            expected_result_size=0,
        )

    def _read_scalar(self, address: int, width: int) -> int:
        _check_guest_range(address, width)
        opcode = _READ_COMMANDS[width]
        result = self._exchange(
            struct.pack("<BI", opcode, address),
            command_name=f"read_u{width * 8} at 0x{address:08x}",
            expected_result_size=width,
        )
        return int.from_bytes(result, "little")

    def read_u8(self, address: int) -> int:
        return self._read_scalar(address, 1)

    def read_u16(self, address: int) -> int:
        return self._read_scalar(address, 2)

    def read_u32(self, address: int) -> int:
        return self._read_scalar(address, 4)

    def read_u64(self, address: int) -> int:
        return self._read_scalar(address, 8)

    def _write_scalar(self, address: int, value: int, width: int) -> None:
        _check_guest_range(address, width)
        _check_uint("value", value, width * 8)
        opcode = _WRITE_COMMANDS[width]
        command = struct.pack("<BI", opcode, address) + value.to_bytes(width, "little")
        self._exchange(
            command,
            command_name=f"write_u{width * 8} at 0x{address:08x}",
            expected_result_size=0,
        )

    def write_u8(self, address: int, value: int) -> None:
        self._write_scalar(address, value, 1)

    def write_u16(self, address: int, value: int) -> None:
        self._write_scalar(address, value, 2)

    def write_u32(self, address: int, value: int) -> None:
        self._write_scalar(address, value, 4)

    def write_u64(self, address: int, value: int) -> None:
        self._write_scalar(address, value, 8)

    @staticmethod
    def _aligned_width(address: int, remaining: int) -> int:
        if remaining >= 8 and address % 8 == 0:
            return 8
        if remaining >= 4 and address % 4 == 0:
            return 4
        if remaining >= 2 and address % 2 == 0:
            return 2
        return 1

    def read_bytes(self, address: int, size: int) -> bytes:
        """Read an arbitrary guest range using naturally aligned batched reads."""
        _check_guest_range(address, size)
        self._connected_socket()
        if size == 0:
            return b""

        output = bytearray(size)
        output_offset = 0
        current_address = address
        remaining = size

        while remaining:
            commands = bytearray()
            command_count = 0
            result_size = 0
            batch_address = current_address
            while remaining:
                width = self._aligned_width(current_address, remaining)
                if (
                    4 + len(commands) + 5 > MAX_REQUEST_SIZE
                    or 5 + result_size + width > MAX_RESPONSE_SIZE
                ):
                    break
                commands.extend(struct.pack("<BI", _READ_COMMANDS[width], current_address))
                command_count += 1
                result_size += width
                current_address += width
                remaining -= width

            if command_count == 0:
                raise PineError("PINE protocol limits cannot fit one aligned read command")
            result = self._exchange(
                bytes(commands),
                command_name=f"batched read at 0x{batch_address:08x} ({command_count} commands)",
                expected_result_size=result_size,
            )
            output[output_offset : output_offset + result_size] = result
            output_offset += result_size

        return bytes(output)

    def write_bytes(self, address: int, data: bytes) -> None:
        """Write an arbitrary guest range using naturally aligned batched writes."""
        if not isinstance(data, bytes):
            raise TypeError("data must be bytes")
        _check_guest_range(address, len(data))
        self._connected_socket()
        offset = 0
        while offset < len(data):
            commands = bytearray()
            batch_address = address + offset
            while offset < len(data):
                current_address = address + offset
                width = self._aligned_width(current_address, len(data) - offset)
                if 4 + len(commands) + 5 + width > MAX_REQUEST_SIZE:
                    break
                commands.extend(struct.pack("<BI", _WRITE_COMMANDS[width], current_address))
                commands.extend(data[offset : offset + width])
                offset += width
            if not commands:
                raise PineError("PINE protocol limits cannot fit one aligned write command")
            self._exchange(
                bytes(commands),
                command_name=f"batched write at 0x{batch_address:08x}",
                expected_result_size=0,
            )


def _numeric_argument(value: str) -> int:
    try:
        return int(value, 0)
    except ValueError as error:
        raise argparse.ArgumentTypeError(f"invalid integer: {value!r}") from error


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Query PCSX2 through its PINE socket")
    parser.add_argument("--socket", dest="socket_path", help="PINE Unix socket path")
    parser.add_argument("--timeout", type=float, default=5.0, help="socket timeout in seconds")
    subparsers = parser.add_subparsers(dest="subcommand", required=True)
    subparsers.add_parser("info", help="print emulator and game information")
    read_parser = subparsers.add_parser("read", help="read guest memory into a file")
    read_parser.add_argument("address", metavar="ADDRESS", type=_numeric_argument)
    read_parser.add_argument("size", metavar="SIZE", type=_numeric_argument)
    read_parser.add_argument("output", metavar="OUTPUT", type=Path)
    return parser


def main(argv: Optional[Sequence[str]] = None) -> int:
    parser = _build_parser()
    args = parser.parse_args(argv)
    try:
        with PineClient(args.socket_path, args.timeout) as client:
            if args.subcommand == "info":
                print(f"Version: {client.version()}")
                print(f"Title: {client.title()}")
                print(f"Game ID: {client.game_id()}")
                print(f"UUID: {client.uuid()}")
                print(f"Game version: {client.game_version()}")
                print(f"Status: {client.status()}")
            else:
                data = client.read_bytes(args.address, args.size)
                args.output.write_bytes(data)
    except (PineError, OSError, ValueError) as error:
        parser.exit(1, f"error: {error}\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
