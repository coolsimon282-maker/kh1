/**
 * Game state kept in work buffer 3 (gameState, GameState in include/gamestate.h): where the player is (world, room, curEntranceNo, three party
 * member positions with their angle) and more; other functions here work with the party (Party_AddCharacter, ...).
 * The location part is probably what a save records.
 */
#include "common.h"

#include "xcursed.h"
#include "xhumungus.h"
#include "gamestate.h"

extern s32 D_002B8364;
extern s32 curWorldNo;

typedef struct {
    /* 0x0 */ s8 unk_0; // compared with curWorldNo
    /* 0x1 */ s8 unk_1; // compared with curRoomNo
    /* 0x2 */ s8 index; // for GameState_SetPresetPositions
    /* 0x3 */ s8 pad;
} XTrumpetSel;

#ifdef VERSION_FM
// .data (0x002BCB60-0x002BCC28)
GameState* gameState = NULL;
// sizes (per group?) of GameState.unk_6C
s8 D_002BCB68[17] = {7, 12, 9, 26, 10, 20, 11, 1, 21, 17, 13, 7, 11, 12, 1, 17, 39};
XTrumpetSel presetPosRooms[39] = {
    {0, 4, 11, 0},
    {1, 1, 23, 0},
    {1, 6, 24, 0},
    {3, 0, 0, 0},
    {3, 10, 68, 0},
    {3, 19, 69, 0},
    {4, 0, 0, 0},
    {4, 3, 36, 0},
    {5, 14, 45, 0},
    {5, 8, 46, 0},
    {5, 3, 47, 0},
    {6, 10, 19, 0},
    {8, 7, 63, 0},
    {8, 11, 65, 0},
    {8, 18, 64, 0},
    {8, 13, 66, 0},
    {8, 0, 68, 0},
    {9, 1, 51, 0},
    {9, 10, 52, 0},
    {9, 13, 54, 0},
    {9, 15, 53, 0},
    {10, 11, 22, 0},
    {10, 9, 24, 0},
    {11, 1, 13, 0},
    {12, 0, 42, 0},
    {12, 1, 43, 0},
    {12, 8, 44, 0},
    {13, 7, 37, 0},
    {13, 10, 38, 0},
    {13, 11, 40, 0},
    {13, 9, 39, 0},
    {15, 0, 0, 0},
    {15, 5, 58, 0},
    {15, 8, 59, 0},
    {15, 11, 60, 0},
    {16, 0, 70, 0},
    {16, 24, 71, 0},
    {16, 29, 72, 0},
    {16, 14, 80, 0},
};
s32 D_002B916C = 0;
s32 D_002B9170 = 0;
s32 D_002B9174 = 0;
#else
GameState* gameState;
extern s8 D_002BCB68[]; // FM address name; sizes (per group?) of GameState.unk_6C
extern XTrumpetSel presetPosRooms[39];
extern s32 D_002B916C;
extern s32 D_002B9170;
extern s32 D_002B9174;
#endif



extern s32 D_004D29D0;
extern s32 D_004D2998;
extern s32 D_004D29AC;
extern s32 D_004D29C4;

extern s32 curRoomNo;
extern s32 D_002B8684;
extern s32 curEntranceNo;

extern void* D_002E26A0[];

void GameState_SaveMemberPos(void*, s32);
void GameState_SavePositions(void);
void GameState_SetPresetPositions(s32);
void GameState_SaveLocation(void);
void func_00111C98(s32, s32);

// Points gameState at work buffer 3.
void GameState_BindBuffer(void) {
    gameState = WorkBuffers_Get(3);
}

// Binds gameState and clears its location, positions and the unk_6C array.
void GameState_Reset(void) {
    s32 i;

    GameState_BindBuffer();
    for (i = 0; i < ARRAY_COUNT(gameState->unk_6C); i++) {
        gameState->unk_6C[i] = 0;
    }
    gameState->worldNo = 0;
    gameState->roomNo = 0;
    gameState->memberPos[0].x = 0;
    gameState->memberPos[0].y = 0;
    gameState->memberPos[0].z = 0;
    gameState->memberPos[0].w = 0;
    gameState->memberPos[1].x = 0;
    gameState->memberPos[1].y = 0;
    gameState->memberPos[1].z = 0;
    gameState->memberPos[1].w = 0;
    gameState->memberPos[2].x = 0;
    gameState->memberPos[2].y = 0;
    gameState->memberPos[2].z = 0;
    gameState->memberPos[2].w = 0;
    gameState->charFlags = 0;
}

