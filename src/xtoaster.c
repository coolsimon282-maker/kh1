#include "common.h"
#include "libvu0.h"

typedef struct {
    /* 0x00*/ char unk_04[0x44];
    /* 0x44*/ f32 unk_44;
    /* 0x48*/ char unk_48[0x4];
    /* 0x4C*/ u16 unk_4C;
    /* 0x4E*/ char unk_4E[0x11];
    /* 0x5F*/ u8 unk_5F;
} XToast;

typedef struct XToaster {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ char unk_004[0x2C];
    /* 0x030 */ sceVu0FVECTOR unk_030;
    /* 0x040 */ sceVu0FVECTOR unk_040;
    /* 0x050 */ char unk_050[0x24];
    /* 0x074 */ struct XToaster* unk_074;
    /* 0x078 */ s32 unk_078;
    /* 0x07C */ char unk_07C[0x4];
    /* 0x080 */ s32 unk_080;
    /* 0x084 */ char unk_084[0xAC];
    /* 0x130 */ XToast* unk_130;
    /* 0x134 */ u8* unk_134;
    /* 0x138 */ char unk_138[0x14];
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
    /* 0x38C */ char unk_38C[0x14];
    /* 0x3A0 */ s32 unk_3A0;
    /* 0x3A4 */ char unk_3A4[0x6C];
    /* 0x410 */ f32 unk_410;
    /* 0x414 */ f32 unk_414;
    /* 0x418 */ char unk_418[0x98];
} XToaster; /* size = 0x4B0 */

extern XToaster D_002C64A0[];
extern XToaster D_002E26A0[];

void func_00123AB8(XToaster* arg0);
XToaster* func_00123880(s32 arg0);
void func_00123C90(XToaster* arg0, s32 arg1);
void func_00124BC8(XToaster* arg0);
XToaster* func_001234A0(XToaster* arg0);
s32 func_00123768(XToaster* arg0);
void func_00124CD8(void);
void func_00136D38(XToaster* arg0);
void func_00162110(s32 arg0, void* arg1);
void func_00149860(XToaster* arg0);

#define XT_FLAGS(p) (*(u64*)&(p)->unk_1D4[0x19C])

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

XToaster* func_001234A0(XToaster* p) {
    if (p == NULL) {
        p = D_002C64A0;
    } else {
        p++;
    }
    for (; p < D_002E26A0; p++) {
        if ((XT_FLAGS(p) & 0x300000000) == 0x100000000) {
            return p;
        }
    }
    return NULL;
}

s64 func_00123518(XToaster* arg0, XToaster* arg1) {
    s64 ret = 0;
    if (!(arg1->unk_000 & 0x200)) {
        u64 t = (*(u64*)&arg1->unk_1D4[0x19C] >> 37) & 3;
        if (t != 0) {
            ret = t != ((*(u64*)&arg0->unk_1D4[0x19C] >> 37) & 3);
        }
    }
    return ret;
}

XToaster* func_00123558(XToaster* arg0, XToaster* p) {
    while ((p = func_001234A0(p)) != NULL) {
        if (func_00123518(arg0, p)) {
            return p;
        }
    }
    return NULL;
}

static inline u64 xtoaster_inl_team(XToaster* p) {
    return (XT_FLAGS(p) >> 37) & 3;
}

XToaster* func_001235B8(XToaster* arg0, XToaster* p) {
    while ((p = func_001234A0(p)) != NULL) {
        if (arg0 != p && xtoaster_inl_team(arg0) == xtoaster_inl_team(p)) {
            return p;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123620);

s32 func_00123698(void) {
    s32 n = 0;
    XToaster* p = NULL;
    while ((p = func_001234A0(p)) != NULL) {
        if (((XT_FLAGS(p) >> 37) & 3) == 2) {
            n++;
        }
    }
    return n;
}

s32 func_001236F0(XToaster* arg0) {
    s32 ret = 0;
    if (arg0->unk_134 != NULL && arg0->unk_134[4] != 0 && arg0->unk_3A0 == 0) {
        if ((*(u64*)arg0 & 0x8010) == 0x8000) {
            ret = 1;
        }
    }
    return ret;
}

s32 func_00123730(XToaster* arg0) {
    s32 ret = 0;
    if (arg0->unk_134 != NULL && arg0->unk_134[5] != 0) {
        if ((*(u64*)arg0 & 0x8020) == 0x8000) {
            ret = 1;
        }
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00123768);

static inline s32 xtoaster_inl_001237E8(XToaster* arg0) {
    if (arg0->unk_000 & 0x1000080) {
        return 0;
    }
    return 1;
}

s32 func_001237E8(XToaster* arg0) {
    s32 ret = 0;
    if (func_00123768(arg0)) {
        ret = xtoaster_inl_001237E8(arg0);
    }
    return ret;
}

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

s32 func_001239D8(s32 arg0) {
    XToaster* p = func_00123880(arg0);
    if (p != NULL) {
        return p->unk_130->unk_4C;
    }
    return 0xFF;
}

void func_00123A08(s32 arg0, s32 arg1) {
    func_00123880(arg0)->unk_000 |= 1 << arg1;
}

void func_00123A40(s32 arg0, s32 arg1) {
    func_00123880(arg0)->unk_000 &= ~(1 << arg1);
}

s32 func_00123A80(s32 arg0, s32 arg1) {
    return func_00123880(arg0)->unk_000 & (1 << arg1);
}

void func_00123AB8(XToaster* arg0) {
    if (!((XT_FLAGS(arg0) >> 39) & 1)) {
        if (arg0->unk_154 != 0) {
            func_00162110(arg0->unk_154, &arg0->unk_158[4]);
            if (arg0->unk_14C != 0) {
                func_00149860(arg0);
            }
            arg0->unk_154 = 0;
            arg0->unk_134 = NULL;
        }
    }
}

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

void func_00123E78(s32 arg0, sceVu0FVECTOR arg1) {
    XToaster* p = func_00123880(arg0);
    XT_FLAGS(p) |= 0x100000000000;
    sceVu0CopyVector(p->unk_030, arg1);
    func_00136D38(p);
}

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
void fm_func_001249D8(void) {
    XToaster* p = NULL;
    func_00124CD8();
    while ((p = func_001234A0(p)) != NULL) {
        func_00124BC8(p);
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124DD0);

INCLUDE_ASM("asm/nonmatchings/xtoaster", func_00124F38);
