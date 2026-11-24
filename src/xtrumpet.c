#include "common.h"

#include "xcursed.h"
#include "xhumungus.h"

typedef struct XTrumpet {
    /* 0x000 */ u8 unk_00[16];
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ s32 unk_14;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 unk_20;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ s32 unk_28;
    /* 0x02C */ s32 unk_2C;
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ s32 unk_3C;
    /* 0x040 */ s32 unk_40;
    /* 0x044 */ s32 unk_44;
    /* 0x048 */ s32 unk_48;
    /* 0x04C */ s32 unk_4C;
    /* 0x050 */ u8 unk_50[28];
    /* 0x06C */ u8 unk_6C[234];
    /* 0x156 */ // u16 unk_156; possibly unused space, unnecessary for match
    /* 0x158 */ s32 unk_158;
    /* 0x15C */ void* unk_15C;
} XTrumpet;

extern s32 D_002B8364;
extern s32 D_002B8678;

XTrumpet* D_002B90B0;

// XTrumpet's unk_10..unk_4C seen as four 16-byte float vectors
typedef struct {
    f32 x, y, z, w;
} XTrumpetVec;

extern s8 D_002BCB68[]; // FM address name; sizes (per group?) of XTrumpet.unk_6C

extern s32 D_002B916C;
extern s32 D_002B9170;
extern s32 D_002B9174;

extern s32 D_004D29D0;
extern s32 D_004D2998;
extern s32 D_004D29AC;
extern s32 D_004D29C4;

extern s32 D_002B8680;
extern s32 D_002B8684;
extern s32 D_002B92F8;

extern void* D_002E26A0[];

void func_00111158(void*, s32);
void func_00111198(void);
void func_00111210(s32);
void func_00111298(void);
void func_00111C98(s32, s32);

void func_001110A0(void) {
    D_002B90B0 = func_0022F768(3);
}

void func_001110D0(void) {
    s32 i;

    func_001110A0();
    for (i = 0; i < ARRAY_COUNT(D_002B90B0->unk_6C); i++) {
        D_002B90B0->unk_6C[i] = 0;
    }
    D_002B90B0->unk_40 = 0;
    D_002B90B0->unk_44 = 0;
    D_002B90B0->unk_10 = 0;
    D_002B90B0->unk_14 = 0;
    D_002B90B0->unk_18 = 0;
    D_002B90B0->unk_1C = 0;
    D_002B90B0->unk_20 = 0;
    D_002B90B0->unk_24 = 0;
    D_002B90B0->unk_28 = 0;
    D_002B90B0->unk_2C = 0;
    D_002B90B0->unk_30 = 0;
    D_002B90B0->unk_34 = 0;
    D_002B90B0->unk_38 = 0;
    D_002B90B0->unk_3C = 0;
    D_002B90B0->unk_158 = 0;
}

typedef struct { u8 pad[0x10]; f32 f[4][4]; } XTF;
void func_00111158(void* a_, s32 i) {
    u8* a = a_;
    ((XTF*)D_002B90B0)->f[i][0] = *(f32*)(a + 0x10);
    ((XTF*)D_002B90B0)->f[i][1] = *(f32*)(a + 0x14);
    ((XTF*)D_002B90B0)->f[i][2] = *(f32*)(a + 0x18);
    ((XTF*)D_002B90B0)->f[i][3] = *(f32*)(a + 0x3C);
}

void func_00111198(void) {
    void* p;

    func_00111298();
    p = D_002E26A0[0];
    if (p != NULL) {
        func_00111158(p, 0);
    }
    p = D_002E26A0[1];
    if (p != NULL) {
        func_00111158(p, 1);
    }
    p = D_002E26A0[2];
    if (p != NULL) {
        func_00111158(p, 2);
    }
}

// 64-byte entries (four vectors); entry vectors 2 and 3 go to XTrumpet vectors 1 and 2
typedef struct {
    /* 0x00 */ XTrumpetVec v[4];
} XTrumpetVecSet;

extern XTrumpetVecSet* D_002BCDA0;

// XTrumpet seen with its four vectors as an array
typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ XTrumpetVec vec[4];
} XTrumpetVecs;

