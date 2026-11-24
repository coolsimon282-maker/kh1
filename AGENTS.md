# Instructions for the local agent (Qwen in OpenCode): matching Final Mix functions

You turn assembly functions of the PS2 game Kingdom Hearts Final Mix into C that compiles to exactly the same
bytes. The full background is in RUNBOOK.md and the matching tricks in MATCHING.md: read the parts you need, not
whole files at once (your context is 64k tokens). The owner is learning: explain what you did in plain words.

## Where you work

* Your checkout: `C:\Users\you\psp-learning\kh1-study\kh1-wt\q1` (branch `fm-q1`). Work only here.
* **Your file: the one `qwen/TASK.md` names** (from 22 Nov: `src/unsplit/seg_132D60.c`, its tiny functions;
  xhumungus/xkinetic are paused). Don't edit any other file except your notes file
  `notes/q1.md`. Never edit `include/`, `config/`, `configure.py`, `tools/`, `eu-notes/`.
* Useful notes from earlier agents (read when you start a file): `notes/a1.md` (xhumungus: the Script stack,
  overlay structs, patterns) and `notes/a6.md` (xkinetic: the `ScriptVM` overlay).

**Skip these in xhumungus.c** (Claude agents already tried them hard; details in notes/a1.md): func_001CF6C8,
func_001CF728, func_001D9EA8, func_001D9F08, func_001CC588, func_001CCA88, func_001CC618, func_001CCEF8,
func_001D0DE0, func_001D0E78, func_001DBA58, func_001D8500, func_001D11C0. `list` shows them among the smallest;
take the next ones up.

## Recording the work

Every attempt is kept for reviewing and improving the work: read `DATASET.md` (short). Always work through
`agent-tools.sh` so each attempt is recorded; give `giveup` a precise reason; note tricks with `lesson`.

## Hard rules

1. Never download anything, never push, never change branches, never rewrite history (`--amend`, `reset`,
   `rebase`).
2. One function per commit, and only after a build whose last line is exactly
   `build/fm/SLPS_251.98.rom: OK`.
3. Never leave the build broken. Giving up on a function: `git checkout -- src/<file>.c` — straight away, before
   anything else. Only ONE function may be uncommitted at a time: if `put` or `build` prints a WARNING/NOTE about
   other uncommitted functions, run that git checkout first, or no build can pass.
4. Keep Linux line endings and keep all `#ifdef VERSION_FM` / `#ifndef VERSION_FM` markers.

## Commands (PowerShell; run them from the checkout folder; builds take 10-60 s)

```
wsl -e bash ./agent-tools.sh list unsplit/seg_132D60                 # functions left in a file, smallest first
wsl -e bash ./agent-tools.sh asm unsplit/seg_132D60 func_00236FD8    # its assembly
wsl -e bash ./agent-tools.sh m2c unsplit/seg_132D60 func_00236FD8    # a first draft of C
wsl -e bash ./agent-tools.sh cfunc func_00218BF0                      # an already-matched function's C (twins!)
wsl -e bash ./agent-tools.sh near unsplit/seg_132D60 func_00236FD8 15 # the lines around it in the file
wsl -e bash ./agent-tools.sh try unsplit/seg_132D60 func_00236FD8 qwen/work.c
      # puts your C (qwen/work.c) in place and builds. MATCHED -> it prints the commit command: run it.
      # Not matching -> it prints the diff (original on the left). Fix qwen/work.c and `try` again.
wsl -e bash ./agent-tools.sh giveup unsplit/seg_132D60 func_00236FD8 <reason in a few words>
      # after 2 failed tries: puts the file back and writes the reason into notes/q1.md. Then the next function.
```

(`build`, `diff <func> 40` and `put <file> <func> qwen/work.c` still exist; `try` does put + build + diff in one go.)

## The loop

1. Take the next function from qwen/TASK.md (twins first). Skip functions full of VU0 instructions (`vadd`,
   `vmul`, `qmtc2`, `vcallms`, `sqc2`).
2. Twin: `cfunc <twin>` and copy it. Otherwise: `asm` + `m2c`. Write the function (plus any extern/prototype it
   needs, just above it) into `qwen/work.c`. **Never open a big src file with the read tool**; use `near` with a
   small number, and grep only `include/` or one file with `-m 5`.
3. `try`. MATCHED: run the commit command it prints, then the next function.
4. Not matching: read the diff, fix qwen/work.c, `try` again (table below and MATCHING.md).
5. After 2 failed tries: `giveup <file> <func> <reason>`, then the next function.

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
