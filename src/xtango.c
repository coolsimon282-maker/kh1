/**
 * Game data queries: play time, item / weapon / accessory / ability tables, what the ten characters have equipped
 * (D_003010F8 save data: 0x74-byte character records, party slots unk_48E, item stock unk_499), AP costs and munny
 * (GameData buffer, work buffer 5). Item types: 0 usable item, 1 accessory, 2..11 weapons.
 */
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

#ifdef VERSION_FM
extern u16 D_003DE5F0[];
extern u32 D_003DE630[];
extern s32 D_003DE690[];
extern s32 D_003DE6A0;
#else
u16 D_003DE5F0[12];
u32 D_003DE630[10];
s32 D_003DE690[3];
s32 D_003DE6A0;
#endif

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

#ifdef VERSION_FM
// .data (0x003E3CB8-0x003E4654)
u16 D_003DE5F0[12] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19};
u16 D_003E3CD0[20] = {0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A};
u32 D_003DE630[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
s32 D_003E3D20[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
u32 D_003E3D48[4] = {0, 12, 13, 0};
s32 D_003DE690[4] = {0x52, 0x53, 0x54, 0x55};
// Probably one object in the original: a count and ten 0xE4-byte entries (the code reads entry 0 as D_003E3D6C,
// from its +4 as D_003E3D70[], and entries 1.. as D_003E3E50[]). Written as four variables: an equate
// ('name = base + off') for the inner labels makes this old gas misplace the base symbol here.
s32 D_003DE6A0 = 0;
s32 D_003E3D6C = 0;
u8 D_003E3D70_b[0xE0] __asm__("D_003E3D70") = {0}; // the code sees XTangoUnkE4b D_003E3D70[]
XTangoUnkE4 D_003E3E50[9] = {{0}};
#endif

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
s32 Char_GetUsedAP(s32);
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

// Play time in frames: the frame counter D_002BBDF4 times the scale D_002BBDEC.
u32 PlayTime_GetFrames(void) {
    return D_002BBDF4 * D_002BBDEC;
}

// Play time in whole hours (frames / 216000, 60 frames a second).
u32 PlayTime_GetTotalHours(void) {
    return PlayTime_GetFrames() / 216000;
}

// Play time in whole minutes (frames / 3600).
u32 PlayTime_GetTotalMinutes(void) {
    return PlayTime_GetFrames() / 3600;
}

// Play time in whole seconds (frames / 60).
u32 PlayTime_GetTotalSeconds(void) {
    return PlayTime_GetFrames() / 60;
}

// Splits the play time into hours, minutes, seconds and frames.
void PlayTime_Split(u32* h, u32* m, u32* s, u32* f) {
    u32 t = PlayTime_GetFrames();

    *h = t / 216000;
    t %= 216000;
    *m = t / 3600;
    t %= 3600;
    *s = t / 60;
    *f = t % 60;
}

// Hours part of the play time (same as PlayTime_GetTotalHours).
u32 PlayTime_GetHoursPart(void) {
    return PlayTime_GetFrames() / 216000;
}

// Minutes part of the play time (0..59).
u32 PlayTime_GetMinutesPart(void) {
    return (PlayTime_GetFrames() / 3600) % 60;
}

// Seconds part of the play time (0..59).
u32 PlayTime_GetSecondsPart(void) {
    return (PlayTime_GetFrames() / 60) % 60;
}

// Frames part of the play time scaled to hundredths of a second.
u32 PlayTime_GetHundredthsPart(void) {
    return (f32)(PlayTime_GetFrames() % 60) * (100.0f / 60.0f);
}

#ifdef VERSION_FM
// Calls fm_func_00111B10 (FM only).
void fm_func_001EE428(void) {
    fm_func_00111B10();
}
#endif

#ifdef VERSION_FM
// Calls fm_func_00111B48.
void func_001EF530(void) {
    fm_func_00111B48();
}
#else
void func_001EF530(void) {
    fm_func_00111B48();
}
#endif

#ifdef VERSION_FM
// Calls fm_func_00111B90.
void func_001EF5C8(void) {
    fm_func_00111B90();
}
#else
// JP's function is 0xA0 bytes (not a tail call like FM's); EU's calls its own copy of fm_func_00111B90
INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF5C8);
#endif

#ifdef VERSION_FM
// Calls fm_func_00111BE8.
void func_001EF668(void) {
    fm_func_00111BE8();
}
#else
// JP's function is 0xA0 bytes as well; EU's calls its own copy of fm_func_00111BE8
INCLUDE_ASM("asm/nonmatchings/xtango", func_001EF668);
#endif

// Converts a BCD number (one decimal digit per nibble) to binary.
s32 BcdToInt(u32 arg0) {
    s32 ret = 0;
    s32 mul = 1;

    do {
        ret += (arg0 & 0xF) * mul;
        arg0 >>= 4;
        mul *= 10;
    } while (arg0 != 0);
    return ret;
}

// Points D_003ED718 (GameData) at work buffer 5.
void GameData_BindBuffer(void) {
    D_003ED718 = WorkBuffers_Get(5);
}

// Resets several game data subsystems and sets munny to 0.
void GameData_Reset(void) {
    func_0022F888();
    Config_Reset();
    D_003ED718->munny = 0;
    GameData_ResetCharPresets();
    func_0021D2B0();
}

#ifdef VERSION_FM
void func_00233610(void);
void func_00233A80(void);
void fm_func_001EFAA8(void);
void func_001F2EB8(void);
void func_0020D748(void);
void func_0022BD20(void);
void func_0022D138(void);
void func_0022D728(void);
void func_0022DB90(void);
void func_0022DFD0(void);
void func_0022E458(void);
void func_0022EBE8(void);
void func_0022EBF0(void);
void func_002319C0(void);
void func_00232790(void);
void func_00232AC8(void);
// Calls the initialisers of the game data subsystems.
void GameData_Initialize(void) {
    func_00233610();
    func_00233A80();
    fm_func_001EFAA8();
    func_001F2EB8();
    func_001F0C28();
    func_0020D748();
    func_0022BD20();
    func_0022D138();
    func_0022D728();
    func_0022DB90();
    func_0022DFD0();
    func_0022E458();
    func_0022EBE8();
    func_0022EBF0();
    func_002319C0();
    func_00232790();
    func_00232AC8();
}
#else
void GameData_Initialize(void) {
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

// Passes a zeroed 16-byte buffer to func_001EDC50, then func_001EDCD8(0.0f).
void func_001EF900(void) {
    u8 buf[16];

    memset(buf, 0, sizeof(buf));
    func_001EDC50(buf);
    func_001EDCD8(0.0f);
}

// Name message of character arg0 (message id from D_003DE5F0); probably the name.
s32 Char_GetName(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[arg0]);
}

// Name message of the character in party slot arg0 (D_003010F8->unk_48E); probably the name.
s32 Party_GetMemberName(s32 arg0) {
    return func_001F0EF0(D_003DE5F0[D_003010F8->unk_48E[arg0]]);
}

// Message D_003E3CD0[arg0] (0 when arg0 > 16).
s32 func_001EF998(s32 arg0) {
    if (arg0 > 16) {
        arg0 = 0;
    }
    return func_001F0EF0(D_003E3CD0[arg0]);
}

// Item table entry of item arg0 (func_00147A88).
XScotch* Item_GetData(s32 arg0) {
    return (XScotch*)func_00147A88(arg0);
}

#ifdef VERSION_FM
// Name string of item arg0 (from its entry's unk_00), or message 151 for item 0.
u32 Item_GetName(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return func_00147808(obj->unk_00);
    }
    return func_001F0EF0(151);
}
#else
u32 Item_GetName(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return func_00147A50(obj->unk_00);
    }
    return func_001F0EF0(160);
}
#endif

