// Placeholder for code that hasn't been assigned to a source file yet (Final Mix offset 0x0EDC50).
// Functions can be matched here like in any other file; the file may be split later.
#include "common.h"
#include "sdk/ee/libdma.h"
#include "sdk/ee/libgraph.h"

static inline f32 sqrtf_inl(f32 x) {
    f32 r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

f32 func_001EDC50(f32* v) {
    return sqrtf_inl(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

f32 func_001EDC80(f32* a, f32* b) {
    sceVu0FVECTOR v;
    v[0] = a[0] - b[0];
    v[1] = a[1] - b[1];
    v[2] = a[2] - b[2];
    return sqrtf_inl(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

f32 func_001EDCD8(f32 x) {
    if (3.1415928f <= x) {
        x -= (f32)((s32)(x / 6.2831855f) + 1) * 3.1415928f * 2.0f;
    } else if (x < -3.1415928f) {
        x += (f32)((s32)(x / -6.2831855f) + 1) * 3.1415928f * 2.0f;
    }
    return x;
}

u32 func_001EDD88(u32 col, s32 s) {
    if (s != 0x80) {
        u32 a = (col >> 24) * s >> 7;
        if (a >= 0x100) {
            a = 0xFF;
        }
        ((u8*)&col)[3] = a;
    }
    return col;
}

u32 fm_func_001EDDC0(u32 x, u32 y, f32 t) {
    u32 r;
    ((u8*)&r)[0] = ((u8*)&x)[0] + (u32)((((u8*)&y)[0] - ((u8*)&x)[0]) * t);
    ((u8*)&r)[1] = ((u8*)&x)[1] + (u32)((((u8*)&y)[1] - ((u8*)&x)[1]) * t);
    ((u8*)&r)[2] = ((u8*)&x)[2] + (u32)((((u8*)&y)[2] - ((u8*)&x)[2]) * t);
    ((u8*)&r)[3] = ((u8*)&x)[3] + (u32)((((u8*)&y)[3] - ((u8*)&x)[3]) * t);
    return r;
}

u32 func_001EDF40(u32 x, u32 y) {
    u32 r;
    ((u8*)&r)[0] = (((u8*)&x)[0] + ((u8*)&y)[0]) >> 1;
    ((u8*)&r)[1] = (((u8*)&x)[1] + ((u8*)&y)[1]) >> 1;
    ((u8*)&r)[2] = (((u8*)&x)[2] + ((u8*)&y)[2]) >> 1;
    ((u8*)&r)[3] = (((u8*)&x)[3] + ((u8*)&y)[3]) >> 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/unsplit/seg_0EDC50", func_001EDFB8);
