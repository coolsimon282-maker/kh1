#include "common.h"
#include "xtango.h"

XWhiskey* D_00663A28[8];

#ifdef VERSION_FM
// FM's code reads this table at 0x669A18 (FM's linker puts the definition above somewhere else).
extern XWhiskey* D_00669A18[8];
#define XPACKAGE_TABLE D_00669A18
#else
#define XPACKAGE_TABLE D_00663A28
#endif

void func_00247778(s32 arg0, XWhiskey* arg1) {
    if (arg0 > 0) {
        while (arg0 != 0) {
            arg0 += -1;
            arg1->unk_10 = 0;
            arg1->unk_14 = 0;
            arg1 = &arg1->unk_20;
        };
    }
}

typedef struct {
    /* 0x00 */ s32 unk_00[4];
    /* 0x10 */ u8 unk_10[0x50];
    /* 0x60 */ u64 unk_60;
} XPackageUnk77A8;

void func_00247128(XPackageUnk77A8* arg0, s32* arg1);

void func_002477A8(XPackageUnk77A8* arg0, s32* arg1) {
    if ((arg0->unk_60 & 0x14) == 0x14) {
        func_00247128(arg0, arg1);
        return;
    }
    arg1[0] = arg0->unk_00[0];
    arg1[1] = arg0->unk_00[1];
    arg1[2] = arg0->unk_00[2];
    arg1[3] = arg0->unk_00[3];
}

INCLUDE_ASM("asm/nonmatchings/xpackage", func_00247808);

INCLUDE_ASM("asm/nonmatchings/xpackage", func_002479A0);

INCLUDE_ASM("asm/nonmatchings/xpackage", func_00247A30);

void func_00247AA0(s32 arg0) {
    func_00247030(arg0, 1);
    func_00246B50(arg0, 1);
    func_00246D68(arg0, 1);
}

typedef struct {
    /* 0x00 */ u64 unk_00[0x18];
} XPackageUnk7AE0Entry; // size = 0xC0, the same entries as XPackageUnk7B60Entry

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8; // offset of the entries from the start of this header
} XPackageUnk7AE0Hdr;

// arg0: list of entry indices ended by -1; each entry is copied to arg1[]
void func_00247AE0(s32* arg0, XPackageUnk7AE0Entry* arg1, XPackageUnk7AE0Hdr* arg2) {
    XPackageUnk7AE0Entry* base = (XPackageUnk7AE0Entry*)((u8*)arg2 + arg2->unk_8);

    while (*arg0 != -1) {
        *arg1 = base[*arg0];
        arg0++;
        arg1++;
    }
}

typedef struct {
    /* 0x00 */ u8 unk_00[0xC0];
} XPackageUnk7B60Entry; // size = 0xC0

typedef struct {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8; // offset of the entries from the start of this header
} XPackageUnk7B60Hdr;

// arg0: list of entry indices ended by -1; arg1 gets each entry's address
void func_00247B60(s32* arg0, s32* arg1, XPackageUnk7B60Hdr* arg2) {
    XPackageUnk7B60Entry* base = (XPackageUnk7B60Entry*)((u8*)arg2 + arg2->unk_8);

    while (*arg0 != -1) {
        *arg1 = (s32)&base[*arg0];
        arg0++;
        arg1++;
    }
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x20];
    /* 0x20 */ s32 unk_20[4][4];
} XPackageUnk7BA8;

void func_00247BA8(XPackageUnk7BA8* arg0, s32* arg1) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg0->unk_20[i][j] = arg1[j];
        }
    }
}

// four GS XYZ vertices (x, y, z, 0) of a rectangle, offset by (0x700, 0x740) pixels
typedef struct {
    /* 0x00 */ u8 unk_00[0xA0];
    /* 0xA0 */ s32 vtx[4][4];
} XPackageQuad;

void func_00247BF8(XPackageQuad* q, s32 x, s32 y, s32 w, s32 h) {
    s32 x0 = (x << 4) + 0x7000;
    s32 y0 = (y << 4) + 0x7400;
    s32 y1 = ((y + h) << 4) + 0x7400;
    s32 x1 = ((x + w) << 4) + 0x7000;

    q->vtx[0][0] = x0;
    q->vtx[0][1] = y0;
    q->vtx[0][2] = -0x100;
    q->vtx[0][3] = 0;
    q->vtx[1][0] = x0;
    q->vtx[1][1] = y1;
    q->vtx[1][2] = -0x100;
    q->vtx[1][3] = 0;
    q->vtx[2][0] = x1;
    q->vtx[2][1] = y0;
    q->vtx[2][2] = -0x100;
    q->vtx[2][3] = 0;
    q->vtx[3][0] = x1;
    q->vtx[3][1] = y1;
    q->vtx[3][2] = -0x100;
    q->vtx[3][3] = 0;
}

// arg0: a type byte, a 32-bit little-endian size, then the data
s32 func_00247C68(u8* arg0, void* arg1, s32* arg2) {
    s32 size = arg0[1] + (arg0[2] << 8) + (arg0[3] << 16) + (arg0[4] << 24);

    memcpy(arg1, arg0 + 5, size);
    *arg2 = size;
    return size;
}

