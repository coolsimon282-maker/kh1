// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", CB_DelayTh);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdDelayThread);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdCallback);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", _sceCd_cd_callback);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", _Cdvd_cbLoop);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdInitEeCB);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", func_00269790);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", cmd_sem_init);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", cdvd_exit);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdPOffCallback);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", _sceCd_Poff_Intr);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", PowerOffCB);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdSearchFile);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", func_00269DA8);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", _sceCd_ncmd_prechk);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdNcmdDiskReady);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdSync);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdSyncS);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", _sceCd_scmd_prechk);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdInit);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdDiskReady);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdMmode);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdRead);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdSeek);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdGetError);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdStatus);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdBreak);

INCLUDE_ASM("asm/nonmatchings/lib/libcdvd", sceCdPowerOff);
