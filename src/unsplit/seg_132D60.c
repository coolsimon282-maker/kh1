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

typedef struct { s32 type; s32 serial; s32 arg[6]; } Ent2347;
extern Ent2347 D_Ent2347[] __asm__("D_006477B0");
extern s32 D_00647FB8;
extern s32 D_00647FC0;
s32 func_002347E0(s32 a0) {
    s32 s;
    D_Ent2347[D_00647FB8].type = 0xD;
    D_Ent2347[D_00647FB8].serial = D_00647FC0;
    D_Ent2347[D_00647FB8].arg[0] = a0;
    D_00647FB8 = (D_00647FB8 + 1) & 0x3F;
    s = D_00647FC0++;
    return s;
}

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

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char D_004913F8[];
extern s32 D_00425CAC;
extern void *D_00425CA8;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcGetDir(int, int, const char *, unsigned, int, void *);
int sceMcSync(int, int *, int *);

void func_00235228(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcGetDir(D_00425C10, D_00425C14, D_004913F8, 0, D_00425CAC, D_00425CA8);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r >= 0) {
            D_00425CAC = r;
            D_00647FF0 = 0;
        } else if (r == -2) {
            D_00425CAC = -1;
            D_00647FF0 = 1;
        } else if (r == -4) {
            D_00425CAC = -1;
            D_00647FF0 = 2;
        } else {
            D_00425CAC = -1;
            D_00647FF0 = 3;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern s32 D_00425CAC;
extern void *D_00425CA8;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcGetDir(int, int, const char *, unsigned, int, void *);
int sceMcSync(int, int *, int *);

void func_002353A8(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcGetDir(D_00425C10, D_00425C14, D_00648020, 0, D_00425CAC, D_00425CA8);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r >= 0) {
            D_00425CAC = r;
            D_00647FF4 = 0;
        } else if (r == -2) {
            D_00425CAC = -1;
            D_00647FF4 = 2;
        } else if (r == -4) {
            D_00425CAC = -1;
            D_00647FF4 = 3;
        } else {
            D_00425CAC = -1;
            D_00647FF4 = 4;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00647FCC;
extern s32 D_00647FD0;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcFormat(int, int);
int sceMcSync(int, int *, int *);

void func_00235520(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcFormat(D_00425C10, D_00425C14);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        if (D_00647FC8 != 0) {
            if (D_00647FCC != 0) {
                D_00647FCC--;
                D_00647FD0 = 0x3C;
                *st = 3;
                break;
            }
            D_00647FF8 = 1;
        } else {
            D_00647FF8 = 0;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    case 3:
        if (D_00647FD0 != 0) {
            D_00647FD0--;
        } else {
            *st = 0;
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00647FCC;
extern s32 D_00647FD0;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcUnformat(int, int);
int sceMcSync(int, int *, int *);

void func_00235688(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcUnformat(D_00425C10, D_00425C14);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        if (D_00647FC8 != 0) {
            if (D_00647FCC != 0) {
                D_00647FCC--;
                D_00647FD0 = 0x3C;
                *st = 3;
                break;
            }
            D_00647FFC = 1;
        } else {
            D_00647FFC = 0;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    case 3:
        if (D_00647FD0 != 0) {
            D_00647FD0--;
        } else {
            *st = 0;
        }
        break;
    }
}

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern char D_00425CB0[];
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcChdir(int, int, const char *, char *);
int sceMcSync(int, int *, int *);

void func_002357F0(void) {
    s32 *st = &D_00647FB4;

    switch (*st) {
    case 0:
        sceMcChdir(D_00425C10, D_00425C14, D_00648020, D_00425CB0);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        switch (D_00647FC8) {
        case 0:
            D_00648000 = 0;
            break;
        case -2:
            D_00648000 = 1;
            break;
        case -4:
            D_00648000 = 2;
            break;
        default:
            D_00648000 = 3;
            break;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235950);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235AB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235D70);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00235EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00236190);

extern s32 D_00647FB4;
extern s32 D_00647FC8;
extern s32 D_00425C10;
extern s32 D_00425C14;
extern char *D_00648020;
extern char *D_00648024;
extern s32 D_00647FB0_a __asm__("D_00647FB0");
extern s32 (*D_00648034_a)(s32) __asm__("D_00648034");
extern s32 D_00647FC4_a __asm__("D_00647FC4");
int sceMcRename(int, int, const char *, const char *);
int sceMcSync(int, int *, int *);

void func_00236450(void) {
    s32 *st = &D_00647FB4;
    s32 r;

    switch (*st) {
    case 0:
        sceMcRename(D_00425C10, D_00425C14, D_00648020, D_00648024);
        (*st)++;
        break;
    case 1:
        if (sceMcSync(1, NULL, &D_00647FC8) != 0) {
            (*st)++;
        }
        break;
    case 2:
        r = D_00647FC8;
        if (r == 0) {
            D_00648018 = 0;
        } else if (r == -2) {
            D_00648018 = 1;
        } else if (r == -4) {
            D_00648018 = 2;
        } else {
            D_00648018 = 3;
        }
        D_00647FB0_a = 0;
        D_00647FD8 = D_00647FD4;
        if (D_00648034_a != NULL) {
            D_00648034_a(D_00647FC4_a);
        }
        break;
    }
}

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

extern f32 D_00425CE0[4][4];

void func_00236C68(sceVu0FMATRIX out, sceVu0FVECTOR a1, sceVu0FVECTOR a2, sceVu0FVECTOR a3, f32 *rot) {
    sceVu0FMATRIX m;
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR v2;

    sceVu0RotMatrixX(m, D_00425CE0, rot[0]);
    sceVu0RotMatrixY(m, m, rot[1]);
    sceVu0RotMatrixZ(m, m, rot[2]);
    sceVu0ApplyMatrix(v0, m, a2);
    sceVu0ApplyMatrix(v1, m, a3);
    sceVu0ApplyMatrix(v2, m, a1);
    sceVu0CameraMatrix(out, v2, v0, v1);
}

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

extern u8 D_00425F80[];
extern u8 D_00425F88[];
extern s32 D_00425F78;
void func_0023B570(void); void func_0023C968(void); void func_00242A38(void); void func_00243A90(void);
void func_00244500(void); void func_00245148(void); void func_002456E8(void); void func_00245E40(void);
void func_00246438(void); void func_00246BC8(void); void fm_func_00247258(void); void func_00248400(void);
void func_00248EA0(void); void func_00249250(void);
void func_00236F18(void) {
    func_00237660(D_00425F80, (s32)D_00425F88, 8);
    func_0023B570();
    func_0023C968();
    func_00242A38();
    func_00243A90();
    func_00244500();
    func_00245148();
    func_002456E8();
    func_00245E40();
    func_00246438();
    func_00246BC8();
    fm_func_00247258();
    func_00248400();
    func_00248EA0();
    func_00249250();
    D_00425F78 = 0;
}

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

void func_00237548(f32 *arg0, f32 *arg1, f32 *arg2, f32 (*arg3)[4]) {
    f32 sp[12];

    sceVu0ApplyMatrix(&sp[0], arg3, arg0);
    sceVu0ApplyMatrix(&sp[4], arg3, arg1);
    sceVu0ApplyMatrix(&sp[8], arg3, arg2);
    sceVu0DivVectorXYZ(&sp[0], &sp[0], sp[3]);
    sceVu0DivVectorXYZ(&sp[4], &sp[4], sp[7]);
    sceVu0DivVectorXYZ(&sp[8], &sp[8], sp[11]);
    sceVu0ClipScreen3(&sp[0], &sp[4], &sp[8]);
}

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

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 n;
    s32 unk_0C;
    u_long128 q[1];
} A2QList;

u_long128* func_00237EC0(A2QList* a0, u_long128* a1) {
    s32 i;
    s32 k = 1;
    for (i = 0; i < a0->n; i++) {
        a1[k] = a0->q[i];
        k++;
    }
    a1[0] = 0;
    *(s32*)a1 = (k - 1) | 0x10000000;
    return a1 + k;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00237F20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002380C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238258);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238440);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002384E0);

void func_002386C0(u_long128 *src, s32 n, u_long128 *dst) {
    s32 i;
    s32 k = 2;
    u_long128 *d;
    u_long128 *s;
    if (n > 0) {
        s = src;
        i = n;
        do {
            d = (u_long128 *)(k * 16 + (s32)dst);
            i--;
            d[0] = s[0];
            k += 6;
            d[1] = s[1];
            d[2] = s[2];
            d[3] = s[3];
            d[4] = s[4];
            d[5] = s[5];
            s += 6;
        } while (i != 0);
    }
    dst[1] = 0;
    ((u64 *)dst)[3] = 0x43413E;
    ((u64 *)dst)[2] = n | 0x8000 | ((u64)0x60AB4000 << 32);
    func_00237018(dst, k, 1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00238768);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002388B8);

extern s32 D_00440994;

s32 func_002389F0(s32 n) {
    s32 i;
    s32 off = 0;
    for (i = 0; i < n; i++) {
        if (i == 5) {
            off += 0x4440;
        } else if (i == 8) {
            off += 0x4440;
        } else if (i == 9) {
            off += 0x1440;
        } else if (i >= 11 && i <= 20) {
            off += 0x1440;
        } else {
            off += 0x2080;
        }
    }
    return D_00440994 + off;
}

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

u8 *func_001478C8(s32 i);
s32 func_00147808(s32 n);
s32 func_001F0638_c(s32, s32, s32, s32, s32, s32) __asm__("func_001F0638");
extern s32 D_006488F0;
extern f32 D_00650DD0;

void func_00239558(s32 a0, s32 a1, s32 a2, u8 c) {
    u8 col[4];

    col[0] = c;
    col[1] = c;
    col[2] = c;
    col[3] = D_00650DD0 * 128.0f;
    D_006488F0 = func_001F0638_c(D_006488F0, 1, *(s32 *)col, ((a1 * 16 + 0x7100) >> 4) - 0x700,
                                 ((a2 * 16 + 0x7420) >> 4) - 0x740, func_00147808(*(u16 *)(func_001478C8(a0) + 4)));
}

typedef struct { s32 v[4]; } V4_9630;
typedef struct { u8 pad[0x60]; V4_9630 m[4]; struct { s32 a; s32 b; s32 c; s32 d; } n[4]; } Obj9630;
extern Obj9630 D_00648900_o __asm__("D_00648900");
extern f32 D_00650DD4;
void func_002475E8(s32, u8 *, s32);
s32 func_002388B8(u8 *, s32, s32);

void func_00239630(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;
    s32 j;

    func_002475E8(a0, (u8 *)&D_00648900_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00648900_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            D_00648900_o.m[i].v[j] = D_00648900_o.m[i].v[j] * f;
        }
    }
    for (i = 0; i < 4; i++) {
        D_00648900_o.m[i].v[3] = D_00648900_o.m[i].v[3] * D_00650DD4;
    }
    D_006488F0 = func_002388B8((u8 *)&D_00648900_o, 1, D_006488F0);
}

void func_00239630(s32, s32, s32, s32, f32);

void func_00239778(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f) {
    if (a0 != 0) {
        func_002479A0(a1);
        if (a2 != 0) {
            func_002479A0(a2);
        }
    }
    func_00247AA0(a1);
    if (a2 != 0) {
        func_00247AA0(a2);
    }
    func_00239630(a1, a3, a4, a5, f);
    if (a2 != 0) {
        func_00239630(a2, a3, a4, a5, f);
    }
}

void func_00239860(s32 a0, s32 a1, s32 x, s32 y, f32 f, s32 a5, s32 col, s32 a7) {
    s32 i;
    s32 j;

    func_002475E8(a0, (u8 *)&D_00648900_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00648900_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a7 != 0 || j != 3) {
                D_00648900_o.m[i].v[j] = ((s32 *)col)[j];
            }
            if (a5 != 0) {
                D_00648900_o.m[i].v[j] = D_00648900_o.m[i].v[j] * f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        D_00648900_o.m[i].v[3] = D_00648900_o.m[i].v[3] * D_00650DD4;
    }
    D_006488F0 = func_002388B8((u8 *)&D_00648900_o, 1, D_006488F0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002399F0);

void func_00239860(s32, s32, s32, s32, f32, s32, s32, s32);

void func_00239A80(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f) {
    if (a0 != 0) {
        func_002479A0(a1);
        if (a2 != 0) {
            func_002479A0(a2);
        }
    }
    func_00247AA0(a1);
    if (a2 != 0) {
        func_00247AA0(a2);
    }
    func_00239860(a1, a3, a4, a5, f, 0, a6, 0);
    if (a2 != 0) {
        func_00239860(a1, a3, a4, a5, f, 0, a6, 0);
    }
}

void func_00239B90(s32 a0, s32 a1, s32 x, s32 y, f32 f, s32 a5, s32 col, s32 a7) {
    s32 i;
    s32 j;

    func_002475E8(a0, (u8 *)&D_00648900_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00648900_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (a7 != 0 || j != 3) {
                D_00648900_o.m[i].v[j] = ((s32 *)col)[i * 4 + j];
            }
            if (a5 != 0) {
                D_00648900_o.m[i].v[j] = D_00648900_o.m[i].v[j] * f;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        D_00648900_o.m[i].v[3] = D_00648900_o.m[i].v[3] * D_00650DD4;
    }
    D_006488F0 = func_002388B8((u8 *)&D_00648900_o, 1, D_006488F0);
}

void func_00239B90(s32, s32, s32, s32, f32, s32, s32, s32);

void func_00239D20(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f) {
    if (a0 != 0) {
        func_002479A0(a1);
        if (a2 != 0) {
            func_002479A0(a2);
        }
    }
    func_00247AA0(a1);
    if (a2 != 0) {
        func_00247AA0(a2);
    }
    func_00239B90(a1, a3, a4, a5, f, 0, a6, 0);
    if (a2 != 0) {
        func_00239B90(a1, a3, a4, a5, f, 0, a6, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00239E30);

/* unused: layout only (notes/f1.md F1): without them func_00245F58 changes; 1-4 all OK */
extern s32 D_23A318_pad1;
extern s32 D_23A318_pad2;
extern u64 D_00648630[];
extern u_long128 *D_006488F0_p __asm__("D_006488F0");
extern u_long128 *D_006488F4;
void func_0023BB98(s32, s32, s32, s32, u8 *, s32, s32, f32);
void func_00239E30(s32, s32, s32, s32, u8 *, s32, s32, f32);

void func_0023A318(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6, f32 f) {
    func_002370C8(D_00648630);
    D_00648630[0x1C] = 5;
    D_00648630[0xC] = 0x30003;
    func_00237018(D_00648630, 0x16, 1);
    D_006488F4 = (u_long128 *)&D_00351E10;
    D_006488F0_p = (u_long128 *)&D_00351E10 + 1;
    if (a0 == 0 && *(s32 *)(a4 + 0x1C4) == 0) {
        func_0023BB98(0, a1, a2, a3, a4, a5, a6, f);
    } else {
        func_00239E30(a0, a1, a2, a3, a4, a5, a6, f);
    }
    if (f != 0.0f) {
        func_00237018(D_006488F4, D_006488F0_p - D_006488F4, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A490);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_0023A608);

typedef struct {
    s32 unk0;
    u32 mask;
    s32 unk8;
    s32 unkC;
    s32 n;
    u8 pad14[0x10];
    u8 c[1];
} Seg132_2E3170;
extern Seg132_2E3170 *D_002E3170[];

void func_0023A720(void) {
    Seg132_2E3170 **pp = D_002E3170;
    Seg132_2E3170 *e;
    s32 i;

    for (; *pp != NULL; pp++) {
        e = *pp;
        if (pp[1] == NULL) {
            for (i = 0; i < e->n; i++) {
                if (e->mask & (1 << i)) {
                    e->c[i] = 0x73;
                } else {
                    e->c[i] = 0xE6;
                }
            }
        } else {
            for (i = 0; i < e->n; i++) {
                e->c[i] = 0x73;
            }
        }
    }
}

/* unused: layout only (F1): keeps func_00245F58 / func_00247CC8 */
extern s32 D_23A7E8_pad1;
extern f32 D_002B8344;

void func_0023A7E8(void) {
    Seg132_2E3170 **pp = D_002E3170;
    Seg132_2E3170 *e;
    s32 i;
    s32 v;

    for (; *pp != NULL; pp++) {
        e = *pp;
        if (pp[1] == NULL) {
            for (i = 0; i < e->n; i++) {
                if (e->mask & (1 << i)) {
                    v = e->c[i];
                    v = v - D_002B8344 * 32.0f;
                    v = (v < 0x73) ? 0x73 : v;
                    e->c[i] = v;
                } else {
                    v = e->c[i];
                    v = v + D_002B8344 * 32.0f;
                    v = (v > 0xE6) ? 0xE6 : v;
                    e->c[i] = v;
                }
            }
        }
    }
}

extern u32 D_002C1EA8;

void func_0023A8D0(void *arg0) {
    s32 var_5 = 0;

    if (D_002C1EA8 & 1) {
        if (*(u32 *)((u8 *)arg0 + 0x1C0) != ((u8 *)arg0 + 0x40)) {
            *(u32 *)((u8 *)arg0 + 0x1C0) = (u32)((u8 *)arg0 + 0x40);
            func_002479A0((u8 *)arg0 + 0x40);
            var_5 = 1;
            *(u32 *)((u8 *)arg0 + 0x1C4) = 0;
        }
    } else {
        if (*(u32 *)((u8 *)arg0 + 0x1C0) != ((u8 *)arg0 + 0x100)) {
            *(u32 *)((u8 *)arg0 + 0x1C0) = (u32)((u8 *)arg0 + 0x100);
            func_002479A0((u8 *)arg0 + 0x100);
            var_5 = 1;
            *(u32 *)((u8 *)arg0 + 0x1C4) = 1;
        }
    }

    if (var_5 == 0) {
        func_00247AA0(*(u32 *)((u8 *)arg0 + 0x1C0));
    }
}

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

extern u64 D_00650DE0[];
extern u_long128 *D_00651200;
extern u_long128 *D_00651204;
typedef struct { s32 used; u8 pad4[0xDC]; } Ent132_E0s;
extern Ent132_E0s D_00651310_s[] __asm__("D_00651310");
void func_0023C270(Ent132_E0s *);

s32 func_0023C400(void) {
    s32 i;
    func_002370C8(D_00650DE0);
    D_00650DE0[0x1C] = 5;
    D_00650DE0[0xC] = 0x30003;
    func_00237018(D_00650DE0, 0x16, 1);
    D_00651204 = (u_long128 *)&D_00351E10;
    D_00651200 = (u_long128 *)&D_00351E10 + 1;
    for (i = 0; i < 10; i++) {
        if (D_00651310_s[i].used != 0) {
            func_0023C270(&D_00651310_s[i]);
        }
    }
    func_00237018(D_00651204, D_00651200 - D_00651204, 1);
    return 0;
}

typedef struct { u64 d[0x18]; } Blk132_C0;
typedef struct { s32 a; s32 b; } Pair132;
typedef struct {
    s32 used;
    s32 unk4;
    s32 unk8;
    s32 padC;
    Blk132_C0 blk;
    s32 unkD0;
    s32 unkD4;
    Pair132 pair;
} Ent132_E0;
extern Blk132_C0 *D_00651300;
extern Ent132_E0 D_00651310_e[] __asm__("D_00651310");

s32 func_0023C4D8(Pair132 *a0, s32 a1, s32 a2, s32 a3) {
    Ent132_E0 *e = (Ent132_E0 *)func_0023C228();
    s32 r = -1;
    if (e != NULL) {
        Blk132_C0 *s = D_00651300;
        e->unk8 = a1;
        e->blk = *s;
        e->unkD0 = a2;
        e->unkD4 = a3;
        r = e - D_00651310_e;
        e->pair = *a0;
    }
    return r;
}

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

void func_002479A0(s32);
void func_00247AA0(s32);
void func_0023CB30(s32 *);
extern s32 D_00651BD8[3];
extern s32 D_00651BE8[3];
extern f32 D_002B8344;

void func_0023CC80(s32 *a0) {
    s32 i;

    switch (a0[0]) {
    case 1:
        *(f32 *)&a0[1] = 1.0f;
        for (i = 0; i < 3; i++) {
            func_002479A0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_002479A0(D_00651BE8[i]);
        }
        a0[0]++;
        break;
    case 2:
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BE8[i]);
        }
        break;
    case 3:
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BE8[i]);
        }
        *(f32 *)&a0[1] = 1.0f;
        a0[0]++;
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BD8[i]);
        }
        for (i = 0; i < 3; i++) {
            func_00247AA0(D_00651BE8[i]);
        }
        *(f32 *)&a0[1] -= D_002B8344 * 0.16666666f;
        if (*(f32 *)&a0[1] <= 0.0f) {
            *(f32 *)&a0[1] = 0.0f;
            a0[0] = 0;
        }
        break;
    }
    func_0023CB30(a0);
}

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

