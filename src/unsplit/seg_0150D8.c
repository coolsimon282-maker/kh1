// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0150D8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"
s32 func_001152C8(s32, s32, s32, s32);
s32 func_001198C8(s32, s32, s32);

typedef struct {
    u_long128* unk_00;
    u_long128* unk_04;
    s16 (*unk_08)[10];
    u8 unk_0C[0x34];
} Seg150D8Ent40;
typedef struct {
    u32 lo : 4;
    u32 hi : 4;
} Seg150D8Bits;
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
} Seg150D8Ent;
typedef struct {
    u8 unk_00[0x2C];
    s32 unk_2C;
    s32 unk_30;
    u8 unk_34[4];
    s16 unk_38;
    s16 unk_3A;
    s16 unk_3C;
    s16 unk_3E;
    u8 unk_40[0x20];
    s32 unk_60;
    u8 unk_64[8];
    s16 unk_6C;
    s16 unk_6E;
    s16 unk_70;
    s16 unk_72;
    s16 unk_74;
    s16 unk_76;
} Seg150D8Unk78;
typedef struct {
    u8 unk_00[0x30];
    s32 unk_30;
    u8 unk_34[0xC];
} Seg150D8Unk40b;
typedef struct {
    u8 unk_00[0xB];
    u8 unk_0B;
    u8 unk_0C[4];
    u8 unk_10[4];
} Seg150D8Unk14;
typedef struct {
    Seg150D8Unk14* unk_00;
    u8 unk_04[0x3C];
} Seg150D8Unk40;
extern Seg150D8Ent40 D_004E2450[];
// sceVu0CopyVector as inline asm (lq/sq through $6, then a nop)
static inline void Seg150D8_CopyQ(void* v0, void* v1) {
    __asm__ __volatile__("lq $6,0x0(%1)\n\tsq $6,0x0(%0)\n\tnop" : : "r"(v0), "r"(v1) : "$6", "memory");
}
extern s32 D_002A62F0;
extern s32 D_002B6478;
void func_00218CA0(s32);
s32 func_00218C78(void);
void func_0011AF48(s32, s32, s32, s32*);
void func_0011A410(void);
void func_00115940(s32, void*);
extern Seg150D8Ent D_004761D0[];
extern Seg150D8Ent* D_004E0420;
extern s32 D_002C12C4;
extern s32 D_002BD250[];
void func_00116368(s32, s32);
void func_00118060(s32, s32, s32, s32);
void func_00118378(s32, s32, s32, s32);
void func_001047C8(void);
void func_00104528(void);
extern Seg150D8Unk40b D_004E2430[];
extern Seg150D8Unk40 D_004E2458[];

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001150D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115158);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001151A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115200);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001152C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115408);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115600);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001156F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115758);

void func_001158A8(volatile f32* arg0, f32* arg1) {
    f32 v = *arg1;

    arg0[0] = v;
    arg0[1] = v;
    arg0[2] = v;
    arg0[3] = v;
    __asm__ volatile("nop");
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001158C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115940);

