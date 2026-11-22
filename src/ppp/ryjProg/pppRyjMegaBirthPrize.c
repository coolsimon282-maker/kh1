#include "ppp.h"

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", pppRyjMegaBirthPrizeDraw);

extern u8 D_0035C710[];

void pppRyjMegaBirthPrizeCon(void) {
    memset(D_0035C710, 0, 0x2000);
    ppvMng->unk_B3 = 1;
    ppvMng->drawPriority = 1;
}

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FD18);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FD78);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FE58);

INCLUDE_ASM("asm/nonmatchings/ppp/ryjProg/pppRyjMegaBirthPrize", func_0019FF38);
