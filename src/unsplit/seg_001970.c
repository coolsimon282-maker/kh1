// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x001970).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"
extern u8 D_002B8C70[];
void* func_0011EEB8(void*, s32, void*);
s32 func_00104298(f32*);
s32 func_00104388(f32*);
extern s32 D_002A3F28; extern s32 D_002B8678; extern s32 D_002B8680; extern s32 D_002B8684;
void func_00104528(void); void func_00104678(void);
s32 func_00103838(void);
s32 func_00103920(void);
extern s32 D_002A6208;
extern s32 D_00494894;
extern f32 D_002B8344;
extern s32 D_002A6204;
extern f32 D_00494898;
extern u64 D_002A6178;
extern f32 D_002B9040[][4];
extern s32 D_002A6230;
extern u16 D_002A62F8[];
void func_0011D1F8(s32, s32, s32);
typedef struct { u32 b0 : 4; u32 b4 : 4; u32 rest : 24; } Seg1970Bits;
s32 func_00142730(s32, s32*);
u8 func_0011AB60(s32, s32);
typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} Seg1970F0C;
extern Seg1970F0C* D_002A624C;
typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
} Seg1970Ent14;
extern s32 D_002BC090;
extern s32 D_002BC094;
extern s32 D_002BC0A0;
extern s32 D_002BC0A4;
extern u8 D_002A4160[];
extern u8 D_002A4180[];
extern s32 D_002A6294;
extern Seg1970Ent14* D_002A6274;
u8* func_0011AB38(s32, s32);

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    u8 unk_08[3];
    u8 unk_0B;
    f32 unk_0C;
    s32 unk_10;
} Seg1970Unk14;
typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
} Seg1970Unk10;
extern Seg1970Unk14* D_002A6238;
extern Seg1970Unk10* D_002A6254;
extern s32 D_002A6258;
extern f32 D_00494A74;
s32 func_00103C48(void);
extern f32 D_004948A0[];
extern s32 D_002A6B84;
void func_00121EB0(s32);
void sceDmaSend(s32, s32);
void iFlushCache(s32);
s32 func_0011A7F8(s32, s32, s32);
s32 func_00104AE0(s32, s32);
s32 func_0011A758(s32, s32, s32);
s32 func_00104CF8(s32, s32);
s32 func_0011EF58(s32*, s32);
extern s32 D_004945E0;
extern s32 D_00494878;
s32 func_00103058(void);
extern f32 D_002A6210[];
extern s32 D_002A6220[];
s32 func_001032B0(void);
extern s32 D_002B8C84;
extern s32 D_00494890;
extern s32 D_002B8C88;
extern f32 D_00494A70;
extern s32 D_002A6308[];
extern s32 D_002A6318[];
extern s32 D_002A6324;
extern sceVu0FVECTOR* D_002A3F48;
s32 func_001F0EF0(s32);
void func_001F1ED8(s32, s32, s32, s32, s32);

void func_00101970(s32 a0, s32* a1, s32 a2) {
    s32* q = a1 + 4;
    q[3] = 0;
    q[2] = 0;
    a1[3] = 0;
    a1[2] = 0;
    if (a0 == 0) {
        a1[0] = 0x30000002;
        a1[1] = (s32)D_002A4160;
        q[0] = 4;
    } else {
        a1[0] = 0x30000002;
        a1[1] = (s32)D_002A4180;
        q[0] = 8;
    }
    a1[5] = a2;
}

s32 func_001019C8(u8* t) {
    iFlushCache(0);
    sceDmaSend(D_002A6B84, *(s32*)(t + 0x10));
    func_00121EB0(*(s32*)(t + 0x10));
    func_00121EB0(*(s32*)(t + 0x14));
    return 2;
}

void func_00101A18(u8* a0, u8 a1, u64* a2) {
    a2[0] = *(u64*)(a0 + 0x10);
    a2[1] = 0x50;
    *(s32*)&a2[2] = *(s32*)(a0 + 0x20 + a1 * 4);
    *((s32*)&a2[2] + 1) = *(s32*)(a0 + 4);
    a2[3] = 0x51;
    a2[4] = *(u64*)(a0 + 0x18);
    a2[5] = 0x52;
    a2[6] = 2;
    a2[7] = 0x53;
}

