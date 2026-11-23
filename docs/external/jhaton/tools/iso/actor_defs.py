#!/usr/bin/env python3
"""Extract actor definitions from Kingdom Hearts (JP) room archives.

Every Kingdom Hearts JP room archive (``*.ard``) on the game ISO contains one
or more object packages. Each package embeds a table of fixed-size (0x78-byte)
definition records with an 8-byte ASCII actor name at +0x68 (kept verbatim,
e.g. ``SORA``, ``KAGE082``, ``mo_tre00``) and a char-id at +0x4C.

Important: a *definition-id slot is reused across room packages* -- the same
slot can hold different content (name, char id, kind) in different rooms. The
stable identity is therefore the actor name (plus its char-id), not the slot.
This tool groups records by (name, char_id) and aggregates the definition
slots and worlds each actor occupies.

Output is a tab-separated table (one row per (name, char_id)):

  name  char_id  kind  definition_ids  worlds  world_count  ard_count

Example:
  python3 tools/iso/actor_defs.py "Kingdom Hearts (Japan)/Kingdom Hearts (Japan).iso" \\
      -o config/jp/actor_definitions.tsv
"""

import argparse
import mmap
import struct
import sys
from collections import Counter
from pathlib import Path
from typing import List, Optional, Tuple

from common import hash_filename

ISO_BLOCK_SIZE = 0x800
REC_SIZE = 0x78
NAME_OFF = 0x68
NAME_LEN = 8
CHAR_OFF = 0x4C
KIND_OFF = 0x54

# World prefixes found in room archive filenames (player-confirmed mapping).
WORLD_CODES = {
    "al": "Agrabah",
    "aw": "Wonderland",
    "dc": "Disney Castle",
    "dh": "Dive to the Heart",
    "di": "Destiny Islands",
    "ew": "End of the World",
    "gb": "Unknown",
    "he": "Olympus Coliseum",
    "lm": "Atlantica",
    "nm": "Halloween Town",
    "pc": "Hollow Bastion",
    "pi": "Monstro",
    "po": "100 Acre Wood",
    "pp": "Neverland",
    "tw": "Traverse Town",
    "tz": "Deep Jungle",
    "zz": "Misc",
}


def fail(msg: str) -> None:
    print(msg, file=sys.stderr)
    sys.exit(1)


def parse_archive(data: bytes) -> Optional[List[bytes]]:
    """Parse a KH archive header (entry count + endpoint table)."""
    if len(data) < 8:
        return None
    count = struct.unpack_from("<I", data, 0)[0]
    if not 0 < count <= 0x1000:
        return None
    table_end = 4 + (count + 1) * 4
    if table_end > len(data):
        return None
    offsets = struct.unpack_from(f"<{count + 1}I", data, 4)
    if any(offset < table_end for offset in offsets):
        return None
    if any(b < a for a, b in zip(offsets, offsets[1:])):
        return None
    return [data[offsets[i] : offsets[i + 1]] for i in range(count)]


def decompress(src: bytes) -> bytearray:
    """Inverse of the game's LZ-style compression (see tools/iso/extract.py)."""
    src_index = len(src) - 1
    if src_index == 0:
        return bytearray()

    key = src[src_index]
    src_index -= 1
    dec_size = (
        src[src_index]
        | (src[src_index - 1] << 8)
        | (src[src_index - 2] << 16)
    )
    src_index -= 3

    dst_index = dec_size - 1
    dst = bytearray(dec_size)
    while dst_index >= 0 and src_index >= 0:
        data = src[src_index]
        src_index -= 1
        if data == key and src_index >= 0:
            copy_index = src[src_index]
            src_index -= 1
            if copy_index > 0 and src_index >= 0:
                copy_length = src[src_index]
                src_index -= 1
                for _ in range(copy_length + 3):
                    if dst_index + copy_index + 1 < len(dst):
                        dst[dst_index] = dst[dst_index + copy_index]
                    else:
                        dst[dst_index] = 0
                    dst_index -= 1
                    if dst_index < 0:
                        break
            else:
                dst[dst_index] = data
                dst_index -= 1
        else:
            dst[dst_index] = data
            dst_index -= 1
    return dst


