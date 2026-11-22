#include "ppp.h"

typedef struct {
    /* 0x0 */ s16 ict;
    /* 0x2 */ u16 aptct;
} VVertexApLc;

void pppVertexApLcCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVertexApLc* v = (VVertexApLc*)&pobj->val[ctbl->useVal[0]];

    v->ict = 0;
    v->aptct = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u8 unk_04[8];
    /* 0x0C */ s32 dataNo;
    /* 0x10 */ s32 valOfs;
} PVertexApLc;

// a union: the target reloads each s16 after every float store, so the stores may alias them
typedef union {
    f32 f;
    s16 h;
} VertexApLcWord;

pppPObject* func_00183C10(ppvmng*, pppPDataVal*, s32);

// starts particle data dataNo as a child of pobj and puts it at vtx
void func_001862E0(pppPObject* pobj, PVertexApLc* p, pppSVECTOR* vtx) {
    pppPObject* child;
    pppPDataVal* pdv;
    VertexApLcWord* pos;

    if (p->dataNo != -1) {
        child = NULL;
        pdv = (pppPDataVal*)ppvMng->unk_80 + p->dataNo;
        if (pdv != NULL) {
            child = func_00183C10(ppvMng, pdv, 0);
            child->ppobj = pobj;
        }
        pos = (VertexApLcWord*)&child->val[p->valOfs];
        pos[0].f = ((s16*)vtx)[0];
        pos[1].f = ((s16*)vtx)[1];
        pos[2].f = ((s16*)vtx)[2];
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexApLc", pppVertexApLcCalc);