#define H(o) (*(u16 *)(a0 + (o)))
void func_00101A70(u8 *a0, s32 a1, s32 a2, u64 *a3) {
    s32 r = a1 % a2;
    s32 q = (a2 - a1) % a2;

    a3[2] = (u64)H(0x20) | ((u64)(H(0x22) + r) << 16) | ((u64)H(0x4) << 32) | ((u64)H(0x6) << 48);
    a3[4] = (u64)*(s32 *)(a0 + 0x18) | ((u64)q << 32);
    a3[0] = *(u64 *)(a0 + 0x10);
    a3[1] = 0x50;
    a3[3] = 0x51;
    a3[5] = 0x52;
    a3[6] = 2;
    a3[7] = 0x53;
    if (a1 != 0) {
        a3[10] = (u64)H(0x20) | ((u64)H(0x22) << 16) | ((u64)H(0x4) << 32) | ((u64)(H(0x6) + q) << 48);
        a3[12] = (u64)*(s32 *)(a0 + 0x18) | ((u64)a1 << 32);
    } else {
        a3[10] = (u64)H(0x20) | ((u64)(H(0x22) + r) << 16) | ((u64)H(0x4) << 32) | ((u64)H(0x6) << 48);
        a3[12] = (u64)*(s32 *)(a0 + 0x18) | ((u64)q << 32);
    }
    a3[8] = *(u64 *)(a0 + 0x10);
    a3[9] = 0x50;
    a3[11] = 0x51;
    a3[13] = 0x52;
    a3[14] = 2;
    a3[15] = 0x53;
}
#undef H

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00101BB8);

extern s32 D_00494420;
extern s32 D_002A3F20;
void func_00101BB8();
void func_00101E70(void) {
    s32 i;
    u8* r;

    func_0011EDD0(&D_004945E0, &D_00494420, 0x1C, 0x10);
    for (i = 0; i < D_002A3F20; i++) {
        r = func_0011EEB8(&D_004945E0, 0x1D4C0, func_00101BB8);
        if (r != NULL) {
            r[0x10] = 0;
            r[0x11] = i;
        }
    }
}

void func_00101E18(void) {
    func_0011EF58(&D_004945E0, 0);
}

s32 func_00101F30(u8* t) {
    iFlushCache(0);
    sceDmaSend(D_002A6B84, *(s32*)(t + 0x10));
    func_00121EB0(*(s32*)(t + 0x10));
    func_00121EB0(*(s32*)(t + 0x14));
    return 2;
}

s32 func_00101F80(u8* t) {
    iFlushCache(0);
    sceDmaSend(D_002A6B84, *(s32*)(t + 0x10));
    func_00121EB0(*(s32*)(t + 0x10));
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00101FC8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00102070);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00102118);

extern s32 D_004945F8;
extern s32 D_002A3F24;
void TaskList_Init(s32*, s32*, s32, s32);
u8* TaskList_Add(s32*, s32, void*);
s32 func_00102118();
void func_00102978(void) {
    s32 i;
    u8* t;

    TaskList_Init(&D_00494878, &D_004945F8, 0x28, 0x10);
    for (i = 0; i < D_002A3F24; i++) {
        t = TaskList_Add(&D_00494878, 120000, func_00102118);
        if (t != NULL) {
            t[0x1D] = i;
            t[0x1C] = 0;
            t[0x1E] = 1;
        }
    }
}

void func_00102950(void) {
    func_0011EF58(&D_00494878, 0);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00102970);

void func_00102CC8(s32* a0, s32* a1, s32* a2, s32* a3) {
    s32 a = D_002BC0A0;
    s32 b = D_002BC090;
    s32 c = D_002BC0A4;
    s32 d = D_002BC094;
    s32 x = (b + a) << 4;
    s32 y = (d + c) << 4;
    *a0 = x - 0x1000;
    *a1 = x + 0x1000;
    *a2 = y - 0xC00;
    *a3 = y + 0xC00;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00102D20);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00102DA8);