s32 func_0023D1E0(f32 a0) {
    return a0 / 0.7853981f;
}

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

typedef struct {
    u64 a;
    u64 b;
} A3V16;
typedef struct {
    s32 w[2];
    s32 c;
    s32 pad;
    u64 rest[0x16];
} A3Blk;
extern A3V16 D_004915A0;
s32 func_0023E160(u8 *, s32, A3V16 *, s32, f32, f32, f32);
void func_0023D528(u8 *, s32 *, s32 *);
s32 func_0023D700_f(s32, s32, s32, s32, s32, f32) __asm__("func_0023D700");

s32 func_0023E330(u8 *a0, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    A3V16 col;
    f32 s;
    f32 f;

    s32 i;
    s32 n;
    s32 q;
    s32 m;

    col = D_004915A0;
    s = **(f32 **)(a0 + 0xA94) * 0.000174532892f;
    if (4.71238804f < s) {
        s = 4.71238804f;
    }
    a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x10, &col, a1, 0.0f, s, *(f32 *)(a0 + 0xA1C));
    s = **(f32 **)(a0 + 0xA94) * 0.000174532892f;
    if (s <= 4.71238804f) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    n = **(f32 **)(a0 + 0xA94) - 27000.0f;
    q = n / 3000;
    for (i = 0; i < q; i++) {
        a1 = func_0023D700_f(*(s32 *)(a0 + 0x5C), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        pos[0] -= 0x1A;
    }
    m = n % 3000;
    if (m != 0) {
        f = m / 3000.0f;
        pos[0] = pos[0] + (1.0f - f) * 26.0f;
        tmp = **(A3Blk **)(a0 + 0x5C);
        tmp.c = tmp.c * (f + 0.0625f);
        a1 = func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    } else {
        pos[0] += 0x1A;
    }
    **(s32 **)(a0 + 0x64) = 0x19E;
    a1 = func_0023D700_f(*(s32 *)(a0 + 0x64), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    return a1;
}

extern A3V16 D_004915B0;

s32 func_0023E5B0(u8 *a0, s32 a1) {
    s32 bufA[4];
    s32 pos[4];
    A3Blk tmp;
    A3Blk blk;
    A3V16 col;
    f32 s;
    f32 f;

    s32 i;
    s32 n;
    s32 q;
    s32 m;

    col = D_004915B0;
    s = **(f32 **)(a0 + 0xA90) * 0.000174532892f;
    if (4.71238804f < s) {
        s = 4.71238804f;
    }
    a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90), &col, a1, 0.0f, s, *(f32 *)(a0 + 0xA1C));
    s = **(f32 **)(a0 + 0xA90) * 0.000174532892f;
    if (s <= 4.71238804f) {
        return a1;
    }
    func_0023D528(a0, bufA, pos);
    blk = **(A3Blk **)(a0 + 0x58);
    blk.w[0] += 0x1A;
    n = **(f32 **)(a0 + 0xA90) - 27000.0f;
    q = n / 3000;
    for (i = 0; i < q; i++) {
        if (i == 0) {
            a1 = func_0023D700_f(*(s32 *)(a0 + 0x54), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        } else {
            a1 = func_0023D700_f((s32)&blk, *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
        }
        pos[0] -= 0x1A;
    }
    m = n % 3000;
    if (m != 0) {
        f = m / 3000.0f;
        pos[0] = pos[0] + (1.0f - f) * 26.0f;
        if (q == 0) {
            tmp = **(A3Blk **)(a0 + 0x54);
        } else {
            tmp = blk;
        }
        tmp.c = tmp.c * (f + 0.0625f);
        a1 = func_0023D700_f((s32)&tmp, *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    } else {
        pos[0] += 0x1A;
    }
    **(s32 **)(a0 + 0x60) = 0x19E;
    a1 = func_0023D700_f(*(s32 *)(a0 + 0x60), *(s32 *)(a0 + 0x6C), pos[0], pos[1], a1, *(f32 *)(a0 + 0xA1C));
    return a1;
}

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

extern A3V16 D_004915F0;

s32 func_0023F700(u8 *a0, s32 a1) {
    A3V16 col;

    col = D_004915F0;
    a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x30, &col, a1, 0.0f, *(f32 *)(a0 + 0x9E4), *(f32 *)(a0 + 0xA1C));
    if (*(f32 *)(a0 + 0x9F0) != 0.0f) {
        s32 *c = (s32 *)&col;
        c[0] = c[1] = c[2] = *(f32 *)(a0 + 0x9EC);
        c[3] = 0x80;
        a1 = func_0023E160(a0 + 0x80, *(s32 *)(a0 + 0x90) + 0x30, &col, a1, *(f32 *)(a0 + 0x9E4), *(f32 *)(a0 + 0x9E8), *(f32 *)(a0 + 0xA1C));
    }
    return a1;
}

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

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } Seg132_454A20;
extern Seg132_454A20 D_00454A20;

