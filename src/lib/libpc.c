// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Its .data is defined below (the library version string).
#include "common.h"

#ifdef VERSION_FM
char D_0046E070[16] = "PsIIlibpc   2500"; // .data: library version (no NUL)
#endif

INCLUDE_ASM("asm/nonmatchings/lib/libpc", scePcStart);

/* scePcStop: clear CTE (bit 31) of the performance counter control register ($25 PCCR). The value lives in $3
   (Sony probably wrote it as one asm block with fixed registers). scePcStart (di, eret) is hand-written asm. */
void scePcStop(void) {
    register unsigned int ctrl __asm__("$3");
    __asm__ __volatile__("mfc0 %0, $25" : "=r"(ctrl));
    ctrl |= 0x80000000;
    ctrl ^= 0x80000000;
    __asm__ __volatile__("mtc0 %0, $25" : : "r"(ctrl));
}
