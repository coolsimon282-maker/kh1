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

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 vsfNo;
    /* 0x06 */ u8 count;
    /* 0x07 */ u8 wait;
    /* 0x08 */ u8 mode;
    /* 0x09 */ char pad[3];
    /* 0x0C */ s32 pdtn;
    /* 0x10 */ s32 valoff;
} PVertexApAtC;

typedef struct {
    /* 0x0 */ u16 modelNo;
    /* 0x2 */ s16 indexN;
    /* 0x4 */ s16* index;
} VsfS;

void pppVertexApAtCalc(pppPObject* pobj, PVertexApAtC* p, pppCtrlTable* ctbl) {
    u16* v = (u16*)&pobj->val[ctbl->useVal[0]];
    VsfS* vsf;
    s32 n;

    if (ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) {
        return;
    }
    if (ppvEmptyLoop != 0) {
        return;
    }
    if (p->vsfNo < 0) {
        return;
    }
    if (v[1] == 0) {
        vsf = &((VsfS*)ppvEnv->lpVsf)[p->vsfNo];
        n = p->count;
        switch (p->mode) {
        case 0:
            while (n-- != 0) {
                if (v[0] >= vsf->indexN) {
                    v[0] = 0;
                }
                func_00186640(pobj, (PVertexApAt*)p, v[0]++);
            }
            break;
        case 1:
            while (n-- != 0) {
                func_00186640(pobj, (PVertexApAt*)p, (s32)(vu0Rand() * vsf->indexN));
            }
            break;
        }
        v[1] = p->wait;
    }
    v[1]--;
}

