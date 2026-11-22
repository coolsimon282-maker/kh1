#include "ppp.h"

typedef u8 TKeHitBorn_Stt;

typedef struct {
    /* 0x0 */ pppCDT cdt;
    /* 0x4 */ pppParamPObj bornPt;
    /* 0xC */ u8 cmdContinue;
} PKeHitBorn;

typedef struct {
    /* 0x0 */ TKeHitBorn_Stt stt;
} VKeHitBorn;

typedef union {
    /* 0x0 */ TKeHitBorn_Stt stt;
    struct {
        /* 0x0 */ u8 hit : 1;
        /* 0x0 */ u8 born : 1;
    } b;
} VKeHitBornBits;

typedef struct {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ u8 hit : 1;
} VKeHitBornHit;

// FM's ppp code behaves as if built without strict aliasing (ctbl->useVal is reloaded after the pointer
// store); storing through a union gives the same alias-everything access.
typedef union {
    pppPObject* p;
} PObjPtr;

pppPObject* func_00183C10(ppvmng* mng, void* pdt);
void func_001AB0F0(void* dst, void* src);

void pppKeHitBornCalc(pppPObject* pobj, PKeHitBorn* p, pppCtrlTable* ctbl) {
    VKeHitBornBits* v = (VKeHitBornBits*)&pobj->val[ctbl->useVal[2]];
    VKeHitBornHit* hit;
    pppPObject* born;
    void* pdt;
    void* dst;
    void* src;

    if (v->stt & 2) {
        return;
    }
    if (pobj->time == p->cdt.time) {
        if (p->cmdContinue) {
            v->stt |= 1;
        } else {
            v->stt &= ~1;
        }
    }
    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    hit = (VKeHitBornHit*)&pobj->val[ctbl->useVal[1]];
    if (!hit->hit) {
        return;
    }
    if (p->bornPt.pdtn == -1) {
        return;
    }
    pdt = (char*)ppvMng->unk_80 + p->bornPt.pdtn * 16;
    born = NULL;
    if (pdt != NULL) {
        born = func_00183C10(ppvMng, pdt);
        ((PObjPtr*)&born->ppobj)->p = pobj;
    }
    src = &pobj->val[ctbl->useVal[0]];
    dst = &born->val[p->bornPt.valoff];
    if (!v->b.hit) {
        v->stt |= 2;
        func_001AB0F0(dst, hit);
    } else {
        func_001AB0F0(dst, src);
    }
}

void pppKeHitBornCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeHitBorn*)&pobj->val[ctbl->useVal[2]])->stt = 0;
}
