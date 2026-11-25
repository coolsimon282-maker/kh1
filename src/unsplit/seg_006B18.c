// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x006B18).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} Seg6B18Q;
extern f32 D_002DECF0[];
extern f32 D_002DECE0[];
extern f32 D_002A6C10[][4];
extern f32 D_00297850[][4];
extern Seg6B18Q D_00486430[];
typedef struct { f32 unk_00; s32 unk_04; f32 unk_08; } Seg6B18F0C;
extern Seg6B18F0C D_00494C00_f[] __asm__("D_00494C00");

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
} Seg6B18Task;
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} Seg6B18Unk10;
typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Seg6B18Unk0C;
extern f32 D_00494BC0[];
extern u8 D_002B8760[];
void FlushCache(s32);
void sceGsExecLoadImage(u8 *, s32);
void sceGsSetDefLoadImage(u8 *, s32, s32, s32, s32, s32, s32, s32);
s32 sceGsSyncPath(s32, s32);
extern s32 D_002A6B84;
extern u8 D_002B8700[];
void iFlushCache(s32);
void sceDmaSend(s32, s32);
extern s32 D_00494A90;
extern sceVu0FVECTOR* D_00494A94;
extern s32 D_00494A98;
extern s32 D_00494A9C;
extern u8 D_0048BFD0[];
extern u8 D_0048C630[];
extern u8 D_0048C690[];
u8* func_00121C98(s32, u8*);
Seg6B18Task* func_0015ED80(s32, s32 (*)(Seg6B18Task*));
s32 func_00106B98(Seg6B18Task*);
s32 func_00106E18(Seg6B18Task*);
extern s32 D_002A6C50;
void func_00121D50(s32);
extern Seg6B18Unk10* D_00494BA8;
extern s32 D_002B91E8;
s32 func_00106DB0(Seg6B18Task*);
extern Seg6B18Unk0C D_00494C00[];
void func_001090E8(s32, s32, s32, s32);
void func_00109180(s32, s32);
extern s32 D_002B6484;

void func_00106948(s32 a0) {
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceDmaSend(D_002A6B84, a0);
}

void func_00106B58(s32 a0) {
    a0 |= 0x80000000;
    sceGsSyncPath(0, 0);
    sceDmaSend(D_002A6B84, a0);
}

s32 func_00106B98(Seg6B18Task* t) {
    iFlushCache(0);
    sceDmaSend(D_002A6B84, t->unk_10);
    return 2;
}

void func_00106A08(s32 arg0, s32 arg1) {
    func_0015ED80(arg1, func_00106B98)->unk_10 = arg0;
}

void func_00106A40(void) {
    D_00494A98 = 0;
    D_00494A9C = 0;
    D_00494A90 = (s32)func_00121C98(0x2000, (u8*)&D_00494A90);
    D_00494A94 = (sceVu0FVECTOR*)func_00121C98(0x8000, (u8*)&D_00494A94);
}

void func_00106AA8(void) {
    func_00121D50((s32)D_00494A94);
    func_00121D50(D_00494A90);
}

sceVu0FVECTOR* func_00106CA8(s32 arg0) {
    s32 old = D_00494A98;

    D_00494A98 = old + arg0;
    return D_00494A94 + old;
}

s32* func_00106CD0(s32 a0, s32 a1) {
    s32* p;
    *(s32*)(D_00494A9C * 16 + D_00494A90) = 0x30000000 + a1;
    ((s32*)(D_00494A9C * 16 + D_00494A90))[1] = a0;
    p = (s32*)(D_00494A9C * 16 + D_00494A90);
    p[3] = 0;
    p[2] = 0;
    D_00494A9C++;
    return (s32*)(D_00494A90 + D_00494A9C * 16 - 16);
}

void func_00106D48(s32 a0) {
    s32* p;
    *(s32*)(D_00494A9C * 16 + D_00494A90) = 0x70000000;
    p = (s32*)(D_00494A9C * 16 + D_00494A90);
    p[3] = 0;
    p[2] = 0;
    p[1] = 0;
    D_00494A9C++;
    func_00106948(a0);
}

