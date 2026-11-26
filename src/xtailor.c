/**
 * Frame and display basics: system messages (probably controller / disc warnings) drawn on their own display while
 * the game waits, allset.set / allarea.nam tables, display environment (D_004D2610), the VSync callback with the play
 * time counter and the per-frame time step, camera matrix copies, and the movie player overlay (dkmovie.x at 0xF20000,
 * driven by command numbers).
 */
#include "common.h"
#include "xtailor.h"
#include "xblade.h"
#include "xpeanut.h"

#include "libgraph.h"
#include "libvu0.h"
#include "sdk/libcdvd.h"
#include "libdma.h"

#ifdef VERSION_FM
// .data (0x002BBBB0-0x002BCB60)
typedef struct {
    u64 unk_00[14];
} XTailorSave;

// labels inside the arrays below, kept for the code (and other files) that use them by name
#define DATA_LABEL(name, base, off) __asm__(".globl " #name "\n" #name " = " #base " + " #off)

// GIF packets and the DMA ref tags that send them (func_00106948)
u64 D_002BBBB0[14] = {
    0x3000000000000001ULL, 0xEEE,
    0x801B0, 0x4C,
    0x131000070ULL, 0x4E,
    0x30000, 0x47,
    0x4400000000008001ULL, 0x5510,
    0x6, 0x100000000ULL,
    0x174007000ULL, 0x17C009000ULL,
};
sceDmaTag D_002B8170 = {7, 0, 0, (sceDmaTag*)D_002BBBB0};
u64 D_002BBC30[18] = {
    0x1000000000000001ULL, 0xE,
    0x30000, 0x47,
    0x4400000000008003ULL, 0x5510,
    0x6, 0x170000000ULL,
    0x174007000ULL, 0x17C009000ULL,
    0x6, 0x180323296ULL,
    0x174007000ULL, 0x174109000ULL,
    0x6, 0x180323296ULL,
    0x17BF07000ULL, 0x17C009000ULL,
};
sceDmaTag D_002BBCC0 = {9, 0, 0, (sceDmaTag*)D_002BBC30};
u64 D_002BBCD0[4] = {
    0x1000000000008001ULL, 0xE,
    0xFFFFFF000801B0ULL, 0x4C,
};
sceDmaTag D_002B8240 = {2, 0, 0, (sceDmaTag*)D_002BBCD0};
u64 D_002BBD00[6] = {
    0x2000000000008001ULL, 0xEE,
    0x800D0, 0x4C,
    0x31000070, 0x4E,
};
sceDmaTag D_002B8280 = {3, 0, 0, (sceDmaTag*)D_002BBD00};

