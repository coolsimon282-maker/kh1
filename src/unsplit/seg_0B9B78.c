// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0B9B78).
// Functions can be matched here like in any other file; the file may be split later.
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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9CB0);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BC048);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9F78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA060);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA108);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA488);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA520);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BABE8);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BADE8);

s32 func_001BAF08(s32 *p) {
    s32 sum = 0;
    s32 i;

    for (i = 7; i >= 0; i--) {
        sum += *p++;
    }
    return sum;
}

s32 func_001BAF38(u8 *a) {
    s32 *p = (s32 *)(a + 8);
    s32 sum = 0;
    s32 i;

    for (i = 5; i >= 0; i--) {
        sum += *p++;
    }
    return sum;
}

s32 func_001BAF08(s32 *p);

s32 func_001BAF70(s32 a0, s32 *a, s32 *b) {
    return func_001BAF08(a) - func_001BAF08(b);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BAFB0);

void fm_func_001B9B30();
void *func_0022F768(s32);

u8 *func_001BB198(s32 i) {
    fm_func_001B9B30();
    return (u8 *)func_0022F768(4) + i * 64 + 0x9C20;
}

u8 *func_001BB1D8(s32 i) {
    fm_func_001B9B30();
    return (u8 *)func_0022F768(4) + i * 64 + 0xA420;
}

void fm_func_001B9B30();
void *func_0022F768(s32);

void func_001BB218(s32 i, s32 x) {
    fm_func_001B9B30();
    ((A2Big22F768 *)func_0022F768(4))->tblAC20[i] = x;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB260);

void *func_001BB260();
typedef struct {
    u8 pad[0xAC20];
    u8 f[1];
} A2BB2E0;

s32 func_001BB2E0(s32 k) {
    A2BB2E0 *p;
    fm_func_001B9B30();
    p = func_0022F768(4);
    if (p->f[k] == 0) {
        if (func_001BA958(func_001BB260(k)) >= 3) {
            p->f[k] = 1;
        }
    }
    return p->f[k];
}

typedef struct {
    u8 b[11];
} A2Bytes11;
extern A2Bytes11 D_004900A8;
s32 func_001BB2E0(s32);

s32 func_001BB370(void) {
    A2Bytes11 buf = D_004900A8;
    u8 *p = buf.b;

    while (*p != 0) {
        if (func_001BB2E0(*p++) < 4) {
            return 0;
        }
    }
    return 1;
}

void *func_001BB260();

s32 func_001BB3F8(void) {
    if (func_001BA958(func_001BB260()) < 3) {
        return 0;
    }
    return 1;
}

extern s32 D_0037A128;

void func_001BB428(s32 x) {
    D_0037A128 = x;
}

extern s32 D_0037A148;
extern s32 D_0037A14C;
extern s32 D_0037A150;
extern s32 D_0037A154;
s32 func_00112CB0(void);

void func_001BB438(void) {
    s32 *p = &D_0037A14C;
    s32 v;

    D_0037A154 = 0;
    v = func_00112CB0();
    *p = v;
    D_0037A150 = v;
    D_0037A148 = v;
}

extern s32 D_0037A150;
extern s32 D_0037A154;
extern s32 D_00623200[];

void func_001BB480(void) {
    s32 i = D_0037A154;

    D_00623200[i] = D_0037A150;
    D_0037A154 = i + 1;
}

void func_001BB4B0(void) {
    D_0037A150 = D_00623200[--D_0037A154];
}

extern s32 D_0037A150;

s32 func_001BB4E0(void) {
    return D_0037A150;
}

extern s32 D_0037A148;

s32 func_001BB4F0(void) {
    return D_0037A148 - 0x400;
}

u32 func_001BB780(u32 a, u32 b);

s32 func_001BB500(s32 a0, u32 a1) {
    s32* p = &D_0037A150;
    u32 v;

    *p -= a0;
    v = func_001BB780(*p, a1);
    *p = v;
    if (v < D_0037A148) {
        D_0037A148 = v;
    }
    return v;
}

extern u8 D_00378A48[];
extern u8 D_00379C78[];
void func_001EFB18(void *, void *);

void func_001BB558(void) {
    func_001EFB18(D_00378A48, D_00379C78);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB580);

