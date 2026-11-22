#include "ppp/pppUtil.h"

typedef struct {
    /* 0x00 */ sceVu0FMATRIX mat;
} VRyjMatrixWorldYXZ;

extern pppFVECTOR D_003701D0;
extern pppIVECTOR D_003701E0;

void pppRyjMatrixWorldYXZCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMatrixWorldYXZ* v = (VRyjMatrixWorldYXZ*)&pobj->val[ctbl->useVal[3]];

    pppGetRotMatrixYXZ(v->mat, &D_003701E0);
    v->mat[3][0] = D_003701D0.x;
    v->mat[3][1] = D_003701D0.y;
    v->mat[3][2] = D_003701D0.z;
}

// FM's ppp code behaves as if built without strict aliasing (ppvPObj.next is reloaded after float
// stores); reading it through a union gives the same alias-everything access.
typedef union {
    pppPObject* next;
} PObjNext;

#define NEXT (((PObjNext*)&ppvPObj)->next)

// v.xyz *= s (hand-written VU0 macro code)
static inline void vu0ScaleXYZ(f32* v, f32 s) {
    __asm__ volatile("qmtc2.ni %1, $vf9
                     "
                     "lqc2 $vf10, 0x0(%0)
                     "
                     "vmulx.xyz $vf10, $vf10, $vf9x
                     "
                     "sqc2 $vf10, 0x0(%0)
                     "
                     :
                     : "r"(v), "r"(s));
}

void pppRyjMatrixWorldYXZCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    pppIVECTOR* ang = (pppIVECTOR*)&pobj->val[ctbl->useVal[1]];
    VRyjMatrixWorldYXZ* v = (VRyjMatrixWorldYXZ*)&pobj->val[ctbl->useVal[3]];
    f32* scl = (f32*)&pobj->val[ctbl->useVal[2]];
    sceVu0FMATRIX m;

    pppGetRotMatrixYXZ(NEXT->cmat, ang);
    NEXT->cmat[3][0] = pos[0];
    NEXT->cmat[3][1] = pos[1];
    NEXT->cmat[3][2] = pos[2];
    pppGetRotMatrixYXZ(m, &D_003701E0);
    m[3][0] = D_003701D0.x;
    m[3][1] = D_003701D0.y;
    m[3][2] = D_003701D0.z;
    sceVu0InversMatrix(m, m);
    sceVu0MulMatrix(NEXT->cmat, NEXT->cmat, v->mat);
    sceVu0MulMatrix(NEXT->cmat, m, NEXT->cmat);
    vu0ScaleXYZ(NEXT->cmat[0], scl[0]);
    vu0ScaleXYZ(NEXT->cmat[1], scl[1]);
    vu0ScaleXYZ(NEXT->cmat[2], scl[2]);
}
