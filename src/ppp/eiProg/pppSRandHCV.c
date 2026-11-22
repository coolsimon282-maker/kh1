#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSRandHCV", pppSRandHCVCalc);

s8 func_0018B7F8(s16 a, f32 b) {
    return a * b;
}

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile("addi $8, $0, -1\n"
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
                     : "=r"(r)
                     :
                     : "$8");
    return r;
}

f32 func_0018B828(u8 twice) {
    f32 r = vu0Rand();

    if (twice) {
        r = (r + vu0Rand()) * 0.5f;
    }
    return r;
}
