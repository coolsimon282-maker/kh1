// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x132D60).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

#include "sdk/ee/eetypes.h"

extern u_long128 D_003F2080;
extern u_long128 D_0040EF80;

void func_0022F808(void) {
    u_long128 *src = &D_003F2080;
    u_long128 *dst = &D_0040EF80;
    s32 count = 0x16C0;
    do {
        *dst = *src;
        src++;
        dst++;
        count--;
    } while (count > 0);
}

#include "sdk/ee/eetypes.h"

extern u_long128 D_0040EF80;
extern u_long128 D_003F2080;

void func_00232DA0(void) {
    u_long128 *src = &D_0040EF80;
    u_long128 *dst = &D_003F2080;
    s32 count = 0x16C0;
    do {
        *dst = *src;
        src++;
        dst++;
        count--;
    } while (count > 0);
}

extern struct {
    s32 unk0;
    s32 unk4;
} D_00425B80;

void func_0022F888(void) {
    D_00425B80.unk0 = 0x5153484B;
    D_00425B80.unk4 = 0x01317F14;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00232E08);

extern u8 D_003F8298[];
u8* func_00232F88(u32 a0) {
    D_003F8298[0xD] = a0 / 10 + '0';
    D_003F8298[0xE] = a0 % 10 + '0';
    return D_003F8298;
}

extern u8 D_003F82A8[];

u8 *func_00232FC8(u32 arg0) {
    D_003F82A8[0xE] = (arg0 / 10) + 0x30;
    D_003F82A8[0xF] = (arg0 % 10) + 0x30;
    D_003F82A8[0x1E] = (arg0 / 10) + 0x30;
    D_003F82A8[0x1F] = (arg0 % 10) + 0x30;
    return &D_003F82A8;
}

extern u8 D_003F82D0[];

u8 *func_00233018(u32 arg0) {
    D_003F82D0[0xE] = (arg0 / 10) + 0x30;
    D_003F82D0[0xF] = (arg0 % 10) + 0x30;
    return &D_003F82D0;
}

extern u8 D_003F82F0[];

u8 *func_00233058(u32 arg0) {
    D_003F82F0[0xE] = (arg0 / 10) + 0x30;
    D_003F82F0[0xF] = (arg0 % 10) + 0x30;
    return &D_003F82F0;
}

extern u8 D_003F8310[];

u8 *func_00233098(u32 arg0) {
    D_003F8310[0xE] = (arg0 / 10) + 0x30;
    D_003F8310[0xF] = (arg0 % 10) + 0x30;
    return &D_003F8310;
}

extern u8 D_003F8330[];

u8 *func_002330D8(u32 arg0) {
    D_003F8330[0xE] = (arg0 / 10) + 0x30;
    D_003F8330[0xF] = (arg0 % 10) + 0x30;
    return &D_003F8330;
}

extern u8 D_003F8350[];

u8 *func_00233118(u32 arg0) {
    D_003F8350[0xE] = (arg0 / 10) + 0x30;
    D_003F8350[0xF] = (arg0 % 10) + 0x30;
    return &D_003F8350;
}

extern s32 D_00351E10;

void func_00233158(void) {
    D_00351E10 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233168);

extern s32 D_00425BC0[];
extern void func_F20000(s32, s32);

void func_002335D8(s32 arg0) {
    func_00120438((const char *)D_00425BC0[arg0], (void *)func_F20000);
    func_F20000(0, 0);
}

extern u8 D_002C5AD0[];
extern s32 D_00425BC8;
extern s32 D_00647780;
extern s32 D_0064778C;
extern s32 D_00647798;
extern void func_002336D8(void);

void func_00233610(void) {
    D_00425BC8 = (s32)&D_002C5AD0;
    D_00647780 = 0;
    D_0064778C = 0;
    D_00647798 = 0;
    func_002336D8();
}

extern s32 D_00647780;
extern s32 D_00647784;
extern s32 D_00647788;
void func_00233650(s32 arg0, s32 arg1) {
    D_00647780 = 1;
    D_00647784 = arg0;
    D_00647788 = arg1;
}

extern s32 D_00647780;

void func_00233670(void) {
    D_00647780 = 0;
}

extern s32 D_0064778C;
extern s32 D_00647790;
extern s32 D_00647794;
void func_00233680(s32 arg0, s32 arg1) {
    D_0064778C = 1;
    D_00647790 = arg0;
    D_00647794 = arg1;
}

extern s32 D_0064778C;

void func_002336A0(void) {
    D_0064778C = 0;
}

extern s32 D_00647798;
extern s32 D_0064779C;

void func_002336B0(s32 arg0) {
    D_00647798 = 1;
    D_0064779C = arg0;
}

extern s32 D_00647798;

void func_002336C8(void) {
    D_00647798 = 0;
}

extern f32 D_006477A4;

void func_002336D8(void) {
    D_006477A4 = 0;
}

f32 func_002336E8(void) {
    return D_006477A4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002336F8);

extern u64 D_006477B0[];
void func_00233AC8(void);
void func_00233A80(void) {
    u64* p;
    s32 i;

    sceMcInit();
    p = D_006477B0;
    for (i = 0x100; i > 0; i--) {
        *p++ = 0;
    }
    func_00233AC8();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233AC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233D08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00233DB0);

extern s32 D_006477A8;

s32 func_00233EE8(void) {
    return D_006477A8;
}

extern s32 D_006477A8;
extern s32 D_00647FD4;
extern s32 D_00647FD8;
void func_00233EF8(s32 arg0) {
    D_006477A8 = 1;
    D_00647FD4 = arg0;
    D_00647FD8 = 0;
}

extern s32 D_006477A8;

void func_00233F18(void) {
    D_006477A8 = 0;
}

extern s32 D_00647FDC;
extern s32 D_00647FE0;

