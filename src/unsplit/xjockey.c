// Final Mix's version of xjockey (JP: src/xjockey.c, 0x248548-0x24A010; here 0x24B9A8-0x24D4A0).
// Split out of the placeholder seg_14B9A8; FM only (the JP/EU builds use src/xjockey.c).
#include "common.h"

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

extern s32 D_00669A38;

s32 func_0024B9C0(void) {
    return D_00669A38;
}

extern s32 D_00669A3C;

s32 func_0024B9D0(void) {
    return D_00669A3C;
}

void func_0024B9E0(s32 x) {
    D_00669A38 = x;
}

void func_0024B9F0(s32 x) {
    D_00669A3C = x;
}

void func_0024BA00(s32 a0) {
    s32 t0;
    D_00669A38 = a0;
    t0 = sceCdGetError();
    D_00669A3C = t0;
}

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

s32 func_0024BA28(s32, s32, s32, void *);

void func_0024BB88(s32 a0, s32 a1, f32 *a2) {
    f32 v;
    if (func_0024BA28(a0, a1, 0, &v) < 0) {
        __asm__ volatile("break 0");
    }
    *a2 = v;
}

s32 func_0024BA28(s32, s32, s32, void *);

void func_0024BBC8(s32 a0, s32 a1, s32 *a2) {
    s32 v;
    if (func_0024BA28(a0, a1, 0, &v) < 0) {
        __asm__ volatile("break 0");
    }
    *a2 = v;
}

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

INCLUDE_ASM("asm/nonmatchings/unsplit/xjockey", func_0024BCE8);

extern u32 D_002C5AD8;

u32 func_0024BE58(void) {
    u32 x = D_002C5AD8;
    return x | ((x >> 24) & 0xF0);
}

extern u32 D_002C5AE0;

u32 func_0024BE70(void) {
    u32 x = D_002C5AE0;
    return x | ((x >> 24) & 0xF0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xjockey", func_0024BE88);

INCLUDE_ASM("asm/nonmatchings/unsplit/xjockey", func_0024C460);

/* rule 3: the target keeps $2 busy after the call (value-returning declaration) */
s32 func_001FADE0_r(s32, s32, s32, s32, s32, s32) __asm__("func_001FADE0");

void func_0024C8B8(s32 a0, s16 *p, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 i;
    for (i = 0; p[i] >= 0; i++) {
        func_001FADE0_r(a0, a2, a3, p[i], a4, a5);
        a2 += a4;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/xjockey", func_0024C950);

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

extern s32 D_0046A5D8;

s32 func_0024CF80(void) {
    return D_0046A5D8;
}

extern s32 D_00669A7C;

s32 func_0024CF90(void) {
    return D_00669A7C;
}

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

INCLUDE_ASM("asm/nonmatchings/unsplit/xjockey", func_0024D1C8);

extern s32 D_0046A55C;

s32 func_0024D408(void) {
    return D_0046A55C;
}

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

extern s32 D_0046A53C;

s32 func_0024A000(void) {
    return D_0046A53C;
}
