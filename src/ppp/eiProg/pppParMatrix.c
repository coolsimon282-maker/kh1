#include "ppp.h"

void pppParMatrixCalc(pppPObject* pobj) {
    sceVu0ApplyMatrix(ppvPObj.next->cmat[3], pobj->ppobj->cmat, ppvPObj.next->cmat[3]);
}
