#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppRandDownIV", pppRandDownIVCalc);

s8 func_00189F20(s8 a, f32 b) {
    f32 f = a;

    return f * b - f;
}
