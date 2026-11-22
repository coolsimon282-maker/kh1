#include "common.h"

#include "memcard.h"
#include "xtango.h"
#include "xpotato.h"
#include "xcursed.h"

#include "string.h"

typedef struct {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
} XScotch;

typedef struct {
    /* 0x0 */ u8 unk_00;
    /* 0x2 */ u16 unk_02;
    /* 0x4 */ u32 unk_04;
    /* 0x8 */ u32 unk_08;
} XBravo;

u16 D_003DE5F0[12];
u32 D_003DE630[10];
s32 D_003DE690[3];
s32 D_003DE6A0;

extern XBravo* func_00147AE8(s32);
void func_001F0C28(void);
extern void func_0021D2B0();
extern void func_0022F888();

typedef struct {
    /* 0x000 */ char unk_000[0x499];
    /* 0x499 */ u8 unk_499[0x100];
    /* 0x599 */ u8 unk_599[48];
} XTangoUnk3010F8;

typedef struct {
    /* 0x00 */ char unk_00[0x30];
    /* 0x30 */ s8 unk_30;
} XTangoUnk30;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0xE0];
} XTangoUnkE4; // size = 0xE4

extern XTangoUnkE4 D_003E3E50[];

typedef struct {
    /* 0x00 */ char unk_00[0xE0];
    /* 0xE0 */ s32 unk_E0;
} XTangoUnkE4b; // size = 0xE4

extern XTangoUnkE4b D_003E3D70[];

typedef struct {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19[0x19];
    /* 0x32 */ u8 unk_32;
    /* 0x33 */ char unk_33[0xD];
    /* 0x40 */ u8 unk_40[48];
    /* 0x70 */ char unk_70[4];
} XTangoChar; // size = 0x74

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ XTangoChar chars[1];
} XTangoParty;

void func_00141B10(s32, s32*);
s32 func_001F0960(s32);
extern s32 D_003E3D20[];
extern u32 D_003E3D48[];
extern XTangoUnk30* func_001496C8(void);
void fm_func_00111B10(void);
void fm_func_00111B48(void);
void fm_func_00111B90(void);
void fm_func_00111BE8(void);
extern u16 D_003E3CD0[];
void func_001EDC50(void*);
void func_001EDCD8(f32);
u32 func_00147808(u16);


extern volatile u32 D_002BBDF4;
extern f32 D_002BBDEC;

u32 func_001EF210(void) {
    return D_002BBDF4 * D_002BBDEC;
}

u32 func_001EF298(void) {
    return func_001EF210() / 216000;
}

u32 func_001EF2D0(void) {
    return func_001EF210() / 3600;
}

u32 func_001EF300(void) {
    return func_001EF210() / 60;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF330);

u32 func_001EF3D0(void) {
    return func_001EF210() / 216000;
}

u32 func_001EF408(void) {
    return (func_001EF210() / 3600) % 60;
}

u32 func_001EF448(void) {
    return (func_001EF210() / 60) % 60;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF488);

#ifdef VERSION_FM
void fm_func_001EE428(void) {
    fm_func_00111B10();
}
#endif

#ifdef VERSION_FM
void func_001EF530(void) {
    fm_func_00111B48();
}
#else
INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF530);
#endif

#ifdef VERSION_FM
void func_001EF5C8(void) {
    fm_func_00111B90();
}
#else
INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF5C8);
#endif

#ifdef VERSION_FM
void func_001EF668(void) {
    fm_func_00111BE8();
}
#else
INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF668);
#endif

s32 func_001EF708(u32 arg0) {
    s32 ret = 0;
    s32 mul = 1;

    do {
        ret += (arg0 & 0xF) * mul;
        arg0 >>= 4;
        mul *= 10;
    } while (arg0 != 0);
    return ret;
}

void func_001EF810(void) {
    D_003ED718 = func_0022F768(5);
}

void func_001EF840(void) {
    func_0022F888();
    func_00218A10();
    D_003ED718->munny = 0;
    func_00215A88();
    func_0021D2B0();
}

#ifdef VERSION_FM
void func_001EF878(void);
INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF878);
#else
void func_001EF878(void) {
    func_00230068();
    memcard_Initialize();
    func_001F0D88(); // in xbiscuit
    func_001F3738(); // in xbiscuit
    func_001F0C28();
    func_0020D538();
    func_00229DC8();
    func_0022A8B0();
    func_0022AED0();
    func_0022B338();
    func_0022BB00();
    func_0022BB08();
    func_0022E530();
    func_0022F218();
    func_0022F570();
}
#endif

