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

## What made things match (learned by earlier agents; add to this in your notes)

* **Bit tests**: `return (x & 1) != 0;` folds to a bare `andi`; the target's `andi + sltu` came from
  `if (x & 1) return 1; return 0;`. Try that form for `lui/and/sltiu` patterns too.
* **Store order**: several stores to one base usually come out last-statement-first, then the rest in source
  order. A chain `x = y = z = 0` comes out as x, z, y.
* **Strict aliasing is on**: if the target keeps a load after a store through `s32*`, type the field `s32` and
  cast where it's used. If a byte store comes first, load every pointer you need at the top of the function.
* **`volatile`**: a global accessed as `lui / addiu %lo / sw 0(reg)` even when used once is declared `volatile`.
* **Small constant loops** get unrolled by the compiler.
* **FM-only globals** (names like `D_004D5AF8`) are defined by the build; a plain `extern` is enough.
* **`cvt.w.s`** (shown as `.word 0x46000064` or similar): matchable now. With the FM build's no-nop mode a
  plain `(s32)f` cast compiles to `cvt.w.s` + `mfc1` (a2 matched pppRandChar/Short/Int this way).
* **Overlay structs**: when indexing through a field gets folded into the wrong base, declare a local struct
  that lays out the region directly (xkinetic's `ScriptVM`).
* **Prototypes matter**: a call with no prototype schedules differently; adding `void f(s32);` fixed several.
* **Ternaries**: if two `li` come out swapped, swap the ternary (`f() ? 2 : 4` instead of `== 0 ? 4 : 2`);
  `movz` instead of `movn` means the condition needs flipping.
* **u64 flag tests**: `((s32)(*(u64*)D_X >> N) & 1) ? 4 : 2`; the `(s32)` before `& 1` avoids a sign-extension.
* **Scalar vs array globals**: if the original re-loads a struct field after storing to a global, declare the
  global as an array and store to `X[0]` (GCC assumes a plain scalar can't alias the struct).
* **xhumungus Script stack** (see notes/a1.md): `unk_174[3]` is the top index, `unk_174[top + 4]` the value.
* **Fast experiments**: compile a test file straight in your WSL mirror with the FM flags (piped through
  masps2.py) to try many variants in seconds; the command is in notes/a4.md.
* **Float functions are matchable now**: FM was assembled without the `nop`s masps2.py used to add after
  `mfc1`, `c.le.s`/`c.lt.s` and `mtc1`; the FM build no longer adds them (since 21 Nov 23:40). Functions given
  up earlier for that reason are worth a retry. Run `wsl -e bash ./agent-tools.sh configure` once in a
  checkout that was set up before then.
* **Global names**: use the names `config/fm/jp_names.txt` gives where there is one; only fall back to the
  FM-address name (`D_00xxxxxx`) for globals it doesn't list.
* **Aliasing**: `src/ppp/` is now compiled with `-fno-strict-aliasing` (as the original was; since 22 Nov
  00:30), so reloads after stores of other types come out by themselves there. Elsewhere (e.g. xpotato), go
  through a union (`typedef union { f32 f; s32 i; } FI;`) or type the pointer field as `s32`.
* **Hand-written VU0 sequences** (random float, `v.xyz *= s`, sqrt) match as `static inline` helpers with
  `__asm__ volatile`; templates in notes/a2.md (copies: vu0Rand in pppRandFloat.c, vu0ScaleXYZ in
  pppKeMatPht.c, vu0Sqrt in pppEiWindFun.c).
* **include/ppp.h's include guard is fixed** (was `#define PPP`): including it with ppp/pppUtil.h is fine now.
* **Check the build result properly**: don't trust `| tail -1` of a filtered log; the commit must follow a build
  whose last line is `build/fm/SLPS_251.98.rom: OK`.
* **Jump tables**: a `switch` that becomes a jump table needs the file to have a .rodata piece in the FM config;
  if the link fails for that reason, give up on the function and note it (the coordinator fixes the config).
* **Scratch files**: the scratchpad folder is shared between agents; use your own subfolder in it.

## Your notes file

`notes/<your agent name>.md`: functions you gave up on (with closest C), and anything you learned about the
code (what a module does, struct layouts, names you're confident about). Commit it with your matches.

## Stopping

Work through as many functions as you can. When your context is getting long (roughly 40 attempts), stop
after a commit and report: how many matched (list), how many given up (list), what's left in your files.
A fresh agent continues from your branch and your notes file.
