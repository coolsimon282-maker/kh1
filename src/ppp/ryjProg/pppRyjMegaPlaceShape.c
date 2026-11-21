#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaPlaceShape", pppRyjMegaPlaceShapeCalc);

void pppRyjMegaPlaceShapeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u8* flag = (u8*)&pobj->val[ctbl->useVal[1]];
    s32* count = (s32*)&pobj->val[ctbl->useVal[0]];

    *flag = 0;
    (*count)++;
}