void func_001EF900(void) {
    u8 buf[16];

    memset(buf, 0, sizeof(buf));
    func_001EDC50(buf);
    func_001EDCD8(0.0f);
}

s32 func_001EF938(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[arg0]);
}

s32 func_001EF960(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[D_003010F8->unk_48E[arg0]]);
}

s32 func_001EF998(s32 arg0) {
    if (arg0 > 16) {
        arg0 = 0;
    }
    return func_001F0EF0(D_003E3CD0[arg0]);
}

XScotch* func_001EF9C8(s32 arg0) {
    return (XScotch*)func_00147A88(arg0);
}

#ifdef VERSION_FM
u32 func_001EF9E0(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return func_00147808(obj->unk_00);
    }
    return func_001F0EF0(151);
}
#else
u32 func_001EF9E0(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return func_00147A50(obj->unk_00);
    }
    return func_001F0EF0(160);
}
#endif

#ifdef VERSION_FM
u32 func_001EFA18(s32 arg0) {
    if (arg0 > 0 && arg0 < 256) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return obj->unk_0C;
    }
    return 0;
}
#else
u32 func_001EFA18(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return obj->unk_0C;
    }
    return 0;
}
#endif

u16 func_001EFA48(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_08;
}

u16 func_001EFA68(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_0A;
}

s16 func_001EFA88(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_06;
}

u8 func_001EFAA8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_02;
}

u8 func_001EFAC8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_03;
}

u16 func_001EFAE8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_10;
}

u16 func_001EFB08(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_04 & 1;
}

s32 func_001EFB30(s32 arg0) {
    s32 n = D_003DE6A0;
    s32 i = 0;

    do {
        if (func_001495C8(arg0, D_003010F8->unk_48E[i++]) != 0) {
            return 1;
        }
        n--;
    } while (n != 0);
    return 0;
}

s8 func_001EFBB0(s32 arg0, s32 arg1) {
    s8 bVar1;
    int iVar3;

    if (func_001EFB08(arg0) != 0) {
        arg1 = 0;
        iVar3 = D_003DE6A0;
    } else {
        iVar3 = 1;
    }

    do {
        if (func_001495C8(arg0, (u32)D_003010F8->unk_48E[arg1]) != 0) {
            return 1;
        }
        iVar3--;
        arg1++;
    } while (iVar3 != 0);
    return 0;
}

#ifdef VERSION_FM
s32 fm_func_001EE900(s32 arg0) {
    s32 flags = func_001495C8(arg0, 0);
    s32 i;

    for (i = 1; i < 7; i++) {
        if ((flags >> i) & 1) {
            return i;
        }
    }
    return -1;
}
#endif

s32 func_001EFC40(s32 arg0, s32 arg1) {
    s32 flags = func_001495C8(arg0, arg1);
    s32 i;

    if (flags & 1) {
        for (i = 1; i < 7; i++) {
            if ((flags >> i) & 1) {
                return i;
            }
        }
    }
    return -1;
}

s32 func_001EFC98(s32 arg0) {
    return func_001EFAA8(arg0) != 13;
}

s32 func_001EFCC0(s32 arg0) {
    return func_001EFAA8(arg0) == 0;
}

