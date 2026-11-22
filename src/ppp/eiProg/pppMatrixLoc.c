#include "ppp.h"

void pppMatrixLocCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    f32* loc = (f32*)&pobj->val[ctbl->useVal[0]];

    sceVu0UnitMatrix(ppvPObj.next->cmat);
    ppvPObj.next->cmat[3][0] = loc[0];
    ppvPObj.next->cmat[3][1] = loc[1];
    ppvPObj.next->cmat[3][2] = loc[2];
}
