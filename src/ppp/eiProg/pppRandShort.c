#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    u16 scale;
    u8 twice;
} PRandShort;

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

void pppRandShortCalc(pppPObject* pobj, PRandShort* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;

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
        tgt = (u16*)&pobj->val[p->index];
    } else {
        tgt = (u16*)&ppvDbgTemp;
    }
    {
        f32 s = p->scale;
        *tgt += (s32)(s * *rv - s);
    }
}
