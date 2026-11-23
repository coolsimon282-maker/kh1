#include "ppp.h"

typedef struct {
    pppCDT cdt;
    s32 index;
    s16 scale[4];
    u8 twice;
} PSRandDownHCV;

NOTHROW_FN(s8 func_0018BA08(s16 a, f32 b));
NOTHROW_FN(f32 func_0018BA38(u8 twice));

void pppSRandDownHCVCalc(pppPObject* pobj, PSRandDownHCV* p, pppCtrlTable* ctbl) {
    f32* rv;
    u16* tgt;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (p->cdt.time != pobj->time) {
        return;
    }
    rv = (f32*)&pobj->val[ctbl->useVal[0]];
    rv[0] = func_0018BA38(p->twice);
    rv[1] = func_0018BA38(p->twice);
    rv[2] = func_0018BA38(p->twice);
    rv[3] = func_0018BA38(p->twice);
    if (p->index != -1) {
        tgt = (u16*)&pobj->val[p->index];
    } else {
        tgt = (u16*)&ppvDbgTemp;
    }
    tgt[0] += func_0018BA08(p->scale[0], rv[0]);
    tgt[1] += func_0018BA08(p->scale[1], rv[1]);
    tgt[2] += func_0018BA08(p->scale[2], rv[2]);
    tgt[3] += func_0018BA08(p->scale[3], rv[3]);
}
