// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifInitRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifExitRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _sceRpcGetPacket);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _sceRpcFreePacket);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _sceRpcGetFPacket);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _sceRpcGetFPacket2);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _request_end);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _request_rdata);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifGetOtherData);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _search_svdata);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _request_bind);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifBindRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", _request_call);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifCallRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifCheckStatRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifSetRpcQueue);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifRegisterRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifRemoveRpc);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifRemoveRpcQueue);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifGetNextRequest);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifExecRequest);

INCLUDE_ASM("asm/nonmatchings/lib/libkernl/sifrpc", sceSifRpcLoop);
