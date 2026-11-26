/**
 * Start-up and the main loop: system initialisation, the fade task list, game mode requests, the soft reset check,
 * and screen captures (frame buffer stored to RAM or to the overlay area 0xF20000, then drawn back for cross fades).
 */
#include "common_funcs.h"

#include "xlamp.h"
#include "xblade.h"
#include "xnoodle.h"
#include "xtailor.h"
#include "xpeanut.h"
#include "disk.h"
#include "io.h"

#include "libgraph.h"

#ifdef VERSION_FM
#include "libdma.h"

// labels inside the arrays below, kept for the code (and other files) that use them by name
#define DATA_LABEL(name, base, off) __asm__(".globl " #name "\n" #name " = " #base " + " #off)

// .data (0x002B6460-0x002B6780)
char D_002B6460[20] = "host:./kingdom.cnf";
u32 D_002B29C4 = 0;
char* D_002B6478 = NULL;
s32 D_002B29CC = 0;
s32 D_002B29D0 = 0;
s32 D_002B6484 = 0;
// GIF packets and the DMA ref tags that send them (func_00106948)
u64 D_002B6490[42] __attribute__((aligned(16))) = {
    0x6000000000000001ULL, 0xEEEEEE,
    0x0, 0x3F,
    0x8008000664021A00ULL, 0x6,
    0x131000070ULL, 0x4E,
    0x44, 0x42,
    0x30000, 0x47,
    0x0, 0x14,
    0x6420000000000001ULL, 0x535310,
    0x116, 0x140808080ULL,
    0x0, 0xFFFFFFFE73F87000ULL,
    0x18002000, 0xFFFFFFFE8BF89000ULL,
    0x3000000000000001ULL, 0xEEE,
    0x8008000264120E00ULL, 0x6,
    0x44, 0x42,
    0x80, 0x3B,
    0x6420000000000001ULL, 0x535310,
    0x156, 0x140808080ULL,
    0x0, 0xFFFFFFFE73F87000ULL,
    0x18002000, 0xFFFFFFFE8BF89000ULL,
    0x1000000000008001ULL, 0xE,
    0x31000070, 0x4E,
};
sceDmaTag D_002B65E0 = {21, 0, 0, (sceDmaTag*)D_002B6490};
u64 D_002B65F0[24] = {
    0x5000000000000001ULL, 0xEEEEE,
    0x0, 0x3F,
    0x8008000664120E00ULL, 0x6,
    0x131000070ULL, 0x4E,
    0x44, 0x42,
    0x30000, 0x47,
    0x6420000000000001ULL, 0x535310,
    0x116,
    0x180808080ULL, 0x0,
    0x173F86FF8ULL, 0x18002000,
    0x18BF88FF8ULL, 0x1000000000008001ULL,
    0xE, 0x31000070,
    0x4E,
};
DATA_LABEL(D_002B2BB8, D_002B65F0, 0x78);
sceDmaTag D_002B2C00 = {12, 0, 0, (sceDmaTag*)D_002B65F0};
u64 D_002B66C0[20] = {
    0x5000000000000001ULL, 0xEEEEE,
    0x401B0, 0x4C,
    0x30000, 0x47,
    0x60, 0x14,
    0x5, 0x8,
    0x8000000664020000ULL, 0x6,
    0x6400000000008001ULL, 0x535310,
    0x116, 0x180808080ULL,
    0x0, 0xFFFFFFFE74007000ULL,
    0x1C002000, 0xFFFFFFFE80008000ULL,
};
sceDmaTag D_002B2CB0 = {10, 0, 0, (sceDmaTag*)D_002B66C0};
s32 D_002B2CC0 = 0;
s32 D_002B2CC4 = 0;
u_long128* D_002B2CC8 = NULL;
u_long128* D_002B2CCC = NULL;
#else
extern s32 D_002B2C00;
extern s32 D_002B2CB0;
#endif

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
} XArcade;

extern char D_002B29B0[]; // "host:./kingdom.cnf"
extern char* D_002B29C8;
extern s64 D_002B2BB8;
extern s32 D_002B2CC0;
extern s32 D_002B2CC4;
extern u_long128* D_002B2CC8;
extern u_long128* D_002B2CCC;
extern s32 fadeScreenColor[4];
extern s32** D_002B8690;
extern s32** D_002B8694;
extern sceGsLoadImage D_002B8700;
extern sceGsLoadImage D_002B8760;
extern s32 D_002B8870;
extern s32 fadeTaskList;
extern s32 D_002B8C8C;

extern s32 D_00358BE0;
extern s32 D_002B9328;
extern vs32 D_00495160;
extern vs32 D_00495164;

