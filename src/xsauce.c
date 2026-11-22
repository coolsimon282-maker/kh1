#include "common.h"
#include "xnoodle.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ s8 unk_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
} XSauce;

u_long128* D_002B7B70;
u_long128* D_002B7BB0;
u_long128* D_002B7BF0;
u_long128* D_002B7C30;
u_long128* D_002B7C70;
u_long128* D_002B7CB0;
u_long128* D_002B7CF0;
u_long128* D_002B7D30;
u_long128* D_002B7D70;
u_long128* D_002B7DB0;
u_long128* D_002B7DF0;
u_long128* D_002B7E30;
u_long128* D_002B7E70;
u_long128* D_002B7EB0;
u_long128* D_002B7EF0;
u_long128* D_002B7F30;
s32 D_002B7FF0;

s32 D_004CF574;
s32 D_004CF57C;

extern s32 D_002C2108;

extern u_long128* func_00121C98(s32 arg0, u_long128** arg1);

u64* func_00106CA8(s32 qwc);
void func_00106CD0(u64* p, s32 qwc);

void func_0010C2D8(s32 n, u_long128** out) {
    s32 qwc = n * 3 + 1;
    u64* p = func_00106CA8(qwc);
    p[1] = 0x535316;
    p[0] = (n | 0x8000) | 0x6400000000000000;
    func_00106CD0(p, qwc);
    *out = (u_long128*)(p + 2);
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C360);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C4B8);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010C918);

typedef struct {
    /* 0x0000 */ char unk_0000[0x2];
    /* 0x0002 */ u16 unk_0002;
    /* 0x0004 */ f32 unk_0004;
    /* 0x0008 */ f32 unk_0008;
    /* 0x000C */ char unk_000C[0x1804];
    /* 0x1810 */ f32 unk_1810[1];
} XSauceTbl;

s32 func_0010CA30(XSauceTbl* p) {
    s32 i;
    if (p->unk_0002 >= 2) {
        for (i = 0; i < p->unk_0002 - 1; i++) {
            if (p->unk_1810[i] != 0.0f) {
                return 0;
            }
        }
    }
    if (p->unk_1810[p->unk_0002 - 1] != 0.0f && p->unk_0008 == p->unk_0004) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CAE0);

s32 func_0010CBA0(XSauceTbl* p) {
    s32 i;
    for (i = 0; i < p->unk_0002; i++) {
        if (p->unk_1810[i] != 0.0f) {
            return 0;
        }
    }
    return 1;
}

typedef struct {
    /* 0x00 */ char unk_00[0xA];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ char unk_0C[0x4];
} XSauceKey; /* size = 0x10 */

typedef struct {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ XSauceKey* unk_20;
} XSauceAnim;

void func_0010CBF8(XSauceAnim* p, s32 n) {
    XSauceKey* k;
    if (n > 0) {
        k = &p->unk_20[1];
        do {
            if (k->unk_0A < 0x80) {
                k->unk_0A = k->unk_0A + p->unk_18;
            } else {
                k->unk_0A = 0x80;
            }
            k++;
        } while (--n);
    }
}

void func_0010CC80(XSauceAnim* p, s32 n) {
    XSauceKey* k;
    s32 v;
    f32 d;
    p->unk_18 = 0.0f;
    if (n > 0) {
        d = p->unk_1C;
        k = &p->unk_20[1];
        do {
            v = k->unk_0A + d;
            if (v < 0) {
                k->unk_0A = 0;
            } else {
                k->unk_0A = v;
            }
            k++;
        } while (--n);
    }
}

s32 func_0010CCD8(void) {
    if (D_002C2108 & 1) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CCF0);

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
} XSauceStep; /* size = 0x10 */

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ XSauceStep unk_10[1];
} XSauceSteps;

void func_0010CCF0(XSauceSteps* p);

