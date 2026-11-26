/**
 * Pause menu pages, probably: the per-character preset tables (GameData unk_20, applied with func_00170D60), party member
 * selection lists, and the config options kept in the GameData buffer (D_003ED718, words 0x00..0x18 and 0x2C) with
 * their get/set helpers and two-choice menu pages. Menu pages are UI objects (func_001F3A20 creates, UiObject_InsertAfter
 * links); D_00425BC8[2] & 0x4000 is probably the cancel button (it closes the page).
 */
#include "xtango.h"
#include "xpotato.h"

extern s32 D_00642CC8;
extern s32 D_00642CA8[];
extern s32 func_00132FE0(s32);

extern s32 Party_GetMemberName(u32);
extern s32 D_003E8E08;

extern s32 D_003F4BD0[];
extern s32 D_00642D24;

extern s32 D_003F47B8[];

extern void func_001F9010(s32);
extern s32 func_001F9438(void*, s32, s32, s32, s32, s32, u32);
extern s32 D_003F4488[];

extern s32 func_00207830(s32, s32, s32, s32, s32, s32, s32);

extern void func_001EFBB8(s32);

extern s32 D_003F47A8[];

extern s32 D_002B6478;

extern u32 D_003DE6A0;
extern s32 D_003E3088;
extern s32 D_003ED728;
extern s32 D_003ED72C;
extern u32 D_003ED730;
extern s32 D_003EE8B0;

extern void* D_0063CF00;
extern s32 D_0063CF04;
extern u32 D_0063CF18;
extern u32 D_0063CF38;
extern u32 D_0063CF3C;
extern u32 D_0063CF40;
extern u32 D_0063CF44;
extern u32 D_0063CF48;
extern u32 D_0063CF4C;
extern u32 D_0063CF50;
extern u32 D_0063CF88;
extern u32 D_0063CFA0;
extern u32 D_0063D050;

extern void* func_001F3A20(void*, s32);
extern void func_001F9B50(s32);

// Sets the preset (GameData unk_20[i]) of all ten characters to 4 and applies it.
void GameData_ResetCharPresets(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_003ED718->unk_20); i++) {
        D_003ED718->unk_20[i] = 4;
        GameData_ApplyCharPreset(i, 4);
    }
}

#ifdef VERSION_FM
extern s32* D_003F41E8[];
extern s32 D_003F4200[][9];
extern void func_00170D60(s32, s32, s32);

// Applies preset arg1 to character arg0: nine func_00170D60(arg0, i, value) calls from table D_003F41E8[arg1], or the character's own D_003F4200 row for preset 4.
void GameData_ApplyCharPreset(s32 arg0, s32 arg1) {
    s32* p;
    s32 i;
    if (arg1 != 4) {
        p = D_003F41E8[arg1];
    } else {
        p = D_003F4200[arg0];
    }
    for (i = 0; i < 9; i++) {
        func_00170D60(arg0, i, p[i]);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xpotato", GameData_ApplyCharPreset);
#endif

#ifdef VERSION_FM
extern s32 func_0013C188(s32, s32);

// Builds the list D_00642CA8 of the indices 0..6 for which func_0013C188(0, i) is set, then 7 (count D_00642CC8).
void func_00215B88(void) {
    s32 i;

    D_00642CC8 = 0;
    for (i = 0; i < 7; i++) {
        if (func_0013C188(0, i)) {
            D_00642CA8[D_00642CC8++] = i;
        }
    }
    D_00642CA8[D_00642CC8++] = 7;
}
#else
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215B88);
#endif

#ifdef VERSION_FM
s32 func_00215C48(s32 arg0);
// Draws the page's help text at (174, 12): message 234, or the D_00642CA8 entry's message for the selected row (FM).
s32 func_00215C48(s32 arg0) {
    s32 val;

    func_001F9010(23);
    val = 234;
    if (D_0063CF44 != D_00642CC8 - 1) {
        val = func_00132FE0(D_0063CF44);
        val = D_00642CA8[D_0063CF44] * 3 + val + 212;
    }
    return func_001F9438((void*)arg0, 0, 174, 12, val, 17, 0x80c87850);
}
#else
#ifdef VERSION_EU
s32 func_00215C48(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215C48);
#else
s32 func_00215C48(s32 arg0) {
    s32 val;

    func_001F9B50(23);
    val = 239;
    if (D_0063CF44 != D_0063CF38 - 1) {
        val = func_00132EF0(D_0063CF44);
        val = (&D_0063CF18)[D_0063CF44] * 3 + val + 217;
    }
    return func_001F9F78(arg0, 0, 174, 12, val, 17, 0x80c87850);
}
#endif
#endif

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215CE8);

// Draws help text D_003F4488[D_0063CF40] at (174, 12).
#ifdef VERSION_EU
s32 func_00215EE8(void* arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215EE8);
#else
s32 func_00215EE8(void* arg0) {
    func_001F9010(23);
    return func_001F9438(arg0, 0, 174, 12, D_003F4488[D_0063CF40], 17, 0x80C87850);
}
#endif

struct XPotMenu;
s32 func_001F42B8(struct XPotMenu*);
void func_001F3758(struct XPotMenu*);
void func_0020BD18(struct XPotMenu*, s32);
void func_001FD858(struct XPotMenu*);
s32 func_001FD518(struct XPotMenu*);
s32 func_001FE570(struct XPotMenu*);
void func_001F3D58(struct XPotMenu*, s32);
void* func_001F4468(struct XPotMenu*);
void UiObject_InsertAfter(void*, void*);
void func_001F3DC0(void*);
s32 func_0013C288(s32);
s32 func_00132F88(s32);
s32 func_001EFBB8_r(s32) __asm__("func_001EFBB8");
s32 func_001F94F0(struct XPotMenu*, s32, s32, s32, s32, s32, s32);
extern s32* D_00425BC8;
void func_0011D598_v(s32) __asm__("func_0011D598");
void func_00207830_v(s32, s32, s32, s32, s32, s32, s32) __asm__("func_00207830");
extern u32 D_00642C9C;
extern s32 D_00642CC8;
extern s32 D_003F4460;
extern s32 D_003F4430;
extern s32 D_003F2C40[][5];
extern s32 D_003F44C8[];

