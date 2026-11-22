// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0EDC50).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"

f32 func_001EDC50(sceVu0FVECTOR arg0) {
    return _sqrtf(arg0[0] * arg0[0] + arg0[1] * arg0[1] + arg0[2] * arg0[2]);
}

f32 func_001EDC80(f32 *p, f32 *q) {
    f32 d[3];

    d[0] = p[0] - q[0];
    d[1] = p[1] - q[1];
    d[2] = p[2] - q[2];
    return _sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0EDC50", func_001EDCD8);

u32 func_001EDD88(u32 arg0, s32 arg1) {
    u32 a;

    if (arg1 != 0x80) {
        a = ((arg0 >> 24) * arg1) >> 7;
        if (a > 0xFF) {
            a = 0xFF;
        }
        ((u8*)&arg0)[3] = a;
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0EDC50", fm_func_001EDDC0);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0EDC50", func_001EDF40);

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0EDC50", func_001EDFB8);
