#include "ppp.h"

typedef struct {
    /* 0x0 */ s16 ict;
    /* 0x2 */ u16 aptct;
} VVertexAp;

void pppVertexApCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVertexAp* v = (VVertexAp*)&pobj->val[ctbl->useVal[0]];
    
    v->ict = 0;
    v->aptct = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ u8 unk_04[8];
    /* 0x0C */ s32 dataNo;
    /* 0x10 */ s32 valOfs;
} PVertexAp;

pppPObject* func_00183C10(ppvmng*, pppPDataVal*);

// starts particle data dataNo as a child of pobj and puts it at vtx (moved by the current object's matrix)
void func_00185F30(pppPObject* pobj, PVertexAp* p, pppSVECTOR* vtx) {
    pppPObject* child;
    pppPDataVal* pdv;
    f32* pos;
    sceVu0FVECTOR v;

    if (p->dataNo != -1) {
        child = NULL;
        pdv = (pppPDataVal*)ppvMng->unk_80 + p->dataNo;
        if (pdv != NULL) {
            child = func_00183C10(ppvMng, pdv);
            child->ppobj = pobj;
        }
        v[0] = vtx->x;
        v[1] = vtx->y;
        v[2] = vtx->z;
        v[3] = 1.0f;
        sceVu0ApplyMatrix(v, ppvPObj.next->cmat, v);
        pos = (f32*)&child->val[p->valOfs];
        pos[0] = v[0];
        pos[1] = v[1];
        pos[2] = v[2];
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppVertexAp", pppVertexApCalc);