#ifdef VERSION_FM
// Entry unk_0C of item arg0 (1..255), else 0; probably the description string.
u32 Item_GetDescription(s32 arg0) {
    if (arg0 > 0 && arg0 < 256) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return obj->unk_0C;
    }
    return 0;
}
#else
u32 Item_GetDescription(s32 arg0) {
    if (arg0 != 0) {
        XScotch* obj = (XScotch*)func_00147A88(arg0);
        return obj->unk_0C;
    }
    return 0;
}
#endif

// Entry unk_08 of item arg0.
u16 func_001EFA48(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_08;
}

// Entry unk_0A of item arg0.
u16 func_001EFA68(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_0A;
}

// Entry unk_06 of item arg0.
s16 func_001EFA88(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_06;
}

// Item category (entry unk_02): 0 usable item, 1 accessory, 2..11 weapons (by how Char_CountItemEquipped uses it).
u8 Item_GetType(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_02;
}

// Entry unk_03 of item arg0.
u8 func_001EFAC8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_03;
}

// Entry unk_10 of item arg0.
u16 func_001EFAE8(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_10;
}

// Bit 0 of entry unk_04; when set func_001EFBB0 checks every party member, so probably "acts on the whole party".
u16 Item_IsPartyWide(s32 arg0) {
    XScotch* obj = (XScotch*)func_00147A88(arg0);
    return obj->unk_04 & 1;
}