s32 func_00103058(void) {
    extern s32 D_002A2748;
    extern s32 D_002A2744;
    extern struct {
        u8 pad[0x28];
        struct {
            u64 a;
            u64 p0;
            u64 b;
            u64 p1[3];
        } e[9];
    } D_002A5430;
    extern struct {
        u8 pad[0x20];
        u64 a;
        u64 b;
    } D_002A52B0;
    extern u8 D_002A5620[];
    extern u8 D_002A5AC0[];
    extern u8 D_002A5A90[];
    u64 h = (u64)D_002A2748 << 32;

    D_002A5430.e[0].a = h | 0x73E06FE0U;
    D_002A5430.e[0].b = h | 0x8BE08FE0U;
    D_002A5430.e[1].a = h | 0x73C06FC0U;
    D_002A5430.e[1].b = h | 0x8BC08FC0U;
    D_002A5430.e[2].a = h | 0x74007000U;
    D_002A5430.e[2].b = h | 0x8C009000U;
    D_002A5430.e[3].a = h | 0x74006FC0U;
    D_002A5430.e[3].b = h | 0x8C008FC0U;
    D_002A5430.e[4].a = h | 0x73C07000U;
    D_002A5430.e[4].b = h | 0x8BC09000U;
    D_002A5430.e[5].a = h | 0x73C06FE0U;
    D_002A5430.e[5].b = h | 0x8BC08FE0U;
    D_002A5430.e[6].a = h | 0x73E06FC0U;
    D_002A5430.e[6].b = h | 0x8BE08FC0U;
    D_002A5430.e[7].a = h | 0x74006FE0U;
    D_002A5430.e[7].b = h | 0x8C008FE0U;
    D_002A5430.e[8].a = h | 0x73E07000U;
    D_002A5430.e[8].b = h | 0x8BE09000U;
    if (D_002A2744 != 0) {
        D_002A52B0.a = h | 0x74007000U;
        D_002A52B0.b = h | 0x8C009000U;
        func_00106948(D_002A5620);
        func_00106948(D_002A5AC0);
    } else {
        func_00106948(D_002A5A90);
        func_00106948(D_002A5AC0);
    }
    return 4;
}

void func_00103130(void) {
    func_0011ED30(0x280A2, func_00103058);
}

void func_00103280(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_002A6210[0] = arg0;
    D_002A6210[1] = arg1;
    D_002A6210[2] = arg2;
    D_002A6210[3] = arg3;
    D_002A6220[0] = 0;
    D_002A6220[1] = 0;
    D_002A6220[2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_001032B0);

void func_001036F0(void) {
    func_0011ED30(0x280A4, func_001032B0);
}

void func_00103810(void) {
    D_002B8C84 = 1;
    D_00494890 = 0;
}

void func_00103730(void) {
    D_002B8C84 = 0;
}

s32 func_00103838(void) {
    s32 i = (f32)D_00494894 - D_002B8344;
    D_00494894 = i;
    if (i <= 0) {
        D_002A6204 = 0xFF;
        return 4;
    }
    D_002A6204 = 255.0f - D_00494898 * i;
    return 0;
}

void func_001037C8(s32 a0) {
    func_0011ED30(0x280A2, func_00103838);
    D_00494894 = a0 * 2;
    if (a0 == 0) a0 = 1;
    D_00494898 = 255.0f / (f32)(a0 * 2);
}

s32 func_00103920(void) {
    s32 i = (f32)D_00494894 - D_002B8344;
    D_00494894 = i;
    if (i <= 0) {
        D_002A6204 = 0;
        return 4;
    }
    D_002A6204 = D_00494898 * i;
    return 0;
}

void func_00103988(s32 a0) {
    func_0011ED30(0x280A2, func_00103920);
    D_00494894 = a0 * 2;
    if (a0 == 0) a0 = 1;
    D_00494898 = 255.0f / (f32)(a0 * 2);
}

extern s32 D_002A61F0;
extern u64 D_002A6058;
extern u8 D_002A6070[];
void func_00106948(void *);
s32 func_001039F8(void) {
    if (D_002A6204 != 0) {
        if (D_002A61F0 == 0) {
            D_002A6058 = ((u64)D_002A6204 << 24) | 0x100000000;
        } else {
            D_002A6058 = ((u64)D_002A6204 << 24) | 0x100FFFFFF;
        }
        func_00106948(D_002A6070);
    }
    return 0;
}

extern s32 D_0048CAE0[];
extern s32 D_0048CB28[];
extern s32 D_0048CB70[];
extern s32 D_0048CBB8[];
extern s32 D_004948B0[][4];
extern s32 D_004948F0[][4];
extern s32 D_00494930[][4];
extern s32 D_00494970[][4];

void func_00103A70(void) {
    s32 i, j, k;

    k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            D_0048CBB8[k] = D_00494930[i][j];
            D_0048CB70[k] = D_00494970[i][j];
            D_0048CB28[k] = D_004948B0[i][j];
            D_0048CAE0[k] = D_004948F0[i][j];
            k++;
        }
    }
}

