#include "common.h"
#include "common_funcs.h"

#include "xlamp.h"
#include "xpeanut.h"

#include "gcc/stdio.h"
#include "eekernel.h"
#include "libvu0.h"

typedef struct XAppleStemTip {
    /* 0x00 */ char unk_00[0x48];
    /* 0x48 */ s32 unk_48;
} XAppleStemTip;

typedef struct XAppleStem {
    /* 0x00 */ s32 unk_00[0x6C / 4];
    /* 0x6C */ XAppleStemTip* unk_6C;
} XAppleStem;

typedef struct AppleWormInner {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[0x7];
} AppleWormInner;

typedef struct AppleWorm {
    /* 0x00 */ char unk_00[0x98];
    /* 0x98 */ AppleWormInner unk_98[2];
} AppleWorm;

typedef struct XApple4 {
    /* 0x00 */ s32 unk_00[4];
} XApple4;

typedef union X32 {
    s32 s32;
    u8 u8[4];
} X32;

typedef struct XAppleBlemish {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ X32 unk_04;
    /* 0x008 */ char unk_08[0x8];
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ char unk_14[0x28];
    /* 0x03C */ f32 unk_3C;
    /* 0x040 */ char unk_40[0x90];
    /* 0x0D0 */ sceVu0FMATRIX unk_D0;
    /* 0x110 */ char unk_110[0x10];
    /* 0x120 */ sceVu0FVECTOR unk_120;
    /* 0x134 */ char unk_130[0x240];
    /* 0x370 */ u64 unk_370;
    /* 0x374 */ char unk_378[0xCC];
    /* 0x444 */ s32 unk_444;
} XAppleBlemish;

typedef struct LargeApple {
    /* 0x00 */ char unk_00[0x30];
    /* 0x30 */ f32 unk_30[3];
    /* 0x3C */ f32 unk_3C;
} LargeApple;

typedef struct OtherApple {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ char unk_02[0xE];
    /* 0x10 */ f32 unk_10;
} OtherApple;

typedef struct AppleCore {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ s32 (*unk_04)();
} AppleCore;

s32 func_001009A8();
void* func_00122AF8(s32, s32, s32);
s32 func_00122B70(void*);
extern f32 D_002B8340[];
extern LargeApple* D_00532504;

// funcs
s32 func_0011EF58(s32*, s32);
f32 func_00120A38(sceVu0FVECTOR);
f32 func_00120A58(f32*);
f32 func_00120AC8(f32);
XAppleBlemish* func_001234A0(XAppleBlemish*);
void func_00123830(XAppleBlemish*, s32);
void func_00123E48(s32, sceVu0FVECTOR);
void func_00124BC8(XAppleBlemish*);
void func_00130248(XAppleBlemish*, f32, UNK_PTR);
void func_001313A8(XAppleBlemish*, UNK_PTR);
void func_00131410(XAppleBlemish*);
s32 func_00132160(s32, s32, s32);
void func_001372F8(f32, XAppleBlemish*);
void func_00137348(XAppleBlemish*);
void func_0013A790(void);
s32 func_0013AFE8(void);
s32 func_0013B368(void);
s32 func_0013B6E0(void);
s32 func_0013B890(void);
s32 func_0013B1D0(void);
void func_0013B578(void);
s32 func_0013BD88(s32*, AppleCore*, s32);
s32 func_0013BDA0(s32*);
s32 func_00141668(XAppleBlemish*, s32);
void func_00157AD8(s32);
s32 func_00157B90(void);
void func_00163638(sceVu0FMATRIX, sceVu0FMATRIX);
void func_00177828(s32);
void func_001778A0(s32);
void func_001778B8(s32);
f32 func_00177D68(void);
void func_001C64E0(UNK_PTR, UNK_PTR, UNK_PTR);
s32 func_001EE090(void);

// ???
extern s32 func_F20000(s32, s32);

// .data
extern f32 D_002B8340[];
extern s32 D_002C1E00;
extern sceVu0FMATRIX D_002C1E20;
extern u32 D_002C1EA8;
extern u32 D_002C1EC8;
extern XAppleStem* D_002DEC00;
extern u32 D_002DED20;

