#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixNoRot", pppRyjMatrixNoRotCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixNoRot", func_0019B2A0);

extern sceVu0FVECTOR D_00372720;
void func_0019B458(sceVu0FVECTOR dst, sceVu0FVECTOR* a, sceVu0FVECTOR* b, f32 t) {
    s32 i = t;
    f32* v = D_00372720;

    a += i;
    b += i;
    v[2] = t - (f32)i;
    __asm__ volatile(
        "lqc2 $vf1, 0x0(%1)\n"
        "lqc2 $vf2, 0x10(%1)\n"
        "lqc2 $vf3, 0x0(%2)\n"
        "lqc2 $vf4, 0x10(%2)\n"
        "lqc2 $vf5, 0x0(%3)\n"
        "vsub.xyzw $vf10, $vf4, $vf3\n"
        "vmuly.xyzw $vf11, $vf3, $vf5y\n"
        "vmulx.xyzw $vf12, $vf3, $vf5x\n"
        "vsub.xyzw $vf13, $vf2, $vf1\n"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n"
        "vadd.xyzw $vf11, $vf11, $vf4\n"
        "vadd.xyzw $vf10, $vf10, $vf12\n"
        "vsub.xyzw $vf13, $vf13, $vf11\n"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n"
        "vadd.xyzw $vf10, $vf10, $vf13\n"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n"
        "vadd.xyzw $vf10, $vf10, $vf1\n"
        "sqc2 $vf10, 0x0(%0)\n"
        : : "r"(dst), "r"(a), "r"(b), "r"(v) : "memory");
}

typedef struct {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ f32 height;
    /* 0x14 */ u8 unk_14;
    /* 0x15 */ u8 world;
    /* 0x16 */ u8 unk_16;
    /* 0x17 */ u8 unk_17;
    /* 0x18 */ u8 unk_18;
} RyjMatrixNoRot;

extern sceVu0FMATRIX D_00615E70;

void func_0019B4D8(RyjMatrixNoRot* p, sceVu0FVECTOR top, sceVu0FVECTOR bottom) {
    sceVu0FVECTOR v;
    f32 h;

    v[3] = 1.0f;
    h = p->height;
    v[0] = 0.0f;
    v[2] = 0.0f;
    v[1] = h * 0.5f;
    sceVu0ApplyMatrix(top, ppvPObj.next->cmat, v);
    v[1] = -h * 0.5f;
    sceVu0ApplyMatrix(bottom, ppvPObj.next->cmat, v);
    if (p->world) {
        sceVu0ApplyMatrix(top, D_00615E70, top);
        sceVu0ApplyMatrix(bottom, D_00615E70, bottom);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixNoRot", func_0019B5C0);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixNoRot", func_0019B698);
