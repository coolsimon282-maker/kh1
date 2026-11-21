#include "ppp.h"

void pppSclMoveLoopCon(pppPObject* pobj, pppCtrlTable* ctbl) {
    f32* v = (f32*)&pobj->val[ctbl->useVal[1]];

    v[0] = v[1] = v[2] = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSclMoveLoop", pppSclMoveLoopCon2);

INCLUDE_ASM("asm/nonmatchings/ppp/eiProg/pppSclMoveLoop", pppSclMoveLoopCalc);
