// Final Mix's version of gumi (JP: src/gumi.c, 0x1BBCD8-0x1BD0B8; here 0x1B9B78-0x1BAF08).
// Split out of the placeholder seg_0B9B78; FM only (JP/EU use src/gumi.c). Built without -g like JP's gumi.c (NO_G_FILES).
#include "common.h"

extern s32 D_0037A148;
extern s32 D_0037A150;
extern s32 D_0037A154;
s32 func_001BB740(void);

typedef struct {
    u8 pad[0x9C00];
    u8 tbl9C00[0x1020];
    u8 tblAC20[1];
} A2Big22F768;

void *func_0022F768(s32);

u8 func_001B9B78(s32 i) {
    return ((A2Big22F768 *)func_0022F768(4))->tbl9C00[i];
}

void *func_0022F768(s32);

void func_001B9BB0(s32 i, s32 x) {
    ((A2Big22F768 *)func_0022F768(4))->tbl9C00[i] = x;
}

double asin(double);

double func_001B9BF8(double x) {
    return asin(x);
}

extern s32 D_00621210;
s32 func_001207F8(s32);
void FlushCache(int);
void func_F20000(void);

s32 func_001B9C10(void) {
    if (func_001207F8(D_00621210)) {
        return 0;
    }
    FlushCache(0);
    FlushCache(2);
    func_F20000();
    return 4;
}

void func_001B9C60(const char *name) {
    void (*f)(void) = func_F20000;

    D_00621210 = func_00120438(name, f);
    FlushCache(0);
    FlushCache(2);
    f();
}

void func_001B9CB0(void) {
    u8* p = func_0022F768(4);

    if (*(s32*)(p + 0x9B40) == 0) {
        *(s32*)(p + 0x9B40) = 0x4000;
    }
    if (*(s32*)(p + 0x9B44) == 0) {
        *(s32*)(p + 0x9B44) = 0x8000;
    }
    if (*(s32*)(p + 0x9B48) == 0) {
        *(s32*)(p + 0x9B48) = 0x400;
    }
    if (*(s32*)(p + 0x9B4C) == 0) {
        *(s32*)(p + 0x9B4C) = 0x2000;
    }
    if (*(s32*)(p + 0x9B50) == 0) {
        *(s32*)(p + 0x9B50) = 0x2000;
    }
    if (*(s32*)(p + 0x9B54) == 0) {
        *(s32*)(p + 0x9B54) = 0x2000;
    }
    if (*(s32*)(p + 0x9B58) == 0) {
        *(s32*)(p + 0x9B58) = 0x1000;
    }
    if (*(s32*)(p + 0x9B5C) == 0) {
        *(s32*)(p + 0x9B5C) = 0x1000;
    }
    if (*(s32*)(p + 0x9B60) == 0) {
        *(s32*)(p + 0x9B60) = 0x1000;
    }
}

void func_001B9CB0();

s32 func_001B9DF0(s32 i) {
    u8 *p = func_0022F768(4);

    func_001B9CB0();
    return ((s32 *)(p + 0x9B40))[i];
}

void func_001B9E40(s32 i, s32 x) {
    ((s32 *)((u8 *)func_0022F768(4) + 0x9B40))[i] = x;
}

s32 func_001BAAD0(void);
s32 func_001BC590(s32);

s32 func_001B9E88(void) {
    if (func_001BAAD0() & 0x80) {
        return 0;
    }
    return func_001BC590(0x31) > 0;
}

void func_001BB580(void);
void func_001BE820(void*, s32);
void func_001BAAF0(u8*);
void func_001B9F78(s32);
void* func_001BA9A8(void);
s32* func_001BA980(void);
void func_001BAA20(u8*);
void* func_001BA9D8(s32);
void func_001BAB80(s32, u8*);
void func_001BA108(void*, s32);