char* D_00301010[8] = {
    "xs_dumbo", "xs_bambi", "xs_genie", "xs_tink", "xs_mushu", "xs_simba",
};
sceVu0FVECTOR D_00301030 = {0.0f, -120.0f, -70.0f, 1.0f};
sceVu0FVECTOR D_00301040 = {0.0f, -100.0f, -20.0f, 1.0f};
char* D_00301050 = ".dbt";
char* D_00301054 = ".x";
AppleCore D_00301058[4] = {
    {60.0f, func_0013AFE8},
    {30.0f, func_0013B368},
    {60.0f, func_0013B6E0},
    {0.0f, func_0013B890},
};
char* D_00301078; // = ".dat";

extern s32 D_00301080;
extern s32 D_00301088;
extern f32 D_0030108C;
extern f32 D_00301090;
extern s32 D_00301094;
extern AppleWorm* D_003051EC;
extern u32 D_00375BC0;

// .rodata

// .bss ?
extern f32 D_005324B4;
extern f32 D_005324B8;
extern f32 D_005324BC;
extern sceVu0FVECTOR D_005324C0;
extern sceVu0FVECTOR D_005324D0;
extern sceVu0FVECTOR D_005324E0;
extern sceVu0FVECTOR D_005324F0;
extern f32 D_00532500;
extern s32 D_00532508;
extern s32 D_00532518;
extern s32 D_00532528;
extern XAppleBlemish* D_005325E8;
extern XAppleBlemish* D_005325EC;
extern sceVu0FVECTOR D_005325F0;
extern s32 D_00532600;
extern s32 D_00532604;
extern XApple4* D_00532608;
extern s32* D_0053260C;
extern s32 D_00532610;

#ifdef VERSION_FM
extern f32 D_0052AD04;
extern f32 D_0052AD08;
extern f32 D_0052AD0C;
extern sceVu0FVECTOR D_0052AD10;
extern sceVu0FVECTOR D_0052AD20;
extern sceVu0FVECTOR D_0052AD30;
extern sceVu0FVECTOR D_0052AD40;
extern f32 D_0052AD50;
extern f32 D_002B8344;
void func_001625C8(sceVu0FMATRIX, sceVu0FMATRIX);

