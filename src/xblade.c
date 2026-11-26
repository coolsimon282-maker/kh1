/**
 * World and room changes (world data file, room and entrance tables, start positions, room archive and .img loads, as
 * a chain of tasks and load callbacks), the pause screen (colours, fade, sound pause), and the 64 model / matrix slots
 * drawn for the room (func_00114638, func_00114818 packets).
 */
#include "common.h"

#include "sdk/ee/libgraph.h"
#include "sdk/ee/libvu0.h"

#include "worldfile.h"
#include "xblade.h"
#include "xarcade.h"
#include "xnoodle.h"
#include "xlamp.h"
#include "xtailor.h"
#include "disk.h"

#include "string.h"

typedef struct XPointy {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ s16 unk_02;
} XPointy;

typedef struct XBlobule {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x2C];
    /* 0x30 */ sceVu0FVECTOR unk_30;
} XBlobule; // size = 0x40

extern sceVu0FMATRIX D_00297850;
extern s32 D_002979E0;
extern s32 D_002979E4;
extern u32 D_002A0508;
extern s32 D_002A0510;
extern s32 D_002A0520[];
extern u32 D_002B29C4;
extern s32 D_002B2CC4;
extern s32 D_002B2CC8;
extern s32 D_002B8354;
extern s32 D_002B8364;
extern sceVu0FMATRIX D_002B84F0;
extern u32 D_002B85F8;
extern s32 curWorldNo;
extern s32 curRoomNo;
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[0x38];
} XWorldEntry; // size = 0x40

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ char unk_1C[0x20];
    /* 0x3C */ f32 unk_3C;
} XBladeObj;

extern XWorldEntry* roomTable;
extern XWorldEntry* entranceTable;
extern s32 entranceCount;
extern sceVu0FVECTOR D_004D92F0[3];
extern XBladeObj* D_002E26A0[3];
extern s32 D_002B91E8;
extern s32 D_004D92E0;
extern volatile s32 D_002BBDE0;
extern s32 D_002B9660;
void func_0011C5A8(void);
void PartyMenu_ClearOpenRequest(void);
void func_00113660(void);
void func_0011D598(s32, s32);

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x14];
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
} XBladeHdr;

void func_00111408(s32, s32, s32);
void func_001089D0(void*);
void func_00108FD0(s32, s32, s32, void*, s32);
extern s32 D_002B8684;
extern s32 D_002B8688;
extern s32 D_002B8698[];
extern s32 D_002B91E0;
//extern XBlobule D_002B92F0[];
extern s32 curEntranceNo;
extern s32 D_002B9304;
extern s32 D_002B9308;
extern s32 D_002B930C;
extern s32 D_002B9310;
extern s32 D_002B9314;
extern s32 D_002B9318[];
extern s32 D_002B9328;
extern s32 D_002B932C;
extern u32 D_002B9330;
extern u32 D_002B9334;
extern s32 D_002B9338;
extern u32 D_002B933C;
extern s32 D_002B9340;
extern volatile s32 D_002B9664; // TODO not sure if volatile but needed to match func_00113BC0
extern s32 D_002B9668;
extern s32 D_002B966C;

#ifdef VERSION_FM
#include "libdma.h"

// .data (0x002BCDA0-0x002BD150)
XWorldEntry* entranceTable = NULL;
s32 entranceCount = 0;
s32 curEntranceNo = 0;
XWorldEntry* roomTable = NULL;
u32 roomCount = 0;
s32 D_002B9304 = 0;
s32 D_002B9308 = 0;
s32 D_002B930C = 0;
s32 D_002B9310 = 0;
s32 D_002B9314 = 0;
s32 D_002B9318[4] = {0};
s32 D_002B9328 = 0;
s32 D_002B932C = 0;
u32 D_002B9330 = 0;
u32 D_002B9334 = 0;
s32 D_002B9338 = 0;
u32 D_002B933C = 0;
s32 D_002B9340 = 0;
// GIF packet (sent by func_00113410 through the ref tag D_002BD100)
u64 D_002BCE00[96] __attribute__((aligned(16))) = {
    0x1000000000000001ULL, 0xE,
    0x30000, 0x47,
    0xA400000000008009ULL, 0x5151515100ULL,
    0xC, 0xC,
    0x100000000ULL, 0x177007688ULL,
    0x14C000000ULL, 0x177007CF8ULL,
    0x100000000ULL, 0x179007688ULL,
    0x14C000000ULL, 0x179007CF8ULL,
    0xC, 0xC,
    0x14C000000ULL, 0x177007CF8ULL,
    0x14C000000ULL, 0x177008308ULL,
    0x14C000000ULL, 0x179007CF8ULL,
    0x14C000000ULL, 0x179008308ULL,
    0xC, 0xC,
    0x14C000000ULL, 0x177008308ULL,
    0x100000000ULL, 0x177008978ULL,
    0x14C000000ULL, 0x179008308ULL,
    0x100000000ULL, 0x179008978ULL,
    0xC, 0xC,
    0x100D17A88ULL, 0x176E07688ULL,
    0x180D17A88ULL, 0x176E07F08ULL,
    0x100D17A88ULL, 0x177007688ULL,
    0x180D17A88ULL, 0x177007F08ULL,
    0xC, 0xC,
    0x180D17A88ULL, 0x176E07F08ULL,
    0x180D17A88ULL, 0x176E080F8ULL,
    0x180D17A88ULL, 0x177007F08ULL,
    0x180D17A88ULL, 0x1770080F8ULL,
    0xC, 0xC,
    0x180D17A88ULL, 0x176E080F8ULL,
    0x100D17A88ULL, 0x176E08978ULL,
    0x180D17A88ULL, 0x1770080F8ULL,
    0x100D17A88ULL, 0x177008978ULL,
    0xC, 0xC,
    0x100D17A88ULL, 0x179007688ULL,
    0x180D17A88ULL, 0x179007F08ULL,
    0x100D17A88ULL, 0x179207688ULL,
    0x180D17A88ULL, 0x179207F08ULL,
    0xC, 0xC,
    0x180D17A88ULL, 0x179007F08ULL,
    0x180D17A88ULL, 0x1790080F8ULL,
    0x180D17A88ULL, 0x179207F08ULL,
    0x180D17A88ULL, 0x1792080F8ULL,
    0xC, 0xC,
    0x180D17A88ULL, 0x1790080F8ULL,
    0x100D17A88ULL, 0x179008978ULL,
    0x180D17A88ULL, 0x1792080F8ULL,
    0x100D17A88ULL, 0x179208978ULL,
};
sceDmaTag D_002BD100 = {48, 0, 0, (sceDmaTag*)D_002BCE00};
s32 D_002B9660 = 0;
volatile s32 D_002B9664 = 0;
s32 D_002B9668 = 0;
s32 D_002B966C = 0;
u64 D_002BD120[4] = {
    0x1000000000008001ULL, 0xE,
    0x507FD, 0x48,
};
sceDmaTag D_002BD140 = {2, 0, 0, (sceDmaTag*)D_002BD120};
#endif
extern s32 D_002BD8D8;
extern s32 D_002C1EBC;

extern s32 D_003F0DD8;

extern s32 D_004D2A2C;
extern s32 D_004D2A60;
extern s32 D_004D2A68;
extern s32 D_004D2A6C;
extern s32 D_004D2A70;
extern s32 D_004D2A74;
extern s32 D_004D2A8C;
extern s32 D_004D2A90;
extern s32 D_004D2A94;
extern s32 D_004D2A98;
extern s32 D_004D2A9C;
extern s32 D_004D2AA0;
extern s32 D_004D2AAC;
extern s32 D_004D2AB0;

extern s32 D_9A0000;

void func_001009A8();
s32 func_001016E8();
u16 func_00105660();
void GameState_SavePositions();
void func_001116C8();
void func_00114420();
void func_00117588();
void func_00177688(void);
void func_001776C8(void);
void func_00132450();
void func_00157B90();
void func_00177470();
void func_001778A0(s32);
void func_00180CE0();
void func_001C38C0();
void func_001C4FF0();
void* func_001EE280(s32);
void func_001ED878();

