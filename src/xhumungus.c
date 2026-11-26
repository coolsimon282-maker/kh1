/**
 * The largest game file (FM 0x1C6D08-0x1DDC78), about 650 functions not yet sorted into subsystems. Known so far:
 * script operator evaluation (ScriptOp_ApplyOperator) and the native command call (ScriptOp_CallCommand) used by the
 * script opcode handlers in xkinetic.c. Fragile (rule F1): identifiers here keep their old names; new names go through
 * config/fm/symbol_addrs.txt and the aliases in config/fm/undefined_syms.txt.
 */
#include "common.h"

#include "xcursed.h"
#include "xhumungus.h"
#include "xtailor.h"
#include "xarcade.h"
#include "xflamingo.h"
#include "xpeanut.h"

extern u32 D_002A2740;
extern s32 D_002A2744;
extern s32 D_002A2748;
extern u32 D_002B29C4;
extern u32 D_002B8000;
extern u32 D_002B8004;
extern u32 D_002B8008;
extern u32 D_002B8014;
extern f32 D_002B8348;
extern u32 D_002B834C;
extern s32 D_002B8678;
extern s32 D_002B8680;
extern s32 D_002B8684;
extern u32 D_002B916C;
extern u32 D_002B9170;
extern u32 D_002B9338;
extern u32 D_002B9660;
extern s32 D_002C2104;
extern s32 D_002C2108;
extern s32 D_002C2024;
extern u16 D_002C1EAA;
extern u32 D_00375BC0;
extern XGiantMountain D_003854E0;
extern u32 D_00388860;
extern u32 D_003889B0;

// Sora/Riku score on Destiny Island
extern s32 D_003C10B8[];

extern XHumungusFunc D_003C10D8[];
extern XHumungusFunc D_003D4A20[];
extern s32* D_003D55DC;

extern u32 D_003F0DD4;
extern s32 D_0041F8BC;

extern char D_0048A3A0[];

extern UNK_PTR D_00624550;
extern UNK_PTR D_00624554;
extern UNK_PTR D_00624658;
extern UNK_PTR D_00624958;
extern UNK_PTR D_00624960;
extern UNK_PTR D_00624970;

extern void func_F20000();

extern u32 D_0038CD00[];
extern u32* D_002C6440;
extern s32 D_0038CDE4;
extern s32 D_0038CDE8;

struct XNoodle;
void func_0010BB10(struct XNoodle*, s32);
extern struct XNoodle D_0062A130;
extern s32 D_0038D0D4;
extern s32 D_003F6E24;
extern u8 D_003C5808[];

void func_0010EDA0(struct XNoodle*, void*, void (*)(void));
s32 func_00131B08(s32);
void func_001EAC68(void);
void func_0024D418(void);
void func_0013DFA0(void*);
void func_00135848(void*);
void func_00135870(void*);
void func_0014F398(void*);
extern s32 D_0038D0E0[];
extern s32 D_0062A210;
extern s32 D_002A61F0;
extern s32 D_00388CC4[];
void func_00242BD0(void);
void func_001ED878(s32);
void func_00177908(s32);
void func_00108180(s32);
void func_001081A0(s32);
extern s32 D_002BC090;
extern s32 D_002BC094;
extern s32 D_003F76B8;
extern s32 D_002BC0A0;
extern s32 D_002BC0A4;
extern s32 D_002BBABC;
extern s32 D_002BBAC0;
s32 func_0013BF68(void);
s32 func_001DDB58(void);
extern f32 D_0038CDDC;
extern f32 D_002A6200;
extern f32* D_002E26A0[];
extern u32 D_002BCA00[];
extern f32* D_002E26A0[];
extern u32 D_002BCA00[];
extern s32 D_002BC090;
extern s32 D_002BC094;
extern s32 D_003F76B8;
extern s32 (*D_003773C4)(void);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C8470);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C8950);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C8E68);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C9380);

typedef struct {
    /* 0x000 */ u64 flags;
    /* 0x008 */ u8 unk_08[0xB8];
    /* 0x0C0 */ sceVu0FVECTOR unk_C0;
    /* 0x0D0 */ sceVu0FVECTOR unk_D0;
    /* 0x0E0 */ sceVu0FVECTOR unk_E0;
    /* 0x0F0 */ u8 unk_F0[0x30];
    /* 0x120 */ f32 unk_120;
} Unk3C5510D;
extern Unk3C5510D D_003C5510_d __asm__("D_003C5510");
void func_001C6890(Script*);
void func_001C6A20(void);
f32 func_001E9E58(f32* a, f32* b);
void func_001E9D00(f32* out, f32* a, f32* b, f32 roll);