void func_00233F28(s32 arg0, s32 arg1) {
    D_00647FDC = arg0;
    D_00647FE0 = arg1;
}

extern s32 D_00425C48[];

s32 func_00233F40(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C48[];

void func_00233F68(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C48 + (((arg0 * 4) + arg1) * 4));
    *ptr = 0;
}

extern s32 D_00425C68[];

s32 func_00233F88(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C68[];

void func_00233FB0(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C68 + (((arg0 * 4) + arg1) * 4))) = 0;
}

extern s32 D_00425C88[];

s32 func_00233FD0(s32 arg0, s32 arg1) {
    s32 *ptr = (s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4));
    s32 val = *ptr;
    *ptr = 0;
    return val;
}

extern s32 D_00425C88[];

void func_00233FF8(s32 arg0, s32 arg1) {
    *((s32 *)((s32)&D_00425C88 + (((arg0 * 4) + arg1) * 4))) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234018);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234098);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234148);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234210);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234290);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234310);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002343A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002345A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234668);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234730);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002347E0);

extern s32 D_00647FEC;

s32 func_00234840(void) {
    return D_00647FEC;
}

extern s32 D_00647FF0;

s32 func_00234850(void) {
    return D_00647FF0;
}

extern s32 D_00647FF4;

s32 func_00234860(void) {
    return D_00647FF4;
}

extern s32 D_00647FF8;

s32 func_00234870(void) {
    return D_00647FF8;
}

extern s32 D_00647FFC;

s32 func_00234880(void) {
    return D_00647FFC;
}

extern s32 D_00648000;

s32 func_00234890(void) {
    return D_00648000;
}

extern s32 D_00648004;

s32 func_002348A0(void) {
    return D_00648004;
}

extern s32 D_00648008;

s32 func_002348B0(void) {
    return D_00648008;
}

extern s32 D_0064800C;

s32 func_002348C0(void) {
    return D_0064800C;
}

extern s32 D_00648010;

s32 func_002348D0(void) {
    return D_00648010;
}

extern s32 D_00648014;

s32 func_002348E0(void) {
    return D_00648014;
}

extern s32 D_00648018;

s32 func_002348F0(void) {
    return D_00648018;
}

extern s32 D_0064801C;

s32 func_00234900(void) {
    return D_0064801C;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234910);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00234F80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235228);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002353A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235520);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002357F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235AB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236190);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236450);

extern s32 D_00647FB0_b __asm__("D_00647FB0");
extern s32 D_0064801C_b __asm__("D_0064801C");
extern s32 (*D_00648034)(s32);
extern s32 D_00647FC4;
void func_00236598(void) {
    D_00647FB0_b = 0;
    D_00647FD8 = D_00647FD4;
    D_0064801C_b = D_00648034(D_00647FC4);
}

extern s32 D_00647FB0;
extern void (*D_00425BD0[])(void);
void func_002365E0(void) {
    D_00425BD0[D_00647FB0]();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236618);

extern s32 D_00648038[];
void func_002366A8(s32 arg0, s32 arg1) {
    D_00648038[arg0] = arg1;
}

extern s32 D_00648038[];

s32 func_002366C0(s32 arg0) {
    return D_00648038[arg0];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002366D8);

extern s32 D_00648038_b[] __asm__("D_00648038");
void func_002367A0(s32 i) {
    s32* p = &D_00648038_b[i];

    *p = ((s64)*p * 0x41C64E6D + 0x3039) & 0x7FFFFFFF;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002367F8);

void func_002368B0(s32* p) {
    *p = ((s64)*p * 0x41C64E6D + 0x3039) & 0x7FFFFFFF;
}

extern float D_00648050[];
void func_002368F8(s32 arg0, f32 arg1) {
    D_00648050[arg0] = arg1;
}

f32 func_00236910(s32 arg0) {
    return D_00648050[arg0];
}

extern float D_00648050[];

void func_00236928(s32 arg0) {
    f32 *ptr = &D_00648050[arg0];
    ptr[0] = (ptr[0] * 69069.0f + 1.0f) * 0x1.0p-32f;
}

f32 func_00236970(u32 *p) {
    *p = (u64)*p * 0x41C64E6D + 0x3039;
    return *p * (1.0f / 4294967296.0f);
}

f32 func_002369E8(u32 a) {
    a = (u64)a * 0x41C64E6D + 0x3039;
    return a * (1.0f / 4294967296.0f);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236A58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236C68);

s32 func_00236D48(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

s32 func_00236D98(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixX(arg0, arg1, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
    sceVu0RotMatrixZ(arg0, arg0, arg2[2]);
}

// func_00236DE8 (src/unsplit/seg_132D60.c)
void func_00236DE8(f32 (*arg0)[4], f32 fparg0) {
    sceVu0UnitMatrix(arg0);
    arg0[0][0] *= fparg0;
    arg0[1][1] *= fparg0;
    arg0[2][2] *= fparg0;
}

s32 func_00236E40(u32* p) {
    if (p[2] > 0xFFFF28) {
        return 1;
    }
    if (p[0] > 0xFFFF) {
        return 1;
    }
    return p[1] > 0xFFFF;
}

s32 func_00236E80(u32 *a, u32 *b, u32 *c, u32 *d) {
    if (func_00236E40(a) != 0) {
        return 1;
    }
    if (func_00236E40(b) != 0) {
        return 1;
    }
    if (func_00236E40(c) != 0) {
        return 1;
    }
    return func_00236E40(d) != 0;
}

void func_00239368(void);

// func_00236F00 (src/unsplit/seg_132D60.c)
void func_00236F00(void) {
    func_00239368();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236F18);

void func_00236FC0(void) {

}

void func_00236FC8(void) {

}

s32 func_00236FD0(void) {
    return 0;
}

void func_00236FD8(void *arg0, s32 arg1) {
    s64 val = ((((s32)(arg1 - (s32)(long)arg0) >> 4) - 1) | 0x8000) | ((s64)0x8000 << 45);
    ((s64 *)arg0)[1] = 0xE;
    ((s64 *)arg0)[0] = val;
}

// func_00237008 (src/unsplit/seg_132D60.c)
u64* func_00237008(u64 arg0, u64 arg1, u64* arg2) {
    arg2[0] = arg1;
    arg2[1] = arg0;
    return arg2 + 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237018);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002370C8);

extern u8 D_006480D0;
extern void func_002370C8(void *);
extern void func_00237018(void *, s32, s32);

void func_002372E0(void) {
    func_002370C8(&D_006480D0);
    func_00237018(&D_006480D0, 0x16, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237318);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237548);

typedef struct { s32 shift; u8 *buf; } A2Tbl;

void func_00237600(void *arg0) {
    A2Tbl *t = arg0;
    s32 n = 1 << t->shift;
    u8 *p = t->buf;
    s32 i;
    for (i = 0; i < n; i++) {
        memset(p, 0, 8);
        p += 8;
    }
}

extern void func_00237600(void *arg0);

void func_00237660(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0) = arg2;
    *(s32 *)((u8 *)arg0 + 4) = arg1;
    func_00237600(arg0);
}