// True when func_001495C8(arg0, member) is set for any current party member.
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

// func_001495C8 test for party slot arg1, or for every member when Item_IsPartyWide(arg0).
s8 func_001EFBB0(s32 arg0, s32 arg1) {
    s8 bVar1;
    int iVar3;

    if (Item_IsPartyWide(arg0) != 0) {
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
// Index 1..6 of the lowest set bit 1..6 of func_001495C8(arg0, 0), else -1 (FM only).
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

// Index 1..6 of the lowest set bit 1..6 of func_001495C8(arg0, arg1) when its bit 0 is set, else -1.
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

// Item type is not 13.
s32 func_001EFC98(s32 arg0) {
    return Item_GetType(arg0) != 13;
}

// Item type is 0 (usable item).
s32 Item_IsUsable(s32 arg0) {
    return Item_GetType(arg0) == 0;
}

// False when arg0 is a weapon (type 2..11) of another type than character arg1's weapon type (D_003E3D20).
s32 Item_CanCharEquip(s32 arg0, s32 arg1) {
    s32 type;

    if (arg0 != 0) {
        type = Item_GetType(arg0);
        if (type >= 2 && type <= 11) {
            if (type != D_003E3D20[arg1]) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

// Item arg0 has one of the three types in D_003E3D48.
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

// Item arg0 is non-zero and of type 0 (usable item).
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

// Calls func_001BC390.
s32 func_001EFDD0(s32 arg0) {
    return func_001BC390(arg0);
}

// Calls func_001BC370.
s32 func_001EFDE8(s32 arg0) {
    return func_001BC370(arg0);
}

// Sum of func_001BC590(i) for i below func_001BC578().
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
s32 Item_GetNameOrNone(s32 arg0);
// Item_GetName, or message 167 for item 0 (FM).
s32 Item_GetNameOrNone(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetName(arg0);
    }
    return func_001F0EF0(167);
}
#else
s32 Item_GetNameOrNone(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetName(arg0);
    }
    return func_001F0EF0(176);
}
#endif

#ifdef VERSION_FM
s32 Item_GetNameOrNone2(s32 arg0);
// Same as Item_GetNameOrNone (a second copy in the game).
s32 Item_GetNameOrNone2(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetName(arg0);
    }
    return func_001F0EF0(167);
}
#else
s32 Item_GetNameOrNone2(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetName(arg0);
    }
    return func_001F0EF0(176);
}
#endif

#ifdef VERSION_FM
s32 Item_GetDescriptionOrNone(s32 arg0);
// Item_GetDescription, or message 168 for item 0 (FM).
s32 Item_GetDescriptionOrNone(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetDescription(arg0);
    }
    return func_001F0EF0(168);
}
#else
s32 Item_GetDescriptionOrNone(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetDescription(arg0);
    }
    return func_001F0EF0(177);
}
#endif

#ifdef VERSION_FM
s32 Item_GetDescriptionOrNone2(s32 arg0);
// Same as Item_GetDescriptionOrNone (a second copy in the game).
s32 Item_GetDescriptionOrNone2(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetDescription(arg0);
    }
    return func_001F0EF0(168);
}
#else
s32 Item_GetDescriptionOrNone2(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetDescription(arg0);
    }
    return func_001F0EF0(177);
}
#endif

// Field unk_30 of func_001496C8()s result.
s32 func_001EFF08(void) {
    return func_001496C8()->unk_30;
}

// Character arg0's stat 19 (func_00141B10 stats) with weapon arg1 equipped for the test; probably strength.
s32 Char_PreviewWeaponStat19(s32 arg0, u8 arg1) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_32;

    chr->unk_32 = arg1;
    func_00141B10(arg0, buf);
    chr->unk_32 = save;
    return buf[19];
}

// Character arg0's stat 15 with accessory slot arg1 set to arg2 for the test.
s32 Char_PreviewAccessoryStat15(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[15];
}

