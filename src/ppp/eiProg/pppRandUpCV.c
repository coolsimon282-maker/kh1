#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s8 scale[4];
    u8 twice;
} PRandUpCV;

s8 RandCV_Scale(s8 a, f32 b);

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

void pppRandUpCVCalc(pppPObject* pobj, PRandUpCV* p, pppCtrlTable* ctbl) {
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
    if (p->twice) {
        r = (r + vu0Rand()) * 0.5f;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    *rv = r;
    tgt = p->index != -1 ? (u8*)&pobj->val[p->index] : (u8*)&ppvDbgTemp;
    tgt[0] += RandCV_Scale(p->scale[0], *rv);
    tgt[1] += RandCV_Scale(p->scale[1], *rv);
    tgt[2] += RandCV_Scale(p->scale[2], *rv);
    tgt[3] += RandCV_Scale(p->scale[3], *rv);
}

// a * b.
s8 RandUpCV_Scale(s8 arg0, f32 arg1) {
    return arg0 * arg1;
}
