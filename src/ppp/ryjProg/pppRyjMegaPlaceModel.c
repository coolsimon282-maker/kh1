#include "ppp.h"

s32 func_0019FE58(void* arg0, void* arg1); // pppRyjMegaBirthPrize

void pppRyjMegaPlaceModelCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    u8* v1 = (u8*)&pobj->val[ctbl->useVal[1]];

    if (*v1 == 0) {
        if (func_0019FE58(&pobj->val[ctbl->useVal[0]], p)) {
            *v1 = 1;
        }
    }
}

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
