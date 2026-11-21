#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", pppRyjDrawMatrixWorldDttFrCon);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", pppRyjDrawMatrixWorldDttFrCalc);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A3F98);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A3FE0);

s32 func_001A4040(s32* arg0, ppvmng* arg1) {
    if (arg0[0] == 0) {
        return 0;
    }
    if (arg1->unk_B6 != 0) {
        if (arg0[1] == 0) {
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4070);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4538);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4680);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjDrawMatrixWorldDttFr", func_001A4BC8);