void func_00103B68(sceVu0FMATRIX out, sceVu0FVECTOR a1, sceVu0FVECTOR a2, sceVu0FVECTOR a3, f32 *rot) {
    sceVu0FMATRIX m;
    sceVu0FVECTOR v0;
    sceVu0FVECTOR v1;
    sceVu0FVECTOR v2;

    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, rot[0]);
    sceVu0RotMatrixY(m, m, rot[1]);
    sceVu0RotMatrixZ(m, m, rot[2]);
    sceVu0ApplyMatrix(v0, m, a2);
    sceVu0ApplyMatrix(v1, m, a3);
    sceVu0ApplyMatrix(v2, m, a1);
    sceVu0CameraMatrix(out, v2, v0, v1);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00103C48);

void func_00104110(void) {
    D_004948A0[0] = D_004948A0[1] = D_004948A0[3] = 0.0f;
    D_004948A0[2] = D_00494A74;
    func_0011ED30(0x280A4, func_00103C48);
}

void func_00104268(f32 arg0, f32 arg1) {
    D_002B8C88 = 1;
    D_00494A70 = arg0;
    D_00494A74 = arg1;
}

void func_00104178(void) {
    D_002B8C88 = 0;
}

s32 func_00104298(f32* a0) {
    f32 f = a0[4] - D_002B8344;
    a0[4] = f;
    if (f <= 0.0f) {
        D_002A6178 = (u64)1 << 32;
        return 4;
    }
    D_002A6178 = ((s64)(s32)(a0[5] * f) << 24) | ((u64)1 << 32);
    return 0;
}

void func_00104200(s32 n) {
    u8* r;
    D_002A6208 = 1;
    r = func_0011EEB8(D_002B8C70, 0, func_00104298);
    if (r != NULL) {
        *(f32*)(r + 0x10) = n * 2;
        if (n == 0) {
            n = 1;
        }
        *(f32*)(r + 0x14) = 128.0f / (n * 2);
    }
}

s32 func_00104388(f32* a0) {
    f32 f = a0[4] + D_002B8344;
    a0[4] = f;
    if (a0[6] <= f) {
        D_002A6208 = 0;
        D_002A6178 = (u64)3 << 31;
        return 4;
    }
    D_002A6178 = ((s64)(s32)(a0[5] * f) << 24) | ((u64)1 << 32);
    return 0;
}

void func_00104310(s32 n) {
    u8* r;
    s32 d;
    r = func_0011EEB8(D_002B8C70, 0, func_00104388);
    d = n * 2;
    if (n == 0) {
        n = 1;
    }
    n *= 2;
    if (r != NULL) {
        D_002A6208 = 1;
        *(s32*)(r + 0x10) = 0;
        *(f32*)(r + 0x18) = d;
        *(f32*)(r + 0x14) = 128.0f / n;
    }
}

void func_001043A0(s32 arg0, s32* arg1) {
    sceVu0UnitMatrix((sceVu0FVECTOR*)arg1);
    arg1[0x18] = arg0;
}

void func_001044B8(s32 arg0, s32* arg1) {
    arg1[0x18] = arg0;
}

void func_001043E0(u8* a0) {
    sceVu0RotMatrix((void*)a0, D_002B9040, (void*)(a0 + 0x40));
    sceVu0TransMatrix((void*)a0, (void*)a0, (void*)(a0 + 0x50));
    if (*(s32*)(a0 + 0x60) != -1) {
        sceVu0MulMatrix((void*)a0, (void*)*(s32*)(a0 + 0x60), (void*)a0);
    }
}

extern s32 D_002A6234_s __asm__("D_002A6234");
extern s32 D_002A623C;
extern s32 D_002A6240;
extern s32 D_002A6244;
extern s32 D_002A6248;
extern s32 D_002A6250;
extern s32 D_002A625C;
extern s32 D_002A6260;
extern s32 D_002A6264;
extern s32 D_002A6268;
extern s32 D_002A626C;
extern s32 D_002A6270;
extern s32 D_002A6278;
extern s32 D_002A627C;
extern s32 D_002A6280;
extern s32 D_002A6284;
extern s32 D_002A6288;
extern s32 D_002A628C;
extern s32 D_002A6290;
extern s32 D_002A6298;
extern s32 D_002A629C;
extern s32 D_002A62A0;
extern s32 D_002A62A4;
extern s32 D_002A62A8;
extern s32 D_002A62EC;

