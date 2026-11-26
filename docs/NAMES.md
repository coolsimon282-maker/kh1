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
