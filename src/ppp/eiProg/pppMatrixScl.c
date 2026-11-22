#include "ppp.h"

void pppMatrixSclCalc(pppPObject* pobj, void* data, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    f32* scl = (f32*)&pobj->val[ctbl->useVal[1]];

    sceVu0UnitMatrix(ppvPObj.next->cmat);
    ppvPObj.next->cmat[0][0] = scl[0];
    ppvPObj.next->cmat[1][1] = scl[1];
    ppvPObj.next->cmat[2][2] = scl[2];
    ppvPObj.next->cmat[3][0] = pos[0];
    ppvPObj.next->cmat[3][1] = pos[1];
    ppvPObj.next->cmat[3][2] = pos[2];
}
