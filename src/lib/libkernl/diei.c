// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* R5900 opcodes with no C spelling. COP0 Status ($12) bit 16 = interrupts enabled. */
#define EI() __asm__ __volatile__(".word 0x42000038" : : : "memory")
#define MFC0_STATUS(dst) __asm__ __volatile__("mfc0 %0, $12" : "=r"(dst))
#define COP0_STATUS_EIE 0x10000

/* DIntr: the reference C (do { di; sync.p } while (Status.EIE)). The original was assembled with gas 2.10, which
   moves "move $2,$4" into the last jr's delay slot (configure.py LIB_GAS210_FILES). */
#define DI() __asm__ __volatile__(".word 0x42000039" : : : "memory")
#define SYNCP() __asm__ __volatile__("sync.p" : : : "memory")
int DIntr(void) {
    int eie;
    int st;

    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        do {
            DI();
            SYNCP();
            MFC0_STATUS(st);
            st &= COP0_STATUS_EIE;
        } while (st);
    }
    return eie != 0;
}

int EIntr(void) {
    int eie;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    EI();
    return eie != 0;
}