s32 D_002BBD40 = 0;
s32 D_002BBD48[18] = {0};
s32 D_002BBD90[20] = {0};
volatile s32 D_002BBDE0 = 0;
u32 D_002BBDE4 = 0;
s32 D_002BBDE8 = 0;
f32 D_002BBDEC = 0.0f;
volatile s32 D_002BBDF0 = 0;
volatile u32 D_002BBDF4 = 0;
volatile s32 D_002B8340 = 0;
f32 D_002B8344 = 0.0f;
f32 D_002B8348 = 0.0f;
s32 D_002B834C = 0;
s32 D_002BBE08 = 0;
s32 D_002B8354 = 0;
s32 D_002BBE10 = 0;
s32 D_002BBE14 = 0;
s32 D_002BBE18 = 0;
s32 D_002B8364 = 0;
sceVu0FMATRIX D_002B8370 = {0};
sceVu0FMATRIX D_002B83B0 = {0};
sceVu0FMATRIX D_002B83F0 = {0};
sceVu0FMATRIX D_002B8430 = {0};
sceVu0FMATRIX D_002B8470 = {0};
sceVu0FMATRIX D_002B84B0 = {0};
sceVu0FMATRIX D_002B84F0 = {0};
sceVu0FMATRIX D_002B8530 = {0};
sceVu0FMATRIX D_002B8570 = {0};
s32 D_002BC060[4] = {0};
s32 fadeScreenColor[4] = {0};
s32 D_002BC080[4] = {0};
DATA_LABEL(D_002BC08C, D_002BC080, 12);
s32 D_002BC090 = 0;
s32 D_002BC094 = 0;
f32 D_002BC098 = 0.0f;
s32 D_002BC09C = 0;
s32 D_002BC0A0 = 0;
s32 D_002BC0A4 = 0;
u32 D_002B85F8 = 0;
s32 D_002BC0B0[4] = {0};
DATA_LABEL(fadeOverlayAlpha, D_002BC0B0, 12);
s32 D_002BC0C0[12] = {0};
f32 D_002BC0F0[12] = {0};
f32 D_002BC120 = 0.0f;
f32 D_002BC124 = 0.0f;
s32 curWorldNo = 0;
s32 D_002BC12C = 0;
s32 curRoomNo = 0;
s32 D_002B8684 = 0;
s32 D_002B8688 = 0;
s32 D_002B868C = 0;
s32* D_002BC140 = NULL;
s32* D_002BC144 = NULL;
s32 D_002B8698[10] = {0};
s32 D_002BC170[2][4] = {{0}};
sceVu0FVECTOR D_002BC190 = {0};
sceVu0FVECTOR D_002BC1A0 = {0};
sceGsLoadImage D_002B8700 = {{0}};
sceGsLoadImage D_002B8760 = {{0}};
u8 D_002BC270[0xB0] = {0};
u32 D_002B8870[256] = {0};
s32 fadeTaskList[4] = {0};
s32 D_002BC730 = 0;
s32 D_002B8C84 = 0;
s32 D_002B8C88 = 0;
s32 D_002BC73C = 0;
s32 D_002B8C90 = 0;
s32 D_002B8C94 = 0;
// GS register addresses (D_002BC750/D_002BC7C0) and values (D_002BC830) that func_0010FEC0 copies into D_004D8EF0
u64 D_002BC750[13] __attribute__((aligned(16))) = {
    0x4C, 0x4E,
    0x18, 0x40,
    0x47, 0x42,
    0x4A, 0x6,
    0x14, 0x16,
    0x34, 0x36,
    0x8,
};
u64 D_002BC7C0[13] __attribute__((aligned(16))) = {
    0x4D, 0x4F,
    0x19, 0x41,
    0x48, 0x43,
    0x4B, 0x7,
    0x15, 0x17,
    0x35, 0x37,
    0x9,
};
u64 D_002BC830[13] __attribute__((aligned(16))) = {
    0x800D0, 0x31000070,
    0x740000007000ULL, 0x17F000001FF0000ULL,
    0x5000D, 0x44,
    0x0, 0x20000045DD308002ULL,
    0x60, 0x2000000001300000ULL,
    0x0, 0x0,
    0x5,
};
u64 D_002BC8A0[28] __attribute__((aligned(16))) = {
    0x5000000000000001ULL, 0xEEEEE,
    0x131000070ULL, 0x4E,
    0x1080000, 0x4C,
    0x44, 0x42,
    0x30000, 0x47,
    0x1BF000001FF0000ULL, 0x40,
    0x4400000000000001ULL, 0x5510,
    0x6,
    0x180000000ULL, 0x174007000ULL,
    0x190009000ULL, 0x4000000000008001ULL,
    0xEEEE, 0x5000D,
    0x47, 0x800D0,
    0x4C, 0x17F000001FF0000ULL,
    0x40, 0x31000070,
    0x4E,
};
DATA_LABEL(D_002BC918, D_002BC8A0, 0x78);
sceDmaTag D_002BC980 = {14, 0, 0, (sceDmaTag*)D_002BC8A0};
u64 D_002BC990[4] = {
    0x5000000000008001ULL, 0xEEEEE,
    0x0, 0x3F,
};
u64 D_002BC9B0[8] = {
    0x807010, 0x3D,
    0x60, 0x15,
    0x44, 0x43,
    0x5000D, 0x48,
};
sceDmaTag D_002BC9F0 = {6, 0, 0, (sceDmaTag*)D_002BC990};
XTailorSave D_002BCA00[2] = {{{0}}};
DATA_LABEL(D_002BCA70, D_002BCA00, 0x70);
s32 D_002B9030 = 0;
sceVu0FMATRIX D_002B9040 = {0};
s32 D_002BCB30 = 0;
s32 D_002B9084 = 0;
sceVu0FVECTOR D_002B9090 = {0};
s32 D_002B90A0[3] = {0};
#else
extern s32 D_002BC980;
extern s32 D_002B8170;
extern s32 D_002B8240;
extern s32 D_002B8280;
extern s32 D_002BBCC0;
#endif

extern u64 D_002BC918;

extern s32 D_002BBD48[];
extern s32 D_002BBD90[];

extern s32 D_004D6B20[];

extern s32 D_002A30D0;
extern sceVu0FMATRIX D_002B8370;
extern sceVu0FMATRIX D_002B83B0;
extern sceVu0FMATRIX D_002B83F0;
extern sceVu0FMATRIX D_002B8430;
extern sceVu0FMATRIX D_002B8470;
extern sceVu0FMATRIX D_002B84B0;
extern sceVu0FMATRIX D_002B84F0;
extern sceVu0FMATRIX D_002B8530;
extern sceVu0FMATRIX D_002B8570;
extern s32 fadeScreenColor[4];
extern s32 D_002B8210;
extern s32 curWorldNo;
extern s32 curRoomNo;

extern s32 D_002B9030;
extern s32 D_002B9084;
extern f32 D_002B9090[4];
extern s32 D_002B90A0[3];

extern char D_00486C40[];
extern char D_00486C50[];
extern char D_00486C60[];