extern XArcade D_0048EC00;
extern s32 D_0048EC08;

extern void func_F20000(s32, s32);
extern void func_00100240(); // in xbeginning
extern void func_00101560(void); // in xporcupine
void* Screen_Capture(void);
extern void Screen_RestoreCapture();
extern u_long128* func_00121C98(s32, u_long128**);
extern void func_001600B8();
extern void func_001C20B8();
extern void func_00233968();
extern void SaTask_Init();

#ifdef VERSION_FM
extern u32 D_002BBDE4;
extern char D_002B6460[];
extern DiskManager D_0046A688; // disk_Mgr
extern char* D_002B6478;
extern s32 D_002BC73C;
void fm_func_00110068(void);
KingdomFile* func_00120190(char* filename); // cdvd_FindFile

// First set-up: display, work buffers, IOP modules, disc size of kingdom.img, play time 0, sound, pads.
void Graphics_Initialize(void) {
    KingdomFile* file;

    D_002BBDE4 = 7;
    fm_func_00110068();
    IoThread_Init();
    GameData_BindBuffer();
    WorkBuffers_Clear(-1);
    Iop_LoadModules(D_002B6460, "host:./kingdom.log");

    file = func_00120190("kingdom.img");
    if (file != NULL) {
        D_0046A688.unk_18(file->length);
    } else {
        D_0046A688.unk_18(0);
    }
    D_002B6478 = D_0046A688.unk_1C();
    PlayTime_SetFrames(0);
    D_002BC73C = 0;
    SoundRpc_Initialize(NULL);
    Pad_Reset();
}
#else
void Graphics_Initialize(void) {
    KingdomFile* file;

    Gs_SetDefaultDrawEnv();
    VSync_InstallCallback();
    IoThread_Init();
    GameData_BindBuffer();
    WorkBuffers_Clear(-1);
    Iop_LoadModules(D_002B29B0, "host:./kingdom.log");

    file = cdvd_FindFile("kingdom.img");
    if (file != NULL) {
        disk_Mgr.unk_18(file->length);
    } else {
        disk_Mgr.unk_18(0);
    }
    D_002B29C8 = disk_Mgr.unk_1C();
    PlayTime_SetFrames(0);
    D_002B8C8C = 0;
    SoundRpc_Initialize(NULL);
    Pad_Reset();
}
#endif

// Task: updates the fade task list (fadeTaskList).
s32 FadeTaskList_Task(void) {
    TaskList_UpdateMatching(&fadeTaskList, 0);
    return 0;
}

// Initialises the game systems (task system, game state and data, allset / allarea tables, ...) before the main loop.
INCLUDE_ASM("asm/nonmatchings/xarcade", Game_InitSystems);
void Game_InitSystems();

// Resets the fades, sets up fadeTaskList and adds FadeTaskList_Task.
void* Fade_InitSystem(void) {
    func_00110190();
    func_00176E30();
    func_00176E98();
    D_00358BE0 = 1;
    TaskList_Init(&fadeTaskList, &D_002B8870, 0x20, 0x20);
    return TaskSystem_AddTask(190050, FadeTaskList_Task);
}

// Requests game mode arg0 (D_00495164, state D_00495160 = 2) and starts capturing the screen.
void* GameMode_Request(s32 arg0) {
    D_00495164 = arg0;
    D_00495160 = 2;
    return Screen_Capture();
}

#ifdef VERSION_FM
// Clears the pending entrance flag, func_00101560, returns func_00155ED8(0, 0x40) (FM only).
s32 fm_func_00109588(void) {
    D_002B9328 = 0;
    func_00101560();
    return func_00155ED8(0, 0x40);
}
#endif

#ifdef VERSION_FM
extern s32** D_002BC140;
extern s32** D_002BC144;
extern volatile s32 D_002BBDE0;
void func_00122130(void);
void func_0015F018(void);
void func_00236F18(void);

// Resets several systems (func_00122130, func_0015F018, scripts, SaTask_Init) and keeps two camera matrix pointers.
void func_001093D8(void) {
    func_00122130();
    func_0015F018();
    func_00100240();
    func_001C20B8();
    func_00236F18();
    SaTask_Init();
    D_002BC140 = viewMatrix;
    D_002BC144 = screenMatrix;
    D_002BBDE0 = 3;
    D_00495160 = 0;
}
#else
void func_001093D8(void) {
    func_00122518();
    func_001600B8();
    func_00100240();
    func_001C20B8();
    func_00233968();
    SaTask_Init();
    D_002B8690 = viewMatrix;
    D_002B8694 = screenMatrix;
}
#endif