s32 func_00240810(s32 *a0) {
    s32 r;
    s32 q;
    s32 n;
    u8 *p;

    if (a0[0] == 4) {
        r = 0;
        if (D_00454A20.unk4 != 0) {
            if ((f32)D_00454A20.unk4 < (f32)D_00454A20.unkC * 0x1.333332p-2f) {
                r = 1;
            }
        }
    } else {
        r = 0;
        if (a0[0] != 3) {
            p = *(u8 **)(*(u8 **)(a0 + 1) + 0x6C);
            q = *(s32 *)(p + 0x3C);
            if (q > 0) {
                n = *(s32 *)(p + 0x40);
                r = q < 9;
                if (n >= 45) {
                    r = (f32)q / (f32)n < 0x1.999998p-3f;
                }
            }
        }
    }
    return r;
}

extern u8 D_00651E70;
extern s32 func_00240810(s32 *);

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

extern f32 D_002B8344;
s32 func_00240B28(u8* a0) {
    s32 r;
    if (*(s32*)(a0 + 0xA30) > 0) {
        *(s32*)(a0 + 0xA30) -= D_002B8344;
        r = 1;
    } else {
        r = 2;
        if (*(s32*)(a0 + 0xA24) == 0) r = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240B68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00240FA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002410B8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241260);

typedef struct { u8 pad[0xA1C]; f32 a; f32 b; u8 pad2[0xD00 - 0xA24]; } S651E70;
void func_0023E0B0(s32 a0, s32 a1) {
    S651E70 *p = (S651E70 *)&D_00651E70 + a0;

    switch (a1) {
    case 0:
        p->a = 1.0f;
        p->b = -0.0999999940395355224609375f;
        break;
    case 1:
        p->a = 0.0f;
        p->b = 0.0999999940395355224609375f;
        break;
    case 2:
        p->b = 0.0f;
        p->a = 1.0f;
        break;
    case 3:
        p->b = 0.0f;
        p->a = 0.0f;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241560);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002415F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002416A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00241948);

/* unused: layout only (notes/f1.md F1, with func_0023A7E8): 1, 3, 4, 5 of these keep func_00241A10 folding its store */
extern s32 D_241A10_pad1;
extern s32 D_241A10_pad2;
extern s32 D_241A10_pad3;
extern s32 D_241A10_pad4;
extern u32 D_00652888[];

void func_00241A10(s32 arg0, u32 arg1) {
    D_00652888[arg0 * 0x340] = arg1;
}

void func_002492D0(f32 *, f32, f32, f32, f32);

void func_00241A38(s32 a0) {
    u8 *p;
    u8 *q;
    s32 t;
    u16 r;
    s32 w;

    if (D_00651E50[a0] != 0) {
        p = (u8 *)D_00651E50 + 0x20 + a0 * 0xD00;
        t = *(s32 *)p;
        if (t != 4) if (t != 3) {
            q = *(u8 **)(*(u8 **)(p + 4) + 0x6C);
            w = *(s32 *)(q + 0x44);
            r = *(u16 *)(q + 0xBE);
            *(s32 *)(p + 0x9E0) = w;
            *(f32 *)(p + 0x9E4) = w * 0.5235987f;
            func_002492D0((f32 *)(p + 0x9EC), 0.0f, 0.0f, 0.0f, 128.0f);
            *(s32 *)(p + 0x9FC) = r;
            *(f32 *)(p + 0xA00) = r * 0.017453289f;
            func_002492D0((f32 *)(p + 0xA08), 0.0f, 0.0f, 0.0f, 128.0f);
        }
    }
}

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

extern u8 D_0044A830[];
extern u8 D_0044C5A0[];
extern u8 D_0044DFD0[];
extern u8 D_0044F380[];
extern u8 D_0044F4D0[];
extern u8 D_00451040[];
extern u32 D_002C1EA8;
void func_00247668();
s32 func_0011ED60();
s32 func_002416A8();
void func_00241D60();

void func_00242A38(void) {
    func_00247668(D_0044A830);
    func_00247668(D_0044C5A0);
    func_00247668(D_0044DFD0);
    func_00247668(D_0044F380);
    func_00247668(D_0044F4D0);
    func_00247668(D_00451040);
    memset(D_00651E50, 0, 0x4130);
    D_00651E50[0x1049] = (D_002C1EA8 >> 3) & 1;
    func_00241D60();
    if (func_0011ED60(func_002416A8) == 0) {
        func_0011ED30(0x29811, func_002416A8);
    }
}

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

typedef struct { s32 w; s32 h; u8 pad[8]; u8 clut[0x400]; u8 img[1]; } Seg132Tex;
typedef struct { u8 pad[0x140]; Seg132Tex *tex; } Seg132TexOwner;
typedef struct { s32 x; s32 y; s32 z; s32 w; } Seg132QW;
u32 func_00122048(s32 a, u32 b);
u_long128 *func_0011F9E8(s32 dbp, s32 dbw, s32 dpsm, s32 dsax, s32 dsay, s32 rrw, s32 rrh, s32 qwc, s32 src, u_long128 *pkt);
u64 *func_0011F970(u64 arg0, u64 arg1, u64 *arg2);
void func_0011F9B0(u_long128 *arg0, s32 arg1, u_long128 *arg2);
void *sceDmaGetChan(int);
void sceDmaSend(void *, void *);
void func_001220B8(u32);

void func_00242C08(Seg132TexOwner *a0, s32 a1, s32 *a2, f32 f) {
    Seg132Tex *t = a0->tex;
    u32 buf;
    u_long128 *p;
    Seg132QW *v;
    s32 n;

    if (t == NULL) {
        return;
    }
    buf = func_00122048(0, 0x10);
    p = func_0011F9E8(0x3C00, 0, 0, 0, 0, 0x10, 0x10, 0x40, (s32)t->clut, (u_long128 *)buf);
    p = func_0011F9E8(0x3A00, 4, 0x13, 0, 0, t->w, t->h, t->w * t->h / 16, (s32)t->img, p);
    v = (Seg132QW *)p;
    v++;
    ((u64 *)v)[0] = 0x80AB400000008001;
    ((u64 *)v)[1] = 0x53531EEE;
    v++;
    v = (Seg132QW *)func_0011F970(0x3F, 0, (u64 *)v);
    v = (Seg132QW *)func_0011F970(6, 0x20078005A1313A00, (u64 *)v);
    v = (Seg132QW *)func_0011F970(0x14, 0, (u64 *)v);
    v->x = 0x80;
    v->y = 0x80;
    v->z = 0x80;
    v->w = (u32)(f * 128.0f);
    v++;
    n = a1 + 1;
    v->x = t->h * a1 * 16;
    v->y = 0;
    v++;
    v->x = a2[0] - t->h / 2 * 16;
    v->y = a2[1] - t->h / 2 * 16;
    v->z = 0;
    v->w = 0x8000;
    v++;
    v->x = t->h * n * 16;
    v->y = t->h * 16;
    v++;
    v->x = a2[0] + t->h / 2 * 16;
    v->y = a2[1] + t->h / 2 * 16;
    v->z = 0;
    v->w = 0;
    v++;
    func_0011F9B0(p, 7, (u_long128 *)v);
    FlushCache(0);
    sceDmaSend(sceDmaGetChan(2), (void *)((buf & 0x0FFFFFFF) | 0x80000000));
    sceGsSyncPath(0, 0);
    func_001220B8(buf);
}

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

extern s32 D_00458548;
extern s32 D_0045854C;
extern s32 D_006560E0;

void func_002433E8(s32 x, s32 y, s32 a2, s32 a3, f32 f) {
    u8 col[4];
    u8 *a;

    if (a3 != 0) {
        col[0] = 0x73;
        col[1] = 0x73;
        col[2] = 0x73;
        a = &col[3];
        *a = f * 128.0f;
    } else {
        col[0] = 0xE6;
        col[1] = 0xE6;
        col[2] = 0xE6;
        a = &col[3];
        *a = f * 128.0f;
    }
    D_006560E0 = func_001F0638_c(D_006560E0, 1, *(s32 *)col, (((x + D_00458548) * 16 + 0x7000) >> 4) - 0x700,
                                 (((y + D_0045854C) * 16 + 0x7400) >> 4) - 0x740, a2);
}

void func_002477A8(u8 *, s32 *);
u8 *func_00147A88(s32);

void func_00243508(s32 a0, u8 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f) {
    s32 buf[4];
    s32 i;
    s32 n;
    u8 *q = a1;

    for (i = 0; i < 7; i++) {
        func_00243380(a0, (s32)a1, a2, a4, a5);
        a1 += 0xC0;
    }
    for (i = 0; i < 2; i++) {
        func_00243380(a0, (s32)a1, a3, a4, a5);
        a1 += 0xC0;
    }
    if (a6 != 0) {
        n = func_00147808(*(u16 *)func_00147A88(a6));
        func_002477A8(q, buf);
        func_002433E8(a4 + buf[0], a5 + buf[1], n, a7, f);
    }
}

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

extern u8 D_00454A40[];
extern u8 D_00455A10[];
extern u8 D_004569E0[];
extern u8 D_004577D0[];
extern u8 D_00458520[];
extern u8 D_00656230[];

void func_00243A90(void) {
    memset(&D_006561D0, 0, 0x60);
    func_00243168((u8 *)&D_006561D0 + 0x14, 5, (s32)((u8 *)&D_006561D0 + 0x24));
    D_006561D0 = 0;
    func_00247668(D_00454A40);
    func_00247668(D_00455A10);
    func_00247668(D_004569E0);
    func_00247668(D_004577D0);
    func_00247B60(D_00458520, D_00656230, D_00454A40);
    func_00247B60(D_00458520, D_00656230 + 0x24, D_00455A10);
    func_00247B60(D_00458520, D_00656230 + 0x48, D_004569E0);
    func_00247B60(D_00458520, D_00656230 + 0x6C, D_004577D0);
    if (func_0011ED60(func_00243A20) == 0) {
        func_0011ED30(0x29811, func_00243A20);
    }
}

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

extern u8 D_00458560[];
extern u8 D_00459C50[];
extern u8 D_00459C68[];
extern u8 D_00459C78[];
extern u8 D_00459C98[];
s32 func_00244298();

void func_00244500(void) {
    s32 i;
    s32 j;
    u8 *p;
    memset(D_00656510, 0, 0x9620);
    func_00247668(D_00458560);
    for (i = 0; i < 3; i++) {
        p = (u8 *)D_00656510 + 0x10 + ((i << 13) + i * 0x1200);
        for (j = 0; j < 5; j++) {
            func_00247AE0(D_00459C50, p + 0x30, D_00458560);
            func_00247AE0(D_00459C68, p + 0x330, D_00458560);
            func_00247AE0(D_00459C78, p + 0x4B0, D_00458560);
            func_00247AE0(D_00459C98, p + 0x930, D_00458560);
            p += 0xA00;
        }
    }
    if (func_0011ED60(func_00244298) == 0) {
        func_0011ED30(0x29811, func_00244298);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244670);

typedef struct { s32 unk_00; char pad04[0xA00 - 4]; } A2Ent2_A00;
typedef struct { s32 count[4]; A2Ent2_A00 ent[3][5]; } A2Tbl_656510;
extern A2Tbl_656510 D_00656510_t __asm__("D_00656510");

s32 func_002448D8(void) {
    s32 i, j;
    A2Ent2_A00 *row;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < D_00656510_t.count[i]; j++) {
            row = D_00656510_t.ent[i];
            if (row[j].unk_00 != 0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_00244960(void) {

}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244968);

typedef struct { u8 b[0xC0]; } Mon132_C0a;
extern Mon132_C0a D_0065FD80_a[5][10] __asm__("D_0065FD80");
extern Mon132_C0a D_00662300_a[3] __asm__("D_00662300");
extern s32 D_00662540_w[] __asm__("D_00662540");
void func_00247A30(Mon132_C0a *);

void func_00244A10(s32 a0, s32 a1) {
    s32 *d = D_00662540_w;
    s32 i;
    s32 j;

    if (d[0] == 0) {
        d[1] = a1;
        d[0] = 1;
        d[5] = a0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                func_00247A30(&D_0065FD80_a[i][j]);
            }
        }
        for (i = 0; i < 3; i++) {
            func_00247A30(&D_00662300_a[i]);
        }
    } else {
        d[1] += a1;
    }
    d[2] = 0;
}

extern void* D_00662540;

void func_00244B00(void) {
    D_00662540 = NULL;
}

s32 func_00244B10(s32 n, s32 *d) {
    s32 i;
    s32 r = 5;

    d[0] = n / 10000;
    d[1] = n % 10000 / 1000;
    d[2] = n % 1000 / 100;
    d[3] = n % 100 / 10;
    d[4] = n % 10;
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            break;
        }
        r--;
    }
    return r;
}

