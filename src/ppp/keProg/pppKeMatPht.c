#include "ppp/pppUtil.h"

// FM's ppp code behaves as if built without strict aliasing (ppvPObj.next is reloaded after float
// stores); reading it through a union gives the same alias-everything access.
typedef union {
    pppPObject* next;
} PObjNext;

#define NEXT (((PObjNext*)&ppvPObj)->next)

// v.xyz *= s (hand-written VU0 macro code)
static inline void vu0ScaleXYZ(f32* v, f32 s) {
    __asm__ volatile("qmtc2.ni %1, $vf9\n"
                     "lqc2 $vf10, 0x0(%0)\n"
                     "vmulx.xyz $vf10, $vf10, $vf9x\n"
                     "sqc2 $vf10, 0x0(%0)\n"
                     :
                     : "r"(v), "r"(s));
}

void pppKeMatPhtCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    pppIVECTOR* ang = (pppIVECTOR*)&pobj->val[ctbl->useVal[1]];
    f32* scl = (f32*)&pobj->val[ctbl->useVal[2]];

    pppGetRotMatrixZYX(KeMatPht, ang);
    vu0ScaleXYZ(KeMatPht[0], scl[0]);
    vu0ScaleXYZ(KeMatPht[1], scl[1]);
    vu0ScaleXYZ(KeMatPht[2], scl[2]);
    KeMatPht[3][0] = pos[0];
    KeMatPht[3][1] = pos[1];
    KeMatPht[3][2] = pos[2];
    sceVu0UnitMatrix(NEXT->cmat);
    NEXT->cmat[0][0] = scl[0];
    NEXT->cmat[1][1] = scl[1];
    NEXT->cmat[2][2] = scl[2];
    sceVu0CopyVector(NEXT->cmat[3], KeMatPht[3]);
}