void func_00115D18(void) {
    s32 i;
    s32* p;
    D_004E0420 = D_004761D0;
    p = &D_004761D0[0].unk_8;
    for (i = 0x3FF; i >= 0; i--) {
        *p = 0;
        p += 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00115D58);

void func_00115E90(s32 a0, u32* a1) {
    if ((*a1 & 0x106) == 0) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00115ED0(s32 a0, u32* a1) {
    if ((*a1 & 0x406) == 0x400) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00115F10(s32 a0, u32* a1) {
    if ((*a1 & 0xF6) == 0x20) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00115F50(s32 a0, u32* a1) {
    if ((*a1 & 0xE) == 0) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00115F90(s32 a0, Seg150D8Bits* a1) {
    if (a1->hi != 7 && a1->hi != 5) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00115FD8(s32 a0, u32* a1) {
    if ((*a1 & 0x10006) == 0) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00116020(s32 a0, u32* a1) {
    if ((*a1 & 0xF6) == 0x50) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00116060(s32 a0, Seg150D8Bits* a1) {
    if (a1->hi != 7 && a1->hi != 9 && a1->hi != 5) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_001160B0(s32 a0, Seg150D8Bits* a1) {
    if (a1->hi == 9) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_001160F0(s32 a0, u32* a1) {
    if (((*a1 >> 17) & 1) == 0) {
        D_002BD250[D_002C12C4++] = a0;
    }
}

void func_00116130(s32 arg0, u32* arg1) {
    if ((*arg1 & 0x106) == 0) {
        func_00115940(arg0, arg1);
    }
}

void func_00116160(s32 arg0, u32* arg1) {
    if ((*arg1 & 0x406) == 0x400) {
        func_00115940(arg0, arg1);
    }
}

void func_00116198(s32 arg0, u32* arg1) {
    if ((*arg1 & 0xF6) == 0x20) {
        func_00115940(arg0, arg1);
    }
}

void func_001161D0(s32 arg0, u32* arg1) {
    if ((*arg1 & 0xE) == 0) {
        func_00115940(arg0, arg1);
    }
}

void func_00116200(s32 a0, Seg150D8Bits* a1) {
    if (a1->hi != 7 && a1->hi != 5) {
        func_00115940(a0, (void*)a1->hi);
    }
}

void func_00116240(s32 arg0, u32* arg1) {
    if ((*arg1 & 0x10006) == 0) {
        func_00115940(arg0, arg1);
    }
}

void func_00116278(s32 arg0, u32* arg1) {
    if ((*arg1 & 0xF6) == 0x50) {
        func_00115940(arg0, arg1);
    }
}

void func_001162B0(s32 a0, Seg150D8Bits* a1) {
    if (a1->hi != 7 && a1->hi != 9 && a1->hi != 5) {
        func_00115940(a0, (void*)a1->hi);
    }
}

void func_001162F8(s32 arg0, Seg150D8Bits* arg1) {
    if (arg1->hi == 9) {
        func_00115940(arg0, arg1);
    }
}

void func_00116330(s32 arg0, u32* arg1) {
    if (((*arg1 >> 17) & 1) == 0) {
        func_00115940(arg0, arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00116368);

void func_00116628(Seg150D8Unk78* arg0) {
    arg0->unk_30 = 0;
    arg0->unk_38 = 0;
    arg0->unk_2C = -1;
    arg0->unk_60 = 0;
    arg0->unk_76 = -1;
    arg0->unk_74 = -1;
    arg0->unk_70 = -1;
    arg0->unk_6E = -1;
    arg0->unk_6C = -1;
    arg0->unk_3E = -1;
    arg0->unk_3A = -1;
}

void func_00116660(Seg150D8Unk78* arg0) {
    func_00116628(arg0);
    arg0->unk_3C = -1;
}

s32 func_00116690(u32* arg0) {
    return (*arg0 >> 17) & 1;
}

s32 func_001166A0(u32* arg0) {
    return (*arg0 >> 26) & 1;
}

s32 func_001166B0(u8* arg0) {
    return arg0[3] & 1;
}

s32 func_001166C0(void) {
    return 0;
}

s32 func_001166C8(u32* arg0) {
    return (*arg0 >> 27) & 1;
}

s32 func_001166D8(u32* arg0) {
    return (*arg0 >> 9) & 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001166E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00117710);

void func_00117588(s32 arg0) {
    func_00116368(arg0, 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001178D0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00117948);

s32 func_00117BB0(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (func_001152C8(a0, a1, a2, a3) != 0) {
        if (func_001198C8(-1, a0, a3) != 0) return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00117C08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00117DB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118060);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118230);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118378);

void func_00118548(u8* a0) {
    s32 m;
    if (D_002A62F0 != 0) {
        func_00118060((s32)a0, 9, 1, -1);
        return;
    }
    m = -1;
    *(s32*)(a0 + 0x34) = m;
    *(s16*)(a0 + 0x30) = m;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118590);

void func_00118608(s32 arg0) {
    func_00118060(arg0, 3, 0, -1);
}

void func_00118628(s32 arg0, s32 arg1) {
    func_00118060(arg0, 3, 0, arg1);
}

void func_00118648(s32 arg0) {
    func_00118060(arg0, 10, 1, -1);
}

void func_00118668(s32 arg0) {
    func_00118378(arg0, 3, 0, -1);
}

void func_00118688(s32 arg0, s32 arg1) {
    func_00118378(arg0, 3, 0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001186A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118868);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118B58);

void func_00118D78(s32 arg0) {
    func_001047C8();
    func_00118060(arg0, 3, 0, -1);
    func_00104528();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118DB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00118EA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119128);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001191C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001195D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119688);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119710);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119788);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001197E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_001198C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119A20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119AD8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119E80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119EF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_00119FC0);

s32 func_0011A068(void) {
    s32 i;

    for (i = 63; i >= 0; i--) {
        D_004E2430[i].unk_30 = 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A0A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A410);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A728);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A7C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A818);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A648);

void func_0011A758(s32 a0, s32 a1, u_long128* a2) {
    Seg150D8Ent40* e = &D_004E2450[a0];
    Seg150D8_CopyQ(a2, &e->unk_04[e->unk_08[a1][4]]);
}

void func_0011A9C8(s32 a0, s32 a1, u_long128* a2) {
    Seg150D8Ent40* e = &D_004E2450[a0];
    Seg150D8_CopyQ(a2, &e->unk_00[e->unk_08[a1][0]]);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011A7F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011AAC8);

u8* func_0011AB38(s32 arg0, s32 arg1) {
    return D_004E2458[arg0].unk_00[arg1].unk_10;
}

u8 func_0011AB60(s32 arg0, s32 arg1) {
    return D_004E2458[arg0].unk_00[arg1].unk_0B;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011AB88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011AF48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011AED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011B108);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011B220);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011B6A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011B908);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011B9F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011BBE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011BDF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011BFC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011C118);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0150D8", func_0011C338);

void func_0011C5E8(void) {
    if (func_00218C78() == 1 && D_002B6478 != 2) {
        func_00218CA0(0);
    }
}
