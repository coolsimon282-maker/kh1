#include "ppp.h"

typedef struct {
    /* 0x00 */ sceVu0FVECTOR unk_00[4];
    /* 0x40 */ sceVu0FMATRIX mat;
} VRyjDrawMatrixWorldDtt;

extern sceVu0FMATRIX D_00615E70;

void pppRyjDrawMatrixWorldDttCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjDrawMatrixWorldDtt* v = (VRyjDrawMatrixWorldDtt*)&pobj->val[ctbl->useVal[1]];

    sceVu0CopyMatrix(v->mat, D_00615E70);
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDtt", pppRyjDrawMatrixWorldDttCalc);
