#include "ppp.h"

void pppDrawMatrixWoodSta(void) {
}

extern sceVu0FMATRIX D_006160C0;

void pppDrawMatrixWoodCalc(void) {
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ppvParScl[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ppvParScl[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ppvParScl[2]);
    *(u_long128*)ppvPObj.next->dmat[3] = *(u_long128*)ppvPObj.next->cmat[3];
    sceVu0MulMatrix(ppvPObj.next->dmat, D_006160C0, ppvPObj.next->dmat);
    sceVu0ApplyMatrix(ppvPObj.next->dmat[3], ppvSWMatrix, ppvPObj.next->cmat[3]);
}
