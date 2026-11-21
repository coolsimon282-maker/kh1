# Matching functions for Final Mix (instructions for agents)

You turn assembly functions into C that compiles to exactly the same bytes, in the **Final Mix** build
(`SLPS_251.98`). Each agent works in its own checkout (a git worktree) on its own branch, on its own list of
files. Local work only.

## Rules

1. Only edit the `src/` files on your list. Don't edit `include/`, `config/`, `configure.py`, `tools/`,
   `eu-notes/` or any other file. If a function needs a struct or prototype, declare it near the top of the C
   file you're working in.
2. One function per commit. The build must end in `build/fm/SLPS_251.98.rom: OK` before you commit.
3. Never push, never change branches, never rewrite history, never download anything.
4. Keep Linux line endings. Keep the `#ifdef VERSION_FM` / `#ifndef VERSION_FM` markers (see below).
5. Never leave the build broken. Giving up on a function: `git checkout -- src/<file>.c` (safe: you commit
   every match, so the file has no other changes), then note it in your notes file.

## Tools (run from your checkout's root folder)

```
wsl -e bash ./agent-tools.sh build                 # must end in: build/fm/SLPS_251.98.rom: OK
wsl -e bash ./agent-tools.sh list xhumungus        # functions left in src/xhumungus.c, smallest first
wsl -e bash ./agent-tools.sh asm xhumungus func_001D6CA8
wsl -e bash ./agent-tools.sh m2c xhumungus func_001D6CA8    # first draft of C
wsl -e bash ./agent-tools.sh diff func_001D6CA8             # where your C differs from the original
```

A build takes 10-60 s. The checkout's build runs in its own copy inside WSL (`wsl-build.sh`), so several
agents can build at once.

## The loop

1. `list` a file; take the smallest function you haven't tried (check your notes file for ones you gave up on).
   Skip functions full of VU0 macro instructions (`vadd`, `vmul`, `vsub`, `qmfc2`, `qmtc2`, `ctc2`, `cfc2`,
   `vcallms`) or MMI (`pextlw`, `paddw`, `pcpyld`, `lq`/`sq` heavy code) for now.
2. `m2c` for a draft. Read the `asm` too: m2c's draft is a starting point, not the answer.
3. Replace the `INCLUDE_ASM("...", name);` line with your C function. Reuse the types and prototypes the file
   already has; grep `src/` and `include/` for how others use the same functions and globals. Add any
   prototype you need near the top of the file (not in `include/`).
4. `build`.
   * `OK`: it matches. Commit: `git add src/<file>.c` and
     `git commit -m "Match <func> (<file>)" -m "Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>"`.
   * Compile error: fix it.
   * Checksum fails: `diff <func>` and adjust. Typical fixes: signed/unsigned and `s16`/`s32` types, statement
     order, `if/else` vs early return, a temporary variable, `do {} while` vs `for`, casts, pointer vs index
     loops, `f32` constants (`1.0f`), argument order.
5. After about 6 failed builds on one function: give up on it (rule 5), add a line to your notes file:
   function, what it does, your closest C and what still differs. Then take the next.

## Markers in the files

```
#ifdef VERSION_FM                 FM's code for this function differs from the JP C below it. To match it for
<declaration>;                    FM, replace the INCLUDE_ASM line inside #ifdef VERSION_FM with C. Leave the
INCLUDE_ASM("...", func_X);       #else part (JP's C) as it is.
#else
...JP's C...
#endif

#ifdef VERSION_FM                 a function only FM has. Match it inside the #ifdef like any other.
INCLUDE_ASM("...", fm_func_X);
#endif

#ifndef VERSION_FM                a function FM doesn't have. Leave it alone.
```

## Your notes file

`notes/<your agent name>.md`: functions you gave up on (with closest C), and anything you learned about the
code (what a module does, struct layouts, names you're confident about). Commit it with your matches.

## Stopping

Work through as many functions as you can. When your context is getting long (roughly 40 attempts), stop
after a commit and report: how many matched (list), how many given up (list), what's left in your files.
A fresh agent continues from your branch and your notes file.