// Menu page with three rows (func_0013C288 / func_00132F88 names, message 0xD4 when empty); confirming opens two child pages.
#ifdef VERSION_EU
void func_00215F48(struct XPotMenu* m);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00215F48);
#else
void func_00215F48(struct XPotMenu* m) {
    u8* p[2];
    void* t;
    s32 sel;
    s32 i;
    s32 y;
    s32 c;
    s32 r;
    s32 yy;
    s32 k;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(m);
            func_0011D598_v(3);
            D_0063CF04 = 0;
        } else {
            func_001FD858(m);
            func_0020BD18(m, 8);
            sel = func_001FD518(m);
            D_0063CF40 = sel;
            if (func_001FE570(m)) {
                func_001F3D58(m, 5);
                func_001F3758(m);
                D_0063CF04 = 2;
                D_00642C9C = D_0063CF40;
                t = func_001F4468(m);
                p[0] = func_001F3A20(&D_003F4460, 6);
                if (p[0] != NULL) {
                    UiObject_InsertAfter(p[0], t);
                    *(u16*)(p[0] + 0xCC) = *(u16*)(p[0] + 0xCE) = *(u16*)&D_00642CC8;
                    *(u16*)(p[0] + 0xD2) = *(u16*)&D_0063CF44 << 4;
                    p[1] = func_001F3A20(&D_003F4430, 6);
                    if (p[1] != NULL) {
                        UiObject_InsertAfter(p[1], p[0]);
                        func_001F3DC0(p[0]);
                    }
                }
            }
        }
    }
    sel = func_001FD518(m);
    for (y = 0, i = 0; i < 3;) {
        c = (i == sel);
        func_00207830_v((s32)m, c, 2, 0, y, 0xB4, D_003F44C8[i]);
        yy = y + 5;
        y += 0x1C;
        func_001F9438(m, 0, 0x56, yy, 0x33, 0xF, D_003F2C40[c][4]);
        k = func_0013C288(i);
        i++;
        r = func_00132F88(k);
        if (r == 0) {
            r = func_001EFBB8_r(0xD4);
        }
        func_001F94F0(m, 0, 0x60, yy, r, 0xF, D_003F2C40[c][4]);
    }
}
#endif

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00216198);

#ifdef VERSION_FM
s32 func_00216758(XWhiskey* arg0);
// Draws help text (menu word +0x24) at (174, 12).
s32 func_00216758(XWhiskey* arg0) {
    func_001F9010(23);
    return func_001F9438(arg0, 0, 174, 12, *(s32*)((u8*)arg0 + 0x24), 17, 0x80C87850);
}
#else
#ifdef VERSION_EU
s32 func_00216758(XWhiskey* arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00216758);
#else
s32 func_00216758(XWhiskey* arg0) {
    func_001F9B50(23);
    return func_001F9F78(arg0, 0, 174, 12, arg0->munny, 17, 0x80c87850);
}
#endif
#endif

#ifdef VERSION_FM
typedef struct {
    s32* list;
    s32 count;
} XPotatoTbl;
extern XPotatoTbl D_003F40F8[];

// Stores the chosen preset D_0063CF48 for the selected party member and applies it to the entries listed in D_003F40F8 (preset 5: nothing).
void PresetMenu_ApplyChoice(void) {
    u8 idx = D_003010F8->unk_48E[D_0063CF3C];
    s32* list = D_003F40F8[idx].list;
    s32 count = D_003F40F8[idx].count;
    s32 i;

    D_003ED718->unk_20[idx] = D_0063CF48;
    switch ((s32)D_0063CF48) {
        case 5:
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        default:
            for (i = 0; i < count; i++) {
                func_00170D60(idx, list[i], D_003F41E8[D_0063CF48][list[i]]);
            }
            break;
        case 4:
            for (i = 0; i < count; i++) {
                func_00170D60(idx, list[i], D_003F4200[idx][list[i]]);
            }
            break;

    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xpotato", PresetMenu_ApplyChoice);
#endif

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002168F8);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00216D88);

#ifdef VERSION_FM
s32 func_00217038(s32 arg0);
// Draws help text 204, or 205 with the selected party member's name (D_003E8E08) (FM).
s32 func_00217038(s32 arg0) {
    s32 val = 204;
    if (D_0063CF3C != 0) {
        val = 205;
        D_003E8E08 = Party_GetMemberName(D_0063CF3C);
    }
    func_001F9010(23);
    return func_001F9438((void*)arg0, 0, 174, 12, val, 17, 0x80c87850);
}
#else
#ifdef VERSION_EU
s32 func_00217038(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217038);
#else
s32 func_00217038(s32 arg0) {
    s32 val = 213;
    if (D_0063CF3C != 0) {
        val = 214;
        D_003E3088 = Party_GetMemberName(D_0063CF3C);
    }
    func_001F9B50(23);
    return func_001F9F78(arg0, 0, 174, 12, val, 17, 0x80c87850);
}
#endif
#endif

INCLUDE_ASM("asm/nonmatchings/xpotato", func_002170B0);

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217420);

#ifdef VERSION_FM
s32 func_00217810(s32 arg0);
// Draws the page frame (func_00207830, message 108 in FM).
s32 func_00217810(s32 arg0) {
    return func_00207830(arg0, 4, 2, 0, 0, 122, 108);
}
#else
#ifdef VERSION_EU
s32 func_00217810(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217810);
#else
s32 func_00217810(s32 arg0) {
    return func_00207728(arg0, 4, 2, 0, 0, 122, 117);
}
#endif
#endif

