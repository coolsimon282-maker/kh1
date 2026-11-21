#include "common.h"
#include "libdma.h"

extern s32 D_0051C6C4;

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void* unk_10;
} XCream;

s32 func_001274C0(XCream* arg0) {
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), arg0->unk_10);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_001274F8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127560);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127960);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127B18);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127B98);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127C20);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128250);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128488);

INCLUDE_ASM("asm/nonmatchings/xcream", func_001284E8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128780);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128B68);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128CA8);

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
} XCreamUnk8CA8;

s32 func_00128CA8(XCreamUnk8CA8* arg0, s32 arg1);

void func_00128D10(XCreamUnk8CA8* arg0) {
    arg0->unk_0 = func_00128CA8(arg0, arg0->unk_4);
}

void func_00128D40(s32* arg0) {
    func_0012B850(*arg0);
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128D58);

void func_00128DA0(void) {
    func_0012B850(D_0051C6C4);
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ u16 unk_4;
} XCreamUnk8DF8;

extern u8* D_00514F10;

void func_00128DC0(s32* arg0) {
    s32 i;
    s32 ofs = 0x720;

    for (i = 0; i < 4; i++) {
        *(u16*)(D_00514F10 + ofs + 4) = arg0[i];
        ofs += 2;
    }
}

void func_00128DF8(XCreamUnk8DF8* arg0) {
    *(u16*)(D_00514F10 + arg0->unk_0 * 2 + 0x724) = arg0->unk_4;
}

void func_00128E18(void) {
}

void func_00128E20(void) {
}