// memberPos seen as f[i][0..3] after a 0x10-byte pad: the view is load-bearing; with gameState->memberPos[i] GCC adds the
// 0x10 to the index first and the function is 8 bytes longer.
typedef struct { u8 pad[0x10]; f32 f[4][4]; } XTF;
// Stores party member i's position (+0x10) and angle (+0x3C) in gameState vector i.
void GameState_SaveMemberPos(void* a_, s32 i) {
    u8* a = a_;
    ((XTF*)gameState)->f[i][0] = *(f32*)(a + 0x10);
    ((XTF*)gameState)->f[i][1] = *(f32*)(a + 0x14);
    ((XTF*)gameState)->f[i][2] = *(f32*)(a + 0x18);
    ((XTF*)gameState)->f[i][3] = *(f32*)(a + 0x3C);
}

// Saves the location and the position of each of the three party members (D_002E26A0) that exists.
void GameState_SavePositions(void) {
    void* p;

    GameState_SaveLocation();
    p = D_002E26A0[0];
    if (p != NULL) {
        GameState_SaveMemberPos(p, 0);
    }
    p = D_002E26A0[1];
    if (p != NULL) {
        GameState_SaveMemberPos(p, 1);
    }
    p = D_002E26A0[2];
    if (p != NULL) {
        GameState_SaveMemberPos(p, 2);
    }
}

// 64-byte entries (four vectors); entry vectors 2 and 3 go to GameState memberPos 1 and 2
typedef struct {
    /* 0x00 */ GameStatePos v[4];
} XTrumpetVecSet;

extern XTrumpetVecSet* entranceTable;

// Saves member 0's position, and members 1 and 2 from preset entry index (entranceTable) instead.
void GameState_SetPresetPositions(s32 index) {
    s32 i;

    if (D_002E26A0[0] != NULL) {
        GameState_SaveMemberPos(D_002E26A0[0], 0);
    }
    for (i = 0; i < 2; i++) {
        gameState->memberPos[i + 1].x = entranceTable[index].v[i + 2].x;
        gameState->memberPos[i + 1].y = entranceTable[index].v[i + 2].y;
        gameState->memberPos[i + 1].z = entranceTable[index].v[i + 2].z;
        gameState->memberPos[i + 1].w = entranceTable[index].v[i + 2].w;
    }
}

// GameState's unk_4C..unk_6B, copied from what func_0017F1C8 returns
typedef struct {
    /* 0x00 */ s32 w[8];
} XTrumpetUnk4C;

XTrumpetUnk4C* func_0017F1C8(void);

// Saves curWorldNo, curRoomNo, curEntranceNo and the eight words func_0017F1C8 returns.
void GameState_SaveLocation(void) {
    GameState* t = gameState;

    t->worldNo = curWorldNo;
    t->roomNo = curRoomNo;
    t->entranceNo = curEntranceNo;
    *(XTrumpetUnk4C*)&t->unk_4C = *func_0017F1C8();
}


// Saves the location; rooms listed in presetPosRooms use the preset positions, the others the actual ones.
void GameState_SaveRoomPositions(void) {
    s32 i;
    XTrumpetSel* p;

    GameState_SaveLocation();
    for (i = 0; i < 39; i++) {
        p = &presetPosRooms[i];
        if (curWorldNo == p->unk_0 && curRoomNo == p->unk_1) {
            GameState_SetPresetPositions(p->index);
            return;
        }
    }
    GameState_SavePositions();
}

// Copies gameState vector index to out.
void GameState_GetPosition(s32 index, f32* out) {
    out[0] = (gameState->memberPos + index)->x;
    out[1] = (gameState->memberPos + index)->y;
    out[2] = (gameState->memberPos + index)->z;
    out[3] = (gameState->memberPos + index)->w;
}