// Opens the page: creates UI object D_003EE8B0 after arg0, D_0063CF00 = arg0, state D_0063CF04 = 0 (probably the
// preset page: its other state D_0063CF3C..D_0063CF50 is what PresetMenu_ApplyChoice uses).
void PresetMenu_Open(void* arg0) {
    void* p0 = func_001F3A20(&D_003EE8B0, 0);

    if (p0 != NULL) {
        UiObject_InsertAfter(p0, arg0);
    }
    D_0063CF00 = arg0;
    D_0063CF04 = NULL;
}

// Clamps the selected party slot D_0063CF3C to the party size, then func_00215B88.
void PresetMenu_ClampMemberSlot(void) {
    if (D_0063CF3C > D_003DE6A0 - 1) {
        D_0063CF3C = D_003DE6A0 - 1;
    }
    func_00215B88();
}

// Clears the page selections D_0063CF3C..D_0063CF50.
void PresetMenu_ClearSelection(void) {
    D_0063CF3C = 0;
    D_0063CF40 = 0;
    D_0063CF44 = 0;
    D_0063CF48 = 0;
    D_0063CF4C = 0;
    D_0063CF50 = 0;
}

extern s32 D_00642CF0[];
extern s32 D_00642D10;
extern s32 D_00642D14;
s32 func_0013C360(s32);

typedef struct {
    char pad[0x44];
    u8 name[0x30];
} XPotChr;

#ifdef VERSION_FM
// Builds the row list D_00642CF0 for character arg0: rows 0..2, 1..4 more by the length of its 0x30-byte text at +0x44, and row 7 for character 0 when func_0013C360(i) == 1 for some i.
void func_00217908(s32 arg0) {
    XPotChr* c;
    s32 i;

    c = &((XPotChr*)D_003010F8)[arg0];
    D_00642CF0[0] = 0;
    D_00642CF0[1] = 1;
    D_00642CF0[2] = 2;
    D_00642D10 = 3;
    D_00642D14 = 0;
    while (c->name[D_00642D14] != 0) {
        D_00642D14++;
    }
    if (D_00642D14 >= 0x25) {
        D_00642CF0[3] = 3;
        D_00642CF0[4] = 4;
        D_00642CF0[5] = 5;
        D_00642CF0[6] = 6;
        D_00642D10 += 4;
    } else if (D_00642D14 >= 0x19) {
        D_00642D10 += 3;
        D_00642CF0[3] = 3;
        D_00642CF0[4] = 4;
        D_00642CF0[5] = 5;
    } else if (D_00642D14 >= 0xD) {
        D_00642D10 += 2;
        D_00642CF0[3] = 3;
        D_00642CF0[4] = 4;
    } else if (D_00642D14 > 0) {
        D_00642D10 += 1;
        D_00642CF0[3] = 3;
    }
    if (arg0 == 0) {
        for (i = 0; i < 7; i++) {
            if (func_0013C360(i) == 1) {
                D_00642CF0[D_00642D10++] = 7;
                break;
            }
        }
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217908);
#endif

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00217B00);

#ifdef VERSION_FM
s32 PartyMenu_DrawHelp(s32 arg0);
// Draws help text 0x110, or 0x111 with party member D_0063CF88's name (FM).
s32 PartyMenu_DrawHelp(s32 arg0) {
    s32 v = 0x110;

    func_001F9010(23);
    if (D_0063CF88 != 0) {
        D_003E8E08 = Party_GetMemberName(D_0063CF88);
        v++;
    }
    return func_001F9438((void*)arg0, 0, 174, 12, v, 17, 0x80C87850);
}
#else
#ifdef VERSION_EU
s32 PartyMenu_DrawHelp(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", PartyMenu_DrawHelp);
#else
s32 PartyMenu_DrawHelp(s32 arg0) {
    s32 val = 277;

    func_001F9B50(23);
    if (D_0063CF88 != 0) {
        D_003E3088 = Party_GetMemberName(D_0063CF88);
        val = 278;
    }
    return func_001F9F78(arg0, 0, 174, 12, val, 17, 0x80c87850);
}
#endif
#endif

#ifdef VERSION_FM
typedef struct XPotMenu {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ struct XPotMenu* unk_10;
    /* 0x14 */ char unk_14[0x10];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk_28[0xB0];
    /* 0xD8 */ u16 unk_D8;
} XPotMenu;

extern s32* D_00425BC8;
extern s32 D_00642D28;
extern s32 D_003F4790[];
s32 func_001F42B8(XPotMenu*);
void func_001F3758(XPotMenu*);
void func_001FDFD0(XPotMenu*);
void func_0020BD18(XPotMenu*, s32);
s32 func_001FD538(XPotMenu*);
void func_001FD858(XPotMenu*);
s32 func_001FD518(XPotMenu*);
s32 func_001FE570(XPotMenu*);
void func_00206690(XPotMenu*, s32, s32, s32);
void func_002078F0(XPotMenu*, s32, s32, s32, s32, s32, s32, s32, s32);

extern XPotMenu* D_00642CE8;


s32 Char_GetName(s32);
void func_00207870(XPotMenu*, s32, s32, s32, s32, s32, s32);

// Party member list page: one row per member (Char_GetName); moving fills the child page through func_00217908.
void PartyMenu_Update(XPotMenu* m) {
    XPotMenu* p;
    u32 v;
    s32 b;
    s32 sel;
    u32 i;
    s32 y;
    s32 c;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(D_00642CE8);
            func_0011D598(3);
        } else {
            func_001FD858(m);
            func_0020BD18(m, 8);
            v = func_001FD518(m);
            D_0063CF88 = v;
            p = m->unk_10;
            if (p != NULL) {
                p->unk_24 = b = D_003010F8->unk_48E[v];
                p = p->unk_10;
                if (p != NULL) {
                    func_00217908(D_003010F8->unk_48E[v]);
                    p->unk_D8 = *(u16*)&D_00642D10;
                    func_001FDFD0(p);
                    p->unk_24 = b;
                }
            }
        }
    }
    sel = func_001FD518(m);
    for (y = 0, i = 0; i < D_003DE6A0; i++, y += 28) {
        c = (i == sel) ? 11 : 0;
        func_00207870(m, c, 2, 0, y, 0x7A, Char_GetName(D_003010F8->unk_48E[i]));
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/xpotato", PartyMenu_Update);
#endif

#ifdef VERSION_FM
s32 func_00218840(s32 arg0);
// Draws the page frame (func_00207830, message 109 in FM).
s32 func_00218840(s32 arg0) {
    return func_00207830(arg0, 4, 2, 0, 0, 122, 109);
}
#else
#ifdef VERSION_EU
s32 func_00218840(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218840);
#else
s32 func_00218840(s32 arg0) {
    return func_00207728(arg0, 4, 2, 0, 0, 122, 118);
}
#endif
#endif

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218870);