typedef struct Seg132Node { struct Seg132Node* next; s32 pad; } Seg132Node;
typedef struct { s32 bits; Seg132Node* tbl; } Seg132Ot;
void func_00237680(Seg132Ot* ot, Seg132Node* n, s32 i) {
    s32 max = 1 << ot->bits;

    if (i < 0) {
        i = 0;
    }
    if (i >= max) {
        i = max - 1;
    }
    n->next = ot->tbl[i].next;
    ot->tbl[i].next = n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002376C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237790);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002378C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237A48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237B30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237D48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237EC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237F20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002380C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002384E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002386C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002388B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002389F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238A70);

void func_00238A70(void);
void func_002499F0(void);
extern u_long128 D_00648230[];
int sceGsSetDefLoadImage(void *lp, short dbp, short dbw, short dpsm, short x, short y, short w, short h);
int sceGsExecLoadImage(void *lp, u_long128 *srcaddr);
int sceGsSyncPath(int mode, u_short timeout);
void FlushCache(int);

void func_00239368(void) {
    u_long128 li[6];

    func_00238A70();
    sceGsSetDefLoadImage(li, 0x3FD8, 1, 0, 0, 0, 0x10, 0x10);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(li, D_00648230);
    func_002499F0();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002393D8);

#include "common.h"

extern void func_002452F0(void);
extern void func_00244B00(void);
extern void func_002444A0(void);
extern void func_00243668(void);
extern void func_002458E0(void);
extern void func_00246020(void);
extern void func_00246A60(void);
extern void func_00247350(void);
extern void func_00245140(void);
extern void func_00248B00(void);
extern void func_00249240(void);
extern void func_0023CFD8(void);

void func_00239488(void) {
    func_002452F0();
    func_00244B00();
    func_002444A0();
    func_00243668();
    func_002458E0();
    func_00246020();
    func_00246A60();
    func_00247350();
    func_00245140();
    func_00248B00();
    func_00249240();
    func_0023CFD8();
}

s32 func_002448D8(void);                                /* extern */
s32 func_00245228(void);                                /* extern */
s32 func_00243BD8(void);                                /* extern */
s32 func_00245F18(void);                                /* extern */
s32 func_002474A8(void);                                /* extern */
s32 func_00235F50(void) {
    if (func_002448D8() != 0) {
        return 1;
    }
    if (func_00245228() != 0) {
        return 1;
    }
    if (func_00243BD8() != 0) {
        return 1;
    }
    if (func_00245F18() != 0) {
        return 1;
    }
    return func_002474A8() != 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239558);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239630);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239778);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239860);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002399F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239A80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239B90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239D20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239E30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A318);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A490);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A608);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A720);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A7E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A8D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023AED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023B4B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023B570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023BB98);

s32 func_001233F8(s32);
void func_00141348(s32 *, s32 *);
void func_00246A70(s32 a0, s32 a1, s32 a2, s32 a3);

void func_0023C1B0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 r[4];

    if (func_001233F8(*arg0) != 0) {
        func_00141348(arg0, r);
        if (r[0] != 0 && r[0] != 2) {
            func_00246A70(arg1, arg2, r[1], r[2]);
        }
    }
}

extern s32 D_00651310[];

s32 *func_0023C228(void) {
    s32 *ptr = D_00651310;
    int i;
    for (i = 0; i < 10; i++) {
        if (ptr[0] == 0) {
            ptr[0] = 1;
            ptr[1] = 0;
            return ptr;
        }
        ptr = (s32 *)((u8 *)ptr + 0xE0);
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C270);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C4D8);

extern s32 D_00651310[];

void func_0023C5A8(s32 arg0) {
    *((s32 *)((s32)&D_00651310 + (arg0 * 0xE0))) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C5C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C7A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C8C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023C968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CA48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CB30);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CC80);

extern s32 D_0044A820_a[] __asm__("D_0044A820");
void func_0023CC80(s32*);
s32 func_0023CEB0(void) {
    if (D_0044A820_a[0] == 0) {
        return 0;
    }
    func_0023CC80(D_0044A820_a);
    return 0;
}

extern s32 D_0044A820;

void func_0023CEE8(void) {
    if (D_0044A820 == 0) {
        D_0044A820 = 1;
    }
}

