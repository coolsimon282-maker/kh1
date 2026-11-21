#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceModel", pppRyjMegaPlaceModelCalc);

typedef struct {
    /* 0x0 */ char unk_00[0x4];
    /* 0x4 */ s32 unk_04;
} VRyjMegaPlaceModel;

void pppRyjMegaPlaceModelCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaPlaceModel* v0 = (VRyjMegaPlaceModel*)&pobj->val[ctbl->useVal[0]];
    u8* v1 = (u8*)&pobj->val[ctbl->useVal[1]];

    *v1 = 0;
    v0->unk_04++;
}
