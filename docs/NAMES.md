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
