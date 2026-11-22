#include "ppp.h"

typedef struct {
    /* 0x0 */ u8 faps;
    /* 0x1 */ u8 aptct;
} VPointAp;

void pppPointApCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VPointAp*)&pobj->val[ctbl->useVal[1]])->aptct = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s32 pdtn;
    /* 0x08 */ s32 valoff;
    /* 0x0C */ u8 aps;
} PPointAp;

pppPObject* func_00183C10(ppvmng*, pppPDataVal*);

void pppPointApCalc(pppPObject* pobj, PPointAp* p, pppCtrlTable* ctbl) {
    f32* pos = (f32*)&pobj->val[ctbl->useVal[0]];
    VPointAp* v = (VPointAp*)&pobj->val[ctbl->useVal[1]];

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (v->aptct == 0) {
        pppPObject* child;
        pppPDataVal* pdv;
        f32* dst;

        if (p->pdtn == -1) {
            return;
        }
        child = NULL;
        pdv = &((pppPDataVal*)ppvMng->unk_80)[p->pdtn];
        if (pdv != NULL) {
            child = func_00183C10(ppvMng, pdv);
            child->ppobj = pobj;
        }
        dst = (f32*)&child->val[p->valoff];
        dst[0] = pos[0];
        dst[1] = pos[1];
        dst[2] = pos[2];
        v->aptct = p->aps;
    }
    v->aptct--;
}