extern A2Elem1C *D_0062321C;

A2Elem1C *func_001BB658(s32 i) {
    return &D_0062321C[i];
}

s32 func_001BC590(s32);

s32 func_001BB678(void) {
    s32 r = 6;

    if (func_001BC590(0x42) > 0) {
        r = 8;
    }
    if (func_001BC590(0x43) > 0) {
        r = 10;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB6D0);

extern s32 D_00623214;

s32 func_001BB720(void) {
    return D_00623214;
}

extern s32 D_00623218;

s32 func_001BB730(void) {
    return D_00623218;
}

extern s32 *D_00623210;

s32 func_001BB740(void) {
    return *D_00623210;
}

u32 func_001BB750(u32 a, u32 b) {
    if (a % b != 0) {
        a += b - a % b;
    }
    return a;
}

u32 func_001BB780(u32 a, u32 b) {
    if (a % b != 0) {
        a -= a % b;
    }
    return a;
}

extern s32 D_00623224;
extern s32 D_00623220;

void func_001BB7B0(s32 x) {
    D_00623224 = x;
    D_00623220 = 0;
}

void func_001C1680(void);

s32 func_001BB7C8(char *a, s32 b) {
    D_00623220 = 1;
    D_00623224 = -1;
    func_00120590(a, b, (void *)func_001BB7B0, 0);
    while (D_00623220 != 0) {
        func_001C1680();
    }
    return D_00623224;
}

extern s32 D_00623220;

s32 func_001BB848(void) {
    return D_00623220;
}

extern s32 D_002BC140;
extern s32 D_002BC144;

void func_001BB858(s32 a, s32 b) {
    D_002BC140 = a;
    D_002BC144 = b;
}

extern s32 D_006257D0;

void func_001BB870(s32 x) {
    D_006257D0 = x;
}

typedef struct { u8 pad0[4]; u16 n; u8 pad6[6]; u8 c; u8 padD[0xF63]; } BB880Inv;
void func_001BAAA8(s32);
void func_001BE820(void *, s32);

s32 func_001BB880_r(s32 a0) __asm__("func_001BB880");
s32 func_001BB880_r(s32 a0) {
    s32 map[16];
    s32 none;
    s32 idx[10];
    BB880Inv *p;
    BB880Inv *e;
    s32 i;
    s32 n;
    s32 r;
    s32 t;

    p = func_001BA9D8(0);
    none = -1;
    n = 0;
    for (i = 0; i < 10; i++) {
        if (p->n == 0) {
            map[i] = none;
        } else {
            map[i] = n++;
        }
        p++;
    }
    i = func_001BAAD0();
    if (i >= 0) {
        if (map[i] >= 0) {
            func_001BAAA8(map[i]);
        } else {
            func_001BAAA8(0);
        }
    }
    p = func_001BA9D8(0);
    for (i = 0; i < 10; i++) {
        if (p->n != 0 && p->c != 0) {
            p->c = map[p->c - 1] + 1;
        }
        p++;
    }
    if (D_006257D0 != 0) {
        p = (BB880Inv *)D_006257D0;
        if (p->n != 0 && p->c != 0) {
            p->c = map[p->c - 1] + 1;
        }
    }
    p = func_001BA9D8(0);
    n = 0;
    for (i = 0; i < 10; i++) {
        if (p[i].n != 0) {
            idx[n++] = i;
        }
    }
    for (i = 0; i < 10 && i < n; i++) {
        if (i != idx[i]) {
            p[i] = p[idx[i]];
        }
    }
    for (; i < 10; i++) {
        func_001BE820(&p[i], 0xF70);
    }
    p = func_001BA9D8(0);
    for (i = 0; i < 10; i++) {
        if (p->c != 0) {
            t = p->c - 1;
            if (t == i || ((BB880Inv *)func_001BA9D8(t))->c - 1 != i) {
                p->c = 0;
            }
        }
        p++;
    }
    return map[a0];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBBD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBCE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBDF0);

void func_001BBCE0(sceVu0FMATRIX, void *);
void func_001BBBD0(sceVu0FMATRIX, void *);

void func_001BBF38(sceVu0FMATRIX out, void *a1) {
    sceVu0FMATRIX m;

    func_001BBCE0(out, a1);
    func_001BBBD0(m, a1);
    sceVu0MulMatrix(out, out, m);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBF88);

extern s32 D_00625640;

s32 func_001BC4A8(void) {
    return D_00625640;
}

extern s32 D_00625648[];

s32 func_001BC4B8(s32 i) {
    return D_00625648[i];
}

extern u8 D_00623230[];

void *func_001BC4D0(void) {
    return D_00623230;
}

extern u8 D_00623E40[];

void *func_001BC4E0(void) {
    return D_00623E40;
}

extern u8 D_00625750[];

void *func_001BC4F0(void) {
    return D_00625750;
}

extern s32 D_00623228;

s32 func_001BC500(void) {
    return D_00623228;
}

extern s32 D_00623E30;

s32 func_001BC510(void) {
    return D_00623E30;
}

extern s32 D_00625748;

s32 func_001BC520(void) {
    return D_00625748;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BC530);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BC900);

