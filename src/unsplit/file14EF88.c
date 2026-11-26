// JP: the asm piece at 0x24B980-0x24BCD0 (here 0x24EF88-0x24F2E0), then newlib's __assert (JP: lib/libc/assert
// at 0x24BCD0). Split out of the placeholder seg_14B9A8.
#include "common.h"

extern u8 D_004919E8[];
extern s32 D_0066AA84;
extern s32 _impure_ptr;
void abort(void);
void fiprintf(s32, u8 *, s32, s32, s32);
void func_00149E38(s32, u8 *);
void func_0024F008();

extern u8 *D_002E26A0[];
void func_00242B68(s32);
s32 func_0013C2A8(u16);
void func_00241C60(void *, s32);

void func_0024EF88(void) {
    s32 i;

    func_00242B68(1);
    func_00242B68(2);
    for (i = 0; i < 2; i++) {
        u8 *o = D_002E26A0[i + 1];

        if (o != NULL) {
            func_00241C60(o, func_0013C2A8(*(u16 *)(*(u8 **)(o + 0x130) + 0x4C)));
        }
    }
}

extern void (*D_0066AA80)(void);
extern u8 D_0066AA90[];
unsigned long long func_001245F0(s32);
void func_00123E48(s32, u8 *);
void func_0024F008(void)
{
  s32 *new_var;
  new_var = &D_0066AA84;
  func_001245F0(*(*((s32 **) new_var)));
  func_00123E48(*(*((s32 **) new_var)), D_0066AA90);
  func_0024EF88();
  if (D_0066AA80 != 0)
  {
    D_0066AA80();
  }
}

void func_0024F070(void) {
    func_00149E38(*(u16 *)(*(u8 **)&D_0066AA84 + 0x4C), func_0024F008);
}

u8 *func_0013DA88(s32);
void func_00141218(u8 *);
void Actor_FreeModel(u8 *);
void Actor_Remove(u8 *);
u8 *func_00132040(u8 *);
s32 func_001571A8(s32, s32);
s32 func_001560F8_s(s32, void*) __asm__("func_001560F8");
void func_0024F070(void);

void func_0024F098(u8 *a0, void (*cb)(void)) {
    u8 *p;
    u8 *q;
    s8 c;

    if (a0[3] != ((u8 *)D_003010F8)[0x491]) {
        p = func_0013DA88(((u8 *)D_003010F8)[0x491]);
        sceVu0CopyVector((f32 *)D_0066AA90, (f32 *)(p + 0x10));
        *(f32 *)(D_0066AA90 + 0xC) = *(f32 *)(p + 0x3C);
        c = *(s8 *)(*(u8 **)(p + 0x130) + 0x55);
        func_00141218(p);
        Actor_FreeModel(p);
        Actor_Remove(p);
        *(u8 **)&D_0066AA84 = NULL;
        while ((q = *(u8 **)&D_0066AA84 = func_00132040(*(u8 **)&D_0066AA84)) != NULL) {
            if (*(u16 *)(q + 0x4C) == a0[3] && *(s8 *)(q + 0x54) == 1) {
                break;
            }
        }
        q[0x55] = c;
        func_001571A8(*(u16 *)(*(u8 **)&D_0066AA84 + 0x4C), 0);
        func_001560F8_s(**(s32 **)&D_0066AA84, func_0024F070);
        D_0066AA80 = cb;
    } else {
        func_0024EF88();
        cb();
    }
}

extern s32 D_0066AAA0;
extern void (*D_0066AA80)(void);
void func_00131D68(s32, s32);

void func_0024F1D0(s32 a0) {
    func_00131D68(a0, D_0066AAA0);
    if (D_0066AA80 != NULL) {
        D_0066AA80();
    }
}

extern s32 D_002C5C4C;
extern s32 D_002C5C50;
extern s32 D_0046A6B0[];
void func_001560F8(s32, void*);

s32 func_0024F210(s32 a0, s32 a1) {
    s32 id;
    s32 n;

    D_0066AAA0 = a0;
    D_0066AA80 = (void (*)(void))a1;
    n = D_003010F8->unk_491;
    id = D_0046A6B0[n];
    if (D_002C5C4C != 0) {
        if (n == 1) {
            id = 0xC000A;
        } else if (n == 2) {
            id = 0xC000B;
        }
    } else if (D_002C5C50 != 0) {
        if (n == 1) {
            id = 0xC0008;
        } else if (n == 2) {
            id = 0xC0009;
        }
    }
    func_001560F8(id, func_0024F1D0);
    return id;
}

void __assert(s32 a0, s32 a1, s32 a2) {
    fiprintf(*(s32 *)(*(u8 **)&_impure_ptr + 0xC), D_004919E8, a2, a0, a1);
    abort();
}