// Clamps the selected party slot D_0063CF88 to the party size.
void PartyMenu_ClampSlot(void) {
    if (D_0063CF88 > D_003DE6A0 - 1) {
        D_0063CF88 = D_003DE6A0 - 1;
    }
}

// Clears the selected party slot D_0063CF88.
void PartyMenu_ClearSlot(void) {
    D_0063CF88 = 0;
}

#ifdef VERSION_FM
void Config_Reset(void);
// Clears the config options (GameData words 0x00..0x18), option 6 (+0x2C) = 1 in FM.
void Config_Reset(void) {
    XWhiskey* p = D_003ED718;

    *(s32*)((u8*)p + 0x2C) = 1;
    p->unk_08 = 0;
    p->unk_04 = 0;
    p->unk_0C = 0;
    p->unk_10 = 0;
    p->unk_14 = 0;
    p->unk_18 = 0;
    p->unk_00 = 0;
}
#else
void Config_Reset(void) {
    D_003ED718->unk_00 = 0;
    D_003ED718->unk_08 = 0;
    D_003ED718->unk_04 = 0;
    D_003ED718->unk_0C = 0;
    D_003ED718->unk_10 = 0;
    D_003ED718->unk_14 = 0;
    D_003ED718->unk_18 = 0;
}
#endif

