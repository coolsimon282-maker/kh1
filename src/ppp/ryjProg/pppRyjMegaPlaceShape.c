#include "ppp.h"

s32 func_0019FD78(void*, void*);

void pppRyjMegaPlaceShapeCalc(pppPObject* pobj, void* p, pppCtrlTable* ctbl) {
    u8* flag = (u8*)&pobj->val[ctbl->useVal[1]];

    if (*flag == 0) {
        if (func_0019FD78(&pobj->val[ctbl->useVal[0]], p) != 0) {
            *flag = 1;
        }
    }
}

void pppRyjMegaPlaceShapeCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    u8* flag = (u8*)&pobj->val[ctbl->useVal[1]];
    s32* count = (s32*)&pobj->val[ctbl->useVal[0]];

    *flag = 0;
    (*count)++;
}