void func_00104528(void) {
    D_002A6234_s = D_002A6270;
    D_002A6238 = (Seg1970Unk14*)D_002A6274;
    D_002A623C = D_002A6278;
    D_002A6240 = D_002A627C;
    D_002A6244 = D_002A6280;
    D_002A6248 = D_002A6284;
    D_002A624C = (Seg1970F0C*)D_002A6288;
    D_002A6250 = D_002A628C;
    D_002A6254 = (Seg1970Unk10*)D_002A6290;
    D_002A6258 = D_002A6294;
    D_002A625C = D_002A6298;
    D_002A6260 = D_002A629C;
    D_002A6264 = D_002A62A0;
    D_002A6268 = D_002A62A4;
    D_002A626C = D_002A62A8;
    D_002A62EC = 0;
}

extern s32 D_002A6234_s __asm__("D_002A6234");
extern s32 D_002A62AC;
extern Seg1970Unk14* D_002A62B0;
extern s32 D_002A62B4;
extern s32 D_002A62B8;
extern s32 D_002A62BC;
extern s32 D_002A62C0;
extern s32 D_002A62C4;
extern s32 D_002A62C8;
extern s32 D_002A62CC;
extern s32 D_002A62D0;
extern s32 D_002A62D4;
extern s32 D_002A62D8;
extern s32 D_002A62DC;
extern s32 D_002A62E0;
extern s32 D_002A62E4;

void func_00104678(void) {
    D_002A6234_s = D_002A62AC;
    D_002A6238 = D_002A62B0;
    D_002A623C = D_002A62B4;
    D_002A6240 = D_002A62B8;
    D_002A6244 = D_002A62BC;
    D_002A6248 = D_002A62C0;
    D_002A624C = (Seg1970F0C*)D_002A62C4;
    D_002A6250 = D_002A62C8;
    D_002A6254 = (Seg1970Unk10*)D_002A62CC;
    D_002A6258 = D_002A62D0;
    D_002A625C = D_002A62D4;
    D_002A6260 = D_002A62D8;
    D_002A6264 = D_002A62DC;
    D_002A6268 = D_002A62E0;
    D_002A626C = D_002A62E4;
    D_002A62EC = 1;
}

void func_001047C8(void) {
    if (D_002A3F28 != 0) {
        if (D_002B8678 == 15 && D_002B8680 == 12 && (D_002B8684 == 24 || D_002B8684 == 2)) {
            func_00104528();
            return;
        }
        func_00104678();
    } else {
        func_00104528();
    }
}

typedef struct {
    /* 0x00 */ f32 x0;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 sx;
    /* 0x0C */ s32 nx;
    /* 0x10 */ u8 unk_10[0x10];
    /* 0x20 */ f32 z0;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 sz;
    /* 0x2C */ s32 nz;
} Grid104850;
extern Grid104850* D_002A6234;

void func_00104850(f32* pos, s32* out) {
    f32 x = pos[0];
    f32 z = pos[2];

    out[0] = (x - D_002A6234->x0) / D_002A6234->sx;
    out[2] = (z - D_002A6234->z0) / D_002A6234->sz;
    if (out[0] < 0) {
        out[0] = 0;
    } else if (out[0] >= D_002A6234->nx) {
        out[0] = D_002A6234->nx - 1;
    }
    if (out[2] < 0) {
        out[2] = 0;
    } else if (out[2] >= D_002A6234->nz) {
        out[2] = D_002A6234->nz - 1;
    }
}

void func_00104908(void) {
    D_002A6318[0] = D_002A6318[1] = D_002A6318[2] = D_002A6308[0] = D_002A6308[1] = D_002A6308[2] = -1;
    D_002A6324 = 0;
}

