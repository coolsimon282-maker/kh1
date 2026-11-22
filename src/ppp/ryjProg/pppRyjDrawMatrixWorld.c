#include "ppp.h"

extern sceVu0FMATRIX D_00615E70;
extern sceVu0FMATRIX D_00615EB0;

void pppRyjDrawMatrixWorldCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    sceVu0CopyMatrix((sceVu0FVECTOR*)&pobj->val[ctbl->useVal[1]], D_00615E70);
}

void pppRyjDrawMatrixWorldCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    sceVu0MulMatrix(ppvPObj.next->dmat, D_00615EB0, (sceVu0FVECTOR*)&pobj->val[ctbl->useVal[1]]);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvPObj.next->dmat, ppvPObj.next->cmat);
}