extern s32 D_004CF580;
extern s32 D_004CF588;
extern s32 D_004CF58C;
extern s32 D_004CF590;
extern s32 D_004D0590;
extern sceVu0FMATRIX D_004D2590;
extern sceVu0FMATRIX D_004D25D0;
extern sceGsDispEnv D_004D2610;
extern s32 D_004D284C;
extern sceVu0FMATRIX D_004D2850;
extern sceVu0FMATRIX D_004D2890;
extern sceVu0FMATRIX D_004D28D0;
extern sceVu0FMATRIX D_004D2910;
extern sceVu0FMATRIX D_004D2950;
extern s32 D_004D2990;
extern s32 D_004D2994;

extern s32 func_F20000();
void Movie_SetSysMessage(s32);

// Sends GS packet D_002B8170 and waits for the GS.
void func_0010F3D0(void) {
    func_00106948(&D_002B8170);
    sceGsSyncPath(0, 0);
}

// Sends GS packet D_002B8240 and waits for the GS.
void func_0010F3F8(void) {
    func_00106948(&D_002B8240);
    sceGsSyncPath(0, 0);
}

// Sends GS packet D_002B8280 and waits for the GS.
void func_0010F420(void) {
    func_00106948(&D_002B8280);
    sceGsSyncPath(0, 0);
}

#define DISPWIDTH 640

// Sets the display registers for the system message screen (PMODE, DISPFB1 at 0xD8000, DISPLAY1 640 x 128).
void func_0010F448(void) {
    sceGsSyncPath(0, 0);
    DPUT_GS_PMODE(SCE_GS_SET_PMODE(1, 1, 0, 0, 0, 0, 0xFF));
    DPUT_GS_DISPFB1(SCE_GS_SET_DISPFB1(0xD8000 / 2048, 512 / 64, SCE_GS_PSMCT32, 0, 0));
    DPUT_GS_DISPLAY1(SCE_GS_SET_DISPLAY1(0, 160, 4, 0, (DISPWIDTH * 4) - 1, 128 - 1));
}

#ifdef VERSION_FM
extern s32 D_004D5B0C;
void func_001FD100(s32, s32);
void func_001F1ED8(s32, s32, s32, s32, s32);
void func_00207748(s32, s32, s32, s32);
// Draws the system message for the bits of arg0 (4: message 3 or 4 with a choice, 2: message 2, 1: message 1) on its own display, or restores the display for 0; probably the controller / disc warnings.
void SysMessage_Draw(u32 arg0) {
    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        if (arg0 == 0) {
            sceGsSyncPath(0, 0);
            Frame_UpdateTimeStep();
            DPUT_GS_PMODE(0x22);
        } else {
            sceGsSyncPath(0, 0);
            Frame_UpdateTimeStep();
            if (arg0 & 4) {
                func_0010F3D0();
                func_00106948(&D_002BBCC0);
                if (D_004D5B0C == 0) {
                    func_001FD100(76, 11);
                    func_001F1ED8(0x64FFFFFF, 118, 16, func_001F0EF0(3), 15);
                    func_00207748(1, 351, 92, 90);
                } else {
                    func_001FD100(84, 30);
                    func_001F1ED8(0x64FFFFFF, 126, 39, func_001F0EF0(4), 15);
                    func_00207748(1, 351, 70, 90);
                }
                func_0010F3F8();
                func_00106948(&D_002BBCC0);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 2) {
                func_0010F3D0();
                func_00106948(&D_002BBCC0);
                func_001FD100(96, 30);
                func_001F1ED8(0x64FFFFFF, 138, 39, func_001F0EF0(2), 15);
                func_0010F3F8();
                func_00106948(&D_002BBCC0);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 1) {
                func_0010F3D0();
                func_00106948(&D_002BBCC0);
                func_001FD100(84, 30);
                func_001F1ED8(0x64FFFFFF, 126, 39, func_001F0EF0(1), 15);
                func_0010F3F8();
                func_00106948(&D_002BBCC0);
                func_0010F420();
                func_0010F448();
                return;
            }
        }
    }
}
#else
void SysMessage_Draw(u32 arg0) {
    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        if (arg0 == 0) {
            sceGsSyncPath(0, 0);
            Frame_UpdateTimeStep();
            DPUT_GS_PMODE(0x22);
        } else {
            sceGsSyncPath(0, 0);
            Frame_UpdateTimeStep();
            if (arg0 & 4) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                if (D_004CF58C == 0) {
                    func_001FD4C0(76, 11);
                    func_001F2EF8(0x64FFFFFF, 118, 16, func_001F0EF0(3), 15);
                    func_00207640(1, 351, 92, 90);
                } else {
                    func_001FD4C0(84, 30);
                    func_001F2EF8(0x64FFFFFF, 126, 39, func_001F0EF0(4), 15);
                    func_00207640(1, 351, 70, 90);
                }
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 2) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                func_001FD4C0(104, 30);
                func_001F2EF8(0x64FFFFFF, 146, 39, func_001F0EF0(2), 15);
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
            if (arg0 & 1) {
                func_0010F3D0();
                func_00106948(&D_002B8210);
                func_001FD4C0(84, 30);
                func_001F2EF8(0x64FFFFFF, 126, 39, func_001F0EF0(1), 15);
                func_0010F3F8();
                func_00106948(&D_002B8210);
                func_0010F420();
                func_0010F448();
                return;
            }
        }
    }
}
#endif