// Invalidates the instruction cache and calls the overlay at 0xF20000 (command 0).
void Overlay_Run(void) {
    FlushCache(INVALIDATE_ICACHE);
    func_F20000(0, 0);
}

extern s32 D_002B6484;
extern u32 D_002BCA00_w[] __asm__("D_002BCA00");
extern s32 D_002BBE08;
extern s32 D_002B9030;
s32 func_0010BF98_s(void) __asm__("IoThread_IsBusy");
s32 func_00110F68_s(void) __asm__("func_00110F68");
s32 func_001EE090(void);
void func_00239488(void);
void func_00178140(s32);
void func_001220D0(void);
s32 func_0010FB90_s(void) __asm__("func_0010FB90");

// When the pad combination (all shoulder buttons with start and select, probably) is held and nothing is loading, stops sound, any movie and the game and returns D_002BBE08 (cleared: reset).
s32 SoftReset_Check(void) {


    if (D_002B6484 == 0 && (*(u64 *)D_002BCA00_w & 0xF0900000000) == 0xF0900000000 && (D_002BCA00_w[2] & 0xF09) != 0 &&
        func_0010BF98_s() == 0 && func_001EE090() == 0) {
        *(volatile s32 *)&D_002BBE08 = 0;
        SoundRpc_Initialize(1);
        func_00114420();
        func_00239488();
        func_00178140(0);
        func_0010FB90_s();
        if (D_002B9030 != 0) {
            do {
                func_001220D0();
                func_00110FA8();
                Frame_UpdateTimeStep();
            } while (func_00110F68_s() != 1);
            Movie_Finish();
        }
        Frame_UpdateTimeStep();
        func_0010FDB8(0);
    }
    return *(volatile s32 *)&D_002BBE08;
}

// The main loop, probably: initialises, plays the opening movies, then each frame runs the pause, system message and task system updates.
INCLUDE_ASM("asm/nonmatchings/xarcade", Game_MainLoop);

// Uploads the two halves of a screen image stored at 0xF20000 back to VRAM (0xE00, 0x1400).
void Screen_RestoreFromOverlayArea(void) {
    sceGsSetDefLoadImage(&D_002B8700, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, &func_F20000);
    sceGsSetDefLoadImage(&D_002B8760, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8760, &func_F20000 + 0x48000);
}