s32 func_0010CE98(XSauceSteps* p) {
    s32 i;
    f32 sum;
    func_0010CCF0(p);
    if (p->unk_08 >= p->unk_04) {
        return p->unk_00;
    }
    sum = 0.0f;
    for (i = 0; i < p->unk_00; i++) {
        sum += p->unk_10[i].unk_0C;
        if (p->unk_08 <= sum) {
            return i + 1;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010CF18);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D010);

s32 func_0010D130(char* s) {
    s32 n = 0;
    while (*s != 0) {
        s++;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D168);

s16 func_0010D218(s32* pos, u8* buf) {
    s32 i = *pos;
    s32 lo = buf[++i];
    s32 hi = buf[++i];
    *pos = i;
    return lo + (hi << 8);
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010D250);

void func_0010E230(XSauce* arg0) {
    arg0->unk_12 = 0;
    if (arg0->unk_20 != 0) {
        func_00121D50(arg0->unk_20);
        arg0->unk_20 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E270);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E330);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E450);

void func_0010E580(void) {
    u_long128* imageAddrs[8];

    imageAddrs[0] = func_00121C98(0x40, imageAddrs);
    imageAddrs[1] = func_00121C98(0x40, imageAddrs + 1);
    imageAddrs[2] = func_00121C98(0x40, imageAddrs + 2);
    imageAddrs[3] = func_00121C98(0x40, imageAddrs + 3);
    imageAddrs[4] = func_00121C98(0x40, imageAddrs + 4);
    imageAddrs[5] = func_00121C98(0x40, imageAddrs + 5);
    imageAddrs[6] = func_00121C98(0x40, imageAddrs + 6);
    imageAddrs[7] = func_00121C98(0x40, imageAddrs + 7);

    func_0010E450(imageAddrs[0], imageAddrs[1], 0);
    func_0010E450(imageAddrs[2], imageAddrs[3], 1);
    func_0010E450(imageAddrs[4], imageAddrs[5], 2);
    func_0010E450(imageAddrs[6], imageAddrs[7], 3);

    func_0010C1D0(16364, imageAddrs[0]);
    func_0010C1D0(16365, imageAddrs[1]);
    func_0010C1D0(16366, imageAddrs[2]);
    func_0010C1D0(16367, imageAddrs[3]);
    func_0010C1D0(16368, imageAddrs[4]);
    func_0010C1D0(16369, imageAddrs[5]);
    func_0010C1D0(16370, imageAddrs[6]);
    func_0010C1D0(16371, imageAddrs[7]);

    sceGsSyncPath(0, 0);

    func_00121D50(imageAddrs[0]);
    func_00121D50(imageAddrs[1]);
    func_00121D50(imageAddrs[2]);
    func_00121D50(imageAddrs[3]);
    func_00121D50(imageAddrs[4]);
    func_00121D50(imageAddrs[5]);
    func_00121D50(imageAddrs[6]);
    func_00121D50(imageAddrs[7]);
}

void func_0010E700(void) {
    *(u16*)(func_0011ED30(180150, func_0010C248) + 2) = -1;

    func_0010C1D0(16348, &D_002B7B70);
    func_0010C1D0(16349, &D_002B7BB0);
    func_0010C1D0(16350, &D_002B7BF0);
    func_0010C1D0(16351, &D_002B7C30);
    func_0010C1D0(16352, &D_002B7C70);
    func_0010C1D0(16353, &D_002B7CB0);
    func_0010C1D0(16354, &D_002B7CF0);
    func_0010C1D0(16355, &D_002B7D30);
    func_0010C1D0(16356, &D_002B7D70);
    func_0010C1D0(16357, &D_002B7DB0);
    func_0010C1D0(16358, &D_002B7DF0);
    func_0010C1D0(16359, &D_002B7E30);
    func_0010C1D0(16360, &D_002B7E70);
    func_0010C1D0(16361, &D_002B7EB0);
    func_0010C1D0(16362, &D_002B7EF0);
    func_0010C1D0(16363, &D_002B7F30);
}

void func_0010E830(XSauce* arg0) {
    func_00106948(&D_002B7FF0);
    arg0->unk_11 = 1;
    func_0010E330(arg0);
}

void func_0010E868(XSauce* arg0) {
    func_00106948(&D_002B7FF0);
    arg0->unk_24 = 0;
    arg0->unk_11 = 0;
    func_0010E330(arg0);
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010E8A0);

s32 func_0010E9A8(u8* s) {
    s32 n = 0;
    s32 go = 1;
    s32 i = 0;
    do {
        u8 c = s[i];
        if (c < 0x20) {
            if (c < 9) {
                if (c == 0) { go = 0; } else if (c == 4) { go = 0; }
            } else if (c == 15) {
                i++;
                if (s[i] == 1) {
                    n++;
                }
            } else {
                i++;
            }
        }
        i++;
    } while (go);
    return n;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EA38);

/* statement order found by brute force (scheduling) */
void func_0010EB50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, XSauce* p) {
    p->unk_10 = 1;
    p->unk_12 = 0;
    p->unk_00 = 0;
    p->unk_14 = 0;
    p->unk_24 = 0;
    p->unk_11 = 0;
    p->unk_0E = 0;
    p->unk_08 = arg0;
    p->unk_0A = arg1;
    p->unk_1C = 0;
    p->unk_04 = arg3;
    p->unk_13 |= 2;
    p->unk_20 = 0;
    p->unk_0C = arg0 + 0x5E;
    p->unk_18 = arg2;
    p->unk_28 = 0;
    func_00106948(&D_002B7FF0);
    func_0010E330(p);
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EBE0);

void func_0010ED10(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    XSauce* s;
    s = (XSauce*)func_00121C98(0x2C, (u_long128**)&s);
    func_0010C248();
    s->unk_13 = 0;
    s->unk_13 |= 4;
    func_0010EB50(arg0, arg1, arg2, arg3, s);
    func_00121D50(s);
}

typedef struct {
    /* 0x00 */ char unk_00[0x80];
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ char unk_88[0xA];
    /* 0x92 */ u8 unk_92;
    /* 0x93 */ u8 unk_93;
} XSauceUnk;

void func_0010EDA0(XSauceUnk* arg0, s32 arg1, s32 arg2) {
    arg0->unk_80 = arg2;
    arg0->unk_84 = arg1;
    arg0->unk_93 &= ~1;
    arg0->unk_92 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EDC0);

s32 func_0010EEC8(s32 arg0) {
    s32 stack[4];

    return func_0010EDC0(arg0, stack) / 24 + 1;
}

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010EF00);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010F0A0);

INCLUDE_ASM("asm/nonmatchings/xsauce", func_0010F1C8);

void func_0010F380(void) {
    if (D_004CF574 != 0) {
        func_00121D50(D_004CF574);
    }
}

#ifdef VERSION_FM
extern s32 D_004D5AF8;
extern s32 D_004D5AFC;

void func_0010F3B8(s32 arg0, s32 arg1, s32 arg2) {
    D_004D5AF8 = arg2 - 1;
    D_004CF574 = 0;
    D_004D5AFC = 0;
    *(s32*)(arg1 + 0xA8) = arg0;
}
#else
void func_0010F3B8(s32 arg0, s32 arg1) {
    *(s32*)(arg1 + 0xA8) = arg0; // todo: figure out what struct this is
    D_004CF574 = 0;
    D_004CF57C = 0;
}
#endif