// Character arg0's stat 17 with accessory slot arg1 set to arg2 for the test.
s32 Char_PreviewAccessoryStat17(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[17];
}

// Character arg0's stat 56 (max AP, see Char_GetMaxAP) with accessory slot arg1 set to arg2.
s32 Char_PreviewAccessoryMaxAP(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[56];
}

// Character arg0's stat 19 with accessory slot arg1 set to arg2 for the test.
s32 Char_PreviewAccessoryStat19(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[19];
}

// Character arg0's stat 20 with accessory slot arg1 set to arg2 for the test.
s32 Char_PreviewAccessoryStat20(s32 arg0, s32 arg1, u8 arg2) {
    s32 buf[60];
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    u8 save = chr->unk_19[arg1];

    chr->unk_19[arg1] = arg2;
    func_00141B10(arg0, buf);
    chr->unk_19[arg1] = save;
    return buf[20];
}

// Number of current party members whose weapon (unk_32) is arg0.
s32 Party_CountWeaponUsers(s32 arg0) {
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

// Number of arg0 accessories equipped by current party members.
s32 Party_CountAccessoryEquipped(s32 arg0) {
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

// Number of arg0 accessories equipped by the ten characters other than arg1.
s32 Char_CountAccessoryOnOthers(s32 arg0, s32 arg1) {
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

// Number of arg0 equipped (as weapon or accessory) by all ten characters.
s32 Char_CountEquippedAll(s32 arg0) {
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

// Stock of item arg0 (unk_499) minus the copies equipped by the ten characters, at least 0.
s32 Inventory_GetFreeCount(s32 arg0) {
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

// How many arg1 character arg0 holds: in item slots (type 0), accessory slots (type 1) or as weapon.
s32 Char_CountItemEquipped(s32 arg0, s32 arg1) {
    s32 count = 0;
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    s32 type = Item_GetType(arg1);

    if (type == 0) {
        s32 n = chr->unk_19[8];
        s32 j;
        for (j = 0; j < n; j++) {
            if (chr->unk_19[9 + j] == arg1) {
                count++;
            }
        }
    } else if (type == 1) {
        s32 n = chr->unk_18;
        s32 j;
        for (j = 0; j < n; j++) {
            if (chr->unk_19[j] == arg1) {
                count++;
            }
        }
    } else if ((u32)(type - 2) < 10) {
        count = chr->unk_32 == arg1;
    }
    return count;
}

// Item type - 2 (weapon type index).
s32 Item_GetWeaponIndex(s32 arg0) {
    return Item_GetType(arg0) - 2;
}

// Item arg0's type is weapon type D_003DE630[idx].
s32 Item_IsWeaponType(s32 arg0, s32 idx) {
    if (arg0 != 0) {
        return Item_GetType(arg0) == D_003DE630[idx];
    }
    return FALSE;
}

// Item arg0's type is one of the ten weapon types in D_003DE630.
s32 Item_IsWeapon(s32 arg0) {
    u32 type;
    u32 i;

    if (arg0 != 0) {
        type = Item_GetType(arg0);
        for (i = 0; i < 10; i++) {
            if (type == D_003DE630[i]) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// True when D_003010F8->unk_036 is none of the four values in D_003DE690.
s32 func_001F0600(void) {
    s32 i;

    for (i = 3; i >= 0; i--) {
        if (D_003010F8->unk_036 == D_003DE690[i]) {
            return 0;
        }
    }
    return 1;
}

// Item arg0 is non-zero and of type 1 (accessory).
s32 Item_IsAccessory(s32 arg0) {
    if (arg0 != 0) {
        return Item_GetType(arg0) == 1;
    }
    return FALSE;
}

// Number of abilities in character arg0's ability list (unk_40, 0-terminated, 48 max).
s32 Char_GetAbilityCount(s32 arg0) {
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    s32 i;

    for (i = 0; i < 48; i++) {
        if (chr->unk_40[i] == 0) {
            break;
        }
    }
    return i;
}

// Number of entries in the 48-entry list at D_003010F8 + 0x599 (0-terminated, like a character ability list).
s32 func_001F06E8(void) {
    s32 i;

    for (i = 0; i < 48; i++) {
        if (((XTangoUnk3010F8*)D_003010F8)->unk_599[i] == 0) {
            break;
        }
    }
    return i;
}

// Number of entries of ability arg1 in character arg0's list (bit 0x80 ignored).
s32 Char_CountAbility(s32 arg0, s32 arg1) {
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

// Number of entries arg0 in the list at D_003010F8 + 0x599 (bit 0x80 ignored).
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

// Ability table entry (func_00147AE8).
XBravo* Ability_GetData(s32 arg0) {
    return func_00147AE8(arg0);
}

#ifdef VERSION_FM
// Entry unk_04 of ability arg0 (bit 0x80 cleared), or message 180 (FM); probably the name.
u32 Ability_GetName(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_04;
    }
    return func_001F0EF0(180);
}
#else
u32 Ability_GetName(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_04;
    }
    return func_001F0EF0(189);
}
#endif

#ifdef VERSION_FM
// Entry unk_08 of ability arg0, or message 180 (FM); probably the description.
u32 Ability_GetDescription(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_08;
    }
    return func_001F0EF0(180);
}
#else
u32 Ability_GetDescription(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_08;
    }
    return func_001F0EF0(189);
}
#endif

// Entry unk_00 of ability arg0; summed by Char_GetUsedAP, so the AP cost.
u8 Ability_GetApCost(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_00;
    }
    return 0;
}

// Entry unk_02 of ability arg0.
u16 func_001F08D8(s32 arg0) {
    if (arg0 != 0) {
        return func_00147AE8(arg0 & ~0x80)->unk_02;
    }
    return 0;
}

// Message 0xD4 + arg0 * 3 + arg1.
s32 func_001F0910(s32 arg0, s32 arg1) {
    return func_001F0EF0(arg0 * 3 + arg1 + 0xD4);
}

// Stat 56 of character arg0 (D_003E3E50 = D_003E3D70 + 0xE0, the stats func_00141B10 fills); max AP by Char_GetFreeAP.
s32 Char_GetMaxAP(s32 arg0) {
    return D_003E3E50[arg0].unk_00;
}

// Sum of the AP cost of character arg0's abilities without bit 0x80 (equipped ones, probably).
s32 Char_GetUsedAP(s32 arg0) {
    XTangoChar* chr = &((XTangoParty*)D_003010F8)->chars[arg0];
    s32 sum = 0;
    s32 i = 0;
    u8* p = chr->unk_40;
    s32 c;

loop:
    if (i >= 48) {
        goto end;
    }
    i++;
    c = *p++;
    if (c == 0) {
        goto end;
    }
    if (c & 0x80) {
        goto loop;
    }
    sum += Ability_GetApCost(c);
    goto loop;
end:
    return sum;
}

// Character arg0's stat 56 minus Char_GetUsedAP, at least 0.
s32 Char_GetFreeAP(s32 arg0) {
    XTangoUnkE4b* entry = &D_003E3D70[arg0];
    s32 diff = entry->unk_E0 - Char_GetUsedAP(arg0);

    if (diff < 0) {
        diff = 0;
    }
    return diff;
}

// Sets munny (at most 99999).
void Munny_Set(u32 arg0) {
    D_003ED718->munny = arg0 <= 99999 ? arg0 : 99999;
}

// Returns munny.
s32 Munny_Get(void) {
    return D_003ED718->munny;
}

// Adds to munny, clamped to 0..99999.
void Munny_Add(s32 arg0) {
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

// Subtracts from munny, clamped to 0..99999.
void Munny_Sub(s32 arg0) {
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

extern s32 D_003E3D6C;

// Counts party members (D_003E3D6C, D_003DE6A0 with slot 3) and recomputes the stats (D_003E3D70) of all ten characters.
void Party_RefreshStats(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (D_003010F8->unk_48E[i] == 0xFF) {
            break;
        }
    }
    D_003E3D6C = i;
    D_003DE6A0 = i;
    if (D_003010F8->unk_48E[3] != 0xFF) {
        D_003DE6A0 = i + 1;
    }
    for (i = 0; i < 10; i++) {
        func_00141B10(i, (s32*)&D_003E3D70[i]);
    }
}

// func_0013DA88 of party slot arg0s character when non-zero and Actor_IsActive accepts it, else 0.
s32 func_001F0BD8(s32 arg0) {
    s32 val = func_0013DA88(D_003010F8->unk_48E[arg0]);
    if (val == 0 || Actor_IsActive(val) == 0) {
        return 0;
    }
    return val;
}

// Empty.
void func_001F0C28(void) {
}
