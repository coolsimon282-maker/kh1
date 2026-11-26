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
| pppEndAllPart | 0x0017F9D8 | ppp/pppMngr.c | Ends every running effect: stops its sound, frees its objects and marks the manager ended. |
| pppPauseAllPart | 0x0017FA68 | ppp/pppMngr.c | Sets flag 0x20 on every running effect (pppCalcAllPart skips them: probably pause). |
| pppResumeAllPart | 0x0017FAA8 | ppp/pppMngr.c | Clears flag 0x20 on every running effect (undoes pppPauseAllPart). |
| pppPausePart | 0x0017FAE8 | ppp/pppMngr.c | Sets flag 0x20 on the running effect whose handle (unk_94) is arg0. |
| pppResumePart | 0x0017FB40 | ppp/pppMngr.c | Clears flag 0x20 on the running effect whose handle (unk_94) is arg0. |
| pppEndPart | 0x0017FB98 | ppp/pppMngr.c | Ends the running effect whose handle is arg0 (sound stopped, objects freed, marked ended). |
| pppKillAllPart | 0x0017FC48 | ppp/pppMngr.c | Like pppEndAllPart, but clears each manager completely (pppClearMng). |
| pppKillPart | 0x0017FCD8 | ppp/pppMngr.c | Like pppEndPart, but clears the manager completely (pppClearMng). |
| pppEndPartInArea | 0x0017FD88 | ppp/pppMngr.c | Ends every effect whose DPD data lies in [arg0, arg0 + arg1) (e.g. before that memory is reused). |
| pppKillPartInArea | 0x0017FE60 | ppp/pppMngr.c | Like pppEndPartInArea, but clears the managers completely. |
| pppStopAllPart | 0x0017FF38 | ppp/pppMngr.c | Sets (arg0 != 0) or clears the stop bit 0x80 and unk_B7 of every running effect. |
| pppGetPartBoneNo | 0x0017FF98 | ppp/pppMngr.c | Returns the bone number (pEtc->boneNo) of the effect with handle arg0, or -2 if there is none. |
| dpd_reloc_rsd_texp | 0x0017FFD8 | ppp/pppMngr.c | Moves the texture (TBP) and CLUT (CBP) addresses in an RSD model's packets to the given VRAM blocks. |
| dpd_reloc_shape_texp | 0x00180180 | ppp/pppMngr.c | Moves the texture (TBP) and CLUT (CBP) addresses in a shape's packets to the given VRAM blocks. |
| dpd_set_object_etc | 0x001803F0 | ppp/pppMngr.c | Points the manager at etc. header number idx of a DPD and records how many texture/CLUT blocks it needs. |
| dpd_reloc_tables | 0x001804D0 | ppp/pppMngr.c | Turns the offsets in a DPD's five pointer tables into addresses (adds the base). |
| dpd_reloc | 0x00180540 | ppp/pppMngr.c | Relocates a loaded DPD file and the program data of each of its effects. |
| dpd_set_shape_texp | 0x001805B8 | ppp/pppMngr.c | For every shape the effect uses, moves its texture/CLUT addresses to the manager's VRAM blocks. |
| dpd_set_rsd_texp | 0x001806C8 | ppp/pppMngr.c | For every RSD model the effect uses, moves its texture/CLUT addresses to the manager's VRAM blocks. |
| dpd_reloc_pdata | 0x00182D58 | ppp/pppMngr.c | Relocates an effect's program data: program numbers become pppProg pointers, offsets become addresses. |
| dpd_load_tim | 0x00180AB8 | ppp/pppMngr.c | Uploads one texture image to GS memory (VRAM block offset added for relocatable images). |
| dpd_load_clut | 0x00180B40 | ppp/pppMngr.c | Uploads one CLUT (16x16 or 8x2) to GS memory. |
| dpd_load_object_tim | 0x00180C20 | ppp/pppMngr.c | Uploads the textures the effect uses. |
| dpd_load_all_tim | 0x00180CE0 | ppp/pppMngr.c | Uploads every texture of a DPD. |
| dpd_load_object_clut | 0x00180D50 | ppp/pppMngr.c | Uploads the CLUTs the effect uses. |
| dpd_load_all_clut | 0x00180E10 | ppp/pppMngr.c | Uploads every CLUT of a DPD. |
| pppGetAllWorkMemSize | 0x00181318 | ppp/pppMngr.c | Adds up the work memory size (pEtc->nWorkMemSize) of every running, not suspended effect. |
| pppSuspendOnePart | 0x00181368 | ppp/pppMngr.c | Suspends the first running effect with unk_98 < arg0: stops its sound, frees its objects, sets flag 4. |
| pppKillOneTempPart | 0x00181410 | ppp/pppMngr.c | Clears the first running effect with unk_98 < 0 (sound stopped, objects freed, manager cleared). |
| pppQuickSortF | 0x001814B0 | ppp/pppMngr.c | Quicksort of a[left..right] in descending order, swapping b[] (the indices) along. |
| pppGetFreeMng | 0x00181FE0 | ppp/pppMngr.c | Finds a free manager in ppvMngTbl, initialises it and returns it through *out. |
| pppProgIni | 0x001822F8 | ppp/pppMngr.c | Calls every program's ini function (pppProg.iniFunc) for the manager. |
| pppProgSta | 0x00182368 | ppp/pppMngr.c | Calls every program's sta function (pppProg.staFunc) for the manager. |
| pppProgEnd | 0x001823D8 | ppp/pppMngr.c | Calls every program's end function (pppProg.endFunc) for the manager. |
| pppCon2PObject | 0x00182448 | ppp/pppMngr.c | Points an object's control data at its program data and calls each program's con2 function. |
| pppConPObject | 0x001824E8 | ppp/pppMngr.c | Points an object's control data at its program data and calls each program's con function. |
| pppCreatePObject | 0x00182588 | ppp/pppMngr.c | Allocates an effect object for program data pdv, links it into the manager's list by priority and constructs it. |
| pppEndMng | 0x001827F0 | ppp/pppMngr.c | Marks a manager ended (usef bit 1 -> 2) and tells its owner through the handle (flags bit 1 -> 2). |
| pppClearMng | 0x00182840 | ppp/pppMngr.c | Clears a manager and its handle's flags. |
| pppSetMngData | 0x00182C10 | ppp/pppMngr.c | Points a manager at an effect's program data: program table, data values, start frames (calls ini if arg2). |
| pppSetEnv | 0x00182E78 | ppp/pppMngr.c | Makes env the current effect environment, copies three values from src and initialises its heap. |
| pppBirthPObject | 0x001837A8 | ppp/pppMngr.c | Creates the objects whose start frame has been reached. |
| pppCalcMng | 0x00183840 | ppp/pppMngr.c | Runs the start of a manager's frame: sta functions, new objects, calc pass. |
| pppStepMng | 0x00183878 | ppp/pppMngr.c | Runs the end of a manager's frame and advances its time by one frame; returns 1 when the effect is over. |
| pppStepMngNoCalc | 0x00183958 | ppp/pppMngr.c | Advances a manager's time by one frame without running its programs; returns 1 when the effect is over. |
| pppInitHeap | 0x00183A00 | ppp/pppMngr.c | Initialises the effect heap: one free block from start to start + size - 16 and an end block. |
| pppSortAllPart | 0x00181608 | ppp/pppMngr.c | Computes each effect's depth and sorts the effects for drawing (pppQuickSortF). |
| pppCalcAllPart | 0x00181738 | ppp/pppMngr.c | Per-frame update of every running effect (sound, render data, program calls, end handling). |
| pppDrawAllPart | 0x00181B30 | ppp/pppMngr.c | Draws every running effect in depth order (VRAM cache, texture upload, DMA of the packets). |
| ppvMngTbl | 0x00364130 | ppp/pppMngr.c | the 0x100 effect managers (ppvmng, 0xC0 bytes each): every loop over managers in pppMngr.c walks it; was D_00364130 |
| curWorldNo | 0x002BC128 | worldfile.c (data) | world index: worldfile_getNames/getBinImgName pass it to worldfile_getAbbr to build the file names (al, tw, ...); was D_002B8678 |
| curRoomNo | 0x002BC130 | worldfile.c (data) | room index: worldfile_getNames prints it + 1 as the file number (al01.ard); was D_002B8680 |