// D_002B91E8 = the current room entry's word +0x04.
void func_00112168(void) {
    D_002B91E8 = roomTable[curRoomNo].unk_04;
}

// Sets bit 0x20 of D_002B85F8.
void func_00112190(void) {
    D_002B85F8 |= 0x20;
}

// Clears bit 0x20 of D_002B85F8.
void func_001121A8(void) {
    D_002B85F8 &= ~0x20;
}

void World_ApplyWorldData(void);
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ char unk_30[0x10];
} XWorldEntryF;
typedef struct {
    s32 unk_00;
    s32 unk_04;
} XBladePair;
extern s32 D_002B91EC;
extern s32 D_002B91E4;
extern u32 roomCount;
extern s32 D_002BC12C;
extern s32 D_002B8C84;
extern s32 D_002BCB30;
extern s32 D_002C12C0;
extern s32 D_002C1380;
extern s32 D_002C1360;
extern s32 D_002C1384;
extern XBladePair D_002C1378;
extern s32 cameraRoll;
s32 func_00111468(s32, s32);
void GameState_ApplyAvailableSelection(void);
void func_00103280(f32, f32, f32, f32);
void *func_001EE228(void *);
u8 *func_001EAFF8(void);
void worldfile_getNames_v(void) __asm__("worldfile_getNames");

#define EA (XWorldEntryF *)(curRoomNo * 64 + (s32)roomTable)
// Reads the world data file at D_004D2A2C (room table, entrance table and other offsets), picks the room for a pending entrance, and applies the current room's settings (flags, colours, D_002C1378 pair; world 3 has an alternative pair late in the game, probably).
void World_ApplyWorldData(void) {
    u8 *h;
    u8 *w;
    XWorldEntryF *e1;
    XWorldEntryF *e2;
    XWorldEntryF *e3;
    XWorldEntryF *e4;

    h = (u8 *)D_004D2A2C;
    w = h + *(s32 *)(h + 0x10);
    D_002B91E0 = (s32)(h + *(s32 *)(h + 0x18));
    D_002B91EC = (s32)(h + *(s32 *)(h + 0x20));
    D_002B91E4 = (s32)(h + *(s32 *)(h + 0x30));
    D_002B9330 = (u32)(h + *(s32 *)(h + 0x38));
    roomTable = (XWorldEntry *)(w + *(s32 *)w);
    roomCount = *(u32 *)(w + 4) >> 6;
    entranceTable = (XWorldEntry *)(w + *(s32 *)(w + 8));
    entranceCount = *(u32 *)(w + 0xC) >> 6;
    if (D_002B9328 != 0) {
        curRoomNo = entranceTable[curEntranceNo].unk_00;
        D_002B8684 = func_00111468(curWorldNo, curRoomNo);
        worldfile_getNames_v();
        if (D_002B932C == 0) {
            GameState_ApplyAvailableSelection();
        }
    }
    D_002BC12C = roomTable[curRoomNo].unk_00;
    func_00103280(1.0f, 1.0f, 1.0f, 1.0f);
    ScreenWobble_Set(1.0f, 1.0f, 1.0f, 1.0f);
    D_002B8C84 = (((XWorldEntryF *)roomTable)[curRoomNo].unk_10 >> 1) & 1;
    if (D_002B8C84 != 0) {
        ScreenWobble_Set(1.0f, 0.9f, 1.0f, (13421772.0f / 268435456.0f));
    }
    e1 = EA;
    D_002B85F8 = (D_002B85F8 & ~4) | (((*(u32 *)((u8 *)e1 + 0x10) & 1) ^ 1) << 2);
    D_002B85F8 = (D_002B85F8 & ~8) | ((((*(u32 *)((u8 *)e1 + 0x10) >> 2) & 1) ^ 1) << 3);
    func_00112190();
    e2 = EA;
    D_002BCB30 = (e2->unk_10 >> 3) & 1;
    D_002C12C0 = (e2->unk_10 >> 6) & 1;
    D_002C1380 = e2->unk_14;
    D_002C1360 = e2->unk_18;
    D_002C1384 = e2->unk_1C;
    D_002A0520[0] = e2->unk_20;
    D_002A0520[1] = e2->unk_24;
    func_001EE228((void *)D_002C1380);
    e3 = EA;
    D_002C1378.unk_00 = e3->unk_08;
    D_002C1378.unk_04 = e3->unk_0C;
    if (curWorldNo == 3 && *func_001EAFF8() >= 0x2B) {
        e4 = EA;
        D_002C1378.unk_00 = e4->unk_28;
        D_002C1378.unk_04 = e4->unk_2C;
    }
    cameraRoll = 0;
}

// Adds task func_001016E8 (priority 50000).
void* func_001124E8(void) {
    return TaskSystem_AddTask(50000, func_001016E8);
}

