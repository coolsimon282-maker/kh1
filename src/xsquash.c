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

#ifdef VERSION_FM
typedef struct {
    /* 0x00 */ u32 used : 1;
    /* 0x00 */ u32 state : 2;
    /* 0x00 */ u32 b3 : 1;
    /* 0x00 */ u32 rest : 28;
    /* 0x04 */ s32 k;
    /* 0x08 */ s32 n;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ void (*cb)(s32);
} SquashSlot;
extern s32 D_00350D14;
u8* func_00147A88(s32);
void func_00149BD0(s32 a0, s32 a1, s32 a2);

s32 func_00149E38(s32 k, void (*cb)(s32)) {
    char buf[0x20];
    u8* p;
    SquashSlot* s;
    s32 off;
    s32 n;
    s32 i;
    u8* r;

    off = k * 0x74 + 0x30;
    p = (u8*)D_003010F8 + off;
    if (p[6] == 0) {
        return 0;
    }
    n = *(s16*)(func_00147A88(p[6]) + 6);
    s = (SquashSlot*)D_0054C1B0;
    for (i = 0; i < 3; i++, s++) {
        if (s->used && s->k == k && s->n == n) {
            s->state = 1;
            return 0;
        }
    }
    s = (SquashSlot*)D_0054C1B0;
    if (k != 0) {
        s++;
        for (i = 0; i < 2; i++, s++) {
            if (!s->used || s->state == 0) {
                break;
            }
        }
    }
    s->cb = cb;
    s->k = k;
    s->n = n;
    s->used = 1;
    s->state = 1;
    s->b3 = 0;
    if (n == 0) {
        return 0;
    }
    r = func_00147A10(D_00350CE8[k]);
    sprintf(buf, D_0048E410, r + n * 0x58 - 0x58, D_00350D14);
    func_00120590(buf, s->unk_10, (s32 (*)(void))func_00149BD0, 0);
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/xsquash", func_00149E38);
#endif

#ifndef VERSION_FM
INCLUDE_RODATA("asm/nonmatchings/xsquash", D_00488128);

INCLUDE_RODATA("asm/nonmatchings/xsquash", D_00488130);

INCLUDE_RODATA("asm/nonmatchings/xsquash", D_00488138);
#endif
