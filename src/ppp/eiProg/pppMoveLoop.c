#include "ppp.h"

typedef struct {
    pppFVECTOR vec;
} VMoveLoop;

void pppMoveLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VMoveLoop* v = (VMoveLoop*)&pobj->val[ctbl->useVal[1]];

    v->vec.x = v->vec.y = v->vec.z = 0.0f;
}

void pppMoveLoopCon2(pppPObject* pobj, pppCtrlTable* ctbl) {
    pppMoveLoopCon(pobj, ctbl);
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppMoveLoop", pppMoveLoopCalc);