// Load callback of the room file: sets up sound (SoundRpc_Initialize(2), func_001EE1E0 banks), resets func_0014A248 / func_00146BC8 slots, then func_0011CC20 with func_001124E8.
s32 func_00112508(UNK_TYPE arg0, UNK_TYPE arg1, s32* arg2) {
    SoundRpc_Initialize(2);
    func_001EE1E0(3, -9);
    func_00101528();
    func_001EE1E0(0, -1);
    func_001EE1E0(3, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_0014A248();
    func_00146BC8(-3);
    func_00146BC8(-4);
    func_00146BC8(-5);
    func_00146BC8(-6);
    func_00146BC8(-7);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE1E0(3, -10);
    return func_0011CC20(-1, arg2, func_001124E8);
}

// Loads the file named by func_0011C938 into a func_00155ED8(0x34, 4) buffer with func_00112508 as callback.
s32 func_001125F0(void) {
    char stack[64];

    func_0011C938(stack);
    return cdvd_QueueFileLoad(stack, func_00155ED8(0x34, 4), func_00112508, 0);
}

// Load callback for the world data file: applies it, sets up D_002A0508 from D_002B9330 (aligned to 0x40) and loads the room file.
s32 World_OnWorldDataLoaded(void) {
    World_ApplyWorldData();
    func_0010E580();
    Gs_LoadFontImage(D_002B9330);
    D_002A0508 = D_002B9330;
    D_002A0508 = AlignUp(D_002B9330, 0x40);
    return func_001125F0();
}

// Task: unless a load is already pending, reloads the world names and loads the world data file (worldDataFile) when the world changed, else goes on with the room.
s32 World_LoadTask(void) {
    if (D_002B930C == 1 && D_002B9310 == 0) {
        return 0;
    }

    worldfile_getNames();
    D_002B9304 = 0;
    D_002B9308 = 0;
    D_002B9314 = 1;
    D_004D2A2C = &D_9A0000;
    func_00177688();
    func_001776C8();

    if (D_002B8688 == curWorldNo) {
        D_002B9304 = 1;
    }
    
    if (D_002B9304 == 1) {
        World_ApplyWorldData();
        if (D_002B9328 != 0) {
            func_001125F0();
        } else {
            func_001124E8();
        }
    } else {
        cdvd_QueueFileLoad(worldDataFile, D_004D2A2C, World_OnWorldDataLoaded, 0);
    }
    return 4;
}

// Task: stops the scripts (func_001C38C0) and adds World_LoadTask.
s32 World_StartLoadTask(void) {
    func_001C38C0();
    D_002B29C4 = 0;
    func_00122720();
    TaskSystem_AddTask(189999, World_LoadTask);
    return 4;
}

// Adds World_StartLoadTask (priority 190000).
void* World_StartLoad(void) {
    func_001009D8();
    return TaskSystem_AddTask(190000, World_StartLoadTask);
}

// Sets the world, room, D_002B8684 and entrance number, records them (func_00111408) and starts loading.
void World_ChangeRoom(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    curEntranceNo = arg3;
    curWorldNo = arg0;
    curRoomNo = arg1;
    D_002B8684 = arg2;
    func_00111408(arg0, arg1, arg2);
    World_StartLoad();
}

// Same as World_ChangeRoom without func_00111408.
void* World_ChangeRoomDirect(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    curEntranceNo = arg3;
    curWorldNo = arg0;
    curRoomNo = arg1;
    D_002B8684 = arg2;
    return World_StartLoad();
}

// Goes to entrance arg0 of the current world (its room from the entrance table) and starts loading.
void World_ChangeToEntrance(s32 arg0) {
    s32 val;

    curEntranceNo = arg0;
    val = entranceTable[arg0].unk_00;
    curRoomNo = val;
    D_002B8684 = func_00111468(curWorldNo, val);
    World_StartLoad();
}

// Load callback of Room_PreloadBinImg: keeps the buffer (D_002A0510) and marks it loaded (D_002B9310).
void Room_OnBinImgPreloaded(s32 arg0) {
    D_002A0510 = arg0;
    D_002B9310 = 1;
}

extern s32 D_002A050C;
extern s32 D_002B868C;

// Starts loading <room>.img of the room behind entrance arg0 when it is not the current one (and flag 13 of D_002C1EA8 is clear).
void Room_PreloadBinImg(s32 arg0) {
    char str[0x40];
    s32 one = 1;
    s32 id;

    if (((D_002C1EA8 >> 13) & 1) != one) {
        id = roomTable[entranceTable[arg0].unk_00].unk_00;
        if (D_002B868C != id) {
            D_002B930C = one;
            worldfile_getBinImgName(id);
            strcpy(str, worldBinImgFile);
            strcat(str, ".img");
            D_002A050C = func_00155ED8(0x34, 8);
            D_002A050C = AlignUp(D_002A050C, 0x80);
            cdvd_QueueFileLoad(str, D_002A050C, (s32 (*)(void))Room_OnBinImgPreloaded, 0);
        }
    }
}
// extern s32 D_002A050C;
// extern s32 D_002B868C;
// extern s32 D_002B92FC;

// typedef struct Something {
//     /* 0x00 */ s32 unk_00;
//     /* 0x04 */ char unk_04[0x3C];
// } Something;

// extern s32* D_002B92F0;

// void Room_PreloadBinImg(s32 arg0) {
//     char str[0x40];
//     s32* temp;
//     s32 temp2;
//     s32 new_var2 = 1;
    
//     if (((D_002C1EA8 >> 0xD) & 1) != new_var2) {
//         temp = (D_002B92F0[arg0 << 4] << 6) + D_002B92FC;
//         temp2 = *temp;
//         if (D_002B868C != temp2) {
//             D_002B930C = 1;
//             worldfile_getBinImgName(temp2);
//             strcpy(str, worldBinImgFile);
//             strcat(str, ".img");
//             D_002A050C = func_00155ED8(0x34, 8);
//             D_002A050C = AlignUp(D_002A050C, 0x80);
//             cdvd_QueueFileLoad(str, D_002A050C, Room_OnBinImgPreloaded, 0);
//         }
//     }
// }

// Task: func_0011C6C8(0), D_002B29C4 = 0, func_00122720.
s32 func_001129C8(void) {
    func_0011C6C8(0);
    D_002B29C4 = 0;
    func_00122720();
    return 4;
}

// Stops sounds and fades them out over 360 frames (func_0011C5F0, func_0011D310, func_00101628).
void func_001129F8(void) {
    func_00157B90();
    D_002A0520[1] = 0;
    D_002A0520[0] = 0;
    func_0011C5F0(0, 0, 360);
    func_0011C5F0(1, 0, 360);
    func_0011D310(360);
    func_00101628(360);
}

// Leaves the room for mode 4 (GameMode_Request(4)), keeping world and room in D_002B8698.
void func_00112A50(void) {
    func_0012C990(2, 0);
    func_0012C990(6, 0);
    D_002C1EA8 |= 0x80000;
    func_001129F8();
    func_001C38C0();
    TaskSystem_AddTask(190000, func_001129C8);
    D_002B8698[0] = curWorldNo;
    D_002B8698[1] = curRoomNo;
    GameMode_Request(4);
}

// Leaves the room for mode 6, saving party positions and world, room, entrance in D_002B9318.
void func_00112AD8(void) {
    D_002C1EA8 |= 0x80000;
    func_001129F8();
    func_001C38C0();
    Party_SaveSpawnPositions();
    TaskSystem_AddTask(190000, func_001129C8);
    D_002B9318[0] = curWorldNo;
    D_002B9318[1] = curRoomNo;
    D_002B9318[2] = curEntranceNo;
    GameMode_Request(6);
}

// Empty.
void func_00112B60(void) {
    // empty function
}

// Sets up sound for a new room (SoundRpc_Initialize(2) and the func_001EE1E0 banks).
void func_00112B68(void) {
    SoundRpc_Initialize(2);
    func_001EE1E0(3, -9);
    func_001EE1E0(0, -1);
    func_001EE1E0(3, -1);
    func_001EE1E0(0, 0);
    func_001EE1E0(0, 1);
    func_001EE1E0(1, 0);
    func_001EE1E0(1, 1);
    func_001EE1E0(0, -8);
    func_001EE1E0(3, -8);
    func_001EE1E0(0, -3);
    func_001EE1E0(3, -3);
    func_001EE1E0(0, -4);
    func_001EE1E0(3, -4);
    func_001EE1E0(0, -5);
    func_001EE1E0(3, -5);
    func_001EE1E0(0, -6);
    func_001EE1E0(3, -6);
    func_001EE1E0(0, -7);
    func_001EE1E0(3, -7);
    func_001EE1E0(3, -10);
}

// func_00114420, then mode 9 (GameMode_Request).
void* func_00112C70(void) {
    func_00114420();
    return GameMode_Request(9);
}

#ifdef VERSION_FM
// Returns D_004D92E0 (FM only).
s32 fm_func_00112FC0(void) {
    return D_004D92E0;
}
#endif

#ifdef VERSION_FM
// Sets D_004D92E0 (FM only).
void fm_func_00112FD0(s32 arg0) {
    D_004D92E0 = arg0;
}
#endif

#ifdef VERSION_FM
// func_00114420, then mode 8 (FM: sets D_004D92E0 = 1 first).
void* func_00112C90(void) {
    func_00114420();
    fm_func_00112FD0(1);
    return GameMode_Request(8);
}
#else
void* func_00112C90(void) {
    func_00114420();
    return GameMode_Request(8);
}
#endif

// func_00155ED8(61, 3).
s32 func_00112CB0(void) {
    return func_00155ED8(61, 3);
}

// func_00155ED8(0, 64).
s32 func_00112CD0(void) {
    return func_00155ED8(0, 64);
}

// Stores the position and angle (+0x10, +0x3C) of the three party members (D_002E26A0) in D_004D92F0.
void Party_SaveSpawnPositions(void) {
    s32 i;
    XBladeObj* obj;

    for (i = 0; i < 3; i++) {
        obj = D_002E26A0[i];
        if (obj != NULL) {
            D_004D92F0[i][0] = obj->unk_10;
            D_004D92F0[i][1] = obj->unk_14;
            D_004D92F0[i][2] = obj->unk_18;
            D_004D92F0[i][3] = obj->unk_3C;
        }
    }
}

// Party member i's position stored by Party_SaveSpawnPositions.
void Party_GetSavedSpawnPosition(s32 i, sceVu0FVECTOR dst) {
    dst[0] = D_004D92F0[i][0];
    dst[1] = D_004D92F0[i][1];
    dst[2] = D_004D92F0[i][2];
    dst[3] = D_004D92F0[i][3];
}

// Index of the first entrance of the current room in the entrance table, or 1000.
s32 World_FindEntranceForRoom(void) {
    s32 i;

    for (i = 0; i < entranceCount; i++) {
        if (curRoomNo == entranceTable[i].unk_00) {
            return i;
        }
    }
    return 1000;
}

void GameState_GetPosition(s32, sceVu0FVECTOR);
void func_00104FD0(s32, sceVu0FVECTOR);

// Start position of party member 0: from the current entrance (floats 4..7), the saved one, or GameState_GetPosition(0).
void World_GetSpawnPos0(sceVu0FVECTOR dst) {
    if (curEntranceNo == -1) {
        curEntranceNo = World_FindEntranceForRoom();
    }
    if (curEntranceNo < entranceCount) {
        dst[0] = ((f32*)&entranceTable[curEntranceNo])[4];
        dst[1] = ((f32*)&entranceTable[curEntranceNo])[5];
        dst[2] = ((f32*)&entranceTable[curEntranceNo])[6];
        dst[3] = ((f32*)&entranceTable[curEntranceNo])[7];
        if (D_002B9328 != 0) {
            if (D_002B932C == 1) {
                Party_GetSavedSpawnPosition(0, dst);
            }
        }
        if (D_002B8364 == 1) {
            GameState_GetPosition(0, dst);
        }
    } else {
        func_00104FD0(0, dst);
    }
}

// Start position of party member 1 (entrance floats 8..11).
void World_GetSpawnPos1(sceVu0FVECTOR dst) {
    if (curEntranceNo == -1) {
        curEntranceNo = World_FindEntranceForRoom();
    }
    if (curEntranceNo < entranceCount) {
        dst[0] = ((f32*)&entranceTable[curEntranceNo])[8];
        dst[1] = ((f32*)&entranceTable[curEntranceNo])[9];
        dst[2] = ((f32*)&entranceTable[curEntranceNo])[10];
        dst[3] = ((f32*)&entranceTable[curEntranceNo])[11];
        if (D_002B9328 != 0) {
            if (D_002B932C == 1) {
                Party_GetSavedSpawnPosition(1, dst);
            }
        }
        if (D_002B8364 == 1) {
            GameState_GetPosition(1, dst);
        }
    } else {
        func_00104FD0(0, dst);
    }
}

// Start position of party member 2 (entrance floats 12..15).
void World_GetSpawnPos2(sceVu0FVECTOR dst) {
    if (curEntranceNo == -1) {
        curEntranceNo = World_FindEntranceForRoom();
    }
    if (curEntranceNo < entranceCount) {
        dst[0] = ((f32*)&entranceTable[curEntranceNo])[12];
        dst[1] = ((f32*)&entranceTable[curEntranceNo])[13];
        dst[2] = ((f32*)&entranceTable[curEntranceNo])[14];
        dst[3] = ((f32*)&entranceTable[curEntranceNo])[15];
        if (D_002B9328 != 0) {
            if (D_002B932C == 1) {
                Party_GetSavedSpawnPosition(2, dst);
            }
        }
        if (D_002B8364 == 1) {
            GameState_GetPosition(2, dst);
        }
    } else {
        func_00104FD0(0, dst);
    }
}
extern s32 D_002B92F4;

// void func_00104DC8(s32, sceVu0FVECTOR);
// void GameState_GetPosition(s32, sceVu0FVECTOR);
// void Party_GetSavedSpawnPosition(s32, sceVu0FVECTOR);
// s32 World_FindEntranceForRoom(void);

// void World_GetSpawnPos2(sceVu0FVECTOR arg0) {
//     sceVu0FMATRIX* mtx;

//     if (curEntranceNo == -1) {
//         curEntranceNo = World_FindEntranceForRoom();
//     }
//     if (curEntranceNo < D_002B92F4) {
//         mtx = &D_002B92F0[curEntranceNo];
//         arg0[0] = (*mtx)[3][0];
//         arg0[1] = (*mtx)[3][1];
//         arg0[2] = (*mtx)[3][2];
//         arg0[3] = (*mtx)[3][3];
//         if (D_002B9328 != 0) {
//             if (D_002B932C == 1) {
//                 Party_GetSavedSpawnPosition(2, arg0);
//             }
//         }
//         if (D_002B8364 == 1) {
//             GameState_GetPosition(2, arg0);
//         }
//     } else {
//         func_00104DC8(0, arg0);
//     }
// }

// D_002B9334 = arg0: func_001C4740(arg0, 0) when non-zero, else Fade_ResetScreenColor.
s32 func_001130F0(s32 arg0) {
    D_002B9334 = arg0;
    if (arg0 != 0) {
        D_002B933C = 0;
        return func_001C4740(arg0, 0);
    }
    return Fade_ResetScreenColor();
}

// func_0013C008 while a pending entrance exists and D_002B932C == 0.
void func_00113130(void) {
    if (D_002B9328 != 0 && D_002B932C == 0) {
        func_0013C008();
    }
}

// func_00105860 (returns a value) is called without a prototype: one more declaration here changes
// func_00114B50's code.
void func_00132550();
void func_00175F58();
void func_001113E8();
extern s32 D_0029B410;
extern s32 D_0029B414;

// Task: finishes entering the room (starts its script func_001C4FF0(D_002B91E0), clears load flags, saves positions).
s32 func_00113170(void) {
    if (D_002B2CC4 != 0) {
        return 0;
    }
    D_002B8354 = 1;
    func_00105860();
    func_00180CE0();
    func_00132550();
    D_002B933C = 1;

    if (D_0029B410 != 0 && D_0029B414 != 0) {
        func_00175F58(D_0029B410, D_0029B414, curRoomNo + 1, 100000);
    }

    func_001009A8();
    D_002C1EA8 &= ~0x4;
    D_002C1EA8 &= ~0x8000000;
    func_001C4FF0(D_002B91E0, 0);
    D_002B930C = 0;
    D_002B9310 = 0;
    D_002B9328 = 0;
    func_00114430();
    D_002BD8D8 = 0;

    if (D_002B8364 == 1 || D_002B29C4 == 1) {
        func_001113E8();
    }

    D_002B8364 = 0;
    GameState_SavePositions();
    func_001116C8();
    func_001ED878(0);
    D_002B9314 = 0;
    return 4;
}

// Adds task func_00113170 (priority 49900).
void* func_001132A0(void) {
    return TaskSystem_AddTask(49900, func_00113170);
}

// func_00113130, then func_00122588(D_002B9340, func_001132A0).
void func_001132C0(void) {
    func_00113130();
    func_00122588(D_002B9340, func_001132A0);
}

// Load callback of the room archive: resets the 64 model slots, then goes on (func_001132C0), through func_0011E7C8 when D_002B9338 == 0.
void Room_OnArchiveLoaded(void) {
    if (D_002B29C4 == 1) {
        func_0013C668();
    }
    func_001144C8();
    if (D_002B9338 == 0) {
        D_002BD8D8 = 1;
        func_0011E7C8(func_001132C0, func_00155ED8(0x34, 4));
        return;
    }
    func_001132C0();
}

// Task: loads roomArchiveFile into D_002B9340 (aligned to 0x80) with Room_OnArchiveLoaded as callback.
s32 Room_LoadArchive(void) {
    func_00112168();
    func_00101580();
    D_002B9340 = AlignUp(D_002B9340, 0x80);
    cdvd_QueueFileLoad(roomArchiveFile, D_002B9340, Room_OnArchiveLoaded, 0);
    return 4;
}

// Rounds arg0 up to a multiple of arg1.
s32 AlignUp(s32 arg0, s32 arg1) {
    if ((arg0 % arg1) != 0) {
        arg0 = ((arg0 / arg1) * arg1) + arg1;
    }
    return arg0;
}

#ifndef NON_MATCHING
// Draws the pause screen probably: GS register words from the colours D_004D2A8C..D_004D2AA0, messages 5..9, then sets the display (PMODE, DISPFB1, DISPLAY1).
INCLUDE_ASM("asm/nonmatchings/xblade", PauseScreen_Draw);
#else

typedef struct Big300 {
    /* 0x00 */ s64 unk_00[0x300 / 8];
} Big300; // size = 0x300;

extern Big300 D_002B9350;
extern s32 D_002B9650;

s32 func_001F0EF0(s32);

void PauseScreen_Draw(void) {
    s32 temp_16;
    s32 temp_7;
    u64 temp_3;
    u64 temp_5;
    u64 new_var2;
    s32 new_var4;
    s32 *new_var6;

    new_var6 = &D_004D2A98;
    new_var4 = (*new_var6) << 0x18;
    temp_7 = D_004D2A94 << 0x10;
    new_var2 = (u64) D_004D2A9C << 0x18;
    temp_7 = temp_7 | D_004D2A90 << 8;

    temp_3 = ((u64) D_004D2AA0 << 0x18) | 0x100D17A88;

    D_002B9350.unk_00[0x140 / 8] = temp_3;
    D_002B9350.unk_00[0x160 / 8] = temp_3;
    D_002B9350.unk_00[0x180 / 8] = temp_3;
    D_002B9350.unk_00[0x190 / 8] = temp_3;
    D_002B9350.unk_00[0x1A0 / 8] = temp_3;
    D_002B9350.unk_00[0x1B0 / 8] = temp_3;
    D_002B9350.unk_00[0x1D0 / 8] = temp_3;
    D_002B9350.unk_00[0x1F0 / 8] = temp_3;
    D_002B9350.unk_00[0x230 / 8] = temp_3;
    D_002B9350.unk_00[0x250 / 8] = temp_3;
    D_002B9350.unk_00[0x270 / 8] = temp_3;
    D_002B9350.unk_00[0x280 / 8] = temp_3;
    D_002B9350.unk_00[0x290 / 8] = temp_3;
    D_002B9350.unk_00[0x2A0 / 8] = temp_3;
    D_002B9350.unk_00[0x2C0 / 8] = temp_3;
    D_002B9350.unk_00[0x2E0 / 8] = temp_3;
    
    temp_5 = new_var2 | 0x100000000;
    
    D_002B9350.unk_00[0x50 / 8] = temp_5;
    D_002B9350.unk_00[0x70 / 8] = temp_5;
    D_002B9350.unk_00[0x90 / 8] = temp_5;
    D_002B9350.unk_00[0xA0 / 8] = temp_5;
    D_002B9350.unk_00[0xB0 / 8] = temp_5;
    D_002B9350.unk_00[0xC0 / 8] = temp_5;
    D_002B9350.unk_00[0xE0 / 8] = temp_5;
    D_002B9350.unk_00[0x100 / 8] = temp_5;

    temp_16 = D_004D2A8C | new_var4 | temp_7;
    
    Frame_UpdateTimeStep();
    func_0010F3D0();
    func_00106948(&D_002B9650);
    func_001F2EF8(temp_16, 0xB6, 0x36, func_001F0EF0(5), 18);
    func_001F2EF8(temp_16, 0xD6, 0x36, func_001F0EF0(6), 18);
    func_001F2EF8(temp_16, 0xF6, 0x36, func_001F0EF0(7), 18);
    func_001F2EF8(temp_16, 0x116, 0x36, func_001F0EF0(8), 18);
    func_001F2EF8(temp_16, 0x136, 0x36, func_001F0EF0(9), 18);
    func_0010F420();
    sceGsSyncPath(0, 0);

    DPUT_GS_PMODE(0xFF03);
    DPUT_GS_DISPFB1(0x11B0);
    DPUT_GS_DISPLAY1(0x7F9FF020D227C);
}
#endif

// Sets the pause screen colours D_004D2A8C..D_004D2AA0 to their defaults.
void PauseScreen_ResetColors(void) {
    D_004D2A8C = 205;
    D_004D2A90 = 135;
    D_004D2A94 = 50;
    D_004D2A98 = 128;
    D_004D2A9C = 76;
    D_004D2AA0 = 128;
}

typedef struct {
    /* 0x0 */ s32 unk_00;
    /* 0x4 */ s32 unk_04;
    /* 0x8 */ s32 unk_08;
} XBlade5AD0;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C[9];
    /* 0x30 */ s32 unk_30[15];
    /* 0x6C */ s32 unk_6C;
} XBlade5BB0;

