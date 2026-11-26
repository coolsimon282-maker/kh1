/**
 * Screen fades: fade the whole screen (fadeScreenColor, 0 = black .. 128 = normal) or an overlay (fadeOverlayAlpha)
 * in or out over a number of frames, and an iris-like wipe (a rectangle that closes on or opens from a point).
 * Each fade is a task on fadeTaskList (see xgoblin.c) that steps by the frame time D_002B8340[1].
 */
#include "common.h"

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} XFlapjack;

s32 D_002B29CC;
s32 D_002B29D0;

s32 fadeScreenColor[4];
s32 fadeOverlayAlpha;

extern f32 D_002B8340[];
extern u16 fadeTaskList;

f32 D_0048E508;

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u16 unk_0C;
} XPancakeHeader;

void func_00106718(void);
void func_001091F8(u8*, u8*);
void func_00106728(void);
XFlapjack* TaskList_Add(u16*, s32, s32 (*)(XFlapjack*));

// Returns 1 when the screen is faded out (screen colour 0) or the overlay is fully in (128).
s32 Fade_IsBlack(void) {
    if (((fadeScreenColor[0] == 0) || (fadeOverlayAlpha == 128)) & 0xFFFF) {
        return 1;
    }
    return 0;
}

#ifdef VERSION_FM
extern s32 D_002A6204;

// Returns 1 while a fade is not back to normal (screen not 128, overlay not 0, or D_002A6204 set).
s32 Fade_IsActive(void) {
    if (fadeScreenColor[0] != 128 || fadeOverlayAlpha != 0 || D_002A6204 != 0) {
        return 1;
    }
    return 0;
}
#endif

// Sends the image data of a packed header (offsets at +0x18 / +0x1C) to func_001091F8.
void func_00106208(u8* arg0) {
    XPancakeHeader* hdr = (XPancakeHeader*)(arg0 + 0x10);
    u8* data = (u8*)hdr + hdr->unk_0C;

    func_001091F8(data, data + hdr->unk_08);
}

extern s32 D_002B8C90;
extern s32 D_00494A7C;
extern s32 D_00494A80;
extern s32 D_00494A84;
extern f32 D_00494A8C;
extern u8 D_002A6A40[];
extern u8 D_002A6AA0[];
extern u8 D_002A6B70[];
extern u8 D_002C13A0[];
void func_00106948(u8*);

#define XP_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
typedef struct {
    char pad[0xA8];
    s64 unk_A8;
    char padB0[8];
    s64 unk_B8;
} XPancakePkt;
extern XPancakePkt D_002A6AB0;
// Wipe task: shrinks or grows the rectangle around the centre each frame; ends (returns 4) when done.
s32 FadeTask_UpdateIris(void) {
    s32 n;
    f32 t;

    if (D_002B8C90 == 1) {
        D_0048E508 = 0;
        return 4;
    }
    if (D_0048E508 == 0.0f) {
        return 4;
    }
    func_00106948(D_002A6A40);
    t = D_00494A8C + D_0048E508;
    D_00494A8C = t;
    n = 800.0f / t;
    if (n <= D_00494A84) {
        n = D_00494A84;
    }
    if (t < 0.0f) {
        n = 800;
    }
    func_00106208(D_002C13A0);
    D_002A6AB0.unk_A8 = XP_XYZ(D_00494A7C - n * 16, D_00494A80 - n * 28, -2);
    D_002A6AB0.unk_B8 = XP_XYZ(D_00494A7C + n * 16, D_00494A80 + n * 28, -2);
    func_00106948(D_002A6B70);
    func_00106948(D_002A6AA0);
    return 0;
}

// Starts a wipe that closes on the point (c, d) over a frames, down to size b.
void Fade_StartIrisClose(s32 a, s32 b, s32 c, s32 d) {
    D_00494A7C = c * 16 + 0x7000;
    D_00494A80 = d * 16 + 0x7400;
    D_00494A8C = 1.0f;
    D_0048E508 = 800.0f / (f32)b / (f32)(a - 1);
    D_00494A84 = b;
    TaskSystem_AddTask(0x2E646, FadeTask_UpdateIris);
}

// Starts a wipe that opens from the point (c, d) over a frames, from size b.
void Fade_StartIrisOpen(s32 a, s32 b, s32 c, s32 d) {
    f32 k = 800.0f / (f32)b / (f32)(a - 1);
    D_00494A7C = c * 16 + 0x7000;
    D_00494A80 = d * 16 + 0x7400;
    D_0048E508 = -k;
    D_00494A8C = (f32)a * k + 1.0f;
    D_00494A84 = b;
    TaskSystem_AddTask(0x2E646, FadeTask_UpdateIris);
}

