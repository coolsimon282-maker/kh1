// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* R5900 opcodes with no C spelling. COP0 Status ($12), bit 16 = interrupts enabled. */
#define SYNC() __asm__ __volatile__("sync" : : : "memory")
#define MFC0_STATUS(dst) __asm__ __volatile__("mfc0 %0, $12" : "=r"(dst))
#define COP0_STATUS_EIE 0x10000

int DIntr(void);
int EIntr(void);
int _DisableIntc(int);
int _EnableIntc(int);
int _DisableDmac(int);
int _EnableDmac(int);
int _iEnableIntc(int);
int _iDisableIntc(int);
int _iEnableDmac(int);
int _iDisableDmac(int);

int QueryIntrContext(void) {
    int st;
    __asm__ __volatile__(".set noreorder
	mfc0 %0, $12
	.set reorder" : "=r"(st));
    return (st ^ 1) & 1;
}

int DisableIntc(int cause) {
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _DisableIntc(cause);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int EnableIntc(int cause) {
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _EnableIntc(cause);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int DisableDmac(int channel) {
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _DisableDmac(channel);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int EnableDmac(int channel) {
    int eie;
    int rv;
    MFC0_STATUS(eie);
    eie &= COP0_STATUS_EIE;
    if (eie) {
        DIntr();
    }
    rv = _EnableDmac(channel);
    SYNC();
    if (eie) {
        EIntr();
    }
    return rv;
}

int iEnableIntc(int cause) {
    int r = _iEnableIntc(cause);
    SYNC();
    return r;
}

int iDisableIntc(int cause) {
    int r = _iDisableIntc(cause);
    SYNC();
    return r;
}

int iEnableDmac(int channel) {
    int r = _iEnableDmac(channel);
    SYNC();
    return r;
}

int iDisableDmac(int channel) {
    int r = _iDisableDmac(channel);
    SYNC();
    return r;
}