void func_00111210(s32 index) {
    s32 i;

    if (D_002E26A0[0] != NULL) {
        func_00111158(D_002E26A0[0], 0);
    }
    for (i = 0; i < 2; i++) {
        ((XTrumpetVecs*)D_002B90B0)->vec[i + 1].x = D_002BCDA0[index].v[i + 2].x;
        ((XTrumpetVecs*)D_002B90B0)->vec[i + 1].y = D_002BCDA0[index].v[i + 2].y;
        ((XTrumpetVecs*)D_002B90B0)->vec[i + 1].z = D_002BCDA0[index].v[i + 2].z;
        ((XTrumpetVecs*)D_002B90B0)->vec[i + 1].w = D_002BCDA0[index].v[i + 2].w;
    }
}

// XTrumpet's unk_4C..unk_6B, copied from what func_0017F1C8 returns
typedef struct {
    /* 0x00 */ s32 w[8];
} XTrumpetUnk4C;

XTrumpetUnk4C* func_0017F1C8(void);

void func_00111298(void) {
    XTrumpet* t = D_002B90B0;

    t->unk_40 = D_002B8678;
    t->unk_44 = D_002B8680;
    t->unk_48 = D_002B92F8;
    *(XTrumpetUnk4C*)&t->unk_4C = *func_0017F1C8();
}

typedef struct {
    /* 0x0 */ s8 unk_0; // compared with D_002B8678
    /* 0x1 */ s8 unk_1; // compared with D_002B8680
    /* 0x2 */ s8 index; // for func_00111210
    /* 0x3 */ s8 pad;
} XTrumpetSel;

extern XTrumpetSel D_002BCB80[39];

void func_00111328(void) {
    s32 i;
    XTrumpetSel* p;

    func_00111298();
    for (i = 0; i < 39; i++) {
        p = &D_002BCB80[i];
        if (D_002B8678 == p->unk_0 && D_002B8680 == p->unk_1) {
            func_00111210(p->index);
            return;
        }
    }
    func_00111198();
}

void func_001113A8(s32 index, f32* out) {
    out[0] = ((XTrumpetVec*)&D_002B90B0->unk_10 + index)->x;
    out[1] = ((XTrumpetVec*)&D_002B90B0->unk_10 + index)->y;
    out[2] = ((XTrumpetVec*)&D_002B90B0->unk_10 + index)->z;
    out[3] = ((XTrumpetVec*)&D_002B90B0->unk_10 + index)->w;
}

void func_001113E8(void) {
    func_001809C8(&D_002B90B0->unk_4C);
}

void func_00111408(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 ofs;

    if (arg0 == 20) {
        return;
    }
    ofs = 0;
    for (i = 0; i < arg0; i++) {
        ofs += D_002BCB68[i];
    }
    D_002B90B0->unk_6C[ofs + arg1] = arg2;
}

s8 func_00111468(s32 arg0, s32 arg1) {
    s32 i;
    s32 ofs = 0;

    for (i = 0; i < arg0; i++) {
        ofs += D_002BCB68[i];
    }
    return D_002B90B0->unk_6C[ofs + arg1];
}

extern s32 D_002BBD90[];
extern u8* D_002BBD48[];

// D_002BBD48[group]: u8 count, count keys, then rows of count chars ('#' = skip, 'a'.. = value)
void func_001114B8(s32 group, s32 row) {
    u8* tbl;
    u8* keys;
    u8* vals;
    s32 i;

    if (D_002BBD90[group] == 0) {
        return;
    }
    tbl = D_002BBD48[group];
    keys = tbl + 2;
    vals = keys + tbl[1] * (row + 1);
    for (i = 0; i < tbl[1]; i++) {
        if (vals[i] != '#') {
            func_00111408(group, keys[i] - 1, (u8)(vals[i] - 'a'));
        }
    }
}

void func_00111580(s32 param1) {
    func_001114B8(D_002B8678, param1);
}

void* func_001115A0(void) {
    if (D_002B90B0 != 0) {
        return D_002B90B0->unk_15C;
    }
    return NULL;
}

void func_001115C0(void) {
    if (D_002B90B0 != 0) {
        D_002B90B0->unk_15C++;
    }
}

void func_001115E8(void) {
    D_002B8364 = 0;
    func_0022F578(-1);
    func_001EF840();
    func_001601A8();
    func_0013CB18();
    func_001EBEB0();
    func_001BC048();
    func_001110D0();
}