// Saves D_002C1EB8 in D_004CF580 (state for the first two message bits).
s32 func_0010F6F0(void) {
    D_004CF580 = D_002C1EB8.s32;
}

// Saves D_002C1EB8 in D_004CF588 (state for message bit 2).
void func_0010F708(void) {
    D_004CF588 = D_002C1EB8.s32;
}

// SysMessage_Draw, and passes the bits to the movie player (Movie_SetSysMessage) while a movie runs.
void SysMessage_Show(u32 arg0) {
    SysMessage_Draw(arg0);
    if (Movie_IsRunning() != 0) {
        Movie_SetSysMessage(arg0);
    }
}

#ifdef VERSION_FM
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} XTailor5AD0;
extern volatile XTailor5AD0 D_002C5AD0_t __asm__("D_002C5AD0");
extern s32 D_002BBD40;
extern s32 D_002C1EB8_w __asm__("D_002C1EB8");
extern s32 D_002B6484;
extern volatile s32 D_002B9664;
void Sound_PauseNested(s32);
void func_001220D0(void);
void func_0011DE90(void);

static inline u32 xt_bit(u32 x, s32 n) {
    return (x >> n) & 1;
}

// Loops while one of the watched bits of D_002C1EB8 is set (comparing with the states saved before), showing the message, pausing sound and updating the pads; returns whether a message was shown (FM).
s32 SysMessage_WaitWhileActive(void) {
    volatile s32 loop;
    s32 saved;
    u32 mask;
    s32 res;
    s32 started;
    u32 cur;
    u32 a;
    u32 b;
    u32 on1;
    u32 off1;
    u32 on2;
    u32 off2;

    if (D_002BBD40 == 0 && D_002B6484 == 1) {
        D_002C1EB8_w = 0;
        return 0;
    }
    D_004D5B0C = 0;
    loop = 1;
    started = 0;
    res = 0;
    mask = 0;
    saved = D_002B9664;
    do {
        cur = D_002C1EB8.s32;
        a = D_004CF580 ^ cur;
        b = D_004CF588 ^ cur;
        on1 = a & cur;
        off1 = a & ~cur;
        on2 = b & cur;
        off2 = b & ~cur;
        if (xt_bit(on1, 0) == 1) {
            mask |= 1;
            res = 1;
            SysMessage_Show(mask);
        }
        if (xt_bit(off1, 0) == 1) {
            mask &= ~1;
            SysMessage_Show(mask);
        }
        if (xt_bit(on1, 1) == 1) {
            mask |= 2;
            res = 1;
            SysMessage_Show(mask);
        }
        if (xt_bit(off1, 1) == 1) {
            mask &= ~2;
            SysMessage_Show(mask);
        }
        if (xt_bit(on2, 2) == 1) {
            mask |= 4;
            res = 1;
            SysMessage_Show(mask);
        }
        if (xt_bit(off2, 2) == 1) {
            mask &= ~4;
            SysMessage_Show(mask);
        }
        if (started == 0 && mask != 0) {
            started = 1;
            Sound_PauseNested(mask);
        }
        if (started == 1 && mask == 0) {
            Sound_PauseNested(0);
        }
        if (mask != 0) {
            D_002B9664 = 1;
            func_0010FB90();
            func_001220D0();
            func_0010F708();
            if (Movie_IsRunning() != 0) {
                func_00110FA8();
            }
            func_0011DE90();
            Frame_UpdateTimeStep();
            if ((mask & 4) && (D_002C5AD0_t.unk_08 & 0x2000)) {
                func_0011D598(2);
                if (D_004D5B0C == 0) {
                    D_004D5B0C = 1;
                    SysMessage_Show(mask);
                } else {
                    D_002C1EB8.u8 &= 0xFB;
                }
            }
        } else {
            D_002B9664 = 0;
            loop = 0;
        }
    } while (loop);
    D_002B9664 = saved;
    return res;
}
#else
INCLUDE_ASM("asm/nonmatchings/xtailor", SysMessage_WaitWhileActive);
#endif

// Fills the 17 pointer / size pairs D_002BBD48 / D_002BBD90 from the table of offsets at arg0 + 0x10.
void AllSet_SetupTable(s32* arg0) {
    s32* p = arg0 + 4;
    s32 i;

    for (i = 0; i < 17; i++) {
        D_002BBD48[i] = (s32)arg0 + p[0];
        D_002BBD90[i] = p[1];
        p += 2;
    }
}

