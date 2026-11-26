#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s32 scale[3];
    u8 twice;
} PRandIV;

s32 RandDownFV_Scale(s32 a, f32 b);

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

void pppRandIVCalc(pppPObject* pobj, PRandIV* p, pppCtrlTable* ctbl) {
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
        r += vu0Rand();
    } else {
        r += r;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    *rv = r;
    if (p->index != -1) {
        tgt = (s32*)&pobj->val[p->index];
    } else {
        tgt = (s32*)&ppvDbgTemp;
    }
    tgt[0] += RandDownFV_Scale(p->scale[0], *rv);
    tgt[1] += RandDownFV_Scale(p->scale[1], *rv);
    tgt[2] += RandDownFV_Scale(p->scale[2], *rv);
}

// a * b.
s32 RandIV_Scale(s32 arg0, f32 arg1) {
    return arg0 * arg1;
}