s32 func_00104940(f32 *a0, s32 *out) {
    s32 hi[4];
    s32 lo[4];
    s32 n;
    s32 x, z;

    func_00104850(a0, lo);
    func_00104850(a0 + 3, hi);
    if (D_002A6324 == (s32)D_002A6234 && D_002A6308[0] == hi[0] && D_002A6308[2] == hi[2] &&
        D_002A6318[0] == lo[0] && D_002A6318[2] == lo[2]) {
        return -1;
    }
    n = 0;
    for (x = lo[0]; x < hi[0] + 1; x++) {
        for (z = lo[2]; z < hi[2] + 1; z++) {
            *out++ = x * D_002A6234->nz + z;
            n++;
        }
    }
    D_002A6308[0] = hi[0];
    D_002A6308[2] = hi[2];
    D_002A6318[0] = lo[0];
    D_002A6318[2] = lo[2];
    D_002A6324 = (s32)D_002A6234;
    return n;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00104A90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00104AE0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00104AA8);

void func_00104EB0(s32 a0, f32* a1) {
    Seg1970F0C* p = &D_002A624C[D_002A6238[a0].unk_00];
    a1[0] = p->unk_00;
    a1[1] = p->unk_04;
    a1[2] = p->unk_08;
    a1[3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00104CF8);

void func_00104FA8(s32 arg0, f32* arg1) {
    *arg1 = D_002A6238[arg0].unk_0C;
}

void func_00104FD0(s32 a0, f32* a1) {
    a1[0] = D_002A6254[a0].unk_04;
    a1[1] = D_002A6254[a0].unk_08;
    a1[2] = D_002A6254[a0].unk_0C;
    a1[3] = 1.0f;
}

s32 func_00105020(void) {
    s32 i;
    for (i = 0; i < D_002A6294; i++) {
        if ((D_002A6274[i].unk_10 & 0xF6) == 0x50) return 1;
    }
    return 0;
}

s32 func_00105078(void) {
    s32 i;
    for (i = 0; i < D_002A6294; i++) {
        if ((D_002A6274[i].unk_10 & 0xF6) == 0x90) return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_001050D0);

void func_00105218(void) {
    s32 i;
    for (i = 0; i < D_002A6230; i++) {
        func_0011D1F8(D_002A62F8[i], i, 0x3C0);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00105288);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_001054D0);

void func_00105510(s32 a0, s32 a1) {
    s32 n = D_002A6258;
    Seg1970Unk14* p;
    if (n > 0) {
        p = D_002A6238;
        do {
            if (p->unk_0B == a0) p->unk_10 = (p->unk_10 & ~0xF0) | ((a1 & 0xF) << 4);
            p++;
        } while (--n);
    }
}

void func_00105560(s32 a0, s32 a1) {
    s32 n = D_002A6258;
    Seg1970Unk14* p;
    if (n > 0) {
        p = D_002A6238;
        do {
            if (p->unk_0B == a0) p->unk_10 = (p->unk_10 & ~0x3C0000) | ((a1 & 0xF) << 18);
            p++;
        } while (--n);
    }
}

extern Seg1970Unk14* D_002A62B0;
extern s32 D_002A62D0;
typedef struct {
    u8 unk_00[0xB];
    u8 unk_0B;
    f32 unk_0C;
    u32 unk_10_0 : 1;
    u32 unk_10_1 : 31;
} Seg1970Unk14B;

void func_001055B8(s32 a0, s32 a1) {
    s32 i;
    s32 n;
    Seg1970Unk14B* p;

    if (D_002A6258 > 0) {
        p = (Seg1970Unk14B*)D_002A6238;
        i = D_002A6258;
        do {
            if (p->unk_0B == a0) p->unk_10_0 = a1;
            p++;
        } while (--i);
    }
    if (D_002A3F28 != 0) {
        n = D_002A62D0;
        if (n > 0) {
            p = (Seg1970Unk14B*)D_002A62B0;
            do {
                if (p->unk_0B == a0) p->unk_10_0 = a1;
                p++;
            } while (--n);
        }
    }
}

extern Seg1970Unk14 *D_002A62B0;
extern s32 D_002A62D0;

void func_00105860(void) {
    s32 n = D_002A6258;
    s32 i;
    Seg1970Unk14 *p;

    if (n > 0) {
        s32 *d = &D_002B8680;
        p = D_002A6238;
        i = n;
        do {
            if (p->unk_08[2] != 0 && p->unk_0B != 0 && p->unk_0B < 100) {
                s32 x = p->unk_10 & ~1;
                s32 c = p->unk_0B != *d + 1;
                p->unk_10 = x;
                if (c) {
                    p->unk_10 = x | 1;
                }
            }
            p++;
        } while (--i);
    }
    if (D_002A3F28 != 0) {
        n = D_002A62D0;
        if (n > 0) {
            s32 *d = &D_002B8680;
            p = D_002A62B0;
            i = n;
            do {
                if ((u8)(p->unk_0B - 1) < 99) {
                    s32 x = p->unk_10 & ~1;
                    s32 c = p->unk_0B != *d + 1;
                    p->unk_10 = x;
                    if (c) {
                        p->unk_10 = x | 1;
                    }
                }
                p++;
            } while (--i);
        }
    }
}

s32 func_00105960(s32 a0, s32 a1) {
    s32 buf;
    s32 r = func_00142730(a0, &buf);
    if (buf == -1) {
        Seg1970Unk14* p = D_002A6238;
        p += r;
        return p->unk_0B == a1;
    }
    return func_0011AB60(buf, r) == a1;
}

s32 func_001059D0(s32 a0) {
    s32 buf;
    s32 r = func_00142730(a0, &buf);
    if (buf == -1) {
        Seg1970Unk14* p = D_002A6238;
        p += r;
        return p->unk_0B;
    }
    return func_0011AB60(buf, r);
}

s32 func_00105A30(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        return func_00104CF8(arg1, arg2);
    }
    return func_0011A758(arg0, arg1, arg2);
}

void func_00105A70(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        func_001047C8();
        func_00104CF8(arg1, arg2);
        func_00104528();
        return;
    }
    func_0011A758(arg0, arg1, arg2);
}

