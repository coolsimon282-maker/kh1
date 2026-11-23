// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* intr.o's file-static setup(): syscall 116 (SetSyscall) */
void func_0025FA20(int num, int addr) {
    __asm__ __volatile__("addiu $3, $0, 116\n\tsyscall 0" : : : "$3", "memory");
}

/* Copy(dst, src, len): syscall 90 */
void func_0025FA30(char* dst, char* src, int len) {
    __asm__ __volatile__("addiu $3, $0, 90\n\tsyscall 0" : : : "$3", "memory");
}

/* kCopy */
int func_0025FA40(int* dst, int* src, unsigned int n) {
    unsigned int i;
    n >>= 2;
    for (i = 0; i < n; i++) {
        *dst++ = *src++;
    }
    return 0;
}

/* GetEntryAddress(num): syscall 91 */
int func_0025FA78(int num) {
    __asm__ __volatile__("addiu $3, $0, 91\n\tsyscall 0" : : : "$3", "memory");
}

int FlushCache(int);

extern unsigned int D_0046B6E0[]; /* alarm_handler[464], copied to 0x80076000 */
extern unsigned int D_0046BE20[]; /* alarm_entry, copied to 0x82000 */
extern int D_0046BE48[];          /* alarm_syscalls[16]: {number, handler} pairs */

void InitAlarm(void) {
    unsigned int i;

    if (*(volatile int*)0x10001810 & 0x100)
        return;
    func_0025FA20(D_0046BE48[0], D_0046BE48[1]);
    func_0025FA30((char*)0x80076000, (char*)D_0046B6E0, 0x740);
    func_0025FA30((char*)0x82000, (char*)D_0046BE20, 0x28);
    FlushCache(0);
    FlushCache(2);
    func_0025FA20(D_0046BE48[2], D_0046BE48[3]);
    for (i = 2; i < 8; i++) {
        func_0025FA20(D_0046BE48[i * 2], func_0025FA78(D_0046BE48[i * 2]));
    }
}