void func_00111638(void) {
    s32 value;

    D_002B8364 = 1;
    D_002B8678 = D_002B90B0->unk_40;
    D_002B8680 = D_002B90B0->unk_44;
    value = func_00111468(D_002B8678, D_002B8680);
    D_002B8684 = value;
    D_002B92F8 = D_002B90B0->unk_48;
}

void func_001116A8(void) {
    D_004D2998 = 0;
}

void func_001116B8(void) {
    D_004D2998 = 1;
}

void func_001116C8(void) {
    if (D_004D2998 == 0) {
        func_0022F808();
    }
}

void func_001116F8(void) {
    s32 iVar1 = func_0013C2A8(3);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 8;
    }
    iVar1 = func_0013C2A8(5);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x20;
    }
    iVar1 = func_0013C2A8(6);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x40;
    }
    iVar1 = func_0013C2A8(7);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x80;
    }
    iVar1 = func_0013C2A8(8);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x100;
    }
    iVar1 = func_0013C2A8(9);
    if (iVar1 != -1) {
        D_002B90B0->unk_158 |= 0x200;
    }
}

void func_001117D8(void) {
  switch (D_002B8678) {
  case 5:
    if (D_002B90B0->unk_158 & 8) {
      func_0013C768(3);
    }
    break;
  case 8:
    if (D_002B90B0->unk_158 & 0x20) {
      func_0013C768(5);
    }
    break;
  case 9:
    if (D_002B90B0->unk_158 & 0x40) {
      func_0013C768(6);
    }
    break;
  case 10:
    if (D_002B90B0->unk_158 & 0x80) {
      func_0013C768(7);
    }
    break;
  case 0xd:
    if (D_002B90B0->unk_158 & 0x100) {
      func_0013C768(8);
    }
    break;
  case 0xf:
    if (D_002B90B0->unk_158 & 0x200) {
      func_0013C768(9);
    }
  }
}

