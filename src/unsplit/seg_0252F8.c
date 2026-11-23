// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0252F8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001252F8);

extern u32 D_002C1EA8;
void func_001252F8(void);

void func_00125B40(s32 on) {
    if (on) {
        D_002C1EA8 |= 0x400000;
    } else {
        D_002C1EA8 &= ~0x400000;
    }
    func_001252F8();
}

typedef struct {
    u8 unk_00[0x70];
    s32 unk_70;
} Seg252F8Unk74;
extern Seg252F8Unk74* D_002E26A0;

s32 func_00125B90(s32 arg0) {
    Seg252F8Unk74* p = D_002E26A0;

    if ((arg0 & 1) && p->unk_70 != 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125BB8);

extern u32 D_002E3190;
s32 func_00130030(u8 *);
s32 func_00125B68(u8 *p) {
    if (((D_002E3190 >> 8) & 0xFFFF) == 0) {
        switch (*(s32 *)(p + 0x164)) {
        case 0x8A:
        case 0x3D:
            return 1;
        case 0xC8:
        case 0xCA:
            if (func_00130030(p) != 0) {
                return 1;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}

u8 *func_00130340(u8 *a0, s32 a1, f32 f);
u8 *func_00130578(u8 *a0, s32 a1, f32 f);
void func_001333E0(u8 *a0, s32 a1, s32 a2);
typedef struct {
    u8 unk_00[0xF0];
    f32 unk_F0;
} Seg252F8Unk3051EC;
extern Seg252F8Unk3051EC *D_003051EC;

void func_00125BE8(u8 *a0, s32 a1) {
    u8 *p = a0;

    switch (*(s32 *)(p + 0x70)) {
    case 2:
        func_00130340(a0, 0x100008A, 8.0f);
        func_00130578(p, 0x40000006, 0.0f);
        sceVu0ScaleVector((f32 *)(p + 0x3C0), (f32 *)(p + 0x3C0), D_003051EC->unk_F0);
        break;
    case 8:
        func_00130340(a0, 0x100008A, 8.0f);
        func_00130578(p, 0x40000075, 8.0f);
        sceVu0ScaleVector((f32 *)(p + 0x3C0), (f32 *)(p + 0x3C0), D_003051EC->unk_F0);
        break;
    default:
        func_00130340(p, 0x100003D, 8.0f);
        func_00130578(p, 0x40000000, 0.0f);
        break;
    }
    func_001333E0(p, 0, a1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125CF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125DC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126108);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126838);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001269D8);

s32 func_001233F8(s32);
void func_0012ED88(u8 *, s32 *, f32 *, f32 *);
void sceVu0CopyVector(f32 *, f32 *);

void func_00126BA0(u8 *a, s32 *b, f32 *c) {
    f32 v[4];

    if (func_001233F8(*b) != 0) {
        func_0012ED88(a, b, v, c);
        c[1] = 0.0f;
    } else {
        sceVu0CopyVector(c, (f32 *)(a + 0x30));
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126C10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126E80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126F18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001271B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00127340);
