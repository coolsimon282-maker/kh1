// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x006B18).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106948);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106B58);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106B98);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106A08);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106A40);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00106CB0);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00107E10);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001085E8);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00108900);

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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00109180);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_001091F8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_006B18", func_00109230);

extern s32 D_002B6484;

void func_00109268(void) {
    D_002B6484 = 0;
}

void func_00109278(void) {
    D_002B6484 = 1;
}