// Reads "allset.set" and sets up its table.
void AllSet_Load(void) {
    void* src = func_00155ED8(0x34, 0xC);
    s32 size = func_00120438("allset.set", src);
    memcpy(&D_004CF590, src, size);
    AllSet_SetupTable(&D_004CF590);
}

// Reads "allarea.nam" to D_004D0590.
void AreaNames_Load(void) {
    void* src = func_00155ED8(0x34, 0xC);
    s32 size = func_00120438("allarea.nam", src);
    memcpy(&D_004D0590, src, size);
}

// Name data of room arg1 of world arg0 in allarea.nam.
void* AreaNames_Get(s32 arg0, s32 arg1) {
    u8* p = (u8*)&D_004D0590 + D_004D6B20[arg0 * 2];
    s32* q = (s32*)(p + 0x10);

    return p + q[arg1 * 2];
}

// AreaNames_Get for the current world and room.
void* AreaNames_GetCurrent(void) {
    return AreaNames_Get(curWorldNo, curRoomNo);
}

#ifdef VERSION_FM
extern XTailorSave D_002BCA00[2];
extern XTailorSave D_002C5AD0[2];
void Pad_Update(void);
void func_001BA4A8(void);

// Updates the pads; while D_004D2990 is set the pad data is replaced by D_002BCA00 and func_001BA4A8 runs (probably demo playback) (FM).
void func_0010FB90(void) {
    s32 i;

    func_0010F6F0();
    if (D_004D2990) {
        for (i = 0; i < 2; i++) {
            D_002C5AD0[i] = D_002BCA00[i];
        }
    }
    Pad_Update();
    for (i = 0; i < 2; i++) {
        D_002BCA00[i] = D_002C5AD0[i];
    }
    if (D_004D2990 != 0) {
        func_001BA4A8();
    }
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_0010FB90);
#endif

// D_004D2990 = 0.
void func_0010FCD0(void) {
    D_004D2990 = 0;
}

// D_004D2990 = 1.
void func_0010FCE0(void) {
    D_004D2990 = 1;
}

extern f32 D_002BBDEC;
extern volatile u32 D_004D90F0;

// Play time frame limit D_004D90F0: 0x14996C4 at 60 Hz (D_002BBDEC == 1.0), else 0x112A84E (both about 100 hours).
void PlayTime_SetLimit(void) {
    if (D_002BBDEC == 1.0f) {
        D_004D90F0 = 0x14996C4;
    } else {
        D_004D90F0 = 0x112A84E;
    }
}

// Sets the display environment D_004D2610 to w x h and puts it.
void Gs_SetDisplaySize(s16 w, s16 h) {
    D_004D284C = 0;
    sceGsSetDefDispEnv(&D_004D2610, 1, w, h, 0, 0);
    D_004D2610.dispfb.FBP &= 0xFFFFFE00;
    FlushCache(WRITEBACK_DCACHE);
    sceGsSyncPath(0, 0);
    sceGsPutDispEnv(&D_004D2610);
}

// Sets D_002BC918 to grey arg0, sends packet D_002BC980 and sets a 512 x 447 display.
void func_0010FDB8(s32 arg0) {
    D_002BC918 = SCE_GS_SET_RGBAQ(arg0, arg0, arg0, 0x80, 1);
    func_00106948(&D_002BC980);
    Gs_SetDisplaySize(0x200, 0x1BF);
}

// Returns the display offset (DX, DY) of D_004D2610.
void Gs_GetDisplayOffset(u32* x, u32* y) {
    *x = D_004D2610.display.DX;
    *y = D_004D2610.display.DY;
}

// Resets the GS (sceGsResetGraph) and puts the display environment again.
void Gs_ResetGraph(void) {
    sceGsResetGraph(1, 1, 2, 0);
    DPUT_GS_EXTWRITE(0);
    sceGsPutDispEnv(&D_004D2610);
}

// Sets the display offset (DX, DY) of D_004D2610 and marks it changed (D_004D284C).
void Gs_SetDisplayOffset(s32 x, s32 y) {
    D_004D2610.display.DX = x;
    D_004D2610.display.DY = y;
    D_004D284C = 1;
}

#ifdef VERSION_FM
extern f32 D_002BBDEC;
int sceDmaReset(int mode);
void PlayTime_SetLimit(void);

// Resets the GS path, DMA channel 1 and VU0, frame scale 1.0, play time limit (FM only).
void fm_func_00110068(void) {
    sceGsResetPath();
    sceDmaReset(1);
    sceVpu0Reset();
    D_002BBDEC = 1.0f;
    PlayTime_SetLimit();
}
#endif