void func_001113E8(void) {
    func_001809C8(&gameState->unk_4C);
}

void func_00111408(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 ofs;

    if (arg0 == 20) {
        return;
    }
    ofs = 0;
    for (i = 0; i < arg0; i++) {
        ofs += D_002BCB68[i];
    }
    gameState->unk_6C[ofs + arg1] = arg2;
}

s8 func_00111468(s32 arg0, s32 arg1) {
    s32 i;
    s32 ofs = 0;

    for (i = 0; i < arg0; i++) {
        ofs += D_002BCB68[i];
    }
    return gameState->unk_6C[ofs + arg1];
}

extern s32 D_002BBD90[];
extern u8* D_002BBD48[];

// D_002BBD48[group]: u8 count, count keys, then rows of count chars ('#' = skip, 'a'.. = value)
void func_001114B8(s32 group, s32 row) {
    u8* tbl;
    u8* keys;
    u8* vals;
    s32 i;

    if (D_002BBD90[group] == 0) {
        return;
    }
    tbl = D_002BBD48[group];
    keys = tbl + 2;
    vals = keys + tbl[1] * (row + 1);
    for (i = 0; i < tbl[1]; i++) {
        if (vals[i] != '#') {
            func_00111408(group, keys[i] - 1, (u8)(vals[i] - 'a'));
        }
    }
}

void func_00111580(s32 param1) {
    func_001114B8(curWorldNo, param1);
}

void* func_001115A0(void) {
    if (gameState != 0) {
        return gameState->unk_15C;
    }
    return NULL;
}

void func_001115C0(void) {
    if (gameState != 0) {
        gameState->unk_15C++;
    }
}

// Clears every work buffer and resets the game data, several subsystems and the game state (probably the new-game set-up).
void GameState_Initialize(void) {
    D_002B8364 = 0;
    WorkBuffers_Clear(-1);
    GameData_Reset();
    func_001601A8();
    func_0013CB18();
    func_001EBEB0();
    func_001BC048();
    GameState_Reset();
}

void func_00111638(void) {
    s32 value;

    D_002B8364 = 1;
    curWorldNo = gameState->worldNo;
    curRoomNo = gameState->roomNo;
    value = func_00111468(curWorldNo, curRoomNo);
    D_002B8684 = value;
    curEntranceNo = gameState->entranceNo;
}

void func_001116A8(void) {
    D_004D2998 = 0;
}

void func_001116B8(void) {
    D_004D2998 = 1;
}

void func_001116C8(void) {
    if (D_004D2998 == 0) {
        func_0022F808();
    }
}

void GameState_RefreshAvailableFlags(void) {
    s32 iVar1 = Party_FindCharacterSlot(3);
    if (iVar1 != -1) {
        gameState->charFlags |= 8;
    }
    iVar1 = Party_FindCharacterSlot(5);
    if (iVar1 != -1) {
        gameState->charFlags |= 0x20;
    }
    iVar1 = Party_FindCharacterSlot(6);
    if (iVar1 != -1) {
        gameState->charFlags |= 0x40;
    }
    iVar1 = Party_FindCharacterSlot(7);
    if (iVar1 != -1) {
        gameState->charFlags |= 0x80;
    }
    iVar1 = Party_FindCharacterSlot(8);
    if (iVar1 != -1) {
        gameState->charFlags |= 0x100;
    }
    iVar1 = Party_FindCharacterSlot(9);
    if (iVar1 != -1) {
        gameState->charFlags |= 0x200;
    }
}

void GameState_ApplyAvailableSelection(void) {
  switch (curWorldNo) {
  case 5:
    if (gameState->charFlags & 8) {
      Party_AddCharacter(3);
    }
    break;
  case 8:
    if (gameState->charFlags & 0x20) {
      Party_AddCharacter(5);
    }
    break;
  case 9:
    if (gameState->charFlags & 0x40) {
      Party_AddCharacter(6);
    }
    break;
  case 10:
    if (gameState->charFlags & 0x80) {
      Party_AddCharacter(7);
    }
    break;
  case 0xd:
    if (gameState->charFlags & 0x100) {
      Party_AddCharacter(8);
    }
    break;
  case 0xf:
    if (gameState->charFlags & 0x200) {
      Party_AddCharacter(9);
    }
  }
}

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xtrumpet", eu_func_00111AA8);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xtrumpet", eu_func_00111AC8);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xtrumpet", eu_func_00111B00);
#endif