typedef struct { u16 a; u16 b; u16 id; u16 c; u16 d; u16 e; } BCD10Ent;
typedef struct { u8 pad0[4]; u16 n; u8 pad6[0x6A]; BCD10Ent e[320]; } BCD10Inv;
s32 func_001BE6C8(void);
s32 func_001BE710(void);
s32 func_001BE680(void);
s32 func_001BCD10_r(BCD10Inv *dst, BCD10Inv *src) __asm__("func_001BCD10");

s32 func_001BCD10_r(BCD10Inv *dst, BCD10Inv *src) {
    s16 cnt[192];
    s32 i;
    s32 r;
    s32 ok;
    s32 k;
    s32 c;
    s32 n8;
    s32 n4;
    s32 total;
    s32 a4;
    s32 a8;

    for (i = 191; i >= 0; i--) {
        cnt[i] = 0;
    }
    *dst = *src;
    total = 0;
    dst->n = 0;
    n8 = 0;
    n4 = 0;
    r = 0;
    for (i = 0; i < src->n; i++) {
        if (src->e[i].id != 0) {
            ok = 1;
            k = src->e[i].id - 1;
            a8 = 0;
            a4 = 0;
            switch (k) {
            case 4 ... 8:
                if (n4 >= func_001BE6C8()) {
                    ok = 0;
                    r |= 4;
                }
                a4 = 1;
                break;
            case 0x3A ... 0x3F:
                if (n8 >= func_001BE710()) {
                    ok = 0;
                    r |= 8;
                }
                a8 = 1;
                break;
            }
            c = cnt[k];
            if (c >= func_001BC590(k)) {
                ok = 0;
                r |= 1;
            }
            if (total >= func_001BE680()) {
                ok = 0;
                r |= 2;
            }
            if (ok) {
                n4 += a4;
                n8 += a8;
                total++;
                cnt[k]++;
                dst->e[dst->n] = src->e[i];
                dst->n++;
            }
        }
    }
    return r;
}

extern u8 D_00621320[];
void func_001BA108(void *, s32);
void func_001BCD10(s32, void *);

void func_001BD010(s32 a) {
    s32 r = func_001BAAD0();

    if (!(r & 0x80)) {
        func_001BCD10(a, func_001BA9D8(r));
        return;
    }
    func_001BA108(D_00621320, r & 0x7F);
    func_001BCD10(a, D_00621320);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD470);

extern u8 D_00622290[];
extern void func_001BD880(u8 *);

void func_001BD7F8(s32 arg0) {
    s32 ret = func_001BC4A8();
    if (arg0 >= ret) {
        s32 ret2 = func_001BC4A8();
        func_001BCD10((s32) &D_00622290, func_001BA9D8(arg0 - ret2));
    } else {
        s32 tmp = func_001BC4B8(arg0);
        func_001BA108(D_00621320, tmp);
        func_001BCD10((s32) &D_00622290, D_00621320);
    }
    func_001BD880(&D_00622290);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD880);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD9E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BDB58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE110);

