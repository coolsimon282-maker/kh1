#include "ppp.h"

void pppVertexApAtCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    s16* v = (s16*)&pobj->val[ctbl->useVal[0]];

    v[0] = 0;
    v[1] = 0;
}

typedef struct {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ s32 pdtn;
    /* 0x10 */ s32 valoff;
} PVertexApAt;

pppPObject* func_00183C10(ppvmng*, pppPDataVal*);

void func_00186640(pppPObject* parent, PVertexApAt* p, u16 arg2) {
    pppPObject* pobj;
    pppPDataVal* pdv;

    if (p->pdtn != -1) {
        pobj = NULL;
        pdv = &((pppPDataVal*)ppvMng->unk_80)[p->pdtn];
        if (pdv != NULL) {
            pobj = func_00183C10(ppvMng, pdv);
            pobj->ppobj = parent;
        }
        *(u16*)(pobj->val + p->valoff) = arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexApAt", pppVertexApAtCalc);