extern volatile XBlade5AD0 D_002C5AD0;
extern volatile XBlade5BB0 D_002C5BB0;

// Clears D_002C5AD0 / D_002C5BB0 counters.
void func_00113660(void) {
    D_002C5AD0.unk_08 = 0;
    D_002C5AD0.unk_04 = 0;
    D_002C5BB0.unk_6C = 0;
    D_002C5BB0.unk_04 = 0;
    D_002C5BB0.unk_08 = 0;
    D_002C5BB0.unk_30[0] = 0;
    D_002C5BB0.unk_30[1] = 0;
    D_002C5BB0.unk_30[2] = 0;
    D_002C5BB0.unk_30[3] = 0;
    D_002C5BB0.unk_30[4] = 0;
    D_002C5BB0.unk_30[5] = 0;
    D_002C5BB0.unk_30[6] = 0;
    D_002C5BB0.unk_30[7] = 0;
    D_002C5BB0.unk_30[8] = 0;
    D_002C5BB0.unk_30[9] = 0;
    D_002C5BB0.unk_30[10] = 0;
    D_002C5BB0.unk_30[11] = 0;
    D_002C5BB0.unk_30[12] = 0;
    D_002C5BB0.unk_30[13] = 0;
    D_002C5BB0.unk_30[14] = 0;
}

