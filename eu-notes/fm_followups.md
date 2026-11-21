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
