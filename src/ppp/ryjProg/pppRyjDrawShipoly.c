#include "ppp.h"

typedef struct {
    /* 0x0 */ u32 unFrameCt;
    /* 0x4 */ u8 bSmp;
    /* 0x5 */ u8 bStandby;
    /* 0x6 */ char dummy0[2];
    /* 0x8 */ pppFVECTOR* pvecSmp;
} VRyjDrawShipoly;

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", pppRyjDrawShipolyCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", pppRyjDrawShipolyDraw);

void pppRyjDrawShipolyCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipoly* p = (VRyjDrawShipoly*)&pobj->val[ctbl->useVal[2]];
    p->pvecSmp = NULL;
    p->unFrameCt = 0;
    p->bSmp = FALSE;
    p->bStandby = TRUE;
}

void pppRyjDrawShipolyDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawShipoly* p = (VRyjDrawShipoly*)&pobj->val[ctbl->useVal[2]];

    if (p->pvecSmp != NULL) {
        pppFree(ppvEnv, p->pvecSmp);
        p->pvecSmp = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", func_0019C460);

extern f32 D_00372740[4];

void func_0019C618(f32* out, u8* a, u8* b, f32 t) {
    s32 i = t;
    f32* v = D_00372740;
    v[2] = t - (f32)i;
    a += i * 16;
    b += i * 16;
    __asm__ volatile(
        "lqc2 $vf1,0x0(%1)\n\t"
        "lqc2 $vf2,0x10(%1)\n\t"
        "lqc2 $vf3,0x0(%2)\n\t"
        "lqc2 $vf4,0x10(%2)\n\t"
        "lqc2 $vf5,0x0(%3)\n\t"
        "vsub.xyzw $vf10,$vf4,$vf3\n\t"
        "vmuly.xyzw $vf11,$vf3,$vf5y\n\t"
        "vmulx.xyzw $vf12,$vf3,$vf5x\n\t"
        "vsub.xyzw $vf13,$vf2,$vf1\n\t"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n\t"
        "vadd.xyzw $vf11,$vf11,$vf4\n\t"
        "vadd.xyzw $vf10,$vf10,$vf12\n\t"
        "vsub.xyzw $vf13,$vf13,$vf11\n\t"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n\t"
        "vadd.xyzw $vf10,$vf10,$vf13\n\t"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n\t"
        "vadd.xyzw $vf10,$vf10,$vf1\n\t"
        "sqc2 $vf10,0x0(%0)"
        : : "r"(out), "r"(a), "r"(b), "r"(v) : "memory");
}

typedef struct {
    /* 0x00 */ char pad_00[0x21];
    /* 0x21 */ u8 w;
    /* 0x22 */ u8 h;
    /* 0x23 */ u8 x;
} PRyjShipolyTex;

void func_0019C698(PRyjShipolyTex* p, s32* x0, s32* x1, s32* y0, s32* y1) {
    s32 x = 0;
    s32 w = 0x1000;
    s32 h = 0x1000;

    switch (p->w) {
        case 1:
            w = 0x800;
            break;
        case 2:
            w = 0x400;
            break;
    }
    switch (p->h) {
        case 1:
            h = 0x800;
            break;
        case 2:
            h = 0x400;
            break;
    }
    switch (p->x) {
        case 1:
            x = 0x400;
            w += 0x400;
            break;
        case 2:
            x = 0x800;
            w += 0x800;
            break;
        case 3:
            x = 0xC00;
            w += 0xC00;
            break;
    }
    *x0 = x + 0x10;
    *x1 = w - 0x10;
    *y0 = 0x10;
    *y1 = h - 0x10;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", func_0019C770);