#ifdef VERSION_FM
u32 fm_func_00111B08(arg0)
u32 arg0;
{
    return arg0;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111B10(void) {
    return fm_func_00111B08() / 216000;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111B48(void) {
    u32 t = fm_func_00111B08();
    u32 hours = t / 216000;
    u32 rest = t % 216000;

    return rest / 3600;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111B90(void) {
    u32 t = fm_func_00111B08();
    u32 hours = t / 216000;
    u32 rest = t % 216000;
    u32 minutes = rest / 3600;

    rest = rest % 3600;
    return rest / 60;
}
#endif

#ifdef VERSION_FM
u32 fm_func_00111BE8(void) {
    u32 t = fm_func_00111B08();
    u32 hours = t / 216000;
    u32 rest = t % 216000;
    u32 minutes = rest / 3600;
    u32 seconds;
    f32 f;

    rest = rest % 3600;
    seconds = rest / 60;
    rest = rest % 60;
    f = rest;
    f *= 100.0f / 60.0f;
    return f;
}
#endif

#ifdef VERSION_EU
void func_00111910(void);
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111910);
#else
void func_00111910(void) {
    D_002B9174 = 0;
}
#endif

extern volatile s32 D_002BBDF0;
extern s32 D_004D9250;
extern s32 D_004D9254;
extern f32 D_002BBDEC;

// timer task: counts D_002B916C up to D_004D9254 from the elapsed time (D_002BBDEC per tick)
#ifdef VERSION_EU
s32 func_00111920(void);
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111920);

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xtrumpet", eu_func_00111C60);
#endif

#ifdef VERSION_EU
INCLUDE_ASM("asm/nonmatchings/xtrumpet", eu_func_00111C70);
#endif
#else
s32 func_00111920(void) {
    switch (D_004D29AC) {
    case 1:
        return 0;
    case 2:
        return 4;
    case 0:
        if (D_002B916C < D_004D9254) {
            D_002B916C = (u32)(D_002BBDF0 - D_004D9250) * D_002BBDEC;
            return 0;
        }
        D_002B916C = D_004D9254;
        return 4;
    }
    return 0;
}
#endif

extern volatile s32 D_002BBDF0;
extern s32 D_004D9250;
extern s32 D_004D9254;

#ifdef VERSION_EU
void func_00111A00(s32 arg0);
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111A00);
#else
void func_00111A00(s32 arg0) {
    D_004D29AC = 0;
    D_004D9250 = D_002BBDF0;
    D_002B916C = 0;
    if (arg0 == 0) {
        D_004D9254 = 0x34B84;
    } else {
        D_004D9254 = 0x14996C4;
    }
    TaskSystem_AddTask(0x2C04C, func_00111920);
}
#endif

extern void (*D_004D9258)(void);

// timer task: counts D_002B916C down from D_004D9254; at zero it calls D_004D9258
#ifdef VERSION_EU
s32 func_00111A70(void);
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111A70);
#else
s32 func_00111A70(void) {
    switch (D_004D29AC) {
    case 1:
        return 0;
    case 2:
        return 4;
    case 0:
        if (D_002B916C > 0) {
            D_002B916C = D_004D9254 - (u32)(D_002BBDF0 - D_004D9250) * D_002BBDEC;
            return 0;
        }
        D_002B916C = 0;
        D_004D9258();
        return 4;
    }
    return 0;
}
#endif

// starts the countdown timer task (func_00111A70): sec seconds, then cb
#ifdef VERSION_EU
void func_00111B70(s32 sec, void (*cb)(void));
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111B70);
#else
void func_00111B70(s32 sec, void (*cb)(void)) {
    D_004D9258 = cb;
    D_004D29AC = 0;
    D_004D9250 = D_002BBDF0;
    D_002B916C = D_004D9254 = sec * 60;
    TaskSystem_AddTask(0x2C04C, func_00111A70);
}
#endif

