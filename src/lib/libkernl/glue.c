// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", sceResetttyinit);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", VSync);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", VSync2);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", write);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", read);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", open);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", close);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", iotctl);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", lseek);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", sbrk);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", isatty);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", fstat);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", getpid);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", kill);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", stat);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/glue", unlink);
