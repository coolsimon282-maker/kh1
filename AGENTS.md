# Instructions for the local agent (Qwen in OpenCode): matching Final Mix functions

You turn assembly functions of the PS2 game Kingdom Hearts Final Mix into C that compiles to exactly the same
bytes. The full background is in RUNBOOK.md and the matching tricks in MATCHING.md: read the parts you need, not
whole files at once (your context is 64k tokens). The owner is learning: explain what you did in plain words.

## Where you work

* Your checkout: `C:\Users\you\psp-learning\kh1-study\kh1-wt\q1` (branch `fm-q1`). Work only here.
* **Your files: `src/xhumungus.c` and `src/xkinetic.c`.** Don't edit any other file except your notes file
  `notes/q1.md`. Never edit `include/`, `config/`, `configure.py`, `tools/`, `eu-notes/`.
* Useful notes from earlier agents (read when you start a file): `notes/a1.md` (xhumungus: the Script stack,
  overlay structs, patterns) and `notes/a6.md` (xkinetic: the `ScriptVM` overlay).

**Skip these in xhumungus.c** (Claude agents already tried them hard; details in notes/a1.md): func_001CF6C8,
func_001CF728, func_001D9EA8, func_001D9F08, func_001CC588, func_001CCA88, func_001CC618, func_001CCEF8,
func_001D0DE0, func_001D0E78, func_001DBA58, func_001D8500, func_001D11C0. `list` shows them among the smallest;
take the next ones up.

## Hard rules

1. Never download anything, never push, never change branches, never rewrite history (`--amend`, `reset`,
   `rebase`).
2. One function per commit, and only after a build whose last line is exactly
   `build/fm/SLPS_251.98.rom: OK`.
3. Never leave the build broken. Giving up on a function: `git checkout -- src/<file>.c`.
4. Keep Linux line endings and keep all `#ifdef VERSION_FM` / `#ifndef VERSION_FM` markers.

## Commands (PowerShell; run them from the checkout folder; builds take 10-60 s)

```
wsl -e bash ./agent-tools.sh build                         # last line must be: build/fm/SLPS_251.98.rom: OK
wsl -e bash ./agent-tools.sh list xhumungus                # functions left in the file, smallest first (bytes, name)
wsl -e bash ./agent-tools.sh asm xhumungus func_001D5E48   # its assembly
wsl -e bash ./agent-tools.sh m2c xhumungus func_001D5E48   # a first draft of C
wsl -e bash ./agent-tools.sh diff func_001D5E48 60         # original (left) vs yours (right), 60 lines
git diff --stat                                            # before committing: only your one file
git add src/xhumungus.c
git commit -m "Match func_001D5E48 (xhumungus)"
```

If the build says `build.ninja` is missing or the toolchain changed, run `wsl -e bash ./agent-tools.sh configure`
once (about a minute).

## The loop

1. `list` the file; take the smallest function not in your notes' give-up list. Skip functions full of VU0
   instructions (`vadd`, `vmul`, `qmtc2`, `vcallms`, `sqc2`).
2. `asm` it, then `m2c` it.
3. Replace its `INCLUDE_ASM("...", name);` line with your C. Use the file's existing types, overlay structs and
   prototypes (look at how nearby matched functions are written; xhumungus has many very similar ones). Put any
   new prototype near the top of the file.
4. `build`. OK: go to 6. Compile error: fix. FAILED: `diff` and adjust (table below and MATCHING.md).
5. After about 6 failed builds: `git checkout -- src/<file>.c`, add a line to `notes/q1.md` (function, what it
   does, your closest C, what still differs), and take the next function.
6. `git diff --stat` (only your file), `git add`, `git commit -m "Match <func> (<file>)"`. Tell the owner in one
   sentence what the function does.

| The diff shows | Try |
|---|---|
| two `li` swapped, or `movz` vs `movn` | flip the condition or swap the ternary arms |
| same instructions, different registers | reorder declarations; reuse a variable; add a prototype for the called function |
| stores in a different order | the last store usually comes first; permute the statements |
| original reloads a value after a store | read it through a union, or type the field `s32` (xhumungus is a strict-aliasing file) |
| `j` (tail call) where the original has `jal` and returns | `do { f(); } while (0);` around the call, or return `s32` |
| `dsll32`/`dsra32` on a u64 bit test | `(s32)(x >> n) & 1` |

## Session length

After about 10 functions (or when your context is getting full), commit your notes file
(`git add notes/q1.md`, `git commit -m "q1 notes"`) and stop. Tell the owner: how many matched, which, which you
gave up on. The owner starts a fresh session to continue, and asks Claude to merge `fm-q1` into `fm`.