extern u8 D_00426820[];
extern u8 D_004267F0[];
typedef struct { u8 b[0xC0]; } Mon132_C0;
extern Mon132_C0 D_0065FD80_m[5][10] __asm__("D_0065FD80");
extern Mon132_C0 D_00662300_m[3] __asm__("D_00662300");
void func_00244968(Mon132_C0 *, u8 *, s32, s32);

void func_00244BE0(s32 a0, s32 a1, s32 a2) {
    s32 x;
    s32 d[5];
    s32 k;
    s32 i;

    k = func_00244B10(a0, d);
    x = a1;
    for (i = 0; i < k; i++) {
        func_00244968(&D_0065FD80_m[i][d[5 - k + i]], D_00426820, x, a2);
        x += 0xD;
    }
    x += 2;
    func_00244968(&D_00662300_m[0], D_004267F0, x, a2);
    func_00244968(a0 < 2 ? &D_00662300_m[1] : &D_00662300_m[2], D_004267F0, x, a2);
}

typedef struct {
    u8 pad[0x60];
    s32 flags;
    u8 pad64[0x5C];
} A3Mon;
extern A3Mon D_0065FD80[5][10];
extern A3Mon D_00662300[3];
void func_00247108(A3Mon *);
void func_00247218(A3Mon *);
void func_00246C60(A3Mon *);
void func_00246C28(A3Mon *);
void func_00246E80(A3Mon *);
void func_00246FF0(A3Mon *);
void func_00247AA0_m(A3Mon *) __asm__("func_00247AA0");