s32 func_00106DB0(Seg6B18Task* t) {
    *(volatile u32*)0x10009020 = 0;
    *(volatile u32*)0x10009030 = t->unk_10 & 0x0FFFFFFF;
    *(volatile u32*)0x1000E010 = 2;
    iFlushCache(0);
    *(volatile u32*)0x10009000 = 0x105;
    return 2;
}

extern s32 D_002A6C54;
extern u8 D_002BC270[];
void* func_0011F9E8(s32, s32, s32, s32, s32, s32, s32, s32, s32, void*);
s32 func_00106E18(Seg6B18Task* t) {
    func_0011F9E8(0x3600, 2, 0, 0, 0, 0x80, D_002A6C50 << 7, D_002A6C50 << 12, D_002A6C54, D_002BC270);
    iFlushCache(0);
    sceDmaSend(D_002A6B84, (s32)D_002BC270);
    return 2;
}

void func_00106CB0(s32 arg0) {
    if (D_002A6C50 != 0) {
        func_0015ED80(arg0, func_00106E18);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106ED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107120);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001072C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001073F0);

s32 func_00107520(s32 arg0) {
    Seg6B18Unk10* p = &D_00494BA8[arg0];

    return (D_002B91E8 & p->unk_08) != 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107AB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107A78);

extern s32 D_00351BD0;
extern u8 D_0046E120[];
extern u8 D_00472160[];
extern u8 D_004761A0[];
extern u8 D_0047A1E0[];
extern u8 D_0047E220[];
extern u8 D_00482260[];

void func_00107B68(s32 a0, s32 a1) {
    Seg6B18Task* t = func_0015ED80(a0, func_00106DB0);

    switch (a1) {
    case 1:
        t->unk_10 = (s32)(D_00351BD0 ? D_00472160 : D_0046E120);
        break;
    case 0:
        t->unk_10 = (s32)(D_00351BD0 ? D_0047A1E0 : D_004761A0);
        break;
    case 3:
        t->unk_10 = (s32)(D_00351BD0 ? D_00482260 : D_0047E220);
        break;
    }
}

void func_00107E10(f32* a0) {
    sceVu0CopyVector(D_00494BC0, a0 + 4);
    D_00494BC0[3] = a0[3];
    sceVu0CopyVector(D_00494BC0 + 4, a0 + 12);
}

void func_00107E60(void) {
    sceVu0FMATRIX m;
    sceVu0FVECTOR v;
    sceVu0SubVector(v, D_002DECF0, D_002DECE0);
    sceVu0Normalize(v, v);
    sceVu0RotMatrix(D_002A6C10, D_00297850, v);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107CF8);

void func_00108180(s32 arg0) {
    D_002B91E8 = (1 << arg0) | D_002B91E8;
}

void func_001081A0(s32 arg0) {
    D_002B91E8 = ~(1 << arg0) & D_002B91E8;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001081C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001083D8);

void func_001085E8(s32 arg0, s32 arg1) {
    func_0015ED80(arg0, func_00106DB0)->unk_10 = arg1;
}

void func_00108618(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_00494C00[i].unk_00 = 0;
    }
}

void func_00108488(s32 a0, s32 a1) {
    f32 f = a1 * 2;
    D_00494C00_f[a0].unk_00 = f;
    *(f32*)&D_00494C00_f[a0].unk_04 = 1.0f;
    D_00494C00_f[a0].unk_08 = -(1.0f / f);
    func_001081A0(a0);
}

void func_001084F0(s32 a0, s32 a1) {
    f32 f = a1 * 2;
    D_00494C00_f[a0].unk_00 = f;
    D_00494C00_f[a0].unk_04 = 0;
    D_00494C00_f[a0].unk_08 = 1.0f / f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108548);

void func_00108900(s32 *a0, s32 a1, s32 *a2, s32 *a3) {
    s32* p = (s32*)D_0048BFD0;
    s32* q = (s32*)D_0048C630;
    s32* r = (s32*)D_0048C690;
    a2[0] = a3[0] = p[0];
    a2[1] = a3[1] = p[1];
    a0[4] = q[4];
    a0[5] = (s32)a2;
    a0[6] = q[6];
    a0[7] = q[7];
    a0[28] = r[4];
    a0[29] = (s32)a3;
    a0[30] = r[6];
    a0[31] = r[7];
}