// Returns config option arg0 (0..6: GameData +0x00, 0x04, 0x08, 0x10, 0x14, 0x18, 0x2C).
#ifdef VERSION_EU
u32 Config_Get(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", Config_Get);
#else
u32 Config_Get(s32 arg0) {
    switch (arg0) {
        case 0:
            return D_003ED718->unk_00;
        case 1:
            return D_003ED718->unk_04;
        case 2:
            return D_003ED718->unk_08;
        case 3:
            return D_003ED718->unk_10;
        case 4:
            return D_003ED718->unk_14;
        case 5:
            return D_003ED718->unk_18;
        case 6:
        default:
            return *(u32*)((u8*)D_003ED718 + 0x2C);
    }
}
#endif

// Sets config option arg0 (same order as Config_Get).
#ifdef VERSION_EU
void Config_Set(s32 arg0, u32 arg1);
INCLUDE_ASM("asm/nonmatchings/xpotato", Config_Set);
#else
void Config_Set(s32 arg0, u32 arg1) {
    switch (arg0) {
        case 0:
            D_003ED718->unk_00 = arg1;
            break;
        case 1:
            D_003ED718->unk_04 = arg1;
            break;
        case 2:
            D_003ED718->unk_08 = arg1;
            break;
        case 3:
            D_003ED718->unk_10 = arg1;
            break;
        case 4:
            D_003ED718->unk_14 = arg1;
            break;
        case 5:
            D_003ED718->unk_18 = arg1;
            break;
        case 6:
        default:
            *(u32*)((u8*)D_003ED718 + 0x2C) = arg1;
            break;
    }
}
#endif

// Config option 0 (GameData +0x00).
u32 Config_GetOption0(void) {
    return D_003ED718->unk_00;
}

// Calls Config_GetOption0.
u32 Config_GetOption0Wrap(void) {
    return Config_GetOption0();
}

// Sets config option 0.
void Config_SetOption0(s32 arg0) {
    D_003ED718->unk_00 = arg0;
}

// Config option 1 (GameData +0x04).
u32 Config_GetOption1(void) {
    return D_003ED718->unk_04;
}

// Calls Config_GetOption1.
u32 Config_GetOption1Wrap(void) {
    return Config_GetOption1();
}

// Sets config option 1.
u32 Config_SetOption1(u32 arg0) {
    D_003ED718->unk_04 = arg0;
}

// Config option 2 (GameData +0x08).
s32 Config_GetOption2(void) {
    return D_003ED718->unk_08;
}

// Calls Config_GetOption2.
u32 Config_GetOption2Wrap(void) {
    return Config_GetOption2();
}

// Sets config option 2.
void Config_SetOption2(s32 arg0) {
    D_003ED718->unk_08 = arg0;
}

// Returns 0.
u32 func_00218BF0(void) {
    return 0;
}

// Returns 0.
u32 func_00218BF8(void) {
    return 0;
}

// Empty.
void func_00218C00(void) {
}

// Config option 3 (GameData +0x10).
u32 Config_GetOption3(void) {
    return D_003ED718->unk_10;
}

// Calls Config_GetOption3.
s32 Config_GetOption3Wrap(void) {
    return Config_GetOption3();
}

// Sets config option 3.
void Config_SetOption3(s32 arg0) {
    D_003ED718->unk_10 = arg0;
}

// Config option 4 (GameData +0x14).
u32 Config_GetOption4(void) {
    return D_003ED718->unk_14;
}

// Calls Config_GetOption4.
s32 Config_GetOption4Wrap(void) {
    return Config_GetOption4();
}

// Sets config option 4.
void Config_SetOption4(s32 arg0) {
    D_003ED718->unk_14 = arg0;
}

// Config option 5 (GameData +0x18).
u32 Config_GetOption5(void) {
    return D_003ED718->unk_18;
}

// Calls Config_GetOption5.
s32 Config_GetOption5Wrap(void) {
    return Config_GetOption5();
}

// Sets config option 5.
void Config_SetOption5(s32 arg0) {
    D_003ED718->unk_18 = arg0;
}

#ifdef VERSION_FM
// Config option 6 (GameData +0x2C, FM only).
s32 Config_GetOption6(void) {
    return *(s32*)((u8*)D_003ED718 + 0x2C);
}
#endif

#ifdef VERSION_FM
// Calls Config_GetOption6.
s32 Config_GetOption6Wrap(void) {
    return Config_GetOption6();
}
#endif

#ifdef VERSION_FM
// Sets config option 6.
void Config_SetOption6(s32 arg0) {
    *(s32*)((u8*)D_003ED718 + 0x2C) = arg0;
}
#endif

#ifdef VERSION_FM
// True when D_002B6478 == 2 (FM only).
s32 fm_func_00219428(void) {
    return D_002B6478 == 2;
}
#endif

#ifdef VERSION_FM
// Message id D_003F47A8[arg0] (FM only).
s32 fm_func_00219440(s32 arg0) {
    return D_003F47A8[arg0];
}
#endif

#ifdef VERSION_FM
// func_001EFBB8 of fm_func_00219440(arg0) (FM only).
void fm_func_00219458(s32 arg0) {
    func_001EFBB8(fm_func_00219440(arg0));
}
#endif

// Draws help text D_003F47B8[menu word +0x24] at (174, 12).
#ifdef VERSION_EU
s32 func_00218CB0(XWhiskey* arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218CB0);
#else
s32 func_00218CB0(XWhiskey* arg0) {
    func_001F9010(23);
    return func_001F9438(arg0, 0, 174, 12, D_003F47B8[*(s32*)((u8*)arg0 + 0x24)], 17, 0x80C87850);
}
#endif

// D_003ED72C++, D_003ED728--.
void func_00218D08(void) {
    D_003ED72C++;
    D_003ED728--;
}

// Uploads two images from D_003ED730 to VRAM (GsPacket_LoadImage at 0x3600 and 0x3680).
void func_00218D38(void) {
    GsPacket_LoadImage(0x3600, 4, 19, 0, 0, 138, 0x58, 759, D_003ED730, &D_0063CFA0);
    GsPacket_LoadImage(0x3680, 1, 0, 0, 0, 16, 16, 64, D_003ED730 + 0x2F70, &D_0063D050);
}

INCLUDE_ASM("asm/nonmatchings/xpotato", func_00218DD0);

NOTHROW(void, func_00218DD0);
#ifndef VERSION_FM
// JP/EU: what the FM-only block above declares for the shared code below
typedef struct XPotMenu {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ struct XPotMenu* unk_10;
    /* 0x14 */ char unk_14[0x10];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ char unk_28[0xB0];
    /* 0xD8 */ u16 unk_D8;
} XPotMenu;

extern s32* D_00425BC8;
extern s32 D_00642D28;
extern s32 D_003F4798[];
extern s32 D_003F47A0[];
s32 func_001F42B8(XPotMenu*);
void func_001F3758(XPotMenu*);
void func_001FDFD0(XPotMenu*);
void func_0020BD18(XPotMenu*, s32);
s32 func_001FD538(XPotMenu*);
void func_001FD858(XPotMenu*);
s32 func_001FD518(XPotMenu*);
s32 func_001FE570(XPotMenu*);
void func_00206690(XPotMenu*, s32, s32, s32);
void func_002078F0(XPotMenu*, s32, s32, s32, s32, s32, s32, s32, s32);
#endif
extern s32 D_003F4878[];
extern s32 D_003F4818[];
extern s32 D_003F4848[];
extern s32 D_003F48A8[];
extern s32* D_003F4A48[];
extern s32 D_003F4A78[];
extern s32 D_003F4AA8[][2];
void func_001F9270(void*, s32, s32, s32, s32, u32);
void func_00206130(void*, s32, s32, s32, s32, u32);
void func_001FC308(void*, s32, s32, s32, s32, s32, s32, u32, u32);

// Draws twelve labels (D_003F4878..D_003F48A8) and their line sets, highlighting entry D_00642D28.
#ifdef VERSION_EU
void func_002190C0(void* arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_002190C0);
#else
void func_002190C0(void* arg0) {
    s32 i;
    s32 n;
    s32* p;
    s32* q;
    s32** pp;
    s32* np;

    func_001F9270(arg0, 0, 0x10, 0x145, 0xF, 0x801EC8C8);
    for (i = 0; i < 12; i++) {
        func_001F9438(arg0, D_003F4878[i], D_003F4818[i], D_003F4848[i], D_003F48A8[i], 0xF,
                      (i == D_00642D28) ? 0x80B4B4B4 : 0x40808080);
    }
    if (D_003ED72C == 2) {
        func_00218DD0(arg0, 0xB0, 0x3D);
    }
    pp = D_003F4A48;
    np = D_003F4A78;
    for (i = 0; i < 12; i++, np++, pp++) {
        p = *pp;
        for (n = *np; n > 0; n--) {
            func_00206130(arg0, p[0], p[1], p[2], p[3], (i == D_00642D28) ? 0x80F35054 : 0x33F35054);
            p += 4;
        }
    }
    q = D_003F4AA8[D_00642D28];
    func_001FC308(arg0, q[0], q[1], 0, 0, 0xA, 0, 0x33F35054, 0x33F35054);
    func_001FC308(arg0, q[0], q[1] + 0xF, 0, 0, 0xB, 0, 0x33F35054, 0x33F35054);
}
#endif

#ifdef VERSION_FM
extern s32* D_00425BC8;
extern s32 D_00642D28;
extern s32 D_003F4790[];
s32 func_001F42B8(XPotMenu*);
void func_001F3758(XPotMenu*);
void func_001FDFD0(XPotMenu*);
void func_0020BD18(XPotMenu*, s32);
s32 func_001FD538(XPotMenu*);
void func_001FD858(XPotMenu*);
s32 func_001FD518(XPotMenu*);
s32 func_001FE570(XPotMenu*);
void func_00206690(XPotMenu*, s32, s32, s32);
void func_002078F0(XPotMenu*, s32, s32, s32, s32, s32, s32, s32, s32);

// Config menu page for option 0: two choices (D_003F4790), the selection written to GameData +0x00; pad bit 0x4000 closes it.
void ConfigMenu_UpdateOption0(XPotMenu* m) {
    XPotMenu* p;
    s32 v;
    s32 sel;
    s32 i;
    s32 y;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(m);
            func_0011D598(3);
        } else {
            func_001FDFD0(m);
            func_0020BD18(m, 8);
            D_003ED718->unk_00 = func_001FD538(m);
            p = m->unk_10;
            if (p != NULL) {
                func_001FD858(p);
                v = func_001FD518(p);
                D_00642D28 = v;
                p = p->unk_10;
                if (p != NULL) {
                    p->unk_24 = v;
                }
            }
            if (func_001FE570(m)) {
                func_001F3758(m);
            }
        }
    }
    func_00206690(m, -75, 12, 76);
    func_002078F0(m, 11, 0, 2, 0, 0, 142, 71, 294);
    sel = func_001FD538(m);
    for (y = 148, i = 0; i < 2; i++, y += 112) {
        func_002078F0(m, i == sel, 2, 2, y, 0, 106, y + 53, D_003F4790[i]);
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/xpotato", ConfigMenu_UpdateOption0);
#endif

#ifdef VERSION_FM
extern s32 D_003F4798[];

// Config menu page for option 1 (choices D_003F4798, GameData +0x04).
void ConfigMenu_UpdateOption1(XPotMenu* m) {
    XPotMenu* p;
    s32 v;
    s32 sel;
    s32 i;
    s32 y;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(m);
            func_0011D598(3);
        } else {
            func_001FDFD0(m);
            func_0020BD18(m, 8);
            D_003ED718->unk_04 = func_001FD538(m);
            p = m->unk_10;
            if (p != NULL) {
                func_001FD858(p);
                v = func_001FD518(p);
                D_00642D28 = v;
                p = p->unk_10;
                if (p != NULL) {
                    p->unk_24 = v;
                }
            }
            if (func_001FE570(m)) {
                func_001F3758(m);
            }
        }
    }
    func_00206690(m, -75, 12, 76);
    func_002078F0(m, 11, 0, 2, 0, 0, 142, 71, 299);
    sel = func_001FD538(m);
    for (y = 148, i = 0; i < 2; i++, y += 112) {
        func_002078F0(m, i == sel, 2, 2, y, 0, 106, y + 53, D_003F4798[i]);
    }
}

