#include "common.h"

void func_0011EDD0(s32*, s32*, s32, s32);
#define TaskList_Init func_0011EDD0 // name in config/fm/symbol_addrs.txt; old identifier kept for src/unsplit and xhumungus (rule F1)
s32 func_00120590(char*, s32, s32 (*)(void), s32); // TODO LOOK AT
// cdvd_QueueFileLoad (config/fm/symbol_addrs.txt) is still defined as func_00120590 in src/unsplit/seg_01FD30.c;
// the define keeps every file's C identical until that file is split (renaming there moves code, rule F1)
#define cdvd_QueueFileLoad func_00120590
void* func_0011ED30(s32, s32 (*func)(void));
#define TaskSystem_AddTask func_0011ED30 // name in config/fm/symbol_addrs.txt; old identifier kept for src/unsplit and xhumungus (rule F1)
s32 func_00155ED8(s32, s32);
s32 func_00120438(const char* fileName, void* dst);
void func_001208B8();