s32 func_0013AB68(u16* arg0) {
    sceVu0FVECTOR sp0;
    sceVu0FVECTOR sp10;
    sceVu0FMATRIX sp20;
    sceVu0FMATRIX sp60;

    f32 var_f21;
    f32 ry;
    f32 s;
    f32 fVar1;
    f32 fVar2;

    if (((D_002C1EA8 >> 20) & 1) == 0) {
        return 4;
    }

    if (*arg0 & 0x10) {
        func_001625C8(D_005325E8->unk_D0, sp60);
        D_002DECF0[3] = 1.0f;
        D_002DECE0[3] = 1.0f;
        sceVu0ApplyMatrix(D_0052AD20, sp60, D_002DECE0);
        sceVu0ApplyMatrix(D_0052AD30, sp60, D_002DECF0);
        sceVu0SubVector(D_0052AD10, D_00301040, D_0052AD20);
        D_0052AD08 = func_00120A38(D_0052AD10);
        sceVu0SubVector(D_0052AD10, D_0052AD30, D_0052AD20);
        sceVu0Normalize(D_0052AD10, D_0052AD10);
        sceVu0ScaleVector(D_0052AD10, D_0052AD10, D_0052AD08);
        sceVu0AddVector(D_0052AD30, D_0052AD10, D_0052AD20);
        sceVu0SubVector(D_0052AD40, D_0052AD20, D_0052AD30);
        D_0052AD40[1] = 0.0f;
        func_001223B0(D_0052AD40, D_0052AD40);
        D_0052AD08 = D_0052AD40[3];
        D_0052AD40[3] = 1.0f;
        sceVu0SubVector(D_0052AD10, D_00301030, D_00301040);
        D_0052AD0C = func_00120A58(D_0052AD10) - D_0052AD08;

        fVar1 = atan2f(D_0052AD20[0] - D_0052AD30[0], D_0052AD20[2] - D_0052AD30[2]);
        fVar2 = atan2f(D_00301030[0] - D_00301040[0], D_00301030[2] - D_00301040[2]);
        D_0052AD04 = func_00120AC8(fVar2 - fVar1);

        if (func_00177D68() < 0.5f) {
            if (D_0052AD04 < 0.0f) {
                D_0052AD04 += 2 * PI;
            } else {
                D_0052AD04 -= 2 * PI;
            }
        }
        if (func_00177D68() < 0.5f) {
            D_0052AD04 += 0.5235987306f;
        } else {
            D_0052AD04 -= 0.5235987306f;
        }
        D_0052AD50 = 40.0f;
    }

    D_0052AD50 -= D_002B8344;
    var_f21 = D_0052AD50 / 40.0f;
    if (var_f21 < 0.0f) {
        var_f21 = 0.0f;
    }

    var_f21 = (cosf(var_f21 * PI) + 1.0f) * 0.5f;
    sceVu0InterVector(sp10, D_00301040, D_0052AD30, var_f21);
    ry = func_00120AC8(D_0052AD04 * var_f21);
    sceVu0RotMatrixY(sp20, D_002C1E20, ry);
    sceVu0ApplyMatrix(D_0052AD10, sp20, D_0052AD40);
    s = D_0052AD08 + D_0052AD0C * var_f21;
    sceVu0ScaleVector(D_0052AD10, D_0052AD10, s);
    sceVu0AddVector(sp0, sp10, D_0052AD10);
    sp0[3] = 1.0f;
    sp10[3] = 1.0f;
    sp0[1] = (D_00301030[1] * var_f21) + (D_0052AD20[1] * (1.0f - var_f21));
    sceVu0ApplyMatrix(D_002DECE0, D_005325E8->unk_D0, sp0);
    sceVu0ApplyMatrix(D_002DECF0, D_005325E8->unk_D0, sp10);
    return 0;
}
#else
s32 func_0013AB68(u16* arg0) {
    sceVu0FVECTOR sp0;
    sceVu0FVECTOR sp10;
    sceVu0FMATRIX sp20;
    sceVu0FMATRIX sp60;

    f32 var_f21;
    f32 ry;
    f32 s;
    f32 fVar1;
    f32 fVar2;

    if (((D_002C1EA8 >> 20) & 1) == 0) {
        return 4;
    }

    if (*arg0 & 0x10) {
        func_00163638(D_005325E8->unk_D0, sp60);
        D_002DECF0[3] = 1.0f;
        D_002DECE0[3] = 1.0f;
        sceVu0ApplyMatrix(D_005324D0, sp60, D_002DECE0);
        sceVu0ApplyMatrix(D_005324E0, sp60, D_002DECF0);
        sceVu0SubVector(D_005324C0, D_00301040, D_005324D0);
        D_005324B8 = func_00120A38(D_005324C0);
        sceVu0SubVector(D_005324C0, D_005324E0, D_005324D0);
        sceVu0Normalize(D_005324C0, D_005324C0);
        sceVu0ScaleVector(D_005324C0, D_005324C0, D_005324B8);
        sceVu0AddVector(D_005324E0, D_005324C0, D_005324D0);
        sceVu0SubVector(D_005324F0, D_005324D0, D_005324E0);
        D_005324F0[1] = 0.0f;
        func_001223B0(D_005324F0, D_005324F0);
        D_005324B8 = D_005324F0[3];
        D_005324F0[3] = 1.0f;
        sceVu0SubVector(D_005324C0, D_00301030, D_00301040);
        D_005324BC = func_00120A58(D_005324C0) - D_005324B8;

        fVar1 = atan2f(D_005324D0[0] - D_005324E0[0], D_005324D0[2] - D_005324E0[2]);
        fVar2 = atan2f(D_00301030[0] - D_00301040[0], D_00301030[2] - D_00301040[2]);
        D_005324B4 = func_00120AC8(fVar2 - fVar1);

        if (func_00177D68() < 0.5f) {
            if (D_005324B4 < 0.0f) {
                D_005324B4 += 2 * PI;
            } else {
                D_005324B4 -= 2 * PI;
            }
        }
        if (func_00177D68() < 0.5f) {
            D_005324B4 += PI / 6;
        } else {
            D_005324B4 -= PI / 6;
        }
        D_00532500 = 40.0f;
    }

    D_00532500 -= D_002B8340[1];
    var_f21 = D_00532500 / 40.0f;
    if (var_f21 < 0.0f) {
        var_f21 = 0.0f;
    }

    var_f21 = (cosf(var_f21 * PI) + 1.0f) * 0.5f;
    sceVu0InterVector(sp10, D_00301040, D_005324E0, var_f21);
    ry = func_00120AC8(D_005324B4 * var_f21);
    sceVu0RotMatrixY(sp20, D_002C1E20, ry);
    sceVu0ApplyMatrix(D_005324C0, sp20, D_005324F0);
    s = D_005324B8 + D_005324BC * var_f21;
    sceVu0ScaleVector(D_005324C0, D_005324C0, s);
    sceVu0AddVector(sp0, sp10, D_005324C0);
    sp0[3] = 1.0f;
    sp10[3] = 1.0f;
    sp0[1] = (D_00301030[1] * var_f21) + (D_005324D0[1] * (1.0f - var_f21));
    sceVu0ApplyMatrix(D_002DECE0, D_005325E8->unk_D0, sp0);
    sceVu0ApplyMatrix(D_002DECF0, D_005325E8->unk_D0, sp10);
    return 0;
}
#endif