void PauseScreen_Show(s32);
// 0: restores the normal display (PMODE 0x22); else draws the pause screen with the default colours.
void PauseScreen_Show(s32 arg0) {
    if (arg0 == 0) {
        Frame_UpdateTimeStep();
        DPUT_GS_PMODE(0x22);
    } else {
        PauseScreen_ResetColors();
        PauseScreen_Draw();
    }
}

extern s32 D_004D2A80;
extern s32 D_004D2A84;
extern s32 D_004D2A88;
extern s32 D_004D2AA4;

#ifdef VERSION_FM
NOTHROW(int, PauseScreen_Draw);
extern s32 D_004D9340;
extern s32 D_004D9344;
extern s32 D_004D9348;
extern s32 D_004D9364;
// Steps the pause screen colour fade in (D_004D9340 = 1) or out (2) and redraws it (FM).
void PauseScreen_AnimateColors(void) {
    switch (D_004D9340) {
        default:
        case 0:
            return;
        case 1:
            switch (D_004D9344) {
                case 0:
                    if (D_004D9348 < 2) {
                        D_004D2A8C += 0;
                        D_004D2A90 += 0;
                        D_004D2A94 += 0;
                        D_004D2A98 += 50;
                        D_004D2A9C += 15;
                        D_004D2AA0 += 25;
                        break;
                    }
                    D_004D9344 = 1;
                case 1:
                    if (D_004D9348 < 5) {
                        D_004D2A8C += 25;
                        D_004D2A90 += 2;
                        D_004D2A94 -= 68;
                        D_004D2A98 += 9;
                        D_004D2A9C += 15;
                        D_004D2AA0 += 25;
                        break;
                    }
                    D_004D9344 = 2;
                case 2:
                    D_004D9364 = 0;
                    PauseScreen_ResetColors();
                    break;
            }
            break;
        case 2:
            switch (D_004D9344) {
                case 0:
                    if (D_004D9348 < 2) {
                        D_004D2A8C -= 0;
                        D_004D2A90 -= 0;
                        D_004D2A94 -= 0;
                        D_004D2A98 -= 14;
                        D_004D2A9C -= 15;
                        D_004D2AA0 -= 25;
                        break;
                    }
                    D_004D9344 = 1;
                case 1:
                    if (D_004D9348 < 5) {
                        D_004D2A8C -= 25;
                        D_004D2A90 -= 2;
                        D_004D2A94 += 68;
                        D_004D2A98 -= 33;
                        D_004D2A9C -= 15;
                        D_004D2AA0 -= 25;
                        break;
                    }
                    D_004D9344 = 2;
                case 2:
                    PauseScreen_Show(0);

                    if (D_002B9668 == 2) {
                        func_00113A10(0);
                    } else {
                        Sound_PauseNested(0);
                    }
                    D_004D9340 = 0;
                    return;
            }
            break;
    }
    PauseScreen_Draw();
    D_004D9348++;
}
#else
INCLUDE_ASM("asm/nonmatchings/xblade", PauseScreen_AnimateColors);
#endif

