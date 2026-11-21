# Plan: Kingdom Hearts decompile to 100% C

Written 21 Nov 2026 for the owner and the coding agents working in this folder. Local work only: nothing is
pushed anywhere (see AGENTS.md).

## 1. Where it stands

| | |
|---|---|
| Versions we can build and check | **Final Mix** (`SLPS_251.98`, Japanese, NTSC) and **EU** (`SCES_509.67`, PAL). Both rebuild byte for byte. The Japanese original (`SLPS_251.05`), upstream's main target, isn't here. |
| Code in C (by size, EU build) | **4%** (64 KB of 1,461 KB). About 1,100 functions, mostly small. |
| Assembly inside C files (`INCLUDE_ASM`) | 30% (451 KB, 1,738 functions). Biggest: `ppp` effects system 220 KB, `xhumungus` 78 KB. |
| Assembly not yet split into files | 64% (945 KB, 4,231 functions), of which about 140 KB is Sony's SDK libraries. |
| How alike the versions are | Of upstream's 1,145 C functions (written for JP), 894 are unchanged in both FM and EU; 215 changed the same way in both; only 16 differ just in EU and 20 just in FM. **FM and EU share almost all their code.** |

So about 5,900 functions (about 1.4 MB of machine code) are still assembly.

## 2. What "100%" means here

* Every **game** function is C that compiles to exactly the original bytes, in the FM and EU builds.
* **Sony's libraries** (libc, libkernl, libgraph, libdma, libpad, libmc, libcdvd, libipu, libvu0...) count as done
  once they're identified and matched, either as C (Sony shipped some as source) or as the SDK's own objects.
  That's how other PS2 decompiles treat them.
* **Not C by nature, and that's fine**: the start-up code (`crt0`, hand-written), the VU1 microcode (the
  `.DVP.overlay` sections and the microcode in data; it's a different processor's program), and any truly
  hand-written assembly in the game (rare; each case gets a note).
* **Data** (tables, strings) moved from assembly into C definitions too, in the last phase. Not needed for
  matching, but needed for a "shiftable" build (one where code can move), which any port needs.

## 3. Which version to work on: Final Mix first, EU kept in step

* FM is Japanese, so upstream's layout and its Sony library list (`config/fm/lib_symbol_addrs.txt`, 1,090
  symbols) already exist for it.
* FM and EU share almost all their code (above), so C matched for FM almost always matches EU; the EU mapping
  tools (`eu-notes/`) carry it over and mark the differences with `VERSION_EU`.
* Every change is checked against both: `fm` and `eu` must both end in `OK`.
* If the Japanese original turns up, the same tools map onto it.

## 4. Phases

### Phase 0: tooling (days)

1. **Bring the C files into the FM build**, the way EU got them: generalise `eu-notes/gen_eu_c.py` to a
   target version (it already does EU), giving FM about 265 of the 275 C files, with `VERSION_FM` markers
   where FM differs.
2. **One check for everything**: a script that builds `fm` and `eu` (separate build folders, so neither
   clobbers the other's `asm/`) and says OK/FAILED for each. Agents run it after every function.
3. **A progress report**: bytes and functions in C per module and per version, written to `PROGRESS.md`
   after each session.
4. **Decompiling aids** in WSL:
   * `m2c`: turns a function's assembly into a first draft of C (needs a lot of fixing, but saves most of the
     typing);
   * `decomp-permuter`: tries thousands of small rewrites of a nearly-matching function to find the one that
     matches (register allocation problems);
   * the existing `diff.py` (asm-differ) and `tools/m2ctx.py` (makes the type context m2c needs).

### Phase 1: split the 945 KB into files (weeks)

Nothing can be matched sensibly until it's in a file with a name, because static functions, file-local data
and compiler settings are per file. Ways to find the boundaries:

1. **Sony libraries**: FM's config already names them and their addresses; split them out in FM and carry the
   split to EU. About 140 KB done quickly.
