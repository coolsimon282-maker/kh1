#include "ppp/pppUtil.h"

typedef struct {
    /* 0x00 */ sceVu0FMATRIX mat;
} VRyjMatrixWorldZYX;

extern pppFVECTOR D_003701D0;
extern pppIVECTOR D_003701E0;

void pppRyjMatrixWorldZYXCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMatrixWorldZYX* v = (VRyjMatrixWorldZYX*)&pobj->val[ctbl->useVal[3]];

    pppGetRotMatrixZYX(v->mat, &D_003701E0);
    v->mat[3][0] = D_003701D0.x;
    v->mat[3][1] = D_003701D0.y;
    v->mat[3][2] = D_003701D0.z;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixWorldZYX", pppRyjMatrixWorldZYXCalc);
