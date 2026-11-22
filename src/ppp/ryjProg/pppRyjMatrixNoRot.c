#include "ppp.h"

extern sceVu0FMATRIX D_00615EB0;

// v.xyz *= s (hand-written VU0 macro code)
static inline void vu0ScaleXYZ(f32* v, f32 s) {
    __asm__ volatile(
        "qmtc2.ni %1, $vf9\n"
        "lqc2 $vf10, 0x0(%0)\n"
        "vmulx.xyz $vf10, $vf10, $vf9x\n"
        "sqc2 $vf10, 0x0(%0)\n"
        : : "r"(v), "r"(s));
}

void pppRyjMatrixNoRotCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    f32* scl = (f32*)&pobj->val[ctbl->useVal[2]];

    sceVu0InversMatrix(ppvPObj.next->cmat, D_00615EB0);
    vu0ScaleXYZ(ppvPObj.next->cmat[0], scl[0]);
    vu0ScaleXYZ(ppvPObj.next->cmat[1], scl[1]);
    vu0ScaleXYZ(ppvPObj.next->cmat[2], scl[2]);
    ppvPObj.next->cmat[3][0] = pos[0];
    ppvPObj.next->cmat[3][1] = pos[1];
    ppvPObj.next->cmat[3][2] = pos[2];
}

extern sceVu0FVECTOR D_00372710;

// hand-written VU0 code (whole body)
void func_0019B2A0(sceVu0FVECTOR* a, s32 n, sceVu0FVECTOR* out) {
    sceVu0FVECTOR tmp[32];

    __asm__ volatile(
        ".set noreorder\n"
        "addi $9, $5, -0x1\n"
        "addi $10, $5, -0x2\n"
        "lqc2 $vf1, 0x0(%0)\n"
        "sqc2 $vf0, 0x0($6)\n"
        "sll $11, $9, 4\n"
        "add $11, $11, $6\n"
        "sqc2 $vf0, 0x0($11)\n"
        "daddu $8, $9, $0\n"
        "daddu $11, $0, $0\n"
        "1:\n"
        "blez $8, 2f\n"
        "addi $8, $8, -0x1\n"
        "sll $12, $11, 4\n"
        "addi $13, $12, 0x10\n"
        "add $14, $12, $4\n"
        "add $15, $13, $4\n"
        "add $16, $13, $29\n"
        "lqc2 $vf10, 0x0($14)\n"
        "lqc2 $vf11, 0x0($15)\n"
        "vsub.xyzw $vf10, $vf11, $vf10\n"
        "sqc2 $vf10, 0x0($16)\n"
        "b 1b\n"
        "addi $11, $11, 0x1\n"
        "2:\n"
        "lqc2 $vf10, 0x20($29)\n"
        "lqc2 $vf11, 0x10($29)\n"
        "lqc2 $vf12, 0x0($6)\n"
        "vsub.xyzw $vf10, $vf10, $vf11\n"
        "vsub.xyzw $vf10, $vf10, $vf12\n"
        "sqc2 $vf10, 0x10($6)\n"
        "vaddx.xyzw $vf11, $vf0, $vf1x\n"
        "sqc2 $vf11, 0x10($29)\n"
        "daddu $8, $10, $0\n"
        "addi $8, $8, -0x1\n"
        "addi $11, $0, 0x1\n"
        "3:\n"
        "blez $8, 4f\n"
        "addi $8, $8, -0x1\n"
        "sll $12, $11, 4\n"
        "addi $13, $12, 0x10\n"
        "addi $14, $13, 0x10\n"
        "add $15, $12, $29\n"
        "add $16, $13, $29\n"
        "add $17, $14, $29\n"
        "add $18, $13, $6\n"
        "add $19, $12, $6\n"
        "lqc2 $vf10, 0x0($15)\n"
        "lqc2 $vf11, 0x0($16)\n"
        "lqc2 $vf12, 0x0($17)\n"
        "lqc2 $vf13, 0x0($19)\n"
        "vdiv Q, $vf0w, $vf10x\n"
        "vwaitq\n"
        "vaddq.x $vf15, $vf0, Q\n"
        "vdiv Q, $vf0w, $vf10y\n"
        "vwaitq\n"
        "vaddq.y $vf15, $vf0, Q\n"
        "vdiv Q, $vf0w, $vf10z\n"
        "vwaitq\n"
        "vaddq.z $vf15, $vf0, Q\n"
        "vsub.xyzw $vf16, $vf12, $vf11\n"
        "vmul.xyzw $vf17, $vf13, $vf15\n"
        "vsub.xyzw $vf17, $vf16, $vf17\n"
        "sqc2 $vf17, 0x0($18)\n"
        "vmuly.xyzw $vf18, $vf15, $vf1y\n"
        "vaddx.xyzw $vf18, $vf18, $vf1x\n"
        "sqc2 $vf18, 0x0($16)\n"
        "b 3b\n"
        "addi $11, $11, 0x1\n"
        "4:\n"
        "sll $11, $9, 4\n"
        "add $11, $11, $6\n"
        "sll $12, $10, 4\n"
        "add $12, $12, $6\n"
        "lqc2 $vf10, 0x0($11)\n"
        "lqc2 $vf11, 0x0($12)\n"
        "vsub.xyzw $vf11, $vf11, $vf10\n"
        "sqc2 $vf11, 0x0($12)\n"
        "daddu $11, $10, $0\n"
        "5:\n"
        "blezl $11, 6f\n"
        "nop\n"
        "sll $12, $11, 4\n"
        "addi $13, $12, 0x10\n"
        "add $15, $12, $29\n"
        "add $16, $12, $6\n"
        "add $17, $13, $6\n"
        "lqc2 $vf10, 0x0($15)\n"
        "lqc2 $vf11, 0x0($16)\n"
        "lqc2 $vf12, 0x0($17)\n"
        "vsub.xyzw $vf11, $vf11, $vf12\n"
        "vdiv Q, $vf11x, $vf10x\n"
        "vwaitq\n"
        "vaddq.x $vf15, $vf0, Q\n"
        "vdiv Q, $vf11y, $vf10y\n"
        "vwaitq\n"
        "vaddq.y $vf15, $vf0, Q\n"
        "vdiv Q, $vf11z, $vf10z\n"
        "vwaitq\n"
        "vaddq.z $vf15, $vf0, Q\n"
        "sqc2 $vf15, 0x0($16)\n"
        "b 5b\n"
        "addi $11, $11, -0x1\n"
        "6:\n"
        ".set reorder\n"
        : : "r"(D_00372710)
        : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17", "$18", "$19", "memory");
}

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

void func_0019B5C0(RyjMatrixNoRot* p, s32* x, s32* w, s32* y, s32* h) {
    s32 th = 0x1000;
    s32 tx = 0;
    s32 tw = 0x1000;

    switch (p->unk_16) {
    case 1:
        tw = 0x800;
        break;
    case 2:
        tw = 0x400;
        break;
    }
    switch (p->unk_17) {
    case 1:
        th = 0x800;
        break;
    case 2:
        th = 0x400;
        break;
    }
    switch (p->unk_18) {
    case 1:
        tx = 0x400;
        tw += 0x400;
        break;
    case 2:
        tx = 0x800;
        tw += 0x800;
        break;
    case 3:
        tx = 0xC00;
        tw += 0xC00;
        break;
    }
    *x = tx + 0x10;
    *w = tw - 0x10;
    *y = 0x10;
    *h = th - 0x10;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixNoRot", func_0019B698);