// Clears D_004D2A68 (sound pause count) and D_004D2A6C.
void func_001139F8(void) {
    D_004D2A68 = 0;
    D_004D2A6C = 0;
}

// func_001EE280(arg0) and remembers arg0 in D_004D2A6C.
void* func_00113A10(s32 arg0) {
    void* p0 = func_001EE280(arg0);
    D_004D2A6C = arg0;
    return p0;
}

// arg0 != 0: pauses sound (func_001EE280(2)) and counts up; 0: counts down and resumes at zero. Prints "ERROR:sound pause" on wrap.
void Sound_PauseNested(s32 arg0) {
    if (arg0 == 0) {
        D_004D2A68--;
        if (D_004D2A68 == 0) {
            if (D_004D2A6C == 1) {
                func_00113A10(arg0);
                func_001EEC58();
                Frame_UpdateTimeStep();
                func_00113A10(1);
            } else {
                func_00113A10(arg0);
            }
        }
    } else {
        func_001EE280(2);
        D_004D2A68++;
        if (D_004D2A68 == 0) {
            D_004D2A68++;
            printf("ERROR:sound pause\n");
        }
    }
}

// Task: func_00102970(0x80, 0x20) until D_004D2A70 == 4.
s32 func_00113AF8(void) {
    func_00102970(0x80, 0x20);

    if (D_004D2A70 == 4) {
        return 0;
    }
    return 4;
}

// Task: adds func_00113AF8 (priority 10499), D_004D2A70 = 3.
s32 func_00113B30(void) {
    XPointy* p0 = TaskSystem_AddTask(10499, func_00113AF8);
    p0->unk_02 = 1;
    func_00102970(0x80, 0x10);
    D_004D2A70 = 3;
    return 4;
}

// Task: adds func_00113B30 (priority 190019), Screen_SaveRegion.
s32 func_00113B78(void) {
    XPointy* p0 = TaskSystem_AddTask(190019, func_00113B30);
    p0->unk_02 = 1;
    Screen_SaveRegion();
    func_00102970(0x80, 0x10);
    return 4;
}

// Task: ends the pause (D_004D2A70 = D_002B9664 = D_004D2A60 = 0, func_001778A0(0)).
s32 func_00113BC0(void) {
    func_00102970(0x80, 0);
    if (D_003F0DD8 != 0) {
        D_003F0DD8 = 0;
        func_00112A50();
    }
    D_004D2A70 = 0;
    D_002B9664 = 0;
    sceGsSyncPath(0, 0);
    func_00121D50(D_002B2CC8);
    func_001778A0(0);
    D_004D2A60 = 0;
    return 4;
}

// Task: adds func_00113BC0 (priority 190019).
s32 func_00113C40(void) {
    XPointy* p0;

    func_00102970(0x80, 0x10);
    p0 = TaskSystem_AddTask(190019, func_00113BC0);
    p0->unk_02 = -1;
    return 4;
}

// Task: func_00102970(0x80, 0x20).
s32 func_00113C80(void) {
    func_00102970(0x80, 0x20);
    return 4;
}

// D_002B9668 = 1.
void func_00113CA8(void) {
    D_002B9668 = 1;
}

extern u32 D_00375BC0;
extern s32 fadeScreenColor;
extern s32 fadeOverlayAlpha;
extern s32 D_002A6204;
extern s32 D_002BD858;
extern s32 D_002BD85C;
// func_00114B50 compiles differently with another number of function declarations in this file (cse
// hashes symbol addresses); func_001336A0's prototype keeps the count right since func_00114638 matched.
s32 func_001336A0(void);

// include/xblade.h declares this `void PauseMenu_SelectMode();` but it returns D_002B9668; define it under
// another C name with the real symbol name.
s32 func_00113CB8_s32(void) __asm__("PauseMenu_SelectMode");

// PauseMenu_SelectMode: picks the pause mode D_002B9668 (0..7) from the game flags when no pause is running.
s32 func_00113CB8_s32(void) {
    s32 one;

    if (D_004D2A60 == 0) {
        one = 1;
        D_002B9668 = 0;
        if ((D_002C1EA8 & 1) == one) {
            D_002B9668 = 2;
        }
        if (((D_002C1EA8 >> 4) & 1) == one) {
            D_002B9668 = 2;
        }
        if (((D_00375BC0 >> 1) & 1) == one) {
            D_002B9668 = one;
        }
        if (((D_00375BC0 >> 3) & 1) == one) {
            D_002B9668 = 3;
        }
        if (D_002B966C == one) {
            D_002B9668 = D_002B966C;
        }
        if (D_002BD858 != 0) {
            D_002B9668 = 4;
        }
        if (D_002BD85C != 0) {
            D_002B9668 = 5;
        }
        if (D_002BBDE0 == 5) {
#ifdef VERSION_FM
            D_002B9668 = 7;
#else
            D_002B9668 = 2;
#endif
        }
        if (func_001336A0() != 0) {
            D_002B9668 = 2;
        }
        if (D_002B9668 == 0) {
            if (fadeScreenColor != 0x80 || fadeOverlayAlpha != 0 || D_002A6204 != 0) {
                D_002B9668 = 1;
            }
        }
    }
    return D_002B9668;
}

// D_002C1EBC = 1.
void func_00113E18(void) {
    D_002C1EBC = 1;
}

// D_002C1EBC = 0.
void func_00113E28(void) {
    D_002C1EBC = 0;
}

// Starts the pause: func_001778A0(1), D_004D2A70 = D_004D2A60 = 1.
void func_00113E38(void) {
    func_001778A0(1);
    D_004D2A70 = 1;
    D_004D2A60 = 1;
}

// D_002B9664 = 1, D_002B8354 = 0, func_0011D598(6, 1).
void func_00113E68(void) {
    /* the target loads the 1 once into a1 and stores it from there; CSE turns every plain form into two loads */
    register s32 one asm("$5") = 1;

    D_002B9664 = one;
    D_002B8354 = 0;
    func_0011D598(6, one);
}

static const char padding[] = "\0\0"; // TODO likely file split

INCLUDE_ASM("asm/nonmatchings/xblade", PauseMenu_Update);
// s32 PauseMenu_Update(void) {
//     s32 init1;
//     f32 temp_f20;
//     s32 init2;
//     s32 ret;

//     if (((D_002B8330 == 3) || (ret = 1, (D_002B8330 == 5))) && (ret = 1, (D_002B2CC4 == 0))) {
//         if (D_004D2A74 == 0) {
//             switch (D_002B9668) {
//                 case 1:
//                 case 2:
//                     D_004D2A7C = 1;
//                     D_004D2A78 = 0;
//                     D_004D2A80 = 0;
//                     D_004D2AA4 = 0;
//                     temp_f20 = D_002B8340[1];
//                     init1 = D_002B8354;
   
//                     do {
//                         init2 = D_004D2A80;
//                         if (D_004D2AA4 == 0) {
//                             if (D_002C2020[2] & 8) {
//                                 D_002B8354 = 0;
//                                 D_004D2A78 ^= 1;
//                                 D_004D2AA4 = 1;

//                                 do {
//                                     D_004D2A88 = 0;
//                                     D_004D2A84 = 0;
//                                 } while (0);