s32 func_001EFCE0(s32 arg0, s32 arg1) {
    s32 type;

    if (arg0 != 0) {
        type = func_001EFAA8(arg0);
        if (type >= 2 && type <= 11) {
            if (type != D_003E3D20[arg1]) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

s32 func_001EFD40(s32 arg0) {
    XScotch* obj;
    u32 i;

    if (arg0 != 0) {
        obj = (XScotch*)func_00147A88(arg0);
        for (i = 0; i < 3; i++) {
            if (obj->unk_02 == D_003E3D48[i]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_001EFDA0(s32 arg0) {
    XScotch* obj;

    if (arg0 != 0) {
        obj = (XScotch*)func_00147A88(arg0);
        if (obj->unk_02 == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_001EFDD0(s32 arg0) {
    return func_001BC390(arg0);
}

s32 func_001EFDE8(s32 arg0) {
    return func_001BC370(arg0);
}

s32 func_001EFE00(void) {
    s32 sVar1 = func_001BC578();
    s32 iVar2 = 0;
    s32 iVar3 = 0;
    s32 iVar4 = 0;
    s32 iVar5;

    if (0 < sVar1) {
        do {
            iVar5 = iVar2 + 1;
            iVar2 = func_001BC590(iVar2);
            iVar4 += iVar2;
            iVar2 = iVar5;
            iVar3 = iVar4;
        } while (iVar5 < sVar1);
    }
    return iVar4;
}

#ifdef VERSION_FM
s32 func_001EFE68(s32 arg0);
s32 func_001EFE68(s32 arg0) {
    if (arg0 != 0) {
        return func_001EF9E0(arg0);
    }
    return func_001F0EF0(167);
}
#else
s32 func_001EFE68(s32 arg0) {
    if (arg0 != 0) {
        return func_001EF9E0(arg0);
    }
    return func_001F0EF0(176);
}
#endif

#ifdef VERSION_FM
s32 func_001EFE90(s32 arg0);
s32 func_001EFE90(s32 arg0) {
    if (arg0 != 0) {
        return func_001EF9E0(arg0);
    }
    return func_001F0EF0(167);
}
#else
s32 func_001EFE90(s32 arg0) {
    if (arg0 != 0) {
        return func_001EF9E0(arg0);
    }
    return func_001F0EF0(176);
}
#endif

#ifdef VERSION_FM
s32 func_001EFEB8(s32 arg0);
s32 func_001EFEB8(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFA18(arg0);
    }
    return func_001F0EF0(168);
}
#else
s32 func_001EFEB8(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFA18(arg0);
    }
    return func_001F0EF0(177);
}
#endif

#ifdef VERSION_FM
s32 func_001EFEE0(s32 arg0);
s32 func_001EFEE0(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFA18(arg0);
    }
    return func_001F0EF0(168);
}
#else
s32 func_001EFEE0(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFA18(arg0);
    }
    return func_001F0EF0(177);
}
#endif

s32 func_001EFF08(void) {
    return func_001496C8()->unk_30;
}

s32 func_001EFF28(s32 arg0, u8 arg1) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_32;

    chr->unk_32 = arg1;
    func_00141B10(arg0, buf);
    chr->unk_32 = save;
    return buf[19];
}

s32 func_001EFF90(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[15];
}

s32 func_001EFFF8(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[17];
}

s32 func_001F0060(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[56];
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F00C8);

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0130);

s32 func_001F0198(s32 arg0) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        s32 idx = D_003010F8->unk_48E[i];
        XTangoChar* chr;

        if (idx == 0xFF) {
            break;
        }
        chr = &((XTangoParty*)D_003010F8)->chars[idx];
        if (chr->unk_32 == arg0) {
            count++;
        }
    }
    return count;
}

s32 func_001F0218(s32 arg0) {
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        s32 idx = D_003010F8->unk_48E[i];
        XTangoChar* chr;

        if (idx == 0xFF) {
            break;
        }
        chr = &((XTangoParty*)D_003010F8)->chars[idx];
        for (j = 0; j < chr->unk_18; j++) {
            if (chr->unk_19[j] == arg0) {
                count++;
            }
        }
    }
    return count;
}

s32 func_001F02B8(s32 arg0, s32 arg1) {
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        XTangoChar* chr;

        if (i == arg1) {
            continue;
        }
        chr = &((XTangoParty*)D_003010F8)->chars[i];
        for (j = 0; j < chr->unk_18; j++) {
            if (chr->unk_19[j] == arg0) {
                count++;
            }
        }
    }
    return count;
}

s32 func_001F0330(s32 arg0) {
    s32 count = 0;
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[i];

        if (chr->unk_32 == arg0) {
            count++;
        }
        for (j = 0; j < chr->unk_18; j++) {
            if (chr->unk_19[j] == arg0) {
                count++;
            }
        }
    }
    return count;
}

s32 func_001F03A0(s32 arg0) {
    s32 count = ((XTangoUnk3010F8*)D_003010F8)->unk_499[arg0];
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[i];

        if (chr->unk_32 == arg0) {
            count--;
        }
        for (j = 0; j < chr->unk_18; j++) {
            if (chr->unk_19[j] == arg0) {
                count--;
            }
        }
    }
    if (count < 0) {
        count = 0;
    }
    return count;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0420);

