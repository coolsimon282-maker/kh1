// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x021B98).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121B98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121AE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121D00);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121D60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121DE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121C98);

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32* unk_0C;
} Seg21B98Unk10;
Seg21B98Unk10* func_00121DE0(s32, s32);

void func_00121EB0(s32 arg0, s32 arg1) {
    Seg21B98Unk10* p = func_00121DE0(arg0, arg1);

    if (p->unk_0C != NULL) {
        *p->unk_0C = 0;
    }
    p->unk_0C = NULL;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121D50);

void func_00121F30(s32 a0, s32 *a1) {
    Seg21B98Unk10 *p = func_00121DE0(a0, (s32)a1);

    *a1 = a0;
    p->unk_0C = a1;
    p->unk_00 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00121F6C);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_001223B0);

extern u32* D_004F6EB8;
extern u32 D_004F6DB8[];

void func_00122410(void) {
    D_004F6DB8[0] = D_004F6DB8[1] = 0x70000000;
    D_004F6EB8 = D_004F6DB8;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122048);

void func_001220B8(void) {
    D_004F6EB8 -= 2;
}

void func_001220D0(void) {
    scePcStop();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_001220E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122130);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122588);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_00122720);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_021B98", func_001223B8);
