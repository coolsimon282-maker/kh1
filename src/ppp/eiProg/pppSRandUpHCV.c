#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSRandUpHCV", pppSRandUpHCVCalc);

s8 func_0018BA08(s16 a, f32 b) {
    return a * b;
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile("addi $8, $0, -1
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
                     : "=r"(r)
                     :
                     : "$8");
    return r;
}

f32 func_0018BA38(u8 twice) {
    f32 r = vu0Rand();

    r = -r;
    if (twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    return r;
}
