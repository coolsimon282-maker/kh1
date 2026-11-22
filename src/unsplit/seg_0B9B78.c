// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0B9B78).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

extern s32 D_0037A148;
extern s32 D_0037A150;
extern s32 D_0037A154;
s32 func_001BB740(void);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9B78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9BB0);

double asin(double);

double func_001B9BF8(double x) {
    return asin(x);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9C10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9C60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9CB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9DF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001B9E40);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA2A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BC480);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA358);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA4A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA520);

extern s32 D_003772D0;

void func_001BA6F8(void) {
    D_003772D0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA708);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA7E0);

s32 func_001BA848(void) {
    return 0;
}

f32 func_001BA850(void) {
    return 0.0f;
}

f32 func_001BA860(void) {
    return 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA870);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BA9D8);

void func_001BAA20(u8 *p) {
    s32 i;
    u8 *q = p + 7;

    *(s32 *)(p + 8) = 0;
    for (i = 7; i >= 0; i--) {
        *q-- = i;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BAA58);

s32 *func_001BA980();

void func_001BAAA8(s32 x) {
    func_001BA980()[2] = x;
}

s32 *func_001BA980();

s32 func_001BAAD0(void) {
    return func_001BA980()[2];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BAAF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BAB80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BABE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BAD78);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB218);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB260);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB2E0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB370);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB438);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB500);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB678);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB7C8);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BB880);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBBD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBCE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBDF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BBF38);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BCD10);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD090);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD470);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD7F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD880);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BD9E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BDB58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE010);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE110);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE1E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE278);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE320);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE370);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE3C0);

extern s32 D_00625640;
void *func_001BA9D8(s32);
void func_001BB880(s32);
void func_001BD470(void);

void func_001BE430(s32 a0) {
    memset(func_001BA9D8(a0 - D_00625640), 0, 0xF70);
    func_001BB880(0);
    func_001BD470();
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE470);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE680);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE6C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE710);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE758);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE798);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE820);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE8A8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE988);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BE9F0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEA58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEBD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BECB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEDD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEE80);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEEF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEF40);

void func_001BEF98(char *d, char *s) {
    while (*s != 0) {
        *d++ = *s++;
    }
    *d = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BEFC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF048);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF3E8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF548);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF698);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF710);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0B9B78", func_001BF888);