void func_00244D00(s32 a0, s32 a1) {
    s32 i;
    s32 j;
    A3Mon *p;

    if (a0) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                func_00247108(&D_0065FD80[i][j]);
                func_00247218(&D_0065FD80[i][j]);
            }
        }
        p = D_00662300;
        for (i = 0; i < 3; i++, p++) {
            func_00247108(p);
            func_00247218(p);
        }
    }
    if (a1) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 10; j++) {
                if (D_0065FD80[i][j].flags & 2) {
                    func_00246C60(&D_0065FD80[i][j]);
                    func_00246C28(&D_0065FD80[i][j]);
                }
                if (D_0065FD80[i][j].flags & 0x40) {
                    func_00246E80(&D_0065FD80[i][j]);
                    func_00246FF0(&D_0065FD80[i][j]);
                }
            }
        }
        p = D_00662300;
        for (i = 0; i < 3; i++, p++) {
            if (p->flags & 2) {
                func_00246C60(p);
                func_00246C28(p);
            }
            if (p->flags & 0x40) {
                func_00246E80(p);
                func_00246FF0(p);
            }
        }
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            func_00247AA0_m(&D_0065FD80[i][j]);
        }
    }
    p = D_00662300;
    for (i = 0; i < 3; i++, p++) {
        func_00247AA0_m(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00244F28);

extern u64 D_0065FB30[];
extern u_long128 *D_0065FC90;
extern u_long128 *D_0065FC94;
void func_00244F28(void);

s32 func_00245090(void) {
    func_002370C8(D_0065FB30);
    D_0065FB30[0x1C] = 5;
    D_0065FB30[0xC] = 0x30003;
    D_0065FB30[0xE] = 0x8000000048;
    func_00237018(D_0065FB30, 0x16, 1);
    func_00244960();
    D_0065FC94 = (u_long128 *)&D_00351E10;
    D_0065FC90 = (u_long128 *)&D_00351E10 + 1;
    func_00244F28();
    func_00237018(D_0065FC94, D_0065FC90 - D_0065FC94, 1);
    return 0;
}

extern u8 D_00459D40[];
extern u8 D_0045B770[];
extern u8 D_0045B780[];
void func_00247AE0();

void func_00245148(void) {
    s32 i;
    memset(&D_00662540, 0, 0x18);
    func_00247668(D_00459D40);
    func_00247AE0(D_0045B770, D_00662300, D_00459D40);
    for (i = 0; i < 5; i++) {
        func_00247AE0(D_0045B780, D_0065FD80[i], D_00459D40);
    }
    if (func_0011ED60(func_00245090) == 0) {
        func_0011ED30(0x28489, func_00245090);
    }
}

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

extern u8 D_006626D0[];
extern s32 D_006626C0;
void func_002475E8(s32, u8 *, s32);
s32 func_002388B8(u8 *, s32, s32);
typedef struct { s32 a; s32 b; s32 c; s32 d; } V4_5300;
typedef struct { u8 pad[0x60]; V4_5300 m[4]; V4_5300 n[4]; } Obj5300;
extern Obj5300 D_006626D0_o __asm__("D_006626D0");

void func_00245300(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_006626D0_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_006626D0_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_006626D0_o.m[i].d = D_006626D0_o.m[i].d * f;
    }
    D_006626C0 = func_002388B8((u8 *)&D_006626D0_o, 1, D_006626C0);
}

