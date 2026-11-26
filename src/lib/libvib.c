// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
#include "common.h"

#ifdef VERSION_FM
// .data (0x0046C5F0-0x0046C600)
char D_0046C5F0[16] = "PsIIlibvib  2500"; // library version (no NUL)
#endif

/* the DBC command word passed by value in one 64-bit register */
typedef struct {
    unsigned long long cmd : 14;
    unsigned long long type : 2;
    unsigned long long unit : 8;
    unsigned long long ver : 8;
    unsigned long long pad : 32;
} VibDbcCmd;

int sceDbcReceiveData(int port, VibDbcCmd cmd, void* res, void* data);
int sceDbcSendData2(int port, VibDbcCmd cmd, void* res, void* data);
void* memcpy(void* dst, const void* src, unsigned int n);

int sceVibGetProfile(int port, unsigned char* profile) {
    VibDbcCmd c;
    int res;
    int r;

    c.cmd = 2;
    c.type = 2;
    c.unit = 3;
    c.ver = 1;
    r = sceDbcReceiveData(port, c, &res, profile);
    if (r < 0) {
        return r;
    }
    return res;
}

int sceVibSetActParam(int port, int n1, unsigned char* p1, int n2, unsigned char* p2) {
    struct {
        int n1;
        int n2;
        unsigned char data[0x28];
    } buf;
    int size;
    VibDbcCmd c;

    buf.n2 = n2;
    size = 0x28;
    c.cmd = 0xB;
    c.type = 1;
    c.unit = 3;
    c.ver = 1;
    memcpy(buf.data, p2, n2);
    buf.n1 = n1;
    memcpy(buf.data + n2, p1, n1);
    return sceDbcSendData2(port, c, &size, &buf);
}
