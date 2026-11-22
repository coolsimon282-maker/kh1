#include "ppp.h"

void pppGetRotMatrixXYZ(sceVu0FMATRIX mp, pppIVECTOR* angle);
extern sceVu0FVECTOR D_003701D0;
extern pppIVECTOR D_003701E0;

void pppRyjMatrixWorldXYZCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    sceVu0FVECTOR* m = (sceVu0FVECTOR*)&pobj->val[ctbl->useVal[3]];

    pppGetRotMatrixXYZ((void*)m, &D_003701E0);
    m[3][0] = D_003701D0[0];
    m[3][1] = D_003701D0[1];
    m[3][2] = D_003701D0[2];
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMatrixWorldXYZ", pppRyjMatrixWorldXYZCalc);
