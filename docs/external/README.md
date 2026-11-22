# Reference material from other forks of ethteck/kh1 (pulled 22 Nov 2026, local reference only)

None of these forks has matched functions we lack (all at upstream's ~1,717 unmatched). What is worth having:

## jhaton/kh1 (branch backup/pre-omarchy-2026-09-24) - credit: jhaton
- `jhaton/jp_semantic_names.txt`: 81 real function names at Japanese-version addresses (cdvd_*, Fade_*, ...).
- `jhaton/names_for_fm.tsv`: the same names with the name our C uses (func_<JP address>) and the Final Mix address
  where config/fm/jp_names.txt knows it (47 of 81; the other 34 are in code that upstream had not split, so the
  JP->FM mapping for them still has to be made).
  NOT applied yet: renaming touches many source files, so do it when no agent has uncommitted work.
- `jhaton/tools/script_bytecode.py`, `script_command_db.py`: decoder and command database for the game's script VM
  (our src/xhumungus.c). Read these before matching xhumungus script handlers.
- `jhaton/tools/iso/actor_defs.py`: actor definitions from the disc.
- `jhaton/tools/khtrace.py`, `pcsx2_pine.py`: tracing the running game through PCSX2's PINE interface (useful for
  the porting plan's memory map and rendering path work).
- `jhaton/pc/PORTING_PLAN.md`: their PC port plan (C++20 host, SDL3 / SDL_GPU, guest memory with explicit 32-bit
  pointers, PCSX2 as a behaviour oracle only). Compare with docs/porting/PORTING-PLAN.md.

## seb-sep/kh1 - credit: seb-sep
- `seb-sep/func_001011E0_draft.c`: work-in-progress C for xporcupine func_001011E0 (JP). Against Final Mix it is
  175 instructions off (size 0x2c0 vs 0x2c8): a starting point for structure and names, not a match.

## KillingStalking/kh1us (branch wip/usa-elf-audit)
- Tooling and audit documents that map the US version onto the JP code (tools/elf/USA_*.md in that branch). No new
  C. Fetched as remote x_KillingStalking_kh1us for reference; compare its mapping checks with eu-notes/ if the US
  version ever matters.

## Yotona/kh1
- Build-tool (splat) version bumps only. Nothing taken.

The four forks are fetched as read-only remotes named x_<owner>_<repo> (push disabled).
