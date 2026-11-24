# Recording the work: instructions for every worker and coordinator

Every attempt is kept so the owner and Claude can read the work back and improve how it is done: which tries are
wasted, what each worker was given before it failed, which rules should go into MATCHING.md and the job packets.
Output written by Claude (agents a*/f* and coordinating sessions) is for that review only and is not used to train
any model. A future PS2 decompiler model would be trained only on the local/open models' attempts (Qwen: q*, r*) and
on pairs made by compiling open-source C with the same compilers. **A failed attempt with its reason is as valuable as a match.** So the
rule is: nothing useful is thrown away, and what you learn is written down where a program can find it.

The data lives in `kh1-study\dataset\` (outside the repository: never committed, never published). Its layout is
described in `kh1-study\dataset\README.md`.

## What is recorded for you (you do nothing)

Because every command goes through `agent-tools.sh`, these are written automatically:

| What | Where | When |
|---|---|---|
| Every tool call with its full output: the job packet from `next`, m2c drafts, look-alike functions, comparisons, build verdicts | `dataset\calls\<workspace>.jsonl` | every `agent-tools.sh` call |
| Every attempt: the C tried (as a diff of the source file), the target assembly, the comparison, the result, and the compiler and flags the file is built with | `dataset\attempts\<workspace>.jsonl` | every `quick`, `try`, `giveup` |
| Every lesson | `dataset\lessons\<workspace>.jsonl` | every `lesson` |

This only works if you use the tools. **Do not compile or compare by hand** (calling the compiler, `quickcmp.py`
or `ninja` directly): an attempt made that way leaves no record. If a tool cannot do what you need, say so in
your notes so the tool can be extended.

## What you must do yourself

1. **Always go through `put` + `quick` (or `try`)** for each variant you test, even ones you expect to fail. One
   variant per call: the sequence "this C gave this difference, so I changed that" is the training signal.
2. **When a trick makes a function match, record it:**
   `wsl -e bash ./agent-tools.sh lesson <file> <func> "<what the difference looked like> -> <what fixed it>"`
   Write it so it stands alone, e.g. `"bnel where the target has bne after a jal -> callee only declared; added
   NOTHROW(void, func_00123456)"`. Name instructions and registers, not "it was off by a bit".
3. **When you give a function up, say exactly why**, as a lesson too (and as your notes line):
   `lesson <file> <func> "gave up: 3 of 41 off, $s0/$s1 swapped in the loop; tried reordering declarations, a
   temp for the base pointer, index loop; closest attempt work/f_0012.c"`. Include how far off, what differs,
   what you tried, and where the closest attempt is.
4. **Commit messages carry the trick.** `Match <func> (<file>)` in the subject, and in the body one or two
   sentences on what was not obvious. The matched C plus that sentence is a training example by itself.
5. **Keep your scratch files.** Never delete or overwrite a work file that was an attempt: give each variant its
   own name (`work/<func>_1.c`, `_2.c`, ...). They are collected.
6. **Record facts about the compiler and the platform as rules**, in your notes file under a dated heading and as
   a lesson on the function that proved them: which source shape gives which instruction pattern, which flag a
   file needs, what the assembler does to delay slots. State the compiler (ee-gcc 2.96 for game code and
   libc/libm/libgcc; ee-gcc 2.9-991111 for Sony's libraries), because the future model must cover both.
7. **Record what is NOT C.** Hand-written assembly (system-call stubs, 128-bit MMI string routines, exception
   handlers), jump tables, vector-unit code: one lesson line saying what it is and how you could tell. Knowing
   what to refuse is part of the job the model has to learn.
8. **Record the type and name knowledge you recover**: when you work out a struct layout, a function's real
   prototype, or what a data symbol is, put it in the headers or as a comment by the definition, not only in
   your head. Types are half of what makes a draft match on the first try.

## For whoever coordinates (a Claude session)

- Run `python kh1-study\dataset\collect.py` at the end of each working session: it copies the work files, the
  build histories, the notes, and OpenCode's session database (Qwen's sessions) into the dataset folder.
- When you change the tools, keep the logging: a new command that compiles or compares must call
  `tools/logattempt.py`; anything a worker reads must go through `agent-tools.sh` so `tools/logcall.py` sees it.
- When you set up a new game or compiler, keep the same record shapes and fill in `game`, `platform`, `compiler`,
  `flags` in `tools/logattempt.py`, so sets from different games can be joined.
- Put every worker's instructions under these rules: the brief you give an agent must point at this file.
- Reading the logs back for improvements: `dataset\attempts` grouped by function shows where tries are wasted
  (compile errors, repeated identical differences); `dataset\calls` shows what each worker was given before it
  failed; `dataset\lessons` is the list of rules to fold into `MATCHING.md` and the job packets.
