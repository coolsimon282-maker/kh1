# EU version (SCES_509.67): how it's built

The European program is the Japanese code base with small edits, at shifted addresses. This copy of the project
builds it as a third version, `eu`, byte for byte (`build/eu/SCES_509.67.rom: OK`), with **267 of the 275 game C
files** in it (state of 21 Nov 2026).

## What's where

| | |
|---|---|
| `config/kh.eu.yaml` | the EU layout: code to 0x16d630, data to 0x3867d0, read-only data to 0x38da30; gp 0x48da30 |
| `config/eu/jp_names.txt` | JP names at their EU addresses (generated; 3,800+ names) |
| `config/eu/symbol_addrs.txt` | hand-made: `_start`, `_exit`, four jump-only functions |
| `config/eu/undefined_syms.txt` | addresses outside the program (hardware/scratch) |
| `configure.py` | `eu` added; passes `-DVERSION_EU` (or `_JP`/`_FM`); compile pipe uses `pipefail` |
| `diff_settings.py` | `KH_VERSION=eu` makes `diff.py` compare against EU |
| `src/**/*.c` | `#ifdef VERSION_EU` markers, see below |

In the C files:

* `#ifdef VERSION_EU` / declaration / `INCLUDE_ASM` / `#else` / JP's C / `#endif`: 84 functions whose EU code
  differs from JP's (or that are too small to pin to one place). EU takes them from EU's assembly.
* `#ifdef VERSION_EU` / `INCLUDE_ASM(..., eu_func_XXXXXXXX)` / `#endif`: 28 functions only EU has.
* `#ifndef VERSION_EU` ... `#endif`: 2 functions EU doesn't have.

## EU on the fm branch (26 Nov, a5)

The fm branch had left the EU markers out (5000bb58); after the FM matching and cleanup runs EU builds byte for
byte again from the same source (`build/eu/SCES_509.67.rom: OK`). What it took:

* **Compiler settings** (configure.py): EU is built without `-g` (call delay slots filled) and, like FM, without
  masps2's hazard nops; only `EU_G_FILES` (xgoblin, xhumungus, pppRyjMatrixNoRot, pppRyjDrawShipoly) keep `-g`.
  With that every EU C piece has its EU size.
* **Markers**: `apply_eu_wrap_fm.py` applies eu_wrap / jp_only / eu_only like apply_eu_wrap.py but only looks at
  text the EU build compiles (outside `#ifdef VERSION_FM`), with the tsv names mapped to the cleanup names.
  eu_wrap.tsv grew by 40 functions: FM-matched shared C that differs in EU (50 Hz time constants, FM's extra config
  option, xbuffalo's 0x20-byte thread slots instead of 0x30, call targets that are FM-only names).
* **Names**: the names shared C uses that config/eu lacks (FM-address names, library names, JP names added after
  jp_names.txt was made, 537) are at the end of config/eu/undefined_syms.txt, each read from the EU program at every
  relocation against it (`eu_symaddrs.py`, with an EU link made with `--unresolved-symbols=ignore-all`; all
  references agreed). Seven FM-address names that are also EU's own address names are at the end of jp_names.txt
  (EU's own symbol gets `eu_` in front). `eu_symaddrs.py ALL` on a real link lists symbols whose value disagrees
  with the EU code.
* **Read-only data**: the jump tables of four newly matched C functions (xbeginning, xowl, pppRyjMegaBirth,
  pppRyjMegaBirthModel) are their files' `.rodata` pieces in config/kh.eu.yaml.
* xpackage's table is read at EU's 0x661FD8 (the EU layout does not place C .bss).

## Not in the EU build yet

| file | why |
|---|---|
| memcard, disk, xcapy, xjockey, gumi | their C-defined data differs in EU (probably save names, paths, language tables) |
| xkingdom | has zero-filled statics (.bss); where they go in EU's bss isn't worked out |
| xlamp | a call in its C points at a different EU function than another file's code says |
| xsquash | no C function found in EU, and both neighbours are assembly |
| lib/* (4) | Sony's libraries, built with the other compiler; not tried |

## How the mapping was made

All of this runs in WSL. The scripts read the JP C files compiled with `-DPERMUTER` (INCLUDE_ASM left out) into
`~/kh1-test/obj`; the 32-bit compilers can't read `/mnt/c`, so `~/kh1-test` is a copy.

1. `build_all.sh` compiles every game C file into `~/kh1-test/obj` (copy `src/` and `include/` there first).
2. `match_eu.py` searches the EU program for each compiled function, with linker-filled address bits
   ignored: `eu_matches.tsv` (file, function, size, EU address(es), shift).
3. `plan_c_files.py`: one line per JP C file (`c_plan.tsv`).
4. `list_eu_funcs.py`: every function start splat finds in a plain EU split (`eu_funcs.tsv`).
   Only needs redoing if the plain split changes.
5. `gen_eu_c.py` writes the generated parts of `config/kh.eu.yaml`, `config/eu/jp_names.txt` and
   `config/eu/undefined_syms.txt`, and the lists `eu_wrap.tsv`, `eu_only.tsv`, `jp_only.tsv`:
   * C functions found once in EU are anchors (a false match out of order with the rest is dropped);
     ones found several times are settled by their position between anchors.
   * Everything else in a file goes on EU's function starts in JP order. Where the counts differ, JP and EU
     function sizes are lined up (Needleman-Wunsch); unmatched EU starts are EU-only functions, unmatched JP
     ones are JP-only.
   * Runs of files with no anchor go between placed neighbours (or outwards from one placed neighbour) the
     same way, if the sizes fit within 10%.
   * Every C function is checked against EU's code at its final place; the ones that differ go in
     `eu_wrap.tsv`.
   * Each C function's relocations, read against the EU instruction at the same place, give the EU address of
     everything it calls or uses. (MIPS keeps the offset in the instruction itself, so `D_002B8340[1]` is
     `D_002B8340` + 4.)
   * A file's own .data/.rodata piece starts where its C references say (or a JP-named INCLUDE_RODATA piece,
     or the lowest address its EU code loads), with JP's size; the C's bytes must be inside it. Variables
     the C defines get their names and sizes there; names in .rodata pieces are `force_not_migration`.
   * EU symbols whose automatic name would clash with a JP name now elsewhere become `eu_func_*` / `eu_D_*`
     (never inside a C file's own data piece).
6. `apply_eu_wrap.py` makes the source edits from the three lists. It only adds; it never removes markers.
   (To redo them from scratch, first restore upstream's sources with `git checkout 0df3b65 -- src`, which
   **also throws away any functions matched since**, so only do that before matching starts.)
7. `python3 configure.py -c -v eu && ninja` through `../wsl-build.sh`; `eu_romdiff.py` (run in
   `~/kh1-decomp-build`) lists where the image differs, by config piece, if the checksum fails.

## Numbers from the first look (before building)

* 860 of 1,145 JP C functions (75%) were found unchanged in EU by the search alone.
* Shifts: about +0x110 to +0x308 early in the code, -0x1c0 to -0x3400 further in. Data moves too
  (D_002B85F8 -> 0x2B6A68).
* `align.py` / `eu_dis.py` (Windows Python + rabbitizer) did the first size-sequence alignment and disassembly.
