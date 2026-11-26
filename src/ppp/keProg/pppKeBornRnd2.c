#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ char pad_06[6];
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ char pad_0F[1];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} PKeBornRnd2;

s32 func_001AAF80(void);
void func_0018EB98();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd2* p, void* func, void* v, s16 a, u8 b, u8 c);

s32 pppKeBornRnd2Calc(pppPObject* pobj, PKeBornRnd2* p, pppCtrlTable* ctbl) {
    if (!ppvEmptyLoop && !(ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) && p->unk_0D != 0xFF &&
        !((func_001AAF80() >> 8) & p->unk_0D) && p->unk_10 != -1 && p->unk_18 != -1) {
        KeBornRnd2(pobj, p, func_0018EB98, &pobj->val[ctbl->useVal[0]], p->unk_04, p->unk_0E, p->unk_0C);
    }
}

typedef struct {
    /* 0x0 */ s16 unk_00;
} VKeBornRnd2;

void pppKeBornRnd2Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd2*)&pobj->val[ctbl->useVal[0]])->unk_00 = 0;
}

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ char pad_04[8];
    /* 0x0C */ s32 pdtn;
    /* 0x10 */ s32 posOff;
    /* 0x14 */ char pad_14[4];
    /* 0x18 */ s32 velOff;
} PKeBornRnd2Cb;

pppPObject* pppCreatePObject(ppvmng* mng, void* pdt);
void func_001AB0F0(void* dst, void* src);

void func_0018EDD8(pppPObject* pobj, PKeBornRnd2Cb* p, s16* sv) {
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
    func_001AB0F0(pos, t);
    sceVu0SubVector(t, t, ppvPObj.next->cmat[3]);
    sceVu0Normalize(t, t);
    func_001AB0F0(vel, t);
}