#else
#ifdef VERSION_EU
void ConfigMenu_UpdateOption1(XPotMenu* m);
INCLUDE_ASM("asm/nonmatchings/xpotato", ConfigMenu_UpdateOption1);
#else
void ConfigMenu_UpdateOption1(XPotMenu* m) {
    XPotMenu* p;
    s32 v;
    s32 sel;
    s32 i;
    s32 y;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(m);
            func_0011D598(3);
        } else {
            func_001FDFD0(m);
            func_0020BD18(m, 8);
            D_003ED718->unk_04 = func_001FD538(m);
            p = m->unk_10;
            if (p != NULL) {
                func_001FD858(p);
                v = func_001FD518(p);
                D_00642D28 = v;
                p = p->unk_10;
                if (p != NULL) {
                    p->unk_24 = v;
                }
            }
            if (func_001FE570(m)) {
                func_001F3758(m);
            }
        }
    }
    func_00206690(m, -75, 12, 76);
    func_002078F0(m, 11, 0, 2, 0, 0, 142, 71, 303);
    sel = func_001FD538(m);
    for (y = 148, i = 0; i < 2; i++, y += 112) {
        func_002078F0(m, i == sel, 2, 2, y, 0, 106, y + 53, D_003F4798[i]);
    }
}
#endif
#endif

#ifdef VERSION_FM
extern s32 D_003F47A0[];

// Config menu page for option 2 (choices D_003F47A0, GameData +0x08).
void ConfigMenu_UpdateOption2(XPotMenu* m) {
    XPotMenu* p;
    s32 v;
    s32 sel;
    s32 i;
    s32 y;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(m);
            func_0011D598(3);
        } else {
            func_001FDFD0(m);
            func_0020BD18(m, 8);
            D_003ED718->unk_08 = func_001FD538(m);
            p = m->unk_10;
            if (p != NULL) {
                func_001FD858(p);
                v = func_001FD518(p);
                D_00642D28 = v;
                p = p->unk_10;
                if (p != NULL) {
                    p->unk_24 = v;
                }
            }
            if (func_001FE570(m)) {
                func_001F3758(m);
            }
        }
    }
    func_00206690(m, -75, 12, 76);
    func_002078F0(m, 11, 0, 2, 0, 0, 142, 71, 303);
    sel = func_001FD538(m);
    for (y = 148, i = 0; i < 2; i++, y += 112) {
        func_002078F0(m, i == sel, 2, 2, y, 0, 106, y + 53, D_003F47A0[i]);
    }
}

