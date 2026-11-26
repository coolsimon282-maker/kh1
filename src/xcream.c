#include "common.h"
#include "libdma.h"
#include "libvu0.h"

extern s32 D_0051C6C4;

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ void* unk_10;
} XCream;

s32 GraphicsDmaTask_Update(XCream* arg0) {
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

extern s32 D_004F82C0;
extern s32 D_004F82C4;
typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 col0[4];
    /* 0x10 */ u8 col1[4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ u8 col2[4];
    /* 0x1C */ u8 col3[4];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ u64 unk_38;
    /* 0x40 */ u64 unk_40;
} XCreamPrm;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} XCreamSub;

typedef struct {
    /* 0x000 */ s32 flags;
    /* 0x004 */ u8 unk_004[0x114];
    /* 0x118 */ f32 unk_118;
    /* 0x11C */ u8 unk_11C[0x30];
    /* 0x14C */ XCreamSub* unk_14C;
    /* 0x150 */ u8 unk_150[0xC];
    /* 0x15C */ s32 unk_15C;
    /* 0x160 */ u8 unk_160[0x230];
    /* 0x390 */ s32 unk_390;
} XCreamObj;

typedef struct {
    /* 0x00 */ f32 unk_00[4];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} XCreamCam;

extern XCreamCam D_002BC0F0;
f32 func_00135CA0(f32);
void func_001621E0(s32, sceVu0FVECTOR*, XCreamPrm*, XCreamObj*);

void func_00127960(u8* arg0, sceVu0FVECTOR* arg1, s32 arg2) {
    XCreamObj* obj = (XCreamObj*)arg0;
    XCreamPrm prm;
    s32 i;

    if (obj->flags & 0x100) {
        prm.col0[0] = 0x80;
        prm.col0[1] = 0x80;
        prm.col0[2] = 0x80;
        prm.col0[3] = 0x80;
        prm.unk_00 = 0x101;
        prm.col1[0] = D_002BC0F0.unk_10;
        prm.col1[1] = D_002BC0F0.unk_14;
        prm.col1[2] = D_002BC0F0.unk_18;
        prm.col1[3] = (s32)func_00135CA0(obj->unk_118);
    } else {
        prm.col0[0] = 0;
        prm.col0[1] = 0;
        prm.unk_00 = 0x101;
        prm.col0[2] = 0;
        prm.col1[0] = 0x80;
        prm.col0[3] = arg2;
        prm.col1[1] = 0x80;
        prm.col1[2] = 0x80;
        prm.col1[3] = 0xFF;
    }
    prm.unk_04 = 0;
    prm.unk_08 = D_004F82C4 + D_004F82C0;
    D_004F82C0 += 10;
    prm.unk_20 = 0;
    prm.unk_28 = obj->unk_390;
    if (obj->unk_390 & 0x40000000) {
        prm.unk_28 = -1;
    }
    prm.unk_2C = 0;
    if (obj->unk_14C != NULL && obj->unk_14C->unk_00 != 0 && (obj->flags & 0x4000)) {
        prm.unk_14 = obj->unk_14C->unk_04;
        for (i = 0; i < 4; i++) {
            prm.col2[i] = prm.col0[i];
            prm.col3[i] = prm.col1[i];
        }
    } else {
        prm.unk_14 = 0;
    }
    {
        u64 tag1 = 0x1000401D0;
        u64 tag0 = 0x3A0001C0;

        prm.unk_38 = tag0;
        prm.unk_30 = 0;
        prm.unk_40 = tag1;
        prm.unk_34 = 0;
    }
    func_001621E0(obj->unk_15C, arg1, &prm, obj);
}

typedef struct {
    f32 x, y, z, w;
} XCreamVec;

#ifdef VERSION_FM
// .data (0x002E27E0-0x002E2810)
s32 D_002E27E0[4] = {128, 196, 256, 0};
XCreamVec D_002E27F0 = {0.0f, 0.0f, 0.0f, 1.0f};
sceVu0FVECTOR D_002E2800 = {1.0f, 0.0f, 0.0f, 1.0f};
#else
extern XCreamVec D_002E27F0;
#endif
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
    func_0015ED80(0xEC53, GraphicsDmaTask_Update)->unk_10 = D_004F8270;
    func_0015ED80(0xB1BB, GraphicsDmaTask_Update)->unk_10 = D_004F8270;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/xcream", func_001284E8);

INCLUDE_ASM("asm/nonmatchings/xcream", func_00128780);

void* TaskSystem_AddTask(s32, s32 (*func)(void));
u64* GsPacket_AddReg(u64 arg0, u64 arg1, u64* arg2);
void GsPacket_SetGifTag(u_long128* arg0, s32 arg1, u_long128* arg2);
void GsPacket_SetDmaTag(u_long128* arg0, s32 arg1, u_long128* arg2);

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
    p = (u_long128*)GsPacket_AddReg(0x47, 0x50000, (u64*)p);
    p = (u_long128*)GsPacket_AddReg(0x48, 0x50000, (u64*)p);
    p = (u_long128*)GsPacket_AddReg(0x14, 0x60, (u64*)p);
    GsPacket_SetGifTag(b, 1, p);
    GsPacket_SetDmaTag(a, 7, p);
    D_00351BC8(0);
    sceVu0ViewScreenMatrix(D_004F82D0, 32768.0f, 1.0f, 1.0f, 2048.0f, 2048.0f, 1.0f, 65535.0f, 1.0f, 65535.0f);
    TaskSystem_AddTask(0x1FBCF, func_00128488);
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