// Stops the wipe (step 0).
void Fade_ResetIntensity(void) {
    D_0048E508 = 0;
}

// Fade-in task: raises the screen colour towards 128; ends at the set time.
s32 FadeTask_UpdateScreenIn(XFlapjack* arg0) {
    arg0->unk_10 += D_002B8340[1];
    if (arg0->unk_18 <= arg0->unk_10) {
        fadeScreenColor[0] = fadeScreenColor[1] = fadeScreenColor[2] = fadeScreenColor[3] = 128;
        return 4;
    }
    fadeScreenColor[0] = fadeScreenColor[1] = fadeScreenColor[2] = fadeScreenColor[3] = arg0->unk_14 * arg0->unk_10;
    return 0;
}

// Starts fading the screen in over arg0 frames.
void Fade_StartScreenIn(s32 arg0) {
    XFlapjack* p0;
    s32 val;

    func_00106718();
    func_00106728();
    p0 = TaskList_Add(&fadeTaskList, 0, FadeTask_UpdateScreenIn);
    val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = 0.0f;
        p0->unk_18 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

// Fade-out task: lowers the screen colour towards 0.
s32 FadeTask_UpdateScreenOut(XFlapjack* arg0) {
    arg0->unk_10 -= D_002B8340[1];
    if (arg0->unk_10 <= 0) {
        fadeScreenColor[0] = fadeScreenColor[1] = fadeScreenColor[2] = fadeScreenColor[3] = 0;
        return 4;
    }
    fadeScreenColor[0] = fadeScreenColor[1] = fadeScreenColor[2] = fadeScreenColor[3] = arg0->unk_14 * arg0->unk_10;
    return 0;
}

// Starts fading the screen out over arg0 frames.
void Fade_StartScreenOut(s32 arg0) {
    XFlapjack* p0 = TaskList_Add(&fadeTaskList, 0, FadeTask_UpdateScreenOut);
    s32 val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

// Clears the flag D_002B29CC (checked by Fade_StartOverlayOut).
void func_00106718(void) {
    D_002B29CC = 0;
}

// Clears the flag D_002B29D0 (checked by Fade_StartOverlayOut).
void func_00106728(void) {
    D_002B29D0 = 0;
}

// Overlay fade-in task: raises the overlay alpha towards 128.
s32 FadeTask_UpdateOverlayIn(XFlapjack* arg0) {
    arg0->unk_10 += D_002B8340[1];
    if (arg0->unk_18 <= arg0->unk_10) {
        fadeOverlayAlpha = 128;
        return 4;
    }
    fadeOverlayAlpha = arg0->unk_14 * arg0->unk_10;
    return 0;
}

// Starts fading the overlay in over arg0 frames.
void Fade_StartOverlayIn(s32 arg0) {
    XFlapjack* p0;
    s32 val;

    func_00106718();
    func_00106728();
    p0 = TaskList_Add(&fadeTaskList, 0, FadeTask_UpdateOverlayIn);
    val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = 0.0f;
        p0->unk_18 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

// Overlay fade-out task: lowers the overlay alpha towards 0.
s32 FadeTask_UpdateOverlayOut(XFlapjack* arg0) {
    arg0->unk_10 -= D_002B8340[1];
    if (arg0->unk_10 <= 0.0f) {
        fadeOverlayAlpha = 0;
        return 4;
    }
    fadeOverlayAlpha = arg0->unk_14 * arg0->unk_10;
    return 0;
}

// Starts fading the overlay out over arg0 frames (or fades the screen in instead if D_002B29CC/D_002B29D0 is 1).
void Fade_StartOverlayOut(s32 arg0) {
    XFlapjack* p0;
    f32 f0;
    s32 val;

    if (D_002B29CC == 1 || D_002B29D0 == 1) {
        Fade_StartScreenIn(arg0);
        func_00106718();
        func_00106728();
        return;
    }

    p0 = TaskList_Add(&fadeTaskList, 0, FadeTask_UpdateOverlayOut);
    val = arg0 << 1;
    f0 = 128.0f;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != 0) {
        p0->unk_10 = val;
        p0->unk_14 = f0 / ((f32)(arg0 << 1));
    }
}
