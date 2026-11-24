// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

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
