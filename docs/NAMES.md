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
| Iop_LoadModules | 0x0011ECD8 | xgoblin.c | Loads the IOP modules (sio2man.irx, ..., ds2o.irx twice, ..., libssl.irx) and starts the services that use them. |
| TaskList_Add | 0x0011F090 | xgoblin.c | Takes a free entry, fills it in and links it into the list sorted by priority (unk_04). |
| TaskList_FindByFunc | 0x0011F2E0 | xgoblin.c | Returns the task in the list whose function is arg1 (0 if none). |
| TaskList_Unlink | 0x0011F320 | xgoblin.c | Unlinks task arg1 from the list; returns 1 if it was there. |
| TaskList_FindFree | 0x0011EFE8 | xgoblin.c | Finds a free entry (unk_00 == 0) in the pool, searching on from the last one handed out (unk_0C). |
| TaskSystem_RemoveTask | 0x0011EF58 | xgoblin.c | Unlinks the main-list task that runs function func, if there is one. |
| TaskSystem_FindTask | 0x0011EF38 | xgoblin.c | Looks a task up by its function in the main task list (the result is not used). |
| Pad_ReadSticks | 0x0011F370 | xgoblin.c | Reads both analog sticks with a dead zone (D_002C5C20): direction bits for the d-pad, unit and scaled vectors. |
| Pad_UpdateButtons | 0x0011F548 | xgoblin.c | Updates held/pressed/released buttons and the key-repeat timers (first delay D_002C5C24, then D_002C5C28). |
| Pad_MapButtons | 0x0011F628 | xgoblin.c | Maps raw button bits to game buttons through the table D_002C1EE0. |
| Pad_Update | 0x0011F668 | xgoblin.c | Reads the controller (scePad2), sets vibration, updates the button state and the game's mapped copy. |
| Pad_Reset | 0x0011F988 | xgoblin.c | Resets the controller state and the dead zone / key-repeat settings. |
| Pad_Initialize | 0x0011FA88 | xgoblin.c | Initialises the controller library (sceDbcInit, scePad2Init) and opens the pad socket. |
| GsPacket_AddReg | 0x0011FB38 | xgoblin.c | Writes one A+D pair (value arg1, register arg0) and returns the next position. |
| GsPacket_SetGifTag | 0x0011FB48 | xgoblin.c | Writes a GIF tag for the A+D data up to arg2 (one register, A+D; arg1 = EOP). |
| GsPacket_SetDmaTag | 0x0011FB78 | xgoblin.c | Writes a DMA tag (QWC up to arg2, ID arg1; scratchpad address bit for 0x70000000+). |
| GsPacket_LoadImage | 0x0011FBB0 | xgoblin.c | Builds a DMA chain that uploads an image to GS memory (BITBLTBUF, TRXPOS, TRXREG, TRXDIR, then the data). |
| TaskSystem_AddTask | 0x0011EF10 | xgoblin.c | Adds a task with priority prio and function func to the main task list. |
| TaskList_Init | 0x0011EFA8 | xgoblin.c | Sets up a task list over a pool of count entries of size bytes each, all free. |
| Fade_IsBlack | 0x001063C8 | xpancake.c | Returns 1 when the screen is faded out (screen colour 0) or the overlay is fully in (128). |
| Fade_IsActive | 0x001063F8 | xpancake.c | Returns 1 while a fade is not back to normal (screen not 128, overlay not 0, or D_002A6204 set). |
| FadeTask_UpdateIris | 0x00106460 | xpancake.c | Wipe task: shrinks or grows the rectangle around the centre each frame; ends (returns 4) when done. |
| Fade_StartIrisClose | 0x001065A8 | xpancake.c | Starts a wipe that closes on the point (c, d) over a frames, down to size b. |
| Fade_StartIrisOpen | 0x00106648 | xpancake.c | Starts a wipe that opens from the point (c, d) over a frames, from size b. |
| fadeScreenColor | 0x002BC070 | xpancake.c | screen brightness RGBA (0..128) the screen fade tasks write; was D_002B85C0 |
| fadeOverlayAlpha | 0x002BC0BC | xpancake.c | overlay alpha (0..128) the overlay fade tasks write; was D_002B860C |
| fadeTaskList | 0x002BC720 | xpancake.c | task list (xgoblin.c) every fade task is added to; was D_002B8C70 |
| Interpolation_StartVector | 0x001224C8 | xowl.c | Moves vec[3] to target over time (at once if time <= 0), calling done when it gets there. |
| Light_CalcAmbient | 0x00122588 | xowl.c | Computes an object's ambient colour and the mask of directional/point/spot lights that reach it. |
| Light_Add | 0x001226F0 | xowl.c | Takes a free light, sets its type, flags and unk_08 and a default colour; returns it (NULL if none is free). |
| Light_GetDirMatrix | 0x00122770 | xowl.c | Builds the light direction matrix for an object at pos from the lights in its mask (spot/point falloff included). |
| Light_GetColorMatrix | 0x001229C0 | xowl.c | Builds the light colour matrix for an object from the lights in its mask, ambient colour in row 3. |
| LightTask_Update | 0x00122AB0 | xowl.c | Per-frame task: runs the interpolation tasks, recomputes the global ambient colour and handles type 3 lights. |
| Light_ClearTemporary | 0x00122C08 | xowl.c | Frees every temporary light (flag 8) and resets the interpolation tasks. |
| Light_DisableTemporary | 0x00122C70 | xowl.c | Sets flag 0x10 (ignored) on every temporary light. |
| Light_EnableAll | 0x00122CB8 | xowl.c | Clears flag 0x10 on every light. |
| Light_Initialize | 0x00122CF0 | xowl.c | Clears every light, adds the default directional light (0, 1, 0, white) and starts LightTask_Update. |
| lightTbl | 0x002C5C80 | xowl.c | the 31 lights (0x40 bytes: type, flags, range, position, direction, colour) every Light_ function walks; was D_002C5C80 |
| interpTaskList | 0x004F6EC0 | xowl.c | task list of the vector interpolation tasks (Interpolation_Initialize); was D_004FA670 |
| ScriptOp_ApplyOperator | 0x001CD208 | xkinetic.c / xhumungus.c | Opcode 1 APPLY_OPERATOR (entry 1 of scriptOpTable; in xhumungus.c) |
| ScriptOp_JumpIfFalse | 0x001C0910 | xkinetic.c / xhumungus.c | Opcode 3 JUMP_IF_FALSE: pops a value and jumps by the operand if it is 0. |
| ScriptOp_Reserved04 | 0x001C0960 | xkinetic.c / xhumungus.c | Opcode 4 (unused): does nothing. |
| ScriptOp_End | 0x001C0B40 | xkinetic.c / xhumungus.c | Opcode 5 END. |
| ScriptOp_SaveSwitchValue | 0x001C0968 | xkinetic.c / xhumungus.c | Opcode 6 SAVE_SWITCH_VALUE: pops a value into switch slot operand and makes it the current one. |
| ScriptOp_SwitchEq | 0x001C09A0 | xkinetic.c / xhumungus.c | Opcode 7 SWITCH_EQ: pushes (current switch value == operand). |
| ScriptOp_PopSwitchValue | 0x001C0B28 | xkinetic.c / xhumungus.c | Opcode 8 POP_SWITCH_VALUE: drops the current switch value. |
| ScriptOp_LoadLocal | 0x001C0D70 | xkinetic.c / xhumungus.c | Opcode 10 LOAD_LOCAL: pushes local variable operand. |
| ScriptOp_StoreLocal | 0x001C13B8 | xkinetic.c / xhumungus.c | Opcode 11 STORE_LOCAL: pops a value into local variable operand. |
| ScriptOp_LoadVar8 | 0x001C0F30 | xkinetic.c / xhumungus.c | Opcode 12 LOAD_VAR8: pushes an 8-bit game variable. |
| ScriptOp_StoreVar8 | 0x001C13E8 | xkinetic.c / xhumungus.c | Opcode 13 STORE_VAR8. |
| ScriptOp_LoadVar16 | 0x001C1118 | xkinetic.c / xhumungus.c | Opcode 14 LOAD_VAR16: pushes a 16-bit game variable. |
| ScriptOp_StoreVar16 | 0x001C1628 | xkinetic.c / xhumungus.c | Opcode 15 STORE_VAR16. |
| ScriptOp_LoadVar32 | 0x001C11D8 | xkinetic.c / xhumungus.c | Opcode 16 LOAD_VAR32: pushes a 32-bit game variable. |
| ScriptOp_StoreVar32 | 0x001C1718 | xkinetic.c / xhumungus.c | Opcode 17 STORE_VAR32. |
| ScriptOp_Reserved18 | 0x001C1318 | xkinetic.c / xhumungus.c | Opcode 18 (unused): does nothing. |
| ScriptOp_Reserved19 | 0x001C1320 | xkinetic.c / xhumungus.c | Opcode 19 (unused): does nothing. |
| ScriptOp_Reserved20 | 0x001C1328 | xkinetic.c / xhumungus.c | Opcode 20 (unused): does nothing. |
| ScriptOp_PushS24Alt | 0x001C1960 | xkinetic.c / xhumungus.c | Opcode 21 PUSH_S24_ALT: pushes the operand without clamping. |
| ScriptOp_StartThread | 0x001C19F8 | xkinetic.c / xhumungus.c | Opcode 22 START_THREAD: pops a script number and a slot (0-7) and starts entry operand there. |
| ScriptOp_WaitThread | 0x001C1AA8 | xkinetic.c / xhumungus.c | Opcode 23 WAIT_THREAD. |
| ScriptOp_CallCommand | 0x001DCAD0 | xkinetic.c / xhumungus.c | Opcode 24 CALL_COMMAND (entry 24 of scriptOpTable; in seg_0DDC78) |
| ScriptOp_StopThread | 0x001C1B58 | xkinetic.c / xhumungus.c | Opcode 25 STOP_THREAD: pops a script number and a slot and stops that thread (6 if it is this script). |
| ScriptOp_SwitchLt | 0x001C09E8 | xkinetic.c / xhumungus.c | Opcode 26 SWITCH_LT: pushes (current switch value < operand). |
| ScriptOp_SwitchLe | 0x001C0A38 | xkinetic.c / xhumungus.c | Opcode 27 SWITCH_LE: pushes (current switch value <= operand). |
| ScriptOp_SwitchGt | 0x001C0A88 | xkinetic.c / xhumungus.c | Opcode 28 SWITCH_GT: pushes (current switch value > operand). |
| ScriptOp_SwitchGe | 0x001C0AD8 | xkinetic.c / xhumungus.c | Opcode 29 SWITCH_GE: pushes (current switch value >= operand). |
| ScriptOp_LoadWorkBit | 0x001C1330 | xkinetic.c / xhumungus.c | Opcode 30 LOAD_WORK_BIT. |
| ScriptOp_StoreWorkBit | 0x001C1880 | xkinetic.c / xhumungus.c | Opcode 31 STORE_WORK_BIT. |
| Script_ReadWork | 0x001C0DA0 | xkinetic.c | Reads 1, 2 or 4 bytes at offset arg0 of work buffer 2 into *arg2. |
| Script_WriteWork | 0x001C0E80 | xkinetic.c | Writes 1, 2 or 4 bytes from *arg2 to offset arg0 of work buffer 2. |
| Script_GetOpcode | 0x001C1CE8 | xkinetic.c | Returns the opcode (top byte) of instruction arg1 at arg0. |
| Script_GetOperand | 0x001C1CF8 | xkinetic.c | Returns the signed 24-bit operand of instruction arg1 at arg0. |
| scriptOpTable | 0x0037A198 | xkinetic.c | the 32 opcode handlers, in the order of jhaton's OPCODE_NAMES (6 checked against the handlers' code); was D_003759E0 |
| SoundRpc_Initialize | 0x001EC7D0 | xquack.c | Clears the buffers, binds the sound RPC server (id 0x11, retrying) and sends command 0 with the voice-state buffers. |
| SoundRpc_IsVoiceActive | 0x001ECB08 | xquack.c | Returns 1 if one of the 24 voices plays sound arg0 (with arg1 / arg2 matching unless < 0). |
| soundRpcClient | 0x003E3C88 | xquack.c | the sceSifClientData every sound RPC call goes through (bound to id 0x11 by SoundRpc_Initialize); was D_003DE5C0 |
| soundRpcBuf | 0x00633640 | xquack.c | the 0x2000-byte send/receive buffer of every sound RPC call; was D_0062D980 |
| Gs_LoadClut16 | 0x00100D18 | xbeginning.c | Uploads a 16-colour CLUT (8x2, PSMCT32) to GS block dbp. |
| Gs_LoadClut256 | 0x00100D90 | xbeginning.c | Uploads a 256-colour CLUT (16x16, PSMCT32) to GS block dbp. |
| Gs_LoadTex4_512x256 | 0x00100E08 | xbeginning.c | Uploads a 512x256 4-bit texture (PSMT4) to GS block dbp. |
| Gs_LoadTex8_256x256 | 0x00100E80 | xbeginning.c | Uploads a 256x256 8-bit texture (PSMT8) to GS block dbp. |
| Gs_LoadTex8H_256x1024 | 0x00100EF8 | xbeginning.c | Uploads a 256x1024 PSMT8H texture to GS block dbp. |
| Room_LoadBinImg | 0x001015A8 | xporcupine.c | Queues the load of worldBinImgFile + ".img" into a newly allocated buffer (D_002A050C). |
| KeLnsFlr_SetShape | 0x001A5688 | ppp/xberry.c | sets a flare's frame count from the shape data and restarts its sequence |
| KeLnsFlr_Step | 0x001A56A0 | ppp/xberry.c | steps a flare's shape animation by 0x200 (looping on flag 0x80) |
| KeLnsShp_SetDraw | 0x001A5740 | ppp/xberry.c | sets up the draw of the current shape frame (func_001BA340) |
| KeLnsClm_SetShape | 0x001A5FD0 | ppp/xberry.c | sets the shape of every flare of a KeLnsClm and seeds their phases once |
| KeLnsShp_Draw | 0x001A60E8 | ppp/xberry.c | draws a flare shape at the lens position, alpha scaled by the lens power (cf. KeLnsFls_Draw) |
| KeLnsStr_Draw | 0x001A62C0 | ppp/xberry.c | draws a flare shape stretched along the lens direction (zMat) |
| KeLnsCrn_SetShape | 0x001A6518 | ppp/xberry.c | sets a KeLnsCrn's shape and its flare (KeLnsFlr_SetShape) |
| op_seed_vu0_rand | 0x001AA080 | ppp/draw/draw.c | seeds the VU0 random register from rand() (existing comment) |
| op_log2_ceil | 0x001AA0A8 | ppp/draw/draw.c | Returns the number of bits needed for n (the smallest b with 1 << b >= n). |
| op_load_tim2 | 0x001AA0E0 | ppp/draw/draw.c | Uploads a TIM2 picture's image (and CLUT, if it has one) to GS memory. |
| op_ot_insert0 | 0x001AA6B0 | ppp/draw/draw.c | inserts a packet into ordering table 0 (16 priorities) |
| op_ot_insert1 | 0x001AA700 | ppp/draw/draw.c | inserts a packet into ordering table 1 (16 priorities) |
| op_ot_insert2 | 0x001AA750 | ppp/draw/draw.c | inserts a packet into ordering table 2 (256 priorities) |
| op_fill_sprite | 0x001AA7A0 | ppp/draw/draw.c | builds an alpha + full-screen sprite packet in one colour and puts it in OT 1 |
| GameState_SaveMemberPos | 0x00111340 | xtrumpet.c | Stores party member i's position (+0x10) and angle (+0x3C) in gameState vector i. |
| GameState_SavePositions | 0x00111380 | xtrumpet.c | Saves the location and the position of each of the three party members (D_002E26A0) that exists. |
| GameState_SetPresetPositions | 0x001113F8 | xtrumpet.c | Saves member 0's position, and members 1 and 2 from preset entry index (D_002BCDA0) instead. |
| GameState_SaveLocation | 0x00111480 | xtrumpet.c | Saves curWorldNo, curRoomNo, D_002B92F8 and the eight words func_0017F1C8 returns. |
| GameState_SaveRoomPositions | 0x00111510 | xtrumpet.c | Saves the location; rooms listed in presetPosRooms use the preset positions, the others the actual ones. |
| GameState_GetPosition | 0x00111590 | xtrumpet.c | Copies gameState vector index to out. |
| gameState | 0x002BCB60 | xtrumpet.c | pointer to the game state in work buffer 3 (GameState_BindBuffer sets it); was D_002B90B0 |
| presetPosRooms | 0x002BCB80 | xtrumpet.c | 39 (world, room, preset index) entries: rooms whose saved party positions come from a preset; was D_002BCB80 |
| PlayTime_GetFrames | 0x001EE118 | xtango.c | Play time in frames: the frame counter D_002BBDF4 times the scale D_002BBDEC. |
| PlayTime_GetTotalHours | 0x001EE198 | xtango.c | Play time in whole hours (frames / 216000, 60 frames a second). |
| PlayTime_GetTotalMinutes | 0x001EE1D0 | xtango.c | Play time in whole minutes (frames / 3600). |
| PlayTime_GetTotalSeconds | 0x001EE200 | xtango.c | Play time in whole seconds (frames / 60). |
| PlayTime_Split | 0x001EE230 | xtango.c | Splits the play time into hours, minutes, seconds and frames. |
| PlayTime_GetHoursPart | 0x001EE2D0 | xtango.c | Hours part of the play time (same as PlayTime_GetTotalHours). |
| PlayTime_GetMinutesPart | 0x001EE308 | xtango.c | Minutes part of the play time (0..59). |
| PlayTime_GetSecondsPart | 0x001EE348 | xtango.c | Seconds part of the play time (0..59). |
| PlayTime_GetHundredthsPart | 0x001EE388 | xtango.c | Frames part of the play time scaled to hundredths of a second. |
| BcdToInt | 0x001EE488 | xtango.c | Converts a BCD number (one decimal digit per nibble) to binary. |
| Char_GetName | 0x001EE5F0 | xtango.c | Name message of character arg0 (message id from D_003DE5F0); probably the name. |
| Party_GetMemberName | 0x001EE618 | xtango.c | Name message of the character in party slot arg0 (D_003010F8->unk_48E); probably the name. |
| Item_GetData | 0x001EE680 | xtango.c | Item table entry of item arg0 (func_00147A88). |
| Item_GetName | 0x001EE698 | xtango.c | Name string of item arg0 (from its entry's unk_00), or message 151 for item 0. |
| Item_GetDescription | 0x001EE6D0 | xtango.c | Entry unk_0C of item arg0 (1..255), else 0; probably the description string. |
| Item_GetType | 0x001EE768 | xtango.c | Item category (entry unk_02): 0 usable item, 1 accessory, 2..11 weapons (by how Char_CountItemEquipped uses it). |
| Item_IsPartyWide | 0x001EE7C8 | xtango.c | Bit 0 of entry unk_04; when set func_001EFBB0 checks every party member, so probably "acts on the whole party". |
| Item_IsUsable | 0x001EE9E0 | xtango.c | Item type is 0 (usable item). |
| Item_CanCharEquip | 0x001EEA00 | xtango.c | False when arg0 is a weapon (type 2..11) of another type than character arg1's weapon type (D_003E3D20). |
| Item_GetNameOrNone | 0x001EEB88 | xtango.c | Item_GetName, or message 167 for item 0 (FM). |
| Item_GetNameOrNone2 | 0x001EEBB0 | xtango.c | Same as Item_GetNameOrNone (a second copy in the game). |
| Item_GetDescriptionOrNone | 0x001EEBD8 | xtango.c | Item_GetDescription, or message 168 for item 0 (FM). |
| Item_GetDescriptionOrNone2 | 0x001EEC00 | xtango.c | Same as Item_GetDescriptionOrNone (a second copy in the game). |
| Char_PreviewWeaponStat19 | 0x001EEC48 | xtango.c | Character arg0's stat 19 (func_00141B10 stats) with weapon arg1 equipped for the test; probably strength. |
| Char_PreviewAccessoryStat15 | 0x001EECB0 | xtango.c | Character arg0's stat 15 with accessory slot arg1 set to arg2 for the test. |
| Char_PreviewAccessoryStat17 | 0x001EED18 | xtango.c | Character arg0's stat 17 with accessory slot arg1 set to arg2 for the test. |
| Char_PreviewAccessoryMaxAP | 0x001EED80 | xtango.c | Character arg0's stat 56 (max AP, see Char_GetMaxAP) with accessory slot arg1 set to arg2. |
| Char_PreviewAccessoryStat19 | 0x001EEDE8 | xtango.c | Character arg0's stat 19 with accessory slot arg1 set to arg2 for the test. |
| Char_PreviewAccessoryStat20 | 0x001EEE50 | xtango.c | Character arg0's stat 20 with accessory slot arg1 set to arg2 for the test. |
| Party_CountWeaponUsers | 0x001EEEB8 | xtango.c | Number of current party members whose weapon (unk_32) is arg0. |
| Party_CountAccessoryEquipped | 0x001EEF38 | xtango.c | Number of arg0 accessories equipped by current party members. |
| Char_CountAccessoryOnOthers | 0x001EEFD8 | xtango.c | Number of arg0 accessories equipped by the ten characters other than arg1. |
| Char_CountEquippedAll | 0x001EF050 | xtango.c | Number of arg0 equipped (as weapon or accessory) by all ten characters. |
| Inventory_GetFreeCount | 0x001EF0C0 | xtango.c | Stock of item arg0 (unk_499) minus the copies equipped by the ten characters, at least 0. |
| Char_CountItemEquipped | 0x001EF140 | xtango.c | How many arg1 character arg0 holds: in item slots (type 0), accessory slots (type 1) or as weapon. |
| Item_GetWeaponIndex | 0x001EF250 | xtango.c | Item type - 2 (weapon type index). |
| Item_IsWeaponType | 0x001EF270 | xtango.c | Item arg0's type is weapon type D_003DE630[idx]. |
| Item_IsWeapon | 0x001EF2C0 | xtango.c | Item arg0's type is one of the ten weapon types in D_003DE630. |
| Item_IsAccessory | 0x001EF370 | xtango.c | Item arg0 is non-zero and of type 1 (accessory). |
| Char_GetAbilityCount | 0x001EF3A0 | xtango.c | Number of abilities in character arg0's ability list (unk_40, 0-terminated, 48 max). |
| Char_CountAbility | 0x001EF450 | xtango.c | Number of entries of ability arg1 in character arg0's list (bit 0x80 ignored). |
| Ability_GetData | 0x001EF528 | xtango.c | Ability table entry (func_00147AE8). |
| Ability_GetName | 0x001EF540 | xtango.c | Entry unk_04 of ability arg0 (bit 0x80 cleared), or message 180 (FM); probably the name. |
| Ability_GetDescription | 0x001EF580 | xtango.c | Entry unk_08 of ability arg0, or message 180 (FM); probably the description. |
| Ability_GetApCost | 0x001EF5C0 | xtango.c | Entry unk_00 of ability arg0; summed by Char_GetUsedAP, so the AP cost. |
| Char_GetMaxAP | 0x001EF658 | xtango.c | Stat 56 of character arg0 (D_003E3E50 = D_003E3D70 + 0xE0, the stats func_00141B10 fills); max AP by Char_GetFreeAP. |
| Char_GetUsedAP | 0x001EF680 | xtango.c | Sum of the AP cost of character arg0's abilities without bit 0x80 (equipped ones, probably). |
| Char_GetFreeAP | 0x001EF720 | xtango.c | Character arg0's stat 56 minus Char_GetUsedAP, at least 0. |
| Munny_Set | 0x001EF778 | xtango.c | Sets munny (at most 99999). |
| Munny_Get | 0x001EF7A0 | xtango.c | Returns munny. |
| Munny_Add | 0x001EF7B0 | xtango.c | Adds to munny, clamped to 0..99999. |
| Munny_Sub | 0x001EF7F0 | xtango.c | Subtracts from munny, clamped to 0..99999. |
| Party_RefreshStats | 0x001EF830 | xtango.c | Counts party members (D_003E3D6C, D_003DE6A0 with slot 3) and recomputes the stats (D_003E3D70) of all ten characters. |
| GameData_ResetCharPresets | 0x00216180 | xpotato.c | Sets the preset (GameData unk_20[i]) of all ten characters to 4 and applies it. |
| GameData_ApplyCharPreset | 0x002161E8 | xpotato.c | Applies preset arg1 to character arg0: nine func_00170D60(arg0, i, value) calls from table D_003F41E8[arg1], or the character's own D_003F4200 row for preset 4. |
| Config_Reset | 0x00219128 | xpotato.c | Clears the config options (GameData words 0x00..0x18), option 6 (+0x2C) = 1 in FM. |
| Config_Get | 0x00219158 | xpotato.c | Returns config option arg0 (0..6: GameData +0x00, 0x04, 0x08, 0x10, 0x14, 0x18, 0x2C). |
| Config_Set | 0x002191F0 | xpotato.c | Sets config option arg0 (same order as Config_Get). |
| Config_GetOption0 | 0x00219288 | xpotato.c | Config option 0 (GameData +0x00). |
| Config_GetOption0Wrap | 0x00219298 | xpotato.c | Calls Config_GetOption0. |
| Config_SetOption0 | 0x002192B0 | xpotato.c | Sets config option 0. |
| Config_GetOption1 | 0x002192C0 | xpotato.c | Config option 1 (GameData +0x04). |
| Config_GetOption1Wrap | 0x002192D0 | xpotato.c | Calls Config_GetOption1. |
| Config_SetOption1 | 0x002192E8 | xpotato.c | Sets config option 1. |
| Config_GetOption2 | 0x002192F8 | xpotato.c | Config option 2 (GameData +0x08). |
| Config_GetOption2Wrap | 0x00219308 | xpotato.c | Calls Config_GetOption2. |
| Config_SetOption2 | 0x00219320 | xpotato.c | Sets config option 2. |
| Config_GetOption3 | 0x00219348 | xpotato.c | Config option 3 (GameData +0x10). |
| Config_GetOption3Wrap | 0x00219358 | xpotato.c | Calls Config_GetOption3. |
| Config_SetOption3 | 0x00219370 | xpotato.c | Sets config option 3. |
| Config_GetOption4 | 0x00219380 | xpotato.c | Config option 4 (GameData +0x14). |
| Config_GetOption4Wrap | 0x00219390 | xpotato.c | Calls Config_GetOption4. |
| Config_SetOption4 | 0x002193A8 | xpotato.c | Sets config option 4. |
| Config_GetOption5 | 0x002193B8 | xpotato.c | Config option 5 (GameData +0x18). |
| Config_GetOption5Wrap | 0x002193C8 | xpotato.c | Calls Config_GetOption5. |
| Config_SetOption5 | 0x002193E0 | xpotato.c | Sets config option 5. |
| Config_GetOption6 | 0x002193F0 | xpotato.c | Config option 6 (GameData +0x2C, FM only). |
| Config_GetOption6Wrap | 0x00219400 | xpotato.c | Calls Config_GetOption6. |
| Config_SetOption6 | 0x00219418 | xpotato.c | Sets config option 6. |
| ConfigMenu_UpdateOption0 | 0x00219A88 | xpotato.c | Config menu page for option 0: two choices (D_003F4790), the selection written to GameData +0x00; pad bit 0x4000 closes it. |
| ConfigMenu_UpdateOption1 | 0x00219C18 | xpotato.c | Config menu page for option 1 (choices D_003F4798, GameData +0x04). |
| ConfigMenu_UpdateOption2 | 0x00219DA8 | xpotato.c | Config menu page for option 2 (choices D_003F47A0, GameData +0x08). |
| NativeCmd_SinDeg | 0x00128DE0 | xaudacity.c | Native command 2 (1 arg, returns a value): sine of the angle a0 in degrees (wrapped by func_00120AC8). |
| NativeCmd_CosDeg | 0x00128E38 | xaudacity.c | Native command 3 (1 arg, returns a value): cosine of the angle a0 in degrees. |
| NativeCmd_DegToRad | 0x00128F10 | xaudacity.c | Native command 149 (1 arg, returns a value): a0 degrees to radians (wrapped by func_00120AC8). |
| NativeCmd_AddVector | 0x00128FF8 | xaudacity.c | Native command 7 (2 args): vector a0 += a1. |
| NativeCmd_SubVector | 0x00129020 | xaudacity.c | Native command 8 (2 args): vector a0 -= a1. |
| NativeCmd_RotateVectorY | 0x00129068 | xaudacity.c | Native command 10 (2 args): rotates vector a0 about Y by a1 degrees. |
| NativeCmd_RotateVectorZ | 0x001290D8 | xaudacity.c | Native command 31 (2 args): rotates vector a0 about Z by a1 degrees. |
| NativeCmd_RotateVectorXYZ | 0x00129270 | xaudacity.c | Native command 144 (2 args): rotates vector a0 by the X/Y/Z angles in degrees of vector a1. |
| NativeCmd_AddScaledVector | 0x00129148 | xaudacity.c | Native command 18 (3 args): vector a0 += a1 * a2 * D_002B8344[0] (D_002B8344[0] is probably the frame time step). |
| NativeCmd_ScaleVector | 0x001291E8 | xaudacity.c | Native command 93 (2 args): scales vector a0 (XYZ) by a1. |
| NativeCmd_FaceVector | 0x00129388 | xaudacity.c | Native command 11 (2 args): object a0's angle unk_150 = atan2 of vector a1 (x, z), applied with func_00137688. |
| NativeCmd_SetAngleFromVector | 0x00129530 | xaudacity.c | Native command 36 (2 args): object a0's angle unk_150 = atan2 of vector a1 (x, z), without applying it. |
| NativeCmd_SetFlags1CC | 0x00129AE0 | xaudacity.c | Native command 111 (2 args): object a0's flags unk_1CC |= a1. |
| NativeCmd_ClearFlags1CC | 0x00129AF8 | xaudacity.c | Native command 112 (2 args): object a0's flags unk_1CC &= ~a1. |
| NativeCmd_SetFlags3A4 | 0x00129BB8 | xaudacity.c | Native command 116 (4 args): ors a1, a2, a3 into object a0's flag words unk_3A4, unk_3A8, unk_3AC. |
| NativeCmd_ClearFlags3A4 | 0x00129BF0 | xaudacity.c | Native command 117 (4 args): clears a1, a2, a3 from object a0's flag words unk_3A4, unk_3A8, unk_3AC. |
| NativeCmd_AddLight | 0x0012AD78 | xaudacity.c | Native command 52 (3 args, returns a value): a0 = Light_Add(a0, a1 | 8, a2). |
| NativeCmd_ClearInterpolation | 0x0012ADB0 | xaudacity.c | Native command 53 (1 arg): Interpolation_ClearValue(a0). |
| NativeCmd_StartInterpolation | 0x0012ADC8 | xaudacity.c | Native command 201 (3 args): Interpolation_StartVector(a0, a1, a2, NULL). |
| NativeCmd_SetAngles16 | 0x0012A628 | xaudacity.c | Native command 55 (2 args): stores the radian angles of vector a1 as 16-bit angles (0x10000 a turn) in the three words at a0->unk_04. |
| NativeCmd_LineCheck | 0x0012AF88 | xaudacity.c | Native command 140 (4 args, returns a value): steps from a0 along a1 (length in its w) in pieces of at most a2 through func_001166E8, stores the end point in a3; a0 = hit bit (probably a collision line check). |
| World_ApplyWorldData | 0x001124F8 | xblade.c | Reads the world data file at D_004D2A2C (room table, entrance table and other offsets), picks the room for a pending entrance, and applies the current room's settings (flags, colours, D_002C1378 pair; world 3 has an alternative pair late in the game, probably). |
| World_OnWorldDataLoaded | 0x00112968 | xblade.c | Load callback for the world data file: applies it, sets up D_002A0508 from D_002B9330 (aligned to 0x40) and loads the room file. |
| World_LoadTask | 0x001129C8 | xblade.c | Task: unless a load is already pending, reloads the world names and loads the world data file (worldDataFile) when the world changed, else goes on with the room. |
| World_StartLoadTask | 0x00112AD8 | xblade.c | Task: stops the scripts (func_001C38C0) and adds World_LoadTask. |
| World_StartLoad | 0x00112B18 | xblade.c | Adds World_StartLoadTask (priority 190000). |
| World_ChangeRoom | 0x00112B48 | xblade.c | Sets the world, room, D_002B8684 and entrance number, records them (func_00111408) and starts loading. |
| World_ChangeRoomDirect | 0x00112B80 | xblade.c | Same as World_ChangeRoom without func_00111408. |
| World_ChangeToEntrance | 0x00112BB8 | xblade.c | Goes to entrance arg0 of the current world (its room from the entrance table) and starts loading. |
| Room_OnBinImgPreloaded | 0x00112C08 | xblade.c | Load callback of Room_PreloadBinImg: keeps the buffer (D_002A0510) and marks it loaded (D_002B9310). |
| Room_PreloadBinImg | 0x00112C20 | xblade.c | Starts loading <room>.img of the room behind entrance arg0 when it is not the current one (and flag 13 of D_002C1EA8 is clear). |
| Party_SaveSpawnPositions | 0x00113048 | xblade.c | Stores the position and angle (+0x10, +0x3C) of the three party members (D_002E26A0) in D_004D92F0. |
| Party_GetSavedSpawnPosition | 0x001130A0 | xblade.c | Party member i's position stored by Party_SaveSpawnPositions. |
| World_FindEntranceForRoom | 0x001130E0 | xblade.c | Index of the first entrance of the current room in the entrance table, or 1000. |
| World_GetSpawnPos0 | 0x00113138 | xblade.c | Start position of party member 0: from the current entrance (floats 4..7), the saved one, or GameState_GetPosition(0). |
| World_GetSpawnPos1 | 0x00113270 | xblade.c | Start position of party member 1 (entrance floats 8..11). |
| World_GetSpawnPos2 | 0x001133A0 | xblade.c | Start position of party member 2 (entrance floats 12..15). |
| Room_LoadArchive | 0x00113768 | xblade.c | Task: loads roomArchiveFile into D_002B9340 (aligned to 0x80) with Room_OnArchiveLoaded as callback. |
| Room_OnArchiveLoaded | 0x001136D8 | xblade.c | Load callback of the room archive: resets the 64 model slots, then goes on (func_001132C0), through func_0011E7C8 when D_002B9338 == 0. |
| AlignUp | 0x001137C8 | xblade.c | Rounds arg0 up to a multiple of arg1. |
| PauseScreen_Draw | 0x001137F8 | xblade.c | Draws the pause screen probably: GS register words from the colours D_004D2A8C..D_004D2AA0, messages 5..9, then sets the display (PMODE, DISPFB1, DISPLAY1). |
| PauseScreen_ResetColors | 0x00113A00 | xblade.c | Sets the pause screen colours D_004D2A8C..D_004D2AA0 to their defaults. |
| PauseScreen_Show | 0x00113AB0 | xblade.c | 0: restores the normal display (PMODE 0x22); else draws the pause screen with the default colours. |
| PauseScreen_AnimateColors | 0x00113AF8 | xblade.c | Steps the pause screen colour fade in (D_004D9340 = 1) or out (2) and redraws it (FM). |
| Sound_PauseNested | 0x00113E28 | xblade.c | arg0 != 0: pauses sound (func_001EE280(2)) and counts up; 0: counts down and resumes at zero. Prints "ERROR:sound pause" on wrap. |
| roomTable | 0x002BCDAC | xblade.c | 64-byte room entries of the current world (offset at world data + 0x10), indexed by curRoomNo. |
| roomCount | 0x002BCDB0 | xblade.c | Number of entries in roomTable. |
| entranceTable | 0x002BCDA0 | xblade.c | 64-byte entrance entries (room number, then three party start positions), indexed by curEntranceNo. |
| entranceCount | 0x002BCDA4 | xblade.c | Number of entries in entranceTable. |
| curEntranceNo | 0x002BCDA8 | xblade.c | Entrance used to enter the current room (World_ChangeRoom's arg3, index into entranceTable; -1 = find one). |
| SysMessage_Draw | 0x0010F658 | xtailor.c | Draws the system message for the bits of arg0 (4: message 3 or 4 with a choice, 2: message 2, 1: message 1) on its own display, or restores the display for 0; probably the controller / disc warnings. |
| SysMessage_Show | 0x0010F8D0 | xtailor.c | SysMessage_Draw, and passes the bits to the movie player (Movie_SetSysMessage) while a movie runs. |
| SysMessage_WaitWhileActive | 0x0010F918 | xtailor.c | Loops while one of the watched bits of D_002C1EB8 is set (comparing with the states saved before), showing the message, pausing sound and updating the pads; returns whether a message was shown (FM). |
| AllSet_SetupTable | 0x0010FBE0 | xtailor.c | Fills the 17 pointer / size pairs D_002BBD48 / D_002BBD90 from the table of offsets at arg0 + 0x10. |
| AllSet_Load | 0x0010FC38 | xtailor.c | Reads "allset.set" and sets up its table. |
| AreaNames_Load | 0x0010FC98 | xtailor.c | Reads "allarea.nam" to D_004D0590. |
| AreaNames_Get | 0x0010FCE8 | xtailor.c | Name data of room arg1 of world arg0 in allarea.nam. |
| AreaNames_GetCurrent | 0x0010FD18 | xtailor.c | AreaNames_Get for the current world and room. |
| PlayTime_SetLimit | 0x0010FEA0 | xtailor.c | Play time frame limit D_004D90F0: 0x14996C4 at 60 Hz (D_002BBDEC == 1.0), else 0x112A84E (both about 100 hours). |
| Gs_SetDisplaySize | 0x0010FEE8 | xtailor.c | Sets the display environment D_004D2610 to w x h and puts it. |
| Gs_GetDisplayOffset | 0x0010FFB8 | xtailor.c | Returns the display offset (DX, DY) of D_004D2610. |
| Gs_ResetGraph | 0x0010FFE0 | xtailor.c | Resets the GS (sceGsResetGraph) and puts the display environment again. |
| Gs_SetDisplayOffset | 0x00110020 | xtailor.c | Sets the display offset (DX, DY) of D_004D2610 and marks it changed (D_004D284C). |
| Gs_SetDefaultDrawEnv | 0x001100A8 | xtailor.c | Builds and puts the default draw environment D_004D8EF0 from the register tables D_002BC750..D_002BC830 (FM). |
| Gs_Reset | 0x001101E8 | xtailor.c | Resets the GS, installs the VSync callback and sets the default draw environment (FM only). |
| VSync_Callback | 0x00110218 | xtailor.c | VSync handler: interlace field, frame counters, the play time counter D_002BBDF4 (held at the limit), vsync count D_004D90F4. |
| Fade_ResetScreenColor | 0x00110360 | xtailor.c | fadeScreenColor = (128, 128, 128, 128). |
| Fade_ClearScreenColor | 0x00110380 | xtailor.c | fadeScreenColor = (0, 0, 0, 0). |
| PlayTime_SetFrames | 0x00110448 | xtailor.c | Sets the play time counter D_002BBDF4. |
| Frame_ResetCounters | 0x00110458 | xtailor.c | Clears the frame counters and sets the time step D_002B8344 to the frame scale. |
| VSync_InstallCallback | 0x001104C0 | xtailor.c | sceGsSyncVCallback(VSync_Callback). |
| Frame_UpdateTimeStep | 0x001104E0 | xtailor.c | Waits for the next frame (func_0010C0E0) and sets the time step D_002B8344 from the vsyncs counted (capped at 5, scaled by D_002B8348) (FM). |
| Movie_OnPlayerLoaded | 0x00110FC8 | xtailor.c | Load callback of dkmovie.x: marks the player loaded and starts it (func_F20000(0, movie)). |
| Movie_ClearState | 0x00111000 | xtailor.c | Clears the movie flags (D_002A30D0, D_002B9030, D_002B9084). |
| Movie_Load | 0x00111020 | xtailor.c | Loads the movie player overlay "dkmovie.x" to 0xF20000 for movie arg0. |
| Movie_Start | 0x00111060 | xtailor.c | Pauses sound, func_001EEC00(0x7B), player command 1. |
| Movie_IsRunning | 0x00111090 | xtailor.c | Player command 2 while the player is loaded, else 0. |
| Movie_SetSysMessage | 0x00111170 | xtailor.c | Player command 6 with the system message bits. |
| Movie_Finish | 0x001111B0 | xtailor.c | Ends the movie: command 4, clears the movie flags, resumes sound (FM). |
| Actor_GetDebugName | 0x00122DC8 | xtoaster.c | Text for actor id arg0 (its definition's name at +0x68, or the id type and number) in arg1 or one of four static buffers, upper-cased. |
| Actor_IsActive | 0x00122FF8 | xtoaster.c | True for a non-NULL actor whose flags (+0x370) have the "used" bit 32 set and the "removed" bit 33 clear. |
| Actor_SetParent | 0x00123030 | xtoaster.c | Sets actor arg0's parent (+0x74) and +0x78, then recounts every active actor's children (+0x80). |
| Actor_Next | 0x001230A0 | xtoaster.c | Next active actor after p in the 96-actor array D_002C64A0 (from the first for NULL), or NULL. |
| Actor_IsOpponent | 0x00123118 | xtoaster.c | True when arg1 has a team (flags bits 37..38) different from arg0's and is not flagged 0x200. |
| Actor_FindNextOpponent | 0x00123158 | xtoaster.c | Next active actor after p that is an opponent of arg0. |
| Actor_FindNextAlly | 0x001231B8 | xtoaster.c | Next active actor after p (other than arg0) of arg0's team. |
| Actor_CountTeam2 | 0x00123298 | xtoaster.c | Number of active actors of team 2. |
| Actor_PushState | 0x00123438 | xtoaster.c | Pushes the actor's state word (+0x000) on its small stack (+0x37C) and sets it to arg1. |
| Actor_PopState | 0x00123460 | xtoaster.c | Restores the actor's state word from its stack. |
| Actor_FindById | 0x00123488 | xtoaster.c | Actor for id arg0 by its type byte (bits 16..23): 0 party slot 0..2, 1 character number (definition +0x4C), 11 definition +0x4E, else the actor's own id (+0x04). |
| Actor_GetCharNo | 0x00123618 | xtoaster.c | Character number (definition +0x4C) of actor id arg0, or 0xFF. |
| Actor_SetStateBit | 0x00123648 | xtoaster.c | Sets bit arg1 of actor id arg0's state word. |
| Actor_ClearStateBit | 0x00123680 | xtoaster.c | Clears bit arg1 of actor id arg0's state word. |
| Actor_TestStateBit | 0x001236C0 | xtoaster.c | Tests bit arg1 of actor id arg0's state word. |
| Actor_FreeModel | 0x001236F8 | xtoaster.c | Releases the actor's model (+0x154, func_00162110) and its +0x14C data unless flags bit 39 is set. |
| Actor_Free | 0x00123760 | xtoaster.c | Actor_FreeModel, then clears the state word and +0x374. |
| Actor_FreeRemovedTask | 0x00123790 | xtoaster.c | Task: frees every actor flagged removed (bit 33, without bit 55). |
| Actor_Alloc | 0x00123810 | xtoaster.c | Takes the next unused actor slot (round robin from D_002E26AC), clears it and marks it used; NULL when all 96 are used. |
| Actor_SetPosition | 0x001238D0 | xtoaster.c | Places the actor at vector arg1 (w = angle), resets its motion fields and ground position. |
| Actor_SetPositionById | 0x00123A88 | xtoaster.c | Actor_SetPosition for actor id arg0. |
| Actor_SetDirectionById | 0x00123AB8 | xtoaster.c | Sets actor id arg0's direction vector (+0x30) and marks it fixed (flags bit 44). |
| Actor_GetStartPosition | 0x00123B40 | xtoaster.c | Start position of the actor: the spawn point for the party (kind 0 / 1), else from its definition, placed near the player for some placement modes. |
| Actor_SetupPartyMember | 0x00123D48 | xtoaster.c | When the actor is a party member (Party_FindCharacterSlot < 3, kind 3), puts it in party slot D_002E26A0[k] and sets up its party data. |
| Actor_Reset | 0x00124060 | xtoaster.c | Resets the actor's state, motion and timers and places it at arg1. |
| Actor_Spawn | 0x00124218 | xtoaster.c | Creates an actor from its definition (func_001320A8), allocates it, sets it up (party, parent, start position) and resets it; probably. |
| Actor_Remove | 0x001247E8 | xtoaster.c | Takes an active actor out of the party slots and marks it removed (freed later by Actor_FreeRemovedTask). |
| Actor_RemoveById | 0x001248E8 | xtoaster.c | Actor_Remove for actor id arg0. |
| Actor_RemoveAll | 0x001249D8 | xtoaster.c | Updates the party flags, then removes every active actor (FM only). |
| Actor_InitSystem | 0x00124B90 | xtoaster.c | Clears the actor array and party slots, resets related systems and adds Actor_FreeRemovedTask once. |
| Text_FadeInGlyphs | 0x0010CE50 | xsauce.c | Raises the alpha (+0x0A, up to 0x80) of the n glyph keys by the step +0x18; probably the text fade in. |
| Text_FadeOutGlyphs | 0x0010CED0 | xsauce.c | Lowers the alpha of the n glyph keys by +0x1C (down to 0) and clears the fade-in step. |
| Text_CenterLines | 0x0010D138 | xsauce.c | Shifts the x (+0x04) of every glyph key line (lines split where +0x06 changes) so that the line is centred on the window. |
| Text_StrLen | 0x0010D350 | xsauce.c | Length of a 0-terminated string. |
| Text_Sprintf | 0x0010D388 | xsauce.c | vsprintf into buf, then converts it to the game's font codes (space -> 1, other bytes - 0x0F); returns the length. |
| Text_ReadU16 | 0x0010D438 | xsauce.c | Reads the little-endian 16-bit value after buf[*pos], advancing *pos by 2. |
| MsgWin_Init | 0x0010ED20 | xsauce.c | Sets up text window p at (arg0, arg1) with text arg3 and scale arg2, and starts drawing it. |
| MsgWin_DrawTemp | 0x0010EEE0 | xsauce.c | Draws text arg3 at (arg0, arg1) through a temporary text window. |
| MsgWin_DrawCursor | 0x0010F0D0 | xsauce.c | Draws the pulsing choice cursor at (x, y) relative to the window (FM). |
| MsgWin_SetupChoices | 0x0010F258 | xsauce.c | Builds the choice position list D_004CF574 (one entry per text line) and lowers both limits of arg0 by one. |
| MsgWin_UpdateChoice | 0x0010F368 | xsauce.c | Moves the choice with up / down (wrapping on a fresh press), cancel jumps to the last one, confirm calls the menu's callback with the choice (1-based) and frees the list (FM). |
| MsgWin_FreeChoices | 0x0010F520 | xsauce.c | Frees the choice position list. |
| MsgWin_InitChoice | 0x0010F558 | xsauce.c | Sets the first choice (arg2 - 1, FM) and the window's +0xA8, clears the choice list. |
| Summon_CameraTask | 0x0013ABF8 | xapple.c | Task: while summoning (D_002C1EA8 bit 20) moves the camera (D_002DECE0 / D_002DECF0) from where it was to the summon view (D_00301030 / D_00301040) over 40 frames with a random turn. |
| Summon_PhaseBegin | 0x0013B050 | xapple.c | Phase 0: freezes the summoner, starts its effect and camera task, hides the other party members (FM). |
| Summon_OnOverlayLoaded | 0x0013B1A0 | xapple.c | Load callback of the summon program xs_<name>.x: sets up the parts of the .dbt data and marks it loaded (D_00532604 = 4). |
| Summon_EnterSceneTask | 0x0013B238 | xapple.c | Task: pushes a state on every actor (the summoner is held, the others stopped), moves the summoner away and starts the summon scene scripts (FM). |
| Summon_PhaseLoad | 0x0013B3D0 | xapple.c | Phase 1: once the .dat is loaded, loads xs_<name>.dbt and the xs_<name>.x program (to 0xF20000) and adds Summon_EnterSceneTask. |
| Summon_LightFadeTask | 0x0013B4E8 | xapple.c | Task list entry: fades a light (Light_Add) in over 60 frames, then clears it (FM). |
| Summon_RestoreActors | 0x0013B5D8 | xapple.c | Pops the actors' states, puts the summoner back at its saved position and restarts the game state (FM). |
| Summon_PhaseStart | 0x0013B740 | xapple.c | Phase 2: restores the actors, gives the summoned actor (id type 7) and the summoner their motions and starts the summon program (FM). |
| Summon_PhaseWaitEnd | 0x0013B8F0 | xapple.c | Phase 3: waits for the summon program (command 1) to end, then clears the summon flags. |
| Summon_MainTask | 0x0013B958 | xapple.c | Task: runs the summon phases (D_00301058: duration, function) and the summon task list. |
| Summon_OnSoundLoaded | 0x0013BA08 | xapple.c | D_00532604 = 2 (summon sounds loaded). |
| Summon_OnDataLoaded | 0x0013BA18 | xapple.c | Load callback of xs_<name>.dat: sets up its parts (effects, sounds), then the .dbt buffer D_0053260C (FM). |
| Summon_GetDuration | 0x0013BB20 | xapple.c | Summon time: (the summoner's +0x6C->+0x48 + bits 10..12 of D_002DED20) * 3000; probably. |
| Summon_Start | 0x0013BB60 | xapple.c | Starts summon arg1 (D_00301010: dumbo, bambi, genie, tink, mushu, simba) for actor arg0: sets the flags, takes a cost from the actor (func_00141668, probably MP), loads xs_<name>.dat, adds Summon_MainTask. |
| Summon_End | 0x0013BD08 | xapple.c | Stops a running summon: ends the program and the task, restores the party, clears the summon flags. |
| summonFileNames | 0x00304B00 | xapple.c | File name bases of the six summons ("xs_dumbo" ... "xs_simba"). |
| summonPhaseTable | 0x00304B48 | xapple.c | The four summon phases: duration and function (Summon_PhaseBegin .. Summon_PhaseWaitEnd). |
| UiPart_StepColorAnim | 0x00249FB0 | xmonitor.c | Advances the part's colour key track (track 0, flags 0xA) by dt; sets "ended" (4) at the last key. |
| UiPart_StartColorAnim | 0x0024A088 | xmonitor.c | Turns the colour track on (flags 8, track state 2). |
| UiPart_StopColorAnim | 0x0024A0A8 | xmonitor.c | Turns the colour track off. |
| UiPart_RewindColorAnim | 0x0024A0C0 | xmonitor.c | Rewinds the colour track to its first key. |
| UiPart_GetColor | 0x0024A0E0 | xmonitor.c | Colour of the colour track now (linear between the current and next key). |
| UiPart_GetColorAnimState | 0x0024A1C0 | xmonitor.c | State of the colour track (2 running, 4 ended). |
| UiPart_StepGradientAnim | 0x0024A1C8 | xmonitor.c | Advances the four-corner colour track (track 1, flags 0xC0) by dt. |
| UiPart_RewindGradientAnim | 0x0024A2E0 | xmonitor.c | Rewinds the four-corner colour track. |
| UiPart_GetGradient | 0x0024A300 | xmonitor.c | The four corner colours of track 1 now (interpolated). |
| UiPart_StartGradientAnim | 0x0024A450 | xmonitor.c | Turns the four-corner colour track on. |
| UiPart_StopGradientAnim | 0x0024A470 | xmonitor.c | Turns the four-corner colour track off. |
| UiPart_GetGradientAnimState | 0x0024A488 | xmonitor.c | State of the four-corner colour track. |
| UiPart_StepRectAnim | 0x0024A490 | xmonitor.c | Advances the rectangle track (track 2, flags 0x14) by dt. |
| UiPart_RewindRectAnim | 0x0024A568 | xmonitor.c | Rewinds the rectangle track. |
| UiPart_GetRect | 0x0024A588 | xmonitor.c | Rectangle (x, y, w, h) of track 2 now (interpolated). |
| UiPart_StartRectAnim | 0x0024A678 | xmonitor.c | Turns the rectangle track on. |
| UiPart_StopRectAnim | 0x0024A698 | xmonitor.c | Turns the rectangle track off. |
| UiPart_GetRectAnimState | 0x0024A6B0 | xmonitor.c | State of the rectangle track. |
| UiPart_BuildSprite | 0x0024A6B8 | xmonitor.c | Fills a sprite packet (colours from the tracks or the part, XYZ from the rectangle, UV with half-texel offsets) for part arg1. |
| UiPart_BuildSprite8 | 0x0024AA48 | xmonitor.c | UiPart_BuildSprite with TEX0 set for an 8-bit CLUT texture (PSM 0x13, CLD 1). |
| UiFile_Relocate | 0x0024AAC8 | xmonitor.c | Turns the key track offsets of every part in a UI file into pointers (asserts 16-byte alignment). |
| UiPart_GetCurrentRect | 0x0024AC08 | xpackage.c | The part's rectangle: from its rectangle track when that runs (flags 0x14), else its own +0x00. |
| UiPart_GetCurrentColors | 0x0024AC68 | xpackage.c | The part's four corner colours: from the colour or gradient track when running, its own four (flag 0x20), or its first one repeated. |
| UiPart_StartAnims | 0x0024AE00 | xpackage.c | Rewinds and starts each key track the part has (rectangle 4, colour 2, gradient 0x40). |
| UiPart_StopAnims | 0x0024AE90 | xpackage.c | Stops each key track the part has. |
| UiPart_StepAnims | 0x0024AF00 | xpackage.c | Advances all three key tracks of the part by one frame. |
| UiFile_CopyParts | 0x0024AF40 | xpackage.c | Copies the 0xC0-byte parts listed in arg0 (ended by -1) from UI file arg2 to arg1. |
| UiFile_GetParts | 0x0024AFC0 | xpackage.c | Stores the address of each part listed in arg0 (ended by -1) of UI file arg2 in arg1. |
| UiPart_SetColor | 0x0024B008 | xpackage.c | Sets all four corner colours of the part to colour arg1. |
| Gs_SetQuadXYZ | 0x0024B058 | xpackage.c | Fills four GS XYZ vertices of the rectangle (x, y, w, h), offset to the GS window (0x700, 0x740 pixels). |
| Decode_CopyChunk | 0x0024B0C8 | xpackage.c | Chunk handler: copies the data of a chunk (type byte, 32-bit size, data) to arg1 and returns the size. |
| Decode_Chunk | 0x0024B138 | xpackage.c | Runs the handler of the chunk's type (table D_00469FC8) on it; returns the size it produced. |
| Decode_GetChunkSize | 0x0024B178 | xpackage.c | Size field of a chunk of type 1 (asserts the type, src/decode.c). |
| Assert_Stub | 0x0024B1E8 | xpackage.c | Empty: the assert handler (called with expression, file, line), compiled out. |
| SaTask_ClearGroups | 0x0024B1F0 | xpackage.c | Clears the eight task group slots (sa_task.c, TASK_GRUPE_MAX). |
| SaTask_RunInGroup | 0x0024B228 | xpackage.c | Calls func_0024AB00(arg1, arg2, arg3) with task group idx's context (D_0046A03C..D_0046A048) set, restoring two of them after. |
| SaTask_StepGroup | 0x0024B448 | xpackage.c | Steps task group idx (func_0024E1D0) with its context set and counts its steps (+0x1C), unless a system message is up. |
| SaTask_FreeGroup | 0x0024B5C8 | xpackage.c | Frees task group arg0 (when it owns its memory, +0x24) and clears its slot. |
| SaTask_RunWithContext | 0x0024B6D0 | xpackage.c | SaTask_RunInGroup with a context passed in (arg0[3..6]). |
| SaTask_GetGroupSize | 0x0024B778 | xpackage.c | Memory a task group with arg0 tasks needs (arg0 * 0x10340 + 0x5E7, 64-byte aligned). |
| SaTask_CreateGroup | 0x0024B7A0 | xpackage.c | Sets up a task group in the given memory in a free slot (asserts "i!=TASK_GRUPE_MAX"). |
| SaTask_AllocGroup | 0x0024B958 | xpackage.c | SaTask_CreateGroup with memory from malloc(SaTask_GetGroupSize(arg0)), owned by the group. |
| SaTask_Init | 0x0024B990 | xpackage.c | SaTask_ClearGroups. |
| SaTask_RunInGroup0 | 0x0024B2C8 | xpackage.c | SaTask_RunInGroup for group 0. |
| SaTask_RunInGroup1 | 0x0024B2F8 | xpackage.c | SaTask_RunInGroup for group 1. |
| SaTask_RunInGroup2 | 0x0024B328 | xpackage.c | SaTask_RunInGroup for group 2. |
| SaTask_RunInGroup3 | 0x0024B358 | xpackage.c | SaTask_RunInGroup for group 3. |
| SaTask_RunInGroup4 | 0x0024B388 | xpackage.c | SaTask_RunInGroup for group 4. |
| SaTask_RunInGroup5 | 0x0024B3B8 | xpackage.c | SaTask_RunInGroup for group 5. |
| SaTask_RunInGroup6 | 0x0024B3E8 | xpackage.c | SaTask_RunInGroup for group 6. |
| SaTask_RunInGroup7 | 0x0024B418 | xpackage.c | SaTask_RunInGroup for group 7. |
| SaTask_StepGroup0 | 0x0024B508 | xpackage.c | SaTask_StepGroup for group 0. |
| SaTask_StepGroup1 | 0x0024B520 | xpackage.c | SaTask_StepGroup for group 1. |
| SaTask_StepGroup2 | 0x0024B538 | xpackage.c | SaTask_StepGroup for group 2. |
| SaTask_StepGroup3 | 0x0024B550 | xpackage.c | SaTask_StepGroup for group 3. |
| SaTask_StepGroup4 | 0x0024B568 | xpackage.c | SaTask_StepGroup for group 4. |
| SaTask_StepGroup5 | 0x0024B580 | xpackage.c | SaTask_StepGroup for group 5. |
| SaTask_StepGroup6 | 0x0024B598 | xpackage.c | SaTask_StepGroup for group 6. |
| SaTask_StepGroup7 | 0x0024B5B0 | xpackage.c | SaTask_StepGroup for group 7. |
| SaTask_FreeGroup0 | 0x0024B610 | xpackage.c | SaTask_FreeGroup for group 0. |
| SaTask_FreeGroup1 | 0x0024B628 | xpackage.c | SaTask_FreeGroup for group 1. |
| SaTask_FreeGroup2 | 0x0024B640 | xpackage.c | SaTask_FreeGroup for group 2. |
| SaTask_FreeGroup3 | 0x0024B658 | xpackage.c | SaTask_FreeGroup for group 3. |
| SaTask_FreeGroup4 | 0x0024B670 | xpackage.c | SaTask_FreeGroup for group 4. |
| SaTask_FreeGroup5 | 0x0024B688 | xpackage.c | SaTask_FreeGroup for group 5. |
| SaTask_FreeGroup6 | 0x0024B6A0 | xpackage.c | SaTask_FreeGroup for group 6. |
| SaTask_FreeGroup7 | 0x0024B6B8 | xpackage.c | SaTask_FreeGroup for group 7. |
| FadeTaskList_Task | 0x00109360 | xarcade.c | Task: updates the fade task list (fadeTaskList). |
| Game_InitSystems | 0x00109388 | xarcade.c | Initialises the game systems (task system, game state and data, allset / allarea tables, ...) before the main loop. |
| Fade_InitSystem | 0x001094F0 | xarcade.c | Resets the fades, sets up fadeTaskList and adds FadeTaskList_Task. |
| GameMode_Request | 0x00109558 | xarcade.c | Requests game mode arg0 (D_00495164, state D_00495160 = 2) and starts capturing the screen. |
| Overlay_Run | 0x00109630 | xarcade.c | Invalidates the instruction cache and calls the overlay at 0xF20000 (command 0). |
| SoftReset_Check | 0x00109658 | xarcade.c | When the pad combination (all shoulder buttons with start and select, probably) is held and nothing is loading, stops sound, any movie and the game and returns D_002BBE08 (cleared: reset). |
| Game_MainLoop | 0x00109770 | xarcade.c | The main loop, probably: initialises, plays the opening movies, then each frame runs the pause, system message and task system updates. |
| Screen_RestoreFromOverlayArea | 0x00109CD0 | xarcade.c | Uploads the two halves of a screen image stored at 0xF20000 back to VRAM (0xE00, 0x1400). |
| Screen_CaptureToOverlayAreaTask | 0x00109D98 | xarcade.c | Task: stores the frame buffer at 0x1A00 (512 x 384) to 0xF20000. |
| Screen_CaptureToOverlayArea | 0x00109DF8 | xarcade.c | Adds Screen_CaptureToOverlayAreaTask. |
| Screen_CrossFadeTask | 0x00109E20 | xarcade.c | Task: draws the captured screen fading out over the time D_00495184 (FM). |
| Screen_StartCrossFade | 0x00109F48 | xarcade.c | Starts Screen_CrossFadeTask (+0x04 of D_0048EC00 = arg0 * 2). |
| Screen_RestoreCapture | 0x00109F88 | xarcade.c | Uploads the screen captured by Screen_CaptureTask (D_002B2CCC) back to VRAM. |
| Screen_CaptureTask | 0x0010A058 | xarcade.c | Task: stores the frame buffer at 0x1A00 to a new buffer D_002B2CCC. |
| Screen_Capture | 0x0010A0D8 | xarcade.c | Marks the capture (D_002B2CC4), starts a fade when the screen is not at full colour, adds Screen_CaptureTask. |
| Screen_FadeCaptureTask | 0x0010A120 | xarcade.c | Task: draws the captured screen darkening over 64 frames, then clears the screen colour (FM). |
| Screen_ShowCaptureTask | 0x0010A248 | xarcade.c | Task: starts an overlay fade in and draws the captured screen for 64 frames (FM). |
| Screen_StartCaptureFade | 0x0010A320 | xarcade.c | Adds Screen_ShowCaptureTask when D_002B2CC0 is set, else Screen_FadeCaptureTask. |
| Screen_DrawCaptureTask | 0x0010A378 | xarcade.c | Task: draws the captured screen every frame. |
| Screen_DrawCapture | 0x0010A3C0 | xarcade.c | Adds Screen_DrawCaptureTask. |
| Screen_SaveRegion | 0x0010A3E8 | xarcade.c | Stores the 256 x 192 VRAM area at 0x3600 in a new buffer D_002B2CC8. |
| Screen_LoadRegion | 0x0010A470 | xarcade.c | Uploads the area saved by Screen_SaveRegion back to 0x3600. |
| Vu0_TransformSpriteVerts | 0x0010A4D8 | xnoodle.c | Hand-written VU0 loop: transforms count vertices by matrix arg1 (plus offset arg5), perspective-divides them and writes ST / RGBA / XYZ quadwords to the GS packet. |
| Gs_LoadFontImage | 0x0010B030 | xnoodle.c | Uploads a 256 x 128 4-bit image to 0x1800 and its palette to 0x3FF4, then a black copy of the palette to 0x3FF8 (probably the font). |
| IoThread_Main | 0x0010C0C8 | xnoodle.c | Thread body: waits for the frame semaphore D_0048ECE0 and runs the (at most two) registered jobs. |
| IoThread_AddJob | 0x0010C170 | xnoodle.c | Registers a job (function, argument) in a free one of the two slots. |
| IoThread_RemoveJob | 0x0010C1B8 | xnoodle.c | Removes the job with function arg0. |
| IoThread_IsBusy | 0x0010C200 | xnoodle.c | True when a job is registered (C name func_0010BF98_s32, declared void in xnoodle.h). |
| IoThread_ClearJobs | 0x0010C240 | xnoodle.c | Clears both job slots. |
| IoThread_Init | 0x0010C278 | xnoodle.c | Creates the two semaphores and the job thread (priority 0x28, stack D_002B3B10) and starts it. |
| Frame_WaitVSync | 0x0010C348 | xnoodle.c | Wakes the job thread and waits for the VSync semaphore D_00495258. |
| VSync_SignalFrame | 0x0010C378 | xnoodle.c | From the VSync handler: signals D_00495258 when a thread waits on it. |
| Kanji_Load | 0x0010C3C0 | xnoodle.c | Reads "kanji.knj" to D_0048ED00. |
| Gs_Load8x2Image | 0x0010C438 | xnoodle.c | Uploads an 8 x 2 32-bit image (a CLUT, probably) to VRAM block dest. |
| Kanji_UploadTask | 0x0010C4B0 | xnoodle.c | Uploads the 256 x 256 kanji image to 0x3600 (not in pause modes 5 and 6). |
| VifDmaTask_Update | 0x00127500 | xcream.c | Packet task: sends the task's packet (+0x10) on DMA channel VIF1 (chain mode) and hands it to func_00121EB0. |
| GraphicsDma_AddTasks | 0x00128440 | xcream.c | Task: resets the draw counter D_004F82C0 and adds two GraphicsDmaTask_Update packet tasks for D_004F8270. |
| GraphicsDma_Init | 0x00128B20 | xcream.c | Sets up the three 0x150 and three 0x220 objects, the GIF register packet D_004F8270 and the view-screen matrix D_004F82D0, and adds GraphicsDma_AddTasks. |
| ScriptProg_Start | 0x00128C60 | xcream.c | Starts program arg1 of the program table D_00514F10 (func_0012B930) and passes it arg0 when arg0's first word is set; probably a script thread. |
| NativeCmd_StartProg | 0x00128CC8 | xcream.c | Native command 20 (2 args, returns a value): a0 = ScriptProg_Start(arg0, a1). |
| NativeCmd_StopProg | 0x00128CF8 | xcream.c | Native command 28 (1 arg): func_0012B850(a0) (stops the program started by NativeCmd_StartProg, probably). |
| NativeCmd_RestartProg | 0x00128D10 | xcream.c | Native command 34 (3 args, returns a value): stops program a0 when set and starts program a2 again. |
| Vec_Length | 0x00120BF8 | xball.c | Length of the vector (sqrt of its inner product). |
| Vec_LengthXZ | 0x00120C18 | xball.c | Length of the vector in the XZ plane. |
| Mat_RotateZXY | 0x00120C38 | xball.c | arg0 = arg1 rotated about Z, X, then Y by the angles in arg2. |
| Angle_Wrap | 0x00120C88 | xball.c | Wraps an angle into -PI..PI (at most 0x400 steps of 2 PI). |
| Mat_AxisAngle | 0x00120CF8 | xball.c | Rotation matrix of angle ang about the unit axis (Rodrigues form). |
| Vec_Project | 0x00120EF0 | xball.c | arg0 = arg1 * arg2 (w set to 1) divided by its w; returns 1 / w. |
| Vec_TriangleNormal | 0x00120F70 | xball.c | Normalised normal of the triangle arg0[0..2]. |
| Mat_IsBoxOnScreen | 0x00121000 | xball.c | True when all eight points, transformed by m, are in front (w >= 1) and inside 0..4095 on screen. |
| Vec_ScaleXZ | 0x001210F0 | xball.c | arg1 = arg2 with X and Z scaled by arg0. |
| Mat_IsClipped | 0x00121120 | xball.c | True when arg0[0][2] < 0 or sceVu0ClipScreen rejects it. |
| Spline_ComputeCoeffs | 0x001213A0 | xball.c | Natural cubic spline: the second-derivative terms of the n values y (end values 0). |
| Spline_Evaluate | 0x001214E0 | xball.c | Cubic spline value at t from values a and coefficients b. |
| Line_IntersectXZ | 0x00121550 | xball.c | Point where line p + t d meets the line through q along n in the XZ plane; returns t (NaN when parallel). |
| Mat_DropShadow | 0x00121620 | xball.c | Drop shadow matrix (sceVu0DropShadowMatrix) with its translation scaled by arg3. |
| Mat_Transpose3x3 | 0x00121668 | xball.c | arg0 = the transposed 3x3 part of arg1, without translation. |
| Angle_StepTowards | 0x001216D8 | xball.c | Angle a turned towards b by at most c per frame (scaled by the time step D_002B8344). |
| Vec_CosAngle | 0x00121748 | xball.c | Cosine of the angle between two vectors, clamped to -1..1. |
| Vec_Angle | 0x00121840 | xball.c | Angle between two vectors (acos of Vec_CosAngle). |
| Vec_RotateTowards | 0x00121860 | xball.c | out = direction a turned towards b by at most t per frame. |
| Mat_ScaleRows | 0x00121958 | xball.c | arg0 rows 0..2 = arg1 rows scaled by arg2[0..2]. |
| Vec_Div3 | 0x001219C8 | xball.c | arg0[i] = arg1[i] / arg2[i] for X, Y, Z. |
| Vec_ToAngles | 0x00121A10 | xball.c | Pitch and yaw of direction arg0 into arg1 (roll 0). |
| Mat_ToEuler | 0x00121A78 | xball.c | Euler angles of the normalised rotation matrix arg0 into arg1. |
| Timer_CountDown | 0x00121B08 | xball.c | A positive timer minus D_002B8340[1], not below 0. |
| Vec_CosAngleXZ | 0x00121B38 | xball.c | Vec_CosAngle of the two vectors flattened to Y = 0 (the result is not returned). |
| CoThread_RunAll | 0x001BFAC8 | xbuffalo.c | Runs every thread in the run list D_0037A170 once (through a register-switching call) and frees the ones that ended; probably. |
| CoThread_GetCount | 0x001BFC80 | xbuffalo.c | Number of used threads counted by CoThread_SortRunList (D_003759DC). |
| CoThread_GetCurrentData | 0x001BFCB0 | xbuffalo.c | Address of the current thread's (D_0037A168) +0x10 quadword. |
| CoThread_InitTable | 0x001BFCD8 | xbuffalo.c | Sets up the thread table D_0037A16C: thread 0, 15 big (0x81C0-byte context and stack) and 384 small (0x9C0) threads in the memory D_006257D4. |
| CoThread_SetupMemory | 0x001BFE50 | xbuffalo.c | Places the thread table, run list and thread memory in the block at arg0, sets up the table and returns the end of the block. |
| CoThread_GetMemorySize | 0x001BFEC8 | xbuffalo.c | Size of the memory CoThread_SetupMemory needs (0x171388 in FM). |
| CoThread_FindFree | 0x001BFED8 | xbuffalo.c | Index of a free big (arg0 == 0, 1..15) or small (16..399) thread, or -1. |
| CoThread_IsUsed | 0x001BFF70 | xbuffalo.c | Used flag of thread arg0 (0 for a negative index). |
| CoThread_Free | 0x001BFFA0 | xbuffalo.c | Calls the thread's end callback (+0x20) and frees it. |
| CoThread_FreeAll | 0x001C0010 | xbuffalo.c | Frees every used thread except thread 0 and sets the table up again. |
| CoThread_RequestEnd | 0x001C0078 | xbuffalo.c | Marks thread arg0 (or the current one for a negative arg0) to be freed (+0x04 bit 0) (FM only). |
| CoThread_CreateBig | 0x001C01B0 | xbuffalo.c | Starts a big thread: priority arg0 (0xFFFF when negative), entry arg1 and eight arguments written into its context; prints a message when none is free. |
| CoThread_Create | 0x001C0310 | xbuffalo.c | Starts a small thread like CoThread_CreateBig; returns its index or -1. |
| CoThread_SortRunList | 0x001C0460 | xbuffalo.c | Frees the threads marked to end and lists the used ones in D_0037A170 by priority (+0x02), ended by -1. |
| CoThread_RunSteps | 0x001C0688 | xbuffalo.c | Calls CoThread_RunAll arg0 times. |
| CoThread_SetEndCallback | 0x001C06C0 | xbuffalo.c | Sets the end callback (+0x20) of thread arg0 (or the current one) (FM only). |