extern s32 D_006627C8;
extern s32 D_006627D0;
extern s32 D_006627D8;
extern u8 D_00431D20[];
extern sceVu0FMATRIX D_002DEC20;
extern void *func_001315C0(s32, s32, f32 *, f32);
void func_00237A48(s32 *, sceVu0FMATRIX, f32 *, s32);
s32 func_00249580(f32 *);
void func_00249558(void *, void *);

void func_002453E8(s32 a0, f32 f) {
    sceVu0FVECTOR v;
    s32 w[4];
    Struct_006627B0 *s = &D_006627B0;
    s32 o = 0;

    switch (s->unk0) {
    case 0:
        o = D_006627C8;
        break;
    case 1:
        o = D_006627D0;
        break;
    case 2:
        o = D_006627D8;
        break;
    }
    if (a0 != 0) {
        func_002479A0(o);
    }
    func_00247AA0(o);
    func_001315C0(s->unk4, 0x8004, v, 0.0f);
    if (func_00249580(v) == 0) {
        func_00237A48(w, D_002DEC20, v, 1);
        func_00249558(w, w);
        w[1] -= 0x36;
        func_00245300(o, (s32)D_00431D20, w[0], w[1], f);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00245508);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002455C0);

extern u8 D_0045B7B0[];
extern u8 D_0045BC00[];
extern s32 D_006627C8;
extern s32 D_006627D0;
extern s32 D_006627D8;
void func_00247668();
void func_00247B60();
s32 func_0011ED60();
s32 func_002455C0();

void func_002456E8(void) {
    s32 buf[4];
    memset(&D_006627B0, 0, 0x18);
    D_006627B0.unk8 = 0;
    func_00247668(D_0045B7B0);
    func_00247B60(D_0045BC00, buf, D_0045B7B0);
    D_006627C8 = buf[2];
    D_006627D0 = buf[1];
    D_006627D8 = buf[0];
    if (func_0011ED60(func_002455C0) == 0) {
        func_0011ED30(0x28489, func_002455C0);
    }
}

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

extern s32 D_00662940;
extern Obj5300 D_00662950_o __asm__("D_00662950");

void func_00245920(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00662950_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00662950_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00662950_o.m[i].d = D_00662950_o.m[i].d * f;
    }
    D_00662940 = func_002388B8((u8 *)&D_00662950_o, 1, D_00662940);
}

s32 func_00245A08(s32 n, s32 *d) {
    s32 i;
    s32 r = 5;

    d[0] = n / 10000;
    d[1] = n % 10000 / 1000;
    d[2] = n % 1000 / 100;
    d[3] = n % 100 / 10;
    d[4] = n % 10;
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            break;
        }
        r--;
    }
    return r;
}

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

extern u8 D_0045BC10[];
extern u8 D_0045D240[];
extern u8 D_0045D248[];
void func_00247AE0();
s32 func_00245DA0();

void func_00245E40(void) {
    s32 i;
    u8 *p;
    func_00247668(D_0045BC10);
    p = D_00662A30;
    for (i = 0; i < 10; i++) {
        func_00247AE0(D_0045D240, p + 0x20, D_0045BC10);
        func_00247AE0(D_0045D248, p + 0xE0, D_0045BC10);
        p += 0x860;
    }
    if (func_0011ED60(func_00245DA0) == 0) {
        func_0011ED30(0x28489, func_00245DA0);
    }
}

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

extern s32 D_00667F50;
extern Obj5300 D_00667F60_o __asm__("D_00667F60");

void func_00246038(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00667F60_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00667F60_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00667F60_o.m[i].d = D_00667F60_o.m[i].d * f;
    }
    D_00667F50 = func_002388B8((u8 *)&D_00667F60_o, 1, D_00667F50);
}

extern u8 D_00668060[];
extern u8 D_00431D20[];
extern sceVu0FMATRIX D_002DEC20;
void func_00237A48(s32 *, sceVu0FMATRIX, f32 *, s32);
s32 func_00249580(f32 *);
void func_00249558(void *, void *);

void func_00246120(u8 *a0, s32 a1, f32 f) {
    sceVu0FVECTOR v;
    s32 w[4];
    s32 o = 0;

    if (*(s32 *)(a0 + 8) == 0) {
        o = (s32)D_00668060;
    }
    if (a1 != 0) {
        func_002479A0(o);
    }
    func_00247AA0(o);
    func_001315C0(*(s32 *)(a0 + 0xC), 0x8004, v, 0.0f);
    if (func_00249580(v) == 0) {
        func_00237A48(w, D_002DEC20, v, 1);
        func_00249558(w, w);
        w[1] -= 0x36;
        func_00246038(o, (s32)D_00431D20, w[0], w[1], f);
    }
}

extern u64 D_00667DF0[];
extern u_long128 *D_00667F50_p __asm__("D_00667F50");
extern u_long128 *D_00667F54;
s32 func_0013C2A8(s32);

void func_002461F8(u8 *a0, s32 a1, f32 f) {
    s32 r;
    s32 n;

    func_002370C8(D_00667DF0);
    D_00667DF0[0x1C] = 5;
    D_00667DF0[0xC] = 0x30003;
    func_00237018(D_00667DF0, 0x16, 1);
    D_00667F54 = (u_long128 *)&D_00351E10;
    D_00667F50_p = (u_long128 *)&D_00351E10 + 1;
    func_00246120(a0, a1, f);
    r = func_0013C2A8(*(u16 *)(*(u8 **)(*(u8 **)(a0 + 0xC) + 0x130) + 0x4C));
    if (r == 1) {
        n = 1;
    } else if (r == 2) {
        n = 2;
    }
    if (func_00242BF0(n) != 0) {
        func_00237018(D_00667F54, D_00667F50_p - D_00667F54, 1);
    }
}

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