s32 func_00105AD0(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == -1) {
        return func_00104AE0(arg1, arg2);
    }
    return func_0011A7F8(arg0, arg1, arg2);
}

s32 func_00105B10(s32 a0, s32 a1) {
    Seg1970Unk14* p;
    if (a0 == -1) {
        p = &D_002A6238[a1];
        return ((u32)p->unk_10 >> 22) & 1;
    }
    return (*(u32*)func_0011AB38(a0, a1) >> 22) & 1;
}

s32 func_00105B68(s32 a0, s32 a1) {
    Seg1970Unk14* p;
    if (a0 == -1) {
        p = &D_002A6238[a1];
        return ((Seg1970Bits*)&p->unk_10)->b4;
    }
    return ((Seg1970Bits*)func_0011AB38(a0, a1))->b4;
}

s32 func_00105BC0(s32 a0, s32 a1) {
    Seg1970Unk14* p;
    if (a0 == -1) {
        p = &D_002A6238[a1];
        return ((u32)p->unk_10 >> 18) & 0xF;
    }
    return (*(u32*)func_0011AB38(a0, a1) >> 18) & 0xF;
}

s32 func_00105C18(s32 a0, s32 a1) {
    Seg1970Unk14* p;
    if (a0 == -1) {
        p = &D_002A6238[a1];
        return ((u32)p->unk_10 >> 28) & 1;
    }
    return (*(u32*)func_0011AB38(a0, a1) >> 28) & 1;
}

void func_00105C70(s32 arg0, sceVu0FVECTOR arg1) {
    sceVu0CopyVector(arg1, D_002A3F48[arg0]);
}

void func_00105C98(s32 a0, f32* a1) {
    sceVu0CopyVector(a1, D_002A3F48[((u32)D_002A6238[a0].unk_10 >> 11) & 0xF]);
}

s32 func_00105AE0(s32 a0) {
    s32 i;
    for (i = 0; i < D_002A6258; i++) {
        if (D_002A6238[i].unk_0B == a0) return ((u32)D_002A6238[i].unk_10 >> 11) & 0xF;
    }
    return 0;
}

void func_00105B38(s32 a0, s32 a1) {
    s32 n = D_002A6258;
    Seg1970Unk14* p;
    if (n > 0) {
        p = D_002A6238;
        do {
            if (p->unk_0B == a0) p->unk_10 = (p->unk_10 & ~0x7800) | ((a1 & 0xF) << 11);
            p++;
        } while (--n);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00105D88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00105F28);

void func_00105FC8(void) {
    func_001F1ED8(0x80C0612C, 0x140, 0x194, func_001F0EF0(15), 15);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_001970", func_00106000);
