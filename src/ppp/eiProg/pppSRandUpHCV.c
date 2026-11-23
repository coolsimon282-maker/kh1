#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s16 scale[4];
    u8 twice;
} PSRandUpHCV;

NOTHROW_FN(s8 func_0018B7F8(s16 a, f32 b));
NOTHROW_FN(f32 func_0018B828(u8 twice));

void pppSRandUpHCVCalc(pppPObject* pobj, PSRandUpHCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    rv[0] = func_0018B828(p->twice);
    rv[1] = func_0018B828(p->twice);
    rv[2] = func_0018B828(p->twice);
    rv[3] = func_0018B828(p->twice);
    if (p->index != -1) {
        tgt = (u16*)&pobj->val[p->index];
    } else {
        tgt = (u16*)&ppvDbgTemp;
    }
    tgt[0] += func_0018B7F8(p->scale[0], rv[0]);
    tgt[1] += func_0018B7F8(p->scale[1], rv[1]);
    tgt[2] += func_0018B7F8(p->scale[2], rv[2]);
    tgt[3] += func_0018B7F8(p->scale[3], rv[3]);
}

s8 func_0018BA08(s16 a, f32 b) {
    return a * b;
}

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

f32 func_0018BA38(u8 twice) {
    f32 r = vu0Rand();

    r = -r;
    if (twice) {
        r = (r - vu0Rand()) * 0.5f;
    }
    return r;
}