extern s32 D_00668280;
extern Obj5300 D_00668290_o __asm__("D_00668290");

void func_00246570(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00668290_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00668290_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00668290_o.m[i].d = D_00668290_o.m[i].d * f;
    }
    D_00668280 = func_002388B8((u8 *)&D_00668290_o, 1, D_00668280);
}

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

extern u8 D_00668370_b[] __asm__("D_00668370");
extern u8 D_0045D6E0[];
extern u8 D_0045E190[];
extern u8 D_0045E198[];
extern u8 D_0045E1A0[];
extern u8 D_0045E1A8[];
extern u8 D_0045E1B8[];
extern u8 D_0045E1C0[];
extern u8 D_0045E1C8[];
extern u8 D_0045E1E0[];
s32 func_00246AA8();

void func_00246BC8(void) {
    memset(D_00668370_b, 0, 0xAB0);
    func_00247668(D_0045D6E0);
    func_00247AE0(D_0045E190, D_00668370_b + 0x20, D_0045D6E0);
    func_00247AE0(D_0045E198, D_00668370_b + 0xE0, D_0045D6E0);
    func_00247AE0(D_0045E1A0, D_00668370_b + 0x1A0, D_0045D6E0);
    func_00247AE0(D_0045E1A8, D_00668370_b + 0x260, D_0045D6E0);
    func_00247AE0(D_0045E1B8, D_00668370_b + 0x4A0, D_0045D6E0);
    func_00247AE0(D_0045E1C0, D_00668370_b + 0x560, D_0045D6E0);
    func_00247AE0(D_0045E1C8, D_00668370_b + 0x620, D_0045D6E0);
    func_00247AE0(D_0045E1E0, D_00668370_b + 0x9E0, D_0045D6E0);
    if (func_0011ED60(func_00246AA8) == 0) {
        func_0011ED30(0x28489, func_00246AA8);
    }
}

/* unused: layout only (notes/f1.md F1). Without it (or with 2 or 4) func_00247CC8 stops folding
 * `la $4,D_00431F30($4)`; 1 and 3 keep the file matching (25 Nov). */
extern s32 D_246CF0_layout1;
s32 func_00246CF0(s32 n, s32 *d) {
    s32 i;
    s32 r = 5;

    d[0] = n / 10000;
    d[1] = n % 10000 / 1000;
    d[2] = n % 1000 / 100;
    d[3] = n % 100 / 10;
    d[4] = n % 10;
    for (i = 0; i < 4; i++) {
        if (d[i] != 0) {
            break;
        }
        r--;
    }
    return r;
}

extern s32 D_00668F80;
extern Obj5300 D_00668F90_o __asm__("D_00668F90");

void func_00246DC0(s32 a0, s32 a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_00668F90_o, a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_00668F90_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_00668F90_o.m[i].d = D_00668F90_o.m[i].d * f;
    }
    D_00668F80 = func_002388B8((u8 *)&D_00668F90_o, 1, D_00668F80);
}

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

extern u8 D_0045E1F0[];
extern u8 D_0045FA80[];
extern u8 D_0045FA88[];
extern u8 D_0045FA90[];
extern u8 D_0045FAC0[];
s32 func_00247190();

void fm_func_00247258(void) {
    s32 i;
    u8 *p;
    func_00247668(D_0045E1F0);
    p = D_0045FAC0;
    for (i = 0; i < 10; i++) {
        func_00247AE0(D_0045FA80, p + 0x30, D_0045E1F0);
        func_00247AE0(D_0045FA88, p + 0xF0, D_0045E1F0);
        func_00247AE0(D_0045FA90, p + 0x1B0, D_0045E1F0);
        p += 0x930;
    }
    if (func_0011ED60(func_00247190) == 0) {
        func_0011ED30(0x28489, func_00247190);
    }
}

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

extern s32 D_006691D0;
extern Obj5300 D_006691E0_o __asm__("D_006691E0");

void func_002474E8(s32 a0, u8 *a1, s32 x, s32 y, f32 f) {
    s32 i;

    func_002475E8(a0, (u8 *)&D_006691E0_o, (s32)a1);
    for (i = 0; i < 4; i++) {
        s32 *e = &D_006691E0_o.n[i].b;
        e[-1] += x * 16;
        e[0] += y * 16;
    }
    for (i = 0; i < 4; i++) {
        D_006691E0_o.m[i].d = D_006691E0_o.m[i].d * f;
    }
    D_006691D0 = func_002388B8((u8 *)&D_006691E0_o, 1, D_006691D0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002475D0);

void func_00247678(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0 / 10;
    *arg2 = arg0 % 10;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_002476A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247930);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00247B50);