#ifdef VERSION_FM
typedef struct {
    sceGifTag tag;
    u64 a[13][2];
    u64 b[13][2];
    u64 c[5][2];
} XTailorDrawEnv;
extern XTailorDrawEnv D_004D8EF0;
extern u64 D_002BC750[13];
extern u64 D_002BC7C0[13];
extern u64 D_002BC830[13];

// Builds and puts the default draw environment D_004D8EF0 from the register tables D_002BC750..D_002BC830 (FM).
void Gs_SetDefaultDrawEnv(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        D_004D8EF0.a[i][0] = D_002BC830[i];
        D_004D8EF0.a[i][1] = D_002BC750[i];
        D_004D8EF0.b[i][0] = D_002BC830[i];
        D_004D8EF0.b[i][1] = D_002BC7C0[i];
    }
    SCE_GIF_CLEAR_TAG(&D_004D8EF0.tag);
    D_004D8EF0.tag.NLOOP = 31;
    D_004D8EF0.tag.EOP = 1;
    D_004D8EF0.tag.NREG = 1;
    D_004D8EF0.tag.REGS0 = 0xE;
    D_004D8EF0.c[0][0] = 1;
    D_004D8EF0.c[0][1] = 0x1A;
    D_004D8EF0.c[1][0] = 1;
    D_004D8EF0.c[1][1] = 0x46;
    D_004D8EF0.c[2][0] = 0;
    D_004D8EF0.c[2][1] = 0x45;
    D_004D8EF0.c[3][0] = 0;
    D_004D8EF0.c[3][1] = 0x49;
    D_004D8EF0.c[4][0] = -4;
    D_004D8EF0.c[4][1] = 0x44;
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(&D_004D8EF0.tag);
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", Gs_SetDefaultDrawEnv);
#endif

#ifdef VERSION_FM
// Resets the GS, installs the VSync callback and sets the default draw environment (FM only).
void Gs_Reset(void) {
    sceGsResetGraph(0, 1, 2, 0);
    VSync_InstallCallback();
    Gs_SetDefaultDrawEnv();
}
#endif

#ifdef VERSION_FM
extern s32 D_002BBDE8;
extern volatile s32 D_002B9664;
extern s32 D_002B9174;
extern volatile s32 D_002BBDF0;
extern volatile u32 D_002BBDF4;
extern volatile u32 D_004D90F0;
extern volatile s32 D_002B8340;
extern volatile s32 D_004D90F4;
s32 func_001115A0(void);
void func_001115C0(void);
void VSync_SignalFrame(void);