extern void (*D_00469FC8[])(u8* arg0, s32 arg1, s32* arg2);

s32 func_00247CD8(s32 arg0, u8* arg1) {
    s32 ret;

    D_00469FC8[*arg1](arg1, arg0, &ret);
    return ret;
}

extern char D_00491878[]; // FM address names; probably the file name and message of an assert
extern char D_00491880[];

void func_00247D88();

s32 func_00247D18(u8* arg0) {
    if (arg0[0] != 1) {
        func_00247D88(D_00491878, D_00491880, 0x3F);
    }
    return arg0[1] + (arg0[2] << 8) + (arg0[3] << 16) + (arg0[4] << 24);
}

void func_00247D88(void) {
}

void func_00247D90(void) {
    s32 i;

    for (i = 7; i >= 0; i--) {
        XPACKAGE_TABLE[i] = NULL;
    }
}

extern s32 D_0046A038;
extern s32 D_0046A03C;
extern s32 D_0046A040;
extern s32 D_0046A044;
extern s32 D_0046A048;

void func_00247DC8(s32 idx, s32 arg1, s32 arg2, s32 arg3) {
    XWhiskey* p = XPACKAGE_TABLE[idx];
    s32 old40, old48, new40, new48;

    old40 = D_0046A040;
    old48 = D_0046A048;
    D_0046A03C = p->unk_0C;
    new40 = p->unk_10;
    D_0046A044 = p->unk_14;
    new48 = p->unk_18;
    D_0046A040 = new40;
    D_0046A048 = new48;
    func_0024AB00(arg1, arg2, arg3);
    D_0046A040 = old40;
    D_0046A048 = old48;
}

void func_00247E68(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(0, arg0, arg1, arg2);
}

void func_00247E98(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(1, arg0, arg1, arg2);
}

void func_00247EC8(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(2, arg0, arg1, arg2);
}

void func_00247EF8(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(3, arg0, arg1, arg2);
}

void func_00247F28(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(4, arg0, arg1, arg2);
}

void func_00247F58(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(5, arg0, arg1, arg2);
}

void func_00247F88(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(6, arg0, arg1, arg2);
}

void func_00247FB8(s32 arg0, s32 arg1, s32 arg2) {
    func_00247DC8(7, arg0, arg1, arg2);
}

void func_0024E1D0(void);

void func_00247FE8(s32 idx) {
    s32 old40 = D_0046A040;
    s32 old48 = D_0046A048;
    XWhiskey* p;

    if ((D_002C1EB8.u8 >> 3 & 3) == 0) {
        p = XPACKAGE_TABLE[idx];
        D_0046A038 = (s32)p;
        D_0046A03C = p->unk_0C;
        D_0046A040 = p->unk_10;
        D_0046A044 = p->unk_14;
        D_0046A048 = p->unk_18;
        p->munny++;
        func_0024E1D0();
        D_0046A040 = old40;
        D_0046A048 = old48;
    }
}

void func_002480A8(void) {
    func_00247FE8(0);
}

void func_002480C0(void) {
    func_00247FE8(1);
}

void func_002480D8(void) {
    func_00247FE8(2);
}

void func_002480F0(void) {
    func_00247FE8(3);
}

void func_00248108(void) {
    func_00247FE8(4);
}

void func_00248120(void) {
    func_00247FE8(5);
}

void func_00248138(void) {
    func_00247FE8(6);
}

void func_00248150(void) {
    func_00247FE8(7);
}

INCLUDE_ASM("asm/nonmatchings/xpackage", func_00248168);
// void func_00248168(s32 arg0) {
//     if (D_00663A28[arg0]->unk_24 != 0) {
//         free(D_00663A28[arg0]);
//     }
//     D_00663A28[arg0] = NULL;
// }

void func_002481B0(void) {
    func_00248168(0);
}

void func_002481C8(void) {
    func_00248168(1);
}

void func_002481E0(void) {
    func_00248168(2);
}

void func_002481F8(void) {
    func_00248168(3);
}

void func_00248210(void) {
    func_00248168(4);
}

void func_00248228(void) {
    func_00248168(5);
}

void func_00248240(void) {
    func_00248168(6);
}

void func_00248258(void) {
    func_00248168(7);
}

void func_00248270(s32* arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 old40, old48, new40, new48;

    old40 = D_0046A040;
    old48 = D_0046A048;
    D_0046A03C = arg0[3];
    new40 = arg0[4];
    D_0046A044 = arg0[5];
    new48 = arg0[6];
    D_0046A040 = new40;
    D_0046A048 = new48;
    func_0024AB00(arg1, arg2, arg3);
    D_0046A040 = old40;
    D_0046A048 = old48;
}

void func_00248300() {
    func_0024AB00();
}

s32 func_00248318(s32 arg0) {
    return ((arg0 << 5) + arg0 * 0x10320 + 0x5E7) & ~0x3F;
}

INCLUDE_ASM("asm/nonmatchings/xpackage", func_00248340);

void func_002484F8(s32 arg0) {
    func_00248340(arg0, malloc(func_00248318(arg0)), 1);
}

void func_00248530(void) {
    func_00247D90();
}
