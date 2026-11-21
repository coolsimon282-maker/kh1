#include "common.h"
#include "libvu0.h"

typedef struct {
    /* 0x00*/ char unk_04[0x44];
    /* 0x44*/ f32 unk_44;
    /* 0x48*/ char unk_48[0x17];
    /* 0x5F*/ u8 unk_5F;
} XToast;

typedef struct {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ char unk_004[0x3C];
    /* 0x040 */ sceVu0FVECTOR unk_040;
    /* 0x050 */ char unk_050[0xE0];
    /* 0x130 */ XToast* unk_130;
    /* 0x134 */ char unk_134[0x18];
    /* 0x14C */ s32 unk_14C;
    /* 0x150 */ s32 unk_150;
    /* 0x154 */ s32 unk_154;
    /* 0x158 */ char unk_158[0x78];
    /* 0x1D0 */ s32 unk_1D0;
    /* 0x1D4 */ char unk_1D4[0x1A0];
    /* 0x374 */ s32 unk_374;
    /* 0x378 */ s32 unk_378;
    /* 0x37C */ s32 unk_37C[3];
    /* 0x388 */ s32 unk_388;
    /* 0x38C */ char unk_38C[0x84];
    /* 0x410 */ f32 unk_410;
    /* 0x414 */ f32 unk_414;
} XToaster;

void func_00123AB8(XToaster* arg0);
XToaster* func_00123880(s32 arg0);
void func_00123C90(XToaster* arg0, s32 arg1);
void func_00124BC8(XToaster* arg0);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487018);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487020);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487028);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487030);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487038);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487040);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487048);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487050);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487058);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487060);

INCLUDE_RODATA("asm/nonmatchings/xtoaster", D_00487068);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001231E0);

void func_00123318(XToaster* arg0, s32* arg1) {
    arg1[0] = arg0->unk_154;
    if (arg0->unk_14C != 0) {
        arg1[1] = *(s32*)arg0->unk_14C;
    } else {
        arg1[1] = 0;
    }
    arg1[2] = arg0->unk_1D0;
}

void func_00123340(f32 arg0, XToaster* arg1) {
    arg1->unk_130->unk_44 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123350);

static inline s32 xtoaster_inl_001233D0(XToaster* arg0) {
    if (arg0->unk_000 & 0x2000000) {
        return 0;
    }
    return 1;
}

s32 func_001233D0(XToaster* arg0) {
    s32 ret = 0;
    if (arg0->unk_130->unk_5F) {
        ret = xtoaster_inl_001233D0(arg0);
    }
    return ret;
}

s32 func_001233F8(XToaster* arg0) {
    s32 ret = 0;
    if (arg0 != NULL) {
        if ((*(u64*)&arg0->unk_1D4[0x19C] & 0x300000000) == 0x100000000) {
            ret = 1;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123430);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001234A0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123518);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123558);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001235B8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123620);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123698);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001236F0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123730);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123768);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001237E8);

void func_00123830(XToaster* arg0, s32 arg1) {
    arg0->unk_37C[arg0->unk_388++] = arg0->unk_000;
    arg0->unk_000 = arg1;
}

void func_00123858(XToaster* arg0) {
    if (arg0->unk_388 > 0) {
        arg0->unk_000 = arg0->unk_37C[--arg0->unk_388];
    }
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123880);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001239D8);

void func_00123A08(s32 arg0, s32 arg1) {
    func_00123880(arg0)->unk_000 |= 1 << arg1;
}

void func_00123A40(s32 arg0, s32 arg1) {
    func_00123880(arg0)->unk_000 &= ~(1 << arg1);
}

s32 func_00123A80(s32 arg0, s32 arg1) {
    return func_00123880(arg0)->unk_000 & (1 << arg1);
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123AB8);

void func_00123B20(XToaster* arg0) {
    func_00123AB8(arg0);
    arg0->unk_000 = 0;
    arg0->unk_374 = 0;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123B50);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123BD0);

void func_00123C80(XToaster* arg0, f32 arg1, f32 arg2) {
    arg0->unk_410 = arg1;
    arg0->unk_414 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123C90);

void func_00123E48(s32 arg0, s32 arg1) {
    func_00123C90(func_00123880(arg0), arg1);
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123E78);

void func_00123ED0(s32 arg0, sceVu0FVECTOR arg1) {
    sceVu0CopyVector(func_00123880(arg0)->unk_040, arg1);
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123F00);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124108);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001242E8);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124420);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_001245F0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124BC8);

void func_00124CA0(s32 arg0) {
    XToaster* p = func_00123880(arg0);
    if (p != NULL) {
        func_00124BC8(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124CD8);

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xtoaster", fm_func_001249D8);
#endif

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124DD0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124F38);
