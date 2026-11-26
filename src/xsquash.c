/**
 * Three functions and their constants, still mostly assembly; purpose not known yet (no C of this file was found in
 * EU). JP/EU: 0x149CE8-0x14A018. Final Mix (#ifdef VERSION_FM, 0x149B40-0x149E60): the same three functions, the
 * first two in C (they build a file name with sprintf and queue it with func_00120590); its constants are not in an
 * .rodata piece of this file.
 */
#include "common.h"

#ifdef VERSION_FM
extern char D_0048E410[];
extern s32 D_00350D10;
int sprintf(char*, const char*, ...);
s32 func_00149A88(void);
s32 func_00149E38(s32, void (*)(s32));
extern s32 D_00350CE8[];
extern s32 D_0054C1B0[];
s32 func_00146A68(u8*, s32, s32, s32);
u8* func_00147A10(s32);
void func_00146BC8(s32 a0);
s32 func_00146A68(u8* a0, s32 a1, s32 a2, s32 a3);
u8* func_00147A10(s32 i);
s32 func_001497C8(s32 a);

void func_00149B40(u8* p) {
    char buf[0x20];
    u8* r = func_00147A10(D_00350CE8[*(s32*)(p + 4)]);
    sprintf(buf, D_0048E410, r + *(s32*)(p + 8) * 0x58 - 0x58, D_00350D10);
    func_00120590(buf, *(s32*)(p + 0x10), func_00149A88, 0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xsquash", func_00149CE8);
#endif

#ifdef VERSION_FM
void func_00149BD0(s32 a0, s32 a1, s32 a2) {
    s32 i = func_001497C8(a2);
    if (a0 > 0) {
        func_00146BC8(-3 - i);
        func_00146A68((u8*)a2, -3 - i, (s32)func_00149B40, (s32)&D_0054C1B0[i * 8]);
        return;
    }
    func_00149B40((u8*)&D_0054C1B0[i * 8]);
}
#else
INCLUDE_ASM("asm/nonmatchings/xsquash", func_00149D78);
#endif

INCLUDE_ASM("asm/nonmatchings/xsquash", func_00149E38);

#ifndef VERSION_FM
INCLUDE_RODATA("asm/nonmatchings/xsquash", D_00488128);

INCLUDE_RODATA("asm/nonmatchings/xsquash", D_00488130);

INCLUDE_RODATA("asm/nonmatchings/xsquash", D_00488138);
#endif