typedef struct { s32 v[4]; s32 pad[20]; } E108970;
typedef struct { E108970 e[1]; } T108970;
extern s32 D_00486430_a[][4] __asm__("D_00486430");
void func_00108970(T108970 *a0, s32 a1, s32 a2) {
    a0->e[a1].v[0] = D_00486430_a[a2][0];
    a0->e[a1].v[1] = D_00486430_a[a2][1];
    a0->e[a1].v[2] = D_00486430_a[a2][2];
    a0->e[a1].v[3] = D_00486430_a[a2][3];
}

void func_001089D0(sceVu0FVECTOR* arg0) {
    arg0[5][3] = 1.0f;
    arg0[4][3] = 1.0f;
    arg0[3][3] = 1.0f;
    arg0[2][3] = 1.0f;
    arg0[1][3] = 1.0f;
    arg0[0][3] = 1.0f;
}

typedef struct { s32 m[6][4]; } E1089F8;
typedef struct { E1089F8 e[2]; void *unkC0; } T1089F8;
typedef struct { u8 pad[0x80]; s32 w[8]; } S1089F8;
void func_001089F8(T1089F8 *a0, S1089F8 *a1) {
    s32 i;
    for (i = 0; i < 2; i++) {
        a0->e[i].m[3][0] = a1->w[0];
        a0->e[i].m[3][1] = a1->w[1] + (s32)a1;
        a0->e[i].m[3][2] = a1->w[2];
        a0->e[i].m[3][3] = a1->w[3];
        a0->e[i].m[4][0] = a1->w[4];
        a0->e[i].m[4][1] = a1->w[5] + (s32)a1;
        a0->e[i].m[4][2] = a1->w[6];
        a0->e[i].m[4][3] = a1->w[7];
    }
}

extern s32 D_0046BE90[];
void func_00108A60_t(s32, s32, T1089F8*, u8*, u8*) __asm__("func_00108A60");

// declared later in the file with a T108CF8* (defined after this point), so defined under an alias
void func_00108A60_t(s32 a0, s32 a1, T1089F8* a2, u8* a3, u8* a4) {
    s32* q = (s32*)D_0048C630;
    s32* r = (s32*)D_0048C690;
    s32 i;

    a2->e[0].m[2][0] = q[8];
    a2->e[0].m[2][1] = q[9];
    a2->e[0].m[2][2] = q[10];
    a2->e[0].m[2][3] = q[11];
    a2->e[1].m[2][0] = r[8];
    a2->e[1].m[2][1] = r[9];
    a2->e[1].m[2][2] = r[10];
    a2->e[1].m[2][3] = r[11];
    func_00108900(a2->e[0].m[0], a0, (s32*)a3, (s32*)a4);
    for (i = 0; i < 2; i++) {
        func_00108970((T108970*)a2, i, a1);
        a2->e[i].m[5][0] = D_0046BE90[0];
        a2->e[i].m[5][1] = D_0046BE90[1];
        a2->e[i].m[5][2] = D_0046BE90[2];
        a2->e[i].m[5][3] = D_0046BE90[3];
    }
}

extern s32 D_00351BD0;
typedef struct { s32 m[6][4]; } E108B60;
typedef struct { E108B60 e[2]; void *unkC0; } T108B60;
typedef struct { u8 pad[0x80]; s32 w[8]; } S108B60;
void func_00108B60(S108B60 *a0, T108B60 *a1) {
    s32 t = a0->w[0];
    s32 i = D_00351BD0;
    a1->unkC0 = a0;
    a1->e[i].m[3][0] = t;
    a1->e[i].m[3][1] = a0->w[1] + (s32)a0;
    a1->e[i].m[3][2] = a0->w[2];
    a1->e[i].m[3][3] = a0->w[3];
    a1->e[i].m[4][0] = a0->w[4];
    a1->e[i].m[4][1] = a0->w[5] + (s32)a0;
    a1->e[i].m[4][2] = a0->w[6];
    a1->e[i].m[4][3] = a0->w[7];
}

typedef struct { s32 pad[2]; s32 x[16]; s32 y[16]; } T108BE8;
extern s32 D_002BC170_i[][4] __asm__("D_002BC170");
void func_00108BE8(s32 a0, s32 (*a1)[4], T108BE8 *a2) {
    s32 i, j, k;
    k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            a2->x[k] = a1[i][j];
            a2->y[k] = D_002BC170_i[i][j];
            k++;
        }
    }
}

