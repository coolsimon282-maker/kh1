/**
 * Event data files: the names opn.dat / end.dat / end2.dat / demo.dat (probably the opening, ending and demo data), the
 * last CD read status and error (sceCdGetError), and lookups of named entries in a loaded data block (func_002485C8;
 * the callers stop with a break instruction when an entry is missing). JP/EU: 0x248548-0x24A010, most of it still
 * assembly. Final Mix (#ifdef VERSION_FM): 0x24B9A8-0x24D4A0, functions paired with JP's by address order and size.
 */
#include "common.h"

#ifdef VERSION_FM
extern s32 D_0046A058[];
extern u8 D_004919B0[];
extern u8 D_004919E8[];
extern s32 D_0066AA84;
extern s32 _impure_ptr;
void abort(void);
void fiprintf(s32, u8 *, s32, s32, s32);
void func_00149E38(s32, u8 *);
void func_0024F008();
s32 sceCdGetError(void);
void sceDevctl(u8 *, s32, s32, s32, s32, s32);

s32 func_0024B9A8(s32 i) {
    return D_0046A058[i];
}
#else
s32 D_0046421C;
s32 D_0046423C;
s32 D_004642B8;

s32 D_00663A48;
s32 D_00663A4C;
s32 D_00663A50;
s32 D_00663A6C;
s32 D_00663A8C;

char* D_00463D48[4] = {"opn.dat", "end.dat", "end2.dat", "demo.dat"};

char* func_00248548(s32 idx) {
    return D_00463D48[idx];
}
#endif

#ifdef VERSION_FM
extern s32 D_00669A38;

s32 func_0024B9C0(void) {
    return D_00669A38;
}
#else
s32 func_00248560(void) {
    return D_00663A48;
}
#endif

#ifdef VERSION_FM
extern s32 D_00669A3C;

s32 func_0024B9D0(void) {
    return D_00669A3C;
}
#else
s32 func_00248570(void) {
    return D_00663A4C;
}
#endif

#ifdef VERSION_FM
void func_0024B9E0(s32 x) {
    D_00669A38 = x;
}
#else
void func_00248580(s32 arg0) {
    D_00663A48 = arg0;
}
#endif

#ifdef VERSION_FM
void func_0024B9F0(s32 x) {
    D_00669A3C = x;
}
#else
void func_00248590(s32 arg0) {
    D_00663A4C = arg0;
}
#endif

#ifdef VERSION_FM
void func_0024BA00(s32 a0) {
    s32 t0;
    D_00669A38 = a0;
    t0 = sceCdGetError();
    D_00669A3C = t0;
}
#else
void func_002485A0(s32 arg0) {
    D_00663A48 = arg0;
    D_00663A4C = sceCdGetError();
}
#endif

#ifdef VERSION_FM
extern s8 D_0046A070[];
unsigned int strlen(const char *);
int memcmp(const void *, const void *, unsigned int);