void func_0023CF08(void) {
    if (D_0044A820 == 2) {
        D_0044A820 = 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CF30);

extern s32 D_0044A820;

s32 func_0023CFC8(void) {
    return D_0044A820 != 0;
}

void func_0023CFD8(void) {
    D_0044A820 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023CFE8);

extern void func_0011D790(s32, s32);

void func_0023D128(s32 arg0) {
    func_0011D790(45, arg0);
}

extern void func_0011D598(s32);
extern void func_0011D790(s32, s32);
extern s32 D_00651E50[];

void func_0023D148(s32 arg0) {
    if (D_00651E50[0x1048] == 0) {
        func_0011D598(0x2D);
        func_0011D790(0x2D, arg0);
        D_00651E50[0x1048] = 1;
    }
}

void func_0011D7C0(s32);
void func_0023D1A0(void) {
    if (D_00651E50[0x1048] == 1) {
        func_0011D7C0(0x2D);
        D_00651E50[0x1048] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D1E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D208);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D490);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D528);

extern void func_00249A48(void *arg0, s32 arg1);
extern void *D_00426970;
extern void *D_0042B790;
extern void *D_004305B0;

void func_0023D698(s32 arg0) {
    if (arg0 == 0) {
        func_00249A48(&D_00426970, 1);
    } else if (arg0 == 1) {
        func_00249A48(&D_0042B790, 1);
    } else {
        func_00249A48(&D_004305B0, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D700);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023D7E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023DA08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023DD48);

void func_0023DD48(void);

// func_0023DFC0 (src/unsplit/seg_132D60.c)
void func_0023DFC0(void) {
    func_0023DD48();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023DFD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E160);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E330);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E5B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E8F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023EC88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023EE80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F0D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F250);

extern s32 func_0023F0D8(void *arg0, s32 arg1);
extern s32 func_0023F250(void *arg0, s32 arg1);
extern s32 D_00454A24;

s32 func_0023F688(s32 *arg0, s32 arg1) {
    s32 *p = arg0;
    s32 on;
    if (p[0] == 4) {
        on = D_00454A24;
    } else {
        on = *(s32 *)(*(u8 **)(p[1] + 0x6C) + 0x3C);
    }
    if (on != 0) {
        return func_0023F250(p, func_0023F0D8(arg0, arg1));
    }
    return arg1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F700);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F7D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023F920);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FAD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FB90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FD58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FEB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023FF38);

extern s32 func_0023FEB8(void);
extern s32 func_0023FF38(void *arg0, s32 arg1);

s32 func_00240118(void *arg0, s32 arg1) {
    struct {
        char _[0xA88];
        f32 *field_0A88;
    } *s = arg0;
    if (*s->field_0A88 != 0.0f) {
        return func_0023FF38(arg0, func_0023FEB8());
    }
    return arg1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240170);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002401F0);

extern s32 func_00240170(void);
extern void func_002401F0(s32, s32);

void func_002403D0(s32 arg0) {
    func_002401F0(arg0, func_00240170());
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240400);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002407B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240810);

extern u8 D_00651E70;
extern void func_00240810(void *);

void func_002408D8(s32 arg0) {
    func_00240810((void *)((u8 *)&D_00651E70 + arg0 * 0xD00));
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240910);

extern void *func_00240910(void);

void func_00240978(void) {
    void *temp = func_00240910();
    if (temp != NULL && *(s32 *)((u8 *)temp + 0x9D0) == 0) {
        *(s32 *)((u8 *)temp + 0x9D0) = 1;
    }
}

extern void *func_00240910(void);

void func_002409B0(void) {
    void *temp = func_00240910();
    if (temp != NULL) {
        *(s32 *)((u8 *)temp + 0x9D4) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002409E0);

extern u8 D_00426850[];
s32 func_0023D700(s32, u8*, s32, s32, s32);
s32 func_00240AE0(s32* a0, s32 a1, s32 a2, s32 a3) {
    if (a0[0x94] == 0) {
        return a3;
    }
    return func_0023D700(a0[0], D_00426850, a1, a2, a3);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240B28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240B68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240FA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002410B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241260);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023E0B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241560);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002415F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002416A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241948);

extern u32 D_00652888[];

void func_00241A10(s32 arg0, u32 arg1) {
    D_00652888[arg0 * 0x340] = arg1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241A38);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241B60);

u8 *func_00241B60(s32, s32);

void func_00241C00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p = func_00241B60(3, arg4);
    *(s32 *)(p + 0xA88) = arg0;
    *(s32 *)(p + 0xA8C) = arg1;
    *(s32 *)(p + 0xA90) = arg2;
    *(s32 *)(p + 0xA94) = arg3;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241C60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241D60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242A38);

extern void *func_00240910(void);

void func_00242B00(void) {
    void *temp = func_00240910();
    if (temp != NULL) {
        if (*(s32 *)((u8 *)temp + 0x770) == 0) {
            *(s32 *)((u8 *)temp + 0x770) = 1;
        }
    }
}

extern void *func_00240910(void);

void func_00242B38(void) {
    void *temp = func_00240910();
    if (temp != NULL) {
        *(s32 *)((u8 *)temp + 0x774) = 1;
    }
}

extern void func_0023D1A0(void);
extern s32 D_00651E50[];

void func_00242B68(s32 arg0) {
    D_00651E50[arg0] = 0;
    if (arg0 == 4) {
        func_0023D1A0();
    }
}

extern struct {
    char _[0xCF0];
    s32 field_0CF0;
} D_00654570;

void func_00242BA0(void) {
    if (D_00654570.field_0CF0 == 0) {
        D_00654570.field_0CF0 = 1;
    }
}

extern s32 D_00655264;

// func_00242BC0 (src/unsplit/seg_132D60.c)
void func_00242BC0(void) {
    D_00655264 = 1;
}

extern s32 D_00652898;

void func_00242BD0(void) {
    D_00652898 = 0;
}

extern s32 D_00652898;

// func_0023F758 (src/unsplit/seg_132D60.c)
void func_0023F758(void) {
    D_00652898 = 1;
}

extern s32 D_00651E50[];

