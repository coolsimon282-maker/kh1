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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C4808);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5168);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C53C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5B88);

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