s32 func_0024BA28(s32 a0, s32 a1, s32 a2, void *a3) {
    s32 *p = (s32 *)a0;
    s32 nl = strlen((char *)a1);
    s32 len, w, type, cnt, sz, k;

    for (;;) {
        len = *p++;
        if (len == 0) {
            return -1;
        }
        w = (len + 3) / 4;
        if (nl == len && memcmp(p, (char *)a1, len) == 0) {
            u8 *src;
            u8 *d;

            p += w;
            type = *p++;
            cnt = *p++;
            sz = D_0046A070[type];
            if (a2 >= cnt) {
                return -1;
            }
            src = (u8 *)p + a2 * sz;
            d = a3;
            for (k = 0; k < sz; k++) {
                *d++ = *src++;
            }
            return type;
        }
        p += w;
        type = *p++;
        cnt = *p++;
        sz = D_0046A070[type];
        w = (sz * cnt + 3) / 4;
        p += w;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_002485C8);
#endif

#ifdef VERSION_FM
s32 func_0024BA28(s32, s32, s32, void *);

void func_0024BB88(s32 a0, s32 a1, f32 *a2) {
    f32 v;
    if (func_0024BA28(a0, a1, 0, &v) < 0) {
        __asm__ volatile("break 0");
    }
    *a2 = v;
}
#else
void func_00248728(s32* arg0, char* arg1, f32* arg2) {
    f32 local_20[4];

    if (func_002485C8(arg0, arg1, 0, local_20) < 0) {
        asm("break");
    }

    arg2[0] = local_20[0];
}
#endif

#ifdef VERSION_FM
s32 func_0024BA28(s32, s32, s32, void *);

void func_0024BBC8(s32 a0, s32 a1, s32 *a2) {
    s32 v;
    if (func_0024BA28(a0, a1, 0, &v) < 0) {
        __asm__ volatile("break 0");
    }
    *a2 = v;
}
#else
void func_00248768(s32* arg0, char* arg1, s32* arg2) {
    s32 local_20[4];

    if (func_002485C8(arg0, arg1, 0, local_20) < 0) {
        asm("break");
    }

    arg2[0] = local_20[0];
}
#endif

#ifdef VERSION_FM
typedef struct {
    void *ptr;
    s32 id;
} A2Ent;

void func_0024BC08(s32 a0, A2Ent *e) {
    while (e->ptr != 0) {
        if (func_0024BA28(a0, e->id, 0, e->ptr) < 0) {
            __asm__ volatile("break 0");
        }
        e++;
    }
}
#else
void func_002487A8(s32* arg0, s32* arg1) {
    while (*arg1 != NULL) {
        if (func_002485C8(arg0, arg1[1], 0, *arg1) < 0) {
            asm("break");
        }
        arg1 += 2;
    }
}
#endif

#ifdef VERSION_FM
typedef union {
    u32 w;
    struct {
        s16 lo;
        s16 hi;
    } s;
} A2Ent4;
extern s32 D_0046A540;
extern A2Ent4 *D_0046A568[];

s32 func_0024BC68(s32 a, s32 b) {
    A2Ent4 *e;

    for (e = D_0046A568[D_0046A540]; e->s.hi != -10; e++) {
        if (e->s.hi == -1 && a == ((e->w >> 4) & 0xF) && b == ((e->w >> 8) & 0xF)) {
            return 1;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248808);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xjockey", func_0024BCE8);
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248888);
#endif

#ifdef VERSION_FM
extern u32 D_002C5AD8;

u32 func_0024BE58(void) {
    u32 x = D_002C5AD8;
    return x | ((x >> 24) & 0xF0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_002489F8);
#endif

#ifdef VERSION_FM
extern u32 D_002C5AE0;

u32 func_0024BE70(void) {
    u32 x = D_002C5AE0;
    return x | ((x >> 24) & 0xF0);
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248A10);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xjockey", func_0024BE88);
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00248A28);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xjockey", func_0024C460);
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249000);
#endif

#ifdef VERSION_FM
/* rule 3: the target keeps $2 busy after the call (value-returning declaration) */
s32 func_001FADE0_r(s32, s32, s32, s32, s32, s32) __asm__("func_001FADE0");

void func_0024C8B8(s32 a0, s16 *p, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 i;
    for (i = 0; p[i] >= 0; i++) {
        func_001FADE0_r(a0, a2, a3, p[i], a4, a5);
        a2 += a4;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249458);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xjockey", func_0024C950);
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_002494F0);
#endif

#ifdef VERSION_FM
void func_0024CDE8(s16* dst, s32 a1) {
    u8* src = (u8*)a1;
    s32 i;
    u32 c;

    for (i = 0; src[i] != 0; i++) {
        c = src[i];
        if (c == 1) {
            c = 0;
        } else if (c - 0x20 < 0xE0) {
            c = c - 0x20;
        } else {
            if (c == 0x18) {
                c = src[i + 1];
                c -= 0x19;
                c <<= 8;
            } else {
                c -= 0x19;
                c <<= 8;
                c += src[i + 1];
            }
            c += 0xE0;
            i++;
        }
        *dst++ = c;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249958);
#endif

#ifdef VERSION_FM
void func_0024CE80(u8 *dst, s16 *src) {
    s32 i;
    s32 j = 0;
    s32 c;

    for (i = 0; i < 8 && (c = *src) >= 0; i++, src++) {
        if (c == 0) {
            c = 1;
        } else {
            c += 0x20;
            if (c >= 0x100) {
                c += 0x1800;
                dst[j++] = c >> 8;
            }
        }
        dst[j++] = c;
    }
    dst[j] = 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_002499F0);
#endif

#ifdef VERSION_FM
typedef struct {
    u8 pad[0x34];
    s8 name[0x2C];
} A2Ent60;
typedef struct {
    u8 pad[0x60];
    A2Ent60 ent[1];
} A2ObjBC4E0;
A2ObjBC4E0 *func_001BC4E0(void);
extern s32 D_00669A60;
extern s16 D_00669A40[];

void func_0024CF00(void) {
    A2Ent60 *e = &func_001BC4E0()->ent[D_00669A60];
    s32 i;

    for (i = 0; e->name[i] != 0; i++) {
        e->name[i] = 0;
    }
    func_0024CE80((u8 *)e->name, D_00669A40);
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249A70);
#endif

#ifdef VERSION_FM
extern s32 D_0046A5D8;

s32 func_0024CF80(void) {
    return D_0046A5D8;
}
#else
s32 func_00249AF0(void) {
    return D_004642B8;
}
#endif

#ifdef VERSION_FM
extern s32 D_00669A7C;

s32 func_0024CF90(void) {
    return D_00669A7C;
}
#else
s32 func_00249B00(void) {
    return D_00663A8C;
}
#endif

#ifdef VERSION_FM
void func_0024CFA0(s32 a0) {
    extern s32 D_0046A558;
    extern s32 D_0046A55C;
    extern s32 D_0046A560;
    extern s32 D_00669A64;
    extern void func_0024C460(s32);
    extern void func_0024BE88(s32);
    extern void func_0024C950(s32);
    extern void func_001F8F30(void);
    extern void func_0011D598(s32);
    extern s32 func_001F3840(s32);
    extern s32 func_001BE010(s32);
    extern void func_001BE3C0(s32);
    s32 i;

    func_0024C460(a0);
    func_0024BE88(a0);
    func_0024C950(a0);
    func_001F8F30();
    if (D_0046A558 != 0 && (func_0024BE58() & 0x2000) && D_0046A55C == 0) {
        D_0046A55C = 1;
        func_0011D598(2);
        func_001F3840(a0);
        D_0046A5D8 = 0;
        return;
    }
    if (!(func_0024BE58() & 0x2000)) {
        return;
    }
    if (D_0046A55C != 0) {
        return;
    }
    if (D_0046A560 == 0) {
        return;
    }
    i = 0;
    if (D_00669A40[0] == -1) {
        goto next;
    }
    if (D_00669A40[0] == 0) {
    next:
        i++;
    loop:
        if (i < 8) {
            if (D_00669A40[i] == -1) {
                goto next;
            }
            if (D_00669A40[i] == 0) {
                goto next;
            }
        }
    }
    if (i == 8) {
        func_0011D598(4);
        return;
    }
    D_0046A5D8 = 1;
    D_0046A55C = 1;
    func_0011D598(2);
    func_001F3840(a0);
    if (D_00669A60 < 0) {
        return;
    }
    func_0024CF00();
    if (D_00669A64 != 0) {
        D_00669A7C = func_001BE010(D_00669A60);
        return;
    }
    func_001BE3C0(D_00669A60);
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249B10);
#endif

#ifdef VERSION_FM
s32 func_001F40C8(void);
void func_001F82B0(void);
s32 func_001EAFD8(void);
void func_001BA2A8(s32, s32);
void func_00114430(void);
void func_001EFAF0(void);
extern s16 D_00669A40[];
extern s32 D_00669A5C;
extern s32 D_0046A53C;

s32 func_0024D138(void) {
    if (func_001F40C8()) {
        func_001F82B0();
        return 0;
    }
    func_0024CE80((u8 *)func_001EAFD8(), D_00669A40);
    if (D_00669A5C != 0) {
        func_001BA2A8(0, func_001EAFD8());
    }
    D_0046A53C = 1;
    func_00114430();
    func_001EFAF0();
    return 4;
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249CA8);
#endif

#ifdef VERSION_FM
INCLUDE_ASM("asm/nonmatchings/xjockey", func_0024D1C8);
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249D38);
#endif

#ifdef VERSION_FM
extern s32 D_0046A55C;

s32 func_0024D408(void) {
    return D_0046A55C;
}
#else
s32 func_00249F78(void) {
    return D_0046423C;
}
#endif

#ifdef VERSION_FM
s32 func_0024D138();
s32 func_001EAFD8(void);
void func_0024CDE8(s16 *, s32);
void func_0024D1C8(s16 *, s32, s32, s32);

void func_0024D418(void) {
    s16 buf[9];
    s32 i;

    func_0011ED30(0x2BFE8, func_0024D138);
    for (i = 0; i < 9; i++) {
        buf[i] = -1;
    }
    func_0024CDE8(buf, func_001EAFD8());
    func_0024D1C8(buf, -1, 0, 1);
}
#else
INCLUDE_ASM("asm/nonmatchings/xjockey", func_00249F88);
#endif

#ifdef VERSION_FM
extern s32 D_0046A53C;

s32 func_0024A000(void) {
    return D_0046A53C;
}
#else
s32 func_0024A000(void) {
    return D_0046421C;
}
#endif

#ifndef VERSION_FM
INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B458);

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B460);

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B478);