void func_00111BD8(void) {
    D_004D29AC = 1;
    D_002B9174 = 1;
}

void func_00111BF0(void) {
    D_004D29AC = 0;
    D_002B9174 = 0;
}

s32 func_00111C08(void) {
    D_004D29AC = 2;
    return D_002B916C;
}

#ifdef VERSION_EU
void func_00111C20(s32 param1);
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111C20);
#else
void func_00111C20(s32 param1) {
    D_002B916C = param1 * 60;
}
#endif

void func_00111C38(s32 param1) {
    D_004D29C4 = param1;
    D_002B9170 = 0;
}

void func_00111C50(s32 param1) {
    D_002B9170 = param1;
}

s32 func_00111C60(s32 param1) {
    s32 result;

    D_002B9170 += param1;
    if (D_004D29C4 == 0 || D_002B9170 < D_004D29C4) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ u8 unk_20[0x14];
    /* 0x34 */ s32 time[2][4]; // fm_func_00111BE8, seconds, minutes, hours
} XTrumpetUnk9288;

extern XTrumpetUnk9288 D_004D9288;

#ifdef VERSION_FM


// splits a frame count into hours/minutes/seconds/hundredths (the fm_func_00111B08 helpers take it in a0)
void func_00111C98(s32 which, s32 t) {
    u32 hours, minutes, seconds, fraction;

    if (t < 0) {
        t = 0;
    }
    hours = ((u32 (*)(s32))fm_func_00111B10)(t);
    minutes = ((u32 (*)(s32))fm_func_00111B48)(t);
    seconds = ((u32 (*)(s32))fm_func_00111B90)(t);
    fraction = ((u32 (*)(s32))fm_func_00111BE8)(t);
    if (which == 0) {
        D_004D9288.time[0][0] = fraction;
        D_004D9288.time[0][1] = seconds;
        D_004D9288.time[0][2] = minutes;
        D_004D9288.time[0][3] = hours;
    } else {
        D_004D9288.time[1][0] = fraction;
        D_004D9288.time[1][1] = seconds;
        D_004D9288.time[1][2] = minutes;
        D_004D9288.time[1][3] = hours;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xtrumpet", func_00111C98);
#endif


extern s32 D_004D9260;

s32 func_00111D98(void) {
    func_00111C98(0, D_002B916C);
    func_00111C98(1, D_004D9260);
    if (D_002B9170 < 0) {
        D_002B9170 = 0;
    }
    if (D_004D29C4 < 0) {
        D_004D29C4 = 0;
    }
    D_004D9288.unk_10 = D_002B9170;
    D_004D9288.unk_14 = D_004D29C4;
    D_004D9288.unk_1C = D_002B9170;
    return D_004D29D0 ? 4 : 0;
}

typedef struct { s32 a0; s32 a3; s32 a9; s32 a6; s32 u10; s32 u14; s32 a5; s32 u1C; s32 a1; s32 a8; s32 u28; s32 a7; s32 a2; } XT9288v;
extern XT9288v D_004D9288_v __asm__("D_004D9288");
#define D D_004D9288_v
void func_002485B8(s32);
void func_00111E20(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9) {
    D.a0 = a0;
    D.a1 = a1;
    D_004D9260 = a4;
    D.a2 = a2;
    D.a3 = a3;
    D.a5 = a5;
    D.a6 = a6;
    D.a9 = a9;
    D.a8 = a8;
    D.u1C = D_002B9170;
    D.u28 = 0;
    func_00111C98(0, D_002B916C);
    func_00111C98(1, D_004D9260);
    D.a7 = a7;
    D.u10 = D_002B9170;
    D.u14 = D_004D29C4;
    func_002485B8((s32)&D);
    D_004D29D0 = 0;
    TaskSystem_AddTask(0x280A0, func_00111D98);
}
#undef D

void func_00111F00(void) {
    D_004D29D0 = 1;
    func_00245130();
    func_00245140();
}

// The following unused functions might be part of worldfile.c?

#ifndef VERSION_FM
void func_00111F28(void) {
}
#endif

void func_00111F30(void) {
}

void func_00111F38(void) {
}
