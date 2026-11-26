#include "common.h"

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} XFlapjack;

s32 D_002B29CC;
s32 D_002B29D0;

s32 D_002B85C0[4];
s32 D_002B860C;

extern f32 D_002B8340[];
extern u16 D_002B8C70;

f32 D_0048E508;

typedef struct {
    /* 0x00 */ char unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u16 unk_0C;
} XPancakeHeader;

void func_00106718(void);
void func_001091F8(u8*, u8*);
void func_00106728(void);
XFlapjack* func_0011EEB8(u16*, s32, s32 (*)(XFlapjack*));

s32 func_001061D8(void) {
    if (((D_002B85C0[0] == 0) || (D_002B860C == 128)) & 0xFFFF) {
        return 1;
    }
    return 0;
}

#ifdef VERSION_FM
extern s32 D_002A6204;

s32 fm_func_001063F8(void) {
    if (D_002B85C0[0] != 128 || D_002B860C != 0 || D_002A6204 != 0) {
        return 1;
    }
    return 0;
}
#endif

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
s32 func_00106230(void) {
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

void func_00106380(s32 a, s32 b, s32 c, s32 d) {
    D_00494A7C = c * 16 + 0x7000;
    D_00494A80 = d * 16 + 0x7400;
    D_00494A8C = 1.0f;
    D_0048E508 = 800.0f / (f32)b / (f32)(a - 1);
    D_00494A84 = b;
    func_0011ED30(0x2E646, func_00106230);
}

void func_00106428(s32 a, s32 b, s32 c, s32 d) {
    f32 k = 800.0f / (f32)b / (f32)(a - 1);
    D_00494A7C = c * 16 + 0x7000;
    D_00494A80 = d * 16 + 0x7400;
    D_0048E508 = -k;
    D_00494A8C = (f32)a * k + 1.0f;
    D_00494A84 = b;
    func_0011ED30(0x2E646, func_00106230);
}

void Fade_ResetIntensity(void) {
    D_0048E508 = 0;
}

s32 FadeTask_UpdateScreenIn(XFlapjack* arg0) {
    arg0->unk_10 += D_002B8340[1];
    if (arg0->unk_18 <= arg0->unk_10) {
        D_002B85C0[0] = D_002B85C0[1] = D_002B85C0[2] = D_002B85C0[3] = 128;
        return 4;
    }
    D_002B85C0[0] = D_002B85C0[1] = D_002B85C0[2] = D_002B85C0[3] = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void Fade_StartScreenIn(s32 arg0) {
    XFlapjack* p0;
    s32 val;

    func_00106718();
    func_00106728();
    p0 = func_0011EEB8(&D_002B8C70, 0, FadeTask_UpdateScreenIn);
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

s32 FadeTask_UpdateScreenOut(XFlapjack* arg0) {
    arg0->unk_10 -= D_002B8340[1];
    if (arg0->unk_10 <= 0) {
        D_002B85C0[0] = D_002B85C0[1] = D_002B85C0[2] = D_002B85C0[3] = 0;
        return 4;
    }
    D_002B85C0[0] = D_002B85C0[1] = D_002B85C0[2] = D_002B85C0[3] = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void Fade_StartScreenOut(s32 arg0) {
    XFlapjack* p0 = func_0011EEB8(&D_002B8C70, 0, FadeTask_UpdateScreenOut);
    s32 val = arg0 << 1;
    if (arg0 == 0) {
        arg0 = 1;
    }
    if (p0 != NULL) {
        p0->unk_10 = val;
        p0->unk_14 = 128.0f / (arg0 << 1);
    }
}

void func_00106718(void) {
    D_002B29CC = 0;
}

void func_00106728(void) {
    D_002B29D0 = 0;
}

s32 FadeTask_UpdateOverlayIn(XFlapjack* arg0) {
    arg0->unk_10 += D_002B8340[1];
    if (arg0->unk_18 <= arg0->unk_10) {
        D_002B860C = 128;
        return 4;
    }
    D_002B860C = arg0->unk_14 * arg0->unk_10;
    return 0;
}

void Fade_StartOverlayIn(s32 arg0) {
    XFlapjack* p0;
    s32 val;

    func_00106718();
    func_00106728();
    p0 = func_0011EEB8(&D_002B8C70, 0, FadeTask_UpdateOverlayIn);
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

s32 FadeTask_UpdateOverlayOut(XFlapjack* arg0) {
    arg0->unk_10 -= D_002B8340[1];
    if (arg0->unk_10 <= 0.0f) {
        D_002B860C = 0;
        return 4;
    }
    D_002B860C = arg0->unk_14 * arg0->unk_10;
    return 0;
}

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

    p0 = func_0011EEB8(&D_002B8C70, 0, FadeTask_UpdateOverlayOut);
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
