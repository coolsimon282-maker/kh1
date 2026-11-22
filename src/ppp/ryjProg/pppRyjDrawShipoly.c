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

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawShipoly", func_0019C618);

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
