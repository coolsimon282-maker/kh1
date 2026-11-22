// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x01FD30).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

extern s32 D_004F2A00[];

s32* func_0011FD30(void) {
    return D_004F2A00;
}

void func_001220D0(void);

void func_0011FD40(void) {
    func_001220D0();
    func_001102C0();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FD60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FE20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FEC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_0011FFD0);

void func_00120038(s32* arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120040);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001200F8);

s32 func_00120170(u32 arg0, u32* arg1) {
    u32 b = *arg1;

    if (arg0 < b) {
        return -1;
    }
    return arg0 > b;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120190);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001201D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001202C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", fm_func_00120438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001204A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120580);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120438);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120678);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120590);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001207F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120888);

void* func_0011EEB8(void*, s32, s32);
s32 func_0011EF58(s32*, s32);
extern s32 D_004E49E8;

void* func_001208E0(s32 arg0) {
    return func_0011EEB8(&D_004E49E8, 0, arg0);
}

s32 func_00120908(void) {
    func_0011EF58(&D_004E49E8, 0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120930);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_001209D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120A20);

void func_001208B8(void) {
    ((s16*)func_0011ED30(0x2D2A8, func_00120908))[1] = -1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120AA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120B10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_01FD30", func_00120BA0);
