#include "common.h"
#include "libdma.h"
#include "libvu0.h"

extern s32 D_0051C6C4;

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void* unk_10;
} XCream;

s32 func_001274C0(XCream* arg0) {
    sceDmaSend(sceDmaGetChan(SCE_DMA_GIF), arg0->unk_10);
    return 2;
}

void func_00121EB0(void*);

s32 func_001274F8(XCream* arg0) {
    sceDmaChan* d = sceDmaGetChan(SCE_DMA_VIF1);

    d->chcr.DIR = 1;
    d->chcr.MOD = 1;
    d->chcr.ASP = 0;
    d->chcr.TTE = 0;
    sceDmaSend(d, arg0->unk_10);
    func_00121EB0(arg0->unk_10);
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127560);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127960);

extern struct {
    f32 x, y, z, w;
} D_002E27F0;
extern s32 D_004F82C0;
extern s32 D_004F82C4;
s32 func_001145E8(void*, s32, s32, void*);

void func_00127B18(u8* arg0, sceVu0FVECTOR* arg1, s32 arg2) {
    sceVu0FMATRIX m;

    sceVu0MulMatrix(m, arg1, (sceVu0FVECTOR*)(arg0 + 0xD0));
    D_002E27F0.w = arg2;
    func_001145E8(m, *(s32*)(arg0 + 0x154), D_004F82C4 + D_004F82C0++, &D_002E27F0);
}

extern sceVu0FVECTOR D_004F82D0[4];
void func_00127960(u8* arg0, sceVu0FVECTOR* arg1, s32 arg2);

void func_00127B98(u8* arg0, sceVu0FVECTOR* arg1, f32 arg2) {
    sceVu0FMATRIX m;

    sceVu0MulMatrix(m, D_004F82D0, arg1);
    if ((s32)(*(u64*)(arg0 + 0x370) >> 39) & 1) {
        func_00127B18(arg0, m, (s32)arg2);
    } else {
        func_00127960(arg0, m, (s32)arg2);
    }
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_00127C20);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128250);

extern u8 D_004F8270[];

XCream* func_0015ED80(s32 arg0, s32 (*arg1)(XCream*));

s32 func_00128488(void) {
    D_004F82C0 = 0;
    func_0015ED80(0xEC53, func_001274C0)->unk_10 = D_004F8270;
    func_0015ED80(0xB1BB, func_001274C0)->unk_10 = D_004F8270;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_001284E8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128780);

void* func_0011ED30(s32, s32 (*func)(void));
u64* func_0011F970(u64 arg0, u64 arg1, u64* arg2);
void func_0011F980(u_long128* arg0, s32 arg1, u_long128* arg2);
void func_0011F9B0(u_long128* arg0, s32 arg1, u_long128* arg2);

typedef struct {
    /* 0x000 */ u8 data[0x150];
} XCreamUnk7820;

typedef struct {
    /* 0x000 */ u8 data[0x220];
} XCreamUnk7C10;

extern XCreamUnk7820 D_004F7820[3];
extern XCreamUnk7C10 D_004F7C10[3];
extern void (*D_00351BC8)(s32);
void func_001284E8(XCreamUnk7820*, s32);
void func_00128780(XCreamUnk7C10*, s32);

// init: the three 0x150 and three 0x220 objects, the GIF packet at D_004F8270, the view-screen matrix
void func_00128B68(void) {
    s32 i;
    u_long128* p;
    u_long128* a;
    u_long128* b;

    for (i = 0; i < 3; i++) {
        func_001284E8(&D_004F7820[i], i);
        func_00128780(&D_004F7C10[i], i);
    }
    p = (u_long128*)D_004F8270;
    a = p++;
    b = p++;
    p = (u_long128*)func_0011F970(0x47, 0x50000, (u64*)p);
    p = (u_long128*)func_0011F970(0x48, 0x50000, (u64*)p);
    p = (u_long128*)func_0011F970(0x14, 0x60, (u64*)p);
    func_0011F980(b, 1, p);
    func_0011F9B0(a, 7, p);
    D_00351BC8(0);
    sceVu0ViewScreenMatrix(D_004F82D0, 32768.0f, 1.0f, 1.0f, 2048.0f, 2048.0f, 1.0f, 65535.0f, 1.0f, 65535.0f);
    func_0011ED30(0x1FBCF, func_00128488);
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
} XCreamUnk8CA8;

extern u8* D_00514F10;

s32 func_0012B930(u8*, s32);
void func_0012BA30(s32, XCreamUnk8CA8*, s32);

s32 func_00128CA8(XCreamUnk8CA8* arg0, s32 arg1) {
    s32 r = func_0012B930(D_00514F10, *(s32*)(D_00514F10 + 4) + arg1 * 2);

    if (arg0->unk_0 != 0) {
        func_0012BA30(r, arg0, 4);
    }
    return r;
}

void func_00128D10(XCreamUnk8CA8* arg0) {
    arg0->unk_0 = func_00128CA8(arg0, arg0->unk_4);
}

void func_00128D40(s32* arg0) {
    func_0012B850(*arg0);
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ XCreamUnk8CA8 unk_4;
} XCreamUnk8D58;

void func_00128D58(XCreamUnk8D58* arg0) {
    if (arg0->unk_0 != 0) {
        func_0012B850(arg0->unk_0);
    }
    arg0->unk_0 = func_00128CA8(&arg0->unk_4, arg0->unk_4.unk_4);
}

void func_00128DA0(void) {
    func_0012B850(D_0051C6C4);
}

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ u16 unk_4;
} XCreamUnk8DF8;

extern u8* D_00514F10;

void func_00128DC0(s32* arg0) {
    s32 i;
    s32 ofs = 0x720;

    for (i = 0; i < 4; i++) {
        *(u16*)(D_00514F10 + ofs + 4) = arg0[i];
        ofs += 2;
    }
}

void func_00128DF8(XCreamUnk8DF8* arg0) {
    *(u16*)(D_00514F10 + arg0->unk_0 * 2 + 0x724) = arg0->unk_4;
}

void func_00128E18(void) {
}

void func_00128E20(void) {
}
