#include "ppp/pppUtil.h"

static inline void vu0ScaleXYZ(f32* v, f32 s) {
    __asm__ volatile(
        "qmtc2.ni %1, $vf9\n"
        "lqc2 $vf10, 0x0(%0)\n"
        "vmulx.xyz $vf10, $vf10, $vf9x\n"
        "sqc2 $vf10, 0x0(%0)\n"
        : : "r"(v), "r"(s));
}

void pppMatrixYZXCalc(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    pppIVECTOR* ang = (pppIVECTOR*)&pobj->val[ctbl->useVal[1]];
    f32* scl = (f32*)&pobj->val[ctbl->useVal[2]];
    pppGetRotMatrixYZX(ppvPObj.next->cmat, ang);
    vu0ScaleXYZ(ppvPObj.next->cmat[0], scl[0]);
    vu0ScaleXYZ(ppvPObj.next->cmat[1], scl[1]);
    vu0ScaleXYZ(ppvPObj.next->cmat[2], scl[2]);
    ppvPObj.next->cmat[3][0] = pos[0];
    ppvPObj.next->cmat[3][1] = pos[1];
    ppvPObj.next->cmat[3][2] = pos[2];
}
