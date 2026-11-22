#include "ppp/pppUtil.h"

typedef struct {
    /* 0x00 */ sceVu0FMATRIX mat;
} VRyjMatrixWorldXZY;

extern pppFVECTOR D_003701D0;
extern pppIVECTOR D_003701E0;

void pppRyjMatrixWorldXZYCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMatrixWorldXZY* v = (VRyjMatrixWorldXZY*)&pobj->val[ctbl->useVal[3]];

    pppGetRotMatrixXZY(v->mat, &D_003701E0);
    v->mat[3][0] = D_003701D0.x;
    v->mat[3][1] = D_003701D0.y;
    v->mat[3][2] = D_003701D0.z;
}

static inline void vu0ScaleXYZ(f32* v, f32 s) {
    __asm__ volatile("qmtc2.ni %1, $vf9\n"
                     "lqc2 $vf10, 0x0(%0)\n"
                     "vmulx.xyz $vf10, $vf10, $vf9x\n"
                     "sqc2 $vf10, 0x0(%0)\n"
                     :
                     : "r"(v), "r"(s));
}

void pppRyjMatrixWorldXZYCalc(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    pppIVECTOR* ang = (pppIVECTOR*)&pobj->val[ctbl->useVal[1]];
    VRyjMatrixWorldXZY* v = (VRyjMatrixWorldXZY*)&pobj->val[ctbl->useVal[3]];
    f32* scl = (f32*)&pobj->val[ctbl->useVal[2]];
    sceVu0FMATRIX m;

    pppGetRotMatrixXZY(ppvPObj.next->cmat, ang);
    ppvPObj.next->cmat[3][0] = pos[0];
    ppvPObj.next->cmat[3][1] = pos[1];
    ppvPObj.next->cmat[3][2] = pos[2];
    pppGetRotMatrixXZY(m, &D_003701E0);
    m[3][0] = D_003701D0.x;
    m[3][1] = D_003701D0.y;
    m[3][2] = D_003701D0.z;
    sceVu0InversMatrix(m, m);
    sceVu0MulMatrix(ppvPObj.next->cmat, ppvPObj.next->cmat, v->mat);
    sceVu0MulMatrix(ppvPObj.next->cmat, m, ppvPObj.next->cmat);
    vu0ScaleXYZ(ppvPObj.next->cmat[0], scl[0]);
    vu0ScaleXYZ(ppvPObj.next->cmat[1], scl[1]);
    vu0ScaleXYZ(ppvPObj.next->cmat[2], scl[2]);
}