s32 func_00242BF0(s32 arg0) {
    return D_00651E50[arg0];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242C08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00242EF8);

void func_00243168(void *arg0, s32 arg1, s32 arg2) {
    memset(arg0, 0, 0x10);
    ((s32 *)arg0)[0] = arg1;
    ((s32 *)arg0)[1] = arg2;
}

typedef struct { s32 a; s32 b; s32 c; } Seg132E12;
typedef struct { s32 cap; Seg132E12* buf; s32 cnt; s32 rd; } Seg132Q;
void func_002431B8(Seg132Q* q, Seg132E12* e) {
    if (q->cnt != q->cap) {
        q->buf[q->cnt] = *e;
        q->cnt++;
    }
}

s32 func_00243208(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    q->rd++;
    if (q->cnt == q->rd) {
        q->rd = 0;
        q->cnt = 0;
    }
    return 1;
}

s32 func_00243278(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    return 1;
}

void func_002432C8(void *arg0) {
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002432D8);

void func_002432D8(s32, s32, s32, s32);                /* extern */

void func_00243380(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
    func_002432D8(arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002433E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243508);

typedef struct { s32 a; s32 b; f32 c; } Seg132Msg;
extern u8 D_006561E4[];
void func_00243630(s32 a0, s32 a1) {
    Seg132Msg m;

    m.b = a1;
    m.a = a0;
    m.c = 1.0f;
    func_002431B8((Seg132Q*)D_006561E4, (Seg132E12*)&m);
}

extern s32 D_006561D0;

void func_00243668(void) {
    D_006561D0 = 0;
    func_002432C8((u8 *)&D_006561D0 + 0x14);
}

typedef struct { s32 a; s32 b; s32 c; } Seg132V3;
typedef struct { s32 flag; Seg132V3 v; s32 z; } Seg132Slot;
extern Seg132Slot D_006561D0_s __asm__("D_006561D0");
void func_00243690(Seg132V3* a0) {
    D_006561D0_s.z = 0;
    D_006561D0_s.v = *a0;
    D_006561D0_s.flag = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002436C0);

void func_002436C0(s32);

s32 func_00243A20(void) {
    Seg132E12 e;
    s32 r = 0;
    s32 *d = &D_006561D0;

    if (*d == 0) {
        if (func_00243208((Seg132Q *)(d + 5), &e) == 0) {
            return 0;
        }
        func_00243690((Seg132V3 *)&e);
    } else {
        r = func_00243278((Seg132Q *)(d + 5), &e) != 0;
    }
    func_002436C0(r);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243A90);

extern s32 D_006561D0_w[] __asm__("D_006561D0");
s32 func_00243BD8(void) {
    s32 buf[4];

    if (D_006561D0_w[0] != 0) {
        return 1;
    }
    return func_00243278((Seg132Q*)&D_006561D0_w[5], (Seg132E12*)buf) != 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243C10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243D18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243DA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243E58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00243EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244188);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244298);

typedef struct { char pad0[0x10]; s32 unk_10; char pad14[0xA00 - 0x14]; } A2Ent_A00;
extern A2Ent_A00 D_00656510[3][5];

void func_002444A0(void) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            D_00656510[i][j].unk_10 = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244500);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244670);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002448D8);

void func_00244960(void) {

}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244968);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244A10);

extern void* D_00662540;

void func_00244B00(void) {
    D_00662540 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244B10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244BE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244D00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244F28);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245148);

s32 func_00245228(void) {
    return D_00662540 != 0;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
} Struct_006627B0;

extern Struct_006627B0 D_006627B0;

void func_00245238(s32 arg0, s32 arg1) {
    D_006627B0.unk10 = 1;
    if (D_006627B0.unk8 == 0 || D_006627B0.unk0 != arg0) {
        D_006627B0.unk0 = arg0;
        D_006627B0.unk4 = arg1;
        D_006627B0.unk8 = 1;
        D_006627B0.unkC = 1.0f;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
} Struct_006627B0_b;
extern Struct_006627B0_b D_006627B0_b __asm__("D_006627B0");
void func_00245280(s32 arg0, s32 arg1) {
    D_006627B0_b.unk10 = 1;
    D_006627B0_b.unk14 = 1;
    if (D_006627B0_b.unk8 == 0 || D_006627B0_b.unk0 != arg0) {
        D_006627B0_b.unk0 = arg0;
        D_006627B0_b.unk4 = arg1;
        D_006627B0_b.unk8 = 1;
        D_006627B0_b.unkC = 1.0f;
    }
}

void func_002452C8(void) {
    if (D_006627B0.unk8 != 0 && D_006627B0.unk8 < 4) {
        D_006627B0.unk8 = 4;
    }
}

extern void* D_006627B8;

void func_002452F0(void) {
    D_006627B8 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245300);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002453E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002455C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002456E8);

void func_00245798(void *arg0, s32 arg1, f32 *arg2) {
    *(s32 *)((u8 *)arg0 + 8) = arg1;
    *(s32 *)arg0 = 1;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    sceVu0CopyVector((u8 *)arg0 + 0x10, arg2);
}

typedef struct { s32 used; s32 age; u8 pad[0x858]; } A2Ent860;
extern u8 D_00662A30[];
extern A2Ent860 D_00662A30_a[10] __asm__("D_00662A30");

void *func_002457C8(void) {
    s32 i;
    A2Ent860 *best = NULL;
    s32 m = -1;
    A2Ent860 *e;

    e = D_00662A30_a;
    for (i = 0; i < 10; i++, e++) {
        if (e->used == 0) {
            return e;
        }
    }
    e = (A2Ent860 *)D_00662A30;
    for (i = 0; i < 10; i++, e++) {
        if (m < e->age) {
            m = e->age;
            best = e;
        }
    }
    return best;
}