s32 func_001BE1E8(s32 a0, s32 a1) {
    if (a0 == 0) {
        a0 = D_006257D0;
    }
    func_001BE820((void *)a0, 0xF70);
    if (!(a1 & 0x80)) {
        if (a1 < 10) {
            func_001BCD10(D_006257D0, func_001BA9D8(a1));
        }
    } else {
        func_001BA108((void *)a0, a1 & 0x7F);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE278);

extern s32 D_00625640;
extern s32 D_00625648[];
void func_001BAAA8(s32);

void func_001BE320(s32 i) {
    if (i >= D_00625640) {
        func_001BAAA8(i - D_00625640);
    } else {
        func_001BAAA8(D_00625648[i] | 0x80);
    }
}

void func_001BE370(s32 i) {
    if (i >= D_00625640) {
        func_001BAAA8(i - D_00625640);
    } else {
        func_001BAAA8(D_00625648[i] | 0x80);
    }
}

extern u8 D_00623ED4[][0x60];

void func_001BE3C0(s32 i) {
    u8 *d = (u8 *)func_001BA9D8(i - D_00625640) + 0x50;
    s32 j;

    for (j = 0; j < 32; j++) {
        *d++ = D_00623ED4[i][j];
    }
}

extern s32 D_00625640;
void *func_001BA9D8(s32);
void func_001BB880(s32);
void func_001BD470(void);

void func_001BE430(s32 a0) {
    memset(func_001BA9D8(a0 - D_00625640), 0, 0xF70);
    func_001BB880(0);
    func_001BD470();
}

typedef struct {
    u8 a;
    s32 b;
} A2Pair;

void func_001BE470(void) {
    s32 i;

    for (i = 0; i < D_00625748; i++) {
        func_001B9E40(((A2Pair *)D_00625750)[i].a, ((A2Pair *)D_00625750)[i].b);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE4D8);

void func_001BD470(void);

void func_001BE5B0(void) {
    func_001BD470();
}

s32 func_001BE5C8(s32 x) {
    return x + 1;
}

s32 func_001BE5D0(s32 a0) {
    s32 t0 = func_001BB740();
    return ((a0 + t0) + 1);
}

s32 func_001BE600(s32 a0) {
    s32 t0 = func_001BB740();
    return ((a0 + (t0 << 1)) + 1);
}

s32 func_001BE630(s32 a0) {
    s32 t0 = func_001BB740();
    return ((a0 + (t0 << 1)) + 0xB);
}

extern s32 D_0037A158;

s32 func_001BE660(void) {
    return D_0037A158;
}

void func_001BE670(s32 x) {
    D_0037A158 = x;
}

s32 func_001BC590(s32);

s32 func_001BE680(void) {
    if (func_001BC590(0x46)) {
        return 200;
    }
    return func_001BC590(0x45) ? 150 : 100;
}

s32 func_001BE6C8(void) {
    if (func_001BC590(0x46)) {
        return 6;
    }
    return func_001BC590(0x45) ? 4 : 2;
}

s32 func_001BE710(void) {
    if (func_001BC590(0x46)) {
        return 10;
    }
    return func_001BC590(0x45) ? 6 : 4;
}

typedef unsigned int u128_stk __attribute__((mode(TI)));

typedef struct {
    u128_stk stk[16];
    s32 val[16];
    s32 cur;
    u128_stk *top;
    s32 n;
} A2Stk;

void func_001BE758(A2Stk *o, s32 a1, u128_stk a2) {
    s32 n = o->n;
    o->val[n] = a1;
    o->stk[n] = a2;
    o->cur = a1;
    o->top = &o->stk[o->n];
    o->n++;
}

void func_001BE798(A2Stk *o, u128_stk a1) {
    o->n--;
    o->stk[o->n - 1] = a1;
    o->cur = o->val[o->n - 1];
    o->top = &o->stk[o->n - 1];
}

typedef struct {
    u8 pad[0x140];
    void (*fn)(s32);
    s32 arg;
} A2CbObj;

void func_001BE7D8(A2CbObj *o) {
    o->fn(o->arg);
}

u32 func_001BE800(u32 a, u32 b) {
    return a + (b - a % b);
}

void func_001BE820(void *dst, s32 n) {
    u8 *p = dst;
    u32 k = (u32)p & 7;

    while (k != 0) {
        k--;
        *p++ = 0;
        n--;
    }
    while ((u32)n >= 8) {
        n -= 8;
        *(u64 *)p = 0;
        p += 8;
    }
    while (n != 0) {
        n--;
        *p++ = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE8A8);

void func_001BE988(f32 *dst, f32 *a, f32 *b, s32 num, s32 den) {
    f32 t = (f32)num / (f32)den;
    s32 i;

    for (i = 0; i < 4; i++) {
        dst[i] = (b[i] - a[i]) * t + a[i];
    }
}

void func_001BE9F0(f32 *v) {
    s32 i;

    for (i = 0; i < 4; i++, v++) {
        if (*v < -3.1415926f) {
            *v += 6.2831853f;
        }
        if (*v > 3.1415926f) {
            *v -= 6.2831853f;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEA58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEBD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BECB8);

f32 func_001BEDD0(f32* v) {
    f32 l = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

    if (l == 0.0f) {
        return l;
    }
    v[0] /= l;
    v[1] /= l;
    v[2] /= l;
    return l;
}

float sqrtf(float);

f32 func_001BEE80(f32 *a, f32 *b) {
    f32 d[4];

    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    return sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
}

f32 func_001BEEF8(f32 *p, f32 *q) {
    f32 d[3];

    d[0] = p[0] - q[0];
    d[1] = p[1] - q[1];
    d[2] = p[2] - q[2];
    return d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
}

void func_001BEF40(char *d, char *a, char *b) {
    while (*a != 0) {
        *d++ = *a++;
    }
    while (*b != 0) {
        *d++ = *b++;
    }
    *d = 0;
}

void func_001BEF98(char *d, char *s) {
    while (*s != 0) {
        *d++ = *s++;
    }
    *d = 0;
}

typedef struct {
    s32 key;
    f32 val;
} A2Key;

f32 func_001BEFC8(s32 x, A2Key *t) {
    f32 pv = 0.0f;
    s32 pk = 0;

    for (; t->key >= 0; t++) {
        if (x == t->key) {
            return t->val;
        }
        if (x < t->key) {
            return (t->val - pv) * ((f32)(x - pk) / (f32)(t->key - pk)) + pv;
        }
        pv = t->val;
        pk = t->key;
    }
    return 0.0f;
}

void func_001BF048(sceVu0FMATRIX dst, sceVu0FMATRIX src) {
    if (dst != src) {
        sceVu0CopyMatrix(dst, src);
    }
    dst[0][3] = 0.0f;
    dst[1][3] = 0.0f;
    dst[2][3] = 0.0f;
    dst[3][0] = 0.0f;
    dst[3][1] = 0.0f;
    dst[3][2] = 0.0f;
    dst[3][3] = 1.0f;
}

void func_001BF098(u8 *a0, u8 *a1) {
    *(f32 *)(a0 + 0x0) = *(f32 *)(a1 + 0x0);
    *(f32 *)(a0 + 0x4) = *(f32 *)(a1 + 0x4);
    *(f32 *)(a0 + 0x8) = *(f32 *)(a1 + 0x8);
    *(f32 *)(a0 + 0x10) = *(f32 *)(a1 + 0x10);
    *(f32 *)(a0 + 0x14) = *(f32 *)(a1 + 0x14);
    *(f32 *)(a0 + 0x18) = *(f32 *)(a1 + 0x18);
    *(f32 *)(a0 + 0x20) = *(f32 *)(a1 + 0x20);
    *(f32 *)(a0 + 0x24) = *(f32 *)(a1 + 0x24);
    *(f32 *)(a0 + 0x28) = *(f32 *)(a1 + 0x28);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF0E8);

typedef struct {
    f32 x, y, z, w;
} A2Vec4;

void func_001BF290(A2Vec4 *v) {
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
    v->w = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF2B0);

void func_001BF360(f32* d, f32* q) {
    f32 n = q[3] * q[3] + q[0] * q[0] + q[1] * q[1] + q[2] * q[2];

    d[0] = -q[0] / n;
    d[1] = -q[1] / n;
    d[2] = -q[2] / n;
    d[3] = q[3] / n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF3E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF548);

f32 sinf(f32);

void func_001BF698(f32 *q, f32 *axis, f32 angle) {
    f32 h = angle * 0.5f;
    f32 s;

    q[3] = cosf(h);
    s = sinf(h);
    q[0] = axis[0] * s;
    q[1] = axis[1] * s;
    q[2] = axis[2] * s;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF710);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF888);
