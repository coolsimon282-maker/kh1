# Follow-ups found while matching Final Mix (for later, not for the matching agents)

## Names in shared code
Agent a4 (run 1) used FM-address names for globals that aren't in config/fm/jp_names.txt, in functions shared
with JP/EU: xbuffalo func_001C1868/1A90/1AB8 (D_0037A168, D_0037A16C), func_001C2110 (D_0037A178);
ppp/ryjProg Front/XZY/ZYX Con (D_003701D0, D_003701E0); xcream func_00128DC0/DF8 (D_00514F10),
func_00128488 (D_004F82C0, D_004F8270); xpackage func_00247CD8 (D_00469FC8), func_00247D18 (D_00491878,
D_00491880); xtrumpet func_00111468/1408 (D_002BCB68). When EU/JP catch up: map these names (the EU generator
maps names by relocation anyway) or rename to JP addresses.

## masps2.py and FM float code
tools/masps2.py always adds a nop after mfc1, c.le.s/c.lt.s, and mtc1 followed by a float op. Some FM functions
have no nop there (a4: fm_func_00111BE8, func_0018B5E8, func_00189F20, func_0018A680; the C otherwise matches).
Maybe those files were built with a different assembler or flags. Worth investigating: could unlock a class of
float functions.

## cvt.w.s
`.word 0x46000064` (cvt.w.s) can't come from plain C with this compiler (it emits trunc.w.s). Same question:
different compiler/flags for those files, or hand-written.

## Other compiler behaviour seen
- gcc emits bnel (branch-likely) where the target has bnez (xbuffalo func_001C1AE0).
- gcc turns a final call into a tail jump where the target uses jal + return (xbuffalo func_001C20B8).
Both may point at different optimisation flags for some files.

## Jump tables in files without a .rodata piece (FM)
A C `switch` that compiles to a jump table puts the table in the file's .rodata. Files placed without their own
.rodata piece in config/kh.fm.yaml (e.g. xpotato) then fail to link. a3: xpotato func_00218A38 and
func_00218AC0 match byte for byte but can't link. Fix: give xpotato (and similar files) a `.rodata` piece in the
FM layout at the right address (gen_eu_c.py would do it once the object has .rodata), then re-commit those two.

## Agents' commit hygiene (night of 21-22 Nov)
a3 run 2 committed one function while the build was failing (its `| tail -1` hid it) and reverted it; it also
amended one commit message. a4 run 2 and a6 run 2 made batch commits (a6 reverted and re-committed singly).
The fm branch built OK after every merge.

## Strict aliasing in xtoaster / xgoblin?
a6 (run 3): xgoblin func_0011EEB8 and xtoaster func_00123350 matched in test compiles only with
-fno-strict-aliasing; committed with a one-member-union read instead. Those files may have been built without
strict aliasing like src/ppp/. Check: compile every matched function in those files with and without the flag;
if all are identical, add them to the -fno-strict-aliasing list in configure.py.

## GCC 2.96 sometimes compiles a function 4 bytes longer after unrelated edits (xhumungus)
a1 (run 3): func_001DB7A8 and fm_func_001DC9A0 occasionally fail to fold an array symbol into the address after
edits elsewhere in xhumungus.c (looks like the compiler reading uninitialised memory). The merged fm built OK at
01:02. If a later merge suddenly fails with a clean diff in the edited function, compare function sizes in the
object against a good build (a1's szcmp.sh in scratchpad\a1) and check these two first.

## -g per file
Files with soft-float calls may need building without -g (the assembler leaves call delay slots empty with -g;
the original has them filled): pppKeMvYpEff.c and draw.c so far (NO_G_FILES). a4's survey said matched code is
identical either way except xapple/xball/xblade/xhumungus/xjockey, but making no -g the default broke the
build from xbeginning on (0x10 bytes short, 22 Nov 01:40). Before flipping the default again: find which files
really change (build each file both ways and compare the whole object including INCLUDE_ASM parts).
a1 run 4 (fm-a1): 207f51d is labelled CC130 but is a broken half CF128 (reverted by 4c339ba; b95709d is the real
CC130); 894e3f1/43c6da8 have scratch paths in their messages; a2e2a82 is func_001CC240 labelled C9DB0 and
briefly left the size-flicker state (fixed by d02303b). Code at the merge builds OK.

## xblade: func_00114B50 depends on the number of declarations in the file
a5 (run 5): func_00114B50's code changes with how many functions xblade.c declares; implicitly declared callees
in a new match broke it (fixed by a real prototype for func_001336A0). Any later xblade match must re-check it.
