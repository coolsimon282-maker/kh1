#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSRandUpFV", pppSRandUpFVCalc);

f32 func_0018ADE0(f32 arg0, f32 arg1) {
    return arg0 * arg1;
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1\n"
        "qmtc2.ni $8, $vf2\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vrxor R, $vf2x\n"
        "vrnext.x $vf1, R\n"
        "vitof0.x $vf2, $vf2\n"
        "vadd.x $vf1, $vf1, $vf2\n"
        "qmfc2.ni %0, $vf1\n"
        : "=r"(r) : : "$8");
    return r;
}

// random number in (-1, 0]: -r, or the average of -r and -r2 when twice is set
f32 func_0018ADE8(u8 twice) {
    f32 r = vu0Rand();

    r = -r;
    if (twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    return r;
}