// Task: stores the frame buffer at 0x1A00 (512 x 384) to 0xF20000.
s32 Screen_CaptureToOverlayAreaTask(void) {
    sceGsStoreImage img;

    sceGsSetDefStoreImage(&img, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecStoreImage(&img, func_F20000); // TODO look into - F20000 is probably an overlay location
    return 4;
}

// Adds Screen_CaptureToOverlayAreaTask.
void* Screen_CaptureToOverlayArea(void) {
    return TaskSystem_AddTask(190000, Screen_CaptureToOverlayAreaTask);
}

#ifdef VERSION_FM
extern f32 D_00495184;
extern f32 D_00495168;
extern f32 D_0049516C;
extern f32 D_002B8344;
extern u64 D_002B6490[];
void Screen_RestoreFromOverlayArea(void);

// Task: draws the captured screen fading out over the time D_00495184 (FM).
s32 Screen_CrossFadeTask(void) {
    f32 a;
    f32 c;
    switch (D_0048EC08) {
    case 0:
        D_0048EC08 = 1;
        D_00495168 = D_00495184;
        D_0049516C = 128.0f / D_00495184;
    case 1:
        break;
    default:
        return 0;
    }
    if (!(D_00495184 <= 0.0f)) {
        Screen_RestoreFromOverlayArea();
        c = (D_00495168 - D_00495184) * D_0049516C;
        a = D_00495184 * D_0049516C;
        D_002B6490[33] = (u64)(s32)a << 24 | 0x100808080;
        D_002B6490[17] = (u64)(s32)c << 24 | 0x100808080;
        func_00106948(&D_002B65E0);
        D_00495184 -= D_002B8344;
        return 0;
    }
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xarcade", Screen_CrossFadeTask);
#endif
s32 Screen_CrossFadeTask();

// Starts Screen_CrossFadeTask (+0x04 of D_0048EC00 = arg0 * 2).
void* Screen_StartCrossFade(s32 arg0) {
    D_0048EC00.unk_04 = arg0 << 1;
    D_0048EC08 = 0;
    return TaskSystem_AddTask(190000, Screen_CrossFadeTask);
}

// Uploads the screen captured by Screen_CaptureTask (D_002B2CCC) back to VRAM.
void Screen_RestoreCapture(void) {
    sceGsSetDefLoadImage(&D_002B8700, 0xE00, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, D_002B2CCC);
    sceGsSetDefLoadImage(&D_002B8760, 0x1400, 8, 1, 0, 0, 0x200, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8760, D_002B2CCC + 0x4800);
}

// Task: stores the frame buffer at 0x1A00 to a new buffer D_002B2CCC.
s32 Screen_CaptureTask(void) {
    sceGsStoreImage img;

    sceGsSetDefStoreImage(&img, 0x1A00, 8, 1, 0, 0, 0x200, 0x180);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    D_002B2CCC = func_00155ED8(62, 2);
    sceGsExecStoreImage(&img, D_002B2CCC);
    return 4;
}

// Marks the capture (D_002B2CC4), starts a fade when the screen is not at full colour, adds Screen_CaptureTask.
void* Screen_Capture(void) {
    D_002B2CC4 = 1;
    if (fadeScreenColor[0] != 0x80) {
        func_001037C8(1);
    }
    return TaskSystem_AddTask(190000, Screen_CaptureTask);
}

#ifdef VERSION_FM
extern f32 D_00495170;
extern s32 D_00495174;
extern f32 D_00495178;
extern f32 D_002B8344;
void Fade_ClearScreenColor(void);

// Task: draws the captured screen darkening over 64 frames, then clears the screen colour (FM).
s32 Screen_FadeCaptureTask(void) {
    s32 c;
    switch (D_0048EC00.unk_00) {
    case 0:
        D_00495170 = 64.0f;
        D_00495174 = 0x80;
        D_00495178 = 2.0f;
        D_0048EC00.unk_00 = 1;
    case 1:
        break;
    default:
        return 0;
    }
    if (!(D_00495170 <= 0.0f)) {
        Screen_RestoreCapture();
        c = D_00495174;
        D_002B2BB8 = (u64)c | ((u64)c << 8) | ((u64)c << 16) | ((u64)0x80 << 24) | ((u64)1 << 32);
        func_00106948(&D_002B2C00);
        D_00495170 -= D_002B8344;
        D_00495174 = D_00495170 * D_00495178;
        return 0;
    }
    D_002B2CC4 = 0;
    Fade_ClearScreenColor();
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xarcade", Screen_FadeCaptureTask);
#endif
s32 Screen_FadeCaptureTask();

#ifdef VERSION_FM
extern f32 D_0049517C;
extern f32 D_002B8344;
void Fade_StartOverlayIn(s32);

// Task: starts an overlay fade in and draws the captured screen for 64 frames (FM).
s32 Screen_ShowCaptureTask(void) {
    switch (D_0048EC00.unk_00) {
    case 0:
        Fade_StartOverlayIn(0x20);
        D_0048EC00.unk_00++;
        D_0049517C = 64.0f;
    case 1:
        break;
    default:
        return 0;
    }
    if (!(D_0049517C <= 0.0f)) {
        Screen_RestoreCapture();
        D_002B2BB8 = 0x180808080;
        func_00106948(&D_002B2C00);
        D_0049517C -= D_002B8344;
        return 0;
    }
    D_002B2CC4 = 0;
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xarcade", Screen_ShowCaptureTask);
#endif
s32 Screen_ShowCaptureTask();

// Adds Screen_ShowCaptureTask when D_002B2CC0 is set, else Screen_FadeCaptureTask.
void* Screen_StartCaptureFade(void) {
    D_0048EC00.unk_00 = 0;
    if (D_002B2CC0 != 0) {
        return TaskSystem_AddTask(190000, Screen_ShowCaptureTask);
    }
    return TaskSystem_AddTask(190000, Screen_FadeCaptureTask);
}

// Task: draws the captured screen every frame.
s32 Screen_DrawCaptureTask(void) {
    Screen_RestoreCapture();
    D_002B2BB8 = 0x180808080;
    func_00106948(&D_002B2C00);
    return 0;
}

// Adds Screen_DrawCaptureTask.
void* Screen_DrawCapture(void) {
    return TaskSystem_AddTask(190000, Screen_DrawCaptureTask);
}

// Stores the 256 x 192 VRAM area at 0x3600 in a new buffer D_002B2CC8.
void Screen_SaveRegion(void) {
    sceGsStoreImage img;

    func_00106948(&D_002B2CB0);
    sceGsSetDefStoreImage(&img, 0x3600, 4, 1, 0, 0, 0x100, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    D_002B2CC8 = func_00121C98(0x24000, &D_002B2CC8);
    sceGsExecStoreImage(&img, D_002B2CC8);
}

// Uploads the area saved by Screen_SaveRegion back to 0x3600.
void Screen_LoadRegion(void) {
    sceGsSetDefLoadImage(&D_002B8700, 0x3600, 4, 1, 0, 0, 0x100, 0xC0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(&D_002B8700, D_002B2CC8);
}