INCLUDE_RODATA("asm/nonmatchings/xjockey", D_0048B488);
#endif

#ifdef VERSION_FM
// .data (0x0046A050-0x0046A608)
typedef struct {
    s16 lo; // position code (row << 8 | column << 4 | kind?)
    s16 hi; // message id; -1 starts a row group, -10 ends the list
} XJockeyMenuEnt; // read through A2Ent4

#define DATA_LABEL(name, base, off) __asm__(".globl " #name "\n" #name " = " #base " + " #off)

extern char D_004918B8[];
extern char D_004918C8[];
extern char D_004918D8[];
extern char D_004918E8[];
extern char D_004918F8[];
extern char D_00491900[];
void func_001000C8();

void (*D_0046A050)() = (void (*)())func_0024D1C8; // nothing refers to it by name
s32 D_0046A058[6] = { // file names (.rodata), func_0024B9A8
    (s32)D_00491900, (s32)D_004918F8, (s32)D_004918E8, (s32)D_004918D8, (s32)D_004918C8, (s32)D_004918B8,
};
s8 D_0046A070[16] = {1, 2, 4, 4, 1, 2, 4, 4};
u8 D_0046A080[0x40] = { // message text (func_0024C460)
    0x19, 0x83, 0x1A, 0x68, 0xAC, 0xBD, 0x99, 0x92, 0x00, 0x2D, 0x19, 0x21, 0xEF, 0x19, 0x0D, 0x52,
    0x22, 0x1A, 0x08, 0x19, 0xF6, 0x9A, 0x97, 0xC4, 0xDE, 0x01, 0x39, 0x22, 0x51, 0x3F, 0x22, 0x19,
    0x21, 0xEF, 0x19, 0x0D, 0x52, 0x1A, 0x48, 0x19, 0x67, 0x1A, 0x08, 0x19, 0xF6, 0x96, 0xB7, 0x95,
    0x93, 0x00, 0x19, 0x83, 0x1A, 0x68, 0xBC, 0x1A, 0x48, 0x19, 0x67, 0x00, 0x00, 0x00, 0x00, 0x00,
};
s32 D_0046A0C0[2] = {0x90000, 0x32};
// five menu layouts (D_0046A568); the asm uses a word inside each by name
XJockeyMenuEnt D_0046A0C8[56] = {
    {0x0, -1}, {0x10, 0x70}, {0x20, 0x71}, {0x30, 0x72}, {0x40, 0x73}, {0x50, 0x74},
    {0x100, -1}, {0x110, 0x75}, {0x120, 0x76}, {0x130, 0x77}, {0x140, 0x78}, {0x150, 0x79},
    {0x200, -1}, {0x210, 0x7A}, {0x220, 0x7B}, {0x230, 0x7C}, {0x240, 0x7D}, {0x250, 0x7E},
    {0x300, 0x0}, {0x310, 0x7F}, {0x320, 0x80}, {0x330, 0x81}, {0x340, 0x82}, {0x350, 0x83},
    {0x400, 0x0}, {0x410, 0x84}, {0x420, 0x85}, {0x430, 0x86}, {0x440, 0x87}, {0x450, 0x88},
    {0x61, 0x89}, {0x71, 0x8A}, {0x81, 0x8B}, {0x91, 0x8C}, {0xA1, 0x8D}, {0x161, 0x8E},
    {0x171, 0x8F}, {0x181, 0x90}, {0x191, 0x91}, {0x1A1, 0x92}, {0x261, 0x93}, {0x271, 0x94},
    {0x281, 0x95}, {0x291, 0x0}, {0x2A1, 0x0}, {0x361, 0x96}, {0x371, 0x97}, {0x381, 0x98},
    {0x391, 0x99}, {0x3A1, 0x9A}, {0x461, 0x9B}, {0x471, 0x9C}, {0x481, 0x9D}, {0x491, 0x0},
    {0x4A1, 0x0}, {0x0, -10},
};
DATA_LABEL(D_0046A112, D_0046A0C8, 0x4A);
XJockeyMenuEnt D_0046A1A8[56] = {
    {0x0, -1}, {0x10, 0x9E}, {0x20, 0x9F}, {0x30, 0xA0}, {0x40, 0xA1}, {0x50, 0xA2},
    {0x100, -1}, {0x110, 0xA3}, {0x120, 0xA4}, {0x130, 0xA5}, {0x140, 0xA6}, {0x150, 0xA7},
    {0x200, -1}, {0x210, 0xA8}, {0x220, 0xA9}, {0x230, 0xAA}, {0x240, 0xAB}, {0x250, 0xAC},
    {0x300, 0x0}, {0x310, 0xAD}, {0x320, 0xAE}, {0x330, 0xAF}, {0x340, 0xB0}, {0x350, 0xB1},
    {0x400, 0x0}, {0x410, 0xB2}, {0x420, 0xB3}, {0x430, 0xB4}, {0x440, 0xB5}, {0x450, 0xB6},
    {0x61, 0xB7}, {0x71, 0xB8}, {0x81, 0xB9}, {0x91, 0xBA}, {0xA1, 0xBB}, {0x161, 0xBC},
    {0x171, 0xBD}, {0x181, 0xBE}, {0x191, 0xBF}, {0x1A1, 0x0}, {0x261, 0x0}, {0x271, 0x0},
    {0x281, 0x0}, {0x291, 0x0}, {0x2A1, 0x0}, {0x361, 0x0}, {0x371, 0x0}, {0x381, 0x0},
    {0x391, 0x0}, {0x3A1, 0x0}, {0x461, 0x0}, {0x471, 0x0}, {0x481, 0x0}, {0x491, 0x0},
    {0x4A1, 0x0}, {0x0, -10},
};
DATA_LABEL(D_0046A1F2, D_0046A1A8, 0x4A);
XJockeyMenuEnt D_0046A288[56] = {
    {0x0, -1}, {0x10, 0xC0}, {0x20, 0xC1}, {0x30, 0xC2}, {0x40, 0xC3}, {0x50, 0xC4},
    {0x100, -1}, {0x110, 0xC5}, {0x120, 0xC6}, {0x130, 0xC7}, {0x140, 0xC8}, {0x150, 0xC9},
    {0x200, -1}, {0x210, 0xCA}, {0x220, 0xCB}, {0x230, 0xCC}, {0x240, 0xCD}, {0x250, 0xCE},
    {0x300, 0x0}, {0x310, 0xCF}, {0x320, 0xD0}, {0x330, 0xD1}, {0x340, 0xD2}, {0x350, 0xD3},
    {0x400, 0x0}, {0x410, 0xD4}, {0x420, 0xD5}, {0x430, 0xD6}, {0x440, 0xD7}, {0x450, 0xD8},
    {0x61, 0xD9}, {0x71, 0xDA}, {0x81, 0xDB}, {0x91, 0xDC}, {0xA1, 0xDD}, {0x161, 0xDE},
    {0x171, 0xDF}, {0x181, 0xE0}, {0x191, 0xE1}, {0x1A1, 0xE2}, {0x261, 0xE3}, {0x271, 0xE4},
    {0x281, 0xE5}, {0x291, 0x0}, {0x2A1, 0x0}, {0x361, 0xE6}, {0x371, 0xE7}, {0x381, 0xE8},
    {0x391, 0xE9}, {0x3A1, 0xEA}, {0x461, 0xEB}, {0x471, 0xEC}, {0x481, 0xED}, {0x491, 0x0},
    {0x4A1, 0x0}, {0x0, -10},
};
DATA_LABEL(D_0046A2D2, D_0046A288, 0x4A);
XJockeyMenuEnt D_0046A368[56] = {
    {0x0, -1}, {0x10, 0xEE}, {0x20, 0xEF}, {0x30, 0xF0}, {0x40, 0xF1}, {0x50, 0xF2},
    {0x100, -1}, {0x110, 0xF3}, {0x120, 0xF4}, {0x130, 0xF5}, {0x140, 0xF6}, {0x150, 0xF7},
    {0x200, -1}, {0x210, 0xF8}, {0x220, 0xF9}, {0x230, 0xFA}, {0x240, 0xFB}, {0x250, 0xFC},
    {0x300, 0x0}, {0x310, 0xFD}, {0x320, 0xFE}, {0x330, 0xFF}, {0x340, 0x100}, {0x350, 0x101},
    {0x400, 0x0}, {0x410, 0x103}, {0x420, 0x104}, {0x430, 0x105}, {0x440, 0x106}, {0x450, 0x107},
    {0x61, 0x108}, {0x71, 0x109}, {0x81, 0x10A}, {0x91, 0x10B}, {0xA1, 0x10C}, {0x161, 0x10D},
    {0x171, 0x10E}, {0x181, 0x10F}, {0x191, 0x110}, {0x1A1, 0x102}, {0x261, 0x0}, {0x271, 0x0},
    {0x281, 0x0}, {0x291, 0x0}, {0x2A1, 0x0}, {0x361, 0x0}, {0x371, 0x0}, {0x381, 0x0},
    {0x391, 0x0}, {0x3A1, 0x0}, {0x461, 0x0}, {0x471, 0x0}, {0x481, 0x0}, {0x491, 0x0},
    {0x4A1, 0x0}, {0x0, -10},
};
DATA_LABEL(D_0046A3B2, D_0046A368, 0x4A);
XJockeyMenuEnt D_0046A448[61] = {
    {0x0, -1}, {0x10, 0xE}, {0x20, 0xF}, {0x30, 0x10}, {0x40, 0x11}, {0x50, 0x12},
    {0x60, 0x13}, {0x70, 0x14}, {0x80, 0x15}, {0x90, 0x16}, {0xA0, 0x17}, {0xB0, 0x18},
    {0x100, -1}, {0x110, 0x19}, {0x120, 0x1A}, {0x130, 0x1B}, {0x140, 0x1C}, {0x150, 0x1D},
    {0x160, 0x1E}, {0x170, 0x1F}, {0x180, 0x20}, {0x190, 0x21}, {0x1A0, 0x22}, {0x1B0, 0x23},
    {0x200, -1}, {0x210, 0x24}, {0x220, 0x25}, {0x230, 0x26}, {0x240, 0x27}, {0x250, 0x1},
    {0x260, 0x2}, {0x270, 0x3}, {0x280, 0x4}, {0x290, 0x5}, {0x2A0, 0x6}, {0x2B0, 0x7},
    {0x300, 0x0}, {0x310, 0x8}, {0x320, 0x9}, {0x330, 0xA}, {0x340, 0x28}, {0x350, 0x29},
    {0x360, 0x0}, {0x370, 0x2F}, {0x380, 0x30}, {0x390, 0x35}, {0x3A0, 0x36}, {0x3B0, 0x33},
    {0x400, 0x0}, {0x410, 0x31}, {0x420, 0x32}, {0x430, 0x37}, {0x440, 0x0}, {0x450, 0xB},
    {0x460, 0xC}, {0x470, 0x51}, {0x480, 0x2B}, {0x490, 0x2A}, {0x4A0, 0x0}, {0x4B0, 0x0},
    {0x0, -10},
};
DATA_LABEL(D_0046A4DA, D_0046A448, 0x92);
s32 D_0046A53C = 0;
s32 D_0046A540 = 0;
s32 D_0046A544 = 0;
s32 D_0046A548 = 0;
s32 D_0046A54C = 0;
s32 D_0046A550 = 0;
s32 D_0046A554 = 0;
s32 D_0046A558 = 0;
s32 D_0046A55C = 0;
s32 D_0046A560 = 0;
A2Ent4* D_0046A568[6] = {
    (A2Ent4*)D_0046A0C8, (A2Ent4*)D_0046A1A8, (A2Ent4*)D_0046A288, (A2Ent4*)D_0046A368,
    (A2Ent4*)D_0046A448, NULL,
};
s16 D_0046A580[4] = {0x70, 0x71, 0x72, -1};
s16 D_0046A588[4] = {0x9E, 0x9F, 0xA0, -1};
s16 D_0046A590[4] = {0xC0, 0xC1, 0xC2, -1};
s16 D_0046A598[4] = {0xEE, 0xEF, 0xF0, -1};
s16 D_0046A5A0[4] = {0xE, 0xF, 0x10, -1};
u32 D_0046A5A8[5] = {0x80000000, 0x80000000, 0x80784040, 0x80784040, 0x4CFFFFFF};
s32 D_0046A5BC = 20;
s16 D_0046A5C0[8] = {0xC6, 0x10D, 0xED, 0xCD, 0xE8, -1, 0x0, 0x0};
s16 D_0046A5D0[4] = {0x1C, 0x18, -1, 0x0};
s32 D_0046A5D8 = 0;
void* D_0046A5E0[10] = { // UI object descriptor
    (void*)func_0024CFA0, 0, (void*)0x0, 0, (void*)0x1C00200, (void*)0x280014, (void*)func_001000C8, (void*)0x10008,
    (void*)0x1, 0,
};
#endif