extern void *func_001315C0(s32, s32, f32 *, f32);
void func_00245840(s32 arg0, s32 arg1) {
    void *temp;
    f32 tempf;
    temp = func_002457C8();
    func_001315C0(arg0, 0x8004, &tempf, 0.0f);
    func_00245798(temp, arg1, &tempf);
}

extern void *func_002457C8(void);
extern void func_00245798(void *arg0, s32 arg1, f32 *arg2);

void func_002458A0(f32 *arg0, s32 arg1) {
    void *ret = func_002457C8();
    func_00245798(ret, arg1, arg0);
}

extern u8 D_00662A30[];

void func_002458E0(void) {
    u8 *p;
    s32 i;

    p = D_00662A30;
    goto offset;
offset:
    p += 0x4B60;
    for (i = 9; i >= 0; i--) {
        *(void **)p = NULL;
        p -= 0x860;
    }
}

void func_00245918(void) {

}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245920);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245A08);

extern void func_002479A0(s32);
extern void func_00247AA0(s32);

void func_00245AD8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245B08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245CD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245DA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245E40);

typedef struct { s32 unk0; u8 pad[0x85C]; } Seg132_662A30;
extern Seg132_662A30 D_00662A30_e[] __asm__("D_00662A30");
s32 func_00245F18(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        if (D_00662A30_e[i].unk0 != 0) {
            return 1;
        }
    }
    return 0;
}

typedef struct { s32 v[4]; } Seg132_668040e;
extern Seg132_668040e D_00668040_e[] __asm__("D_00668040");
s32 func_0013DAA8(s32);
s32* func_00245F58(a0)
    u8* a0;
{
    s32 i = func_0013DAA8(*(u16*)(*(u8**)(a0 + 0x130) + 0x4C)) != 1;
    return D_00668040_e[i].v;
}

typedef struct { s32 used; f32 f; s32 a; s32 b; } A2Slot10;

void func_00245F90(s32 arg0, s32 arg1) {
    A2Slot10 *s = (A2Slot10 *)func_00245F58(arg1);
    if (s->used == 0) {
        s->a = arg0; //P
        s->b = arg1; //P
        s->used = 1; //P
        s->f = 1.0f; //P
    }
}

extern s32 *func_00245F58();

void func_00245FF0(void) {
    s32 *ptr = func_00245F58();
    if (*ptr != 0) {
        *ptr = 4;
    }
}

typedef struct { s32 unk0; s32 pad[3]; s32 unk10; } Seg132_668040;
extern Seg132_668040 D_00668040;
void func_00246020(void) {
    D_00668040.unk10 = 0;
    D_00668040.unk0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246038);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246120);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002461F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246320);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246438);

void func_002464F8(s32 *out) {
    s32 i;
    for (i = 0; i < 2; i++) {
        switch (D_00668040_e[i].v[0]) {
        case 0:
            out[i] = 0;
            break;
        case 4:
            out[i] = 0;
            break;
        case 5:
            out[i] = 0;
            break;
        case 6:
            out[i] = 0;
            break;
        default:
            out[i] = 1;
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246570);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246658);

s32 func_002466E8(u32 arg0) {
    s32 temp_3;
    temp_3 = (s32) ((arg0 >> 0x1F) + arg0) >> 1;
    return (temp_3 < 0x97) ? temp_3 : 0x96;
}

typedef struct { u64 d[0x18]; } Seg132Blk;
void func_00246708(Seg132Blk* a0, Seg132Blk* a1, s32 a2) {
    *a0 = *a1;
    *(s32*)((u8*)a0 + 8) = a2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246750);

extern void* D_00668370;

void func_00246A60(void) {
    D_00668370 = NULL;
}

typedef struct { s32 unk0; s32 pad4[2]; s32 unkC; s32 unk10; u8 pad14[0xA8C]; s32 unkAA0; s32 unkAA4; s32 unkAA8; } Seg132_668370;
extern Seg132_668370 D_00668370_s __asm__("D_00668370");
void func_00246A70(s32 a0, s32 a1, s32 a2, s32 a3) {
    D_00668370_s.unkC = a2;
    D_00668370_s.unk10 = a3;
    D_00668370_s.unkAA4 = a0;
    D_00668370_s.unkAA8 = a1;
    D_00668370_s.unkAA0 = 1;
    if (D_00668370_s.unk0 == 0) {
        D_00668370_s.unk0 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246AA8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246BC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246CF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246DC0);

void func_00246EA8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00246ED8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002470D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247190);

void func_00247228(void *arg0, s32 arg1, f32 *arg2) {
    s32 *p = arg0;
    p[0x20 / 4] = arg1;
    p[0x0 / 4] = 1;
    p[0x4 / 4] = 0;
    sceVu0CopyVector((f32 *)((char *)arg0 + 0x10), arg2);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", fm_func_00247258);

extern u8 D_0045FAC0[];

// func_00247350 (src/unsplit/seg_132D60.c)
void func_00247350(void) {
    u8* var_2;
    s32 var_3;
    volatile u8* tmp = D_0045FAC0;
    var_3 = 9;
    var_2 = (u8*)tmp + 0x52B0;
    do {
        var_3--;
        *(void**)var_2 = NULL;
        var_2 -= 0x930;
    } while (var_3 >= 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247388);

extern void *func_00247388(void);
extern void *func_001315C0(s32, s32, f32 *, f32);
extern void func_00247228(void *arg0, s32 arg1, f32 *arg2);

void func_00247408(s32 arg0, s32 arg1) {
    void *temp;
    f32 tempf;
    temp = func_00247388();
    func_001315C0(arg0, 0x8004, &tempf, 0.0f);
    func_00247228(temp, arg1, &tempf);
}

extern void *func_00247388(void);
extern void func_00247228(void *arg0, s32 arg1, f32 *arg2);

void func_00247468(f32 *arg0, s32 arg1) {
    void *ret = func_00247388();
    func_00247228(ret, arg1, arg0);
}

extern u8 D_0045FAC0_e[] __asm__("D_0045FAC0");
s32 func_002474A8(void) {
    s32 p = (s32)D_0045FAC0_e;

    do {
        if (*(s32*)p != 0) {
            return 1;
        }
        p += 0x930;
    } while (p < (s32)D_0045FAC0_e + 0x5BE0);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002474E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002475D0);

void func_00247678(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0 / 10;
    *arg2 = arg0 % 10;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002476A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247930);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247B50);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247BD0);

extern void func_002474E8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
extern void func_002476A0(void *arg0);

extern s32 D_006693D0[];
extern u8 D_006692C0[];

void func_00247C50(void *arg0) {
    s32 *ptr = &D_006693D0;
    s32 counter = 6;

    do {
        s32 val = *ptr;
        ptr++;
        counter--;
        func_002474E8(val, D_006692C0, *(s32 *)((u8 *)arg0 + 0x24), *(s32 *)((u8 *)arg0 + 0x28), 1.0f);
    } while (counter >= 0);

    func_002476A0(arg0);
}

extern void func_00249A48(void *, s32);
extern u8 D_00431F30[];

void func_00247CC8(s32 arg0) {
    func_00249A48((void *)((u8 *)&D_00431F30 + arg0 * 0x1770), 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247CF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248010);

extern u8 D_00669320[];
extern s32 D_00669388[];

void fm_func_002480D8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_002474E8(D_00669388[i], D_00669320, 0, 0, 1.0f);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248140);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248380);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248400);