extern s32 D_00669390[];
extern u8 D_006692C0[];
extern void func_002474E8(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
extern void func_002476A0(void *arg0);
extern void func_00247930(void *arg0);

void func_00247BD0(void *arg0) {
    s32 *ptr = &D_00669390;
    s32 counter = 7;

    do {
        s32 val = *ptr;
        ptr++;
        counter--;
        func_002474E8(val, D_006692C0, *(s32 *)((u8 *)arg0 + 0x24), *(s32 *)((u8 *)arg0 + 0x28), 1.0f);
    } while (counter >= 0);

    func_002476A0(arg0);
    func_00247930(arg0);
}

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

typedef struct { u8 pad[8]; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Seg132_7CF8;
int sprintf(char *, const char *, ...);
void func_002475D0(s32 x, s32 y, u8 *col, f32 f, char *s, s32 font);
extern s32 D_00467408;
extern char D_004917D8[];
extern char D_004917F0[];
extern char D_004917F8[];
extern char D_00491800[];
extern char D_00491808[];

void func_00247CF8(Seg132_7CF8 *a0) {
    char buf[16];
    u8 col[3];

    col[0] = 0xFF;
    col[1] = 0xFF;
    col[2] = 0xFF;
    switch (a0->unkC) {
    case 1:
        sprintf(buf, D_004917F0, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x54, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_004917F0, a0->unk14);
            func_002475D0(0x61, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    case 2:
        sprintf(buf, D_004917D8, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x61, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_004917D8, a0->unk14);
            func_002475D0(0x6E, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    case 3:
        sprintf(buf, D_00491800, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x6E, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_00491800, a0->unk14);
            func_002475D0(0x7B, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    case 4:
        sprintf(buf, D_00491808, a0->unk10);
        func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
        if (a0->unk8 != 0) {
            sprintf(buf, D_004917F8);
            func_002475D0(0x7B, 0x16, col, 1.0f, buf, D_00467408);
            sprintf(buf, D_00491808, a0->unk14);
            func_002475D0(0x88, 0x16, col, 1.0f, buf, D_00467408);
        }
        break;
    }
}

extern char D_00491810[];
extern char D_00491818[];
extern s32 D_0046740C;

void func_00248010(Seg132_7CF8 *a0) {
    char buf[16];
    u8 col[3];
    s32 x;

    col[0] = 0xFF;
    col[1] = 0xFF;
    col[2] = 0xFF;
    sprintf(buf, D_00491810, *(s32 *)((u8 *)a0 + 0x1C));
    func_002475D0(0x45, 0x16, col, 1.0f, buf, D_00467408);
    x = 0x45;
    x += strlen(buf) * 13;
    sprintf(buf, D_00491818);
    func_002475D0(x + 2, 0x18, col, 1.0f, buf, D_0046740C);
}

extern u8 D_00669320[];
extern s32 D_00669388[];

void fm_func_002480D8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        func_002474E8(D_00669388[i], D_00669320, 0, 0, 1.0f);
    }
}

extern u_long128 *D_006691D0_p __asm__("D_006691D0");
extern u_long128 *D_006691D4;
void func_002393D8(void);
void func_00247B50(void *);
void fm_func_002480D8_a(void *) __asm__("fm_func_002480D8");

void func_00248140(u8 *a0) {
    u8 *s;

    D_006691D4 = (u_long128 *)&D_00351E10;
    D_006691D0_p = (u_long128 *)&D_00351E10 + 1;
    s = *(u8 **)(a0 + 4);
    func_002393D8();
    if (*(s32 *)(s + 0x20) != 0) {
        if (*(s32 *)(s + 0x30) == 0) {
            func_00247C50(s);
        } else if (*(s32 *)(s + 0x2C) == 0) {
            func_00247BD0(s);
        } else {
            func_00247B50(s);
        }
    }
    if (*(s32 *)(s + 4) != 0 || *(s32 *)(s + 0x18) != 0) {
        fm_func_002480D8_a(s);
    }
    if (*(s32 *)(s + 4) != 0) {
        func_00247CF8((Seg132_7CF8 *)s);
    }
    if (*(s32 *)(s + 0x18) != 0) {
        func_00248010((Seg132_7CF8 *)s);
    }
    func_00237018(D_006691D4, D_006691D0_p - D_006691D4, 1);
}

typedef struct {
    s32 a[8];
    s32 c[4][4];
} Seg132_6693F0;
extern Seg132_6693F0 D_006693F0;
extern u64 D_00669490;
extern u64 D_00491820;
extern u8 D_00431D50[][0x30];

void func_00248238(u8 *a0) {
    Seg132_7CF8 *s = *(Seg132_7CF8 **)(a0 + 4);
    s32 i;

    if (*(s32 *)((u8 *)s + 4) != 0 || *(s32 *)((u8 *)s + 0x18) != 0) {
        D_006691D4 = (u_long128 *)&D_00351E10;
        D_006691D0_p = (u_long128 *)&D_00351E10 + 1;
        func_00247CC8(*(s32 *)s);
        D_006693F0.a[0] = 0xC;
        D_006693F0.a[1] = 0xF;
        D_006693F0.a[2] = 0x40;
        D_006693F0.a[3] = 0x40;
        D_006693F0.a[4] = 0;
        D_006693F0.a[5] = 0;
        D_006693F0.a[6] = 0x3F;
        D_006693F0.a[7] = 0x3F;
        for (i = 0; i < 4; i++) {
            D_006693F0.c[i][0] = 0x80;
            D_006693F0.c[i][1] = 0x80;
            D_006693F0.c[i][2] = 0x80;
            D_006693F0.c[i][3] = 0x80;
        }
        D_00669490 = D_00491820;
        func_002474E8((s32)((u8 *)&D_00669490 - 0xA0), D_00431D50[*(s32 *)s], 0, 0, 1.0f);
        func_00237018(D_006691D4, D_006691D0_p - D_006691D4, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_132D60", func_00248380);

extern u8 D_00669350_b[] __asm__("D_00669350");
extern u8 D_00669358[];
extern u64 D_006692D8;
extern u64 D_00669308;
extern u64 D_00669338;
extern u8 D_004656A0[];
extern u8 D_00465FD0[];
extern u8 D_00466180[];
extern u8 D_004667B0[];
extern u8 D_00466DE0[];
extern u8 D_00467350[];
extern u8 D_00467388[];
extern u8 D_00467398[];
extern u8 D_004673C0[];
extern u8 D_004673E8[];
extern u8 D_006693B0[];
s32 func_00248380();

void func_00248400(void) {
    memset(D_00669350_b, 0, 8);
    func_00247668(D_004656A0);
    func_00247668(D_00465FD0);
    func_00247668(D_00466180);
    func_00247668(D_004667B0);
    func_00247668(D_00466DE0);
    func_00247B60(D_00467350, D_00669358, D_004656A0);
    func_00247B60(D_00467388, D_00669388, D_00465FD0);
    func_00247B60(D_00467398, D_00669390, D_00466180);
    func_00247B60(D_004673C0, D_006693B0, D_004667B0);
    func_00247B60(D_004673E8, D_006693D0, D_00466DE0);
    D_006692D8 = 0x0007400621413600;
    D_00669308 = 0x0207400621413600;
    D_00669338 = 0x0607400621413600;
    if (func_0011ED60(func_00248380) == 0) {
        func_0011ED30(0x28489, func_00248380);
    }
}

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

extern s32 D_00469C94;
extern s32 D_00469C98;
extern s32 D_00669610;

void func_002488A8(s32 x, s32 y, s32 a2, s32 a3, f32 f) {
    u8 col[4];
    u8 *a;

    if (a3 != 0) {
        col[0] = 0x73;
        col[1] = 0x73;
        col[2] = 0x73;
        a = &col[3];
        *a = f * 128.0f;
    } else {
        col[0] = 0xE6;
        col[1] = 0xE6;
        col[2] = 0xE6;
        a = &col[3];
        *a = f * 128.0f;
    }
    D_00669610 = func_001F0638_c(D_00669610, 1, *(s32 *)col, (((x + D_00469C94) * 16 + 0x7000) >> 4) - 0x700,
                                 (((y + D_00469C98) * 16 + 0x7400) >> 4) - 0x740, a2);
}

void func_002477A8(u8 *, s32 *);
void func_002488A8(s32, s32, s32, s32, f32);

void func_002489C8(s32 a0, u8 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f) {
    s32 buf[4];
    s32 i;
    u8 *q = a1;

    for (i = 0; i < 7; i++) {
        func_00248840(a0, (s32)a1, a2, a4, a5);
        a1 += 0xC0;
    }
    func_00248840(a0, (s32)a1, a3, a4, a5);
    if (a6 != 0) {
        func_002477A8(q, buf);
        func_002488A8(a4 + buf[0], a5 + buf[1], a6, a7, f);
    }
}

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

extern u8 D_00467410[];
extern u8 D_00468220[];
extern u8 D_00468E10[];
extern u8 D_00469C20[];
extern u8 D_00469C48[];
extern u8 D_00469C70[];
extern u8 D_00669760[];

void func_00248EA0(void) {
    memset(&D_00669700, 0, 0x60);
    func_00248628((u8 *)&D_00669700 + 0x14, 5, (s32)((u8 *)&D_00669700 + 0x24));
    D_00669700 = 0;
    func_00247668(D_00467410);
    func_00247668(D_00468220);
    func_00247668(D_00468E10);
    func_00247B60(D_00469C20, D_00669760, D_00467410);
    func_00247B60(D_00469C48, D_00669760 + 0x20, D_00468220);
    func_00247B60(D_00469C70, D_00669760 + 0x40, D_00468E10);
    if (func_0011ED60(func_00248E30) == 0) {
        func_0011ED30(0x29811, func_00248E30);
    }
}

extern u8 D_00669930[];
extern s32 D_00669920;
void func_002475E8(s32, u8*, s32);
s32 func_002388B8(u8*, s32, s32);
void func_00248FB8(s32 a0, s32 a1) {
    func_002475E8(a0, D_00669930, a1);
    D_00669920 = func_002388B8(D_00669930, 1, D_00669920);
}

extern u64 D_006697C0[];
extern u_long128 *D_00669924;
extern u_long128 *D_00669920_p __asm__("D_00669920");
extern s32 D_00669A10[];
extern u8 D_004267F0[];

void func_00249010(void) {
    s32 *p;
    s32 i;
    func_002370C8(D_006697C0);
    D_006697C0[0x1C] = 5;
    D_006697C0[0xC] = 0x30003;
    D_006697C0[0xE] = 0x8000000048;
    func_00237018(D_006697C0, 0x16, 1);
    D_00669924 = (u_long128 *)&D_00351E10;
    D_00669920_p = (u_long128 *)&D_00351E10 + 1;
    for (i = 0; i < 2; i++) {
        func_00248FB8(D_00669A10[i], (s32)D_004267F0);
    }
    func_00237018(D_00669924, D_00669920_p - D_00669924, 1);
}

s32 func_00246D60(s32);

void func_002490F0(void **a0) {
    s32 *st = (s32 *)a0;
    s32 i;

    switch (*st) {
    case 1:
        for (i = 0; i < 2; i++) {
            func_002479A0(D_00669A10[i]);
        }
        (*st)++;
        break;
    case 2:
        for (i = 0; i < 2; i++) {
            func_00247AA0(D_00669A10[i]);
        }
        if (func_00246D60(D_00669A10[0]) & 4) {
            (*st)++;
        }
        break;
    case 3:
        *st = 0;
        return;
    }
    func_00249010();
}

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