// VSync handler: interlace field, frame counters, the play time counter D_002BBDF4 (held at the limit), vsync count D_004D90F4.
s32 VSync_Callback(s32 arg0) {
    if (DGET_GS_CSR() & 0x2000) {
        D_002BBDE8 = 1;
    } else {
        D_002BBDE8 = 0;
    }
    if (D_002B9664 == 0 && D_002B9174 == 0) {
        D_002BBDF0++;
    }
    if (D_002BBDF4 < D_004D90F0) {
        D_002BBDF4++;
    } else if (func_001115A0() < 3) {
        if (D_004D90F0 + 60 > D_002BBDF4) {
            D_002BBDF4++;
        } else {
            func_001115C0();
            D_002BBDF4 = 0;
        }
    } else {
        D_002BBDF4 = D_004D90F0;
    }
    D_002B8340++;
    /* volatile read, plain store (the store sits in the jal delay slot) */
    *(s32*)&D_004D90F4 = D_004D90F4 + 1;
    VSync_SignalFrame();
    return 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", VSync_Callback);
s32 VSync_Callback(s32);
#endif

// fadeScreenColor = (128, 128, 128, 128).
void Fade_ResetScreenColor(void) {
    fadeScreenColor[3] = 128;
    fadeScreenColor[2] = 128;
    fadeScreenColor[1] = 128;
    fadeScreenColor[0] = 128;
}

// fadeScreenColor = (0, 0, 0, 0).
void Fade_ClearScreenColor(void) {
    fadeScreenColor[3] = 0;
    fadeScreenColor[2] = 0;
    fadeScreenColor[1] = 0;
    fadeScreenColor[0] = 0;
}

#ifdef VERSION_FM
extern s32 D_002B834C;
extern s32 D_002BBE14;
extern s32 D_002BBE18;
extern s32 D_002A6208;
extern s32 D_002A2740;
extern s32 D_002B8C88;
extern s32 D_002A6204;
extern s32 D_002A61F0;
extern s32 D_002BC060[4];
extern s32 D_002BC080[4];
extern s32 D_002BC0B0[4];

// Resets the fade and overlay state and colours (FM).
void func_00110190(void) {
    D_002B834C = 0;
    D_002BBE14 = 0;
    D_002BBE18 = 0;
    D_002A6208 = 0;
    D_002A2740 = 0;
    D_002B8C88 = 0;
    D_002A6204 = 0;
    D_002A61F0 = 0;
    D_002BC060[2] = 0;
    D_002BC060[1] = 0;
    D_002BC060[0] = 0;
    D_002BC060[3] = 0x80;
    D_002BC080[2] = 0x80;
    D_002BC080[1] = 0x80;
    D_002BC080[0] = 0x80;
    D_002BC080[3] = 0x60;
    D_002BC0B0[2] = 0xFF;
    D_002BC0B0[1] = 0xFF;
    D_002BC0B0[0] = 0xFF;
    D_002BC0B0[3] = 0;
    Fade_ResetScreenColor();
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110190);
#endif

// Sets the play time counter D_002BBDF4.
void PlayTime_SetFrames(s32 a0) {
    D_002BBDF4 = a0;
}

extern f32 D_002B8344;
extern s32 D_002B8354;
extern s32 D_002BBE10;
extern sceVu0FMATRIX D_002B9040;
extern s32 D_002B2CC4;
extern s32 D_002B9660;

// Clears the frame counters and sets the time step D_002B8344 to the frame scale.
void Frame_ResetCounters(void) {
    D_002BBDF0 = 0;
    D_002B8340 = 0;
    D_002BBE10 = 0;
    D_002B8354 = 0;
    D_002B8344 = D_002BBDEC;
    sceVu0UnitMatrix(D_002B9040);
    D_002B2CC4 = 0;
    D_002B9660 = 0;
}

// sceGsSyncVCallback(VSync_Callback).
void VSync_InstallCallback(void) {
    sceGsSyncVCallback(VSync_Callback);
}

#ifdef VERSION_FM
extern volatile s32 D_004D90F4;
extern f32 D_002B8344;
extern f32 D_002B8348;
extern s32 D_002B8354;
extern s32 D_002BBE10;
extern s32 D_002B8C90;
void Frame_WaitVSync(void);

// Waits for the next frame (Frame_WaitVSync) and sets the time step D_002B8344 from the vsyncs counted (capped at 5, scaled by D_002B8348) (FM).
void Frame_UpdateTimeStep(void) {
    s32 i;

    Frame_WaitVSync();
    D_002B8344 = D_004D90F4 * D_002BBDEC;
    if (D_004D90F4 < D_002B8354 + 1) {
        for (i = 0; i < D_002B8354; i++) {
            Frame_WaitVSync();
            D_002B8344 = D_004D90F4 * D_002BBDEC;
        }
    }
    if (D_002BBE10 != 0) {
        D_002B8344 = D_002BBDEC + D_002BBDEC;
    }
    D_002B8344 *= D_002B8348;
    if (D_002B8C90 != 1) {
        if (D_002B8344 > 5.0f) {
            D_002B8344 = 5.0f;
        }
    } else {
        D_002B8344 = 128.0f;
    }
    D_004D90F4 = 0;
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", Frame_UpdateTimeStep);
#endif

INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110410);

#ifdef VERSION_FM
extern f32 D_004D90F8;
void func_00110AE0(void);
void func_00110410(sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, sceVu0FMATRIX, f32, f32,
                   f32, f32, f32, f32, f32, f32, f32, f32);

// Saves the six camera matrices (D_002B8370..D_002B84B0) and recomputes them with func_00110410 (FM).
void func_00110848(f32 arg0) {
    func_00110AE0();
    sceVu0CopyMatrix(D_004D2590, D_002B8370);
    sceVu0CopyMatrix(D_004D2850, D_002B83B0);
    sceVu0CopyMatrix(D_004D2890, D_002B83F0);
    sceVu0CopyMatrix(D_004D28D0, D_002B8430);
    sceVu0CopyMatrix(D_004D2910, D_002B8470);
    sceVu0CopyMatrix(D_004D25D0, D_002B84B0);
    func_00110410(D_002B8370, D_002B83B0, D_002B83F0, D_002B8430, D_002B8470, D_002B84B0, arg0, 0.79999996f,
                  0.8399998546f, 2048.0f, 2048.0f, 1.0f, 16777000.0f, 1.0f, 400000000.0f, D_004D90F8);
}

#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110848);
#endif

// Saves D_002B84F0 and multiplies three camera matrices by D_002DEC60.
void func_001109A8(void) {
    sceVu0CopyMatrix(D_004D2950, D_002B84F0);
    sceVu0MulMatrix(D_002B84F0, D_002B83B0, D_002DEC60);
    sceVu0MulMatrix(D_002B8530, D_002B8430, D_002DEC60);
    sceVu0MulMatrix(D_002B8570, D_002B8470, D_002DEC60);
}

// Restores the six camera matrices saved by func_00110848.
void func_00110A30(void) {
    sceVu0CopyMatrix(D_002B8370, D_004D2590);
    sceVu0CopyMatrix(D_002B83B0, D_004D2850);
    sceVu0CopyMatrix(D_002B83F0, D_004D2890);
    sceVu0CopyMatrix(D_002B8430, D_004D28D0);
    sceVu0CopyMatrix(D_002B8470, D_004D2910);
    sceVu0CopyMatrix(D_002B84B0, D_004D25D0);
    sceVu0MulMatrix(D_002B84F0, D_002B83B0, D_002DEC60);
}

INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110AE0);

