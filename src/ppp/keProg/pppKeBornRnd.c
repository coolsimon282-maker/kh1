#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd", pppKeBornRndCalc);

void pppKeBornRndCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    *(s16*)&pobj->val[ctbl->useVal[0]] = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ char pad_04[4];
    /* 0x08 */ f32 speed;
    /* 0x0C */ char pad_0C[4];
    /* 0x10 */ s32 pdtn;
    /* 0x14 */ s32 posOff;
    /* 0x18 */ char pad_18[4];
    /* 0x1C */ s32 velOff;
} PKeBornRndCb;

pppPObject* pppCreatePObject(ppvmng* mng, void* pdt);
void op_vec_copy_xyz(void* dst, void* src);

// Creates a particle (data pdtn) at point sv transformed by the current matrix, moving outward from the matrix origin at p->speed.
void KeBornRnd_Born(pppPObject* pobj, PKeBornRndCb* p, s16* sv) {
    pppPObject* born;
    void* pdt;
    void* pos;
    void* vel;
    sceVu0FVECTOR t;

    born = NULL;
    pdt = (char*)ppvMng->unk_80 + p->pdtn * 16;
    if (pdt != NULL) {
        born = pppCreatePObject(ppvMng, pdt);
        born->ppobj = pobj;
    }
    t[0] = sv[0];
    t[1] = sv[1];
    t[2] = sv[2];
    t[3] = 1.0f;
    pos = &born->val[p->posOff];
    vel = &born->val[p->velOff];
    sceVu0ApplyMatrix(t, ppvPObj.next->cmat, t);
    op_vec_copy_xyz(pos, t);
    sceVu0SubVector(t, t, ppvPObj.next->cmat[3]);
    sceVu0Normalize(t, t);
    sceVu0ScaleVector(t, t, p->speed);
    op_vec_copy_xyz(vel, t);
}
