#include "ppp.h"

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1\n"
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
        : "=r"(r) : : "$8");
    return r;
}

typedef struct {
    pppCDT cdt;
    s32 index;
    f32 scale[3];
    u8 twice;
} PRandFV;

f32 RandDownInt_Scale(f32 a, f32 b);

void pppRandFVCalc(pppPObject* pobj, PRandFV* p, pppCtrlTable* ctbl) {
    f32* rv;
    f32* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (pobj->time == 0) {
        f32 r = vu0Rand();
        if (p->twice) {
            r += vu0Rand();
        } else {
            r += r;
        }
        rv = (f32*)&pobj->val[ctbl->useVal[0]];
        *rv = r;
    } else {
        if (p->cdt.time != pobj->time) {
            return;
        }
        rv = (f32*)&pobj->val[ctbl->useVal[0]];
    }
    if (p->index != -1) {
        tgt = (f32*)&pobj->val[p->index];
    } else {
        tgt = (f32*)&ppvDbgTemp;
    }
    tgt[0] += RandDownInt_Scale(p->scale[0], *rv);
    tgt[1] += RandDownInt_Scale(p->scale[1], *rv);
    tgt[2] += RandDownInt_Scale(p->scale[2], *rv);
}


// a * b.
f32 RandFV_Scale(f32 a, f32 b) {
    return a * b;
}