#else
#ifdef VERSION_EU
void ConfigMenu_UpdateOption2(XPotMenu* m);
INCLUDE_ASM("asm/nonmatchings/xpotato", ConfigMenu_UpdateOption2);
#else
void ConfigMenu_UpdateOption2(XPotMenu* m) {
    XPotMenu* p;
    s32 v;
    s32 sel;
    s32 i;
    s32 y;

    if (func_001F42B8(m)) {
        if (D_00425BC8[2] & 0x4000) {
            func_001F3758(m);
            func_0011D598(3);
        } else {
            func_001FDFD0(m);
            func_0020BD18(m, 8);
            D_003ED718->unk_08 = func_001FD538(m);
            p = m->unk_10;
            if (p != NULL) {
                func_001FD858(p);
                v = func_001FD518(p);
                D_00642D28 = v;
                p = p->unk_10;
                if (p != NULL) {
                    p->unk_24 = v;
                }
            }
            if (func_001FE570(m)) {
                func_001F3758(m);
            }
        }
    }
    func_00206690(m, -75, 12, 76);
    func_002078F0(m, 11, 0, 2, 0, 0, 142, 71, 299);
    sel = func_001FD538(m);
    y = 148;
    i = 0;
    do {
        v = i ^ sel;
        func_002078F0(m, v, 2, 2, y, 0, 106, y + 53, D_003F47A0[i]);
        i++;
    } while (i < 2);
}
#endif
#endif

// Draws help text D_003F4BD0[D_00642D24] at (174, 12).
#ifdef VERSION_EU
s32 func_00219788(void* arg0);
INCLUDE_ASM("asm/nonmatchings/xpotato", func_00219788);
#else
s32 func_00219788(void* arg0) {
    func_001F9010(23);
    return func_001F9438(arg0, 0, 174, 12, D_003F4BD0[D_00642D24], 17, 0x80C87850);
}
#endif