#ifdef VERSION_FM
extern s32 D_0052AE60;
extern s32 D_00350CE0;
extern XAppleStem D_002E26A0;
s32 func_0014F658(XAppleBlemish*, s32);
void func_00130340(XAppleBlemish*, f32, UNK_PTR);
void func_001373F8(XAppleBlemish*, f32);
s32 func_00148768(s32, s32, XAppleBlemish*, s32, f32);
void func_001336D8(void);
void func_0023E0B0(s32, s32);
void func_001452E0(s32, s32);
s32 func_0011EEB8(s32*, s32, void*);
s32 func_0013AB30();

s32 func_0013AFE8(void) {
    register s32* q asm("$16") = &D_0052AE60; /* only way found to get $16/$17 as in the original */
    s32 i;

    func_0014F658(D_005325E8, 0x28);
    func_00130340(D_005325E8, 20.0f, (UNK_PTR)0x1010040);
    func_001373F8(D_005325E8, 0.0f);
    D_005325E8->unk_00 |= 0x200000;
    *q = func_00148768(D_00350CE0, 0, D_005325E8, 0x1C, 0.5f);
    func_00125088(53.0f);
    func_001336D8();
    func_0023E0B0(0, 3);
    func_0023E0B0(1, 3);
    func_0023E0B0(2, 3);
    func_001452E0(1, 4);
    for (i = 1; i < 3; i++) {
        if (D_002E26A0.unk_00[i] != 0) {
            *(s32*)D_002E26A0.unk_00[i] |= 0x1000000;
        }
    }
    func_0011EEB8(&D_00532518, 0, func_0013AB30);
    func_0011ED30(100000, func_0013AB68);
    return 1;
}

#else
INCLUDE_ASM("asm/nonmatchings/xapple", func_0013AFE8);
#endif

void func_0013B138(void) {
    if (D_0053260C[2] - D_0053260C[1] > 0) {
        func_001560C8((s32)D_0053260C + D_0053260C[1]);
    }
    if (D_0053260C[3] - D_0053260C[2] > 0) {
        func_001560C8((s32)D_0053260C + D_0053260C[2]);
    }
    if (D_0053260C[4] - D_0053260C[3] > 0) {
        func_00177908((s32)D_0053260C + D_0053260C[3]);
    }
    FlushCache(INVALIDATE_ICACHE);
    D_00532604 = 4;
}

#ifdef VERSION_FM
extern sceVu0FVECTOR D_0052AE40;
extern s32 D_0052AE60;
extern sceVu0FVECTOR D_002C58B0;
void func_001373F8(XAppleBlemish*, f32);
void func_00137448(XAppleBlemish*);
void func_00176310(s32);
void func_001763A0(s32);
void func_00131498(XAppleBlemish*, s32);
void func_001C4D90(s32, s32, s32);