def read_root_directory(mm: mmap.mmap) -> List[Tuple[str, int, int]]:
    """Read ISO9660 primary-volume root directory records."""
    pvd = mm[16 * ISO_BLOCK_SIZE : 17 * ISO_BLOCK_SIZE]
    rec_len = pvd[156]
    root_len = struct.unpack_from("<I", pvd, 156 + 10)[0]
    root_data = mm[struct.unpack_from("<I", pvd, 156 + 2)[0] * ISO_BLOCK_SIZE :][:root_len]
    entries: List[Tuple[str, int, int]] = []
    pos = 0
    while pos < len(root_data):
        length = root_data[pos]
        if length == 0:
            pos = (pos // ISO_BLOCK_SIZE + 1) * ISO_BLOCK_SIZE
            continue
        record = root_data[pos : pos + length]
        extent = struct.unpack_from("<I", record, 2)[0]
        size = struct.unpack_from("<I", record, 10)[0]
        name = bytes(record[33 : 33 + record[32]]).decode("ascii", "replace")
        entries.append((name, extent, size))
        pos += length
    return entries


def collect_definitions(ard_data: bytes):
    """Yield (resource_index, record_bytes) for every actor definition found."""
    outer = parse_archive(ard_data)
    if outer is None:
        return
    for resource_index, resource in enumerate(outer):
        if not resource or len(resource) < 16:
            continue
        count = struct.unpack_from("<I", resource, 0)[0]
        if not 0 < count <= 0x1000 or 4 + (count + 1) * 4 > len(resource):
            continue
        offsets = struct.unpack_from(f"<{count + 1}I", resource, 4)
        table_end = 4 + (count + 1) * 4
        if any(offset < table_end for offset in offsets):
            continue
        if any(b < a for a, b in zip(offsets, offsets[1:])):
            continue
        start, end = offsets[0], offsets[1]
        if not 8 <= start < end <= len(resource):
            continue
        record_count = struct.unpack_from("<I", resource, start)[0]
        if not 0 < record_count <= 512:
            continue
        if 4 + record_count * REC_SIZE > end - start:
            continue
        records = [
            resource[start + 4 + i * REC_SIZE : start + 4 + (i + 1) * REC_SIZE]
            for i in range(record_count)
        ]
        if not all(0 < struct.unpack_from("<I", rec, 0)[0] < 0x1000000 for rec in records):
            continue
        for record in records:
            yield resource_index, record


def record_name(record: bytes) -> str:
    raw = record[NAME_OFF : NAME_OFF + NAME_LEN].split(b"\x00")[0]
    name = raw.decode("ascii", "replace")
    if not all(32 <= ord(c) < 127 for c in name):
        return f"raw_{bytes(record[NAME_OFF:NAME_OFF + NAME_LEN]).hex()}"
    return name


def read_idx(mm: mmap.mmap, idx_offset: int, idx_size: int):
    idx = mm[idx_offset : idx_offset + idx_size]
    entries: List[Tuple[int, bool, int, int]] = []
    for off in range(0, len(idx), 16):
        (hash_, compressed, block, length) = struct.unpack_from("<IIII", idx, off)
        if hash_ == 0:
            break
        entries.append((hash_, bool(compressed), block, length))
    return entries


def load_ard_filenames(filenames_path: Path) -> List[str]:
    names = [
        line.strip()
        for line in filenames_path.read_text().splitlines()
        if line.strip()
    ]
    return [name for name in names if name.endswith(".ard")]


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("iso_path", type=Path, help="path to the Kingdom Hearts (Japan) ISO")
    parser.add_argument("-o", "--output", type=Path, default=Path("config/jp/actor_definitions.tsv"))
    parser.add_argument(
        "--filenames",
        type=Path,
        default=Path("tools/iso/kingdom_filenames.txt"),
        help="ISO filename-hash dictionary",
    )
    args = parser.parse_args()

    if not args.iso_path.is_file():
        fail(f"ISO not found: {args.iso_path}")

    try:
        ards = load_ard_filenames(args.filenames)
    except OSError as exc:
        fail(f"cannot read filenames list {args.filenames}: {exc}")
    if not ards:
        fail("no .ard filenames found")

    with args.iso_path.open("rb") as handle:
        mm = mmap.mmap(handle.fileno(), 0, access=mmap.ACCESS_READ)

        root = read_root_directory(mm)
        by_name = {name: (extent, size) for name, extent, size in root}
        for required in ("KINGDOM.IDX;1", "SYSTEM.CNF;1"):
            if required not in by_name:
                fail(f"file {required} not found in ISO root")

        idx_extent, idx_size = by_name["KINGDOM.IDX;1"]
        kingdom = read_idx(mm, idx_extent * ISO_BLOCK_SIZE, idx_size)
        base_block = by_name["SYSTEM.CNF;1"][0]
        by_hash = {hash_: (compressed, block, length) for hash_, compressed, block, length in kingdom}

        # (name, char_id) -> {slots: set, files: set, kinds: Counter}
        catalog = {}

        def record(rec: bytes, ard_file: str) -> None:
            def_id = struct.unpack_from("<I", rec, 0)[0]
            name = record_name(rec)
            char_id = struct.unpack_from("<H", rec, CHAR_OFF)[0]
            key = (name, char_id)
            entry = catalog.setdefault(
                key, {"slots": set(), "files": set(), "kinds": Counter()}
            )
            entry["slots"].add(def_id)
            entry["files"].add(ard_file)
            entry["kinds"][rec[KIND_OFF]] += 1

        failed = 0
        for index, ard_file in enumerate(ards, 1):
            if index % 25 == 0 or index == len(ards):
                print(f"  ... {index}/{len(ards)}", file=sys.stderr)
            try:
                compressed, block, length = by_hash[hash_filename(ard_file)]
            except KeyError:
                print(f"warning: {ard_file} absent from KINGDOM.IDX", file=sys.stderr)
                failed += 1
                continue
            raw = mm[(base_block + block) * ISO_BLOCK_SIZE : (base_block + block) * ISO_BLOCK_SIZE + length]
            ard = decompress(raw) if compressed else bytes(raw)
            for _resource_index, rec in collect_definitions(ard):
                record(rec, ard_file)
        if failed:
            print(f"warning: {failed} ard files missing from the ISO", file=sys.stderr)

    rows = []
    for (name, char_id), entry in sorted(catalog.items()):
        files = sorted(entry["files"])
        worlds = sorted({f[:2] for f in files if f[:2] in WORLD_CODES})
        slots = sorted(entry["slots"])
        kind = entry["kinds"].most_common(1)[0][0]
        rows.append(
            (
                name,
                char_id,
                kind,
                ",".join(f"0x{slot:08X}" for slot in slots),
                ",".join(worlds),
                len(worlds),
                len(files),
            )
        )

    legend = "  ".join(f"{code}={world}" for code, world in WORLD_CODES.items())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("w", newline="") as handle:
        handle.write("# Kingdom Hearts (JP) actor definitions; embedded 8-byte dev names kept verbatim.\n")
        handle.write("# Definition-id slots are reused across room packages, so identity is (name, char_id).\n")
        handle.write("# char_id and kind are the most common values across all occurrences.\n")
        handle.write(f"# World codes: {legend}\n")
        handle.write("name\tchar_id\tkind\tdefinition_ids\tworlds\tworld_count\tard_count\n")
        for row in rows:
            handle.write("\t".join(str(field) for field in row) + "\n")

    print(f"wrote {len(rows)} actor definitions to {args.output}", file=sys.stderr)


if __name__ == "__main__":
    main()
