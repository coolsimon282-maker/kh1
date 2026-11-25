// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0C45E8).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

extern u8 D_00375BC0[];
void func_001C5918(s32, s32);
void func_001DE3E0(s32, s32);

typedef struct {
    u8 b[32];
} A2Ring32;
extern s32 D_006277E0;
extern s32 D_006277E4;
extern A2Ring32 D_006257E0[];

A2Ring32 *func_001C45E8(void) {
    s32 r = D_006277E0;

    if (r == D_006277E4) {
        return NULL;
    }
    D_006277E0 = (r + 1) % 256;
    return &D_006257E0[r];
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[6];
} ScriptMsg;
typedef struct {
    u64 d[4];
} A2Msg64;
extern s32 D_0037A21C[];
s32 func_00123880(s32);

s32 func_001C4640(ScriptMsg *m) {
    s32 r;
    A2Msg64 t;

    if ((D_006277E4 + 1) % 256 == D_006277E0) {
        return -1;
    }
    r = func_00123880(m->unk_04);
    if (r == 0 && D_0037A21C[*(u8 *)m * 2] != 0) {
        return r;
    }

    ((A2Msg64 *)D_006257E0)[D_006277E4] = *(A2Msg64 *)m;
    D_006277E4 = (D_006277E4 + 1) % 256;
    return 0;
}

extern s32 D_006297F0;
extern s32 D_006297F4;
extern A2Ring32 D_006277F0[];

A2Ring32 *func_001C4730(void) {
    s32 r = D_006297F0;

    if (r == D_006297F4) {
        return NULL;
    }
    D_006297F0 = (r + 1) % 256;
    return &D_006277F0[r];
}

typedef struct
{
  u64 d[4];
} A2Ring32q;
s32 func_001C4788(A2Ring32q *src)
{
  s32 new_var;
  s32 w = D_006297F4;
  s32 n = w + 1;
  n %= 256;
  new_var = n;
  if (new_var == D_006297F0)
  {
    return -1;
  }
  *(&((A2Ring32q *) D_006277F0)[w]) = *src;
  D_006297F4 = new_var;
  return 0;
}

typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3034];
    /* 0x3034 */ u32 unk_3034;
    /* 0x3038 */ s32 unk_3038;
    /* 0x303C */ s32 unk_303C;
    /* 0x3040 */ u8 unk_3040[0x30];
    /* 0x3070 */ u64 unk_3070;
    /* 0x3078 */ u64 unk_3078;
} A1GM4808;
extern A1GM4808 D_003854E0_48 __asm__("D_003854E0");
extern s32 D_002B91E0;
extern s32 D_002B9334;
void func_001C4740(s32, u32);
NOTHROW(void, func_001C4FF0);

