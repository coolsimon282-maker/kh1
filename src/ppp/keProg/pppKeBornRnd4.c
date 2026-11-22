#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/keProg/pppKeBornRnd4", pppKeBornRnd4Calc);

typedef struct {
    /* 0x0 */ s16 unk_00;
} VKeBornRnd4;

void pppKeBornRnd4Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd4*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
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
} PKeBornRnd4Cb;

pppPObject* func_00183C10(ppvmng* mng, void* pdt);
void func_001AB0F0(void* dst, void* src);

void func_0018F548(pppPObject* pobj, PKeBornRnd4Cb* p, s16* sv) {
    pppPObject* born;
    void* pdt;
    void* pos;
    void* vel;
    sceVu0FVECTOR t;

    born = NULL;
    pdt = (char*)ppvMng->unk_80 + p->pdtn * 16;
    if (pdt != NULL) {
        born = func_00183C10(ppvMng, pdt);
        born->ppobj = pobj;
    }
    t[0] = sv[0];
    t[1] = sv[1];
    t[2] = sv[2];
    t[3] = 1.0f;
    pos = &born->val[p->posOff];
    vel = &born->val[p->velOff];
    sceVu0ApplyMatrix(t, ppvPObj.next->cmat, t);
    func_001AB0F0(pos, t);
    sceVu0SubVector(t, t, ppvPObj.next->cmat[3]);
    sceVu0Normalize(t, t);
    sceVu0ScaleVector(t, t, p->speed);
    func_001AB0F0(vel, t);
}