2. **Read-only data order**: each C file's `.rodata` is one block, in the same order as the files' code. The
   jump tables and constants a function uses tell which block (so which file) it belongs to.
3. **Alignment**: every file starts on an 8-byte boundary, so the padding `nop`s between functions show
   possible file ends.
4. **Who calls whom**: functions only called from inside a group (static helpers) belong to that group's file.
5. **Strings**: error messages and file names in a function's data often name its module.

Each new file starts as `INCLUDE_ASM` lines for all its functions. Upstream's names (`xblade`, `xkingdom`...)
are arbitrary; new files get descriptive names when it's clear what they do.

### Phase 2: matching (the long part)

* **Order**: inside each file, leaf functions (they call nothing unknown) first, then their callers. Small
  before large. Files with many done functions before untouched ones, because their types are already known.
* **Types are the accelerator**: as structs get worked out (the player, enemies, the effects objects, the
  file archive), they go into shared headers in `include/`, and every later function using them is easier.
  Part of each session goes into naming fields and functions.
* **Per function**: m2c draft → fix by hand → build both versions → `diff.py` → adjust → permuter if it's
  only registers left → commit. Give up after a fixed effort and log it (`NOTES-agent.md`).
* **Who does what**: the local Qwen (free, slower) takes functions up to about 40 instructions; Claude takes
  the larger and harder ones and the type work. Agents work on different files at the same time, each in its
  own git worktree, merged locally.
* **Version differences**: a function that differs in EU gets EU's own C inside `#ifdef VERSION_EU` (or keeps
  EU's assembly there until someone matches it).

### Phase 3: the hard code

* **VU0 macro instructions** (the PS2's vector maths; common in `ppp` and the 3D code): written as inline
  `__asm__` inside C functions, as other PS2 decompiles do. Still counts as C.
* **128-bit MMI instructions**: same, or the compiler's builtins where they match.
* **Odd compiler settings**: some files are built without `-g` (`NO_G_FILES` in `configure.py`); more such
  cases will turn up and get noted.
* **The libraries**: match against Sony's SDK 2.5.0 sources/objects, or leave as identified assembly.

### Phase 4: data into C, and a shiftable build

* Move each file's `.data`/`.rodata` from assembly into C definitions (strings, tables), so the C files own
  their data and `INCLUDE_RODATA` goes away.
* Make the build **shiftable**: no hard-coded addresses left (every reference through a symbol). Test: add a
  few bytes of padding early in the program; the build must still boot and play in PCSX2. This is the
  prerequisite for any port, and the real "finished" line for a decompile.

## 5. How long

Honest numbers, with a lot of uncertainty:

| | functions | typical effort each | |
|---|---|---|---|
| small (up to ~40 instructions) | ~3,000 | minutes (agent) | days to weeks in total |
| medium (40-300) | ~2,500 | half an hour to a few hours | months |
| large (300+, game logic, rendering) | ~400 | hours to days each | months |

Community decompiles of games this size have taken several years with many people. Agents speed up the
small and medium functions a lot; the large ones and the type work stay slow. Realistic milestones:
**libraries and the file split: weeks. 25%: a few months. 100%: years, unless work runs in parallel at a
scale that costs real money** (Claude usage scales with the number of functions; the local Qwen is free but
handles only the easier ones).

## 6. Next steps

1. Phase 0.1-0.3 (Claude): FM gets the C files, the two-version check script, the progress report.
2. Phase 0.4: install m2c and decomp-permuter in WSL (open-source tools from GitHub).
3. Phase 1.1: split the Sony libraries out in FM, then EU.
4. Point Qwen at FM with small functions in the files that are already partly done (`xhumungus`, `ppp`).

## 7. Decisions for the owner

* **Target**: FM first with EU kept in step (recommended), or EU first.
* **Pace and cost**: how much Claude time to put into it (each session of matching uses usage); Qwen runs free
  on the PC but holds the graphics card while it works.
* **The Japanese original**: not needed for this plan; if it turns up, it only adds a third check.