s32 func_0013B1D0(void) {
    XAppleBlemish* var_17;
    s32 var_16;

    var_17 = NULL;
    while ((var_17 = func_001234A0(var_17)) != NULL) {
        var_16 = var_17->unk_00;
        if (var_17 == D_005325E8) {
            var_16 |= 0x30;
            var_16 &= ~0x2;
            func_001373F8(var_17, 0.0f);
            var_17->unk_370 |= 0x10000000000000;
        } else {
            var_16 &= ~0x8000;
            func_00137448(var_17);
            sceVu0CopyVector(var_17->unk_120, D_002C58B0);
        }
        func_00123830(var_17, var_16);
    }
    sceVu0CopyVector(D_0052AE40, &D_005325E8->unk_10);
    D_0052AE40[3] = D_005325E8->unk_3C;
    func_00123E48(D_005325E8->unk_04.s32, D_002C58B0);
    func_00176310(D_0052AE60);
    func_001763A0(0);
    func_001778A0(1);
    D_002C1EA8 &= ~0x100000;
    D_002C1EA8 |= 0x4000;
    if (((s32)((D_002C1EC8 >> 8) % 4) < 2) && (D_00532608[1].unk_00[1] != D_00532608[1].unk_00[0])) {
        func_00131498(D_005325E8, (s32)D_00532608 + D_00532608->unk_00[3]);
        func_001C4D90((s32)D_00532608 + D_00532608[1].unk_00[0], (s32)D_00532608 + D_00532608[1].unk_00[1],
                      (s32)D_00532608 + D_00532608[1].unk_00[2]);
    }
    return 4;
}

#else
INCLUDE_ASM("asm/nonmatchings/xapple", func_0013B1D0);
#endif

// s32 func_0013B1D0(void) {
//     XAppleBlemish* var_17;
//     s32 var_16;

//     var_17 = NULL;
//     do {
//         var_17 = func_001234A0(var_17);
//         if (var_17 == NULL) {
//             break;
//         }

//         if (var_17 == D_005325E8) {
//             var_16 = var_17->unk_00 | 0x30;
//             var_16 &= ~0x2;
//             func_001372F8(0.0f, var_17);
//             var_17->unk_370 |= 0x10000000000000;
//         } else {
//             var_16 = var_17->unk_00 & ~0x8000;
//             func_00137348(var_17);
//             sceVu0CopyVector(var_17->unk_120, D_002C1E00 + 0x1E00);
//         }
//         func_00123830(var_17, var_16);

//     } while (TRUE);

//     sceVu0CopyVector(D_005325F0, &D_005325E8->unk_10);
//     D_005325F0[3] = D_005325E8->unk_3C;
//     func_00123E48(D_005325E8->unk_04.s32, D_002C1E00);
//     func_00177828(D_00532610);
//     func_001778B8(0);
//     func_001778A0(1);
//     D_002C1EA8 &= ~0x100000;
//     D_002C1EA8 |= 0x4000;
//     if (((s32)((D_002C1EC8 >> 8) % 4) < 2) && (D_00532608[1].unk_00[1] != D_00532608[1].unk_00[0])) {
//         func_001313A8(D_005325E8, (s32)D_00532608 + D_00532608->unk_00[3]);
//         func_001C64E0((s32)D_00532608 + D_00532608[1].unk_00[0], (s32)D_00532608 + D_00532608[1].unk_00[1],
//         (s32)D_00532608 + D_00532608[1].unk_00[2]);
//     }
//     return 4;
// }

s32 func_0013B368(void) {
    char something[0x20];

    if (D_00532604 != 2 || (func_001EE090() != 0)) {
        return 0;
    }
    func_00157B90();
    D_00532604 = 3;
    sprintf(something, "%s%s", D_00301010[D_00532600], D_00301050);
    func_00120590(something, D_0053260C, NULL, 0);
    sprintf(something, "%s%s", D_00301010[D_00532600], D_00301054);
    func_00120590(something, &func_F20000, &func_0013B138, 0);
    func_0011ED30(47000, &func_0013B1D0);
    return 1;
}

#ifdef VERSION_FM
typedef union {
    LargeApple* p;
    f32 f;
} XAppleLU;
extern XAppleLU D_0052AD54;
extern f32 D_002B8344;

