#include "ppp.h"

typedef struct {
    pppFVECTOR vec;
} VMoveLoop;

void pppMoveLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    VMoveLoop* v = (VMoveLoop*)&pobj->val[ctbl->useVal[1]];

    v->vec.x = v->vec.y = v->vec.z = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppMoveLoop", pppMoveLoopCon2);

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppMoveLoop", pppMoveLoopCalc);
