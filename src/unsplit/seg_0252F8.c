// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0252F8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001252F8);

extern u32 D_002C1EA8;
void func_001252F8(void);

void func_00125B40(s32 on) {
    if (on) {
        D_002C1EA8 |= 0x400000;
    } else {
        D_002C1EA8 &= ~0x400000;
    }
    func_001252F8();
}

typedef struct {
    u8 unk_00[0x70];
    s32 unk_70;
} Seg252F8Unk74;
extern Seg252F8Unk74* D_002E26A0;

s32 func_00125B90(s32 arg0) {
    Seg252F8Unk74* p = D_002E26A0;

    if ((arg0 & 1) && p->unk_70 != 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125BB8);

extern u32 D_002E3190;
s32 func_00130030(u8 *);
s32 func_00125B68(u8 *p) {
    if (((D_002E3190 >> 8) & 0xFFFF) == 0) {
        switch (*(s32 *)(p + 0x164)) {
        case 0x8A:
        case 0x3D:
            return 1;
        case 0xC8:
        case 0xCA:
            if (func_00130030(p) != 0) {
                return 1;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}

u8 *func_00130340(u8 *a0, s32 a1, f32 f);
u8 *func_00130578(u8 *a0, s32 a1, f32 f);
void func_001333E0(u8 *a0, s32 a1, s32 a2);
typedef struct {
    u8 unk_00[0xF0];
    f32 unk_F0;
} Seg252F8Unk3051EC;
extern Seg252F8Unk3051EC *D_003051EC;

void func_00125BE8(u8 *a0, s32 a1) {
    u8 *p = a0;

    switch (*(s32 *)(p + 0x70)) {
    case 2:
        func_00130340(a0, 0x100008A, 8.0f);
        func_00130578(p, 0x40000006, 0.0f);
        sceVu0ScaleVector((f32 *)(p + 0x3C0), (f32 *)(p + 0x3C0), D_003051EC->unk_F0);
        break;
    case 8:
        func_00130340(a0, 0x100008A, 8.0f);
        func_00130578(p, 0x40000075, 8.0f);
        sceVu0ScaleVector((f32 *)(p + 0x3C0), (f32 *)(p + 0x3C0), D_003051EC->unk_F0);
        break;
    default:
        func_00130340(p, 0x100003D, 8.0f);
        func_00130578(p, 0x40000000, 0.0f);
        break;
    }
    func_001333E0(p, 0, a1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125CF0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00125DC8);

extern f32 D_004F77F0;
extern f32 D_004F77F4;
extern f32 D_002E27CC;
extern f32 D_002E27D0;
extern u32 D_002DED20;
void sceVu0SubVector(f32 *, f32 *, f32 *);
f32 sceVu0InnerProduct(f32 *, f32 *);
void func_001223B0(f32 *, f32 *);

void func_00126108(u8 *a0, f32 *n, f32 *b, f32 d, f32 s, s32 *c) {
    sceVu0FVECTOR v;
    f32 t;

    sceVu0SubVector(v, b, (f32 *)(a0 + 0x10));
    v[1] = 0.0f;
    func_001223B0(v, v);
    v[3] = v[3] * s - d;
    t = sceVu0InnerProduct(v, n);
    if (D_004F77F4 < t) {
        if (v[3] < D_002E27D0) {
            c[14]++;
            if (v[3] < D_002E27CC) {
                c[13]++;
            }
        }
    } else if (D_004F77F0 < t) {
        if (v[3] < D_002E27CC) {
            c[11]++;
        }
    }
    if (D_002DED20 & 1) {
        c[10] = c[11];
    }
}

typedef struct { u64 lo : 12; u32 grp : 2; } Bf0252_A;
typedef struct { u64 lo : 37; u32 grp : 2; } Bf0252_B;
typedef struct { u64 lo : 10; u32 on : 1; } Bf0252_C;
f32 func_0012EC60_f(s32, s32, f32 *) __asm__("func_0012EC60");
s32 func_0012EE70(s32, s32);
s32 func_00123558(u8 *, s32);
u8 *func_0014A398(u8 *);

void func_00126238(u8 *a0, f32 *n, s32 *c) {
    sceVu0FVECTOR v;
    s32 i;
    s32 j;
    u8 *p;
    f32 f;

    i = 0;
    while ((i = func_00123558(a0, i)) != 0) {
        j = -1;
        while ((j = func_0012EE70(i, j)) >= 0) {
            f = func_0012EC60_f(i, j, v);
            func_00126108(a0, n, v, f, 1.0f, c);
        }
    }
    p = NULL;
    while ((p = func_0014A398(p)) != NULL) {
        if (((Bf0252_A *)p)->grp != ((Bf0252_B *)(a0 + 0x370))->grp && ((Bf0252_C *)(p + 0x30))->on) {
            func_00126108(a0, n, (f32 *)(p + 0x10), *(f32 *)(p + 0xC), 0.25f, c);
        }
    }
    n[3] = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126838);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_001269D8);

s32 func_001233F8(s32);
void func_0012ED88(u8 *, s32 *, f32 *, f32 *);
void sceVu0CopyVector(f32 *, f32 *);

void func_00126BA0(u8 *a, s32 *b, f32 *c) {
    f32 v[4];

    if (func_001233F8(*b) != 0) {
        func_0012ED88(a, b, v, c);
        c[1] = 0.0f;
    } else {
        sceVu0CopyVector(c, (f32 *)(a + 0x30));
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0252F8", func_00126C10);

void func_00126E80(a, b, c)
    u8* a;
    u8* b;
    f32* c;
{
    if (c[3] > 0.0f) {
        if (c[3] > 0.7999999523162842f) {
            c[3] = (*(f32**)(a + 0x6C))[2];
        } else {
            c[3] = (*(f32**)(a + 0x6C))[1];
        }
    } else {
        if (c[0] == 0.0f && c[2] == 0.0f) {
            sceVu0CopyVector(c, (f32*)(a + 0x20));
        }
        c[1] = 0.0f;
        c[3] = 0.0f;
    }
}

extern u32 D_002DED20;
extern s32 D_002E31B0;
typedef struct {
    void (*fn)(u8*, u8*, u8*);
    u8 pad[0x1C];
} S126F18;
extern S126F18 D_00350DA0[];
void func_00126E80();
void func_0014C580(u8*);
s32 func_0013DFB8(u8*, u8*);
s32 func_001443A8(u8*);
void func_0014CC88(u8*, f32);
void func_0013ECF8(u8*, s32*, u8*);
void func_0013DC10(u8*, s32);
void func_00137688(u8*, f32);
f32 func_001376E8(u8*, u8*);
void func_0015ABD0(u8*);

void func_00126F18(u8* a0, u8* a1, u8* a2) {
    s32 k;
    f32 t;
    s32 s;
    void (*fn)(u8*, u8*, u8*);

    switch (*(s32*)(a0 + 0x70)) {
    case 2:
        func_00126E80();
        if ((D_002DED20 >> 8) & 1) {
            if ((D_002E3190 >> 26) & 1) {
                func_0014C580(a0);
                return;
            }
        }
        break;
    case 4:
        func_00126E80();
        break;
    default:
        fn = D_00350DA0[*(s32*)(a0 + 0x70)].fn;
        if (fn != NULL) {
            fn(a0, a1, a2);
        }
        break;
    }
    if ((D_002E3190 >> 24) & 1) {
        do {
            func_0013DFB8(a0, a2);
        } while (0);
        return;
    }
    if (((D_002E3190 >> 26) & 1) && *(s32*)(a0 + 0x70) == 0 && func_001443A8(a0) == 0) {
        if (((D_002DED20 >> 4) & 1) && (!((D_002DED20 >> 5) & 1) || *(f32*)(a2 + 0xC) < *(f32*)(*(u8**)(a0 + 0x6C) + 8))) {
            func_0013ECF8(a0, &D_002E31B0, a2);
            func_0013DC10(a0, 0x3D);
            func_00130578(a0, 0x40000000, 0.0f);
            *(u8*)(*(u8**)(a0 + 0x14C) + 0x29) = 1;
        } else if ((D_002DED20 >> 5) & 1) {
            func_00137688(a0, func_001376E8(a0, a2));
            do {
                func_0015ABD0(a0);
            } while (0);
        }
        return;
    }
    k = *(s32*)a0;
    if (k & 0x40000) {
        t = *(f32*)(a0 + 0x3B0);
        if (*(f32*)(a0 + 0x3B8) <= t + 5.0f || *(s32*)(a0 + 0x70) != 2) {
            *(s32*)a0 = k & ~0x40000;
        } else if (k & 0x20000) {
            if (!(*(s32*)(a1 + 4) & 4)) {
                *(s32*)a0 = k & ~0x20000;
            }
        } else if (t >= 6.0f) {
            s = *(s32*)(a0 + 0x3D0);
            func_0014CC88(a0, 5.0f);
            *(s32*)(a0 + 0x3D0) = s;
            *(s32*)a0 &= ~0x40000;
        }
    }
}

extern u8 D_002C5BB0[];
extern u8 D_002E3190_b[] __asm__("D_002E3190");
extern u8 D_002C58A0[];
extern f32 D_004F7800[];
extern s32 (*D_002E27D4)(u8 *, u8 *, u8 *);
s32 func_00137618(u8 *);
void func_001251B0(u8 *, u8 *, u8 *);
void func_00126C10(u8 *, u8 *);
void func_001586A8(s32);
void sceVu0CopyVector(f32 *, f32 *);

void func_001271B0(u8 *a0, u8 *a1) {
    sceVu0FVECTOR v;
    u8 *p;
    s32 t;
    u8 *q;

    if (func_00137618(a0) != 0) {
        func_001251B0(a0, D_002C5BB0, a1);
        sceVu0CopyVector(D_004F7800, (f32 *)a1);
        if (D_002E27D4 != NULL) {
            if (D_002E27D4(a0, D_002C5BB0, a1) != 0) {
                func_00126F18(a0, D_002C5BB0, a1);
            }
        } else {
            func_00126F18(a0, D_002C5BB0, a1);
        }
    }
    if ((s8)D_002E3190_b[3] & 1) {
        t = *(s32 *)(a0 + 0x164);
        if (t == 7 || t == 12) {
            t = *(s32 *)(a0 + 0x70);
            if (t == 0 || t == 12) {
                *(s32 *)a0 &= ~4;
                sceVu0CopyVector(v, (f32 *)D_002C58A0);
                p = (u8 *)func_0013DFB8(a0, (u8 *)v);
                if (p != NULL) {
                    *(f32 *)(p + 4) = 2.0f;
                    *(f32 *)(a0 + 0x3B0) = 2.0f;
                }
            }
        }
    } else if (D_002E3190_b[0] != 0) {
        func_00126C10(a0, a1);
    }
    memset(D_002E3190_b, 0, 0xC);
    q = *(u8 **)(a0 + 0x14C);
    if (q != NULL) {
        q = *(u8 **)(q + 0x2C);
        if (q != NULL && (*(s32 *)(q + 4) & 1)) {
            func_001586A8(0xB);
        }
    }
}

#define D_003051EC ((u32 *)D_003051EC)
extern f32 D_002E27CC;
extern f32 D_002E27D0;
extern f32 D_004F77F0;
extern f32 D_004F77F4;
extern s32 D_004F7810;
float cosf(float);
s32 func_00147A10(s32);

void func_00127340(void) {
    D_002E27CC = D_003051EC[2];
    D_004F77F4 = cosf((D_003051EC[0] >> 1) / 180.0f * 0x1.921fb6p+1f);
    D_004F77F0 = cosf((D_003051EC[1] >> 1) / 180.0f * 0x1.921fb6p+1f);
    D_002E27D0 = D_003051EC[3];
    {
        s32 *r = &D_004F7810;
        *r = func_00147A10(0xA9F0);
    }
}
#undef D_003051EC