extern s32 D_00669350_w[] __asm__("D_00669350");
void func_002485B8(s32 arg0) {
    D_00669350_w[0] = 1;
    D_00669350_w[1] = arg0;
}

extern void* D_00669350;

void func_00245130(void) {
    D_00669350 = NULL;
}

extern void* D_00669350;

void func_00245140(void) {
    D_00669350 = NULL;
}

s32 func_002485F0(void) {
    s32 r = 0;
    s32* p;

    if (D_00669350_w[0] == 1) {
        p = (s32*)D_00669350_w[1];
        r = p[8] != 0;
        if (p[1] != 0) {
            r |= 2;
        }
    }
    return r;
}

void func_00248628(void *arg0, s32 arg1, s32 arg2) {
    memset(arg0, 0, 0x10);
    ((s32 *)arg0)[0] = arg1;
    ((s32 *)arg0)[1] = arg2;
}

void func_00248678(Seg132Q* q, Seg132E12* e) {
    if (q->cnt != q->cap) {
        q->buf[q->cnt] = *e;
        q->cnt++;
    }
}

s32 func_002486C8(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    q->rd++;
    if (q->cnt == q->rd) {
        q->rd = 0;
        q->cnt = 0;
    }
    return 1;
}

s32 func_00248738(Seg132Q* q, Seg132E12* e) {
    if (q->cnt == q->rd) {
        return 0;
    }
    *e = q->buf[q->rd];
    return 1;
}

void func_00248788(void *arg0) {
    *(u32 *)((u8 *)arg0 + 12) = 0;
    *(u32 *)((u8 *)arg0 + 8) = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248798);

void func_00248798(s32, s32, s32, s32);                /* extern */

void func_00248840(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != 0) {
        func_002479A0(arg1);
    }
    func_00247AA0(arg1);
    func_00248798(arg1, arg2, arg3, arg4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002488A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002489C8);

extern u8 D_00669714[];
void func_00248AC8(s32 a0, s32 a1) {
    Seg132Msg m;

    m.b = a1;
    m.a = a0;
    m.c = 1.0f;
    func_00248678((Seg132Q*)D_00669714, (Seg132E12*)&m);
}

extern s32 D_00669700;

void func_00248B00(void) {
    D_00669700 = 0;
    func_00248788((u8 *)&D_00669700 + 0x14);
}

extern Seg132Slot D_00669700_s __asm__("D_00669700");
void func_00248B28(Seg132V3* a0) {
    D_00669700_s.z = 0;
    D_00669700_s.v = *a0;
    D_00669700_s.flag = 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248B58);

void func_00248B58(s32);

s32 func_00248E30(void) {
    Seg132E12 e;
    s32 r = 0;
    s32 *d = &D_00669700;

    if (*d == 0) {
        if (func_002486C8((Seg132Q *)(d + 5), &e) == 0) {
            return 0;
        }
        func_00248B28((Seg132V3 *)&e);
    } else {
        r = func_00248738((Seg132Q *)(d + 5), &e) != 0;
    }
    func_00248B58(r);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248EA0);

extern u8 D_00669930[];
extern s32 D_00669920;
void func_002475E8(s32, u8*, s32);
s32 func_002388B8(u8*, s32, s32);
void func_00248FB8(s32 a0, s32 a1) {
    func_002475E8(a0, D_00669930, a1);
    D_00669920 = func_002388B8(D_00669930, 1, D_00669920);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002490F0);

extern void* D_00469F60;
extern void func_002490F0(void **);

s32 func_002491F8(void) {
    if (D_00469F60 == NULL) {
        return 0;
    }
    func_002490F0(&D_00469F60);
    return 0;
}

extern void* D_00469F60;

// func_00249230 (src/unsplit/seg_132D60.c)
void func_00249230(void) {
    D_00469F60 = (void *)1;
}

extern void* D_00469F60;

void func_00249240(void) {
    D_00469F60 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249250);

void func_002492D0(f32* v, f32 x, f32 y, f32 z, f32 w) {
    v[0] = x;
    v[1] = y;
    v[3] = z;
    v[2] = w;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002492E8);

s32 func_00249370(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0RotMatrixZ(arg0, arg1, arg2[2]);
    sceVu0RotMatrixX(arg0, arg0, arg2[0]);
    sceVu0RotMatrixY(arg0, arg0, arg2[1]);
}

