// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x006B18).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"
extern f32 D_00494BC0[];

extern u8 D_002B8760[];
void FlushCache(s32);
void sceGsExecLoadImage(u8 *, s32);
void sceGsSetDefLoadImage(u8 *, s32, s32, s32, s32, s32, s32, s32);
s32 sceGsSyncPath(s32, s32);
typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
} Seg6B18Task;
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

Seg6B18Task* func_0015ED80(s32, s32 (*)(Seg6B18Task*));
s32 func_00106B98(Seg6B18Task*);
s32 func_00106E18(Seg6B18Task*);
extern s32 D_002A6C50;

void func_00106A08(s32 arg0, s32 arg1) {
    func_0015ED80(arg1, func_00106B98)->unk_10 = arg0;
}

void func_00106A40(void) {
    D_00494A98 = 0;
    D_00494A9C = 0;
    D_00494A90 = (s32)func_00121C98(0x2000, (u8*)&D_00494A90);
    D_00494A94 = (sceVu0FVECTOR*)func_00121C98(0x8000, (u8*)&D_00494A94);
}

void func_00121D50(s32);
extern sceVu0FVECTOR* D_00494A94;
extern s32 D_00494A90;

void func_00106AA8(void) {
    func_00121D50((s32)D_00494A94);
    func_00121D50(D_00494A90);
}

extern sceVu0FVECTOR* D_00494A94;
extern s32 D_00494A98;

sceVu0FVECTOR* func_00106CA8(s32 arg0) {
    s32 old = D_00494A98;

    D_00494A98 = old + arg0;
    return D_00494A94 + old;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106CD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106D48);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106DB0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106E18);

void func_00106CB0(s32 arg0) {
    if (D_002A6C50 != 0) {
        func_0015ED80(arg0, func_00106E18);
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106ED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107120);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001072C0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001073F0);

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} Seg6B18Unk10;
extern Seg6B18Unk10* D_00494BA8;
extern s32 D_002B91E8;

s32 func_00107520(s32 arg0) {
    Seg6B18Unk10* p = &D_00494BA8[arg0];

    return (D_002B91E8 & p->unk_08) != 0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107360);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107AB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107A78);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107B68);

void func_00107E10(f32* a0) {
    sceVu0CopyVector(D_00494BC0, a0 + 4);
    D_00494BC0[3] = a0[3];
    sceVu0CopyVector(D_00494BC0 + 4, a0 + 12);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107E60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107CF8);

extern s32 D_002B91E8;

void func_00108180(s32 arg0) {
    D_002B91E8 = (1 << arg0) | D_002B91E8;
}

void func_001081A0(s32 arg0) {
    D_002B91E8 = ~(1 << arg0) & D_002B91E8;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001081C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001083D8);

s32 func_00106DB0(Seg6B18Task*);

void func_001085E8(s32 arg0, s32 arg1) {
    func_0015ED80(arg0, func_00106DB0)->unk_10 = arg1;
}

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} Seg6B18Unk0C;
extern Seg6B18Unk0C D_00494C00[];

void func_00108618(void) {
    s32 i;

    for (i = 31; i >= 0; i--) {
        D_00494C00[i].unk_00 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108488);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001084F0);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108970);

void func_001089D0(sceVu0FVECTOR* arg0) {
    arg0[5][3] = 1.0f;
    arg0[4][3] = 1.0f;
    arg0[3][3] = 1.0f;
    arg0[2][3] = 1.0f;
    arg0[1][3] = 1.0f;
    arg0[0][3] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001089F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108A60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108B60);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108BE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108C58);

void func_00108CD0(s32* arg0, s32* arg1) {
    arg0[0x1A] = arg1[0];
    arg0[0x1B] = arg1[1];
    arg0[0x1C] = arg1[2];
    arg0[0x1D] = arg1[3];
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108CF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108D90);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108DF8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108D68);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108FD0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001090E8);

void func_00109180(s32 a0, s32 a1) {
    sceGsSetDefLoadImage(D_002B8760, ((a1 << 16) >> 16), 0, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsSyncPath(0, 0);
    sceGsExecLoadImage(D_002B8760, a0);
}

void func_001090E8(s32, s32, s32, s32);
void func_00109180(s32, s32);

void func_001091F8(s32 arg0, s32 arg1) {
    func_001090E8(arg0, 0x80, 0xE0, 0x3600);
    func_00109180(arg1, 0x3A00);
}

void func_00109230(s32 arg0, s32 arg1) {
    func_001090E8(arg0, 0x80, 0x30, 0x3A00);
    func_00109180(arg1, 0x3C00);
}

extern s32 D_002B6484;

void func_00109268(void) {
    D_002B6484 = 0;
}

void func_00109278(void) {
    D_002B6484 = 1;
}