s32 func_0013B480(OtherApple* arg0) {
    f32 temp_f2;

    if (arg0->unk_00 & 0x10) {
        D_0052AD54.p = func_00122AF8(1, 9, 0);
        D_0052AD54.p->unk_30[0] = D_0052AD54.p->unk_30[1] = D_0052AD54.p->unk_30[2] = 0.0f;
        D_0052AD54.p->unk_3C = 1.0f;
        func_001009A8();
        arg0->unk_10 = 60.0f;
    }
    arg0->unk_10 -= D_002B8344;
    temp_f2 = arg0->unk_10 / 60.0f;
    if (temp_f2 <= 0.0f) {
        func_00122B70(D_0052AD54.p);
        return 4;
    }
    D_0052AD54.p->unk_30[0] = D_0052AD54.p->unk_30[1] = D_0052AD54.p->unk_30[2] = 1.0f - temp_f2;
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/xapple", func_0013B480);
#endif

#ifdef VERSION_FM
typedef union {
    XAppleBlemish* p;
    f32 f;
} XAppleBU;
#define APL_E8 (((XAppleBU*)&D_005325E8)->p)
extern XAppleStem D_002E26A0;
extern sceVu0FVECTOR D_0052AE40;
s32 func_0014F658(XAppleBlemish*, s32);
void func_00131500(XAppleBlemish*);
void func_00130340(XAppleBlemish*, f32, UNK_PTR);
s32 func_00123858(void*);
void func_001250B0(void);
void func_00133588(void);
void func_001452E0(s32, s32);
void func_0023E0B0(s32, s32);

void func_0013B578(void) {
    XAppleBlemish* var_16;

    func_00133588();
    func_001250B0();
    func_0023E0B0(0, 1);
    var_16 = func_001234A0(NULL);
    if (var_16 != NULL) {
        do {
            if (!((var_16->unk_370 >> 0x21) & 1) && (var_16 != (XAppleBlemish*)D_002E26A0.unk_00[1]) &&
                (var_16 != (XAppleBlemish*)D_002E26A0.unk_00[2])) {
                func_00123858(var_16);
            }
            var_16 = func_001234A0(var_16);
        } while (var_16 != NULL);
    }
    func_0014F658(D_005325E8, 0);
    func_00123E48(D_005325E8->unk_04.s32, D_0052AE40);
    func_00131500(D_005325E8);
    func_00130340(D_005325E8, 0.0f, (UNK_PTR)0x40000000);
    APL_E8->unk_370 &= ~0x10000000000000;
    APL_E8->unk_00 &= ~0x200000;
    APL_E8->unk_444 = 0;
    func_001778A0(0);
    D_002C1EA8 &= ~0x4000;
    func_001452E0(0, 4);
    func_0011EEB8(&D_00532518, 0, &func_0013B480);
}

#else
INCLUDE_ASM("asm/nonmatchings/xapple", func_0013B578);
#endif
// int func_0011EEB8(int*, int, int*);
// int func_00123858(void*);
// void func_001250B0(void);
// void func_00133588(void);
// void func_001452E0(int, int);
// void func_0014F8B0(XAppleBlemish*, int);
// void func_0023E0B0(int, int);

// extern int func_0013B480;

// void func_0013B578(void) {
//     XAppleBlemish* var_16;

//     func_00133588();
//     func_001250B0();
//     func_0023E0B0(0, 1);
//     var_16 = func_001234A0(NULL);
//     if (var_16 != NULL) {
//         do {
//             if (!((var_16->unk_370 >> 0x21) & 1) && (var_16 != D_002DEC00->unk_00[1]) && (var_16 !=
//             D_002DEC00->unk_00[2])) {
//                 func_00123858(var_16);
//             }
//             var_16 = func_001234A0(var_16);
//         } while (var_16 != NULL);
//     }
//     func_0014F8B0(D_005325E8, 0);
//     func_00123E48(D_005325E8->unk_04.s32, D_005325F0);
//     func_00131410(D_005325E8);
//     func_00130248(D_005325E8, 0.0f, 0x40000000);
//     D_005325E8->unk_370 &= ~0x10000000000000;
//     D_005325E8->unk_00 &= ~0x200000;
//     D_005325E8->unk_444 = 0;
//     func_001778A0(0);
//     D_002C1EA8 &= ~0x4000;
//     func_001452E0(0, 4);
//     func_0011EEB8(&D_00532518, 0, &func_0013B480);
// }

#ifdef VERSION_FM
extern XAppleBlemish* D_0052AE3C;

s32 func_0013B6E0(void) {
    XAppleBlemish* var_4;

    if (((D_00375BC0 >> 2) & 1) != 0 || D_00532604 != 4 || func_001EE090() != 0) {
        return 0;
    }

    func_0013B578();
    D_0052AE3C = NULL;
    var_4 = NULL;

    do {
        var_4 = func_001234A0(var_4);
        if (var_4 == NULL) {
            break;
        }
        if (var_4->unk_04.u8[2] == 7) {
            D_0052AE3C = var_4;
            break;
        }
    } while (TRUE);

    if (D_0052AE3C != NULL) {
        if ((D_0053260C[2] - D_0053260C[1]) > 0) {
            func_00131498(D_0052AE3C, (s32)D_0053260C + D_0053260C[1]);
            func_00130340(D_0052AE3C, 0.0f, 0);
            D_0052AE3C->unk_00 &= ~0x30;
        }
        D_0052AE3C->unk_444 = 0;
    }
    if ((((u32)D_002C1EC8 >> 8) % 4) != 1) {
        if (D_0053260C[3] - D_0053260C[2] > 0) {
            func_00131498(D_005325E8, (s32)D_0053260C + D_0053260C[2]);
            func_00130340(D_005325E8, 0.0f, 0);
        }
        func_F20000(0, ((D_0053260C[4] - D_0053260C[3]) <= 0) ? NULL : ((s32)D_0053260C + D_0053260C[3]));
    } else {
        func_00124BC8(D_0052AE3C);
        func_00131500(D_005325E8);
        func_00130340(D_005325E8, 0.0f, (UNK_PTR)0x40000000);
    }
    return 1;
}

#else
INCLUDE_ASM("asm/nonmatchings/xapple", func_0013B6E0);
#endif

// s32 func_0013B6E0(void) {
//     XAppleBlemish* var_4;

//     if (((D_00375BC0 >> 2) & 1) != 0 || D_00532604 != 4 || func_001EE090() != 0) {
//         return 0;
//     }

//     func_0013B578();
//     D_005325EC = NULL;
//     var_4 = NULL;

//     do {
//         var_4 = func_001234A0(var_4);
//         if (var_4 == NULL) {
//             break;
//         }
//         if (var_4->unk_04.u8[2] == 7) {
//             D_005325EC = var_4;
//             break;
//         }
//     } while (TRUE);

//     if (D_005325EC != NULL) {
//         if ((D_0053260C[2] - D_0053260C[1]) > 0) {
//             func_001313A8(D_005325EC, (s32)D_0053260C + D_0053260C[1]);
//             func_00130248(D_005325EC, 0.0f, 0);
//             D_005325EC->unk_00 &= ~0x30;
//         }
//         D_005325EC->unk_444 = 0;
//     }
//     if ((((u32)D_002C1EC8 >> 8) % 4) != 1) {
//         if (D_0053260C[3] - D_0053260C[2] > 0) {
//             func_001313A8(D_005325E8, (s32)D_0053260C + D_0053260C[2]);
//             func_00130248(D_005325E8, 0.0f, 0);
//         }
//         func_F20000(0, ((D_0053260C[4] - D_0053260C[3]) <= 0) ? NULL : ((s32)D_0053260C + D_0053260C[3]));
//     } else {
//         func_00124BC8(D_005325EC);
//         func_00131410(D_005325E8);
//         func_00130248(D_005325E8, 0.0f, 0x40000000);
//     }
//     return 1;
// }

s32 func_0013B890(void) {
    if ((((D_002C1EC8 >> 8) % 4) == 1) || (func_F20000(1, 0) == 0)) {
        func_0013A790();
        D_002C1EA8 &= ~0x2000;
        D_00301088 = 0;
        return 1;
    }
    return 0;
}

s32 func_0013B8F8(u16* arg0) {
    if (*arg0 & 0x10) {
        func_0013BD88(&D_00532508, D_00301058, 4);
    }
    func_0011EF58(&D_00532518, 0);
    return (func_0013BDA0(&D_00532508) != 0) ? 0 : 4;
}

void func_0013B968(s32 arg0) {
    func_00132160(
        arg0,
        (s32)D_00532608->unk_00 + D_00532608->unk_00[1],
        ((D_00532608->unk_00[3] - D_00532608->unk_00[2]) <= 0) ? 0 : ((s32)D_00532608->unk_00 + D_00532608->unk_00[2])
    );
}

void func_0013B9A8(void) {
    D_00532604 = 2;
}

#ifdef VERSION_FM
void func_00155B70(u8*);
void func_001560C8(u8*);
void func_00177908(u8*);
void func_00146BC8(s32);
void func_00146A68(u8*, s32, void (*)(void), s32);

void func_0013B9B8(s32 arg0, s32 arg1, u8* arg2) {
    s32* a = (s32*)arg2;

    if (a[2] - a[1] > 0) {
        func_00155B70(arg2 + a[1]);
    }
    if (a[3] - a[2] > 0) {
        func_001560C8(arg2 + a[2]);
    }
    if (a[4] - a[3] > 0) {
        func_001560C8(arg2 + a[3]);
    }
    if (a[6] - a[5] > 0) {
        func_00177908(arg2 + a[5]);
    }
    D_00532604 = 1;
    if (a[8] - a[7] > 0) {
        func_00146BC8(-7);
        func_00146A68(arg2 + a[7], -7, func_0013B9A8, 0);
    } else {
        D_00532604 = 2;
    }
    D_0053260C = (s32*)(((u32)(arg2 + arg0) + 0x7F) >> 7 << 7);
}
#else
INCLUDE_ASM("asm/nonmatchings/xapple", func_0013B9B8);
void func_0013B9B8();
#endif
// s32 func_0013B9B8(s32 arg0, s32 arg1, s32 arg2) {
//     int iVar1;
//     int iVar2;

//     iVar2 = *(int*)(arg2 + 8);
//     if (iVar2 - *(int*)(arg2 + 4) < 1) {
//         iVar1 = *(int*)(arg2 + 0xc);
//     } else {
//         func_00156058(arg2 + *(int*)(arg2 + 4));
//         iVar2 = *(int*)(arg2 + 8);
//         iVar1 = *(int*)(arg2 + 0xc);
//     }
//     if (iVar1 - iVar2 < 1) {
//         iVar2 = *(int*)(arg2 + 0x10);
//     } else {
//         func_001560C8(arg2 + iVar2);
//         iVar1 = *(int*)(arg2 + 0xc);
//         iVar2 = *(int*)(arg2 + 0x10);
//     }
//     if (iVar2 - iVar1 < 1) {
//         iVar2 = *(int*)(arg2 + 0x18);
//     } else {
//         func_001560C8(arg2 + iVar1);
//         iVar2 = *(int*)(arg2 + 0x18);
//     }
//     if (0 < iVar2 - *(int*)(arg2 + 0x14)) {
//         func_00177908(arg2 + *(int*)(arg2 + 0x14));
//     }
//     D_00532604 = 1;
//     if (*(int*)(arg2 + 0x20) - *(int*)(arg2 + 0x1c) < 1) {
//         D_00532604 = 2;
//     } else {
//         func_00146BC8(-7);
//         func_00146D08(arg2 + *(int*)(arg2 + 0x1c), -7, func_0013B9A8, 0);
//     }
//     D_0053260C = (s32*)(arg2 + arg0 + 0x7fU & 0xffffff80);
// }

f32 func_0013BAC0(void) {
    return (D_002DEC00->unk_6C->unk_48 + ((s32)(D_002DED20 >> 0xA) & 7)) * 3000;
}

void* func_0013BB00(s32 arg0, s32 arg1) {
    char something[0x20];

    D_002C1EA8 |= 0x102000;
    D_00301088 = (D_00301088 & (~7)) | (arg1 & 7) | 8;
    D_00301080 = &D_003051EC->unk_98[arg1].unk_00;
    D_00301094 |= 1 << arg1;
    D_0030108C = D_00301090 = func_0013BAC0();
    func_00141668(arg0, -*(&D_003051EC->unk_98[arg1].unk_00));
    D_005325E8 = arg0;
    D_00532600 = arg1;
    func_00157AD8(1);
    func_00157AD8(2);
    func_00157AD8(3);
    D_00532604 = 0;
    D_00532608 = func_00155ED8(0x34, 0xC);
    sprintf(something, "%s%s", D_00301010[arg1], D_00301078);
    func_00120590(something, D_00532608, func_0013B9B8, 0);
    func_0011EDD0(&D_00532518, &D_00532528, 0x18, 8);
    return func_0011ED30(52000, func_0013B8F8);
}

void func_0013BCA8(void) {
    if ((D_002C1EA8 >> 13) & 1) {
        func_F20000(2, 0);
        func_0011ED80(func_0013B8F8);
        func_0023E0B0(0, 1);
        func_0023E0B0(1, 2);
        func_0023E0B0(2, 2);
    }
    if (D_002C1EA8 & (0x100000 | 0x4000)) {
        func_00133588();
        func_001009A8();
    }
    D_00301088 &= ~8;
    D_00301094 = 0;
    D_002C1EA8 &= ~0x2000;
    D_002C1EA8 &= ~0x4000;
    D_002C1EA8 &= ~0x100000;
}
