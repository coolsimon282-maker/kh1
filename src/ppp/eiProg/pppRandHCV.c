#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s16 scale[4];
    u8 twice;
} PRandHCV;

s16 RandDownCV_Scale(s16 a, f32 b);

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

void pppRandHCVCalc(pppPObject* pobj, PRandHCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;
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
    tgt = p->index != -1 ? (u16*)&pobj->val[p->index] : (u16*)&ppvDbgTemp;
    tgt[0] += RandDownCV_Scale(p->scale[0], *rv);
    tgt[1] += RandDownCV_Scale(p->scale[1], *rv);
    tgt[2] += RandDownCV_Scale(p->scale[2], *rv);
    tgt[3] += RandDownCV_Scale(p->scale[3], *rv);
}

// a * b.
s16 RandHCV_Scale(s16 a, f32 b) {
    return a * b;
}
