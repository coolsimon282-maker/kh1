# Names

Descriptive names given to functions and globals of the Final Mix build, with the reason for each. The names live in
`config/fm/symbol_addrs.txt` (so splat's assembly uses them too); C uses the same identifiers. Addresses are Final
Mix addresses. "probably" marks a name chosen from indirect evidence.

Names still spelled the old way in some C (src/unsplit/, xhumungus.c, and headers those include, via `#define`) are
linked to the new ones by aliases at the end of `config/fm/undefined_syms.txt`: renaming inside those files moves
other functions (rule F1).

| name | address | file | why |
|---|---|---|---|
| cdvd_QueueFileLoad | 0x00120748 | unsplit/seg_01FD30.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00120590); was func_00120590 |
| Fade_ResetIntensity | 0x001066F8 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001064E8); was func_001064E8 |
| Fade_StartOverlayIn | 0x00106978 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106790); was func_00106790 |
| Fade_StartOverlayOut | 0x00106A58 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106880); was func_00106880 |
| Fade_StartScreenIn | 0x00106780 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106578); was func_00106578 |
| Fade_StartScreenOut | 0x00106880 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106690); was func_00106690 |
| FadeTask_UpdateOverlayIn | 0x00106920 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106738); was func_00106738 |
| FadeTask_UpdateOverlayOut | 0x00106A08 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106828); was func_00106828 |
| FadeTask_UpdateScreenIn | 0x00106708 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001064F8); was func_001064F8 |
| FadeTask_UpdateScreenOut | 0x00106810 | xpancake.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00106610); was func_00106610 |
| FileLoadTask_IsActive | 0x0011F2D0 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011F0F8); was func_0011F0F8 |
| GameData_BindBuffer | 0x001EE4B8 | xtango.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001EF810); was func_001EF810 |
| GameData_Initialize | 0x001EE520 | xtango.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001EF878); was func_001EF878 |
| GameData_Reset | 0x001EE4E8 | xtango.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001EF840); was func_001EF840 |
| GameState_ApplyAvailableSelection | 0x001119D0 | xtrumpet.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001117D8); was func_001117D8 |
| GameState_BindBuffer | 0x00111288 | xtrumpet.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001110A0); was func_001110A0 |
| GameState_Initialize | 0x001117E0 | xtrumpet.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001115E8); was func_001115E8 |
| GameState_RefreshAvailableFlags | 0x001118F0 | xtrumpet.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001116F8); was func_001116F8 |
| GameState_Reset | 0x001112B8 | xtrumpet.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001110D0); was func_001110D0 |
| Graphics_Initialize | 0x00109288 | xarcade.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001090D8); was func_001090D8 |
| GraphicsDmaTask_Update | 0x001274C8 | xcream.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001274C0); was func_001274C0 |
| Interpolation_ClearValue | 0x00122768 | xowl.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00122B70); was func_00122B70 |
| Interpolation_Initialize | 0x00122BD8 | xowl.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00122FF0); was func_00122FF0 |
| PcService_Initialize | 0x0011FB00 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011F938); was func_0011F938 |
| PcService_Start | 0x0011FAD0 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011F908); was func_0011F908 |
| Script_ClampValue | 0x001C0BF0 | xkinetic.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001C2578); was func_001C2578 |
| Script_ExecuteEntry | 0x001C1D20 | xflamingo.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001C36A8); was func_001C36A8 |
| Script_GetWorkAddress | 0x001C0E50 | xkinetic.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001C27D8); was func_001C27D8 |
| Script_PushS24 | 0x001C0D20 | xkinetic.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001C26A8); was func_001C26A8 |
| ScriptOp_JumpRelative | 0x001C08F0 | xkinetic.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001C2278); was func_001C2278 |
| ScriptOp_Nop | 0x001C08E8 | xkinetic.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001C2270); was func_001C2270 |
| SoundRpc_FindCachedValue | 0x001ECED0 | xquack.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001EDF88); was func_001EDF88 |
| TaskList_FindPrevious | 0x0011F058 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011EE80); was func_0011EE80 |
| TaskList_RemoveIf | 0x0011F228 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011F050); was func_0011F050 |
| TaskList_UpdateMatching | 0x0011F130 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011EF58); was func_0011EF58 |
| TaskSystem_Initialize | 0x0011EDC8 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011EBE8); was func_0011EBE8 |
| TaskSystem_Update | 0x0011EEB0 | xgoblin.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011ECD0); was func_0011ECD0 |
| UiObject_InsertAfter | 0x001F3E48 | unsplit/seg_0EF950.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x001F4690); was func_001F4690 |
| VectorInterpolationTask_Update | 0x00122430 | xowl.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00122828); was func_00122828 |
| WorkBuffers_Clear | 0x00232AD0 | xcursed.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0022F578); was func_0022F578 |
| WorkBuffers_Get | 0x00232CC0 | xcursed.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0022F768); was func_0022F768 |
| Party_AddCharacter | 0x0013C7D8 | unsplit/seg_03BDE8.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0013C768); was func_0013C768 |
| Party_FindCharacterSlot | 0x0013C318 | unsplit/seg_03BDE8.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0013C2A8); was func_0013C2A8 |
| PartyMenu_ClearOpenRequest | 0x0011C798 | xpaste.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011C5C8); was func_0011C5C8 |
| PartyMenu_RequestOpen | 0x0011C788 | xpaste.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x0011C5B8); was func_0011C5B8 |
| PauseMenu_SelectMode | 0x001140A0 | xblade.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00113CB8); was func_00113CB8 |
| PauseMenu_Update | 0x00114280 | xblade.c | jhaton/kh1 fork (docs/external/jhaton/names_for_fm.tsv, JP 0x00113E98); was func_00113E98 |
