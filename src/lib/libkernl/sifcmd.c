// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", _set_sreg);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", _change_addr);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifGetSreg);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifSetSreg);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", secSifGetDataTable);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifInitCmd);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifExitCmd);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifSetCmdBuffer);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifSetSysCmdBuffer);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifAddCmdHandler);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifRemoveCmdHandler);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", _sceSifSendCmd);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifSendCmd);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", isceSifSendCmd);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", _sceSifCmdIntrHdlr);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", sceSifWriteBackDCache);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifcmd", func_002607E4);
