#include "common.h"
#include "common_funcs.h"
#include "xnoodle.h"

#include "libgraph.h"
#include "eekernel.h"
#include "libdma.h"

// .data
#ifdef VERSION_FM
u16 D_002B6780[12] = {
    0x0, 0x1, 0x2, 0x2, 0x2, 0x3, 0x4, 0x4,
    0x4, 0x0, 0x0, 0x0,
};
f32 D_002B6798[10] = {
    0.0f, 0.0f, 0.0f, 0.29999998211860657f,
    -0.29999998211860657f, 0.0f, 0.0f, 0.29999998211860657f,
    -0.29999998211860657f, 0.0f,
};
u16 D_002B67C0[4] = {
    0x0, 0x6, 0x9, 0x14,
};
u16 D_002B67C8[4] = {
    0x0, 0x4, 0x8, 0x14,
};
sceVu0FVECTOR D_002B67D0 = {128.0f, 128.0f, 128.0f, 128.0f};
sceVu0FVECTOR D_002B67E0 = {128.0f, 128.0f, 128.0f, 58.0f};
sceVu0FVECTOR D_002B67F0[4] = {
    {-12.5f, -12.5f, 0.0f, 1.0f},
    {11.5f, -12.5f, 0.0f, 1.0f},
    {-12.5f, 11.5f, 0.0f, 1.0f},
    {11.5f, 11.5f, 0.0f, 1.0f},
};
sceVu0FVECTOR D_002B6830[4] = {
    {0.375f, 0.625f, 1.0f, 1.0f},
    {0.46875f, 0.625f, 1.0f, 1.0f},
    {0.375f, 0.8125f, 1.0f, 1.0f},
    {0.46875f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6870[4] = {
    {0.46875f, 0.625f, 1.0f, 1.0f},
    {0.5625f, 0.625f, 1.0f, 1.0f},
    {0.46875f, 0.8125f, 1.0f, 1.0f},
    {0.5625f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B68B0[4] = {
    {0.375f, 0.8125f, 1.0f, 1.0f},
    {0.46875f, 0.8125f, 1.0f, 1.0f},
    {0.375f, 1.0f, 1.0f, 1.0f},
    {0.46875f, 1.0f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B68F0[4] = {
    {0.46875f, 0.8125f, 1.0f, 1.0f},
    {0.5625f, 0.8125f, 1.0f, 1.0f},
    {0.46875f, 1.0f, 1.0f, 1.0f},
    {0.5625f, 1.0f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6930[4] = {
    {0.5625f, 0.625f, 1.0f, 1.0f},
    {0.65625f, 0.625f, 1.0f, 1.0f},
    {0.5625f, 0.8125f, 1.0f, 1.0f},
    {0.65625f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6970[4] = {
    {0.5625f, 0.8125f, 1.0f, 1.0f},
    {0.65625f, 0.8125f, 1.0f, 1.0f},
    {0.5625f, 1.0f, 1.0f, 1.0f},
    {0.65625f, 1.0f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B69B0[4] = {
    {0.1875f, 0.4375f, 1.0f, 1.0f},
    {0.28125f, 0.4375f, 1.0f, 1.0f},
    {0.1875f, 0.625f, 1.0f, 1.0f},
    {0.28125f, 0.625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B69F0[4] = {
    {0.1875f, 0.625f, 1.0f, 1.0f},
    {0.1875f, 0.4375f, 1.0f, 1.0f},
    {0.28125f, 0.625f, 1.0f, 1.0f},
    {0.28125f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6A30[4] = {
    {0.28125f, 0.4375f, 1.0f, 1.0f},
    {0.375f, 0.4375f, 1.0f, 1.0f},
    {0.28125f, 0.625f, 1.0f, 1.0f},
    {0.375f, 0.625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6A70[4] = {
    {0.28125f, 0.625f, 1.0f, 1.0f},
    {0.28125f, 0.4375f, 1.0f, 1.0f},
    {0.375f, 0.625f, 1.0f, 1.0f},
    {0.375f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6AB0[4] = {
    {0.0f, 0.4375f, 1.0f, 1.0f},
    {0.09375f, 0.4375f, 1.0f, 1.0f},
    {0.0f, 0.625f, 1.0f, 1.0f},
    {0.09375f, 0.625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6AF0[4] = {
    {0.0f, 0.625f, 1.0f, 1.0f},
    {0.0f, 0.4375f, 1.0f, 1.0f},
    {0.09375f, 0.625f, 1.0f, 1.0f},
    {0.09375f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6B30[4] = {
    {0.09375f, 0.4375f, 1.0f, 1.0f},
    {0.1875f, 0.4375f, 1.0f, 1.0f},
    {0.09375f, 0.625f, 1.0f, 1.0f},
    {0.1875f, 0.625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6B70[4] = {
    {0.09375f, 0.625f, 1.0f, 1.0f},
    {0.09375f, 0.4375f, 1.0f, 1.0f},
    {0.1875f, 0.625f, 1.0f, 1.0f},
    {0.1875f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6BB0[4] = {
    {0.65625f, 0.4375f, 1.0f, 1.0f},
    {0.75f, 0.4375f, 1.0f, 1.0f},
    {0.65625f, 0.625f, 1.0f, 1.0f},
    {0.75f, 0.625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6BF0[4] = {
    {0.65625f, 0.625f, 1.0f, 1.0f},
    {0.65625f, 0.4375f, 1.0f, 1.0f},
    {0.75f, 0.625f, 1.0f, 1.0f},
    {0.75f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6C30[4] = {
    {0.75f, 0.4375f, 1.0f, 1.0f},
    {0.84375f, 0.4375f, 1.0f, 1.0f},
    {0.75f, 0.625f, 1.0f, 1.0f},
    {0.84375f, 0.625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6C70[4] = {
    {0.75f, 0.625f, 1.0f, 1.0f},
    {0.75f, 0.4375f, 1.0f, 1.0f},
    {0.84375f, 0.625f, 1.0f, 1.0f},
    {0.84375f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6CB0[4] = {
    {-24.5f, -24.5f, 0.0f, 1.0f},
    {11.5f, -24.5f, 0.0f, 1.0f},
    {-24.5f, 11.5f, 0.0f, 1.0f},
    {11.5f, 11.5f, 0.0f, 1.0f},
};
sceVu0FVECTOR D_002B6CF0[4] = {
    {-12.5f, -24.5f, 0.0f, 1.0f},
    {23.5f, -24.5f, 0.0f, 1.0f},
    {-12.5f, 11.5f, 0.0f, 1.0f},
    {23.5f, 11.5f, 0.0f, 1.0f},
};
sceVu0FVECTOR D_002B6D30[4] = {
    {-24.5f, -12.5f, 0.0f, 1.0f},
    {11.5f, -12.5f, 0.0f, 1.0f},
    {-24.5f, 23.5f, 0.0f, 1.0f},
    {11.5f, 23.5f, 0.0f, 1.0f},
};
sceVu0FVECTOR D_002B6D70[4] = {
    {-12.5f, -12.5f, 0.0f, 1.0f},
    {23.5f, -12.5f, 0.0f, 1.0f},
    {-12.5f, 23.5f, 0.0f, 1.0f},
    {23.5f, 23.5f, 0.0f, 1.0f},
};
sceVu0FVECTOR D_002B6DB0[4] = {
    {0.375f, 0.0f, 1.0f, 1.0f},
    {0.515625f, 0.0f, 1.0f, 1.0f},
    {0.375f, 0.28125f, 1.0f, 1.0f},
    {0.515625f, 0.28125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6DF0[4] = {
    {0.515625f, 0.0f, 1.0f, 1.0f},
    {0.65625f, 0.0f, 1.0f, 1.0f},
    {0.515625f, 0.28125f, 1.0f, 1.0f},
    {0.65625f, 0.28125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6E30[4] = {
    {0.375f, 0.28125f, 1.0f, 1.0f},
    {0.515625f, 0.28125f, 1.0f, 1.0f},
    {0.375f, 0.5625f, 1.0f, 1.0f},
    {0.515625f, 0.5625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6E70[4] = {
    {0.515625f, 0.28125f, 1.0f, 1.0f},
    {0.65625f, 0.28125f, 1.0f, 1.0f},
    {0.515625f, 0.5625f, 1.0f, 1.0f},
    {0.65625f, 0.5625f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6EB0[4] = {
    {0.0f, 0.625f, 1.0f, 1.0f},
    {0.09375f, 0.625f, 1.0f, 1.0f},
    {0.0f, 0.8125f, 1.0f, 1.0f},
    {0.09375f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6EF0[4] = {
    {0.09375f, 0.625f, 1.0f, 1.0f},
    {0.1875f, 0.625f, 1.0f, 1.0f},
    {0.09375f, 0.8125f, 1.0f, 1.0f},
    {0.1875f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6F30[4] = {
    {0.0f, 0.8125f, 1.0f, 1.0f},
    {0.09375f, 0.8125f, 1.0f, 1.0f},
    {0.0f, 1.0f, 1.0f, 1.0f},
    {0.09375f, 1.0f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6F70[4] = {
    {0.09375f, 0.8125f, 1.0f, 1.0f},
    {0.1875f, 0.8125f, 1.0f, 1.0f},
    {0.09375f, 1.0f, 1.0f, 1.0f},
    {0.1875f, 1.0f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6FB0[4] = {
    {0.1875f, 0.625f, 1.0f, 1.0f},
    {0.28125f, 0.625f, 1.0f, 1.0f},
    {0.1875f, 0.8125f, 1.0f, 1.0f},
    {0.28125f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B6FF0[4] = {
    {0.28125f, 0.625f, 1.0f, 1.0f},
    {0.375f, 0.625f, 1.0f, 1.0f},
    {0.28125f, 0.8125f, 1.0f, 1.0f},
    {0.375f, 0.8125f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B7030[4] = {
    {0.1875f, 0.8125f, 1.0f, 1.0f},
    {0.28125f, 0.8125f, 1.0f, 1.0f},
    {0.1875f, 1.0f, 1.0f, 1.0f},
    {0.28125f, 1.0f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B7070[4] = {
    {0.28125f, 0.8125f, 1.0f, 1.0f},
    {0.375f, 0.8125f, 1.0f, 1.0f},
    {0.28125f, 1.0f, 1.0f, 1.0f},
    {0.375f, 1.0f, 1.0f, 1.0f},
};
u64 D_002B70B0[36] = {
    0x19C501DC60AULL, 0x19C5023C78AULL,
    0x1FC681DC60AULL, 0x1FC6823C78AULL,
    0x19C5029C90AULL, 0x1FC6829C90AULL,
    0x13C3811C30AULL, 0x13C3811C30AULL,
    0x13C3817C48AULL, 0x13C3817C48AULL,
    0x8C0020C60AULL, 0x8C0029C84AULL,
    0x11C2420C60AULL, 0x11C2429C84AULL,
    0x19C5005C00AULL, 0x19C500BC18AULL,
    0x1FC6805C00AULL, 0x1FC680BC18AULL,
    0x19C5011C30AULL, 0x19C5017C48AULL,
    0x1FC6811C30AULL, 0x1FC6817C48AULL,
    0xDC0005C00AULL, 0xDC000BC18AULL,
    0xDC002FCA8AULL, 0xDC0011C30AULL,
    0xDC0017C48AULL, 0xDC0035CC0AULL,
    0x13C3805C00AULL, 0x13C3805C00AULL,
    0x13C380BC18AULL, 0x13C380BC18AULL,
    0x13C382FCA8AULL, 0x13C382FCA8AULL,
    0x13C3835CC0AULL, 0x13C3835CC0AULL,
};
sceVu0FVECTOR D_002B71D0[4] = {
    {-12.5f, -0.5f, 0.0f, 1.0f},
    {11.5f, -0.5f, 0.0f, 1.0f},
    {-12.5f, 55.5f, 0.0f, 1.0f},
    {11.5f, 55.5f, 0.0f, 1.0f},
};
sceVu0FVECTOR D_002B7210[4] = {
    {0.09375f, 0.0f, 1.0f, 1.0f},
    {0.1875f, 0.0f, 1.0f, 1.0f},
    {0.09375f, 0.4375f, 1.0f, 1.0f},
    {0.1875f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B7250[4] = {
    {0.0f, 0.0f, 1.0f, 1.0f},
    {0.09375f, 0.0f, 1.0f, 1.0f},
    {0.0f, 0.4375f, 1.0f, 1.0f},
    {0.09375f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B7290[4] = {
    {0.65625f, 0.0f, 1.0f, 1.0f},
    {0.75f, 0.0f, 1.0f, 1.0f},
    {0.65625f, 0.4375f, 1.0f, 1.0f},
    {0.75f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B72D0[4] = {
    {0.28125f, 0.0f, 1.0f, 1.0f},
    {0.375f, 0.0f, 1.0f, 1.0f},
    {0.28125f, 0.4375f, 1.0f, 1.0f},
    {0.375f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B7310[4] = {
    {0.1875f, 0.0f, 1.0f, 1.0f},
    {0.28125f, 0.0f, 1.0f, 1.0f},
    {0.1875f, 0.4375f, 1.0f, 1.0f},
    {0.28125f, 0.4375f, 1.0f, 1.0f},
};
sceVu0FVECTOR D_002B7350[4] = {
    {0.75f, 0.0f, 1.0f, 1.0f},
    {0.84375f, 0.0f, 1.0f, 1.0f},
    {0.75f, 0.4375f, 1.0f, 1.0f},
    {0.84375f, 0.4375f, 1.0f, 1.0f},
};
// GIF packets and the DMA ref tags that send them
u64 D_002B7390[4] = {
    0x1000000000008001ULL, 0xE,
    0x800D0, 0x4C,
};
sceDmaTag D_002B73B0 = {2, 0, 0, (sceDmaTag*)D_002B7390};
u64 D_002B73C0[4] = {
    0x1000000000008001ULL, 0xE,
    0x10A008C, 0x4C,
};
sceDmaTag D_002B73E0 = {2, 0, 0, (sceDmaTag*)D_002B73C0};
u64 D_002B73F0[12] = {
    0x5000000000008001ULL, 0xEEEEE,
    0x0, 0x3F,
    0x3000D, 0x47,
    0x2007FF05E1B11800ULL, 0x6,
    0x60, 0x14,
    0x44, 0x42,
};
sceDmaTag D_002B7450 = {6, 0, 0, (sceDmaTag*)D_002B73F0};
u64 D_002B7460[6] = {
    0x2000000000008001ULL, 0xEE,
    0x0, 0x3F,
    0x2007FE85E1B11800ULL, 0x6,
};
sceDmaTag D_002B7490 = {3, 0, 0, (sceDmaTag*)D_002B7460};
u64 D_002B74A0[4] = {
    0x1000000000008001ULL, 0xE,
    0x5, 0x8,
};
sceDmaTag D_002B74C0 = {2, 0, 0, (sceDmaTag*)D_002B74A0};
#endif
sceVu0FVECTOR D_002B3A20 = {0.0f, 0.0f, -530.0f, 0.0f};
sceVu0FVECTOR D_002B3A30 = {0.0f, 0.0f, 1.0f, 1.0f};
sceVu0FVECTOR D_002B3A40 = {0.0f, 1.0f, 0.0f, 1.0f};
s32 D_002B3A50[36] = {0};
s32 D_002B3AE0[4] = {0};
typedef struct {
    /* 0x0 */ void (*unk_0)(IOReadTask*);
    /* 0x4 */ IOReadTask* unk_4;
    /* 0x8 */ s32 unk_8;
} XNoodleSlot; // size = 0xC

union {
    s32 raw[8];
    XNoodleSlot slot[2];
} D_002B3AF0 = {{0}};
s32 D_002B3B10[0x1000] = {0};

extern sceGsLoadImage D_002B8700;
extern sceVu0FMATRIX D_002B9040;
extern s32 D_002B9668;

extern s32 D_0048DB00; // gp0 value

// .bss
sceVu0FMATRIX D_0048EC10;
sceVu0FMATRIX D_0048EC50;
sceVu0FMATRIX D_0048EC90;
s32 D_0048ECD4;
s32 D_0048ECD8;
s32 D_0048ECDC;
s32 D_0048ECE0;
u_long128* D_0048ED00;

extern volatile s32 D_00495258;

// Hand-written VU0 loop (the original is assembly inside C).
void func_0010A1F8(u64* pkt, void* arg1, void* arg2, void* arg3, s32 count, void* arg5, void* arg6) {
    __asm__ volatile(
        ".set noreorder\n"
        "daddu $11, $9, $0\n"
        "lqc2 $vf4, 0x0($5)\n"
        "lqc2 $vf5, 0x10($5)\n"
        "lqc2 $vf6, 0x20($5)\n"
        "lqc2 $vf7, 0x30($5)\n"
        "lqc2 $vf24, 0x0($11)\n"
        "lqc2 $vf25, 0x0($10)\n"
        "vftoi0.xyzw $vf25, $vf25\n"
        "1:\n"
        "lqc2 $vf8, 0x0($6)\n"
        "vadd.xy $vf8, $vf24, $vf8\n"
        "vmulax.xyzw ACC, $vf4, $vf8x\n"
        "vmadday.xyzw ACC, $vf5, $vf8y\n"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n"
        "vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vdiv Q, $vf0w, $vf12w\n"
        "lqc2 $vf9, 0x0($7)\n"
        "addi $8, $8, -1\n"
        "addi $6, $6, 0x10\n"
        "addi $7, $7, 0x10\n"
        "sqc2 $vf25, 0x10($4)\n"
        "vwaitq\n"
        "vmulq.xyzw $vf15, $vf9, Q\n"
        "vmulq.xyzw $vf12, $vf12, Q\n"
        "vftoi4.xyzw $vf13, $vf12\n"
        "sqc2 $vf15, 0x0($4)\n"
        "sqc2 $vf13, 0x20($4)\n"
        "bne $0, $8, 1b\n"
        "addi $4, $4, 0x30\n"
        ".set reorder\n"
        : : : "$4", "$6", "$7", "$8", "$11", "memory");
}

extern u64 D_002B70B0[];
extern void* D_00495250;
void func_0010A1F8(u64* pkt, void* arg1, void* arg2, void* arg3, s32 count, void* arg5, void* arg6);

s32 func_0010A270(u64* pkt, s32 arg1, void* arg2, void* arg3, void* arg4, s32 arg5, void* arg6) {
    pkt[0] = D_002B70B0[arg5];
    pkt[1] = 0;
    pkt += 2;
    func_0010A1F8(pkt, arg2, arg6, arg4, 4, arg3, D_00495250);
    ((s32*)pkt)[0x1C / 4] = 0x8000;
    ((s32*)pkt)[0x4C / 4] = 0x8000;
    return arg1 + 0xD;
}

INCLUDE_ASM("asm/nonmatchings/xnoodle", func_0010A2F0);

INCLUDE_ASM("asm/nonmatchings/xnoodle", func_0010A4A0);

void func_0010AD58(u32 arg0) {
    u8* pal = (u8*)(arg0 + 0x8000);
    s32 i;

    sceGsSetDefLoadImage(&D_002B8700, 0x1800, 4, 0x1B, 0, 0, 256, 128);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, (u_long128*)arg0);
    sceGsSyncPath(0, 0);
    sceGsSetDefLoadImage(&D_002B8700, 0x3FF4, 1, 0, 0, 0, 16, 16);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, (u_long128*)pal);
    {
        u8* p = pal;
        for (i = 0; i < 256; i++) {
            *p++ = 0;
            *p++ = 0;
            *p = 0;
            p += 2;
        }
    }
    sceGsSyncPath(0, 0);
    sceGsSetDefLoadImage(&D_002B8700, 0x3FF8, 1, 0, 0, 0, 16, 16);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, (u_long128*)pal);
    sceGsSyncPath(0, 0);
}

void func_0010AE98(XNoodle* arg0) {
    arg0->unk_38 = 0.0f;
    arg0->unk_3C = 1.0f;
    arg0->unk_5C = 1.0f;
    arg0->unk_58 = 1.0f;
}

void func_0010AEB8(f32* arg0) {
    sceVu0ViewScreenMatrix(D_0048EC90, 512.0f, 1.0f, 1.0f, arg0[12] + 2048.0f, arg0[13] + 2048.0f, 1.0f,
                           16777000.0f, 2.0f, 4000000.0f);
}

void func_0010AF38(sceVu0FMATRIX arg0, sceVu0FMATRIX arg1, sceVu0FVECTOR arg2) {
    sceVu0FMATRIX m;

    sceVu0UnitMatrix(m);
    m[0][0] = arg2[0];
    m[1][1] = arg2[1];
    m[2][2] = arg2[2];
    sceVu0MulMatrix(arg0, arg1, m);
}

void func_0010AFA0(sceVu0FMATRIX arg0, XNoodle* arg1) {
    sceVu0FMATRIX m;

    sceVu0RotMatrixX(m, D_002B9040, arg1->unk_20);
    sceVu0MulMatrix(m, D_0048EC10, m);
    sceVu0MulMatrix(arg0, D_0048EC90, m);
}

void func_0010B000(sceVu0FMATRIX arg0, XNoodle* arg1, sceVu0FVECTOR arg2) {
    sceVu0FMATRIX m;

    f32 val = arg1->unk_1C;
    if (180.0f < val) {
        val -= 180.0f;
    } else {
        val += -180.0f;
    }

    sceVu0RotMatrixZ(m, D_002B9040, (val / 180.0f) * PI);
    sceVu0TransMatrix(m, m, arg2);
    sceVu0MulMatrix(m, D_0048EC10, m);
    sceVu0MulMatrix(arg0, D_0048EC90, m);
}

INCLUDE_ASM("asm/nonmatchings/xnoodle", func_0010B0D0);

INCLUDE_ASM("asm/nonmatchings/xnoodle", func_0010B428);

INCLUDE_ASM("asm/nonmatchings/xnoodle", func_0010B810);

void func_0010BB10(XNoodle* arg0, s32 arg1) {
    if (arg0->unk_18 != 0) {
        arg0->unk_14 = arg1;
        arg0->unk_18 = 3;
        func_0010E230(&arg0->unk_80);
    }
}

typedef struct {
    /* 0x00 */ char pad_00[8];
    /* 0x08 */ u16 x;
    /* 0x0A */ u16 y;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ u8 unk_10;
    /* 0x11 */ u8 pad_11;
    /* 0x12 */ u8 unk_12;
    /* 0x13 */ u8 unk_13;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ char pad_18[8];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ void* unk_24;
    /* 0x28 */ s32 unk_28;
} XNoodleSpr;

typedef struct {
    /* 0x00 */ char pad_00[4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char pad_06[4];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char pad_1C[4];
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ char pad_24[0xC];
    /* 0x30 */ sceVu0FVECTOR pos;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ f32 unk_44;
    /* 0x48 */ char pad_48[0x28];
    /* 0x70 */ sceVu0FVECTOR unk_70;
    /* 0x80 */ s32 unk_80;
    /* 0x84 */ s32 unk_84;
} XNoodleObj;

typedef struct {
    /* 0x00 */ char pad_00[0x1C];
    /* 0x1C */ XNoodleObj* obj;
    /* 0x20 */ XNoodleSpr* spr;
} XNoodleNode;

extern u16 D_002B67C0[];
extern u16 D_002B67C8[];
extern f32 D_002B6798[];
extern u16 D_002B6780[];
XNoodleNode* TaskList_Add(s32* list, s32 id, void (*func)());
void func_0010B810();

void func_0010BB50(XNoodleObj* obj, s32 arg1) {
    XNoodleNode* node;
    XNoodleSpr* spr;
    XNoodleSpr* spr2;
    s16 z;

    node = TaskList_Add(D_002B3AE0, D_0048ECD4++, func_0010B810);
    if (node == NULL) {
        return;
    }
    node->spr = (XNoodleSpr*)&obj->unk_80;
    node->obj = obj;
    sceVu0CopyVector(obj->unk_70, obj->pos);
    obj->unk_18 = 0;
    obj->unk_14 = arg1;
    spr = node->spr;
    spr->x = obj->pos[0] + 254.0f - obj->unk_40 * 12.0f;
    spr->y = obj->pos[1] + 180.0f - obj->unk_44 * 12.0f;
    z = obj->pos[0] + 256.0f;
    obj->unk_84 = 0;
    spr->unk_12 = 0;
    spr->unk_24 = obj;
    spr2 = node->spr;
    spr2->unk_20 = 0;
    spr->unk_0C = z;
    spr2->unk_13 = 0;
    spr2->unk_0E = 0;
    node->spr->unk_13 &= ~1;
    obj->unk_10 = D_002B67C0[obj->unk_0C];
    node->spr->unk_14 = 0.5f;
    obj->unk_12 = D_002B67C8[obj->unk_0E];
    obj->unk_20 = D_002B6798[obj->unk_04];
    obj->unk_0A = D_002B6780[obj->unk_04];
    node->spr->unk_28 = 0;
    switch (obj->unk_04) {
        case 0:
            node->spr->unk_10 = 0;
            node->spr->unk_13 &= ~2;
            break;
        case 1:
            node->spr->unk_10 = 0;
            node->spr->unk_13 |= 2;
            break;
        default:
            node->spr->unk_10 = 1;
            node->spr->unk_13 |= 2;
            break;
    }
}

s32 func_0010BDA8(void) {
    TaskList_UpdateMatching(&D_002B3AE0, 0);
    D_0048ECD4 = 0;
    return 0;
}

void func_0010BDD8(void) {
    sceVu0CameraMatrix(D_0048EC50, D_002B3A20, D_002B3A30, D_002B3A40);
}

void* func_0010BE10(void) {
    D_0048ECD4 = 0;
    func_0010BDD8();
    TaskList_Init(D_002B3AE0, D_002B3A50, 0x24, 4);
    return TaskSystem_AddTask(180200, func_0010BDA8);
}

void func_0010BE60(void) {
    s32 i;

    while (1) {
        WaitSema(D_0048ECE0);
        for (i = 0; i < 2; i++) {
            if (D_002B3AF0.slot[i].unk_0 != 0) {
                D_002B3AF0.slot[i].unk_0(D_002B3AF0.slot[i].unk_4);
                D_002B3AF0.slot[i].unk_8 = 1;
            }
        }
    }
}

void func_0010BEE8(void) {
    WaitSema(D_0048ECE0);
}

void func_0010BF08(void (*arg0)(IOReadTask*), IOReadTask* arg1) {
    XNoodleSlot* slot = D_002B3AF0.slot;
    s32 i;

    for (i = 0; i < 2; i++, slot++) {
        if (slot->unk_0 == 0) {
            slot->unk_0 = arg0;
            slot->unk_4 = arg1;
            slot->unk_8 = 0;
            return;
        }
    }
}

void func_0010BF50(void (*arg0)(IOReadTask*)) {
    XNoodleSlot* slot = D_002B3AF0.slot;
    s32 i;

    for (i = 0; i < 2; i++, slot++) {
        if (arg0 == slot->unk_0) {
            slot->unk_0 = 0;
            slot->unk_4 = 0;
            slot->unk_8 = 0;
            return;
        }
    }
}

// include/xnoodle.h declares this `void func_0010BF98();`, but it returns whether an IO slot is in use.
s32 func_0010BF98_s32(void) __asm__("func_0010BF98");

s32 func_0010BF98_s32(void) {
    XNoodleSlot* slot = D_002B3AF0.slot;
    s32 i;

    for (i = 0; i < 2; i++, slot++) {
        if (slot->unk_0 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_0010BFD8(void) {
    XNoodleSlot* slot = D_002B3AF0.slot;
    s32 i;

    for (i = 0; i < 2; i++, slot++) {
        slot->unk_0 = 0;
        slot->unk_4 = 0;
        slot->unk_8 = 0;
    }
}

extern s32 D_00494050;
extern s32 D_0049525C;
void func_0010BE60(void);

void func_0010C010(void) {
    struct ThreadParam tp;
    u8 unused[0x20];
    struct SemaParam sp;
    s32 id;

    func_0010BFD8();
    ChangeThreadPriority(GetThreadId(), 30);
    sp.maxCount = 1;
    sp.currentCount = 0;
    sp.initCount = 0;
    sp.option = 0;
    D_00495258 = CreateSema(&sp);
    D_0048ECE0 = CreateSema(&sp);
    tp.entry = (void (*)(void*))func_0010BE60;
    tp.stack = D_002B3B10;
    tp.stackSize = 0x4000;
    tp.initPriority = 0x28;
    tp.gpReg = &D_00494050;
    id = CreateThread(&tp);
    D_0049525C = id;
    if (id != -1) {
        StartThread(id, NULL);
    }
}

void func_0010C0E0(void) {
    SignalSema(D_0048ECE0);
    WaitSema(D_00495258);
}

void func_0010C110(void) {
    struct SemaParam param;

    iReferSemaStatus(D_00495258, &param);
    if (param.numWaitThreads != 0) {
        iSignalSema(D_00495258);
    }
}

void func_0010C158(void) {
    void* p0 = func_00155ED8(0x34, 0xC);
    s32 val = func_00120438("kanji.knj", p0);
    memcpy(&D_0048ED00, p0, val);
}

void func_00109230(u8*, u8*);

void func_0010C1A8(u8* p) {
    u8* q = p + 0x10;
    u8* data = q + *(u16*)(q + 0xC);

    func_00109230(data, data + *(s32*)(q + 8));
}

s32 func_0010C1D0(s16 dest, u_long128* src) {
    sceGsSetDefLoadImage(&D_002B8700, dest, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    sceGsSyncPath(0, 0);
    FlushCache(WRITEBACK_DCACHE);
    return sceGsExecLoadImage(&D_002B8700, src);
}

s32 func_0010C248(void) {
    if (D_002B9668 < 7) {
        if (D_002B9668 >= 5) {
            return 0;
        }
    }

    sceGsSetDefLoadImage(&D_002B8700, 0x3600, 4, SCE_GS_PSMCT32, 0, 0, 256, 256);
    sceGsSyncPath(0, 0);
    FlushCache(WRITEBACK_DCACHE);
    sceGsExecLoadImage(&D_002B8700, &D_0048ED00);
    return 0;
}
