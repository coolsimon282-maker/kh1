#include "ppp.h"

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile("addi $8, $0, -1\n"
                     "qmtc2.ni $8, $vf2\n"
                     "vrxor R, $vf2x\n"
                     "vrnext.x $vf1, R\n"
                     "vrxor R, $vf2x\n"
                     "vrnext.x $vf1, R\n"
                     "vrxor R, $vf2x\n"
                     "vrnext.x $vf1, R\n"
                     "vrxor R, $vf2x\n"
                     "vrnext.x $vf1, R\n"
                     "vrxor R, $vf2x\n"
                     "vrnext.x $vf1, R\n"
                     "vitof0.x $vf2, $vf2\n"
                     "vadd.x $vf1, $vf1, $vf2\n"
                     "qmfc2.ni %0, $vf1\n"
                     : "=r"(r)
                     :
                     : "$8");
    return r;
}

typedef struct {
    pppCDT cdt;
    s32 index;
    s32 scale[3];
    u8 twice;
} PRandUpIV;

s32 func_00189BC0(s32 a, f32 b);

void pppRandUpIVCalc(pppPObject* pobj, PRandUpIV* p, pppCtrlTable* ctbl) {
    f32* rv;
    s32* tgt;
    f32 r;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    r = vu0Rand();
    if (p->twice) {
        r = (r + vu0Rand()) * 0.5f;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    *rv = r;
    if (p->index != -1) {
        tgt = (s32*)&pobj->val[p->index];
    } else {
        tgt = (s32*)&ppvDbgTemp;
    }
    tgt[0] += func_00189BC0(p->scale[0], *rv);
    tgt[1] += func_00189BC0(p->scale[1], *rv);
    tgt[2] += func_00189BC0(p->scale[2], *rv);
}

s32 func_00189D70(s32 a, f32 b) {
    return a * b;
}
