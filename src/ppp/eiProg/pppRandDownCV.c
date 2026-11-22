#include "ppp.h"

static inline f32 vu0Rand(void) {
    f32 r;
    __asm__ volatile(
        "addi $8, $0, -1
"
        "qmtc2.ni $8, $vf2
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vrxor R, $vf2x
"
        "vrnext.x $vf1, R
"
        "vitof0.x $vf2, $vf2
"
        "vadd.x $vf1, $vf1, $vf2
"
        "qmfc2.ni %0, $vf1
"
        : "=r"(r) : : "$8");
    return r;
}

typedef struct {
    pppCDT cdt;
    s32 index;
    s8 scale[4];
    u8 twice;
} PRandDownCV;

s8 func_0018A2D0(s8 a, f32 b);

void pppRandDownCVCalc(pppPObject* pobj, PRandDownCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u8* tgt;
    f32 r;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    r = vu0Rand();
    r = -r;
    if (p->twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    *rv = r;
    if (p->index != -1) {
        tgt = (u8*)&pobj->val[p->index];
    } else {
        tgt = (u8*)&ppvDbgTemp;
    }
    tgt[0] += func_0018A2D0(p->scale[0], *rv);
    tgt[1] += func_0018A2D0(p->scale[1], *rv);
    tgt[2] += func_0018A2D0(p->scale[2], *rv);
    tgt[3] += func_0018A2D0(p->scale[3], *rv);
}


s16 func_0018A4A8(s16 a, f32 b) {
    return a * b - a;
}