s32 func_001C98D0(Script* arg0) {
    sceVu0FVECTOR v;
    sceVu0FVECTOR w;

    func_001C6890(arg0);
    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    D_003C5510_d.unk_120 = func_001E9E58(v, D_003C5510_d.unk_D0);
    func_001E9D00(w, D_003C5510_d.unk_D0, v, D_003C5510_d.unk_E0[2]);
    sceVu0CopyVector(D_003C5510_d.unk_E0, w);
    func_001C6A20();
    if ((s32)(D_003C5510_d.flags >> 8) & 1) {
        sceVu0CopyVector(D_003C5510_d.unk_C0, D_003C5510_d.unk_D0);
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001C99C8(Script* arg0) {
    func_001C6890(arg0);
    D_003C5510_d.unk_D0[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    D_003C5510_d.unk_D0[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    D_003C5510_d.unk_D0[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_001C6A20();
    if ((s32)(D_003C5510_d.flags >> 8) & 1) {
        sceVu0CopyVector(D_003C5510_d.unk_C0, D_003C5510_d.unk_D0);
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

void func_001C6890(Script*);
void func_001C6A20(void);
typedef struct { u8 pad[0xE0]; f32 rot[3]; } A2Unk3C5510C;
extern A2Unk3C5510C D_003C5510_c __asm__("D_003C5510");

s32 func_001C9A70(Script* arg0) {
    func_001C6890(arg0);
    D_003C5510_c.rot[0] = arg0->unk_174[arg0->unk_174[3] + 2] / 180.0f * 3.1415928f;
    D_003C5510_c.rot[1] = arg0->unk_174[arg0->unk_174[3] + 3] / 180.0f * 3.1415928f;
    D_003C5510_c.rot[2] = arg0->unk_174[arg0->unk_174[3] + 4] / 180.0f * 3.1415928f;
    func_001C6A20();
    arg0->unk_174[3] -= 3;
    return 2;
}

void func_001C6890(Script*);
void func_001C6A20(void);
extern f32 D_003C5630;
extern f32 D_003C5634;

s32 func_001C9B30(Script* arg0) {
    func_001C6890(arg0);
    D_003C5630 = arg0->unk_174[arg0->unk_174[3] + 4];
    func_001C6A20();
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001C9B88(Script* arg0) {
    func_001C6890(arg0);
    D_003C5634 = arg0->unk_174[arg0->unk_174[3] + 4];
    func_001C6A20();
    arg0->unk_174[3]--;
    return 2;
}

extern f32 D_003C55E0[];
extern f32 D_003C55E8[];

// reads a scalar f32 global like a struct field (keeps the load above the stack store)
typedef struct {
    f32 unk_00;
} F32Box;
void func_001C6890(Script*);

s32 func_001C9BE0(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003C55E0[0];
    return 2;
}

s32 func_001C9C30(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003C55E0[1];
    return 2;
}

s32 func_001C9C80(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003C55E8[0];
    return 2;
}

extern f32 D_003C55F0[];

s32 func_001C9CD0(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003C55F0[0] / 3.1415928f * 180.0f;
    return 2;
}

s32 func_001C9D40(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003C55F0[1] / 3.1415928f * 180.0f;
    return 2;
}

s32 func_001C9DB0(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003C55F0[2] / 3.1415928f * 180.0f;
    return 2;
}

s32 func_001C9E20(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = ((F32Box*)&D_003C5630)->unk_00;
    return 2;
}

s32 func_001C9E70(Script* arg0) {
    func_001C6890(arg0);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = ((F32Box*)&D_003C5634)->unk_00;
    return 2;
}

typedef struct {
    /* 0x000 */ u64 unk_00_0 : 1;
    u64 unk_00_1 : 31;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ u8 unk_08[0x10];
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ u8 unk_1C[0x24];
    /* 0x040 */ f32 unk_40[4];
    /* 0x050 */ u8 unk_50[0x20];
    /* 0x070 */ f32 unk_70[4];
    /* 0x080 */ u8 unk_80[0x50];
    /* 0x0D0 */ f32 unk_D0[4];
    /* 0x0E0 */ f32 unk_E0[4];
    /* 0x0F0 */ u8 unk_F0[0x30];
    /* 0x120 */ f32 unk_120;
} Unk3C5510W;
extern Unk3C5510W D_003C5510_w __asm__("D_003C5510");
extern f32 D_002B8344;
void func_001E9FE8(f32*, f32*);
void func_001E9F18(f32* o, f32* pos, f32* rot, f32 dist);

void func_001C9EC0(void) {
    Unk3C5510W* p = &D_003C5510_w;
    f32* a = p->unk_40;
    f32* b = p->unk_70;
    f32 o[4];
    f32 r[4];

    p->unk_18 += D_002B8344;
    if (p->unk_04 < p->unk_18) {
        p->unk_18 = p->unk_04;
        p->unk_00_0 = 0;
    }
    func_001E9FE8(r, p->unk_E0);
    func_001E9F18(o, p->unk_D0, r, p->unk_120);
    p->unk_D0[0] = a[0] + (b[0] - a[0]) / p->unk_04 * p->unk_18;
    p->unk_D0[1] = a[1] + (b[1] - a[1]) / p->unk_04 * p->unk_18;
    p->unk_D0[2] = a[2] + (b[2] - a[2]) / p->unk_04 * p->unk_18;
    func_001C6A20();
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C9FE0);

extern f32 D_002B8344;
typedef struct {
    /* 0x000 */ u64 unk_00_0 : 1;
    u64 unk_00_1 : 1;
    u64 unk_00_2 : 62;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ u8 unk_0C[0x10];
    /* 0x01C */ f32 unk_1C;
    /* 0x020 */ u8 unk_20[0x30];
    /* 0x050 */ f32 unk_50[4];
    /* 0x060 */ u8 unk_60[0x20];
    /* 0x080 */ f32 unk_80[4];
    /* 0x090 */ u8 unk_90[0x50];
    /* 0x0E0 */ f32 unk_E0[4];
} Unk3C5510V;
extern Unk3C5510V D_003C5510_v __asm__("D_003C5510");

void func_001CA090(void) {
    Unk3C5510V* p = &D_003C5510_v;
    f32* a = p->unk_50;
    f32* b = p->unk_80;

    p->unk_1C += D_002B8344;
    if (p->unk_08 < p->unk_1C) {
        p->unk_00_1 = 0;
        p->unk_1C = p->unk_08;
    }
    p->unk_E0[0] = a[0] + (b[0] - a[0]) / p->unk_08 * p->unk_1C;
    p->unk_E0[1] = a[1] + (b[1] - a[1]) / p->unk_08 * p->unk_1C;
    p->unk_E0[2] = a[2] + (b[2] - a[2]) / p->unk_08 * p->unk_1C;
    do {
        func_001C6A20();
    } while (0);
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CA418);

typedef struct {
    /* 0x000 */ u64 unk_00_0 : 9;
    u64 unk_00_9 : 1;
    u64 unk_00_10 : 54;
    /* 0x008 */ u8 unk_08[0xC];
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ u8 unk_18[0x10];
    /* 0x028 */ f32 unk_28;
    /* 0x02C */ u8 unk_2C[0x3C];
    /* 0x068 */ f32 unk_68;
    /* 0x06C */ u8 unk_6C[0x2C];
    /* 0x098 */ f32 unk_98;
    /* 0x09C */ u8 unk_9C[0x90];
    /* 0x12C */ f32 unk_12C;
} Unk3C5510;

extern Unk3C5510 D_003C5510;
extern f32 D_0036266C;

extern f32 D_002B8344;

typedef struct {
    /* 0x000 */ u64 unk_00_0 : 2;
    u64 unk_00_2 : 1;
    u64 unk_00_3 : 1;
    u64 unk_00_4 : 60;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ f32 unk_0C[5];
    /* 0x020 */ f32 unk_20[16];
    /* 0x060 */ f32 unk_60[12];
    /* 0x090 */ f32 unk_90[36];
    /* 0x120 */ f32 unk_120[4];
} Unk3C5510A;

void func_001CA638(void) {
    Unk3C5510A* p = (Unk3C5510A*)&D_003C5510;

    p->unk_20[0] += D_002B8344;
    if (p->unk_0C[0] < p->unk_20[0]) {
        p->unk_00_2 = 0;
        p->unk_20[0] = p->unk_0C[0];
    }
    p->unk_120[0] = p->unk_60[0] + (p->unk_90[0] - p->unk_60[0]) / p->unk_0C[0] * p->unk_20[0];
    do {
        func_001C6A20();
    } while (0);
}

s32 func_001CA720(Script* arg0) {
    Unk3C5510A* p;

    func_001C6890(arg0);
    p = (Unk3C5510A*)&D_003C5510;
    p->unk_00_2 = 1;
    p->unk_60[0] = p->unk_120[0];
    p->unk_20[0] = 0.0f;
    p->unk_0C[0] = arg0->unk_174[arg0->unk_174[3] + 3] * 2.0f;
    p->unk_90[0] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001CA7A0(void) {
    Unk3C5510A* p = (Unk3C5510A*)&D_003C5510;

    p->unk_20[1] += D_002B8344;
    if (p->unk_0C[1] < p->unk_20[1]) {
        p->unk_00_3 = 0;
        p->unk_20[1] = p->unk_0C[1];
    }
    p->unk_120[1] = p->unk_60[1] + (p->unk_90[1] - p->unk_60[1]) / p->unk_0C[1] * p->unk_20[1];
    do {
        func_001C6A20();
    } while (0);
}

s32 func_001CA888(Script* arg0) {
    Unk3C5510A* p;

    func_001C6890(arg0);
    p = (Unk3C5510A*)&D_003C5510;
    p->unk_00_3 = 1;
    p->unk_60[1] = p->unk_120[1];
    p->unk_20[1] = 0.0f;
    p->unk_0C[1] = arg0->unk_174[arg0->unk_174[3] + 3] * 2.0f;
    p->unk_90[1] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CA908);

NOTHROW_FN(void func_001C6890(Script* a));
typedef struct {
    /* 0x000 */ u64 unk_00_0 : 8;
    u64 unk_00_8 : 1;
    u64 unk_00_9 : 55;
    /* 0x008 */ u8 unk_08[0x98];
    /* 0x0A0 */ f32 unk_A0[3];
    /* 0x0AC */ s32 unk_AC;
    /* 0x0B0 */ f32 unk_B0;
    /* 0x0B4 */ s32 unk_B4;
    /* 0x0B8 */ u8 unk_B8[8];
    /* 0x0C0 */ f32 unk_C0[4];
    /* 0x0D0 */ f32 unk_D0[4];
} Unk3C5510K;
extern Unk3C5510K D_003C5510_k __asm__("D_003C5510");
void sceVu0CopyVector(f32*, f32*);

s32 func_001CACC0(Script* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] > 0) {
        func_001C6890(arg0);
        D_003C5510_k.unk_B4 = 0;
        D_003C5510_k.unk_00_8 = 1;
        D_003C5510_k.unk_A0[0] = arg0->unk_174[arg0->unk_174[3]];
        D_003C5510_k.unk_A0[1] = arg0->unk_174[arg0->unk_174[3] + 1];
        D_003C5510_k.unk_A0[2] = arg0->unk_174[arg0->unk_174[3] + 2];
        D_003C5510_k.unk_AC = arg0->unk_174[arg0->unk_174[3] + 3];
        D_003C5510_k.unk_B0 = arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f;
        sceVu0CopyVector(D_003C5510_k.unk_C0, D_003C5510_k.unk_D0);
    } else {
        D_003C5510_k.unk_00_8 = 0;
    }
    arg0->unk_174[3] -= 5;
    return 2;
}

s32 func_001CADC0(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 37) & 1) ? 4 : 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CADE0);

typedef struct {
    /* 0x000 */ u64 unk_00_0 : 4;
    u64 unk_00_4 : 1;
    u64 unk_00_5 : 27;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ u8 unk_08[0x10];
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ u8 unk_1C[0x10];
    /* 0x02C */ s32 unk_2C;
    /* 0x030 */ u8 unk_30[0x10];
    /* 0x040 */ f32 unk_40[3];
    /* 0x04C */ u8 unk_4C[0x24];
    /* 0x070 */ f32 unk_70[3];
    /* 0x07C */ u8 unk_7C[0x54];
    /* 0x0D0 */ f32 unk_D0[3];
} Unk3C5510E;

s32 func_001CB0E0(Script* arg0) {
    Unk3C5510E* p;

    func_001C6890(arg0);
    p = (Unk3C5510E*)&D_003C5510;
    p->unk_00_4 = 1;
    p->unk_40[0] = p->unk_D0[0];
    p->unk_40[1] = p->unk_D0[1];
    p->unk_40[2] = p->unk_D0[2];
    p->unk_04 = arg0->unk_174[arg0->unk_174[3]] * 2.0f;
    p->unk_2C = arg0->unk_174[arg0->unk_174[3] + 1];
    p->unk_18 = 0.0f;
    p->unk_70[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    p->unk_70[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    p->unk_70[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 5;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB1A8);

/* Unused on purpose: keeps fm_func_001DC9A0 / func_001DDC08 matching (notes/f1.md F1). */
extern s32 func_001CB4A0_f1_pad1;
void func_001E9FE8(f32*, f32*);
typedef struct {
    /* 0x000 */ u64 unk_00_0 : 5;
    u64 unk_00_5 : 1;
    u64 unk_00_6 : 26;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ u8 unk_0C[0x24];
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ u8 unk_34[0x1C];
    /* 0x050 */ f32 unk_50[3];
    /* 0x05C */ u8 unk_5C[0x24];
    /* 0x080 */ f32 unk_80[4];
    /* 0x090 */ u8 unk_90[0x50];
    /* 0x0E0 */ f32 unk_E0[3];
} Unk3C5510F;

s32 func_001CB4A0(Script* arg0) {
    Unk3C5510F* p;

    func_001C6890(arg0);
    p = (Unk3C5510F*)&D_003C5510;
    p->unk_00_5 = 1;
    p->unk_08 = arg0->unk_174[arg0->unk_174[3]] * 2.0f;
    p->unk_30 = arg0->unk_174[arg0->unk_174[3] + 1];
    p->unk_80[0] = arg0->unk_174[arg0->unk_174[3] + 2] * 3.1415928f / 180.0f;
    p->unk_80[1] = arg0->unk_174[arg0->unk_174[3] + 3] * 3.1415928f / 180.0f;
    p->unk_80[2] = arg0->unk_174[arg0->unk_174[3] + 4] * 3.1415928f / 180.0f;
    func_001E9FE8(p->unk_80, p->unk_80);
    arg0->unk_174[3] -= 5;
    p->unk_50[0] = p->unk_E0[0];
    p->unk_50[1] = p->unk_E0[1];
    p->unk_50[2] = p->unk_E0[2];
    return 2;
}

typedef struct {
    /* 0x000 */ u64 unk_00;
    /* 0x008 */ f32 unk_08;
    /* 0x00C */ f32 unk_0C;
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ u8 unk_14[0xC];
    /* 0x020 */ f32 unk_20;
    /* 0x024 */ f32 unk_24;
    /* 0x028 */ u8 unk_28[4];
    /* 0x02C */ s32 unk_2C;
    /* 0x030 */ u8 unk_30[4];
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_38;
    /* 0x03C */ u8 unk_3C[0x24];
    /* 0x060 */ f32 unk_60;
    /* 0x064 */ f32 unk_64;
    /* 0x068 */ u8 unk_68[0x28];
    /* 0x090 */ f32 unk_90;
    /* 0x094 */ f32 unk_94;
    /* 0x098 */ u8 unk_98[0x88];
    /* 0x120 */ f32 unk_120;
    /* 0x124 */ f32 unk_124;
} Unk3C5510H;
extern Unk3C5510H D_003C5510_h __asm__("D_003C5510");

void func_001CB5C0(void) {
    f32* p0;
    f32* p1;
    f32 v0 = 0.0f;
    f32 v1 = 0.0f;
    f32 t;
    f32 d;
    f32 s;
    f32 s2;
    f32 s3;

    D_003C5510_h.unk_20 += D_002B8344;
    p0 = &D_003C5510_h.unk_60;
    p1 = &D_003C5510_h.unk_90;
    switch ((u32)D_003C5510_h.unk_34) {
    case 0:
    case 3:
        v0 = (*p1 - *p0) / D_003C5510_h.unk_0C;
        break;
    case 1:
    case 2:
        break;
    }
    switch ((u32)D_003C5510_h.unk_34) {
    case 0:
    case 2:
        v1 = (*p1 - *p0) / D_003C5510_h.unk_0C;
        break;
    case 1:
    case 3:
        v1 = 0.0f;
        break;
    }
    t = D_003C5510_h.unk_20;
    if (t == 0.0f) {
        D_003C5510_h.unk_120 = *p0;
    } else if (D_003C5510_h.unk_0C <= t) {
        D_003C5510_h.unk_120 = *p1;
    } else {
        d = D_003C5510_h.unk_0C - 0.0f;
        s = (t - 0.0f) / d;
        s2 = s * s;
        s3 = s * s2;
        D_003C5510_h.unk_120 = (2.0f * s3 - 3.0f * s2 + 1.0f) * *p0 + (-2.0f * s3 + 3.0f * s2) * *p1 +
                               ((s3 - 2.0f * s2 + s) * v0 + (s3 - s2) * v1) * d;
    }
    func_001C6A20();
    if (D_003C5510_h.unk_20 > D_003C5510_h.unk_0C) {
        D_003C5510_h.unk_00 &= ~0x40;
    }
}

typedef struct {
    u64 unk_00_0 : 6;
    u64 unk_00_6 : 1;
    u64 unk_00_7 : 57;
    s32 unk_08;
} Unk3C5510Bits6;

s32 func_001CB7B8(Script* arg0) {
    Unk3C5510A* p;

    func_001C6890(arg0);
    p = (Unk3C5510A*)&D_003C5510;
    ((Unk3C5510Bits6*)p)->unk_00_6 = 1;
    p->unk_60[0] = p->unk_120[0];
    p->unk_20[0] = 0.0f;
    p->unk_0C[0] = arg0->unk_174[arg0->unk_174[3] + 2] * 2.0f;
    *(s32*)&p->unk_20[5] = arg0->unk_174[arg0->unk_174[3] + 3];
    p->unk_90[0] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 3;
    return 2;
}

void func_001CB850(void) {
    D_003C5510.unk_28 += D_002B8344;
    if (D_003C5510.unk_14 < D_003C5510.unk_28) {
        D_003C5510.unk_00_9 = 0;
        D_0036266C = D_003C5510.unk_98;
    } else {
        D_0036266C = (D_003C5510.unk_98 - D_003C5510.unk_68) * (D_003C5510.unk_28 / D_003C5510.unk_14);
    }
}

s32 func_001CB8C8(Script* arg0) {
    D_003C5510.unk_00_9 = 1;
    D_003C5510.unk_28 = 0.0f;
    D_003C5510.unk_68 = D_0036266C;
    D_003C5510.unk_12C = D_0036266C;
    D_003C5510.unk_14 = arg0->unk_174[arg0->unk_174[3] + 3] * 2.0f;
    D_003C5510.unk_98 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001CB938(Script* arg0) {
    D_003C5510.unk_00_9 = 1;
    D_003C5510.unk_98 = D_003C5510.unk_12C;
    D_003C5510.unk_68 = D_0036266C;
    D_003C5510.unk_28 = 0.0f;
    D_003C5510.unk_14 = arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f;
    arg0->unk_174[3]--;
    return 2;
}

void func_001CB998(void) {
    f32* p0;
    f32* p1;
    f32 v0 = 0.0f;
    f32 v1 = 0.0f;
    f32 t;
    f32 d;
    f32 s;
    f32 s2;
    f32 s3;

    D_003C5510_h.unk_24 += D_002B8344;
    p0 = &D_003C5510_h.unk_64;
    p1 = &D_003C5510_h.unk_94;
    switch ((u32)D_003C5510_h.unk_38) {
    case 0:
    case 3:
        v0 = (*p1 - *p0) / D_003C5510_h.unk_10;
        break;
    case 1:
    case 2:
        break;
    }
    switch ((u32)D_003C5510_h.unk_2C) {
    case 0:
    case 2:
        v1 = (*p1 - *p0) / D_003C5510_h.unk_10;
        break;
    case 1:
    case 3:
        v1 = 0.0f;
        break;
    }
    t = D_003C5510_h.unk_24;
    if (t == 0.0f) {
        D_003C5510_h.unk_124 = *p0;
    } else if (D_003C5510_h.unk_10 <= t) {
        D_003C5510_h.unk_124 = *p1;
    } else {
        d = D_003C5510_h.unk_10 - 0.0f;
        s = (t - 0.0f) / d;
        s2 = s * s;
        s3 = s * s2;
        D_003C5510_h.unk_124 = (2.0f * s3 - 3.0f * s2 + 1.0f) * *p0 + (-2.0f * s3 + 3.0f * s2) * *p1 +
                               ((s3 - 2.0f * s2 + s) * v0 + (s3 - s2) * v1) * d;
    }
    func_001C6A20();
    if (D_003C5510_h.unk_24 > D_003C5510_h.unk_10) {
        D_003C5510_h.unk_00 &= ~0x80;
    }
}

typedef struct {
    u64 unk_00_0 : 7;
    u64 unk_00_7 : 1;
    u64 unk_00_8 : 56;
    s32 unk_08;
} Unk3C5510Bits;

s32 func_001CBB90(Script* arg0) {
    Unk3C5510A* p;

    func_001C6890(arg0);
    p = (Unk3C5510A*)&D_003C5510;
    ((Unk3C5510Bits*)p)->unk_00_7 = 1;
    p->unk_60[1] = p->unk_120[1];
    p->unk_0C[1] = arg0->unk_174[arg0->unk_174[3] + 2] * 2.0f;
    *(s32*)&p->unk_20[6] = arg0->unk_174[arg0->unk_174[3] + 3];
    p->unk_90[1] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 3;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CBC20);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CBE90);

void func_001E9FE8(f32*, f32*);
void func_001E9F18(f32*, f32*, f32*, f32);

s32 func_001CC130(Script* arg0) {
    f32 a[4];
    f32 b[4];

    func_001C6890(arg0);
    func_001E9FE8(b, D_003C55F0);
    func_001E9F18(a, D_003C55F0 - 4, b, D_003C55F0[16]);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = a[0];
    return 2;
}

s32 func_001CC1B8(Script* arg0) {
    f32 a[4];
    f32 b[4];

    func_001C6890(arg0);
    func_001E9FE8(b, D_003C55F0);
    func_001E9F18(a, D_003C55F0 - 4, b, D_003C55F0[16]);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = a[1];
    return 2;
}

s32 func_001CC240(Script* arg0) {
    f32 a[4];
    f32 b[4];

    func_001C6890(arg0);
    func_001E9FE8(b, D_003C55F0);
    func_001E9F18(a, D_003C55F0 - 4, b, D_003C55F0[16]);
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = a[2];
    return 2;
}

s32 func_001CC2C8(void) {
    if (!(D_002C1EA8 >> 1 & 1)) {
        func_00180038();
    }
    return 2;
}

s32 func_001CC300(void) {
    if (!(D_002C1EA8 >> 1 & 1)) {
        func_00180080();
    }
    return 2;
}

typedef struct {
    /* 0x00 */ u64 unk_00;
    /* 0x08 */ u8 unk_08[0xB8];
    /* 0xC0 */ f32 unk_C0[4];
    /* 0xD0 */ f32 unk_D0[4];
} Unk3C5510G;
extern Unk3C5510G D_003C5510_g __asm__("D_003C5510");
s32 func_001C5B88();
s32 func_001CA908();
void func_001CADE0(void);
void func_001CB1A8(void);
void func_001CB5C0(void);
void func_001CB998(void);

void func_001CC338(void) {
    s32 t = (s32)(*(u64*)D_0038CD00 >> 37) & 1;

    if (t == 1) {
        func_0011ED30(99999, func_001C5B88);
    }
    if (*(s32*)&D_003C5510_g.unk_00 & 1) {
        func_001C9EC0();
        if ((s32)(D_003C5510_g.unk_00 >> 8) & 1) {
            sceVu0CopyVector(D_003C5510_g.unk_C0, D_003C5510_g.unk_D0);
        }
    }
    if ((s32)(D_003C5510_g.unk_00 >> 4) & 1) {
        func_001CADE0();
        if ((s32)(D_003C5510_g.unk_00 >> 8) & 1) {
            sceVu0CopyVector(D_003C5510_g.unk_C0, D_003C5510_g.unk_D0);
        }
    }
    if ((s32)(D_003C5510_g.unk_00 >> 1) & 1) {
        func_001CA090();
    }
    if ((s32)(D_003C5510_g.unk_00 >> 5) & 1) {
        func_001CB1A8();
    }
    if ((s32)(D_003C5510_g.unk_00 >> 2) & 1) {
        func_001CA638();
    }
    if ((s32)(D_003C5510_g.unk_00 >> 6) & 1) {
        func_001CB5C0();
    }
    if ((s32)(D_003C5510_g.unk_00 >> 3) & 1) {
        func_001CA7A0();
    }
    if ((s32)(D_003C5510_g.unk_00 >> 7) & 1) {
        func_001CB998();
    }
    if ((s32)(D_003C5510_g.unk_00 >> 8) & 1) {
        func_0011ED30(99999, func_001CA908);
    }
    if ((s32)(D_003C5510_g.unk_00 >> 9) & 1) {
        func_001CB850();
    }
}

void func_001CC520(void) {
    D_003854E0.unk_00 = 0;
}

void func_001CC530(void) {
    func_0010BB10(&D_0062A130, (s32)func_001CC520);
}

void func_001CC558(void) {
    func_0010EDA0(&D_0062A130, D_003C5808, func_001CC530);
}

void func_0010BB50();

typedef struct { u8 b0[4]; s8 b4[0x102C]; u8 b1030[4]; } XHumCC588;
extern XHumCC588 D_003854E0_58 __asm__("D_003854E0");
s32 func_001CC588(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_003854E0_58.b0[i] != 0) {
            break;
        }
    }
    if (i < 4) {
        return 0;
    }
    func_0010BB50(&D_0062A130, func_001CC558);
    D_003854E0_58.b1030[0] = 0;
    D_003854E0_58.b0[0] = 2;
    return 4;
}

typedef struct { s8 b0[4]; s8 b4[8]; s8 bC[0x1004]; s32 w1010[8]; s8 b1030[4]; } XHumCC618;
extern XHumCC618 D_003854E0_c6 __asm__("D_003854E0");
void func_001CC618(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        D_003854E0_c6.b0[i] = 0;
        D_003854E0_c6.w1010[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        D_003854E0_c6.b4[i] = 0;
        D_003854E0_c6.bC[i] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC680);

void func_001CC798(s32 arg0) {
    D_003854E0.unk_3070 &= ~0x100000000;
    D_003854E0.unk_3140 = arg0;
    *D_003854E0.unk_3144 = arg0;
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001CC7D0_f1_pad1;
extern s32 func_001CC7D0_f1_pad2;
extern s32 func_001CC7D0_f1_pad3;

typedef struct { u8 pad[0xB0]; } XHumB0c7;
extern XHumB0c7 D_00629E70_c7[] __asm__("D_00629E70");
typedef struct {
    /* 0x0000 */ u8 b0[4];
    /* 0x0004 */ s8 b4[0x102C];
    /* 0x1030 */ s8 b1030[4];
    /* 0x1034 */ s32 w1034[0x80F];
    /* 0x3070 */ u64 unk_3070_0 : 32;
    u64 unk_3070_32 : 1;
    u64 unk_3070_33 : 31;
    /* 0x3078 */ u8 unk_3078[0xCC];
    /* 0x3144 */ s32* unk_3144;
} XHumCC7D0;
extern XHumCC7D0 D_003854E0_c7 __asm__("D_003854E0");
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ void (*unk_08)(s32);
} XHumA1E0;
extern XHumA1E0 D_0062A1E0;
void func_0010F3B8(XHumA1E0* arg0, XHumB0c7* arg1, s32 arg2);

s32 func_001CC7D0(Script* arg0) {
    s32 i;
    s32 v = arg0->unk_174[36];

    for (i = 0; i < 4; i++) {
        if (D_003854E0_c7.b0[i] != 0 && D_003854E0_c7.b1030[i] == arg0->unk_174[arg0->unk_174[3] + 1]) {
            break;
        }
    }
    if (i >= 4) {
        return 2;
    }
    D_0062A1E0.unk_00 = arg0->unk_174[arg0->unk_174[3] + 2];
    D_0062A1E0.unk_08 = func_001CC798;
    D_0062A1E0.unk_04 = arg0->unk_174[arg0->unk_174[3] + 3];
    if (v >= 0x100) {
        v -= 0x900;
        D_003854E0_c7.unk_3144 = &D_003854E0_c7.w1034[v];
    }
    func_0010F3B8(&D_0062A1E0, &D_00629E70_c7[i], D_0062A1E0.unk_00);
    D_003854E0_c7.unk_3070_32 = 1;
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001CC930(void) {
    return (D_0038CD00[1] & 1) ? 4 : 2;
}

typedef struct { s8 b0[4]; s8 b4[0x100C]; s32 w1010[8]; s8 b1030[4]; } XHumCC950;
typedef struct { u8 pad[0xB0]; } XHumB0;
extern XHumB0 D_00629E70_b[] __asm__("D_00629E70");
extern XHumCC950 D_003854E0_cc __asm__("D_003854E0");
void func_001CC950(s32 a0, XHumB0* a1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (&D_00629E70_b[i] == a1) {
            s8 k = D_003854E0_cc.b1030[i];
            D_003854E0_cc.b0[i] = 0;
            D_003854E0_cc.b4[k] = 0;
            D_003854E0_cc.w1010[k] = 0;
        }
    }
}

typedef struct { u8 b0[4]; s8 b4[0x100C]; s32 w1010[8]; s8 b1030[4]; } XHumCC9A8;
extern XHumCC9A8 D_003854E0_c9 __asm__("D_003854E0");
void func_0010BB10_c9(XHumB0*, s32) __asm__("func_0010BB10");

s32 func_001CC9A8(Script* arg0) {
    s32 v = arg0->unk_174[arg0->unk_174[3] + 4];
    s32 i;

    for (i = 0; i < 4; i++) {
        if (v == D_003854E0_c9.b1030[i]) {
            break;
        }
    }
    if (i < 4 && D_003854E0_c9.b0[i] != 0) {
        func_0010BB10_c9(&D_00629E70_b[i], (s32)func_001CC950);
        D_003854E0_c9.b0[i] = 3;
    }
    arg0->unk_174[3]--;
    return 2;
}

typedef struct { u8 b0[4]; s8 b4[0x100C]; s32 w1010[8]; s8 b1030[4]; } XHumCCA88;
typedef struct { u8 pad[0xB0]; } XHumB0a;
extern XHumB0a D_00629E70_a[] __asm__("D_00629E70");
extern XHumCCA88 D_003854E0_a8 __asm__("D_003854E0");
void func_0010BB10_a(XHumB0a*, s32) __asm__("func_0010BB10");
void func_001CC950();
void func_001CCA88(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_003854E0_a8.b0[i] != 0) {
            func_0010BB10_a(&D_00629E70_a[i], (s32)func_001CC950);
            D_003854E0_a8.b0[i] = 3;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCB18);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCC48);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCEF8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCF78);

extern s32 D_00389C80;
extern void *D_00388480[];
extern u8 D_003C5640[];

typedef struct {
    /* 0x0000 */ u8 pad[0x10];
    /* 0x0010 */ u16 tbl[8][256];
    /* 0x1010 */ s32 cnt[8];
} XGiantMountainQ;

s32 func_001CD2A8(Script* arg0) {
    XGiantMountainQ* g = (XGiantMountainQ*)&D_003854E0;
    s32 k = arg0->unk_174[arg0->unk_174[3] + 3];
    s32 v = arg0->unk_174[arg0->unk_174[3] + 4];

    arg0->unk_174[3] -= 2;
    D_002B8000 = v;
    D_00388480[D_00389C80] = D_003C5640;
    g->tbl[k][g->cnt[k]] = D_00389C80;
    g->cnt[k]++;
    D_00389C80++;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD340);

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001CD4D0_f1_pad1;
extern s32 func_001CD4D0_f1_pad2;

typedef struct { u8 b0[4]; u8 b4[0xC]; u16 tbl[8][256]; s32 w1010[8]; s8 b1030[4]; } XHumCD4D0;
extern XHumCD4D0 D_003854E0_d4 __asm__("D_003854E0");
void func_0010EDA0_d4(XHumB0*, void*, void (*)()) __asm__("func_0010EDA0");
void func_001CD8E8();

s32 func_001CD4D0(Script* arg0) {
    s32 k;
    s32 v;
    s32 i;

    if (D_00375BC0 & 1) {
        arg0->unk_174[3] -= 2;
        return 2;
    }
    k = arg0->unk_174[arg0->unk_174[3] + 3];
    v = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    D_003854E0_d4.tbl[k][D_003854E0_d4.w1010[k]++] = v;
    for (i = 0; i < 4; i++) {
        if (k == D_003854E0_d4.b1030[i]) {
            break;
        }
    }
    if (i < 4 && D_003854E0_d4.b0[i] == 4) {
        D_003854E0_d4.b0[i] = 2;
        D_003854E0_d4.b4[k] = 2;
        func_0010EDA0_d4(&D_00629E70_b[i], D_00388480[v], func_001CD8E8);
    }
    return 2;
}

typedef struct { u8 b0[4]; u8 b4[0xC]; u16 tbl[8][256]; s32 w1010[8]; s8 b1030[4]; } XHumCD620;
extern XHumCD620 D_003854E0_d6 __asm__("D_003854E0");
extern s32 D_003C5890;
void func_0010EDA0_d6(XHumB0*, void*, void (*)()) __asm__("func_0010EDA0");
void func_001CCB18();

void func_001CD620(s32 a0, XHumB0* a1) {
    s32 i;
    XHumB0* p;
    s32 k;

    D_003C5890 = 0;
    for (i = 0; i < 4; i++) {
        p = &D_00629E70_b[i];
        if (p == a1) {
            k = D_003854E0_d6.b1030[i];
            if (D_003854E0_d6.w1010[k] == 0) {
                func_0010BB10_c9(p, (s32)func_001CC950);
            } else {
                D_003854E0_d6.b0[i] = 2;
                D_003854E0_d6.b4[k] = 2;
                func_0010EDA0_d6(p, D_00388480[D_003854E0_d6.tbl[k][a0]], func_001CCB18);
            }
        }
    }
}

typedef struct { u64 d[0x16]; } XHumB0Q;
extern XHumB0Q D_00629E70_q[] __asm__("D_00629E70");
extern XHumB0Q D_006298F0_q[] __asm__("D_006298F0");
typedef struct { u8 b0[4]; u8 b4[0x102C]; s8 b1030[4]; } XHumCD738;
extern XHumCD738 D_003854E0_d7 __asm__("D_003854E0");
void func_001CD620();

s32 func_001CD738(Script* arg0) {
    s32 i;
    s32 k;

    if (D_00375BC0 & 1) {
        arg0->unk_174[3]--;
        return 2;
    }
    k = arg0->unk_174[arg0->unk_174[3] + 4];
    for (i = 0; i < 4; i++) {
        if (D_003854E0_d7.b0[i] == 0) {
            break;
        }
    }
    if (i >= 4 || D_003854E0_d7.b4[k] != 0) {
        return 4;
    }
    arg0->unk_174[3]--;
    D_00629E70_q[i] = D_006298F0_q[k];
    D_003854E0_d7.b1030[i] = k;
    func_0010BB50(&D_00629E70_q[i], func_001CD620);
    D_003854E0_d7.b0[i] = 1;
    D_003854E0_d7.b4[k] = 1;
    return 2;
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001CD8E8_f1_pad1;
typedef struct { u8 b0[4]; u8 b4[0xC]; u16 tbl[8][256]; s32 w1010[8]; s8 b1030[4]; } XHumCD8E8;
extern XHumCD8E8 D_003854E0_d8 __asm__("D_003854E0");
extern s32 D_003C5890;
void func_0010EDA0_d8(XHumB0*, void*, void (*)()) __asm__("func_0010EDA0");

void func_001CD8E8(s32 a0, XHumB0* a1) {
    s32 i;
    XHumB0* p;
    s32 k;

    D_003C5890 = a0;
    for (i = 0; i < 4; i++) {
        p = &D_00629E70_b[i];
        if (p == a1) {
            k = D_003854E0_d8.b1030[i];
            if (D_003854E0_d8.w1010[k] == a0) {
                D_003854E0_d8.b0[i] = 4;
                D_003854E0_d8.b4[k] = 4;
            } else {
                D_003854E0_d8.b0[i] = 2;
                D_003854E0_d8.b4[k] = 2;
                func_0010EDA0_d8(p, D_00388480[D_003854E0_d8.tbl[k][a0]], (void (*)())func_001CD8E8);
            }
        }
    }
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001CDA00_f1_pad1;
extern s32 func_001CDA00_f1_pad2;
extern s32 func_001CDA00_f1_pad3;
void func_001CDA00(s32 a0, XHumB0* a1) {
    s32 i;
    XHumB0* p;
    s32 k;

    D_003C5890 = 0;
    for (i = 0; i < 4; i++) {
        p = &D_00629E70_b[i];
        if (p == a1) {
            k = D_003854E0_d8.b1030[i];
            if (D_003854E0_d8.w1010[k] == 0) {
                D_003854E0_d8.b0[i] = 4;
                D_003854E0_d8.b4[k] = 4;
            } else {
                D_003854E0_d8.b0[i] = 2;
                D_003854E0_d8.b4[k] = 2;
                func_0010EDA0_d8(p, D_00388480[D_003854E0_d8.tbl[k][a0]], (void (*)())func_001CD8E8);
            }
        }
    }
}

typedef struct { u64 d[0x16]; } XHumB0Qb;
extern XHumB0Qb D_00629E70_qb[] __asm__("D_00629E70");
extern XHumB0Qb D_006298F0_qb[] __asm__("D_006298F0");
typedef struct { u8 b0[4]; u8 b4[0x102C]; s8 b1030[4]; } XHumCDB18;
extern XHumCDB18 D_003854E0_db __asm__("D_003854E0");

s32 func_001CDB18(Script* arg0) {
    s32 i;
    s32 k;

    if (D_00375BC0 & 1) {
        arg0->unk_174[3]--;
        return 2;
    }
    k = arg0->unk_174[arg0->unk_174[3] + 4];
    for (i = 0; i < 4; i++) {
        if (D_003854E0_db.b0[i] == 0) {
            break;
        }
    }
    if (i >= 4 || D_003854E0_db.b4[k] != 0) {
        return 4;
    }
    arg0->unk_174[3]--;
    D_00629E70_qb[i] = D_006298F0_qb[k];
    D_003854E0_db.b1030[i] = k;
    func_0010BB50(&D_00629E70_qb[i], func_001CDA00);
    D_003854E0_db.b0[i] = 1;
    D_003854E0_db.b4[k] = 1;
    return 2;
}

typedef struct {
    s16 unk_00;
    char unk_02[0xAE];
} UnkB0;

extern UnkB0 D_006298F4[];
extern UnkB0 D_006298F6[];
extern UnkB0 D_006298F8[];
extern UnkB0 D_006298FC[];
extern UnkB0 D_006298FE[];

s32 func_001CDCC8(Script* arg0) {
    D_006298F6[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001CDD18(Script* arg0) {
    D_006298F8[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

typedef struct {
    f32 unk_00;
    char unk_04[0xAC];
} UnkB0f;

extern UnkB0f D_0062990C[];
extern UnkB0f D_00629984[];

s32 func_001CDD68(Script* arg0) {
    D_0062990C[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

// 0xB0-byte records, accessed as f32 words
extern f32 D_006298F0[][44];

s32 func_001CDDB8(Script* arg0) {
    D_006298F0[arg0->unk_174[arg0->unk_174[3] + 2]][12] = arg0->unk_174[arg0->unk_174[3] + 3];
    D_006298F0[arg0->unk_174[arg0->unk_174[3] + 2]][13] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001CDE20(Script* arg0) {
    D_006298F0[arg0->unk_174[arg0->unk_174[3] + 2]][16] = arg0->unk_174[arg0->unk_174[3] + 3];
    D_006298F0[arg0->unk_174[arg0->unk_174[3] + 2]][17] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001CDE88(Script* arg0) {
    D_006298F4[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001CDED8(Script* arg0) {
    D_006298FC[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001CDF28(Script* arg0) {
    D_006298FE[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001CDF78(Script* arg0) {
    D_00629984[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

/* Unused on purpose: keeps fm_func_001DC9A0 / func_001DDC08 matching (notes/f1.md F1). */
extern s32 func_001CDFC8_f1_pad1;
extern XHumCC9A8 D_003854E0_df __asm__("D_003854E0");
s32 func_001CDFC8(Script* arg0) {
    s32 i;

    if (D_00375BC0 & 1) {
        return 2;
    }
    for (i = 0; i < 4; i++) {
        if (D_003854E0_df.b0[i] != 0 && D_003854E0_df.b1030[i] != 7) {
            break;
        }
    }
    if (i < 4 && !((s32)(*(u64*)&arg0->unk_00[0x328] >> 4) & 1)) {
        return 4;
    }
    return 2;
}

s32 func_001CE060(Script* arg0) {
    u8 val = D_003854E0.unk_01[arg0->unk_174[arg0->unk_174[3] + 4] + 3];

    if (val != 0 && val != 4) {
        return 4;
    }
    arg0->unk_174[3]--;
    return 2;
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001CE0A0_f1_pad1;
extern s32 func_001CE0A0_f1_pad2;
typedef struct { u8 pad[0x30]; f32 unk_30; f32 unk_34; u8 unk_38[0x78]; } XHumB0e;
extern XHumB0e D_00629E70_e[] __asm__("D_00629E70");

s32 func_001CE0A0(Script* arg0) {
    s32 s = arg0->unk_174[arg0->unk_174[3] + 2];
    s32 x = arg0->unk_174[arg0->unk_174[3] + 3];
    s32 y = arg0->unk_174[arg0->unk_174[3] + 4];
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_003854E0_df.b0[i] == 2 && s == D_003854E0_df.b1030[i]) {
            break;
        }
    }
    if (i < 4) {
        XHumB0e* p = &D_00629E70_e[i];
        p->unk_30 = x;
        D_00629E70_e[i].unk_34 = y;
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001CE188(Script* arg0) {
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CE1A0);

s32 func_001CE738(void) {
    func_0017FED8();
    return 2;
}

extern void *D_00388480[];   /* same array as above (merge of fm-a1 and fm-a2): pointer type, cast at use */
s32 func_0010EEC8(s32);

s32 func_001CE758(Script* arg0) {
    s32 i = arg0->unk_174[arg0->unk_174[3] + 1];
    s32 idx = arg0->unk_174[arg0->unk_174[3] + 2];
    s32 a = arg0->unk_174[arg0->unk_174[3] + 3];
    s32 b = arg0->unk_174[arg0->unk_174[3] + 4];
    f32 t = func_0010EEC8((s32)D_00388480[idx]);

    D_006298F0[i][16] = t;
    arg0->unk_174[3] -= 4;
    D_006298F0[i][12] = a + t * 12.0f;
    D_006298F0[i][13] = b + D_006298F0[i][17] * 12.0f;
    return 2;
}

// Handle score against Riku on Destiny Island
s32 func_001CE858(Script* arg0) {
    s32 start = arg0->unk_174[3];

    D_003C10B8[arg0->unk_174[start + 3]] = arg0->unk_174[start + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001CB130);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001CB1A8);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001CB1F0);
#endif

#ifdef VERSION_FM
// one 0xB0-byte record of D_006298F0, copied whole
typedef struct {
    u64 unk_00[22];
} Unk6298F0;

Unk6298F0 fm_func_001CCD30(s32 arg0) {
    return *(Unk6298F0*)D_006298F0[arg0];
}
#endif

#ifdef VERSION_FM
extern UnkB0f D_00629920[];

s32 fm_func_001CCDA8(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = D_00629920[arg0->unk_174[arg0->unk_174[3] + 4]].unk_00;
    return 2;
}
#endif

#ifdef VERSION_FM
extern UnkB0f D_00629924[];

s32 fm_func_001CCDF0(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = D_00629924[arg0->unk_174[arg0->unk_174[3] + 4]].unk_00;
    return 2;
}
#endif

void func_001CE898(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] += arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE8D0(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] -= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE908(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = -arg0->unk_174[arg0->unk_174[3] + 4];
}

void func_001CE928(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] *= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE960(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] /= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE9A0(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] %= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CE9E0(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] == arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEA18(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 5] < arg0->unk_174[arg0->unk_174[3] + 4];
}

void func_001CEA50(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] < arg0->unk_174[arg0->unk_174[3] + 5] ^ 1;
}

void func_001CEA88(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] < arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEAC0(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 5] < arg0->unk_174[arg0->unk_174[3] + 4] ^ 1;
}

void func_001CEAF8(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = arg0->unk_174[arg0->unk_174[3] + 4] != arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEB30(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] &= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEB68(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] |= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEBA0(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] ^= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEBD8(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = ~arg0->unk_174[arg0->unk_174[3] + 4];
}

void func_001CEBF8(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] >>= arg0->unk_174[arg0->unk_174[3] + 5];
}

void func_001CEC30(Script* arg0) {
    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] <<= arg0->unk_174[arg0->unk_174[3] + 5];
}

s32 func_001CEC68(UNK_PTR arg0, s32 arg1) {
    D_003C10D8[arg1](arg0);
    return 2;
}

extern s32 D_003DABD0[];

void func_001CEC98(void) {
    D_003DABD0[0] = func_00155ED8(0x34, 4);
    D_003DABD0[1] = func_00155ED8(0x38, 4);
}

typedef struct {
    /* 0x000 */ u8 unk_000[0x180];
    /* 0x180 */ s32 top;
    /* 0x184 */ s32 stack[92];
    /* 0x2F4 */ f32 unk_2F4;
    /* 0x2F8 */ u8 unk_2F8[0x30];
    /* 0x328 */ u64 unk_328_0 : 2;
    u64 unk_328_2 : 1;
    u64 unk_328_3 : 11;
    u64 unk_328_14 : 1;
    u64 unk_328_15 : 49;
    /* 0x330 */ f32 unk_330;
} ScriptX;

s32 func_001CECE0(Script* arg0) {
    ScriptX* x = (ScriptX*)arg0;

    x->unk_328_2 = 1;
    x->unk_2F4 = x->stack[x->top] * 2.0f;
    x->top--;
    return 6;
}

s32 func_001CED20(Script* arg0) {
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CED38);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CF070);

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[6];
} ScriptMsg;

s32 func_001C4640(ScriptMsg*);

s32 func_001CF128(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 5;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001CF1B0(void) {
    return 2;
}

s32 func_001CF1B8(void) {
    D_00375BC0 |= 2;
    func_00133538();
    return 2;
}

void func_001C6720(void);

s32 func_001CF1E8(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 0;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    func_001C6720();
    D_003854E0.unk_3078 |= 0x400;
    return 2;
}

s32 func_001CF250(void) {
    return 2;
}

s32 fm_func_0011E340(s32);

s32 func_001CF258(void) {
    if (fm_func_0011E340(0) == 0) {
        D_00375BC0 &= ~2;
        return 2;
    }
    return 4;
}

s32 func_001CF2A0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 1;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    D_003854E0.unk_3070 &= ~0x2000000000;
    D_003854E0.unk_3078 &= ~0x400;
    return 2;
}

s32 func_001CF320(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = (*(f32**)&arg0->unk_00[4])[0x10 / 4];
    return 2;
}

s32 func_001CF350(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = (*(f32**)&arg0->unk_00[4])[0x14 / 4];
    return 2;
}

s32 func_001CF380(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = (*(f32**)&arg0->unk_00[4])[0x18 / 4];
    return 2;
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgG;

s32 func_001CF3B0(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 3;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    msg.unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001CF458(Script* arg0) {
    u64 flags = *(u64*)&arg0->unk_00[0x328];

    if (!(flags & 0xA41) || ((s32)(flags >> 4) & 1)) {
        return 2;
    }
    return 4;
}

s32 func_001CF488(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 6;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001CF4D0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 7;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001CF518(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 8;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001CF560(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 9;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001CF5A8(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 10;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001CF5F0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 11;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001CF638(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 12;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3]--;
    return 2;
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgV;


s32 func_001CF6C8(Script* arg0) {
    ScriptMsgV msg;

    msg.unk_00 = 0xF;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    return 2;
}

s32 func_001CF728(Script* arg0) {
    ScriptMsgV msg;

    msg.unk_00 = 0x10;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    return 2;
}

void func_00106578(s32);

s32 func_001CF788(Script* arg0) {
    func_00106578(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

void func_00106690(s32);

s32 func_001CF7D0(Script* arg0) {
    func_00106690(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

void func_00106880(s32);

s32 func_001CF818(Script* arg0) {
    func_00106880(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

void func_00106790(s32);

s32 func_001CF860(Script* arg0) {
    func_00106790(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern s32 D_002BC080[];
extern s32 D_002BC09C;
extern f32 D_002BC098;

s32 func_001CF8A8(void) {
    D_002B834C = 1;
    D_002BC080[0] = 0x80;
    D_002BC080[1] = 0x80;
    D_002BC080[2] = 0x80;
    D_002BC080[3] = 0x40;
    D_002BC090 = 0x100;
    D_002BC094 = 0xC0;
    D_002BC098 = 0.0f;
    D_002BC09C = 1;
    D_002BC0A0 = 0;
    D_002BC0A4 = 0;
    return 2;
}

s32 func_001CF918(void) {
    if (D_002B834C == 1) {
        D_002B834C = 4;
    }
    return 2;
}

s32 func_001CF940(void) {
    D_002B834C = 0;
    func_001ED878(0);
    func_00242BD0();
    return 2;
}

/* Unused on purpose: without one more declaration here func_001DB7A8 loses its %lo folding (notes/f1.md F1). */
extern s32 func_001CF970_f1_pad;

s32 func_001CF970(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 0x11;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 3];
    msg.unk_04 = *(s32*)arg0->unk_00;
    *(f32*)&msg.unk_08[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_001C4640(&msg);
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_00112810(s32, s32, s32, s32);

s32 func_001CFA08(Script* arg0) {
    s32 a = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 b = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 c = arg0->unk_174[arg0->unk_174[3]-- + 4];

    func_00112810(c, b, a, -1);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

s32 func_001CFA90(Script* arg0) {
    s32 a = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 b = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 c = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 d = arg0->unk_174[arg0->unk_174[3]-- + 4];

    func_00112810(d, c, b, a);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

void* func_00112848(s32, s32, s32, s32);

s32 func_001CFB28(Script* arg0) {
    s32 a = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 b = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 c = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 d = arg0->unk_174[arg0->unk_174[3]-- + 4];

    func_00112848(d, c, b, a);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

void func_00112880(s32);

s32 func_001CFBC0(Script* arg0) {
    s32* t = &arg0->unk_174[3];
    s32 v = arg0->unk_174[*t + 4];

    (*t)--;
    func_00112880(v);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

s32 func_001CFC18(Script* arg0) {
    s32 a = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 b = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 c = arg0->unk_174[arg0->unk_174[3]-- + 4];
    s32 d = arg0->unk_174[arg0->unk_174[3]-- + 4];

    func_00112810(d, c, b, a);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

s32 func_001CFCB0(Script* arg0) {
    s32* t = &arg0->unk_174[3];
    s32 v = arg0->unk_174[*t + 4];

    (*t)--;
    func_00112880(v);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

extern s32 D_0038CCCC;
s32 func_001239D8(s32);

s32 func_001CFD08(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001239D8(D_0038CCCC);
    return 2;
}

s32 func_001CFD58(Script* arg0) {
    func_00108180(arg0->unk_174[arg0->unk_174[3]-- + 4]);
    return 2;
}

s32 func_001CFD90(Script* arg0) {
    func_001081A0(arg0->unk_174[arg0->unk_174[3]-- + 4]);
    return 2;
}

s32 func_001CFDC8(Script* arg0) {
    s32 idx = arg0->unk_174[36];

    arg0->unk_174[3]--;
    if (idx >= 0x800) {
        D_00388CC4[idx] = 1;
    }
    return 2;
}

s32 func_001CFE00(Script* arg0) {
    s32 idx = arg0->unk_174[36];

    arg0->unk_174[3]--;
    if (idx >= 0x800) {
        D_00388CC4[idx] = 0;
    }
    return 2;
}

s32 func_001CFE30(Script* arg0) {
    s32 idx = arg0->unk_174[36];

    arg0->unk_174[3]--;
    if (idx >= 0x800) {
        D_00388CC4[idx]++;
    }
    return 2;
}

s32 func_001CFE70(Script* arg0) {
    s32 idx = arg0->unk_174[36];

    arg0->unk_174[3]--;
    if (idx >= 0x800) {
        D_00388CC4[idx]--;
    }
    return 2;
}

f32 func_00177D68(void);

s32 func_001CFEB0(Script* arg0) {
    s32 v = arg0->unk_174[arg0->unk_174[3] + 4];

    arg0->unk_174[arg0->unk_174[3] + 4] = func_00177D68() * v + 0.5f;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CFF30);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0078);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D01D8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0308);

extern s32* D_0038CD3C[];
s32* func_00122AF8(s32, s32, s32);

s32 func_001D0438(Script* arg0) {
    s32 v = arg0->unk_174[arg0->unk_174[3] + 4];
    s32* p = func_00122AF8(2, 0, v);

    D_0038CD3C[v] = p;
    ((f32*)p)[12] = 1.0f;
    ((f32*)p)[13] = 1.0f;
    ((f32*)p)[14] = 1.0f;
    ((f32*)p)[15] = 1.0f;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D04C0(Script* arg0) {
    s32 v = arg0->unk_174[arg0->unk_174[3] + 4];
    s32* p = func_00122AF8(2, 1, v);

    D_0038CD3C[v] = p;
    ((f32*)p)[12] = 1.0f;
    ((f32*)p)[13] = 1.0f;
    ((f32*)p)[14] = 1.0f;
    ((f32*)p)[15] = 1.0f;
    arg0->unk_174[3]--;
    return 2;
}

extern s32* D_0038CD3C[];

s32 func_001D0548(Script* arg0) {
    *D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 3]] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D0590(Script* arg0) {
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[4] = arg0->unk_174[arg0->unk_174[3] + 2];
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[5] = arg0->unk_174[arg0->unk_174[3] + 3];
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[6] = arg0->unk_174[arg0->unk_174[3] + 4];
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[7] = 1.0f;
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D0600(Script* arg0) {
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[8] = arg0->unk_174[arg0->unk_174[3] + 2];
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[9] = arg0->unk_174[arg0->unk_174[3] + 3];
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[10] = arg0->unk_174[arg0->unk_174[3] + 4];
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 1]])[11] = 1.0f;
    arg0->unk_174[3] -= 4;
    return 2;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070;
    /* 0x3078 */ u8 unk_3078[0x20];
    /* 0x3098 */ s32 unk_3098;
    /* 0x309C */ s32 unk_309C;
    /* 0x30A0 */ f32 unk_30A0[3];
    /* 0x30AC */ f32* unk_30AC[1];
} XGiantMountainF;

void func_001D0670(void) {
    XGiantMountainF* g = (XGiantMountainF*)&D_003854E0;
    f32* p;

    if (--g->unk_309C <= 0) {
        g->unk_3070 &= ~0x80000000000;
    }
    p = g->unk_30AC[g->unk_3098];
    p[12] += g->unk_30A0[0];
    p[13] += g->unk_30A0[1];
    p[14] += g->unk_30A0[2];
}

/* Unused on purpose: keeps func_001DB7A8 matching (notes/f1.md F1). */
extern s32 func_001D06F0_f1_pad1;
extern s32 func_001D06F0_f1_pad2;
extern s32 func_001D06F0_f1_pad3;
typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070_0 : 43;
    u64 unk_3070_43 : 1;
    u64 unk_3070_44 : 20;
    /* 0x3078 */ s32 unk_3078;
} XGiantMountain06F0;

s32 func_001D06F0(Script* arg0) {
    XGiantMountainF* g = (XGiantMountainF*)&D_003854E0;
    f32* p;
    f32 r;
    f32 gr;
    f32 b;

    g->unk_3098 = arg0->unk_174[arg0->unk_174[3]];
    p = g->unk_30AC[g->unk_3098];
    g->unk_309C = arg0->unk_174[arg0->unk_174[3] + 4];
    r = arg0->unk_174[arg0->unk_174[3] + 1] / 255.0f;
    gr = arg0->unk_174[arg0->unk_174[3] + 2] / 255.0f;
    b = arg0->unk_174[arg0->unk_174[3] + 3] / 255.0f;
    g->unk_30A0[0] = (r - p[12]) / g->unk_309C;
    g->unk_30A0[1] = (gr - p[13]) / g->unk_309C;
    g->unk_30A0[2] = (b - p[14]) / g->unk_309C;
    if (g->unk_309C == 0) {
        p[12] = r;
        p[13] = gr;
        p[14] = b;
        p[15] = 1.0f;
    } else {
        ((XGiantMountain06F0*)g)->unk_3070_43 = 1;
    }
    arg0->unk_174[3] -= 5;
    return 2;
}

s32 func_001D0828(Script* arg0) {
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 3]])[3] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D0870(Script* arg0) {
    f32 v = arg0->unk_174[arg0->unk_174[3] + 4];

    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 3]])[3] = 1.0 - v / 180.0f;
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_00122B70(s32*);

s32 func_001D0918(Script* arg0) {
    func_00122B70(D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 4]]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D0970(void) {
    func_00104200(16);
    D_003854E0.unk_3078 |= 1;
    return 2;
}

// D_003854E0 seen with a bitfield at 0x3078 (the s32 member keeps the stores ordered against the stack loads)
typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3078];
    /* 0x3078 */ u64 unk_3078_0 : 1;
    u64 unk_3078_1 : 63;
    /* 0x3080 */ s32 unk_3080;
} XGiantMountainB;

s32 func_00104200(s32);

s32 func_001D09A8(Script* arg0) {
    func_00104200(arg0->unk_174[arg0->unk_174[3] + 4]);
    ((XGiantMountainB*)&D_003854E0)->unk_3078_0 = 1;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D0A08(void) {
    func_00104310(16);
    D_003854E0.unk_3078 &= ~1;
    return 2;
}

s32 func_00104310(s32);

s32 func_001D0A40(Script* arg0) {
    func_00104310(arg0->unk_174[arg0->unk_174[3] + 4]);
    ((XGiantMountainB*)&D_003854E0)->unk_3078_0 = 0;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D0AA0(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 0x13;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 2];
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3] + 3];
    msg.unk_10[1] = (f32)arg0->unk_174[arg0->unk_174[3] + 4] * 2;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001D0B50(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 20;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001D0B98(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 0x17;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3]] / 255.0f;
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 1] / 255.0f;
    msg.unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 2] / 255.0f;
    msg.unk_10[3] = arg0->unk_174[arg0->unk_174[3] + 3] * 0.0078125f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 5;
    return 2;
}

s32 func_001D0C98(Script* arg0) {
    ScriptMsgG msg;

    if (*(u8**)&arg0->unk_00[4] != NULL) {
        msg.unk_00 = 0x17;
        msg.unk_01 = (u32)(arg0->unk_174[arg0->unk_174[3] + 4] * 2);
        msg.unk_04 = *(s32*)arg0->unk_00;
        msg.unk_10[0] = (*(u8**)&arg0->unk_00[4])[0x370] * 0.0078125f;
        msg.unk_10[1] = (*(u8**)&arg0->unk_00[4])[0x371] * 0.0078125f;
        msg.unk_10[2] = (*(u8**)&arg0->unk_00[4])[0x372] * 0.0078125f;
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D0D98(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 24;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0DE0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0E78);

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001D0F10_f1_pad1;
extern s32 func_001D0F10_f1_pad2;
extern s32 func_001D0F10_f1_pad3;
extern s32 func_001D0F10_f1_pad4;

extern char D_003C58E0[][256];
extern void* D_003DABD0_p[] __asm__("D_003DABD0");
s32 func_001D0DE0(void);
s32 func_001D0E78(void);
typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070_0 : 33;
    u64 unk_3070_33 : 1;
    u64 unk_3070_34 : 1;
    u64 unk_3070_35 : 29;
    /* 0x3078 */ s32 unk_3078;
} XGiantMountain0F10;
extern XGiantMountain0F10 D_003854E0_0f10 __asm__("D_003854E0");
s32 func_001D0F10(Script* arg0) {
    switch (arg0->unk_174[arg0->unk_174[3] + 3]) {
    case 1:
        D_003DABD0_p[0] = (void*)func_00155ED8(0x34, 4);
        func_00120590(D_003C58E0[arg0->unk_174[arg0->unk_174[3] + 4]], (s32)D_003DABD0_p[arg0->unk_174[arg0->unk_174[3] + 3] - 1], func_001D0DE0, 0);
        D_003854E0_0f10.unk_3070_33 = 1;
        break;
    case 2:
        D_003DABD0_p[1] = (void*)func_00155ED8(0x38, 4);
        func_00120590(D_003C58E0[arg0->unk_174[arg0->unk_174[3] + 4]], (s32)D_003DABD0_p[arg0->unk_174[arg0->unk_174[3] + 3] - 1], func_001D0E78, 0);
        D_003854E0_0f10.unk_3070_34 = 1;
        break;
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

extern char D_003D97E0[][256];

s32 func_001D1068(Script* arg0) {
    switch (arg0->unk_174[arg0->unk_174[3] + 3]) {
    case 1:
        D_003DABD0_p[0] = (void*)func_00155ED8(0x34, 4);
        func_00120590(D_003D97E0[arg0->unk_174[arg0->unk_174[3] + 4]], (s32)D_003DABD0_p[arg0->unk_174[arg0->unk_174[3] + 3] - 1], func_001D0DE0, 0);
        D_003854E0_0f10.unk_3070_33 = 1;
        break;
    case 2:
        D_003DABD0_p[1] = (void*)func_00155ED8(0x38, 4);
        func_00120590(D_003D97E0[arg0->unk_174[arg0->unk_174[3] + 4]], (s32)D_003DABD0_p[arg0->unk_174[arg0->unk_174[3] + 3] - 1], func_001D0E78, 0);
        D_003854E0_0f10.unk_3070_34 = 1;
        break;
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D11C0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1238);

void func_00131500(s32);

s32 func_001D12D0(Script* arg0) {
    s32 b = (s32)(*(u64*)&arg0->unk_00[0x328] >> 7) & 1;

    if (b == 1) {
        func_00131500(*(s32*)&arg0->unk_00[4]);
        *(u64*)&arg0->unk_00[0x328] &= ~0x80;
    }
    return 2;
}

void func_00135978(void*, s32, s32);

s32 func_001D1328(Script* arg0) {
    func_00135978(*(void**)&arg0->unk_00[4], arg0->unk_174[arg0->unk_174[3] + 3],
                  arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001359C0(void*, s32, s32);

s32 func_001D1380(Script* arg0) {
    func_001359C0(*(void**)&arg0->unk_00[4], arg0->unk_174[arg0->unk_174[3] + 3],
                  arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D13D8(Script* arg0) {
    return ((s32)(*(u64*)((u8*)arg0 + 0x328) >> 1) & 1) ? 4 : 2;
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001D13F8_f1_pad1;
extern s32 func_001D13F8_f1_pad2;
extern s32 func_001D13F8_f1_pad3;
extern s32 func_001D13F8_f1_pad4;

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32* unk_004;
    /* 0x008 */ f32 unk_008;
    /* 0x00C */ u8 unk_00C[0x31C];
    /* 0x328 */ u64 unk_328_0 : 1;
    u64 unk_328_1 : 1;
    u64 unk_328_2 : 62;
} ScriptF13;
s32 func_001D13F8(Script* arg0) {
    ScriptMsgG msg;
    f32* o;

    msg.unk_00 = 4;
    msg.unk_01 = (u32)(arg0->unk_174[arg0->unk_174[3] + 4] * 2);
    msg.unk_04 = *(s32*)arg0->unk_00;
    o = *(f32**)&arg0->unk_00[4];
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3] + 1] - o[4];
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 2] - o[5];
    msg.unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 3] - o[6];
    ((ScriptF13*)arg0)->unk_328_1 = 1;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D14F0(void) {
    func_00109B00();
    return 2;
}

s32 func_001D1510(Script* arg0) {
    if (!(D_00375BC0 & 1)) {
        func_00109C50(arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D1568(Script* arg0) {
    return func_00131B08(*(s32*)&arg0->unk_00[4]) ? 2 : 4;
}

s32 func_001D1598(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 27;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001D15E0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 28;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001D1628(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 5;
    msg.unk_01 = (u32)(arg0->unk_174[arg0->unk_174[3] + 4] | 0x10000);
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D16C0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D17D0);

s32 func_001D1878(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 0x13;
    msg.unk_01 = (u32)(arg0->unk_174[arg0->unk_174[3] + 2] | 0x10000);
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3] + 3];
    msg.unk_10[1] = (f32)arg0->unk_174[arg0->unk_174[3] + 4] * 2;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001D1938(void) {
    D_002C1EA8 &= ~8;
    return 2;
}

s32 func_001D1958(void) {
    D_002C1EA8 |= 8;
    return 2;
}

s32 func_001D1978(void) {
    D_002C1EA8 &= ~4;
    D_002C1EA8 &= ~0x8000000;
    return 2;
}

s32 func_001D19A8(void) {
    D_002C1EA8 |= 4;
    return 2;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070;
    /* 0x3078 */ u8 unk_3078[0xB0];
    /* 0x3128 */ s32 unk_3128;
    /* 0x312C */ s32 unk_312C;
} XGiantMountainX;

extern s32 D_002BC080[];

void func_001D19C8(void) {
    if (--((XGiantMountainX*)&D_003854E0)->unk_3128 <= 0) {
        D_003854E0.unk_3070 &= ~0x4000000000;
    }
    D_002BC080[3] += ((XGiantMountainX*)&D_003854E0)->unk_312C;
}

// 0x3070 flags as a bitfield: keeps the flag store ordered against the s32 loads
typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070_0 : 38;
    u64 unk_3070_38 : 1;
    u64 unk_3070_39 : 25;
    /* 0x3078 */ u8 unk_3078[0xB0];
    /* 0x3128 */ s32 unk_3128;
    /* 0x312C */ s32 unk_312C;
} XGiantMountainD;

extern s32 D_002BC08C;

s32 func_001D1A20(Script* arg0) {
    XGiantMountainD* g = (XGiantMountainD*)&D_003854E0;

    g->unk_3128 = arg0->unk_174[arg0->unk_174[3] + 4];
    g->unk_312C = (arg0->unk_174[arg0->unk_174[3] + 3] - D_002BC08C) / g->unk_3128;
    g->unk_3070_38 = 1;
    arg0->unk_174[3] -= 2;
    return 2;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3130];
    /* 0x3130 */ s32 unk_3130;
    /* 0x3134 */ s32 unk_3134;
    /* 0x3138 */ s32 unk_3138;
    /* 0x313C */ s32 unk_313C;
} XGiantMountainC;

void func_001D1A98(void) {
    if (--((XGiantMountainC*)&D_003854E0)->unk_3130 <= 0) {
        D_003854E0.unk_3070 &= ~0x8000000000;
    }
    D_002BC080[0] += ((XGiantMountainC*)&D_003854E0)->unk_3134;
    D_002BC080[1] += ((XGiantMountainC*)&D_003854E0)->unk_3138;
    D_002BC080[2] += ((XGiantMountainC*)&D_003854E0)->unk_313C;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1B10);

s32 func_001D1BD8(Script* arg0) {
    D_002BC090 = (arg0->unk_174[arg0->unk_174[3] + 4] + 0x200) / 2;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D1C10(Script* arg0) {
    D_002BC094 = (arg0->unk_174[arg0->unk_174[3] + 4] + 0x180) / 2;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D1C48(void) {
    D_002C6440[1] |= 4;
    return 2;
}

s32 func_001D1C68(void) {
    D_002C6440[1] &= ~4;
    return 2;
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgF0;

s32 func_001D1C88(Script* arg0) {
    ScriptMsgF0 msg;

    msg.unk_00 = 0x1E;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3] + 1] / 100.0f;
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 2] / 100.0f;
    msg.unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 3] / 100.0f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D1D70(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 0x1F;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = (f32)arg0->unk_174[arg0->unk_174[3] + 2] * 2;
    msg.unk_10[1] = (f32)arg0->unk_174[arg0->unk_174[3] + 3] * 2;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 3;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1E20);

#ifdef VERSION_FM
s32 func_001D1EE0(Script* arg0);
s32 func_001D1EE0(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B8678;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D1EE0(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1EE0);
#else
s32 func_001D1EE0(Script* arg0) {
    s32 val = D_002B8678;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

#ifdef VERSION_FM
s32 func_001D1F08(Script* arg0);
s32 func_001D1F08(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B8680;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D1F08(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1F08);
#else
s32 func_001D1F08(Script* arg0) {
    s32 val = D_002B8680;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

#ifdef VERSION_FM
s32 func_001D1F30(Script* arg0);
s32 func_001D1F30(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B8684;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D1F30(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1F30);
#else
s32 func_001D1F30(Script* arg0) {
    s32 val = D_002B8684;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

s32 func_001D1F58(Script* arg0) {
    func_001055B8((long)arg0->unk_174[arg0->unk_174[3] + 4], 0);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D1FA0(Script* arg0) {
    func_001055B8((long)arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D1FE8(Script* arg0) {
    func_00111408(
        arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]
    );
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001D2040(Script* arg0) {
    func_00106380(
        arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3],
        arg0->unk_174[arg0->unk_174[3] + 4]
    );
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D20A0(Script* arg0) {
    func_00106428(
        arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3],
        arg0->unk_174[arg0->unk_174[3] + 4]
    );
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D2100(void) {
    func_001064E8();
    return 2;
}

s32 func_001D2120(Script* arg0) {
    func_0022F768(1);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D2158(Script* arg0) {
    func_0022F768(1);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D2190(Script* arg0) {
    s32 x = arg0->unk_174[arg0->unk_174[3] + 4];
    s32 i = x / 8;
    s32 sh = 7 - x % 8;

    if (x >= 0xC00) {
        arg0->unk_174[3]--;
        return 2;
    }
    arg0->unk_174[arg0->unk_174[3] + 4] = (((s8*)func_0022F768(1))[i] >> sh) & 1;
    return 2;
}

s32 func_001D2248(void) {
    func_00104200(1);
    D_003854E0.unk_3078 |= 1;
    return 2;
}

s32 func_001D2280(void) {
    func_00104310(1);
    D_003854E0.unk_3078 &= ~1;
    return 2;
}

void func_0013DF40(void*, s32);

s32 func_001D22B8(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_0013DF40(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D2308(Script* arg0) {
    if (D_002E26A0[0] != NULL) {
        func_0013DF40(D_002E26A0[0], arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    if (D_002E26A0[1] != NULL) {
        func_0013DF40(D_002E26A0[1], arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    if (D_002E26A0[2] != NULL) {
        func_0013DF40(D_002E26A0[2], arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D23A8(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_0013DFA0(p);
    }
    return 2;
}

s32 func_001D23D8(void) {
    if (D_002E26A0[0] != NULL) {
        func_0013DFA0(D_002E26A0[0]);
    }
    if (D_002E26A0[1] != NULL) {
        func_0013DFA0(D_002E26A0[1]);
    }
    if (D_002E26A0[2] != NULL) {
        func_0013DFA0(D_002E26A0[2]);
    }
    return 2;
}

#ifdef VERSION_FM
void func_001D2440(void);
void func_001D2440(void) {
    D_003854E0.unk_3078 &= ~0x2000;
    func_F20000(0, 0);
}
#else
void func_001D2440(void) {
    func_F20000(0, 0);
}
#endif

#ifdef VERSION_FM
s32 func_001D2460(void);
extern char D_00490620[];

s32 func_001D2460(void) {
    func_00120590(D_00490620, func_F20000, func_001D2440, NULL);
    D_003854E0.unk_3078 |= 0x2000;
    return 2;
}
#else
s32 func_001D2460(void) {
    func_00120590(D_0048A3A0, func_F20000, func_001D2440, NULL);
    return 2;
}
#endif

s32 func_001D2498(void) {
    D_0041F8BC = 0;
    return 2;
}

s32 func_001D24A8(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(1);
    return 2;
}

s32 func_001D24F0(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(2);
    return 2;
}

s32 func_001D2538(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(4);
    return 2;
}

s32 func_001D2580(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125BB8(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001D25D8(void) {
    D_003854E0.unk_3070 |= 0x10000000000;
    return 8;
}

typedef struct {
    u8 unk_00[0x3034];
    s32 unk_3034;
    s32 unk_3038;
} XHumGM;
void* func_00123880(s32);
s32 func_001C4640(ScriptMsg*);
extern XGiantMountain D_003854E0;
extern Script D_0038D170;
extern Script D_0039A580;
extern u8 D_003C3A70[];
extern s32 D_003C54F0;
extern u8 D_003A7990[];
extern s32 D_003B4D90;
extern s32 D_003A7980;
extern s32 D_0039A570;

s32 func_001D2600(Script* arg0) {
    ScriptMsgG msg;
    s32 i;
    s32 b;

    msg.unk_00 = 0xD;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    if (D_003854E0.unk_316C != 0) {
        for (i = 0; i < D_003C54F0; i++) {
            if (func_00123880(*(s32*)(D_003C3A70 + i * 0x350)) != NULL) {
                msg.unk_04 = *(s32*)(D_003C3A70 + i * 0x350);
                func_001C4640((ScriptMsg*)&msg);
            }
        }
    } else {
      b = (s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1;
      if (b == 1) {
        if (((XHumGM*)&D_003854E0)->unk_3038 == 0) {
            for (i = 0; i < D_003B4D90; i++) {
                if (func_00123880(*(s32*)(D_003A7990 + i * 0x350)) != NULL) {
                    msg.unk_04 = *(s32*)(D_003A7990 + i * 0x350);
                    func_001C4640((ScriptMsg*)&msg);
                }
            }
        } else {
            for (i = 0; i < D_003A7980; i++) {
                if (func_00123880(*(s32*)((u8*)&D_0039A580 + i * 0x350)) != NULL) {
                    msg.unk_04 = *(s32*)((u8*)&D_0039A580 + i * 0x350);
                    func_001C4640((ScriptMsg*)&msg);
                }
            }
        }
    } else if (((XHumGM*)&D_003854E0)->unk_3034 == 0) {
        for (i = 0; i < D_0039A570; i++) {
            if (func_00123880(*(s32*)((u8*)&D_0038D170 + i * 0x350)) != NULL) {
                msg.unk_04 = *(s32*)((u8*)&D_0038D170 + i * 0x350);
                func_001C4640((ScriptMsg*)&msg);
            }
        }
    } else {
        for (i = 0; i < D_003A7980; i++) {
            if (func_00123880(*(s32*)((u8*)&D_0039A580 + i * 0x350)) != NULL) {
                msg.unk_04 = *(s32*)((u8*)&D_0039A580 + i * 0x350);
                func_001C4640((ScriptMsg*)&msg);
            }
        }
    }
    }
    return 2;
}

s32 func_001D2840(Script* arg0) {
    ScriptMsgG msg;
    s32 i;
    s32 b;

    msg.unk_00 = 0xE;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    if (D_003854E0.unk_316C != 0) {
        for (i = 0; i < D_003C54F0; i++) {
            if (func_00123880(*(s32*)(D_003C3A70 + i * 0x350)) != NULL) {
                msg.unk_04 = *(s32*)(D_003C3A70 + i * 0x350);
                func_001C4640((ScriptMsg*)&msg);
            }
        }
    } else {
      b = (s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1;
      if (b == 1) {
        if (((XHumGM*)&D_003854E0)->unk_3038 == 0) {
            for (i = 0; i < D_003B4D90; i++) {
                if (func_00123880(*(s32*)(D_003A7990 + i * 0x350)) != NULL) {
                    msg.unk_04 = *(s32*)(D_003A7990 + i * 0x350);
                    func_001C4640((ScriptMsg*)&msg);
                }
            }
        } else {
            for (i = 0; i < D_003A7980; i++) {
                if (func_00123880(*(s32*)((u8*)&D_0039A580 + i * 0x350)) != NULL) {
                    msg.unk_04 = *(s32*)((u8*)&D_0039A580 + i * 0x350);
                    func_001C4640((ScriptMsg*)&msg);
                }
            }
        }
    } else if (((XHumGM*)&D_003854E0)->unk_3034 == 0) {
        for (i = 0; i < D_0039A570; i++) {
            if (func_00123880(*(s32*)((u8*)&D_0038D170 + i * 0x350)) != NULL) {
                msg.unk_04 = *(s32*)((u8*)&D_0038D170 + i * 0x350);
                func_001C4640((ScriptMsg*)&msg);
            }
        }
    } else {
        for (i = 0; i < D_003A7980; i++) {
            if (func_00123880(*(s32*)((u8*)&D_0039A580 + i * 0x350)) != NULL) {
                msg.unk_04 = *(s32*)((u8*)&D_0039A580 + i * 0x350);
                func_001C4640((ScriptMsg*)&msg);
            }
        }
    }
    }
    return 2;
}

void* func_00123880(s32);

s32 func_001D2A80(Script* arg0) {
    arg0->unk_174[3]++;
    *(void**)&arg0->unk_00[4] = func_00123880(*(s32*)arg0->unk_00);
    if (*(void**)&arg0->unk_00[4] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ u8 unk_004[4];
    /* 0x008 */ f32 unk_008[3];
    /* 0x014 */ f32 unk_014[3];
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ u8 unk_024[0x304];
    /* 0x328 */ u64 unk_328;
} ScriptMv;
double sqrt(double);

void func_001D2AF0(ScriptMv* arg0) {
    ScriptMsgG msg;
    f32 d[3];
    f32 dist = sqrt((arg0->unk_014[0] - arg0->unk_008[0]) * (arg0->unk_014[0] - arg0->unk_008[0]) +
                    (arg0->unk_014[1] - arg0->unk_008[1]) * (arg0->unk_014[1] - arg0->unk_008[1]) +
                    (arg0->unk_014[2] - arg0->unk_008[2]) * (arg0->unk_014[2] - arg0->unk_008[2]));

    if (dist < arg0->unk_020) {
        msg.unk_00 = 3;
        msg.unk_01 = 0;
        msg.unk_04 = arg0->unk_000;
        msg.unk_10[0] = arg0->unk_014[0];
        msg.unk_10[1] = arg0->unk_014[1];
        msg.unk_10[2] = arg0->unk_014[2];
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
        arg0->unk_328 &= ~0x40;
        return;
    }
    msg.unk_00 = 3;
    msg.unk_01 = 0;
    msg.unk_04 = arg0->unk_000;
    msg.unk_10[3] = 1.0f;
    d[0] = (arg0->unk_014[0] - arg0->unk_008[0]) / dist * arg0->unk_020;
    d[1] = (arg0->unk_014[1] - arg0->unk_008[1]) / dist * arg0->unk_020;
    d[2] = (arg0->unk_014[2] - arg0->unk_008[2]) / dist * arg0->unk_020;
    arg0->unk_008[0] += d[0];
    arg0->unk_008[1] += d[1];
    arg0->unk_008[2] += d[2];
    msg.unk_10[0] = arg0->unk_008[0];
    msg.unk_10[1] = arg0->unk_008[1];
    msg.unk_10[2] = arg0->unk_008[2];
    func_001C4640((ScriptMsg*)&msg);
}

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32* unk_004;
    /* 0x008 */ f32 unk_008[3];
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ f32 unk_01C;
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ u8 unk_024[0x15C];
    /* 0x180 */ s32 top;
    /* 0x184 */ s32 stack[92];
    /* 0x2F4 */ u8 unk_2F4[0x34];
    /* 0x328 */ u64 unk_328_0 : 6;
    u64 unk_328_6 : 1;
    u64 unk_328_7 : 57;
} ScriptP;

s32 func_001D2CA0(Script* arg0) {
    ScriptP* x = (ScriptP*)arg0;

    x->unk_328_6 = 1;
    x->unk_020 = arg0->unk_174[arg0->unk_174[3] + 1];
    x->unk_014 = arg0->unk_174[arg0->unk_174[3] + 2];
    x->unk_018 = arg0->unk_174[arg0->unk_174[3] + 3];
    x->unk_01C = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 4;
    x->unk_008[0] = x->unk_004[4];
    x->unk_008[1] = x->unk_004[5];
    x->unk_008[2] = x->unk_004[6];
    return 2;
}

s32 func_001D2D28(Script* arg0) {
    ScriptP* x = (ScriptP*)arg0;

    x->unk_328_6 = 1;
    x->unk_020 = arg0->unk_174[arg0->unk_174[3] + 1] * D_002B8344;
    x->unk_014 = arg0->unk_174[arg0->unk_174[3] + 2];
    x->unk_018 = arg0->unk_174[arg0->unk_174[3] + 3];
    x->unk_01C = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 4;
    x->unk_008[0] = x->unk_004[4];
    x->unk_008[1] = x->unk_004[5];
    x->unk_008[2] = x->unk_004[6];
    return 2;
}

s32 func_001D2DB8(Script* arg0) {
    D_003854E0.unk_3148 |= arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D2DF0(Script* arg0) {
    D_003854E0.unk_3148 &= ~arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D2E30(void) {
    D_002C1EA8 |= 0x10;
    return 2;
}

s32 func_001D2E50(void) {
    D_002C1EA8 &= ~0x10;
    return 2;
}

s32 func_001D2E70(void) {
    D_002A2740 = 1;
    return 2;
}

s32 func_001D2E88(void) {
    D_002A2740 = 0;
    return 2;
}

s32 func_001D2E98(Script* arg0) {
    D_002A2744 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D2EC0(Script* arg0) {
    D_002A2748 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

// INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2EE8);
s32 func_001D2EE8(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C2104;
    return 2;
}

s32 func_001D2F10(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C2024;
    return 2;
}

s32 func_001D2F38(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C2108;
    return 2;
}

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32* unk_004;
    /* 0x008 */ f32 unk_008;
    /* 0x00C */ u8 unk_00C[0x31C];
    /* 0x328 */ u64 unk_328_0 : 1;
    u64 unk_328_1 : 1;
    u64 unk_328_2 : 62;
} ScriptF2F;

s32 func_001D2F60(Script* arg0) {
    ScriptMsgG msg;
    f32* o;
    f32* p;
    s32 k = arg0->unk_174[arg0->unk_174[3] + 3];
    s32* q = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 4;
        o = *(f32**)&arg0->unk_00[4];
        p = *(f32**)&q[1];
        msg.unk_01 = (u32)(k * 2);
        msg.unk_04 = *(s32*)arg0->unk_00;
        msg.unk_10[0] = p[4] - o[4];
        msg.unk_10[1] = p[5] - o[5];
        msg.unk_10[2] = p[6] - o[6];
        ((ScriptF2F*)arg0)->unk_328_1 = 1;
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001D3080(void) {
    D_003854E0.unk_3070 &= ~0x200000000000;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070_0 : 45;
    u64 unk_3070_45 : 1;
    u64 unk_3070_46 : 1;
    u64 unk_3070_47 : 1;
    u64 unk_3070_48 : 1;
    u64 unk_3070_49 : 1;
    u64 unk_3070_50 : 14;
    /* 0x3078 */ s32 unk_3078;
    /* 0x307C */ s32 unk_307C;
    /* 0x3080 */ s32 unk_3080;
    /* 0x3084 */ s32 unk_3084;
    /* 0x3088 */ s32 unk_3088;
    /* 0x308C */ s32 unk_308C;
    /* 0x3090 */ s32 unk_3090;
} XGiantMountainY;

void func_001560F8(s32, void (*)(void));

s32 func_001D30B0(Script* arg0) {
    ((XGiantMountainY*)&D_003854E0)->unk_3070_45 = 1;
    func_001560F8(arg0->unk_174[arg0->unk_174[3] + 4], func_001D3080);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D3118(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 45) & 1) ? 4 : 2;
}

void func_001245F0(s32);
void* func_00123880(s32);

s32 func_001D3138(Script* arg0) {
    func_001245F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    *(void**)&arg0->unk_00[4] = func_00123880(*(s32*)arg0->unk_00);
    arg0->unk_174[3]--;
    return 2;
}

extern s32 D_002BC09C;
extern f32 D_002BC098;

s32 func_001D3198(Script* arg0) {
    D_002BC09C = arg0->unk_174[arg0->unk_174[3] + 3];
    D_002BC098 = arg0->unk_174[arg0->unk_174[3] + 4] * 3.1415928f / 180.0f;
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D3200(Script* arg0) {
    D_002BC0A0 = arg0->unk_174[arg0->unk_174[3] + 3];
    D_002BC0A4 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

double sqrt(double);
extern s32 D_003888C4[];

s32 func_001D3240(Script* arg0) {
    f32 x1 = arg0->unk_174[arg0->unk_174[3] + 1];
    f32 z1 = arg0->unk_174[arg0->unk_174[3] + 2];
    f32 x2 = arg0->unk_174[arg0->unk_174[3] + 3];
    f32 z2 = arg0->unk_174[arg0->unk_174[3] + 4];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1));

    if (arg0->unk_174[36] >= 0x900) {
        D_003888C4[arg0->unk_174[36]] = d;
    }
    arg0->unk_174[3] -= 5;
    return 2;
}

s32 func_001D3300(Script* arg0) {
    f32 x1 = arg0->unk_174[arg0->unk_174[3] + 1];
    f32 z1 = arg0->unk_174[arg0->unk_174[3] + 2];
    f32 x2 = arg0->unk_174[arg0->unk_174[3] + 3];
    f32 z2 = arg0->unk_174[arg0->unk_174[3] + 4];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1));

    arg0->unk_174[3] -= 3;
    arg0->unk_174[arg0->unk_174[3] + 4] = d;
    return 2;
}

s32 func_001D33B8(Script* arg0) {
    f32 x1 = arg0->unk_174[arg0->unk_174[3] - 1];
    f32 y1 = arg0->unk_174[arg0->unk_174[3]];
    f32 z1 = arg0->unk_174[arg0->unk_174[3] + 1];
    f32 x2 = arg0->unk_174[arg0->unk_174[3] + 2];
    f32 y2 = arg0->unk_174[arg0->unk_174[3] + 3];
    f32 z2 = arg0->unk_174[arg0->unk_174[3] + 4];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1) + (y2 - y1) * (y2 - y1));

    if (arg0->unk_174[36] >= 0x900) {
        D_003888C4[arg0->unk_174[36]] = d;
    }
    arg0->unk_174[3] -= 7;
    return 2;
}

s32 func_001D3498(Script* arg0) {
    f32 x1 = arg0->unk_174[arg0->unk_174[3] - 1];
    f32 y1 = arg0->unk_174[arg0->unk_174[3]];
    f32 z1 = arg0->unk_174[arg0->unk_174[3] + 1];
    f32 x2 = arg0->unk_174[arg0->unk_174[3] + 2];
    f32 y2 = arg0->unk_174[arg0->unk_174[3] + 3];
    f32 z2 = arg0->unk_174[arg0->unk_174[3] + 4];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1) + (y2 - y1) * (y2 - y1));

    arg0->unk_174[3] -= 5;
    arg0->unk_174[arg0->unk_174[3] + 4] = d;
    return 2;
}

s32* func_001E98D0(s32, s32);

// object table entry returned by func_001E98D0: +4 points at the object (position at 0x10)
typedef struct {
    s32 unk_00;
    f32* unk_04;
} XHumObjRef;

s32 func_001D3570(Script* arg0) {
    XHumObjRef* a = (XHumObjRef*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 3]);
    XHumObjRef* b = (XHumObjRef*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);
    f32 x1 = a->unk_04[4];
    f32 z1 = a->unk_04[6];
    f32 x2 = b->unk_04[4];
    f32 z2 = b->unk_04[6];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1));

    if (arg0->unk_174[36] >= 0x900) {
        D_003888C4[arg0->unk_174[36]] = d;
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D3668(Script* arg0) {
    s32* a = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 3]);
    s32* b = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);
    f32 x1 = ((f32*)a[1])[4];
    f32 z1 = ((f32*)a[1])[6];
    f32 x2 = ((f32*)b[1])[4];
    f32 z2 = ((f32*)b[1])[6];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (z2 - z1) * (z2 - z1));

    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = d;
    return 2;
}

/* Unused on purpose: keeps func_001DB7A8 matching (notes/f1.md F1). */
extern s32 func_001D3750_f1_pad1;
s32 func_001D3750(Script* arg0) {
    s32* a = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 3]);
    s32* b = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);
    f32 y1 = ((f32*)a[1])[5];
    f32 x1 = ((f32*)a[1])[4];
    f32 z1 = ((f32*)a[1])[6];
    f32 y2 = ((f32*)b[1])[5];
    f32 x2 = ((f32*)b[1])[4];
    f32 z2 = ((f32*)b[1])[6];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));

    if (arg0->unk_174[36] >= 0x900) {
        D_003888C4[arg0->unk_174[36]] = d;
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001D3860(Script* arg0) {
    s32* a = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 3]);
    s32* b = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);
    f32 y1 = ((f32*)a[1])[5];
    f32 x1 = ((f32*)a[1])[4];
    f32 z1 = ((f32*)a[1])[6];
    f32 y2 = ((f32*)b[1])[5];
    f32 x2 = ((f32*)b[1])[4];
    f32 z2 = ((f32*)b[1])[6];
    f32 d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));

    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = d;
    return 2;
}

s32 func_0012CBC0(s32);

s32 func_001D3960(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_0012CBC0(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

void func_00123350(void*, f32, f32, f32);

s32 func_001D39B8(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00123350(p, arg0->unk_174[arg0->unk_174[3] + 4], 0.0f, 1.0f);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D3A20(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00123350(p, arg0->unk_174[arg0->unk_174[3] + 4], 0.0f, 2.0f);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D3A88(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00123350(p, arg0->unk_174[arg0->unk_174[3] + 4], 0.0f, 3.0f);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D3AF0(void) {
    return 2;
}

s32 func_001D3AF8(void) {
    return 2;
}

s32 func_001D3B00(Script* arg0) {
    f32 a[4];
    f32 b[4];
    f32 r[4];
    f32 z;
    f32 ang;
    f32 d;
    f32 e;
    f32 g;
    s32* q = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 1]);

    if (q == NULL) {
        arg0->unk_174[3] -= 3;
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
        return 2;
    }
    z = 0.0f;
    a[0] = ((f32*)q[1])[4];
    a[1] = ((f32*)q[1])[5];
    a[2] = ((f32*)q[1])[6];
    a[3] = 1.0f;
    b[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    b[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    b[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    b[3] = 1.0f;
    func_001E9D00(r, b, a, z);
    ang = ((f32*)q[1])[15] * 180.0f / 3.1415928f;
    arg0->unk_174[3] -= 3;
    if (ang < z) {
        e = ang + 360.0f;
    } else {
        e = ang;
    }
    d = r[1] * 180.0f / 3.1415928f;
    if (d < 0.0f) {
        g = d + 360.0f;
    } else {
        g = d;
    }
    arg0->unk_174[arg0->unk_174[3] + 4] = g - e;
    if (arg0->unk_174[arg0->unk_174[3] + 4] < 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] += 360;
    }
    return 2;
}

s32 func_001D3CF0(Script* arg0) {
    f32 a[4];
    f32 b[4];
    f32 r[4];
    f32 z;
    f32 ang;
    f32 d;
    f32 e;
    f32 g;
    s32* q = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 3]);
    s32* q2 = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);

    if (q == NULL || q2 == NULL) {
        arg0->unk_174[3] -= 1;
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
        return 2;
    }
    z = 0.0f;
    a[0] = ((f32*)q[1])[4];
    a[1] = ((f32*)q[1])[5];
    a[2] = ((f32*)q[1])[6];
    a[3] = 1.0f;
    b[0] = ((f32*)q2[1])[4];
    b[1] = ((f32*)q2[1])[5];
    b[2] = ((f32*)q2[1])[6];
    b[3] = 1.0f;
    func_001E9D00(r, b, a, z);
    ang = ((f32*)q[1])[15] * 180.0f / 3.1415928f;
    arg0->unk_174[3] -= 1;
    if (ang < z) {
        e = ang + 360.0f;
    } else {
        e = ang;
    }
    d = r[1] * 180.0f / 3.1415928f;
    if (d < 0.0f) {
        g = d + 360.0f;
    } else {
        g = d;
    }
    arg0->unk_174[arg0->unk_174[3] + 4] = g - e;
    if (arg0->unk_174[arg0->unk_174[3] + 4] < 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] += 360;
    }
    return 2;
}

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001D0838);
#endif

#ifdef VERSION_FM
void func_001E0D68(s32);

s32 fm_func_001D2468(Script* arg0) {
    func_001E0D68(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif

s32 func_001D3EF0(Script* arg0) {
    func_001E1F78(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D3F38(Script* arg0) {
    func_001E22B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D3F80(Script* arg0) {
    func_001E22F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

#ifndef VERSION_FM
#ifndef VERSION_EU
s32 func_001D3FC8(Script* arg0) {
    func_001E2628(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif
#endif

void func_001E1418(s32, s32);

s32 func_001D4010(Script* arg0) {
    func_001E1418(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001E1438(s32, s32);

s32 func_001D4060(Script* arg0) {
    func_001E1438(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D40B0(Script* arg0) {
    f32 val = arg0->unk_174[arg0->unk_174[3] + 4];

    arg0->unk_174[3]--;
    D_0038CDDC = val / 100.0f;
    return 2;
}

void func_00131C28(void*, f32);

s32 func_001D40F0(Script* arg0) {
    XHumObjRef* a = (XHumObjRef*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);

    if (a->unk_04 != NULL) {
        func_00131C28(a->unk_04, arg0->unk_174[arg0->unk_174[3] + 3] / 100.0f);
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D4190(Script* arg0) {
    arg0->unk_174[3]--;
    return 2;
}

extern f32 D_002BC0F0[];

s32 func_001D41A8(Script* arg0) {
    D_002BC0F0[8] = arg0->unk_174[arg0->unk_174[3] + 3];
    D_002BC0F0[9] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D41F0(Script* arg0) {
    ScriptMsg msg;
    s32* q = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 7;
        msg.unk_01 = 0;
        msg.unk_04 = q[0];
        func_001C4640(&msg);
        msg.unk_00 = 11;
        msg.unk_01 = 0;
        msg.unk_04 = q[0];
        func_001C4640(&msg);
        msg.unk_00 = 0x1C;
        msg.unk_01 = 0;
        msg.unk_04 = q[0];
        func_001C4640(&msg);
        *(u64*)((u8*)q + 0x328) |= 0x100;
    }
    arg0->unk_174[3]--;
    return 2;
}

/* Unused on purpose: keeps func_001DB7A8 matching (notes/f1.md F1). */
extern s32 func_001D42E8_f1_pad;
extern s32 func_001D42E8_f1_pad2;

s32 func_001D42E8(Script* arg0) {
    ScriptMsg msg;
    s32* q = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);

    if (q != NULL) {
        msg.unk_00 = 6;
        msg.unk_01 = 0;
        msg.unk_04 = q[0];
        func_001C4640(&msg);
        msg.unk_00 = 10;
        msg.unk_01 = 0;
        msg.unk_04 = q[0];
        func_001C4640(&msg);
        msg.unk_00 = 0x1B;
        msg.unk_01 = 0;
        msg.unk_04 = q[0];
        func_001C4640(&msg);
        *(u64*)((u8*)q + 0x328) &= ~0x100;
    }
    arg0->unk_174[3]--;
    return 2;
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001D43E0_f1_pad1;

typedef struct { f32 v[4]; } __attribute__((aligned(8))) XHumV4Q;
extern XHumV4Q D_00490630;
void func_001315C0(s32, s32, void*, f32);
void func_0014F9B0(void*, f32*, f32);

s32 func_001D43E0(Script* arg0) {
    XHumV4Q v = D_00490630;
    f32 r[4];
    f32 a[4];
    f32 c[4];
    sceVu0FMATRIX m;

    if (*(void**)&arg0->unk_00[4] != NULL) {
        r[0] = arg0->unk_174[arg0->unk_174[3] + 2] * 3.1415928f / 180.0f;
        r[1] = arg0->unk_174[arg0->unk_174[3] + 3] * 3.1415928f / 180.0f + *(f32*)(*(u8**)&arg0->unk_00[4] + 0x3C);
        r[2] = 0.0f;
        func_001E9FE8(a, r);
        sceVu0UnitMatrix(m);
        sceVu0RotMatrixX(m, m, a[0]);
        sceVu0RotMatrixY(m, m, a[1]);
        sceVu0ApplyMatrix(v.v, m, v.v);
        func_001315C0(*(s32*)&arg0->unk_00[4], 0, c, 0.0f);
        sceVu0AddVector(v.v, c, v.v);
        func_0014F9B0(*(void**)&arg0->unk_00[4], v.v, arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f);
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001D4540(Script* arg0) {
    f32 v[4];

    if (*(void**)&arg0->unk_00[4] != NULL) {
        v[0] = arg0->unk_174[arg0->unk_174[3] + 1];
        v[1] = arg0->unk_174[arg0->unk_174[3] + 2];
        v[2] = arg0->unk_174[arg0->unk_174[3] + 3];
        v[3] = 1.0f;
        func_0014F9B0(*(void**)&arg0->unk_00[4], v, arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f);
    }
    arg0->unk_174[3] -= 4;
    return 2;
}

void func_001315C0(s32, s32, void*, f32);
void func_0014F9B0(void*, f32*, f32);

s32 func_001D45E0(Script* arg0) {
    f32 v[4];
    s32* q = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 3]);

    if (*(void**)&arg0->unk_00[4] != NULL && q != NULL) {
        func_001315C0(q[1], 0, v, 0.0f);
        func_0014F9B0(*(void**)&arg0->unk_00[4], v, arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f);
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_0014FA38(void*, f32);

s32 func_001D4690(Script* arg0) {
    if (*(void**)&arg0->unk_00[4] != NULL) {
        func_0014FA38(*(void**)&arg0->unk_00[4], arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f);
    }
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D46F0);

s32 func_001D4A30(Script* arg0) {
    XGiantMountainY* g = (XGiantMountainY*)&D_003854E0;

    g->unk_3070_47 = 1;
    g->unk_307C = arg0->unk_174[arg0->unk_174[3] + 3] + 0x100;
    g->unk_3080 = arg0->unk_174[arg0->unk_174[3] + 4] + 0xC0;
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D4A98(void) {
    D_003854E0.unk_3070 &= ~0x800000000000;
    return 2;
}

s32 func_001D4AD0(Script* arg0) {
    XGiantMountainY* g = (XGiantMountainY*)&D_003854E0;

    g->unk_3070_48 = 1;
    g->unk_3084 = arg0->unk_174[arg0->unk_174[3] + 3] + 0x100;
    g->unk_3088 = arg0->unk_174[arg0->unk_174[3] + 4] + 0xC0;
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D4B38(void) {
    D_003854E0.unk_3070 &= ~0x1000000000000;
    return 2;
}

s32 func_001D4B70(Script* arg0) {
    func_00111A00((long)arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern s32 D_0038CCC4;
extern Script D_0038D170;
extern Script D_0039A580;
void func_001C3380(Script*, s32);

void func_001D4BB8(void) {
    Script* s = D_0038CCC4 == 0 ? &D_0038D170 : &D_0039A580;

    s->unk_174[3]++;
    s->unk_174[s->unk_174[3] + 4] = 1;
    s->unk_174[3]++;
    s->unk_174[s->unk_174[3] + 4] = 0;
    func_001C3380(s, 2);
}
void func_001D4BB8(); // temp for next function

s32 func_001D4C30(Script* arg0) {
    func_00111B70(arg0->unk_174[arg0->unk_174[3] + 4], func_001D4BB8);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4C80(void) {
    func_00111BD8();
    return 2;
}

s32 func_001D4CA0(void) {
    func_00111BF0();
    return 2;
}

s32 func_001D4CC0(Script* arg0) {
    s32 val = func_00111C08();
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}

s32 func_001D4D00(Script* arg0) {
    func_00111C20(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4D48(Script* arg0) {
    func_00111C38(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4D90(Script* arg0) {
    func_00111C60(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4DD8(Script* arg0) {
    func_00111C50(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4E20(Script* arg0) {
    XGiantMountainY* g = (XGiantMountainY*)&D_003854E0;

    g->unk_3070_49 = 1;
    g->unk_308C = arg0->unk_174[arg0->unk_174[3] + 3] + 0x100;
    g->unk_3090 = arg0->unk_174[arg0->unk_174[3] + 4] + 0xC0;
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D4E88(void) {
    D_003854E0.unk_3070 &= ~0x2000000000000;
    return 2;
}

s32 func_001D4EC0(s32 arg0) {
    D_0038CDE4 = arg0;
    D_00375BC0 |= 8;
    return 2;
}

s32 func_001D4EE8(void) {
    D_00375BC0 &= ~8;
    return 2;
}

void func_001E58C0(s32);

s32 func_001D4F08(Script* arg0) {
    switch (arg0->unk_174[arg0->unk_174[3] + 4]) {
    case 0:
        func_001E58C0(0);
        break;
    case 1:
        func_001E58C0(1);
        break;
    case 2:
        func_001E58C0(2);
        break;
    case 3:
        func_001E58C0(3);
        break;
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4FB0(Script* arg0) {
    func_001E86A0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D4FF8(Script* arg0) {
    s32 val = func_00123880(arg0->unk_174[arg0->unk_174[3] + 3]);
    func_00137230(val, 0, arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001D19E0);
#endif

typedef struct {
    u8 unk_00[0x20];
    u8 unk_20[0x54];
} Unk3010F8Rec;

typedef struct {
    u8 unk_00[6];
    Unk3010F8Rec unk_06[20];
} Unk3010F8Recs;

#ifdef VERSION_FM
s32 fm_func_001D3610(Script* arg0) {
    s32 n = 0;
    s32 top = arg0->unk_174[3];
    s32 v = arg0->unk_174[top + 4];
    s32 i, j, c;

    for (i = 0; i < 4; i++) {
        c = D_003010F8->unk_48E[i];
        if (c < 20) {
            for (j = 0; j < ((u8*)D_003010F8)[c * 0x74 + 0x25]; j++) {
                if (((Unk3010F8Recs*)D_003010F8)->unk_06[c].unk_20[j] == v) {
                    n++;
                }
            }
        }
    }
    n += D_003010F8->unk_492[v + 7];
    arg0->unk_174[arg0->unk_174[3] + 4] = n;
    return 2;
}
#endif

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001D5068_f1_pad1;
extern s32 func_001D5068_f1_pad2;

s32 func_001D5068(Script* arg0) {
    s32 n = 0;
    s32 top = arg0->unk_174[3];
    s32 v = arg0->unk_174[top + 4];
    s32 i, j, c;

    for (i = 0; i < 4; i++) {
        if (i == 3) {
            break;
        }
        c = D_003010F8->unk_48E[i];
        if (c < 20) {
            for (j = 0; j < ((u8*)D_003010F8)[c * 0x74 + 0x25]; j++) {
                if (((Unk3010F8Recs*)D_003010F8)->unk_06[c].unk_20[j] == v) {
                    n++;
                }
            }
        }
    }
    n += D_003010F8->unk_492[v + 7];
    arg0->unk_174[arg0->unk_174[3] + 4] = n;
    return 2;
}

s32 func_001D5128(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003010F8->unk_492[arg0->unk_174[arg0->unk_174[3] + 4] + 7];
    return 2;
}

s32 func_001D5158(Script* arg0) {
    s32 v = D_003010F8->unk_492[arg0->unk_174[arg0->unk_174[3] + 3] + 7] + arg0->unk_174[arg0->unk_174[3] + 4];

    if (v >= 100) {
        D_003010F8->unk_492[arg0->unk_174[arg0->unk_174[3] + 3] + 7] = 99;
    } else if (v < 0) {
        D_003010F8->unk_492[arg0->unk_174[arg0->unk_174[3] + 3] + 7] = 0;
    } else {
        D_003010F8->unk_492[arg0->unk_174[arg0->unk_174[3] + 3] + 7] += arg0->unk_174[arg0->unk_174[3] + 4];
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_00105960(void*, s32);

s32 func_001D51D0(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = func_00105960(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

s32 func_001059D0(f32*);

s32 func_001D5248(Script* arg0) {
    arg0->unk_174[3]++;
    if (D_002E26A0[0] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = func_001059D0(D_002E26A0[0]);
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3040];
    /* 0x3040 */ u8* unk_3040;
    /* 0x3044 */ u8 unk_3044[0x1C];
    /* 0x3060 */ s32* unk_3060;
} XGiantMountainE;

void func_00176BA8(u8*, s32);

s32 func_001D52B0(Script* arg0) {
    u8* p = ((XGiantMountainE*)&D_003854E0)->unk_3040 + ((XGiantMountainE*)&D_003854E0)->unk_3060[arg0->unk_174[arg0->unk_174[3] + 4]];

    if (!(D_00375BC0 & 1)) {
        func_00176BA8(p, 0);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D5328(void) {
    func_00178140(0);
    return 2;
}

s32 func_001D5348(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00135848(p);
    }
    return 2;
}

s32 func_001D5378(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00135870(p);
    }
    return 2;
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgF;

s32 func_001D53A8(Script* arg0) {
    ScriptMsgF msg;
    f32* p = *(f32**)&arg0->unk_00[4];

    if (p != NULL) {
        msg.unk_00 = 3;
        msg.unk_01 = 0;
        msg.unk_04 = *(s32*)arg0->unk_00;
        msg.unk_10[0] = p[0x50 / 4];
        msg.unk_10[1] = p[0x54 / 4];
        msg.unk_10[2] = p[0x58 / 4];
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
    }
    return 2;
}

f32* func_0014F370(void*);

s32 func_001D5420(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_0014F370(p)[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D5480(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_0014F398(p);
    }
    return 2;
}

s32 func_001D54B0(Script* arg0) {
    u8* p = *(u8**)&arg0->unk_00[4];

    if (p != NULL) {
        *(f32*)(*(u8**)(p + 0x130) + 0x18) = arg0->unk_174[arg0->unk_174[3] + 4];
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D54E8(Script* arg0) {
    arg0->unk_174[3]++;
    if (*(u8**)&arg0->unk_00[4] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = *(f32*)(*(u8**)(*(u8**)&arg0->unk_00[4] + 0x130) + 0x18);
    }
    return 2;
}

s32 func_001D5528(Script* arg0) {
    func_0013C768(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D5570(Script* arg0) {
    func_0013C7D0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D55B8(Script* arg0) {
    arg0->unk_174[3]++;
    if (*(u8**)&arg0->unk_00[4] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = *(f32*)(*(u8**)&arg0->unk_00[4] + 0x50);
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

s32 func_001D5608(Script* arg0) {
    arg0->unk_174[3]++;
    if (*(u8**)&arg0->unk_00[4] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = *(f32*)(*(u8**)&arg0->unk_00[4] + 0x54);
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

s32 func_001D5658(Script* arg0) {
    arg0->unk_174[3]++;
    if (*(u8**)&arg0->unk_00[4] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = *(f32*)(*(u8**)&arg0->unk_00[4] + 0x58);
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

s32 func_001D56A8(void) {
    func_00112A50();
    D_003854E0.unk_3070 |= 0x10000000000;
    return 8;
}

s32 func_001D56E8(void) {
    func_0011C540();
    return 2;
}

s32 func_001D5708(void) {
    func_00111198();
    func_0022F808();
    return 2;
}

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001D5730_f1_pad1;

void func_001D5730(ScriptMv* arg0) {
    ScriptMsgG msg;
    f32 d[3];
    f32 dist = sqrt((arg0->unk_014[0] - arg0->unk_008[0]) * (arg0->unk_014[0] - arg0->unk_008[0]) +
                    (arg0->unk_014[1] - arg0->unk_008[1]) * (arg0->unk_014[1] - arg0->unk_008[1]) +
                    (arg0->unk_014[2] - arg0->unk_008[2]) * (arg0->unk_014[2] - arg0->unk_008[2]));

    if (dist < arg0->unk_020 || (D_00375BC0 & 1)) {
        msg.unk_00 = 3;
        msg.unk_01 = 0;
        msg.unk_04 = arg0->unk_000;
        msg.unk_10[0] = arg0->unk_014[0];
        msg.unk_10[1] = arg0->unk_014[1];
        msg.unk_10[2] = arg0->unk_014[2];
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
        arg0->unk_328 &= ~0x200;
        return;
    }
    msg.unk_00 = 3;
    msg.unk_01 = 0;
    msg.unk_04 = arg0->unk_000;
    msg.unk_10[3] = 1.0f;
    d[0] = (arg0->unk_014[0] - arg0->unk_008[0]) / dist * arg0->unk_020;
    d[1] = (arg0->unk_014[1] - arg0->unk_008[1]) / dist * arg0->unk_020;
    d[2] = (arg0->unk_014[2] - arg0->unk_008[2]) / dist * arg0->unk_020;
    arg0->unk_008[0] += d[0];
    arg0->unk_008[1] += d[1];
    arg0->unk_008[2] += d[2];
    msg.unk_10[0] = arg0->unk_008[0];
    msg.unk_10[1] = arg0->unk_008[1];
    msg.unk_10[2] = arg0->unk_008[2];
    func_001C4640((ScriptMsg*)&msg);
}

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32* unk_004;
    /* 0x008 */ f32 unk_008[3];
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ f32 unk_01C;
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ u8 unk_024[0x15C];
    /* 0x180 */ s32 top;
    /* 0x184 */ s32 stack[92];
    /* 0x2F4 */ u8 unk_2F4[0x34];
    /* 0x328 */ u64 unk_328_0 : 9;
    u64 unk_328_9 : 1;
    u64 unk_328_10 : 54;
} ScriptR;
void func_001D5730();

s32 func_001D58F8(Script* arg0) {
    ScriptR* x = (ScriptR*)arg0;

    x->unk_328_9 = 1;
    x->unk_020 = arg0->unk_174[arg0->unk_174[3] + 1] / 50.0f;
    x->unk_014 = arg0->unk_174[arg0->unk_174[3] + 2];
    x->unk_018 = arg0->unk_174[arg0->unk_174[3] + 3];
    x->unk_01C = arg0->unk_174[arg0->unk_174[3] + 4];
    x->unk_008[0] = x->unk_004[4];
    x->unk_008[1] = x->unk_004[5];
    x->unk_008[2] = x->unk_004[6];
    func_001D5730(arg0);
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001D59B8(Script* arg0) {
    s32 idx = arg0->unk_174[arg0->unk_174[3] + 4];
    if (idx < 4) {
        arg0->unk_174[arg0->unk_174[3] + 4] = D_003010F8->unk_48E[idx];
    }
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D59F8(Script* arg0) {
    f32* q = (f32*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[4];
    }
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D5A70(Script* arg0) {
    f32* q = (f32*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[5];
    }
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D5AE8(Script* arg0) {
    f32* q = (f32*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[6];
    }
    return 2;
}


s32* func_001E98D0(s32, s32);

s32 func_001D5B60(Script* arg0) {
    f32* q = (f32*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[0x3C / 4] * 180.0f / 3.1415928f;
    }
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D5C00(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[198];
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D5C68(Script* arg0) {
    f32* q = (f32*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[0x16C / 4] * 0.5f;
    }
    return 2;
}

s32 func_001D5CE8(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)(*(u8**)(*(u8**)&func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1] + 0x6C) + 0x3C);
    return 2;
}

s32 func_001D5D58(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)(*(u8**)(*(u8**)&func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1] + 0x6C) + 0x44);
    return 2;
}

s32 func_001D5DC8(Script* arg0) {
    f32* q = D_002E26A0[arg0->unk_174[arg0->unk_174[3] + 4]];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[4];
    }
    return 2;
}

s32 func_001D5E08(Script* arg0) {
    f32* q = D_002E26A0[arg0->unk_174[arg0->unk_174[3] + 4]];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[5];
    }
    return 2;
}

s32 func_001D5E48(Script* arg0) {
    f32* p = D_002E26A0[arg0->unk_174[arg0->unk_174[3] + 4]];

    if (p != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = p[6];
    }
    return 2;
}

s32 func_001D5E88(Script* arg0) {
    f32* q = func_00123880(D_003010F8->unk_48E[arg0->unk_174[arg0->unk_174[3] + 4]]);

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[0x3C / 4] * 180.0f / 3.1415928f;
    }
    return 2;
}

s32* func_001E9B98(s32, s32);

s32 func_001D5F20(Script* arg0) {
    s32* r = func_001E9B98((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, D_003010F8->unk_48E[arg0->unk_174[arg0->unk_174[3] + 4]]);

    if (r != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = r[0x318 / 4];
    }
    return 2;
}

void* func_00123880(s32);

s32 func_001D5FA0(Script* arg0) {
    f32* q = func_00123880(D_003010F8->unk_48E[arg0->unk_174[arg0->unk_174[3] + 4]]);

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = q[0x16C / 4] * 0.5f;
    }
    return 2;
}

typedef struct {
    /* 0x000 */ u8 unk_000[0x180];
    /* 0x180 */ s32 top;
    /* 0x184 */ s32 stack[92];
    /* 0x2F4 */ f32 unk_2F4;
    /* 0x2F8 */ u8 unk_2F8[0x30];
    /* 0x328 */ u64 unk_328_0 : 1;
    u64 unk_328_1 : 5;
    u64 unk_328_6 : 1;
    u64 unk_328_7 : 2;
    u64 unk_328_9 : 1;
    u64 unk_328_10 : 54;
    /* 0x330 */ f32 unk_330;
} ScriptW;

s32 func_001D6020(Script* arg0) {
    ScriptMsgF msg;

    ((ScriptW*)arg0)->unk_328_0 = 0;
    ((ScriptW*)arg0)->unk_328_6 = 0;
    ((ScriptW*)arg0)->unk_328_9 = 0;
    msg.unk_00 = 0x12;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D60A8);

void func_001007D0(f32);

s32 func_001D63E0(Script* arg0) {
    func_001007D0(arg0->unk_174[arg0->unk_174[3] + 4] * 3.1415928f / 180.0f);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D6450(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3150;
    return 2;
}

s32 func_001D6478(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 0x20;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    msg.unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 3;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6520);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D65D0);

s32* func_001E98D0(s32, s32);

s32 func_00135838(void*);

s32 func_001D6680(Script* arg0) {
    void* q = (void*)func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1];

    if (q != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = func_00135838(q);
    }
    return 2;
}

#ifdef VERSION_FM
s32 func_001D66F8(Script* arg0);
s32 func_001D66F8(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002C1EA8 & 1;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D66F8(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D66F8);
#else
s32 func_001D66F8(Script* arg0) {
    s32 val = D_002C1EA8 & 1;

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

s32 func_001D6728(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)&arg0->unk_00[0x31C];
    return 2;
}

s32 func_001D6750(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)&arg0->unk_00[0x320];
    return 2;
}

s32 func_001D6778(void) {
    ScriptMsg msg;
    u8* p;

    for (p = func_00123620(NULL); p != NULL; p = func_00123620(p)) {
        msg.unk_00 = 7;
        msg.unk_01 = 0;
        msg.unk_04 = *(s32*)(p + 4);
        func_001C4640(&msg);
        msg.unk_00 = 9;
        msg.unk_01 = 0;
        msg.unk_04 = *(s32*)(p + 4);
        func_001C4640(&msg);
    }
    return 2;
}

s32 func_001D6828(void) {
    ScriptMsg msg;
    u8* p;

    for (p = func_00123620(NULL); p != NULL; p = func_00123620(p)) {
        msg.unk_00 = 6;
        msg.unk_01 = 0;
        msg.unk_04 = *(s32*)(p + 4);
        func_001C4640(&msg);
        msg.unk_00 = 8;
        msg.unk_01 = 0;
        msg.unk_04 = *(s32*)(p + 4);
        func_001C4640(&msg);
    }
    return 2;
}

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001D3390);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001D33E0);
#endif

#ifdef VERSION_FM
s32 func_00103988(s32);

s32 fm_func_001D4FC0(Script* arg0) {
    D_002A61F0 = 0;
    func_00103988(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 func_001037C8(s32);

s32 fm_func_001D5010(Script* arg0) {
    D_002A61F0 = 0;
    func_001037C8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 fm_func_001D5060(void) {
    if (--D_0062A210 < 0) {
        D_002A61F0 = 0;
        return 4;
    }
    return 0;
}
#endif

#ifdef VERSION_FM
s32 func_001D68D8(Script* arg0);
s32 func_001D68D8(Script* arg0) {
    D_002A61F0 = 1;
    func_00103988(arg0->unk_174[arg0->unk_174[3] + 4]);
    D_0062A210 = arg0->unk_174[arg0->unk_174[3] + 4];
    func_0011ED30(50000, fm_func_001D5060);
    arg0->unk_174[3]--;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D68D8(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D68D8);
#else
s32 func_001D68D8(Script* arg0) {
    func_001038B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif
#endif

#ifdef VERSION_FM
s32 func_001D6920(Script* arg0);
s32 func_001D6920(Script* arg0) {
    D_002A61F0 = 1;
    func_001037C8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D6920(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6920);
#else
s32 func_001D6920(Script* arg0) {
    func_001037C8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif
#endif

void func_00124CA0(s32);
typedef struct { s32 id; void* p; u8 pad[0x348]; } XHumE350;
s32 func_001D6968(Script* arg0) {
    ScriptX* x = (ScriptX*)arg0;
    s32 i;
    XHumE350* p;
    s32 n;

    func_00124CA0(arg0->unk_174[arg0->unk_174[3] + 4]);
    x->unk_328_2 = 1;
    x->unk_2F4 = 2.0f;
    p = (XHumE350*)&D_0038D170;
    n = D_0039A570;
    for (i = 0; i < n; i++) {
        if (p->id == arg0->unk_174[arg0->unk_174[3] + 4]) {
            p->p = NULL;
        }
        p++;
    }
    p = (XHumE350*)&D_0039A580;
    n = D_003A7980;
    for (i = 0; i < n; i++) {
        if (p->id == arg0->unk_174[arg0->unk_174[3] + 4]) {
            p->p = NULL;
        }
        p++;
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D6A78(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 33;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001D6AC0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 34;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001D6B08(Script* arg0) {
    u32* p = *(u32**)&arg0->unk_00[4];

    if (p != NULL) {
        *p &= ~0x2000000;
    }
    return 2;
}

s32 func_001D6B30(Script* arg0) {
    u32* p = *(u32**)&arg0->unk_00[4];

    if (p != NULL) {
        *p |= 0x2000000;
    }
    return 2;
}

s32 func_001D6B50(Script* arg0) {
    arg0->unk_174[3]++;
    if (*(u8**)&arg0->unk_00[4] != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)(*(u8**)&arg0->unk_00[4] + 0x164);
    }
    return 2;
}

s32* func_001E98D0(s32, s32);

s32 func_001D6B88(Script* arg0) {
    s32* r = func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4]);

    if (r != NULL && r[1] != 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)((u8*)r[1] + 0x164);
    }
    return 2;
}

void func_00141468(void*, s32);

s32 func_001D6C08(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00141468(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

void func_00141668(void*, s32);

s32 func_001D6C58(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00141668(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_00123698();

s32 func_001D6CA8(void) {
    return (func_00123698() <= 0) ? 2 : 4;
}

s32 func_001D6CD8(void) {
    func_0012C990(0, 0);
    return 2;
}

s32 func_001D6D00(void) {
    func_0012C990(0, 1);
    return 2;
}

s32 func_001D6D28(void) {
    func_0012C990(1, 0);
    return 2;
}

s32 func_001D6D50(void) {
    func_0012C990(1, 1);
    return 2;
}

s32 func_001D6D78(void) {
    func_0012C990(2, 0);
    return 2;
}

s32 func_001D6DA0(void) {
    func_0012C990(2, 1);
    return 2;
}

s32 func_001D6DC8(void) {
    func_0012C990(6, 0);
    return 2;
}

s32 func_001D6DF0(void) {
    func_0012C990(6, 1);
    return 2;
}

u8* func_001234A0(u8*);
u8* func_00123620(u8*);

s32 func_001D6E18(Script* arg0) {
    s32 n = 0;
    u8* p;

    for (p = func_001234A0(NULL); p != NULL; p = func_00123620(p)) {
        if (func_001239D8(*(s32*)(p + 4)) == 0xCD) {
            n++;
        }
    }
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = n;
    return 2;
}

#ifdef VERSION_FM
s32 func_001D6EA8(Script* arg0);
s32 func_001D6EA8(Script* arg0) {
    arg0->unk_174[3]++;
    if (D_002DED08 == 2) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D6EA8(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6EA8);
#else
s32 func_001D6EA8(Script* arg0) {
    s32 val = D_002DED08;

    arg0->unk_174[3] = arg0->unk_174[3] + 1;
    if (val == 2) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}
#endif
#endif

s32 func_001D6EF0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 37;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

s32 func_001D6F38(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 38;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

void func_0013C638(s32, s32);

s32 func_001D6F80(Script* arg0) {
    func_0013C638(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_0013C6A8(s32);

s32 func_001D6FD0(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_0013C6A8(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001D7028(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_315C;
    return 2;
}

s32 func_001D7050(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3160;
    return 2;
}

s32 func_001D7078(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3164;
    return 2;
}

s32 func_001D70A0(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3168;
    return 2;
}

typedef struct {
    u8 unk_0000[0x3158];
    s32 unk_3158;
} XHumGM3158;
void func_00124CA0(s32);

s32 func_001D70C8(void) {
    s32 i;
    s32* p;
    s32 n;

    func_00124CA0(((XHumGM3158*)&D_003854E0)->unk_3158);
    p = (s32*)&D_0038D170;
    n = D_0039A570;
    for (i = 0; i < n; i++) {
        if (p[0] == ((XHumGM3158*)&D_003854E0)->unk_3158) {
            p[1] = 0;
        }
        p = (s32*)((u8*)p + 0x350);
    }
    p = (s32*)&D_0039A580;
    n = D_003A7980;
    for (i = 0; i < n; i++) {
        if (p[0] == ((XHumGM3158*)&D_003854E0)->unk_3158) {
            p[1] = 0;
        }
        p = (s32*)((u8*)p + 0x350);
    }
    return 2;
}

s32 func_001D7178(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_0038CDE8;
    return 2;
}

s32 func_001D71A0(void) {
    ScriptMsgG msg;
    u8* p;

    msg.unk_00 = 0xE;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (((*(u64*)(p + 0x370) >> 37) & 3) == 2) {
            msg.unk_04 = *(s32*)(p + 4);
            func_001C4640((ScriptMsg*)&msg);
        }
    }
    return 2;
}

s32 func_001D7250(void) {
    ScriptMsgG msg;
    u8* p;

    msg.unk_00 = 0xD;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (((*(u64*)(p + 0x370) >> 37) & 3) == 2) {
            msg.unk_04 = *(s32*)(p + 4);
            func_001C4640((ScriptMsg*)&msg);
        }
    }
    return 2;
}

void func_0013C778(s32, s32, s32);

s32 func_001D7300(Script* arg0) {
    func_0013C778(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 3;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D7358);

s32 func_001D76F0(Script* arg0) {
    D_002B8348 = arg0->unk_174[arg0->unk_174[3] + 4] / 100.0f;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7730(Script* arg0) {
    D_002A6200 = arg0->unk_174[arg0->unk_174[3] + 4] / 100.0f;
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7770(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3170;
    return 2;
}

s32 func_001D7798(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3174;
    return 2;
}

s32 func_001D77C0(Script* arg0) {
    D_003854E0.unk_3170 = arg0->unk_174[arg0->unk_174[3] + 3];
    D_003854E0.unk_3174 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D7808(Script* arg0) {
    func_0014EE50(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7850(Script* arg0) {
    func_0014EE78(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7898(void) {
    int i = 1;
    int j;

    while (i < 0x20) {
        j = i + 1;
        func_0014EE50(i);
        i = j;
    }
    return 2;
}

s32 func_001D78D8(void) {
    int i = 1;
    int j;

    while (i < 0x20) {
        j = i + 1;
        func_0014EE78(i);
        i = j;
    }
    return 2;
}

s32 func_001D7918(Script* arg0) {
    D_002B8000 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7940(Script* arg0) {
    s32 i;
    s32 n = 0;
    u8* p = D_003010F8->unk_48E;

    for (i = 3; i >= 0; i--) {
        n += *p++ < 20;
    }
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = n;
    return 2;
}

s32 func_001D7998(Script* arg0) {
    func_001452E0(0, arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D79E0(Script* arg0) {
    func_001452E0(1, arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7A28(void) {
    func_00145398();
    return 2;
}

s32 func_001D7A48(void) {
    func_00112B60();
    return 2;
}

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04[0xC];
    /* 0x10 */ f32 unk_10[3];
    /* 0x1C */ u8 unk_1C[4];
    /* 0x20 */ f32 unk_20[3];
    /* 0x2C */ u8 unk_2C[4];
} XHumRec30;

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3178];
    /* 0x3178 */ s32 unk_3178;
    /* 0x317C */ u8 unk_317C[4];
    /* 0x3180 */ XHumRec30 unk_3180[1];
} XGiantMountainR7;

s32 func_001D7A68(Script* arg0) {
    XGiantMountainR7* g = (XGiantMountainR7*)&D_003854E0;
    s32 n = g->unk_3178;

    g->unk_3180[n].unk_00 = arg0->unk_174[arg0->unk_174[3] - 2];
    g->unk_3180[n].unk_10[0] = arg0->unk_174[arg0->unk_174[3] - 1];
    g->unk_3180[n].unk_10[1] = arg0->unk_174[arg0->unk_174[3]];
    g->unk_3180[n].unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 1];
    g->unk_3180[n].unk_20[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    g->unk_3180[n].unk_20[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    g->unk_3180[n].unk_20[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    g->unk_3178++;
    arg0->unk_174[3] -= 7;
    return 2;
}

s32 func_001D7B60(Script* arg0) {
    s32 n = 0;
    u8* p;

    for (p = func_001234A0(NULL); p != NULL; p = func_00123620(p)) {
        if (func_001239D8(*(s32*)(p + 4)) == arg0->unk_174[arg0->unk_174[3] + 4]) {
            n++;
        }
    }
    arg0->unk_174[arg0->unk_174[3] + 4] = n;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D7C00);

void func_00141B10(s32, s32*);

s32 func_001D7D10(Script* arg0) {
    s32 buf[60];

    func_00141B10(arg0->unk_174[arg0->unk_174[3] + 4], buf);
    arg0->unk_174[arg0->unk_174[3] + 4] = buf[15];
    return 2;
}

s32 func_001D7D70(Script* arg0) {
    s32 buf[60];

    func_00141B10(arg0->unk_174[arg0->unk_174[3] + 4], buf);
    arg0->unk_174[arg0->unk_174[3] + 4] = buf[17];
    return 2;
}

s32 func_001D7DD0(Script* arg0) {
    func_00111580(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

#ifdef VERSION_FM
s32 func_001D7E18(void);
s32 func_001D7E18(void) {
    func_001EAC68();
    func_0024D418();
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001D7E18(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D7E18);
#else
s32 func_001D7E18(void) {
    func_00249F88();
    return 2;
}
#endif
#endif

s32 func_001D7E38(void) {
    if (func_0024A000() == 0) {
        return 4;
    }
    return 2;
}

void func_00104268(f32, f32);

s32 func_001D7E68(Script* arg0) {
    func_00104268(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D7EC8(void) {
    func_00104178();
    return 2;
}

s32 func_001D7EE8(void) {
    func_001009A8();
    return 2;
}

s32 func_001D7F08(void) {
    func_001009D8();
    return 2;
}

s32 func_001D7F28(Script* arg0) {
    func_001807B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D7F70(void) {
    func_00180848();
    return 2;
}

void func_00135A10(void*, s32);

s32 func_001D7F90(Script* arg0) {
    func_00135A10(*(void**)&arg0->unk_00[4], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

void func_00135A38(void*, s32);

s32 func_001D7FD8(Script* arg0) {
    func_00135A38(*(void**)&arg0->unk_00[4], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8020(Script* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8068(Script* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 3);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D80B0(Script* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D80F8(Script* arg0) {
    func_0023E0B0(arg0->unk_174[arg0->unk_174[3] + 4], 0);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8140(void) {
    D_002C1EA8 &= ~0x8000000;
    return 2;
}

s32 func_001D8168(void) {
    D_002C1EA8 |= 0x8000000;
    return 2;
}

s32 func_001D8188(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00105AE0((long)arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001D81E0(Script* arg0) {
    func_00105B38(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D8230(void) {
    func_001116A8();
    return 2;
}

s32 func_001D8250(void) {
    func_001116B8();
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8270);

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
} Unk2C5AD0;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 unk_0C[0x24];
    /* 0x30 */ s32 unk_30[15];
    /* 0x6C */ f32 unk_6C;
} Unk2C5BB0;

extern Unk2C5AD0 D_002C5AD0;
extern Unk2C5BB0 D_002C5BB0;

s32 func_001D8380(void) {
    if (!((s32)(*(u64*)D_0038CD00 >> 58) & 1)) {
        return 4;
    }
    D_002C5AD0.unk_04 = 0;
    D_002C5AD0.unk_08 = 0;
    D_002C5BB0.unk_04 = 0;
    D_002C5BB0.unk_08 = 0;
    D_002C5BB0.unk_30[0] = 0;
    D_002C5BB0.unk_30[1] = 0;
    D_002C5BB0.unk_30[2] = 0;
    D_002C5BB0.unk_30[3] = 0;
    D_002C5BB0.unk_30[4] = 0;
    D_002C5BB0.unk_30[5] = 0;
    D_002C5BB0.unk_30[6] = 0;
    D_002C5BB0.unk_30[7] = 0;
    D_002C5BB0.unk_30[8] = 0;
    D_002C5BB0.unk_30[9] = 0;
    D_002C5BB0.unk_30[10] = 0;
    D_002C5BB0.unk_30[11] = 0;
    D_002C5BB0.unk_30[12] = 0;
    D_002C5BB0.unk_30[13] = 0;
    D_002C5BB0.unk_30[14] = 0;
    D_002C5BB0.unk_6C = 0.0f;
    return 0;
}

s32 func_001D8408(void) {
    D_002B9660 = 0;
    return 2;
}

s32 func_001D8418(void) {
    D_002B9660 = 1;
    return 2;
}

s32 func_001D8430(void) {
    D_003854E0.unk_3070 |= 0x800000000000000;
    return 2;
}

s32 func_001D8458(void) {
    D_003854E0.unk_3070 &= ~0x800000000000000;
    return 2;
}

u8* func_001234A0(u8*);
void func_00124CA0(s32);

s32 func_001D8490(void) {
    u8* p;

    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (((s32)(*(u64*)(p + 0x370) >> 37) & 3) == 2) {
            func_00124CA0(*(s32*)(p + 4));
        }
    }
    return 2;
}

#ifdef VERSION_EU
s32 func_001D8500(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8500);
#else
s32 func_001D8500(void) {
    u8* p;

    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (func_001239D8(*(s32*)(p + 4)) >= 300 && func_001239D8(*(s32*)(p + 4)) < 351) {
            func_00124CA0(*(s32*)(p + 4));
        }
    }
    return 2;
}
#endif

void func_00141608(void*, s32);

s32 func_001D8570(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00141608(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D85C0(void) {
    D_002C1EA8 &= ~0x800;
    return 2;
}

s32 func_001D85E0(void) {
    D_002C1EA8 |= 0x800;
    return 2;
}

s32 func_001D8600(void) {
    D_002C1EA8 &= ~0x200;
    return 2;
}

s32 func_001D8620(void) {
    D_002C1EA8 |= 0x200;
    return 2;
}

s32 func_001D8640(void) {
    D_002C1EA8 &= ~0x400;
    return 2;
}

s32 func_001D8660(void) {
    D_002C1EA8 |= 0x400;
    return 2;
}

s32 func_00131DE0(s32, s32);
void func_001245F0(s32);

s32 func_001D8680(Script* arg0) {
    s32 i = -1;

    while ((i = func_00131DE0(i, arg0->unk_174[arg0->unk_174[3] + 4])) != -1) {
        func_001245F0(i);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8700(Script* arg0) {
    arg0->unk_174[3] = arg0->unk_174[3] + 1;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00125B90(1);
    return 2;
}

s32 func_001D8748(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003854E0.unk_3380;
    return 2;
}

s32 func_001D8770(void) {
    D_00388860 = 0;
    return 2;
}

s32 func_001D8780(void) {
    D_002C1EA8 |= 0x1000;
    return 2;
}

s32 func_001D87A0(void) {
    D_002C1EA8 &= ~0x1000;
    return 2;
}

s32 func_001D87C0(Script* arg0) {
    func_001F0A90(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8808(Script* arg0) {
    func_001128F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

#ifdef VERSION_EU
s32 func_001D8850(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8850);
#else
s32 func_001D8850(void) {
    ScriptMsgG msg;
    u8* p;

    msg.unk_00 = 7;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if ((func_001239D8(*(s32*)(p + 4)) >= 0x12C && func_001239D8(*(s32*)(p + 4)) < 0x15F) ||
            (func_001239D8(*(s32*)(p + 4)) >= 0x190 && func_001239D8(*(s32*)(p + 4)) < 0x21C)) {
            msg.unk_04 = *(s32*)(p + 4);
            func_001C4640((ScriptMsg*)&msg);
        }
    }
    return 2;
}
#endif

#ifdef VERSION_EU
s32 func_001D8928(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8928);
#else
s32 func_001D8928(void) {
    ScriptMsgG msg;
    u8* p;

    msg.unk_00 = 6;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if ((func_001239D8(*(s32*)(p + 4)) >= 0x12C && func_001239D8(*(s32*)(p + 4)) < 0x15F) ||
            (func_001239D8(*(s32*)(p + 4)) >= 0x190 && func_001239D8(*(s32*)(p + 4)) < 0x21C)) {
            msg.unk_04 = *(s32*)(p + 4);
            func_001C4640((ScriptMsg*)&msg);
        }
    }
    return 2;
}
#endif

void func_001D8A00(void) {
    D_003854E0.unk_3070 &= ~0x1000000000000000;
}

s32 func_001D8A30(Script* arg0) {
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8A48(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 60) & 1) ? 4 : 2;
}

s32 func_001D8A68(Script* arg0) {
    ScriptMsgF msg;
    f32* p = *(f32**)&arg0->unk_00[4];

    if (p != NULL) {
        msg.unk_04 = *(s32*)arg0->unk_00;
        msg.unk_00 = 0x27;
        msg.unk_01 = 0;
        msg.unk_10[0] = p[4];
        msg.unk_10[1] = p[5] - 20.0f;
        msg.unk_10[2] = p[6];
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
    }
    return 2;
}

s32 func_001D8AF0(Script* arg0) {
    ((ScriptX*)arg0)->unk_328_14 = 1;
    ((ScriptX*)arg0)->unk_330 = arg0->unk_174[arg0->unk_174[3] + 4] * 2.0f;
    arg0->unk_174[3]--;
    return 2;
}

#ifdef VERSION_EU
s32 func_001D8B30(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8B30);
#else
s32 func_001D8B30(Script* arg0) {
    u8* p;
    s32 found = 0;
    f32 best = -1.0f;
    f32 d;

    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if ((func_001239D8(*(s32*)(p + 4)) >= 0x12C && func_001239D8(*(s32*)(p + 4)) < 0x15F) ||
            (func_001239D8(*(s32*)(p + 4)) >= 0x190 && func_001239D8(*(s32*)(p + 4)) < 0x21C)) {
            if (found == 0) {
                found = 1;
                best = func_001E9E58((f32*)(*(u8**)&arg0->unk_00[4] + 0x10), (f32*)(p + 0x10));
            } else {
                d = func_001E9E58((f32*)(*(u8**)&arg0->unk_00[4] + 0x10), (f32*)(p + 0x10));
                if (d < best) {
                    best = d;
                }
            }
        }
    }
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = best;
    return 2;
}
#endif

typedef struct {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} Unk18B;

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3384];
    /* 0x3384 */ Unk18B unk_3384[8];
} XGiantMountainZB;

s32 func_001D8C50(Script* arg0) {
    void* v = *(void**)&arg0->unk_00[4];
    s32 i;

    for (i = 0; i < 8; i++) {
        if (((XGiantMountainZB*)&D_003854E0)->unk_3384[i].unk_00 == NULL || ((XGiantMountainZB*)&D_003854E0)->unk_3384[i].unk_00 == v) {
            ((XGiantMountainZB*)&D_003854E0)->unk_3384[i].unk_00 = v;
            ((XGiantMountainZB*)&D_003854E0)->unk_3384[i].unk_08 = arg0->unk_174[arg0->unk_174[3] + 3];
            ((XGiantMountainZB*)&D_003854E0)->unk_3384[i].unk_10 = arg0->unk_174[arg0->unk_174[3] + 4];
            break;
        }
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

typedef struct {
    /* 0x00 */ void* unk_00;
    /* 0x04 */ u8 unk_04[0x10];
    /* 0x14 */ s32 unk_14;
} Unk18;

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3384];
    /* 0x3384 */ Unk18 unk_3384[8];
} XGiantMountainZ;

s32 func_001D8CD0(Script* arg0) {
    void* v = *(void**)&arg0->unk_00[4];
    s32 i;

    for (i = 0; i < 8; i++) {
        if (((XGiantMountainZ*)&D_003854E0)->unk_3384[i].unk_00 == NULL || ((XGiantMountainZ*)&D_003854E0)->unk_3384[i].unk_00 == v) {
            ((XGiantMountainZ*)&D_003854E0)->unk_3384[i].unk_00 = v;
            ((XGiantMountainZ*)&D_003854E0)->unk_3384[i].unk_14 = arg0->unk_174[arg0->unk_174[3] + 4];
            break;
        }
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D8D38(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_0038D0D4;
    return 2;
}

s32 func_0014E510(s32);

s32 func_001D8D60(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_0014E510(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

void func_001D8DB8(void) {
    D_003854E0.unk_3070 &= ~0x2000000000000000;
}

s32 func_001331D8(s32, s32, void (*)(void));

s32 func_001D8DE8(Script* arg0) {
    if (func_001331D8(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4], func_001D8DB8)) {
        D_003854E0.unk_3070 &= ~((u64)1 << 61);
    } else {
        D_003854E0.unk_3070 |= (u64)1 << 61;
    }
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_0013C108(s32, s32);

s32 func_001D8E90(Script* arg0) {
    func_0013C108(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001D8EE0(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 61) & 1) ? 4 : 2;
}

s32 func_0013C188(s32, s32);
s32 func_00132FE0(s32);

s32 func_001D8F00(Script* arg0) {
    if (func_0013C188(0, arg0->unk_174[arg0->unk_174[3] + 4]) == 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = func_00132FE0(arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    return 2;
}

void func_001D8F80(void) {
    D_003854E0.unk_3070 &= ~0x4000000000000000;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3070];
    /* 0x3070 */ u64 unk_3070_0 : 62;
    u64 unk_3070_62 : 1;
    u64 unk_3070_63 : 1;
    /* 0x3078 */ s32 unk_3078[2];
} XGiantMountainR;

void func_00131F40(s32, void (*)(void));

s32 func_001D8FB0(Script* arg0) {
    if (fm_func_0011E340(0) == 0) {
        ((XGiantMountainR*)&D_003854E0)->unk_3070_62 = 1;
        func_00131F40(arg0->unk_174[arg0->unk_174[3] + 4], func_001D8F80);
    } else {
        return 4;
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D9038(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 62) & 1) ? 4 : 2;
}

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04[0x8];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u8 unk_10[0x8];
} Unk18b;

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3384];
    /* 0x3384 */ Unk18b unk_3384[8];
} XGiantMountainW;

s32 func_001D9058(Script* arg0) {
    s32 v = *(s32*)&arg0->unk_00[4];
    s32 i;

    for (i = 0; i < 8; i++) {
        if (v == ((XGiantMountainW*)&D_003854E0)->unk_3384[i].unk_00) {
            ((XGiantMountainW*)&D_003854E0)->unk_3384[i].unk_0C = arg0->unk_174[arg0->unk_174[3] + 4];
        }
    }
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D90B0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D93B8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D9720);

typedef struct {
    /* 0x000 */ u8 unk_000[0xA80];
    /* 0xA80 */ u8 unk_A80[10];
    /* 0xA8A */ u8 unk_A8A[10];
    /* 0xA94 */ u8 unk_A94[10];
    /* 0xA9E */ u8 unk_A9E[50];
} XCursedBlk1;

s32 func_001D9C28(Script* arg0) {
    XCursedBlk1* p = func_0022F768(1);
    s32 i;

    switch (arg0->unk_174[arg0->unk_174[3] + 4]) {
    case 0:
        for (i = 0; i < 10; i++) {
            if (p->unk_A80[i] == 0) {
                arg0->unk_174[arg0->unk_174[3] + 4] = i + 1;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 10; i++) {
            if (p->unk_A8A[i] == 0) {
                arg0->unk_174[arg0->unk_174[3] + 4] = i + 1;
                break;
            }
        }
        break;
    case 2:
        for (i = 0; i < 10; i++) {
            if (p->unk_A94[i] == 0) {
                arg0->unk_174[arg0->unk_174[3] + 4] = i + 1;
                break;
            }
        }
        break;
    case 3:
        for (i = 0; i < 50; i++) {
            if (p->unk_A9E[i] == 0) {
                arg0->unk_174[arg0->unk_174[3] + 4] = i + 1;
                break;
            }
        }
        break;
    }
    return 2;
}

s32 func_001D9DD0(Script* arg0) {
    func_00156BA0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D9E18(Script* arg0) {
    func_00156B70(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001D9E60(void) {
    D_002C1EA8 &= ~0x8000;
    return 2;
}

s32 func_001D9E88(void) {
    D_002C1EA8 |= 0x8000;
    return 2;
}

s32 func_001D9EA8(Script* arg0) {
    ScriptMsgV msg;

    msg.unk_00 = 0x28;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    return 2;
}

s32 func_001D9F08(Script* arg0) {
    ScriptMsgV msg;

    msg.unk_00 = 0x28;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
    return 2;
}

s32 func_001D9F60(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = *(s32*)&arg0->unk_00[0x324];
    return 2;
}

s32 func_001D9F88(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00158C30(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001D9FE0(void) {
    D_003854E0.unk_3078 |= 1;
    return 2;
}

s32 func_001DA000(void) {
    D_003854E0.unk_3078 &= ~1;
    D_00375BC0 &= ~1;
    D_002B8348 = 1.0;
    D_002C1EA8 &= ~0x400;
    return 2;
}

s32 func_001DA060(Script* arg0) {
    s32 i = -1;

    while ((i = func_00131DE0(i, arg0->unk_174[arg0->unk_174[3] + 4])) != -1) {
        if (func_00123880(i) != NULL) {
            func_00124CA0(i);
        }
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA0F0(Script* arg0) {
    func_0013C1E0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA138(Script* arg0) {
    func_0013C1F0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA180(Script* arg0) {
    func_0013C148(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA1C8(Script* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] != 0) {
        func_0012C990(3, 1);
    } else {
        func_0012C990(3, 0);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA228(Script* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] != 0) {
        func_0012C990(4, 1);
    } else {
        func_0012C990(4, 0);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA288(Script* arg0) {
    if (arg0->unk_174[arg0->unk_174[3] + 4] != 0) {
        func_0012C990(5, 1);
    } else {
        func_0012C990(5, 0);
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA2E8(Script* arg0) {
    func_0014A070(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA330(void) {
    func_00114400();
    return 2;
}

s32 func_001DA350(void) {
    func_00114410();
    return 2;
}

s32 func_001DA370(void) {
    func_00112AD8();
    return 2;
}

s32 func_001DA390(void) {
    if (func_00110EA8() == 2) {
        return 2;
    }
    return 4;
}

s32 func_001DA3C0(Script* arg0) {
    func_00110E38(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA408(void) {
    func_00110E78();
    return 2;
}

s32 func_001DA428(void) {
    if (func_00110EA8() != 4) {
        return 4;
    }
    return 2;
}

s32 func_001DA458(Script* arg0) {
    func_001114B8(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA4A8(Script* arg0) {
    func_001424E8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DA4F0(Script* arg0) {
    func_0013C230(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA540(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_0013C280(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

s32 func_001DA598(Script* arg0) {
    func_00157158(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

void func_001054D0(s32, s32, s32);

s32 func_001DA5E0(Script* arg0) {
    func_001054D0(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001DA638(Script* arg0) {
    func_00105510(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA688(Script* arg0) {
    func_00105560(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DA6D8(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001EF300();
    return 2;
}

s32 func_001DA720(void) {
    func_00112190();
    return 2;
}

s32 func_001DA740(void) {
    func_001121A8();
    return 2;
}

typedef struct {
    /* 0x00 */ f32 v[4];
    /* 0x10 */ s32 a;
    /* 0x14 */ s32 b;
    /* 0x18 */ s32 c;
    /* 0x1C */ s32 d[5];
} __attribute__((aligned(8))) XHumR30b;

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3078];
    /* 0x3078 */ u64 unk_3078_0 : 1;
    u64 unk_3078_1 : 1;
    u64 unk_3078_2 : 62;
    /* 0x3080 */ u8 unk_3080[0x3E0];
    /* 0x3460 */ f32 unk_3460;
    /* 0x3464 */ f32 unk_3464;
    /* 0x3468 */ u8 unk_3468[8];
    /* 0x3470 */ XHumR30b unk_3470;
    /* 0x34A0 */ XHumR30b unk_34A0;
} XGiantMountainA7;
extern XGiantMountainA7 D_003854E0_a7 __asm__("D_003854E0");
extern XHumR30b D_002BC0F0_r7 __asm__("D_002BC0F0");

void func_001DA760(void) {
    f32 t;

    D_003854E0_a7.unk_3464 += D_002B8344;
    if (D_003854E0_a7.unk_3460 < D_003854E0_a7.unk_3464) {
        D_002BC0F0_r7 = D_003854E0_a7.unk_34A0;
        D_003854E0_a7.unk_3078_1 = 0;
        return;
    }
    t = D_003854E0_a7.unk_3464 / D_003854E0_a7.unk_3460;
    D_003854E0_a7.unk_3464 += D_002B8344;
    D_002BC0F0_r7.a = D_003854E0_a7.unk_3470.a + (D_003854E0_a7.unk_34A0.a - D_003854E0_a7.unk_3470.a) * t;
    D_002BC0F0_r7.b = D_003854E0_a7.unk_3470.b + (D_003854E0_a7.unk_34A0.b - D_003854E0_a7.unk_3470.b) * t;
    D_002BC0F0_r7.c = D_003854E0_a7.unk_3470.c + (D_003854E0_a7.unk_34A0.c - D_003854E0_a7.unk_3470.c) * t;
    D_002BC0F0_r7.v[0] = D_003854E0_a7.unk_3470.v[0] + (D_003854E0_a7.unk_34A0.v[0] - D_003854E0_a7.unk_3470.v[0]) * t;
    D_002BC0F0_r7.v[1] = D_003854E0_a7.unk_3470.v[1] + (D_003854E0_a7.unk_34A0.v[1] - D_003854E0_a7.unk_3470.v[1]) * t;
    D_002BC0F0_r7.v[2] = D_003854E0_a7.unk_3470.v[2] + (D_003854E0_a7.unk_34A0.v[2] - D_003854E0_a7.unk_3470.v[2]) * t;
    D_002BC0F0_r7.v[3] = D_003854E0_a7.unk_3470.v[3] + (D_003854E0_a7.unk_34A0.v[3] - D_003854E0_a7.unk_3470.v[3]) * t;
    if (D_003854E0_a7.unk_3460 < D_003854E0_a7.unk_3464) {
        D_002BC0F0_r7 = D_003854E0_a7.unk_34A0;
        D_003854E0_a7.unk_3078_1 = 0;
    }
}

s32 func_001DA940(Script* arg0) {
    D_003854E0_a7.unk_3470 = D_002BC0F0_r7;
    D_003854E0_a7.unk_34A0 = D_002BC0F0_r7;
    D_003854E0_a7.unk_3464 = 0.0f;
    D_003854E0_a7.unk_3460 = arg0->unk_174[arg0->unk_174[3] - 3] * 2.0f;
    D_003854E0_a7.unk_34A0.a = arg0->unk_174[arg0->unk_174[3] - 2];
    D_003854E0_a7.unk_34A0.b = arg0->unk_174[arg0->unk_174[3] - 1];
    D_003854E0_a7.unk_34A0.c = arg0->unk_174[arg0->unk_174[3]];
    D_003854E0_a7.unk_34A0.v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    D_003854E0_a7.unk_34A0.v[1] = arg0->unk_174[arg0->unk_174[3] + 1];
    D_003854E0_a7.unk_34A0.v[2] = arg0->unk_174[arg0->unk_174[3] + 3];
    D_003854E0_a7.unk_34A0.v[3] = arg0->unk_174[arg0->unk_174[3] + 4];
    if (D_003854E0_a7.unk_3460 < 2.0f) {
        D_002BC0F0_r7.a = D_003854E0_a7.unk_34A0.a;
        D_002BC0F0_r7.b = D_003854E0_a7.unk_34A0.b;
        D_002BC0F0_r7.c = D_003854E0_a7.unk_34A0.c;
        D_002BC0F0_r7.v[0] = D_003854E0_a7.unk_34A0.v[0];
        D_002BC0F0_r7.v[1] = D_003854E0_a7.unk_34A0.v[1];
        D_002BC0F0_r7.v[2] = D_003854E0_a7.unk_34A0.v[2];
        D_002BC0F0_r7.v[3] = D_003854E0_a7.unk_34A0.v[3];
        D_003854E0_a7.unk_3078_1 = 0;
    } else {
        D_003854E0_a7.unk_3078_1 = 1;
    }
    arg0->unk_174[3] -= 8;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DAAA8);

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32* unk_004;
    /* 0x008 */ f32 unk_008[3];
    /* 0x014 */ f32 unk_014;
    /* 0x018 */ f32 unk_018;
    /* 0x01C */ f32 unk_01C;
    /* 0x020 */ f32 unk_020;
    /* 0x024 */ f32 unk_024;
    /* 0x028 */ f32 unk_028;
    /* 0x02C */ u8 unk_02C[0x154];
    /* 0x180 */ s32 top;
    /* 0x184 */ s32 stack[92];
    /* 0x2F4 */ u8 unk_2F4[0x34];
    /* 0x328 */ u64 unk_328_0 : 11;
    u64 unk_328_11 : 1;
    u64 unk_328_12 : 52;
} ScriptQ;

/* Unused on purpose: keeps later functions matching (notes/f1.md F1). */
extern s32 func_001DAB88_f1_pad1;

void func_001DAB88(ScriptQ* arg0) {
    ScriptMsgG msg;
    f32 t;

    arg0->unk_028 += D_002B8344;
    if (arg0->unk_024 < arg0->unk_028) {
        msg.unk_00 = 3;
        msg.unk_01 = 0;
        msg.unk_04 = arg0->unk_000;
        msg.unk_10[0] = arg0->unk_014;
        msg.unk_10[1] = arg0->unk_018;
        msg.unk_10[2] = arg0->unk_01C;
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
        arg0->unk_328_11 = 0;
        return;
    }
    t = arg0->unk_028 / arg0->unk_024;
    msg.unk_00 = 3;
    msg.unk_01 = 0;
    msg.unk_04 = arg0->unk_000;
    msg.unk_10[0] = arg0->unk_008[0] + (arg0->unk_014 - arg0->unk_008[0]) * t;
    msg.unk_10[1] = arg0->unk_008[1] + (arg0->unk_018 - arg0->unk_008[1]) * t;
    msg.unk_10[2] = arg0->unk_008[2] + (arg0->unk_01C - arg0->unk_008[2]) * t;
    msg.unk_10[3] = 1.0f;
    func_001C4640((ScriptMsg*)&msg);
}

s32 func_001DACC8(Script* arg0) {
    ScriptQ* x = (ScriptQ*)arg0;

    x->unk_328_11 = 1;
    x->unk_024 = arg0->unk_174[arg0->unk_174[3] + 1] * 2.0f;
    x->unk_014 = arg0->unk_174[arg0->unk_174[3] + 2];
    x->unk_018 = arg0->unk_174[arg0->unk_174[3] + 3];
    x->unk_01C = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 4;
    x->unk_008[0] = x->unk_004[4];
    x->unk_008[1] = x->unk_004[5];
    x->unk_008[2] = x->unk_004[6];
    x->unk_028 = 0.0f;
    return 2;
}

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ f32* unk_004;
    /* 0x008 */ u8 unk_008[0x24];
    /* 0x02C */ f32 unk_02C[3];
    /* 0x038 */ f32 unk_038[3];
    /* 0x044 */ f32 unk_044;
    /* 0x048 */ f32 unk_048;
    /* 0x04C */ u8 unk_04C[0x2DC];
    /* 0x328 */ u64 unk_328_0 : 12;
    u64 unk_328_12 : 1;
    u64 unk_328_13 : 51;
} ScriptAD;

void func_001DAD58(ScriptAD* arg0) {
    arg0->unk_048 += D_002B8344;
    if (arg0->unk_044 < arg0->unk_048) {
        arg0->unk_004[12] = arg0->unk_038[0];
        arg0->unk_004[13] = arg0->unk_038[1];
        arg0->unk_004[14] = arg0->unk_038[2];
        arg0->unk_328_12 = 0;
        return;
    }
    arg0->unk_004[12] = arg0->unk_02C[0] + (arg0->unk_038[0] - arg0->unk_02C[0]) * (arg0->unk_048 / arg0->unk_044);
    arg0->unk_004[13] = arg0->unk_02C[1] + (arg0->unk_038[1] - arg0->unk_02C[1]) * (arg0->unk_048 / arg0->unk_044);
    arg0->unk_004[14] = arg0->unk_02C[2] + (arg0->unk_038[2] - arg0->unk_02C[2]) * (arg0->unk_048 / arg0->unk_044);
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DAE38);

s32 func_001DAF70(void) {
    func_001116F8();
    func_0011C5B8();
    return 6;
}

s32 func_001DAF98(Script* arg0) {
    D_0038D0E0[0] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

void func_00103810(void);
void func_00103280(f32, f32, f32, f32);

s32 func_001DAFC8(Script* arg0) {
    func_00103810();
    func_00103280(arg0->unk_174[arg0->unk_174[3] + 1] / 100.0f, arg0->unk_174[arg0->unk_174[3] + 2] / 100.0f,
                  arg0->unk_174[arg0->unk_174[3] + 3] / 100.0f, arg0->unk_174[arg0->unk_174[3] + 4] / 100.0f);
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001DB078(void) {
    func_00103730();
    return 2;
}

s32 func_001DB098(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = (*(Script**)&arg0->unk_00[4])->unk_70;
    return 2;
}

s32 func_001DB0C8(Script* arg0) {
    func_00108488(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DB118(Script* arg0) {
    func_001084F0(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

void func_001DB168(void) {
    D_003854E0.unk_3070 &= ~0x200000000000;
}

extern void (*D_00377344)(s32, s32, void (*)(void));

s32 func_001DB198(Script* arg0) {
    D_00377344(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4], func_001DB168);
    ((XGiantMountainY*)&D_003854E0)->unk_3070_45 = 1;
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DB218(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 45) & 1) ? 4 : 2;
}

void func_001DB238(void) {
}

extern void (*D_0037733C)(s32, void (*)(void));

s32 func_001DB240(Script* arg0) {
    D_0037733C(arg0->unk_174[arg0->unk_174[3] + 4], func_001DB238);
    arg0->unk_174[3]--;
    return 2;
}

extern void (*D_00377340)(s32);

s32 func_001DB298(Script* arg0) {
    D_00377340(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern void (*D_00377348)(s32, s32);

s32 func_001DB2E8(Script* arg0) {
    D_00377348(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_0037734C)(s32, s32, s32);

s32 func_001DB340(Script* arg0) {
    D_0037734C(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 3;
    return 2;
}

extern void (*D_00377350)(s32, s32);

s32 func_001DB3A0(Script* arg0) {
    D_00377350(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_00377354)(s32, s32);

s32 func_001DB3F8(Script* arg0) {
    D_00377354(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_00377358)(s32, s32);

s32 func_001DB450(Script* arg0) {
    D_00377358(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_0037735C)(s32);

s32 func_001DB4A8(Script* arg0) {
    D_0037735C(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB4F8(Script* arg0) {
    f32 v[4];

    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_00144EB0(arg0->unk_174[arg0->unk_174[3] + 1], v);
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_001DB578(Script* arg0) {
    arg0->unk_174[3]++;
    return 2;
}

void func_00245280(s32, void*);

s32 func_001DB5D0(void) {
    if (!((s32)(*(u64*)&D_0038CD00[2] >> 2) & 1)) {
        return 4;
    }
    func_00245280(1, D_002E26A0[0]);
    return 0;
}

s32 func_001DB618(void) {
    func_0011ED30(50002, func_001DB5D0);
    D_003854E0.unk_3078 |= 4;
    return 2;
}

s32 func_001DB658(void) {
    D_003854E0.unk_3078 &= ~4;
    return 2;
}

extern void (*D_00377360)(s32);

s32 func_001DB678(Script* arg0) {
    D_00377360(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB6C8(Script* arg0) {
    func_0013C858(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DB718(Script* arg0) {
    D_002B8004 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB740(Script* arg0) {
    D_002B8008 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB768(Script* arg0) {
    D_002BBABC = arg0->unk_174[arg0->unk_174[3] + 3];
    D_002BBAC0 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

/* Unused on purpose: keeps func_001DB7A8 matching (notes/f1.md F1). */
extern s32 func_001DB7A8_f1_padb1;
extern s32 func_001DB7A8_f1_padb2;
extern s32 D_002BBAD0[];
extern s32 D_002BBAE0[];

s32 func_001DB7A8(Script* arg0) {
    D_002BBAD0[arg0->unk_174[arg0->unk_174[3] + 2]] = arg0->unk_174[arg0->unk_174[3] + 3];
    D_002BBAE0[arg0->unk_174[arg0->unk_174[3] + 2]] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001DB810(Script* arg0) {
    D_002B8014 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB838(Script* arg0) {
    func_0013C338(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB880(void) {
    D_00375BC0 &= ~4;
    D_003854E0.unk_3070 &= ~0x2000000000;
    return 2;
}

s32 func_001DB8C8(Script* arg0) {
    func_001BC480(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32* func_001E98D0(s32, s32);
void func_00141218(s32);

s32 func_001DB910(Script* arg0) {
    func_00141218(func_001E98D0((s32)(*(u64*)&arg0->unk_00[0x328] >> 5) & 1, arg0->unk_174[arg0->unk_174[3] + 4])[1]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DB970(void) {
    if (D_002C1EAA & 1) {
        return 4;
    }
    return 2;
}

s32 func_001DB990(void) {
    if (D_002C1EA8 & 0x6000) {
        return 4;
    }
    return 2;
}

extern void (*D_00377364)(s32);

s32 func_001DB9B0(Script* arg0) {
    D_00377364(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DBA00(void) {
    if (func_00235F50() != 0) {
        return 4;
    }
    return 2;
}

#ifdef VERSION_FM
s32 func_001DBA30(Script* arg0);
s32 func_001DBA30(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003F6E24;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001DBA30(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DBA30);
#else
s32 func_001DBA30(Script* arg0) {
    s32 val = D_003F0DD4;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

typedef struct {
    u16 kind : 4;
    u16 sub : 4;
    u16 hi : 8;
} DbaBits;
typedef struct {
    u64 kind : 4;
    u64 sub : 4;
    u64 hi : 8;
} DbaBits64;
DbaBits *func_00147778_d(s32) __asm__("func_00147778");
s32 func_0013C9E0_d(s32, s32) __asm__("func_0013C9E0");
void func_0013C858_d(s32, s32) __asm__("func_0013C858");

s32 func_001DBA58(Script *arg0) {
    DbaBits *p = func_00147778_d(arg0->unk_174[arg0->unk_174[3] + 4]);

    switch (p->kind) {
    case 0:
        func_0013C9E0_d(((u8 *)p)[1], p->sub);
        break;
    case 1:
        func_0013C858_d(((u8 *)p)[1], p->sub);
        break;
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_00111468(s32, s32);

s32 func_001DBAE8(Script* arg0) {
    s32 a = arg0->unk_174[arg0->unk_174[3] + 3];
    s32 b = arg0->unk_174[arg0->unk_174[3] + 4];

    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00111468(a, b);
    return 2;
}

void func_00105C70(s32, s32*);

s32 func_001DBB50(Script* arg0) {
    ScriptMsgG msg;
    s32 r[4];

    func_00105C70(arg0->unk_174[arg0->unk_174[3] + 3], r);
    msg.unk_00 = 0x17;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = r[0] * 0.0078125f;
    msg.unk_10[1] = r[1] * 0.0078125f;
    msg.unk_10[2] = r[2] * 0.0078125f;
    msg.unk_10[3] = *(f32*)(*(u8**)&arg0->unk_00[4] + 0xAC);
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DBC40(Script* arg0) {
    u8* p = (u8*)D_003010F8;

    p += arg0->unk_174[arg0->unk_174[3] + 4] * 0x74;
    arg0->unk_174[arg0->unk_174[3] + 4] = p[4];
    return 2;
}

void func_00142388(f32*, s32*);

s32 func_001DBC88(Script* arg0) {
    f32 v[4];
    s32 r[4];

    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_00142388(v, r);
    arg0->unk_174[3] -= 2;
    arg0->unk_174[arg0->unk_174[3] + 4] = r[0];
    return 2;
}

s32 func_001DBD18(Script* arg0) {
    f32 v[4];
    s32 r[4];

    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_00142388(v, r);
    arg0->unk_174[3] -= 2;
    arg0->unk_174[arg0->unk_174[3] + 4] = r[1];
    return 2;
}

s32 func_001DBDA8(Script* arg0) {
    f32 v[4];
    s32 r[4];

    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_00142388(v, r);
    arg0->unk_174[3] -= 2;
    arg0->unk_174[arg0->unk_174[3] + 4] = r[2];
    return 2;
}

void func_00142470(void*, s32*);

s32 func_001DBE38(Script* arg0) {
    s32 v[3];
    void* p;

    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    p = *(void**)&arg0->unk_00[4];
    if (p != NULL) {
        func_00142470(p, v);
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_00142388_r(f32*, s32*) __asm__("func_00142388");

s32 func_001DBEB0(Script* arg0) {
    f32 v[4];
    s32 r[4];
    void* p;

    v[0] = arg0->unk_174[arg0->unk_174[3] + 2];
    v[1] = arg0->unk_174[arg0->unk_174[3] + 3];
    v[2] = arg0->unk_174[arg0->unk_174[3] + 4];
    func_00142388_r(v, r);
    p = *(void**)&arg0->unk_00[4];
    if (p != NULL) {
        func_00142470(p, r);
    }
    arg0->unk_174[3] -= 3;
    return 2;
}

typedef struct {
    /* 0x000 */ s32 unk_000[0xCA];
    /* 0x328 */ u64 unk_328_0 : 15;
    u64 unk_328_15 : 1;
    u64 unk_328_16 : 48;
    /* 0x330 */ f32 unk_330;
    /* 0x334 */ u8 unk_334[0xC];
    /* 0x340 */ f32 unk_340;
    /* 0x344 */ f32 unk_344;
    /* 0x348 */ f32 unk_348;
} ScriptV;

s32 func_001DBF58(Script* arg0) {
    ScriptV* v = (ScriptV*)arg0;

    v->unk_328_15 = 1;
    v->unk_330 = arg0->unk_174[arg0->unk_174[3] + 1] * 2.0f;
    v->unk_340 = arg0->unk_174[arg0->unk_174[3] + 2];
    v->unk_344 = arg0->unk_174[arg0->unk_174[3] + 3];
    v->unk_348 = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 4;
    return 2;
}

s32 func_0014EFE0(void*, s32);

s32 func_001DBFC8(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        arg0->unk_174[arg0->unk_174[3] + 4] = func_0014EFE0(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}

s32 func_001DC040(Script* arg0) {
    func_00131B90(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_00377368)(s32, s32);

s32 func_001DC090(Script* arg0) {
    D_00377368(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_0037736C)(s32, s32);

s32 func_001DC0E8(Script* arg0) {
    D_0037736C(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_00377370)(s32, s32);

s32 func_001DC140(Script* arg0) {
    D_00377370(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_00377378)(s32, s32);

s32 func_001DC198(Script* arg0) {
    D_00377378(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DC1F0(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 0x29;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DC278(void) {
    D_002B9338 = 0;
    return 2;
}

s32 func_001DC288(void) {
    D_002B9338 = 1;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DC2A0);

s32 func_001DC368(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001F0A80();
    return 2;
}

s32 func_001DC3B0(void) {
    return ((s32)(*(u64*)&D_0038CD00[2] >> 4) & 1) ? 4 : 2;
}

void func_00157818(void*, s32);

s32 func_001DC3D8(Script* arg0) {
    void* p = *(void**)&arg0->unk_00[4];

    if (p != NULL) {
        func_00157818(p, arg0->unk_174[arg0->unk_174[3] + 4]);
    }
    arg0->unk_174[3]--;
    return 2;
}

#ifdef VERSION_FM
s32 func_001DC428(Script* arg0);
s32 func_001DC428(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B9170;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001DC428(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DC428);
#else
s32 func_001DC428(Script* arg0) {
    s32 val = D_002B9170;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

#ifdef VERSION_FM
s32 func_001DC450(Script* arg0);
s32 func_001DC450(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B916C;
    return 2;
}
#else
#ifdef VERSION_EU
s32 func_001DC450(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DC450);
#else
s32 func_001DC450(Script* arg0) {
    s32 val = D_002B916C;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif
#endif

extern void (*D_0037737C)(s32, s32);

s32 func_001DC478(Script* arg0) {
    D_0037737C(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_00377380)(s32, s32, s32, s32);

s32 func_001DC4D0(Script* arg0) {
    D_00377380(arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 4;
    return 2;
}

void func_001DC538(void) {
    D_003854E0.unk_3078 &= ~0x20;
}

s32 func_001DC558(Script* arg0) {
    if (func_00149E38(arg0->unk_174[arg0->unk_174[3] + 4], func_001DC538)) {
        D_003854E0.unk_3078 |= 0x20;
    }
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DC5C0(void) {
    return ((s32)(*(u64*)&D_0038CD00[2] >> 5) & 1) ? 4 : 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DC5E8);

s32 func_001DC8A8(Script* arg0) {
    func_001ED6F0(arg0->unk_174[arg0->unk_174[3] + 4], 1);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DC8F0(void) {
    func_00111F00();
    return 2;
}

extern void (*D_00377384)(s32);

s32 func_001DC910(Script* arg0) {
    D_00377384(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern s32 (*D_00377388)(s32, s32, s32);

s32 func_001DC960(Script* arg0) {
    if (D_00377388(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]) != 0) {
        arg0->unk_174[3] -= 3;
        return 2;
    }
    return 4;
}

extern void (*D_0037738C)(s32, s32);

s32 func_001DC9D0(Script* arg0) {
    D_0037738C(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_0037739C)(s32, s32, s32, s32, s32);

s32 func_001DCA28(Script* arg0) {
    D_0037739C(arg0->unk_174[arg0->unk_174[3]], arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 5;
    return 2;
}

extern void (*D_003773A0)(s32, s32, s32, s32, s32);

s32 func_001DCA98(Script* arg0) {
    D_003773A0(arg0->unk_174[arg0->unk_174[3]], arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 5;
    return 2;
}

extern void (*D_00377390)(s32, s32, s32, s32);

s32 func_001DCB08(Script* arg0) {
    D_00377390(arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 4;
    return 2;
}

extern void (*D_00377394)(s32, s32, s32, s32);

s32 func_001DCB70(Script* arg0) {
    D_00377394(arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 4;
    return 2;
}

extern void (*D_00377398)(s32, s32, s32, s32, s32);

s32 func_001DCBD8(Script* arg0) {
    D_00377398(arg0->unk_174[arg0->unk_174[3]], arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 5;
    return 2;
}

extern void (*D_003773A4)(s32);

s32 func_001DCC48(Script* arg0) {
    D_003773A4(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern void (*D_003773A8)(s32);

s32 func_001DCC98(Script* arg0) {
    D_003773A8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern void (*D_003773AC)(s32);

s32 func_001DCCE8(Script* arg0) {
    D_003773AC(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern void (*D_003773B0)(s32, s32);

s32 func_001DCD38(Script* arg0) {
    D_003773B0(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

extern void (*D_003773B4)(s32);

s32 func_001DCD90(Script* arg0) {
    D_003773B4(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

extern void (*D_003773B8)(s32);

s32 func_001DCDE0(Script* arg0) {
    D_003773B8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DCE30(void) {
    D_00375BC0 |= 0x10;
    return 2;
}

s32 func_001DCE50(void) {
    D_00375BC0 &= ~0x10;
    return 2;
}

s32 func_001DCE70(void) {
    func_001ED878(0);
    return 2;
}

typedef struct {
    u8 unk_00[0x74];
} Unk3010F8Elem74;

s32 func_001DCE90(Script* arg0) {
    ((Unk3010F8Elem74*)D_003010F8)[arg0->unk_174[arg0->unk_174[3] + 3]].unk_00[0x36] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DCEE8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DCFA8);

s32 func_001BAD78(s32);

s32 func_001DD118(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = func_001BAD78(arg0->unk_174[arg0->unk_174[3] + 4]);
    return 2;
}

extern s32 (*D_003773C0)(s32, s32);

s32 func_001DD170(Script* arg0) {
    s32 r = D_003773C0(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);

    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = r;
    return 2;
}

extern void (*D_003773BC)(s32, s32, s32, s32, s32);

s32 func_001DD1E0(Script* arg0) {
    D_003773BC(arg0->unk_174[arg0->unk_174[3]], arg0->unk_174[arg0->unk_174[3] + 1], arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 5;
    return 2;
}

s32 func_001DD250(void) {
    return D_003773C4() ? 2 : 4;
}

s32 func_001DD288(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = ((u16*)((u8*)D_003010F8 + 0x580))[arg0->unk_174[arg0->unk_174[3] + 4]];
    return 2;
}

#ifdef VERSION_EU
s32 func_001DD2C0(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DD2C0);
#else
s32 func_001DD2C0(Script* arg0) {
    s32 i;
    s32 n = 0;

    for (i = 0; i < 51; i++) {
        n += ((u16*)((u8*)D_003010F8 + 0x7D8))[i];
    }
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = n;
    return 2;
}
#endif

extern void (*D_003773CC)(s32, s32);

s32 func_001DD318(Script* arg0) {
    D_003773CC(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DD370(void) {
    D_002C1EA8 |= 0x20;
    return 2;
}

s32 func_001DD390(void) {
    D_002C1EA8 &= ~0x20;
    return 2;
}

s32 func_001DD3B0(void) {
    D_003854E0.unk_3078 &= ~0x80;
    return 2;
}

s32 func_001DD3D0(void) {
    D_003854E0.unk_3078 |= 0x80;
    return 2;
}

s32 func_001DD3F0(Script* arg0) {
    if (D_002BCA00[1] & arg0->unk_174[arg0->unk_174[3] + 4]) {
        arg0->unk_174[3]--;
        return 2;
    }
    return 4;
}

extern void (*D_003773D0)(s32);

s32 func_001DD430(Script* arg0) {
    D_003773D0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DD480(void) {
    D_002C1EA8 |= 0x200000;
    return 2;
}

s32 func_001DD4A0(void) {
    D_002C1EA8 &= ~0x200000;
    return 2;
}

extern void (*D_003773D4)(s32, s32);

s32 func_001DD4C8(Script* arg0) {
    D_003773D4(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DD520(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_003889B0;
    return 2;
}

void func_001DD548(void) {
    D_003854E0.unk_3078 &= ~0x100;
}

s32 func_001DD568(void) {
    D_003854E0.unk_3078 |= 0x100;
    func_0011E830(func_001DD548, func_F20000);
    return 2;
}

s32 func_001DD5B0(void) {
    D_003854E0.unk_3078 |= 0x100;
    func_0011E830(func_001DD548, &D_003D55DC);
    return 2;
}

s32 func_001DD5F8(void) {
    return ((s32)(*(u64*)&D_0038CD00[2] >> 8) & 1) ? 4 : 2;
}

void func_001DD620(s32 arg0, s32 arg1, s32 arg2) {
    func_00177908(arg2);
    D_003854E0.unk_3078 &= ~0x200;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3078];
    /* 0x3078 */ u64 unk_3078_0 : 9;
    u64 unk_3078_9 : 1;
    u64 unk_3078_10 : 54;
    /* 0x3080 */ s32 unk_3080;
} XGiantMountainS;

extern char D_004906C0[];

s32 func_001DD658(Script* arg0) {
    func_00120590(D_004906C0, func_00155ED8(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]), (s32 (*)(void))func_001DD620, 0);
    ((XGiantMountainS*)&D_003854E0)->unk_3078_9 = 1;
    arg0->unk_174[3] -= 2;
    return 2;
}

s32 func_001DD6E0(void) {
    return ((s32)(*(u64*)&D_0038CD00[2] >> 9) & 1) ? 4 : 2;
}

typedef struct {
    u8 unk_00[0x74];
} Unk3010F8Elem;

s32 func_001DD708(Script* arg0) {
    arg0->unk_174[arg0->unk_174[3] + 4] = ((Unk3010F8Elem*)D_003010F8)[arg0->unk_174[arg0->unk_174[3] + 4]].unk_00[0x36];
    return 2;
}

extern void (*D_003773D8)(s32, s32, s32);

s32 func_001DD750(Script* arg0) {
    D_003773D8(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 3;
    return 2;
}

s32 func_001DD7B0(Script* arg0) {
    s32* p;

    arg0->unk_174[3]++;
    p = *(s32**)&arg0->unk_00[4];
    if (p != NULL) {
        if (*p & 0x4000) {
            arg0->unk_174[arg0->unk_174[3] + 4] = 1;
        } else {
            arg0->unk_174[arg0->unk_174[3] + 4] = 0;
        }
    }
    return 2;
}

s32 func_001DD7F8(Script* arg0) {
    ScriptX* x = (ScriptX*)arg0;

    x->unk_328_2 = 1;
    x->unk_2F4 = x->stack[x->top] * 2.0f / 100.0f;
    x->top--;
    return 6;
}

s32 func_001DD848(Script* arg0) {
    func_0013BF20(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}

s32 func_001DD890(Script* arg0) {
    ScriptMsgG msg;

    msg.unk_00 = 0x2C;
    msg.unk_01 = (u32)arg0->unk_174[arg0->unk_174[3] + 4];
    msg.unk_04 = *(s32*)arg0->unk_00;
    msg.unk_10[0] = arg0->unk_174[arg0->unk_174[3]] / 255.0f;
    msg.unk_10[1] = arg0->unk_174[arg0->unk_174[3] + 1] / 255.0f;
    msg.unk_10[2] = arg0->unk_174[arg0->unk_174[3] + 2] / 255.0f;
    msg.unk_10[3] = arg0->unk_174[arg0->unk_174[3] + 3] * 0.0078125f;
    func_001C4640((ScriptMsg*)&msg);
    arg0->unk_174[3] -= 5;
    return 2;
}

s32 func_001DD990(void) {
    func_00125B40(1);
    return 2;
}

s32 func_001DD9B0(void) {
    func_00125B40(0);
    return 2;
}

#ifdef VERSION_FM
s32 func_001DD9D0(void);
typedef struct { s32 v[55]; } XHumDD9D0;
extern XHumDD9D0 D_004906D0;
void func_001BA358(s32 i, s32 add);

s32 func_001DD9D0(void) {
    XHumDD9D0 t = D_004906D0;
    u32 i;

    for (i = 0; i < 55; i++) {
        func_001BA358(t.v[i], 99);
    }
    return 2;
}
#else
s32 func_001DD9D0(void) {
    s32 i, j = 0;

    do {
        i = j + 1;
        func_001BC4F8(j, 99);
        j = i;
    } while (i < 0x47);
    return 2;
}
#endif

extern s32 (*D_003773E8)(s32);

s32 func_001DDA18(Script* arg0) {
    if (D_003773E8(arg0->unk_174[arg0->unk_174[3] + 4]) == 0) {
        return 4;
    }
    arg0->unk_174[3]--;
    return 2;
}

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001DA558);
#endif

#ifdef VERSION_FM
s32 fm_func_001DC2E0(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B29C4;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 fm_func_001DC308(Script* arg0) {
    u8* p = func_0022F768(1);

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = (*(u32*)(p + 0xDC4) >> 4) & 1;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 func_001DDA78(Script* arg0);
extern s32 (*D_003773C8)(s32, s32);

s32 func_001DDA78(Script* arg0) {
    if (D_003773C8(arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]) != 0) {
        arg0->unk_174[3] -= 2;
        return 2;
    }
    return 4;
}
#else
#ifdef VERSION_EU
s32 func_001DDA78(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDA78);
#else
s32 func_001DDA78(Script* arg0) {
    s32 sVar2 = D_002B29C4;

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = sVar2;
    return 2;
}
#endif
#endif

#ifdef VERSION_EU
s32 func_001DDAA0(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDAA0);
#else
s32 func_001DDAA0(void) {
    ScriptMsgG msg;
    u8* p;

    msg.unk_00 = 0x1B;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (((*(u64*)(p + 0x370) >> 37) & 3) == 2) {
            msg.unk_04 = *(s32*)(p + 4);
            func_001C4640((ScriptMsg*)&msg);
        }
    }
    return 2;
}
#endif

#ifdef VERSION_EU
s32 func_001DDAF0(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDAF0);
#else
s32 func_001DDAF0(void) {
    ScriptMsgG msg;
    u8* p;

    msg.unk_00 = 0x1C;
    msg.unk_01 = 0;
    msg.unk_10[0] = 0.0f;
    msg.unk_10[1] = 0.0f;
    msg.unk_10[2] = 0.0f;
    msg.unk_10[3] = 1.0f;
    for (p = func_001234A0(NULL); p != NULL; p = func_001234A0(p)) {
        if (((*(u64*)(p + 0x370) >> 37) & 3) == 2) {
            msg.unk_04 = *(s32*)(p + 4);
            func_001C4640((ScriptMsg*)&msg);
        }
    }
    return 2;
}
#endif

#ifdef VERSION_FM
extern void (*D_00377374)(s32, s32, s32);

s32 fm_func_001DC520(Script* arg0) {
    D_00377374(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 3;
    return 2;
}
#endif

s32 func_001F1E98(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 func_001F2D68(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7);

#ifdef VERSION_EU
s32 func_001DDB58(void);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDB58);

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001DA798);
#endif
#else
s32 func_001DDB58(void) {
    func_001F1E98(0x80FFFFFF, 0x46, 0x14, 0x1AF, 0x10);
    func_001F1E98(0x80FFFFFF, 0xF, 0x28, 0x1B0, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0x3D, *(u16*)((u8*)D_003010F8 + 0x856), 0x10, 0x80FFFFFF);
    func_001F1E98(0x80FFFFFF, 0xF, 0x50, 0x1B1, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0x65, *(u16*)((u8*)D_003010F8 + 0x866), 0x10, 0x80FFFFFF);
    func_001F1E98(0x80FFFFFF, 0xF, 0x78, 0x1B2, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0x8D, *(u16*)((u8*)D_003010F8 + 0x85C), 0x10, 0x80FFFFFF);
    func_001F1E98(0x80FFFFFF, 0xF, 0xA0, 0x1B3, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0xB5, *(u16*)((u8*)D_003010F8 + 0x862), 0x10, 0x80FFFFFF);
    func_001F1E98(0x80FFFFFF, 0xF, 0xC8, 0x1B4, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0xDD, *(u16*)((u8*)D_003010F8 + 0x860), 0x10, 0x80FFFFFF);
    func_001F1E98(0x80FFFFFF, 0xF, 0xF0, 0x1B5, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0x105, *(u16*)((u8*)D_003010F8 + 0x864), 0x10, 0x80FFFFFF);
    func_001F1E98(0x80FFFFFF, 0xF, 0x118, 0x1B6, 0x10);
    func_001F2D68(1, 0xA, 0, 0xF2, 0x12D, *(u16*)((u8*)D_003010F8 + 0x84E), 0x10, 0x80FFFFFF);
    return 0;
}
#endif

#ifdef VERSION_FM
s32 fm_func_001DC7C0(void) {
    if (func_0013BF68() == 1) {
        func_0011ED30(190001, func_001DDB58);
    }
    return 2;
}
#endif

#ifdef VERSION_FM
s32 fm_func_001DC800(Script* arg0) {
    s32 r;

    arg0->unk_174[3]++;
    r = func_0013BF68();
    if (r == 1) {
        arg0->unk_174[arg0->unk_174[3] + 4] = r;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}
#endif

#ifdef VERSION_FM
s32 fm_func_002193F0(void);

s32 fm_func_001DC868(Script* arg0) {
    arg0->unk_174[3]++;
    if (fm_func_002193F0() == 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}
#endif

extern s32 D_0037A178[];

#ifdef VERSION_EU
s32 func_001DDC08(Script* arg0);
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDC08);

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001DAA38);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xhumungus", eu_func_001DAA78);
#endif
#else
s32 func_001DDC08(Script* arg0) {
    s32 v = arg0->unk_174[arg0->unk_174[3] + 3];
    s32 f;
    s32 idx;
    s32 sh;

    if ((u32)v >= 0x80) {
        arg0->unk_174[3] -= 2;
        return 2;
    }
    f = arg0->unk_174[arg0->unk_174[3] + 4];
    if ((u32)f >= 2) {
        arg0->unk_174[3] -= 2;
        return 2;
    }
    idx = v / 32;
    sh = 31 - v % 32;
    if (f != 0) {
        D_0037A178[idx] |= 1 << sh;
    } else {
        D_0037A178[idx] &= ~(1 << sh);
    }
    arg0->unk_174[3] -= 2;
    return 2;
}
#endif

#ifdef VERSION_FM
extern s32 D_0037A178[];

s32 fm_func_001DC9A0(Script* arg0) {
    s32 v = arg0->unk_174[arg0->unk_174[3] + 4];

    if ((u32)v >= 0x80) {
        return 2;
    }
    arg0->unk_174[arg0->unk_174[3] + 4] = (D_0037A178[v / 32] >> (31 - v % 32)) & 1;
    return 2;
}
#endif

#ifdef VERSION_FM
void func_0022DEE0(s32);
s32 fm_func_001C1DF8(void);

s32 fm_func_001DCA00(void) {
    func_0022DEE0(0xFFFF);
    func_0011ED30(50001, fm_func_001C1DF8);
    D_003854E0.unk_3078 |= 0x1000;
    return 6;
}
#endif

#ifdef VERSION_FM
s32 fm_func_001DCA48(Script* arg0) {
    arg0->unk_174[3]++;
    if (D_003F76B8 == 0) {
        arg0->unk_174[arg0->unk_174[3] + 4] = 1;
    } else {
        arg0->unk_174[arg0->unk_174[3] + 4] = 0;
    }
    return 2;
}
#endif

#ifdef VERSION_FM
s32 func_0021ADD8(void);

s32 fm_func_001DCA88(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_0021ADD8();
    return 2;
}
#endif

s32 func_001DDCB8(UNK_PTR arg0, s32 idx) {
    return D_003D4A20[idx](arg0);
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDCE8);

typedef struct {
    u8 unk_0000[0x3034];
    s32 unk_3034;
    u8 unk_3038[0x118];
    s32 unk_3150;
    Script* unk_3154;
} XHumGMDF;

void func_001DDFA0(s32 a0) {
    XHumGMDF* g = (XHumGMDF*)&D_003854E0;
    Script* base;
    s32 n;
    s32 i;

    g->unk_3150 = a0;
    if (g->unk_3034 == 0) {
        base = &D_0038D170;
        n = D_0039A570;
    } else {
        base = &D_0039A580;
        n = D_003A7980;
    }
    for (i = 0; i < n; i++) {
        if ((Script*)((u8*)base + i * 0x350) == ((XHumGMDF*)&D_003854E0)->unk_3154) {
            break;
        }
    }
    if (a0 > 0) {
        D_00375BC0 &= ~8;
    }
    base->unk_174[3]++;
    base->unk_174[base->unk_174[3] + 4] = 3;
    base->unk_174[3]++;
    base->unk_174[base->unk_174[3] + 4] = i;
    func_001C3380(base, 8);
}

void func_001DE098(void) {
    D_003854E0.unk_3380++;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE0B0);

void func_001DE1B8(Script* arg0) {
    ScriptMsgG msg;
    f32* o;

    if ((s32)(*(u64*)&arg0->unk_00[0x328] >> 14) & 1) {
        o = *(f32**)&arg0->unk_00[4];
        if (o != NULL) {
            msg.unk_00 = 0x27;
            msg.unk_04 = *(s32*)arg0->unk_00;
            msg.unk_01 = 0;
            msg.unk_10[0] = o[4];
            msg.unk_10[1] = o[5] - 20.0f;
            msg.unk_10[2] = o[6];
            msg.unk_10[3] = 1.0f;
            func_001C4640((ScriptMsg*)&msg);
        }
        *(f32*)&arg0->unk_00[0x330] -= D_002B8344;
        if (*(f32*)&arg0->unk_00[0x330] < 0.0f) {
            *(u64*)&arg0->unk_00[0x328] &= ~0x4000;
        }
    }
    if ((s32)(*(u64*)&arg0->unk_00[0x328] >> 15) & 1) {
        if (*(void**)&arg0->unk_00[4] != NULL) {
            msg.unk_00 = 0x27;
            msg.unk_04 = *(s32*)arg0->unk_00;
            msg.unk_01 = 0;
            msg.unk_10[0] = *(f32*)&arg0->unk_00[0x340];
            msg.unk_10[1] = *(f32*)&arg0->unk_00[0x344];
            msg.unk_10[2] = *(f32*)&arg0->unk_00[0x348];
            msg.unk_10[3] = 1.0f;
            func_001C4640((ScriptMsg*)&msg);
        }
        *(f32*)&arg0->unk_00[0x330] -= D_002B8344;
        if (*(f32*)&arg0->unk_00[0x330] < 0.0f) {
            *(u64*)&arg0->unk_00[0x328] &= ~0x8000;
        }
    }
}

s32 func_001DE338(void) {
    func_0011EF58(&D_00624960, 0);
    return 0;
}

s32 func_001DE360(void) {
    s32 result;

    D_00624550 = func_00155ED8(0x32, 2);
    D_00624554 = D_00624550 + 512000;
    func_0011EDD0(&D_00624960, &D_00624970, 0x50, 0x100);
    result = func_0011ED30(49999, func_001DE338);
    D_00624958 = NULL;
    return result;
}

void func_001DE3E0(UNK_PTR arg0, UNK_PTR arg1) {
    D_00624550 = arg0;
    D_00624554 = arg1;
}

s32 func_001DE3F8(u8* arg0) {
    f32 v[4];
    f32* q;
    u8* o;
    u8* d;
    f32* q2;

    if ((s32)(D_003854E0.unk_3070 >> 40) & 1) {
        return 4;
    }
    if (*(s32*)(*(u8**)(arg0 + 0x10) + 0x14) & 2) {
        return 4;
    }
    func_001315C0(*(s32*)(*(u8**)(arg0 + 0x14) + 4), *(s32*)(arg0 + 0x18), v, *(f32*)(arg0 + 0x1C));
    d = *(u8**)(arg0 + 0x10);
    q = *(f32**)d;
    q[0] = v[0];
    q[1] = v[1];
    q[2] = v[2];
    if ((*(s32*)(arg0 + 0x18) == 0x108C || *(s32*)(arg0 + 0x18) == 0x1097) && !((s32)(D_003854E0.unk_3078 >> 3) & 1)) {
        o = *(u8**)(*(u8**)(arg0 + 0x14) + 4);
        q2 = *(f32**)(d + 0xC);
        q2[0] = o[0x370] * 0.0078125f;
        q2[1] = o[0x371] * 0.0078125f;
        q2[2] = o[0x372] * 0.0078125f;
    }
    return 0;
}

void func_00131A30(s32, s32, f32*);

s32 func_001DE518(u8* arg0) {
    f32 v[4];
    s32* q;

    if ((s32)(*(u64*)D_0038CD00 >> 40) & 1) {
        return 4;
    }
    if (*(s32*)(*(u8**)(arg0 + 0x10) + 0x14) & 2) {
        return 4;
    }
    func_00131A30(*(s32*)(*(u8**)(arg0 + 0x14) + 4), *(s32*)(arg0 + 0x18), v);
    q = *(s32**)(*(u8**)(arg0 + 0x10) + 4);
    q[0] = v[0] * 32768.0f / 3.1415928f;
    q[1] = v[1] * 32768.0f / 3.1415928f;
    q[2] = v[2] * 32768.0f / 3.1415928f;
    return 0;
}

typedef struct {
    /* 0x00 */ f32* unk_00;
    /* 0x04 */ u8 unk_04[0x10];
    /* 0x14 */ s32 unk_14;
} UnkDE5F0A;

typedef struct {
    /* 0x000 */ u8 unk_000[0x15C];
    /* 0x15C */ s32 unk_15C;
} UnkDE5F0C;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ UnkDE5F0C* unk_04;
} UnkDE5F0B;

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ UnkDE5F0A* unk_10;
    /* 0x14 */ UnkDE5F0B* unk_14;
    /* 0x18 */ s32 unk_18;
} UnkDE5F0;

f32 (*func_001623E0(s32))[16];

s32 func_001DE5F0(UnkDE5F0* arg0) {
    f32 (*m)[16];

    if ((s32)(*(u64*)D_0038CD00 >> 40) & 1) {
        return 4;
    }
    if (arg0->unk_10->unk_14 & 2) {
        return 4;
    }
    m = func_001623E0(arg0->unk_14->unk_04->unk_15C);
    arg0->unk_10->unk_00[0] = m[arg0->unk_18][12];
    arg0->unk_10->unk_00[1] = m[arg0->unk_18][13];
    arg0->unk_10->unk_00[2] = m[arg0->unk_18][14];
    return 0;
}

typedef struct {
    /* 0x00 */ u8 unk_00[0xC];
    /* 0x0C */ f32* unk_0C;
    /* 0x10 */ u8 unk_10[4];
    /* 0x14 */ s32 unk_14;
} UnkDE680A;

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ UnkDE680A* unk_10;
    /* 0x14 */ u8 unk_14[0x1C];
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ u8 unk_34[0xC];
    /* 0x40 */ f32 unk_40[3];
} UnkDE680;

s32 func_001DE680(UnkDE680* arg0) {
    if ((s32)(*(u64*)D_0038CD00 >> 40) & 1) {
        return 4;
    }
    if (arg0->unk_10->unk_14 & 2) {
        return 4;
    }
    arg0->unk_30 -= D_002B8344;
    if (arg0->unk_30 < 0.0f) {
        return 4;
    }
    arg0->unk_10->unk_0C[0] += arg0->unk_40[0];
    arg0->unk_10->unk_0C[1] += arg0->unk_40[1];
    arg0->unk_10->unk_0C[2] += arg0->unk_40[2];
    if (arg0->unk_10->unk_0C[0] < 0.0f) {
        arg0->unk_10->unk_0C[0] = 0.0f;
    }
    if (arg0->unk_10->unk_0C[1] < 0.0f) {
        arg0->unk_10->unk_0C[1] = 0.0f;
    }
    if (arg0->unk_10->unk_0C[2] < 0.0f) {
        arg0->unk_10->unk_0C[2] = 0.0f;
    }
    return 0;
}

void func_001318E8(UnkDE5F0C*, s32, sceVu0FMATRIX);
void func_00147E08(UnkDE5F0A*, sceVu0FMATRIX);

s32 func_001DE750(UnkDE5F0* arg0) {
    sceVu0FMATRIX m;

    if ((s32)(*(u64*)D_0038CD00 >> 40) & 1) {
        return 4;
    }
    if (arg0->unk_10->unk_14 & 2) {
        return 4;
    }
    func_001318E8(arg0->unk_14->unk_04, arg0->unk_18, m);
    func_00147E08(arg0->unk_10, m);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE7C0);

void func_001DEDF8(void) {
    func_00177908(D_00624550);
    D_003854E0.unk_3070 &= ~0x100000000000;
}

s32 func_001DEE48(void) {
    return func_00120590(&D_00624658, D_00624550, func_001DEDF8, NULL);
}