void func_001BC048(void) {
    u8* p;
    u8* q;

    func_001BB580();
    p = func_0022F768(4);
    func_001BE820(p, 0xB040);
    *(s32*)(p + 4) = 0x101;
    p[0] = 'G';
    p[1] = 'U';
    p[2] = 'M';
    p[3] = 'I';
    func_001BAAF0(p);
    func_001B9F78(0);
    q = func_001BA9A8();
    q[0x44] = 1;
    q[0x47] = 1;
    func_001BAA20((u8*)func_001BA980());
    func_001BAB80(10, func_001BA9D8(0));
    func_001BA108(func_001BA9D8(0), 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/gumi", func_001B9F78);

INCLUDE_ASM("asm/nonmatchings/unsplit/gumi", func_001BA060);

INCLUDE_ASM("asm/nonmatchings/unsplit/gumi", func_001BA108);

s32 func_001BA1E0(void) {
    return 0xB040;
}

typedef struct {
    u8 pad[0x14];
    u16 unk_14;
    u16 unk_16;
    u8 pad2[4];
} A2Elem1C;
A2Elem1C *func_001BB658(s32 i);

u16 func_001BC370(s32 i) {
    return func_001BB658(i)->unk_14;
}

u16 func_001BC390(s32 i) {
    return func_001BB658(i)->unk_16;
}

void func_001BB558(void);
s32 func_001BE5C8(s32);
s32 func_001BE5D0(s32);
s32 func_001EFBB8(s32);
void func_001EFAF0(void);

s32 func_001BA228(s32 a0) {
    s32 r;

    func_001BB558();
    r = func_001EFBB8(func_001BE5C8(a0));
    func_001EFAF0();
    return r;
}

s32 func_001BA268(s32 a0) {
    s32 r;

    func_001BB558();
    r = func_001EFBB8(func_001BE5D0(a0));
    func_001EFAF0();
    return r;
}

void *func_001BA9D8(s32);

void func_001BA2A8(s32 n, u8 *src) {
    u8 *d = (u8 *)func_001BA9D8(n) + 0x50;
    s32 i;

    for (i = 0; i < 32; i++) {
        *d++ = src[i];
    }
}

void *func_001BA9A8(void);
u8 func_001BA458(s32 x);

s32 func_001BC480(s32 i) {
    u8* p = (u8*)func_001BA9A8() + i;
    s32 c = *p;
    s32 m = func_001BA458(i);

    if (c < m) {
        *p += 1;
        return 1;
    }
    return 0;
}

void func_001BA358(s32 i, s32 add) {
    u8 *p = (u8 *)func_001BA9A8() + i;

    if (*p + add > func_001BA458(i)) {
        *p = func_001BA458(i);
    } else {
        *p += add;
    }
}

void func_001BC578(void) {
    func_001BB740();
}

void *func_001BA9A8(void);

s32 func_001BC590(s32 i) {
    return ((u8 *)func_001BA9A8())[i];
}

void func_001BA420(s32 i, s32 x) {
    ((u8 *)func_001BA9A8())[i] = x;
}

A2Elem1C *func_001BB658(s32 i);

u8 func_001BA458(s32 x) {
    if ((u32)(x - 0x47) < 0x30) {
        return 1;
    }
    return ((u8 *)func_001BB658(x))[0xB];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/gumi", func_001BA488);

typedef struct {
    u64 d[14];
} A2S70;
extern u8 D_002C5AD0[];
extern u8 D_00621220[];
void func_001BA520(void);

void func_001BA4A8(void) {
    func_001BA520();
    *(A2S70 *)D_002C5AD0 = *(A2S70 *)D_00621220;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/gumi", func_001BA520);

extern s32 D_003772D0;

void func_001BA6F8(void) {
    D_003772D0 = 0;
}

extern u8 D_00621220[];
extern s32 D_00621300;
extern s32 D_00621308[][2];
void func_001BE820(void *, s32);
void func_0010FCE0(void);
void func_0010FCD0(void);

void func_001BA708(s32 x) {
    D_003772D0 = x;
    if (x) {
        func_001BE820(D_00621220, 0x70);
        D_00621300 = 0;
        D_00621308[0][0] = 0;
        D_00621308[0][1] = 0;
        D_00621308[1][0] = 0;
        D_00621308[1][1] = 0;
        func_0010FCE0();
    } else {
        func_0010FCD0();
    }
}

extern s32 D_00621300;

void func_001BA768(s32 x) {
    D_00621300 = x;
}

extern s32 D_00621308[][2];

void func_001BA778(s32 i, s32 a, s32 b) {
    D_00621308[i][0] = a;
    D_00621308[i][1] = b;
}

void func_001BE670(s32);

void func_001BA798(void) {
    D_003772D0 = 0;
    func_001BE670(0);
}

void *func_00112C70(void);

void func_001BA7B8(void) {
    func_00112C70();
}

extern s32 D_003772DC;

s32 func_001BA7D0(void) {
    return D_003772DC;
}

extern s32 D_003773EC;
extern s32 D_003772D4;
extern char D_0048FFF0[];
extern char D_00490000[];
int puts(const char *);
void func_001BA910(s32);

void func_001BA7E0(void) {
    D_003773EC = 1;
    D_003772DC = 1;
    func_001BA6F8();
    puts(D_0048FFF0);
    func_001B9C60(D_00490000);
    func_001BA910((s32)func_001BA7B8);
    D_003772D4++;
}

s32 func_001BA848(void) {
    return 0;
}

f32 func_001BA850(void) {
    return 0.0f;
}

f32 func_001BA860(void) {
    return 0.0f;
}

extern void *D_003773E0;
extern void *D_003773E4;
extern void *D_003773DC;
extern s32 D_003772D8;
extern char D_00490008[];
extern char D_00490018[];
void func_001C20B8(void);
void func_00236F18(void);

void func_001BA870(void) {
    D_003773EC = 1;
    D_003773DC = func_001BA848;
    D_003773E0 = func_001BA850;
    D_003773E4 = func_001BA860;
    D_003772DC = 2;
    func_001C20B8();
    func_00236F18();
    func_001BA6F8();
    puts(D_00490008);
    func_001B9C60(D_00490018);
    D_003772D8++;
}

extern s32 D_00621318;

void func_001BA910(s32 x) {
    D_00621318 = x;
}

s32 func_001BA920(void) {
    return D_00621318;
}

void func_001C2808(void *, s32, void *);

void func_001BA930(u8 *obj, s8 v) {
    s8 buf = v;
    func_001C2808(obj + 0x2F0, 1, &buf);
}

void func_001C2728(void *, s32, void *);

s8 func_001BA958(u8 *obj) {
    s8 buf;
    func_001C2728(obj + 0x2F0, 1, &buf);
    return buf;
}

void fm_func_001B9B30();
void *func_0022F768(s32);

s32 *func_001BA980(void) {
    fm_func_001B9B30();
    return (s32 *)((u8 *)func_0022F768(4) + 8);
}

void fm_func_001B9B30();
void *func_0022F768(s32);

void *func_001BA9A8(void) {
    fm_func_001B9B30();
    return (u8 *)func_0022F768(4) + 0x9A78;
}

void fm_func_001B9B30();
void *func_0022F768(s32);

void *func_001BA9D8(s32 i) {
    fm_func_001B9B30();
    return (u8 *)func_0022F768(4) + i * 0xF70 + 0x18;
}

void func_001BAA20(u8 *p) {
    s32 i;
    u8 *q = p + 7;

    *(s32 *)(p + 8) = 0;
    for (i = 7; i >= 0; i--) {
        *q-- = i;
    }
}

s32 *func_001BA980();

void func_001BAA58(u8 *src) {
    u8 *d = (u8 *)func_001BA980();
    s32 i;

    for (i = 0; i < 8; i++) {
        d[i] = src[i];
    }
}

s32 *func_001BA980();

void func_001BAAA8(s32 x) {
    func_001BA980()[2] = x;
}

s32 *func_001BA980();

s32 func_001BAAD0(void) {
    return func_001BA980()[2];
}

void func_001BAAF0(u8 *a0) {
    *(s32 *)(a0 + 0x9B40) = 0x4000;
    *(s32 *)(a0 + 0x9B44) = 0x8000;
    *(s32 *)(a0 + 0x9B48) = 0x400;
    *(s32 *)(a0 + 0x9B60) = 0x1000;
    *(s32 *)(a0 + 0x9B64) = 0;
    *(s32 *)(a0 + 0x9B4C) = 0x2000;
    *(s32 *)(a0 + 0x9B50) = 0x2000;
    *(s32 *)(a0 + 0x9B54) = 0x2000;
    *(s32 *)(a0 + 0x9B58) = 0x1000;
    /* The original assembler moved the last instruction of the `sw $7,0x9B5C($4)` macro (lui $1; addu $1,$1,$4;
     * sw) into the jr delay slot; ours never does, so this store is written with $at spelled out, after a barrier
     * so that nothing else can use $at in between. */
    __asm__ volatile("");
    {
        register u8 *at asm("$1") = a0 + 0x10000;
        *(s32 *)(at - 0x64A4) = 0x1000;
    }
}

extern char D_00490020[];
void func_001BE820(void *, s32);
void func_001BEF98(char *, char *);

void func_001BAB80(s32 n, u8 *p) {
    s32 i;

    for (i = 0; i < n; i++) {
        func_001BE820(p, 0xF70);
        func_001BEF98((char *)(p + 0x50), D_00490020);
        p += 0xF70;
    }
}

void func_001BABE8(void) {
    ((u8*)func_001BA9A8())[0x31]++;
    func_001BA930((u8*)0, 4);
    func_001BA930((u8*)1, 4);
    func_001BA930((u8*)2, 4);
    func_001BA930((u8*)3, 4);
    func_001BA930((u8*)4, 4);
    func_001BA930((u8*)5, 4);
    func_001BA930((u8*)6, 4);
    func_001BA930((u8*)7, 4);
    func_001BA930((u8*)8, 4);
    func_001BA930((u8*)9, 4);
    func_001BA930((u8*)10, 3);
    func_001BA930((u8*)11, 2);
    func_001BA930((u8*)12, 4);
    func_001BA930((u8*)13, 4);
    func_001BA930((u8*)14, 4);
    func_001BA930((u8*)15, 31);
    func_001BA930((u8*)16, 31);
    func_001BA930((u8*)17, 31);
    func_001BA930((u8*)18, 31);
    func_001BA930((u8*)19, 31);
    func_001BA930((u8*)20, 31);
    func_001BA930((u8*)21, 31);
    func_001BA930((u8*)22, 31);
    func_001BA930((u8*)23, 31);
    func_001BA930((u8*)24, 31);
    func_001BA930((u8*)34, -1);
    func_001BA930((u8*)35, -1);
    func_001BA930((u8*)36, -1);
    func_001BA930((u8*)37, -1);
    func_001BA930((u8*)38, -1);
}

typedef struct {
    u8 pad[0x9B38];
    s32 a;
    s32 b;
} A2Obj9B38;

s32 func_001BAD78(s32 i) {
    A2Obj9B38 *q = func_0022F768(4);

    switch (i) {
    case 0:
        return q->a;
    case 1:
        return q->b;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/gumi", func_001BADE8);
