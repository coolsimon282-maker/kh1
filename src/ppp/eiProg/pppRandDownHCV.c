#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppRandDownHCV", pppRandDownHCVCalc);

f32 func_0018AA30(f32 arg0, f32 arg1) {
    return arg0 * arg1 - arg0;
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1
"
        "qmtc2.ni $8, $vf2
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vitof0.x $vf2, $vf2
"
        "vadd.x $vf1, $vf1, $vf2
"
        "qmfc2.ni %0, $vf1
"
        : "=r"(r) : : "$8");
    return r;
}

f32 func_0018AA40(u8 twice) {
    f32 r = vu0Rand();
    if (twice) {
        r += vu0Rand();
    } else {
        r += r;
    }
    return r;
}