// Sets the screen wobble factors D_002B9090 and clears their phases D_002B90A0.
void func_00110C40(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_002B9090[0] = arg0;
    D_002B9090[1] = arg1;
    D_002B9090[2] = arg2;
    D_002B9090[3] = arg3;
    D_002B90A0[0] = 0;
    D_002B90A0[1] = 0;
    D_002B90A0[2] = 0;
}

#ifdef VERSION_FM
extern sceVu0FVECTOR D_002BC190;
void func_00176110(f32*);
void func_00176150(f32*);

// Applies the wobble (cosine of advancing phases) to vector arg0 and passes it to func_00176110 / func_00176150 (FM).
void func_00110C70(sceVu0FVECTOR arg0) {
    register s32 i asm("$18");
    f32* ang;
    f32* v = D_002BC190;
    register f32* s asm("$17");

    sceVu0CopyVector(v, arg0);
    if (D_002B9090[3] != 1.0f) {
        ang = (f32*)D_002B90A0;
        for (i = 0; i < 3; i++) {
            ang[i] += D_002B9090[3];
            if (ang[i] > 3.1415928f) {
                ang[i] -= 6.28318548203f;
            }
            if (ang[i] < -3.1415928f) {
                ang[i] += 6.28318548203f;
            }
            s = &D_002B9090[i];
            *v *= *s + (1.0f - *s) * cosf(ang[i]);
            v++;
        }
    }
    func_00176110(arg0);
    func_00176150(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110C70);
#endif

// Load callback of dkmovie.x: marks the player loaded and starts it (func_F20000(0, movie)).
void Movie_OnPlayerLoaded() {
    D_002B9030 = 1;
    FlushCache(2);
    func_F20000(0, D_004D2994);
}

// Clears the movie flags (D_002A30D0, D_002B9030, D_002B9084).
void Movie_ClearState(void) {
    D_002A30D0 = 0;
    D_002B9030 = 0;
    D_002B9084 = 0;
}

// Loads the movie player overlay "dkmovie.x" to 0xF20000 for movie arg0.
s32 Movie_Load(s32 arg0) {
    D_002B9030 = 0;
    D_004D2994 = arg0;
    return cdvd_QueueFileLoad("dkmovie.x", &func_F20000, Movie_OnPlayerLoaded, NULL);
}

// Pauses sound, func_001EEC00(0x7B), player command 1.
void Movie_Start(void) {
    Sound_PauseNested(2);
    func_001EEC00(0x7B);
    func_F20000(1, 0);
}

// Player command 2 while the player is loaded, else 0.
s32 Movie_IsRunning(void) {
    if (D_002B9030 == 0) {
        return 0;
    }
    return func_F20000(2, 0);
}

#ifndef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xtailor", func_00110ED8);
#endif

// Movie player command 3.
void func_00110EE8(void) {
    func_F20000(3, 0);
}

// Movie player command 8.
void func_00110F08(void) {
    func_F20000(8, 0);
}

// Movie player command 9.
void func_00110F28(void) {
    func_F20000(9, 0);
}

// Movie player command 4.
void func_00110F48(void) {
    func_F20000(4, 0);
}

// Movie player command 5.
void func_00110F68(void) {
    func_F20000(5, 0);
}

// Player command 6 with the system message bits.
void Movie_SetSysMessage(s32 arg0) {
    func_F20000(6, arg0);
}

// Movie player command 7.
void func_00110FA8(void) {
    func_F20000(7, 0);
}

#ifdef VERSION_FM
extern volatile s32 D_002BBDE0;
extern s32 D_002A3F44;
extern s32 D_002B834C;
extern s32 D_002BBE18;
void func_001016B8(void);
s32 func_001EEC00(s32);
void func_00114430(void);
void Sound_PauseNested(s32);

// Ends the movie: command 4, clears the movie flags, resumes sound (FM).
void Movie_Finish(void) {
    if (D_002BBDE0 == 3 && D_002A3F44 == 1) {
        D_002A3F44 = 0;
        func_001016B8();
    }
    func_001EEC00(9);
    func_00114430();
    D_002B834C = 3;
    D_002BBE18 = 0;
    func_00110F48();
    D_002B9030 = 0;
    D_002B9084 = 1;
    Sound_PauseNested(0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xtailor", Movie_Finish);
#endif

// Calls sceCd / sceIpu functions with dummy arguments (probably only so that they are linked).
void func_00111050(void) {
    sceCdRead(0, 0, NULL, NULL);
    Decode_Chunk();
    sceCdStatus();
    sceCdBreak();
    sceCdGetError();
    sceIpuInit();
    sceIpuSync();
}
