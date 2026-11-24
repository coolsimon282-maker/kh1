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

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C6530);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C4ED0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5168);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C53C8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5B88);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5DB8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C5EE8);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C62A0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C6720);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C6890);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0C45E8", func_001C6A20);
