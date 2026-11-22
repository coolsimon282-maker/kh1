#include "ppp.h"

void pppDrawMatrixNoRotCalc(void) {
    sceVu0ScaleVector(ppvPObj.next->dmat[0], ppvPObj.next->cmat[0], ppvParScl[0]);
    sceVu0ScaleVector(ppvPObj.next->dmat[1], ppvPObj.next->cmat[1], ppvParScl[1]);
    sceVu0ScaleVector(ppvPObj.next->dmat[2], ppvPObj.next->cmat[2], ppvParScl[2]);
    sceVu0MulVector(ppvPObj.next->dmat[3], ppvPObj.next->cmat[3], ppvParScl);
    ppvPObj.next->dmat[3][0] += ppvWorldMatrix[3][0];
    ppvPObj.next->dmat[3][1] += ppvWorldMatrix[3][1];
    ppvPObj.next->dmat[3][2] += ppvWorldMatrix[3][2];
    ppvPObj.next->dmat[3][3] = 1.0f;
    sceVu0MulMatrix(ppvPObj.next->dmat, ppvScreenMatrix, ppvPObj.next->dmat);
}