void func_00108C58(s32 (*a1)[4], T108BE8 *a2) {
    s32 i, j, k;
    k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            a2->x[k] = a1[i][j];
            a2->y[k] = D_002BC170_i[i][j];
            k++;
        }
    }
}

void func_00108CD0(s32* arg0, s32* arg1) {
    arg0[0x1A] = arg1[0];
    arg0[0x1B] = arg1[1];
    arg0[0x1C] = arg1[2];
    arg0[0x1D] = arg1[3];
}

typedef struct { T1089F8 t; s32 pad[3]; } T108CF8;
typedef struct { u8 a[2][0x90]; u8 b[2][0x90]; } U108CF8;
extern T108CF8 D_00494D80[];
extern U108CF8 D_00494F20;
void func_00108A60(s32, s32, T108CF8*, u8*, u8*);
void func_00108CF8(void *a0, s32 a1, s32 a2) {
    D_00494D80[a1].t.unkC0 = a0;
    func_00108A60(a1, a2, &D_00494D80[a1], D_00494F20.a[a1], D_00494F20.b[a1]);
    func_001089F8(&D_00494D80[a1].t, a0);
    func_001089D0(a0);
}

s32 func_00108D90(Seg6B18Task *t) {
    *(volatile u32 *)0x10009020 = 0;
    *(volatile u32 *)0x10009030 = t->unk_10 & 0x0FFFFFFF;
    *(volatile u32 *)0x1000E010 = 2;
    iFlushCache(0);
    *(volatile u32 *)0x10009000 = 0x145;
    return 2;
}

extern T108CF8 D_002A6C60[];
extern u8 D_002AD460[][64][0x90];
extern f32 D_002BC190[];
void func_00108C58_d(s32, u8*) __asm__("func_00108C58");   /* fm-a2 callers: declaration-only view of the function a1 defined above */

void func_00108DF8(s32 a0, s32 a1, s32 a2, s32 a3, f32* a4) {
    sceVu0FVECTOR v;

    sceVu0MulVector(v, D_002BC190, a4);
    func_00108B60((S108B60*)a3, (T108B60*)&D_002A6C60[a0]);
    func_00108C58_d(a2, D_002AD460[D_00351BD0][a0]);
    func_00108CD0((s32*)D_002AD460[D_00351BD0][a0], (s32*)v);
    func_0015ED80(a1, func_00108D90)->unk_10 = (s32)&D_002A6C60[a0].t.e[D_00351BD0];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108D68);

extern T108CF8 D_002AA060[];
extern u8 D_002B1C60[][64][0x90];
void func_00108C58_d(s32, u8*) __asm__("func_00108C58");

void func_00108FD0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_00108B60((S108B60*)a3, (T108B60*)&D_002AA060[a0]);
    func_00108C58_d(a2, D_002B1C60[D_00351BD0][a0]);
    func_00108CD0((s32*)D_002B1C60[D_00351BD0][a0], (s32*)a4);
    func_0015ED80(a1, func_00108D90)->unk_10 = (s32)&D_002AA060[a0].t.e[D_00351BD0];
}

int sceGsSetDefLoadImage_s(u8 *, short, short, short, short, short, short, short) __asm__("sceGsSetDefLoadImage");
void func_001090E8(s32 a0, s32 a1, s32 a2, s32 a3) {
    sceGsSetDefLoadImage_s(D_002B8700, a3, a1 / 64, 0x14, 0, 0, a1, a2);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(D_002B8700, a0);
}

void func_00109180(s32 a0, s32 a1) {
    sceGsSetDefLoadImage(D_002B8760, ((a1 << 16) >> 16), 0, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(D_002B8760, a0);
}

void func_001091F8(s32 arg0, s32 arg1) {
    func_001090E8(arg0, 0x80, 0xE0, 0x3600);
    func_00109180(arg1, 0x3A00);
}

void func_00109230(s32 arg0, s32 arg1) {
    func_001090E8(arg0, 0x80, 0x30, 0x3A00);
    func_00109180(arg1, 0x3C00);
}

void func_00109268(void) {
    D_002B6484 = 0;
}

void func_00109278(void) {
    D_002B6484 = 1;
}
