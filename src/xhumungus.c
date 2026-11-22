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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C98D0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C99C8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C9A70);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C9EC0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001C9FE0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CA090);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CACC0);

s32 func_001CADC0(void) {
    return ((s32)(*(u64*)D_0038CD00 >> 37) & 1) ? 4 : 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CADE0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB0E0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB1A8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB4A0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB5C0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB7B8);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CB998);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CBB90);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC338);

void func_001CC520(void) {
    D_003854E0.unk_00 = 0;
}

void func_001CC530(void) {
    func_0010BB10(&D_0062A130, (s32)func_001CC520);
}

void func_001CC558(void) {
    func_0010EDA0(&D_0062A130, D_003C5808, func_001CC530);
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC588);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC618);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC680);

void func_001CC798(s32 arg0) {
    D_003854E0.unk_3070 &= ~0x100000000;
    D_003854E0.unk_3140 = arg0;
    *D_003854E0.unk_3144 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC7D0);

s32 func_001CC930(void) {
    return (D_0038CD00[1] & 1) ? 4 : 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC950);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CC9A8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCA88);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCB18);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCC48);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCEF8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CCF78);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD2A8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD340);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD4D0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD620);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD738);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CD8E8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CDA00);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CDB18);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CDFC8);

s32 func_001CE060(Script* arg0) {
    u8 val = D_003854E0.unk_01[arg0->unk_174[arg0->unk_174[3] + 4] + 3];

    if (val != 0 && val != 4) {
        return 4;
    }
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CE0A0);

s32 func_001CE188(Script* arg0) {
    arg0->unk_174[3]--;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CE1A0);

s32 func_001CE738(void) {
    func_0017FED8();
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CE758);

// Handle score against Riku on Destiny Island
s32 func_001CE858(Script* arg0) {
    s32 start = arg0->unk_174[3];

    D_003C10B8[arg0->unk_174[start + 3]] = arg0->unk_174[start + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

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

void func_001C4640(ScriptMsg*);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CF3B0);

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

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgG;

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CF6C8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CF728);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CF970);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CFB28);

void func_00112880(s32);

s32 func_001CFBC0(Script* arg0) {
    s32* t = &arg0->unk_174[3];
    s32 v = arg0->unk_174[*t + 4];

    (*t)--;
    func_00112880(v);
    D_003854E0.unk_3070 |= 0x10000000000;
    return 10;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001CFC18);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D06F0);

s32 func_001D0828(Script* arg0) {
    ((f32*)D_0038CD3C[arg0->unk_174[arg0->unk_174[3] + 3]])[3] = arg0->unk_174[arg0->unk_174[3] + 4];
    arg0->unk_174[3] -= 2;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0870);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0AA0);

s32 func_001D0B50(Script* arg0) {
    ScriptMsg msg;

    msg.unk_00 = 20;
    msg.unk_01 = 0;
    msg.unk_04 = *(s32*)arg0->unk_00;
    func_001C4640(&msg);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0B98);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0C98);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D0F10);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1068);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1328);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1380);

s32 func_001D13D8(Script* arg0) {
    return ((s32)(*(u64*)((u8*)arg0 + 0x328) >> 1) & 1) ? 4 : 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D13F8);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1878);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1C88);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1D70);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D1E20);

#ifdef VERSION_FM
s32 func_001D1EE0(Script* arg0);
s32 func_001D1EE0(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B8678;
    return 2;
}
#else
s32 func_001D1EE0(Script* arg0) {
    s32 val = D_002B8678;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 func_001D1F08(Script* arg0);
s32 func_001D1F08(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B8680;
    return 2;
}
#else
s32 func_001D1F08(Script* arg0) {
    s32 val = D_002B8680;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 func_001D1F30(Script* arg0);
s32 func_001D1F30(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B8684;
    return 2;
}
#else
s32 func_001D1F30(Script* arg0) {
    s32 val = D_002B8684;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2190);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2308);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2600);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2840);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2AF0);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D2F60);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3240);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3300);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D33B8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3498);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3570);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3668);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3750);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3860);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3B00);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D3CF0);

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
s32 func_001D3FC8(Script* arg0) {
    func_001E2628(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D40F0);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D41F0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D42E8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D43E0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D4540);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D45E0);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D4F08);

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

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xhumungus", fm_func_001D3610);
#endif

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D5068);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D5730);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D58F8);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D5B60);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D5E88);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6478);

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
s32 func_001D66F8(Script* arg0) {
    s32 val = D_002C1EA8 & 1;

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6778);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6828);

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
s32 func_001D68D8(Script* arg0) {
    func_001038B0(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
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
s32 func_001D6920(Script* arg0) {
    func_001037C8(arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3]--;
    return 2;
}
#endif

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D6968);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D70C8);

s32 func_001D7178(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_0038CDE8;
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D71A0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D7250);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D7A68);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D7B60);

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
s32 func_001D7E18(void) {
    func_00249F88();
    return 2;
}
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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8500);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8850);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8928);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8B30);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D8DE8);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D9C28);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D9EA8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001D9F08);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DA760);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DA940);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DAAA8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DAB88);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DACC8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DAD58);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DAFC8);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DB4F8);

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
s32 func_001DBA30(Script* arg0) {
    s32 val = D_003F0DD4;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DBA58);

s32 func_00111468(s32, s32);

s32 func_001DBAE8(Script* arg0) {
    s32 a = arg0->unk_174[arg0->unk_174[3] + 3];
    s32 b = arg0->unk_174[arg0->unk_174[3] + 4];

    arg0->unk_174[3]--;
    arg0->unk_174[arg0->unk_174[3] + 4] = func_00111468(a, b);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DBB50);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DBEB0);

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
s32 func_001DC428(Script* arg0) {
    s32 val = D_002B9170;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
#endif

#ifdef VERSION_FM
s32 func_001DC450(Script* arg0);
s32 func_001DC450(Script* arg0) {
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = D_002B916C;
    return 2;
}
#else
s32 func_001DC450(Script* arg0) {
    s32 val = D_002B916C;
    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = val;
    return 2;
}
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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DD890);

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
INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DD9D0);
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
s32 func_001DDA78(Script* arg0) {
    s32 sVar2 = D_002B29C4;

    arg0->unk_174[3]++;
    arg0->unk_174[arg0->unk_174[3] + 4] = sVar2;
    return 2;
}
#endif

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDAA0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDAF0);

#ifdef VERSION_FM
extern void (*D_00377374)(s32, s32, s32);

s32 fm_func_001DC520(Script* arg0) {
    D_00377374(arg0->unk_174[arg0->unk_174[3] + 2], arg0->unk_174[arg0->unk_174[3] + 3], arg0->unk_174[arg0->unk_174[3] + 4]);
    arg0->unk_174[3] -= 3;
    return 2;
}
#endif

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDB58);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDC08);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DDFA0);

void func_001DE098(void) {
    D_003854E0.unk_3380++;
}

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE0B0);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE1B8);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE3F8);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE518);

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

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE680);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE750);

INCLUDE_ASM("asm/nonmatchings/xhumungus", func_001DE7C0);

void func_001DEDF8(void) {
    func_00177908(D_00624550);
    D_003854E0.unk_3070 &= ~0x100000000000;
}

s32 func_001DEE48(void) {
    return func_00120590(&D_00624658, D_00624550, func_001DEDF8, NULL);
}
