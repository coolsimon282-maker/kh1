#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} PKeThTp;

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ void* unk_1C;
} VKeThTp;

void func_001AB0F0(void*, f32*); // ppp/draw

void pppKeThTpCalc(pppPObject* pobj, PKeThTp* p, pppCtrlTable* ctbl) {
    VKeThTp* v = (VKeThTp*)&pobj->val[ctbl->useVal[0]];
    void* q;

    if (pobj->time == p->cdt.time) {
        v->unk_10 = p->unk_08;
        v->unk_18 = p->unk_04;
        v->unk_14 = p->unk_0C;
        if (p->unk_10 != -1) {
            q = &((pppPDataVal*)ppvMng->unk_80)[p->unk_10].pobj->val[p->unk_14];
        } else {
            q = &ppvDbgTemp;
        }
        v->unk_1C = q;
        if (q == &ppvDbgTemp) {
            v->unk_1C = NULL;
        }
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    func_001AB0F0(v, ppvPObj.next->cmat[3]);
}
void pppKeThTpCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeThTp* v = (VKeThTp*)&pobj->val[ctbl->useVal[0]];

    v->unk_1C = NULL;
    v->unk_0C = 0.0f;
}

void pppKeThTp2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    VKeThTp* v = (VKeThTp*)&pobj->val[ctbl->useVal[0]];

    v->unk_1C = NULL;
    v->unk_0C = 1.0f;
}
