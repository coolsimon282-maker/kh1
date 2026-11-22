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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125B68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125BE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125CF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125DC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126108);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126238);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126838);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001269D8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126BA0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126C10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126E80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126F18);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001271B0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00127340);
