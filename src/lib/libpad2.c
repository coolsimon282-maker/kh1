// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2Init);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2End);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2CreateSocket);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2DeleteSocket);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2Read);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2GetButtonProfile);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2GetState);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2GetButtonInfo);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2LinkDriver);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2GetSide);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2CheckDma);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2SetButtonOrder);

INCLUDE_ASM("asm/nonmatchings/lib/libpad2", scePad2StateIntToStr);