//                                 switch (init2) {
//                                     case 0:
//                                         if (D_002B9668 == 2) {
//                                             func_00113A10(1);
//                                         } else {
//                                             Sound_PauseNested(1);
//                                         }
//                                         D_004D2A8C = 0x80;
//                                         D_004D2A90 = 0x80;
//                                         D_004D2A94 = 0xFF;
//                                         D_004D2A80 = 1;
//                                         D_004D2A98 = 0;
//                                         D_004D2A9C = 0;
//                                         D_004D2AA0 = 0;
//                                         break;
//                                     case 1:
//                                         D_004D2A80 = 2;
//                                         PauseScreen_ResetColors();
//                                         break;
//                                 }
//                                 D_002B9664 ^= 1;
//                             }
//                         }

//                         if (init2 != 0) {
//                             PauseScreen_AnimateColors(D_004D2A78);
//                             D_002B9664 = 1;
//                             func_001224B8();
//                             Pad_UpdateWithReplay();
//                             if (SoftReset_Check() == 0) {
//                                 break; 
//                             } 
//                             if (SysMessage_WaitWhileActive() != 0) {
//                                 PauseScreen_Show(D_004D2A78);
//                             }
//                             Frame_UpdateTimeStep();
//                         } else {
//                             D_004D2A7C = 0;
//                             D_002B9664 = 0;
//                             D_002B8354 = init1;
//                             D_002B8340[1] = temp_f20;
//                         }
//                     } while (D_004D2A7C != 0);

//                     break;
//                 case 4:
//                     if (D_002BD858 != 0) {
//                         func_00113E38();
//                         D_004D2A64 = D_002BD858;
//                         func_0011C5A8();
//                     }
//                     break;
//                 case 5:
//                     if (D_002BD85C != 0) {
//                         func_00113E38();
//                         PartyMenu_ClearOpenRequest();
//                     }
//                     break;
//                 case 3:
//                     if (D_004D2A70 == 0) {
//                         if (D_002C2028 & 8) {
//                             func_00113E38();
//                         }
//                     }
//                     break;
//             }
//         }

//         switch (D_004D2A70) {
//             case 0:
//                 D_002C1EBC = 0;
//                 break;
//             case 1:
//                 func_00113E18();
//                 ((XGoblin*)TaskSystem_AddTask(190020, &func_00113B78))->unk_02 = 1;
//                 D_004D2A70 = 2;
//                 break;
//             case 2:
//                 func_00113E18();
//                 break;
//             case 3:
//                 func_00113E18();
//                 func_00113A10(1);
//                 switch (D_002B9668) {
//                     case 0:
//                         func_00113E68();
//                         D_002B29C8 = disk_Mgr.unk_1C();
//                         func_00157B90();
//                         func_0020D4C0(1);
//                     case 1:
//                     case 2:
//                         break;
//                     case 3:
//                         func_00113E68();
//                         func_0022B248(1);
//                         break;
//                     case 4:
//                         func_00113E68();
//                         GameState_SaveRoomPositions();
//                         func_00157B90();
//                         func_002277D8(1, D_004D2A64);
//                         break;
//                     case 5:
//                         func_00113E68();
//                         func_00157B90();
//                         func_002279D8(1);
//                         break;
//                 }
//                 D_004D2A70 = 4;
//                 break;
//             case 4:
//                 func_00113E18();
//                 if (D_003ED704 == 0) {
//                     if (D_003F0DD8 != 0) {
//                         D_002B9660 = 1;
//                     }
//                     if (D_002B9668 == 3) {
//                         func_001DDFA0(D_003F1454);
//                     }
//                     func_00113A10(0);
//                     D_004D2A70 = 5;
//                 }
//                 break;
//             case 5:
//                 D_002B8354 = 1;
//                 ((XGoblin*)TaskSystem_AddTask(190021, &func_00113C40))->unk_02 = -1;
//                 func_00113E28();
//                 D_004D2A70 = 6;
//                 break;
//             case 6:
//                 func_00113E28();
//                 break;
//             default:
//                 func_00113E28();
//                 break;
//         }
//         ret = D_002B8350;
//     }
//     return ret;
// }

// D_002B966C = 1.
void func_00114400(void) {
    D_002B966C = 1;
}

// D_002B966C = 0.
void func_00114410(void) {
    D_002B966C = 0;
}

// D_004D2A74 = 1.
void func_00114420(void) {
    D_004D2A74 = 1;
}

// D_004D2A74 = 0.
void func_00114430(void) {
    D_004D2A74 = 0;
}

// Clears the pause state and the party menu open request.
void func_00114440(void) {
    D_004D2A60 = 0;
    D_004D2A70 = 0;
    func_00114420();
    D_002B9664 = 0;
    func_00114410();
    func_0011C5A8();
    PartyMenu_ClearOpenRequest();
}

// include/xblade.h declares this `void func_00114480();`; it is built as returning a value (no tail call).
s32 func_00114480_s32(void) __asm__("func_00114480");

// func_00113660 when D_002BBDE0 == 3 and D_002B9660 != 0.
s32 func_00114480_s32(void) {
    if (D_002BBDE0 == 3 && D_002B9660 != 0) {
        func_00113660();
    }
}

typedef struct {
    /* 0x00 */ u8 unk_00[0xD0];
} XBladeD0;

typedef struct {
    /* 0x00 */ u8 unk_00[0x90];
} XBlade90;

extern XBladeD0 D_002A6C60[64];
extern XBladeD0 D_002AA060[64];
extern XBlade90 D_002AD460[2][64];
extern XBlade90 D_002B1C60[2][64];
s32 func_00108A60(s32 idx, s32 type, void* arg2, void* arg3, void* arg4);

// Resets the 64 model slots of types 1 and 5 (func_00108A60) and the slot counters.
void func_001144C8(void) {
    s32 i;

    D_004D2AAC = 0;
    D_004D2AB0 = 0;
    for (i = 0; i < 64; i++) {
        func_00108A60(i, 1, &D_002A6C60[i], &D_002AD460[0][i], &D_002AD460[1][i]);
        func_00108A60(i, 5, &D_002AA060[i], &D_002B1C60[0][i], &D_002B1C60[1][i]);
    }
}

// func_001089D0 on the data at +unk_18 when the header version unk_00 >= 2.
s32 func_001145B0(XBladeHdr* arg0) {
    s32* offset = &arg0->unk_18;

    if (arg0->unk_00 >= 2) {
        func_001089D0((u8*)arg0 + *offset);
    }
}

// Registers model arg1 (data at +unk_20) in the next type-5 slot (func_00108FD0).
s32 func_001145E8(s32 arg0, XBladeHdr* arg1, s32 arg2, s32 arg3) {
    func_00108FD0(D_004D2AB0++, arg2, arg0, (u8*)arg1 + arg1->unk_20, arg3);
    return 1;
}

typedef struct {
    /* 0x00 */ f32* verts;
    /* 0x04 */ void* hdr;
    /* 0x08 */ char unk_08[0x8];
    /* 0x10 */ sceVu0FMATRIX m;
    /* 0x50 */ char unk_50[0x30];
    /* 0x80 */ sceVu0FVECTOR v[8];
    /* 0x100 */ char unk_100[0x10];
} XBladeBox; // size = 0x110

extern void* D_004D9368; // XBladeBox*
#ifndef VERSION_FM
extern u8 D_002BD140[];
#endif