void func_001C4808(s32 a0, u32 a1) {
    if ((*(u32*)D_00375BC0 >> 1) & 1) {
        return;
    }
    if ((s32)(D_003854E0_48.unk_3070 >> 40) & 1) {
        return;
    }
    if ((s32)(D_003854E0_48.unk_3078 >> 7) & 1) {
        return;
    }
    D_003854E0_48.unk_303C = a0;
    if (a1 == 0) {
        return;
    }
    if (a1 < 100) {
        if (D_003854E0_48.unk_3034 != a1) {
            func_001C4740(D_002B9334, a1);
            D_003854E0_48.unk_3078 |= 0x40;
        }
    } else if (D_003854E0_48.unk_3038 == 0) {
        func_001C4FF0(D_002B91E0, a1 - 100);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C48C8);

void func_001C4D90(s32 a0, s32 a1, s32 a2) {
    func_001DE3E0(a1, a2);
    func_001C5918(a0, 0);
    *(s32 *)(D_00375BC0 + 0x0) = (*(s32 *)(D_00375BC0 + 0x0) | 0x4);
}

typedef struct {
    u64 unk_00 : 8;
    u64 unk_01 : 24;
    s32 unk_04;
    s32 unk_08[2];
    f32 unk_10[4];
} ScriptMsgG;
typedef struct {
    /* 0x0000 */ u8 unk_0000[0x3034];
    /* 0x3034 */ s32 unk_3034;
    /* 0x3038 */ u8 unk_3038[0x138];
    /* 0x3170 */ s32 unk_3170;
    /* 0x3174 */ s32 unk_3174;
    /* 0x3178 */ u8 unk_3178[0x2D8];
    /* 0x3450 */ s32 unk_3450;
} A1GM6530;
extern A1GM6530 D_003854E0_65 __asm__("D_003854E0");
extern u8 D_0038D170[];
extern u8 D_0039A580[];
extern volatile s32 D_002B834C;
void func_001C36A8(void*, s32);
s32 func_001D71A0(u8*);

s32 func_001C6530(s32 a0, s32 a1) {
    ScriptMsgG msg;
    u8* p;

    D_003854E0_65.unk_3170 = a0;
    D_003854E0_65.unk_3174 = a1;
    if (D_003854E0_65.unk_3034 == 0) {
        p = D_0038D170;
    } else {
        p = D_0039A580;
    }
    D_003854E0_65.unk_3450 = 0;
    func_001C36A8(p, 10);
    if (a1 == 1) {
        func_001D71A0(p);
        msg.unk_00 = 0x28;
        msg.unk_01 = 0;
        msg.unk_10[0] = 0.0f;
        msg.unk_10[1] = 0.0f;
        msg.unk_10[2] = 0.0f;
        msg.unk_10[3] = 1.0f;
        func_001C4640((ScriptMsg*)&msg);
        if (D_002B834C == a1) {
            D_002B834C = 4;
        }
    }
    return D_003854E0_65.unk_3450;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C4ED0);

typedef struct {
    /* 0x00 */ f32 t;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ f32 v10[4];
    /* 0x20 */ f32 v20[4];
    /* 0x30 */ f32 v30[4];
    /* 0x40 */ f32 v40[4];
    /* 0x50 */ f32 v50[4];
    /* 0x60 */ f32 f60;
} A3Cam380c;
extern A3Cam380c D_0037A380_c __asm__("D_0037A380");
typedef struct {
    /* 0x0000 */ u8 pad[0x3058];
    /* 0x3058 */ s32 unk_3058;
    /* 0x305C */ u8 pad305C[0x10];
    /* 0x306C */ f32* unk_306C;
    /* 0x3070 */ f32* unk_3070;
} A3GM5168;
extern A3GM5168 D_003854E0_51 __asm__("D_003854E0");
void func_001E9D00(f32* out, f32* a, f32* b, f32 roll);
void func_001E9FE8(f32*, f32*);
void func_001E9F18(f32* o, f32* pos, f32* rot, f32 dist);
f32 func_001E9E58(f32* a, f32* b);

void func_001C5168(void) {
    sceVu0FVECTOR v;
    sceVu0FVECTOR r;
    sceVu0FMATRIX m;

    switch ((u32)D_003854E0_51.unk_3058) {
    case 0:
        break;
    case 1:
        D_0037A380_c.v10[0] += D_003854E0_51.unk_306C[4];
        D_0037A380_c.v10[1] += D_003854E0_51.unk_306C[5];
        D_0037A380_c.v10[2] += D_003854E0_51.unk_306C[6];
        break;
    case 2:
        D_0037A380_c.v40[1] += D_003854E0_51.unk_306C[15];
        sceVu0UnitMatrix(m);
        sceVu0RotMatrixY(m, m, D_003854E0_51.unk_306C[15]);
        sceVu0ApplyMatrix(D_0037A380_c.v10, m, D_0037A380_c.v10);
        D_0037A380_c.v10[0] += D_003854E0_51.unk_306C[4];
        D_0037A380_c.v10[1] += D_003854E0_51.unk_306C[5];
        D_0037A380_c.v10[2] += D_003854E0_51.unk_306C[6];
        break;
    case 3:
        func_001E9D00(r, &D_003854E0_51.unk_3070[4], &D_003854E0_51.unk_306C[4], D_0037A380_c.v40[2]);
        D_0037A380_c.v40[1] += r[1];
        func_001E9FE8(r, D_0037A380_c.v40);
        func_001E9F18(v, D_0037A380_c.v10, r, D_0037A380_c.f60);
        v[0] += D_003854E0_51.unk_3070[4];
        v[1] += D_003854E0_51.unk_3070[5];
        v[2] += D_003854E0_51.unk_3070[6];
        sceVu0UnitMatrix(m);
        sceVu0RotMatrixY(m, m, D_003854E0_51.unk_306C[15]);
        sceVu0ApplyMatrix(D_0037A380_c.v10, m, D_0037A380_c.v10);
        D_0037A380_c.v10[0] += D_003854E0_51.unk_306C[4];
        D_0037A380_c.v10[1] += D_003854E0_51.unk_306C[5];
        D_0037A380_c.v10[2] += D_003854E0_51.unk_306C[6];
        D_0037A380_c.f60 = func_001E9E58(v, D_0037A380_c.v10);
        func_001E9D00(D_0037A380_c.v40, D_0037A380_c.v10, v, D_0037A380_c.v40[2]);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C53C8);

extern f32 D_002B8344;
typedef struct {
    f32 v[4];
} __attribute__((aligned(8))) A3V8b;

typedef struct {
    u8 pad[8];
    s32 n;
} A3Cntb;

typedef struct {
    /* 0x0000 */ f32 t;
    /* 0x0004 */ u8 pad4[0xC];
    /* 0x0010 */ A3V8b v10;
    /* 0x0020 */ A3V8b v20;
    /* 0x0030 */ A3V8b v30;
    /* 0x0040 */ A3V8b v40;
    /* 0x0050 */ A3V8b v50;
    /* 0x0060 */ f32 f60;
    /* 0x0064 */ u8 pad64[0xE090];
    /* 0xE0F4 */ f32 fE0F4;
    /* 0xE0F8 */ u8 padE0F8[4];
    /* 0xE0FC */ A3Cntb* cnt;
} A3Cam380b;

typedef struct {
    /* 0x000 */ u8 pad[0xD0];
    /* 0x0D0 */ A3V8b vD0;
    /* 0x0E0 */ A3V8b vE0;
    /* 0x0F0 */ A3V8b vF0;
    /* 0x100 */ A3V8b v100;
    /* 0x110 */ A3V8b v110;
    /* 0x120 */ f32 f120;
    /* 0x124 */ f32 f124;
} A3Cam5510b;

extern A3Cam380b D_0037A380_b __asm__("D_0037A380");
extern A3Cam5510b D_003C5510_a3b __asm__("D_003C5510");
void func_001C53C8(f32);
void func_001C6A20(void);
typedef struct {
    /* 0x0000 */ u8 pad[0x3070];
    /* 0x3070 */ u64 unk_3070;
    /* 0x3078 */ u8 pad3078[0xD4];
    /* 0x314C */ f32 unk_314C;
} A3GM5B88;
extern A3GM5B88 D_003854E0_5b __asm__("D_003854E0");

static inline void A3Copy8b(A3V8b* d, A3V8b* s) {
    *d = *s;
}

s32 func_001C5B88(void) {
    f32 t = D_0037A380_b.t + D_002B8344 * 0.5f * D_003854E0_5b.unk_314C;
    f32 n;

    n = D_0037A380_b.cnt->n;
    D_0037A380_b.t = t;
    if (n < t) {
        D_0037A380_b.t = n;
        func_001C53C8(D_0037A380_b.t);
        A3Copy8b(&D_003C5510_a3b.vD0, &D_0037A380_b.v10);
        A3Copy8b(&D_003C5510_a3b.vE0, &D_0037A380_b.v40);
        A3Copy8b(&D_003C5510_a3b.vF0, &D_0037A380_b.v50);
        A3Copy8b(&D_003C5510_a3b.v110, &D_0037A380_b.v30);
        A3Copy8b(&D_003C5510_a3b.v100, &D_0037A380_b.v20);
        D_003C5510_a3b.f120 = D_0037A380_b.f60;
        D_003C5510_a3b.f124 = D_0037A380_b.fE0F4;
        func_001C6A20();
        D_003854E0_5b.unk_3070 &= ~0x2000000000;
    } else {
        func_001C53C8(D_0037A380_b.t);
        A3Copy8b(&D_003C5510_a3b.vD0, &D_0037A380_b.v10);
        A3Copy8b(&D_003C5510_a3b.vE0, &D_0037A380_b.v40);
        A3Copy8b(&D_003C5510_a3b.vF0, &D_0037A380_b.v50);
        A3Copy8b(&D_003C5510_a3b.v110, &D_0037A380_b.v30);
        A3Copy8b(&D_003C5510_a3b.v100, &D_0037A380_b.v20);
        D_003C5510_a3b.f120 = D_0037A380_b.f60;
        D_003C5510_a3b.f124 = D_0037A380_b.fE0F4;
        func_001C6A20();
        if ((s32)(*(u64*)&D_003C5510_a3b >> 8) & 1) {
            sceVu0CopyVector((f32*)((u8*)&D_003C5510_a3b + 0xC0), D_003C5510_a3b.vD0.v);
        }
    }
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5DB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C62A0);

typedef struct {
    u64 b0 : 1;
    u64 b1 : 1;
    u64 b2 : 1;
    u64 b3 : 1;
    u64 b4 : 1;
    u64 b5 : 1;
    u64 b6 : 1;
    u64 b7 : 1;
    u64 b8 : 1;
    u64 b9 : 23;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ f32 f[0x48];
    /* 0x128 */ f32 unk_128;
} Unk3C5510F;
extern Unk3C5510F D_003C5510_f __asm__("D_003C5510");
void func_001C6890();
void func_001E9FE8(f32*, f32*);

void func_001C6720(void) {
    sceVu0FVECTOR v;

    D_003C5510_f.b0 = 0;
    D_003C5510_f.b1 = 0;
    D_003C5510_f.b2 = 0;
    D_003C5510_f.b3 = 0;
    D_003C5510_f.b4 = 0;
    D_003C5510_f.b5 = 0;
    D_003C5510_f.b6 = 0;
    D_003C5510_f.b7 = 0;
    D_003C5510_f.b8 = 0;
    D_003C5510_f.unk_04 = 0.0f;
    D_003C5510_f.f[0] = 0.0f;
    D_003C5510_f.f[1] = 0.0f;
    D_003C5510_f.f[2] = 0.0f;
    D_003C5510_f.f[14] = 0.0f;
    D_003C5510_f.f[15] = 0.0f;
    D_003C5510_f.f[16] = 0.0f;
    D_003C5510_f.f[17] = 1.0f;
    D_003C5510_f.f[18] = 0.0f;
    D_003C5510_f.f[19] = 0.0f;
    D_003C5510_f.f[20] = 0.0f;
    D_003C5510_f.f[21] = 0.0f;
    D_003C5510_f.f[22] = 1000.0f;
    D_003C5510_f.f[23] = 53.0f;
    D_003C5510_f.f[26] = 0.0f;
    D_003C5510_f.f[27] = 0.0f;
    D_003C5510_f.f[28] = 0.0f;
    D_003C5510_f.f[29] = 1.0f;
    D_003C5510_f.f[30] = 0.0f;
    D_003C5510_f.f[31] = 0.0f;
    D_003C5510_f.f[32] = 0.0f;
    D_003C5510_f.f[33] = 0.0f;
    D_003C5510_f.f[34] = 1000.0f;
    D_003C5510_f.f[35] = 53.0f;
    D_003C5510_f.f[50] = 0.0f;
    D_003C5510_f.f[51] = 0.0f;
    D_003C5510_f.f[52] = 0.0f;
    D_003C5510_f.f[53] = 1.0f;
    D_003C5510_f.f[54] = 0.0f;
    D_003C5510_f.f[55] = 0.0f;
    D_003C5510_f.f[56] = 0.0f;
    D_003C5510_f.f[57] = 0.0f;
    D_003C5510_f.f[62] = 0.0f;
    D_003C5510_f.f[63] = 0.0f;
    D_003C5510_f.f[64] = 1.0f;
    D_003C5510_f.f[65] = 1.0f;
    D_003C5510_f.f[66] = 0.0f;
    D_003C5510_f.f[67] = 1.0f;
    D_003C5510_f.f[68] = 0.0f;
    D_003C5510_f.f[69] = 1.0f;
    D_003C5510_f.f[70] = 1000.0f;
    D_003C5510_f.f[71] = 53.0f;
    func_001C6890();
    sceVu0CopyVector(v, &D_003C5510_f.f[54]);
    v[1] += 3.1415928f;
    func_001E9FE8(v, v);
    D_003C5510_f.unk_128 = v[1];
}

void* memset(void*, s32, u32);
extern sceVu0FVECTOR D_002DECE0;
extern sceVu0FVECTOR D_002DECF0;
extern f32 D_002DED00;
extern f32 D_002DED04;
f32 func_001E9E58(f32* a, f32* b);
void func_001E9D00(f32* out, f32* a, f32* b, f32 roll);

void func_001C6890(void) {
    sceVu0FVECTOR v;
    sceVu0FMATRIX m;
    sceVu0FVECTOR r;

    memset(v, 0, 0x10);
    v[3] = 1.0f;
    memset(r, 0, 0x10);
    sceVu0CopyVector(v, D_002DECE0);
    sceVu0CopyVector(&D_003C5510_f.f[50], D_002DECF0);
    D_003C5510_f.f[70] = func_001E9E58(v, &D_003C5510_f.f[50]);
    D_003C5510_f.f[71] = D_002DED00;
    func_001E9D00(r, &D_003C5510_f.f[50], v, D_002DED04);
    D_003C5510_f.f[62] = 0.0f;
    D_003C5510_f.f[63] = 0.0f;
    D_003C5510_f.f[64] = 1.0f;
    D_003C5510_f.f[65] = 1.0f;
    D_003C5510_f.f[66] = 0.0f;
    D_003C5510_f.f[67] = 1.0f;
    D_003C5510_f.f[68] = 0.0f;
    D_003C5510_f.f[69] = 1.0f;
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, r[0]);
    sceVu0RotMatrixY(m, m, r[1]);
    sceVu0ApplyMatrix(&D_003C5510_f.f[62], m, &D_003C5510_f.f[62]);
    sceVu0ApplyMatrix(v, m, v);
    sceVu0CopyVector(&D_003C5510_f.f[54], r);
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, r[0]);
    sceVu0RotMatrixY(m, m, r[1]);
    sceVu0RotMatrixZ(m, m, r[2]);
    sceVu0ApplyMatrix(&D_003C5510_f.f[66], m, &D_003C5510_f.f[66]);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C6A20);
