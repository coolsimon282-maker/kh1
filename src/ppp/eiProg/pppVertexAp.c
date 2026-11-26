#include "ppp.h"

typedef struct {
    /* 0x0 */ u16 ict;
    /* 0x2 */ u16 aptct;
} VVertexAp;

void pppVertexApCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VVertexAp* v = (VVertexAp*)&pobj->val[ctbl->useVal[0]];
    
    v->ict = 0;
    v->aptct = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 vsfNo;
    /* 0x06 */ u8 num;
    /* 0x07 */ u8 interval;
    /* 0x08 */ u8 mode;
    /* 0x09 */ u8 pad09[3];
    /* 0x0C */ s32 dataNo;
    /* 0x10 */ s32 valOfs;
} PVertexAp;

pppPObject* pppCreatePObject(ppvmng*, pppPDataVal*);

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
            child = pppCreatePObject(ppvMng, pdv);
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

// every `interval` frames starts `num` copies of particle data dataNo at vertices of vsf entry vsfNo (in order,
// or random ones when mode is 1)
void pppVertexApCalc(pppPObject* pobj, PVertexAp* p, pppCtrlTable* ctbl) {
    VVertexAp* v = (VVertexAp*)&pobj->val[ctbl->useVal[0]];
    pppVsfSt* vsf;
    pppSVECTOR* vert;
    pppSVECTOR pt;
    s32 n;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (ppvEmptyLoop) {
        return;
    }
    if (p->vsfNo < 0) {
        return;
    }
    if (v->aptct == 0) {
        vsf = &ppvEnv->lpVsf[p->vsfNo];
        vert = ppvPObj.next->lpvert;
        if (vert == NULL) {
            vert = ppvEnv->lpModel[(s16)vsf->modelNo].vert;
        }
        n = p->num;
        switch (p->mode) {
        case 0:
            while (n--) {
                if (v->ict >= (s16)vsf->indexN) {
                    v->ict = 0;
                }
                pt = vert[(u16)vsf->index[v->ict++]];
                func_00185F30(pobj, p, &pt);
            }
            break;
        case 1:
            while (n--) {
                pt = vert[(u16)vsf->index[(s32)(vu0Rand() * (s16)vsf->indexN)]];
                func_00185F30(pobj, p, &pt);
            }
            break;
        }
        v->aptct = p->interval;
    }
    v->aptct--;
}