#ifdef VERSION_FM
// .data (0x003F4050-0x003F47F0); more xpotato data follows, interleaved with xrodent's (still in the asm data).
// The blocks starting with a function are UI object descriptors (func_001F3A20). D_003F4430, D_003F4460 and D_003EE8B0
// are declared as s32 above (the code only takes their address), so they are defined under other C names here.
extern u8 D_004800A0[];
void func_00215CE8();
void func_00216198();
void func_002168F8();
void func_00216D88();
void func_002170B0();
void func_00217420();
void func_00217B00();
s32 D_003F4050[6] = {
    0x0, 0x3, 0x4, 0x5,
    0x1, 0x2,
};
s32 D_003F4068[6] = {
    0x0, 0x8, 0x7, 0x6,
    0x1, 0x2,
};
s32 fm_D_003F4080[6] = {
    0x0, 0x8, 0x7, 0x1,
    0x2, 0x0,
};
s32 D_003F4098[4] = {
    0x0, 0x8, 0x1, 0x2,
};
s32 D_003F40A8[6] = {
    0x0, 0x8, 0x7, 0x1,
    0x2, 0x0,
};
s32 D_003F40C0[4] = {
    0x0, 0x8, 0x1, 0x2,
};
s32 D_003F40D0[6] = {
    0x0, 0x8, 0x7, 0x1,
    0x2, 0x0,
};
s32 D_003F40E8[4] = {
    0x0, 0x8, 0x1, 0x2,
};
XPotatoTbl D_003F40F8[10] = { // per-preset lists of the entries it sets
    {NULL, 0}, {D_003F4050, 6}, {D_003F4068, 6}, {fm_D_003F4080, 5}, {NULL, 0},
    {D_003F4098, 4}, {D_003F40A8, 5}, {D_003F40C0, 4}, {D_003F40D0, 5}, {D_003F40E8, 4},
};
s32 D_003F4148[10] = {
    0x1, 0x0, 0x2, 0x2,
    0x0, 0x2, 0x0, 0x0,
    0x2, 0x0,
};
s32 D_003F4170[10] = {
    0x1, 0x2, 0x2, 0x0,
    0x2, 0x1, 0x2, 0x2,
    0x0, 0x0,
};
s32 D_003F4198[10] = {
    0x2, 0x0, 0x0, 0x0,
    0x1, 0x0, 0x1, 0x1,
    0x0, 0x0,
};
s32 D_003F41C0[10] = {
    0x1, 0x2, 0x0, 0x1,
    0x2, 0x1, 0x1, 0x1,
    0x1, 0x0,
};
s32* D_003F41E8[6] = {D_003F4148, D_003F4170, D_003F4198, D_003F41C0, NULL, NULL};
s32 D_003F4200[10][9] = { // the characters' own preset rows
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 2, 1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 1, 2, 2},
    {1, 1, 0, 0, 0, 0, 0, 2, 2},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 1, 1, 0, 0, 0, 0, 0, 2},
    {1, 0, 1, 0, 0, 0, 0, 2, 2},
    {1, 0, 1, 0, 0, 0, 0, 0, 2},
    {2, 1, 0, 0, 0, 0, 0, 1, 2},
    {1, 1, 0, 0, 0, 0, 0, 0, 2},
};
s32 D_003F4368[6] = {
    0xEB, 0xEC, 0xED, 0xEE,
    0xEF, 0xF0,
};
s32 D_003F4380[10] = {
    0xF7, 0xF8, 0xF9, 0xFA,
    0xFB, 0xFC, 0xFD, 0xFE,
    0x100, 0x0,
};
s32 D_003F43A8[4] = {
    0x10B, 0x10C, 0x10D, 0x0,
};
s32 D_003F43B8[4] = {
    0x10E, 0x10C, 0x10F, 0x0,
};
void* D_003F43C8[10] = {
    &D_003F43A8, &D_003F43B8, &D_003F43B8, &D_003F43A8,
    &D_003F43A8, &D_003F43A8, &D_003F43A8, &D_003F43A8,
    &D_003F43A8, 0,
};
s32 D_003F43F0[6] = {
    0xF1, 0xF2, 0xF3, 0xF4,
    0xF5, 0xF6,
};
s32 D_003F4408[10] = {
    0x101, 0x102, 0x103, 0x104,
    0x105, 0x106, 0x107, 0x108,
    0x10A, 0x0,
};
void* xpotato_d_003f4430[12] __asm__("D_003F4430") = {
    (void*)func_00215C48, 0, (void*)0x4, (void*)0x12C0000,
    (void*)0x540200, 0, 0, 0,
    0, 0, 0, 0,
};
void* xpotato_d_003f4460[8] __asm__("D_003F4460") = {
    (void*)func_00215CE8, 0, (void*)0x4, (void*)0x47015F,
    (void*)0xFFFE007A, 0, (void*)0x1C007A, (void*)0x2,
};
s32 fm_D_003F4480[2] = {0};
s32 D_003F4488[6] = {
    0xD1, 0xD2, 0xD3, 0x0,
    0x0, 0x0,
};
void* D_003F44A0[10] = {
    (void*)func_00215EE8, 0, (void*)0x4, (void*)0x12C0000,
    (void*)0x540200, 0, 0, 0,
    0, 0,
};
s32 D_003F44C8[6] = {
    0xCE, 0xCF, 0xD0, 0x0,
    0x0, 0x0,
};
void* D_003F44E0[10] = {
    (void*)func_00215F48, 0, (void*)0x4, (void*)0x47009F,
    (void*)0x5200B4, 0, (void*)0x1C00B4, (void*)0x30002,
    (void*)0x3, 0,
};
s32 D_003F4508[6] = {
    0xFFFFFFFD, 0x61, 0xBF, 0x0,
    0x0, 0x0,
};
void* D_003F4520[12] = {
    (void*)func_00216198, 0, (void*)0x4, (void*)0x47009F,
    (void*)0x156, 0, (void*)0x1A0156, 0,
    0, 0, 0, 0,
};
void* D_003F4550[12] = {
    (void*)func_00216758, 0, (void*)0x4, (void*)0x12C0000,
    (void*)0x540200, 0, 0, 0,
    0, 0, 0, 0,
};
void* D_003F4580[10] = {
    (void*)func_002168F8, 0, (void*)0x4, (void*)0x47009F,
    (void*)0x1A0156, 0, (void*)0x1C0156, (void*)0x10002,
    (void*)0x1, 0,
};
s32 D_003F45A8[6] = {
    0xCE, 0xCF, 0xD0, 0x0,
    0x0, 0x0,
};
void* D_003F45C0[12] = {
    (void*)func_00216D88, 0, (void*)0x4, (void*)0x47009F,
    (void*)0x1C0156, 0, 0, 0,
    0, 0, 0, 0,
};
void* D_003F45F0[12] = {
    (void*)func_00217038, 0, (void*)0x4, (void*)0x12C0000,
    (void*)0x540200, 0, 0, 0,
    0, 0, 0, 0,
};
void* D_003F4620[12] = {
    (void*)func_002170B0, 0, (void*)0x4, (void*)0x47000B,
    (void*)0x7A, 0, (void*)0x1C007A, (void*)0x2,
    (void*)0x4, 0, 0, 0,
};
// at 0x003F4650 (the name is the JP address)
void* xpotato_d_003ee8b0[12] __asm__("D_003EE8B0") = {
    (void*)func_00217420, 0, (void*)0x4, 0,
    (void*)0x1800200, 0, 0, 0,
    0, 0, 0, 0,
};
void* D_003F4680[12] = {
    (void*)func_00217810, 0, (void*)0x4, (void*)0x1F000B,
    (void*)0x1A007A, 0, 0, 0,
    0, 0, 0, 0,
};
s32 D_003F46B0[8] = {
    0x112, 0x113, 0x114, 0x115,
    0x115, 0x115, 0x115, 0x116,
};
void* D_003F46D0[12] = {
    (void*)func_00217B00, 0, (void*)0x7, &D_004800A0,
    (void*)0xDC0160, 0, 0, 0,
    0, 0, 0, 0,
};
void* D_003F4700[12] = {
    (void*)PartyMenu_DrawHelp, 0, (void*)0x4, (void*)0x12C0000,
    (void*)0x540200, 0, 0, 0,
    0, 0, 0, 0,
};
void* D_003F4730[12] = {
    (void*)PartyMenu_Update, 0, (void*)0x4, (void*)0x47000B,
    (void*)0x7A, 0, (void*)0x1C007A, (void*)0x2,
    0, 0, 0, 0,
};
void* D_003F4760[12] = {
    (void*)func_00218840, 0, (void*)0x4, (void*)0x1F000B,
    (void*)0x1A007A, 0, 0, 0,
    0, 0, 0, 0,
};
s32 D_003F4790[2] = {
    0x127, 0x128,
};
s32 D_003F4798[2] = {
    0x12C, 0x12D,
};
s32 D_003F47A0[2] = {
    0x130, 0x131,
};
s32 D_003F47A8[4] = {
    0x1CA, 0x5A, 0x5B, 0x0,
};
s32 D_003F47B8[14] = {
    0x152, 0x153, 0x154, 0x155,
    0x156, 0x157, 0x158, 0x159,
    0x15A, 0x15B, 0x15C, 0x15D,
    0x0, 0x0,
};
#endif
