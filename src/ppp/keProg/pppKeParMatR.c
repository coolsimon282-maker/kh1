#include "ppp.h"

void pppKeParMatRCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    pppPObject* parent = pobj->ppobj;
    sceVu0FMATRIX m;
    sceVu0FVECTOR v;

    sceVu0Normalize(m[0], parent->cmat[0]);
    sceVu0Normalize(m[1], parent->cmat[1]);
    sceVu0Normalize(m[2], parent->cmat[2]);
    sceVu0ApplyMatrix(v, parent->cmat, ppvPObj.next->cmat[3]);
    sceVu0MulMatrix(ppvPObj.next->cmat, m, ppvPObj.next->cmat);
    sceVu0CopyVector(ppvPObj.next->cmat[3], v);
}