// Transforms the model's eight bounding box corners by arg0 and registers it in the next slot (func_00108DF8) when func_0024EDF0 says it is visible.
s32 func_00114638(sceVu0FVECTOR* m, u8* mdl, s32 id, s32 arg3) {
    XBladeBox* w;
    s32 ret;

    w = (XBladeBox*)func_00122048(0x110, 0x80);
    {
        s32* hp = (s32*)(mdl + 0x18);
        s32 o = *hp;
        D_004D9368 = w;
        w->hdr = hp;
        w->verts = (f32*)(mdl + o);
    }
    ret = 0;
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[0], m, ((XBladeBox*)D_004D9368)->verts + 0);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[1], m, ((XBladeBox*)D_004D9368)->verts + 4);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[2], m, ((XBladeBox*)D_004D9368)->verts + 8);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[3], m, ((XBladeBox*)D_004D9368)->verts + 12);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[4], m, ((XBladeBox*)D_004D9368)->verts + 16);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[5], m, ((XBladeBox*)D_004D9368)->verts + 20);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[6], m, ((XBladeBox*)D_004D9368)->verts + 24);
    sceVu0ApplyMatrix(((XBladeBox*)D_004D9368)->v[7], m, ((XBladeBox*)D_004D9368)->verts + 28);
    sceVu0MulMatrix(((XBladeBox*)D_004D9368)->m, D_002B84F0, D_00297850);
    if (func_0024EDF0(((XBladeBox*)D_004D9368)->m, ((XBladeBox*)D_004D9368)->v) == 0) {
        if (id == 40000) {
            func_00106A08(&D_002BD140, 40000);
        }
        func_00108DF8(D_004D2AAC++, id, m, ((XBladeBox*)D_004D9368)->verts, arg3);
        ret = 1;
    }
    func_001220B8(D_004D9368);
    return ret;
}

// Clears the slot counters D_004D2AAC / D_004D2AB0.
void func_00114800(void) {
    D_004D2AAC = 0;
    D_004D2AB0 = 0;
}

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void* unk_10;
} XBladeTask;

typedef struct {
    /* 0x00 */ s32 unk_00[4];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ void* unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20[4];
    /* 0x30 */ s32 unk_30[4];
    /* 0x40 */ s32 unk_40[4];
} XBladePkt; // size = 0x50

typedef struct {
    /* 0x00 */ s32 (*unk_00)[4];
    /* 0x04 */ u8 unk_04[0xC];
} XBlade3044D8; // size = 0x10

// Not a real symbol: func_00114B50 below changes its code with the identifiers declared before this point (cse hashes
// symbol-name pointers, rule F1); since func_00113E68 matched it needs one more here.
extern s32 xblade_cse_pad;
extern XBladePkt D_004D9380[2];
extern XBladePkt D_004D9420[][2];
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} XBladeMatTag;

typedef struct {
    /* 0x00 */ XBladeMatTag tag;
    /* 0x08 */ s32 m[2][4][4];
    /* 0x88 */ s32 unk_88[2];
} XBladeMatEnt; // size = 0x90

extern XBladeMatEnt D_004DBC20[2][64];
extern XBladeMatTag D_0048BFD0;

extern XBladePkt D_0048C630;
extern XBladePkt D_0048C690;
extern s32 D_00486430[][4];
extern s32 D_0046BE90[4];
extern s32 D_00486300[4];

// Fills two packets from templates D_0048C630 / D_0048C690, pointing at matrix slot idx (or the template's for -1).
void func_00114818(XBladePkt* pkt, s32 idx, s32 n) {
    s32 k;

    if (idx == -1) {
        pkt[0].unk_14 = D_0048C630.unk_14;
        pkt[1].unk_14 = D_0048C690.unk_14;
    } else {
        pkt[0].unk_14 = &D_004DBC20[0][idx];
        pkt[1].unk_14 = &D_004DBC20[1][idx];
    }
    pkt[0].unk_10 = D_0048C630.unk_10;
    pkt[0].unk_18 = D_0048C630.unk_18;
    pkt[0].unk_1C = D_0048C630.unk_1C;
    pkt[1].unk_10 = D_0048C690.unk_10;
    pkt[1].unk_18 = D_0048C690.unk_18;
    pkt[1].unk_1C = D_0048C690.unk_1C;
    pkt[0].unk_20[0] = D_0048C630.unk_20[0];
    pkt[0].unk_20[1] = D_0048C630.unk_20[1];
    pkt[0].unk_20[2] = D_0048C630.unk_20[2];
    pkt[0].unk_20[3] = D_0048C630.unk_20[3];
    pkt[1].unk_20[0] = D_0048C690.unk_20[0];
    pkt[1].unk_20[1] = D_0048C690.unk_20[1];
    pkt[1].unk_20[2] = D_0048C690.unk_20[2];
    pkt[1].unk_20[3] = D_0048C690.unk_20[3];
    for (k = 0; k < 2; k++) {
        pkt[k].unk_00[0] = D_00486430[n][0];
        pkt[k].unk_00[1] = D_00486430[n][1];
        pkt[k].unk_00[2] = D_00486430[n][2];
        pkt[k].unk_00[3] = D_00486430[n][3];
        pkt[k].unk_40[0] = D_0046BE90[0];
        pkt[k].unk_40[1] = D_0046BE90[1];
        pkt[k].unk_40[2] = D_0046BE90[2];
        pkt[k].unk_40[3] = D_0046BE90[3];
        pkt[k].unk_30[0] = D_00486300[0];
        pkt[k].unk_30[1] = D_00486300[1];
        pkt[k].unk_30[2] = D_00486300[2];
        pkt[k].unk_30[3] = D_00486300[3];
    }
}

// Two 4x4 matrices per entry (copied as words), [2 buffers][64 entries]; D_004DBC20 holds a header 8 bytes before.
extern s32 D_00351BD0;
extern s32 D_004DBC28[][64][36];
extern s32 D_002BC170[4][4];

// Copies matrix arg1 and D_002BC170 into matrix slot idx of buffer D_00351BD0.
void func_001149B0(s32 idx, s32 src[4][4]) {
    s32 i, j, k = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            D_004DBC28[D_00351BD0][idx][k] = src[i][j];
            D_004DBC28[D_00351BD0][idx][k + 16] = D_002BC170[i][j];
            k++;
        }
    }
}

// Initialises the 64 matrix slot tags and their packets.
void func_00114A50(void) {
    s32 i, j;

    for (i = 0; i < 64; i++) {
        for (j = 0; j < 2; j++) {
            D_004DBC20[j][i].tag.unk_00 = D_0048BFD0.unk_00;
            D_004DBC20[j][i].tag.unk_04 = D_0048BFD0.unk_04;
        }
    }
    func_00114818(D_004D9380, -1, 2);
    for (j = 0; j < 64; j++) {
        func_00114818(D_004D9420[j], j, 2);
    }
}

// func_00117588(arg0) for arg1 == -1, else func_0011AED0(arg1, arg0).
void func_00114B18(f32* arg0, s32 arg1) {
    if (arg1 == -1) {
        func_00117588(arg0);
        return;
    }
    func_0011AED0(arg1, arg0);
}

extern XBlade3044D8 D_003044D8[];
s32 func_00108D90(XBladeTask*);
XBladeTask* func_0015ED80(s32 arg0, s32 (*arg1)(XBladeTask*));

// Adds a func_00108D90 task with the packet for slot idx (or the default for -1).
void func_00114B50(s32 arg0, s32 idx) {
    if (idx == -1) {
        func_0015ED80(arg0, func_00108D90)->unk_10 = &D_004D9380[D_00351BD0];
    } else {
        func_001149B0(idx, D_003044D8[idx].unk_00);
        func_0015ED80(arg0, func_00108D90)->unk_10 = &D_004D9420[idx][D_00351BD0];
    }
}

// func_00104AA8 for arg0 == -1, else func_0011A648.
s32 func_00114C18(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        return func_00104AA8(arg1, arg2);
    }
    return func_0011A648(arg0, arg1, arg2);
}

// func_00104AA8 for arg0 == -1, else func_0011A7F8.
s32 func_00114C58(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        return func_00104AA8(arg1, arg2);
    }
    return func_0011A7F8(arg0, arg1, arg2);
}

// func_00104CF8 for arg0 == -1, else func_0011A758.
void func_00114C98(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        func_00104CF8(arg1, arg2);
        return;
    }
    func_0011A758(arg0, arg1, arg2);
}
