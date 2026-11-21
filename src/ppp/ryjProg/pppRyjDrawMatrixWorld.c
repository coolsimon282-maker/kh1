#include "ppp.h"

extern sceVu0FMATRIX D_00615E70;

void pppRyjDrawMatrixWorldCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    sceVu0CopyMatrix((sceVu0FVECTOR*)&pobj->val[ctbl->useVal[1]], D_00615E70);
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorld", pppRyjDrawMatrixWorldCalc);
