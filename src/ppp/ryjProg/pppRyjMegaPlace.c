#include "ppp.h"

typedef struct {
    /* 0x00 */ u32 unShapeNum;
    /* 0x04 */ u32 unModelNum;
    /* 0x08 */ u32 unLampNum;
    /* 0x0C */ void* pvShape;
    /* 0x10 */ void* pvModel;
    /* 0x14 */ void* pvLamp;
} VRyjMegaPlace;

void pppRyjMegaPlaceCalc(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    VRyjMegaPlace* v = (VRyjMegaPlace*)&pobj->val[ctbl->useVal[0]];

    if (v->pvShape == NULL && v->unShapeNum != 0) {
        v->pvShape = pppDbgAlloc(ppvEnv, v->unShapeNum * 32);
        memset(v->pvShape, 0, v->unShapeNum * 32);
    }
    if (v->pvModel == NULL && v->unModelNum != 0) {
        v->pvModel = pppDbgAlloc(ppvEnv, v->unModelNum * 32);
        memset(v->pvModel, 0, v->unModelNum * 32);
    }
    if (v->pvLamp == NULL && v->unLampNum != 0) {
        v->pvLamp = pppDbgAlloc(ppvEnv, v->unLampNum * 48);
        memset(v->pvLamp, 0, v->unLampNum * 48);
    }
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlace", func_001A0140);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlace", func_001A0460);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlace", func_001A07A8);

void pppRyjMegaPlaceDraw(pppPObject* pobj, s32 param, pppCtrlTable* ctbl) {
    VRyjMegaPlace* v = (VRyjMegaPlace*)&pobj->val[ctbl->useVal[0]];

    func_001A0140(v);
    func_001A0460(v);
    func_001A07A8(v);
}

void pppRyjMegaPlaceCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    void** v = (void**)&pobj->val[ctbl->useVal[0]];

    v[2] = NULL;
    v[1] = NULL;
    v[0] = NULL;
    v[5] = NULL;
    v[4] = NULL;
    v[3] = NULL;
    ppvMng->unk_B3 = 1;
    ppvMng->drawPriority = 1;
}

void pppRyjMegaPlaceDes(pppPObject* pobj, pppCtrlTable* ctbl) {
    VRyjMegaPlace* v = (VRyjMegaPlace*)&pobj->val[ctbl->useVal[0]];

    if (v->pvShape != NULL) {
        pppFree(ppvEnv, v->pvShape);
        v->pvShape = NULL;
    }
    if (v->pvModel != NULL) {
        pppFree(ppvEnv, v->pvModel);
        v->pvModel = NULL;
    }
    if (v->pvLamp != NULL) {
        pppFree(ppvEnv, v->pvLamp);
        v->pvLamp = NULL;
    }
}
