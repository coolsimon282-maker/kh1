#include "ppp.h"

typedef struct {
    /* 0x00 */ pppCDT cdt;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char pad_09[3];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
} PKeBornRnd3;

s32 func_001AAF80(void);
void func_0018EDD8();
void KeBornRnd2(pppPObject* pobj, PKeBornRnd3* p, void* func, void* v, s16 a, u8 b, u8 c);

s32 pppKeBornRnd3Calc(pppPObject* pobj, PKeBornRnd3* p, pppCtrlTable* ctbl) {
    if (!ppvEmptyLoop && !(ppvUserStopPartF != 0 || ppvMng->stop || ppvMng->unk_B4 != 0) && p->unk_07 != 0xFF &&
        !((func_001AAF80() >> 8) & p->unk_07) && p->unk_0C != -1 && p->unk_14 != -1) {
        KeBornRnd2(pobj, p, func_0018EDD8, &pobj->val[ctbl->useVal[0]], p->unk_04, p->unk_08, p->unk_06);
    }
}

typedef struct {
    /* 0x0 */ s16 unk_0;
} VKeBornRnd3;

void pppKeBornRnd3Con(pppPObject* pobj, pppCtrlTable* ctbl) {
    ((VKeBornRnd3*)&pobj->val[ctbl->useVal[0]])->unk_0 = 0;
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
    /* 0x20 */ char pad_20[4];
    /* 0x24 */ s32 dirOff;
} PKeBornRnd3Cb;

pppPObject* pppCreatePObject(ppvmng* mng, void* pdt);
void func_001AB0F0(void* dst, void* src);

// born callback: places the new object at the transformed point sv, direction away from the matrix origin
void func_0018F000(pppPObject* pobj, PKeBornRnd3Cb* p, s16* sv) {
    pppPObject* born;
    void* pdt;
    void* pos;
    void* vel;
    void* dir;
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
    dir = &born->val[p->dirOff];
    sceVu0ApplyMatrix(t, ppvPObj.next->cmat, t);
    func_001AB0F0(pos, t);
    sceVu0SubVector(t, t, ppvPObj.next->cmat[3]);
    sceVu0Normalize(t, t);
    func_001AB0F0(dir, t);
    sceVu0ScaleVector(t, t, p->speed);
    func_001AB0F0(vel, t);
}