s32 func_001F0530(s32 arg0) {
    return func_001EFAA8(arg0) - 2;
}

s32 func_001F0550(s32 arg0, s32 idx) {
    if (arg0 != 0) {
        return func_001EFAA8(arg0) == D_003DE630[idx];
    }
    return FALSE;
}

s32 func_001F05A0(s32 arg0) {
    u32 type;
    u32 i;

    if (arg0 != 0) {
        type = func_001EFAA8(arg0);
        for (i = 0; i < 10; i++) {
            if (type == D_003DE630[i]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_001F0600(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_003010F8->unk_036 == D_003DE690[i]) {
            return 0;
        }
    }
    return 1;
}

s32 func_001F0650(s32 arg0) {
    if (arg0 != 0) {
        return func_001EFAA8(arg0) == 1;
    }
    return FALSE;
}

s32 func_001F0680(s32 arg0) {
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    s32 i;

    for (i = 0; i < 48; i++) {
        if (chr->unk_40[i] == 0) {
            break;
        }
    }
    return i;
}

s32 func_001F06E8(void) {
    s32 i;

    for (i = 0; i < 48; i++) {
        if (((XTangoUnk3010F8*)D_003010F8)->unk_599[i] == 0) {
            break;
        }
    }
    return i;
}

s32 func_001F0730(s32 arg0, s32 arg1) {
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    s32 count = 0;
    s32 i;

    for (i = 0; i < 48; i++) {
        s32 c = chr->unk_40[i];

        if (c == 0) {
            break;
        }
        if ((c & ~0x80) == arg1) {
            count++;
        }
    }
    return count;
}

s32 func_001F07A0(s32 arg0) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 48; i++) {
        s32 c = ((XTangoUnk3010F8*)D_003010F8)->unk_599[i];

        if (c == 0) {
            break;
        }
        if ((c & ~0x80) == arg0) {
            count++;
        }
    }
    return count;
}

XBravo* func_001F0808(s32 arg0) {
    return func_00147AE8(arg0);
}

#ifdef VERSION_FM
u32 func_001F0820(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_04;
    }
    return func_001F0EF0(180);
}
#else
u32 func_001F0820(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_04;
    }
    return func_001F0EF0(189);
}
#endif

#ifdef VERSION_FM
u32 func_001F0860(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_08;
    }
    return func_001F0EF0(180);
}
#else
u32 func_001F0860(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_08;
    }
    return func_001F0EF0(189);
}
#endif

u8 func_001F08A0(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_00;
    }
    return 0;
}

u16 func_001F08D8(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_02;
    }
    return 0;
}

s32 func_001F0910(s32 arg0, s32 arg1) {
    return func_001F0EF0(arg0 * 3 + arg1 + 0xD4);
}

s32 func_001F0938(s32 arg0) {
    return D_003E3E50[arg0].unk_00;
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0960);

s32 func_001F0A00(s32 arg0) {
    XTangoUnkE4b* entry = &D_003E3D70[arg0];
    s32 diff = entry->unk_E0 - func_001F0960(arg0);

    if (diff < 0) {
        diff = 0;
    }
    return diff;
}

void func_001F0A58(u32 arg0) {
    D_003ED718->munny = arg0 <= 99999 ? arg0 : 99999;
}

s32 func_001F0A80(void) {
    return D_003ED718->munny;
}

void func_001F0A90(s32 arg0) {
    s32 val = D_003ED718->munny + arg0;

    D_003ED718->munny = val;
    if (val < 0) {
        D_003ED718->munny = 0;
        return;
    }
    if (val > 99999u) {
        D_003ED718->munny = 99999;
    }
}

void func_001F0AD0(s32 arg0) {
    s32 val = D_003ED718->munny - arg0;

    D_003ED718->munny = val;
    if (val < 0) {
        D_003ED718->munny = 0;
        return;
    }
    if (val > 99999u) {
        D_003ED718->munny = 99999;
    }
}

INCLUDE_ASM("asm/nonmatchings/xtango", func_001F0B10);

s32 func_001F0BD8(s32 arg0) {
    s32 val = func_0013DA88(D_003010F8->unk_48E[arg0]);
    if (val == 0 || func_001233F8(val) == 0) {
        return 0;
    }
    return val;
}

void func_001F0C28(void) {
}