#ifdef VERSION_FM
u32 fm_func_00111B08(arg0)
u32 arg0;
{
    return arg0;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111B10(void) {
    return fm_func_00111B08() / 216000;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111B48(void) {
    u32 t = fm_func_00111B08();
    u32 hours = t / 216000;
    u32 rest = t % 216000;

    return rest / 3600;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111B90(void) {
    u32 t = fm_func_00111B08();
    u32 hours = t / 216000;
    u32 rest = t % 216000;
    u32 minutes = rest / 3600;

    rest = rest % 3600;
    return rest / 60;
}
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xtrumpet", fm_func_00111BE8);
#endif

void func_00111910(void) {
    D_002B9174 = 0;
}

extern volatile s32 D_002BBDF0;
extern s32 D_004D9250;
extern s32 D_004D9254;
extern f32 D_002BBDEC;

// timer task: counts D_002B916C up to D_004D9254 from the elapsed time (D_002BBDEC per tick)
s32 func_00111920(void) {
    switch (D_004D29AC) {
    case 1:
        return 0;
    case 2:
        return 4;
    case 0:
        if (D_002B916C < D_004D9254) {
            D_002B916C = (u32)(D_002BBDF0 - D_004D9250) * D_002BBDEC;
            return 0;
        }
        D_002B916C = D_004D9254;
        return 4;
    }
    return 0;
}

extern volatile s32 D_002BBDF0;
extern s32 D_004D9250;
extern s32 D_004D9254;

void func_00111A00(s32 arg0) {
    D_004D29AC = 0;
    D_004D9250 = D_002BBDF0;
    D_002B916C = 0;
    if (arg0 == 0) {
        D_004D9254 = 0x34B84;
    } else {
        D_004D9254 = 0x14996C4;
    }
    func_0011ED30(0x2C04C, func_00111920);
}

extern void (*D_004D9258)(void);

// timer task: counts D_002B916C down from D_004D9254; at zero it calls D_004D9258
s32 func_00111A70(void) {
    switch (D_004D29AC) {
    case 1:
        return 0;
    case 2:
        return 4;
    case 0:
        if (D_002B916C > 0) {
            D_002B916C = D_004D9254 - (u32)(D_002BBDF0 - D_004D9250) * D_002BBDEC;
            return 0;
        }
        D_002B916C = 0;
        D_004D9258();
        return 4;
    }
    return 0;
}

// starts the countdown timer task (func_00111A70): sec seconds, then cb
void func_00111B70(s32 sec, void (*cb)(void)) {
    D_004D9258 = cb;
    D_004D29AC = 0;
    D_004D9250 = D_002BBDF0;
    D_002B916C = D_004D9254 = sec * 60;
    func_0011ED30(0x2C04C, func_00111A70);
}

void func_00111BD8(void) {
    D_004D29AC = 1;
    D_002B9174 = 1;
}

void func_00111BF0(void) {
    D_004D29AC = 0;
    D_002B9174 = 0;
}

s32 func_00111C08(void) {
    D_004D29AC = 2;
    return D_002B916C;
}

void func_00111C20(s32 param1) {
    D_002B916C = param1 * 60;
}

void func_00111C38(s32 param1) {
    D_004D29C4 = param1;
    D_002B9170 = 0;
}

void func_00111C50(s32 param1) {
    D_002B9170 = param1;
}

s32 func_00111C60(s32 param1) {
    s32 result;

    D_002B9170 += param1;
    if (D_004D29C4 == 0 || D_002B9170 < D_004D29C4) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u8 unk_20[0x14];
    /* 0x34 */ s32 time[2][4]; // fm_func_00111BE8, seconds, minutes, hours
} XTrumpetUnk9288;

extern XTrumpetUnk9288 D_004D9288;

#ifdef VERSION_FM
u32 fm_func_00111BE8(u32);

// splits a frame count into hours/minutes/seconds/hundredths (the fm_func_00111B08 helpers take it in a0)
void func_00111C98(s32 which, s32 t) {
    u32 hours, minutes, seconds, fraction;

    if (t < 0) {
        t = 0;
    }
    hours = ((u32 (*)(s32))fm_func_00111B10)(t);
    minutes = ((u32 (*)(s32))fm_func_00111B48)(t);
    seconds = ((u32 (*)(s32))fm_func_00111B90)(t);
    fraction = fm_func_00111BE8(t);
    if (which == 0) {
        D_004D9288.time[0][0] = fraction;
        D_004D9288.time[0][1] = seconds;
        D_004D9288.time[0][2] = minutes;
        D_004D9288.time[0][3] = hours;
    } else {
        D_004D9288.time[1][0] = fraction;
        D_004D9288.time[1][1] = seconds;
        D_004D9288.time[1][2] = minutes;
        D_004D9288.time[1][3] = hours;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111C98);
#endif


extern s32 D_004D9260;

s32 func_00111D98(void) {
    func_00111C98(0, D_002B916C);
    func_00111C98(1, D_004D9260);
    if (D_002B9170 < 0) {
        D_002B9170 = 0;
    }
    if (D_004D29C4 < 0) {
        D_004D29C4 = 0;
    }
    D_004D9288.unk_10 = D_002B9170;
    D_004D9288.unk_14 = D_004D29C4;
    D_004D9288.unk_1C = D_002B9170;
    return D_004D29D0 ? 4 : 0;
}

typedef struct { s32 a0; s32 a3; s32 a9; s32 a6; s32 u10; s32 u14; s32 a5; s32 u1C; s32 a1; s32 a8; s32 u28; s32 a7; s32 a2; } XT9288v;
extern XT9288v D_004D9288_v __asm__("D_004D9288");
#define D D_004D9288_v
void func_002485B8(s32);
void func_00111E20(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9) {
    D.a0 = a0;
    D.a1 = a1;
    D_004D9260 = a4;
    D.a2 = a2;
    D.a3 = a3;
    D.a5 = a5;
    D.a6 = a6;
    D.a9 = a9;
    D.a8 = a8;
    D.u1C = D_002B9170;
    D.u28 = 0;
    func_00111C98(0, D_002B916C);
    func_00111C98(1, D_004D9260);
    D.a7 = a7;
    D.u10 = D_002B9170;
    D.u14 = D_004D29C4;
    func_002485B8((s32)&D);
    D_004D29D0 = 0;
    func_0011ED30(0x280A0, func_00111D98);
}
#undef D

void func_00111F00(void) {
    D_004D29D0 = 1;
    func_00245130();
    func_00245140();
}

// The following unused functions might be part of worldfile.c?

#ifndef VERSION_FM
void func_00111F28(void) {
}
#endif

void func_00111F30(void) {
}

void func_00111F38(void) {
}