void func_002493C0(sceVu0FMATRIX out, sceVu0FVECTOR tv, sceVu0FVECTOR rot) {
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    func_00249370(m, m, rot);
    sceVu0TransMatrix(out, m, tv);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249420);

void func_00249518(sceVu0FMATRIX arg0, f32 arg1) {
    sceVu0UnitMatrix(arg0);
    arg0[2][2] = arg1;
    arg0[1][1] = arg1;
    arg0[0][0] = arg1;
}

void func_00249558(void *arg0, void *arg1) {
    *(s32 *)arg0 = (*(s32 *)arg1 - 0x7000) >> 4;
    *(s32 *)((u8 *)arg0 + 4) = (*(s32 *)((u8 *)arg1 + 4) - 0x7400) >> 4;
}

extern sceVu0FVECTOR D_00469F90;
extern sceVu0FVECTOR D_00469FA0;
extern sceVu0FMATRIX D_002DEC20;
s32 func_00249580(f32* a0) {
    sceVu0FVECTOR v;

    sceVu0CopyVector(v, a0);
    return sceVu0ClipAll(D_00469F90, D_00469FA0, D_002DEC20, (sceVu0FVECTOR*)v, 1) != 0;
}

// func_002495C8 (src/unsplit/seg_132D60.c)
void func_002495C8(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 t, u, v;
    t = fparg0 * -3.0f;
    u = fparg0 + fparg0;
    v = fparg1 * 3.0f;
    t = t + v;
    ((f32 *)arg0)[3] = fparg0;
    ((f32 *)arg0)[2] = fparg2;
    t = t - (fparg2 + fparg2);
    u = u - (fparg1 + fparg1);
    t = t - fparg3;
    u = u + fparg2;
    ((f32 *)arg0)[1] = t;
    u = u + fparg3;
    ((f32 *)arg0)[0] = u;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249618);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249718);

void func_002497B8(sceVu0FVECTOR v, sceVu0FVECTOR d, f32 s) {
    sceVu0FVECTOR t;
    sceVu0FVECTOR u;

    sceVu0CopyVector(t, d);
    t[3] = 0.0f;
    sceVu0ScaleVectorXYZ(u, t, s);
    sceVu0AddVector(v, v, u);
}

void func_00249820(s32 *dst, s32 *src) {
    s32 i;
    for (i = 0; i < 4; i++) {
        dst[i] = src[i];
    }
}

void func_00249858(f32 *arg0, f32 *arg1) {
    sceVu0CopyVector(arg0, (f32 *)((u8 *)arg1 + 0x20));
}

void func_00249870(void) {
    ((void (*)(void))sceVu0CopyVector)();
}

void func_00249888(f32 *arg0, f32 *arg1) {
    sceVu0CopyVector(arg0, (f32 *)((u8 *)arg1 + 0x10));
}

void func_002498A0(f32 *v) {
    if (*v < 3.1415926f) {
        *v += 6.2831853f;
    }
    if (*v > 3.1415926f) {
        *v += -6.2831853f;
    }
}

// func_00249900 (src/unsplit/seg_132D60.c)
void func_00249900(f32 *arg0, f32 *arg1) {
    sceVu0FVECTOR temp;
    sceVu0CopyVector(temp, arg0);
    sceVu0CopyVector(arg0, arg1);
    sceVu0CopyVector(arg1, temp);
}

f32 func_00249950(f32 *arg0, f32 fparg0, f32 fparg1) {
    f32 var_f0;
    var_f0 = *arg0;
    if (var_f0 < fparg0) {
        *arg0 = fparg0;
        var_f0 = fparg0;
    }
    if (fparg1 < var_f0) {
        *arg0 = fparg1;
        var_f0 = fparg1;
    }
    return var_f0;
}

void func_00249988(sceVu0FVECTOR out, sceVu0FVECTOR a, sceVu0FVECTOR b, f32 t) {
    sceVu0FVECTOR d;

    sceVu0SubVector(d, b, a);
    sceVu0ScaleVectorXYZ(d, d, t);
    sceVu0AddVector(out, a, d);
}

void func_002499F0(void) {
    u64 buf[6];

    sceGsSyncPath(0, 0);
    buf[2] = 0x1000000000008001;
    buf[3] = 0xE;
    buf[4] = 0;
    buf[5] = 0x3F;
    func_00237018(buf, 3, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249A48);

extern void func_00249D48(s32 *);

void func_00249C48(void) {
    ((void (*)(void))func_00249D48)();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249C60);

typedef struct { s32 n; s32 e[1]; } Seg132_249D20;
s32 func_00249D20(Seg132_249D20* p, s32 a1) {
    p->e[p->n] = a1;
    p->n++;
    return a1 + 0x10;
}

void func_00249D48(s32 *arg0) {
    *arg0 = 0;
}

typedef struct { u64 x : 14; u64 pad : 23; u64 y : 14; } Seg132_249D50;
void func_00249D50(u8* p, s32 x, s32 y) {
    Seg132_249D50* f = (Seg132_249D50*)(p + 0x28);

    f->x = x;
    f->y = y;
}

s32 func_00249DA0(s32 arg0) {
    return arg0 + 0x10;
}

extern char D_00491840[];

void func_00249DA8(const char *s1) {
    strncmp(s1, D_00491840, 4);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249DC8);

void func_00249EB8(void *arg0, void *arg1) {
    u8 *src;
    u8 *dst;
    int i;
    s32 offset;
    src = (u8 *)arg1 + 0x40;
    offset = *(u32 *)((u8 *)arg1 + 0x18);
    src += offset;
    dst = (u8 *)arg0;
    for (i = 0; i < 64; i++) {
        if (i < 32) {
            dst[i] = src[i];
        } else {
            dst[i + 0x20] = src[i];
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00249F08);
