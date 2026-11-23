// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* libpad2 has no reference source: the types are derived from the assembly. */

/* one half of a socket's DMA buffer (the IOP fills the two halves in turn) */
typedef struct {
    unsigned char state; /* 0x00 */
    unsigned char unk1;
    unsigned char len;   /* 0x02, bytes of pad data */
    unsigned char unk3;
    int stat;            /* 0x04 */
    unsigned char pad08[0x14];
    unsigned char data[0x60]; /* 0x1C */
    int count;           /* 0x7C, bumped by every transfer */
} Pad2Side;

typedef struct {
    int valid;  /* 0x0 */
    int kind;   /* 0x4: 1 = a digital button (one bit), 8 = an analog value (one byte) */
    int offset; /* 0x8: byte in the pad data */
    int shift;  /* 0xC: bit in that byte */
} Pad2Button;

typedef struct {
    int used;           /* 0x000 */
    int linked;         /* 0x004 */
    int dep;            /* 0x008 */
    Pad2Side *dma;      /* 0x00C */
    Pad2Button btn[40]; /* 0x010 */
    unsigned char pad290[0xA0];
} Pad2Socket; /* 0x330 */

/* the request word sceDbcReceiveData is given */
typedef struct {
    unsigned long a : 14;
    unsigned long b : 2;
    unsigned long c : 8;
    unsigned long d : 8;
} Pad2Cmd;

typedef union {
    Pad2Cmd f;
    int i;
} Pad2CmdU;

typedef struct {
    unsigned int option;
    int type;
    int port;
    int slot;
    int number;
    unsigned char name[16];
} Pad2DbcParam;

typedef struct {
    unsigned int option;
    int port;
    int slot;
    int number;
    unsigned char name[16];
} scePad2SocketParam;

extern int D_0046C5D0;            /* set by scePad2Init */
extern int D_0046C5D8[2];         /* the two DMA counts last seen by scePad2CheckDma */
extern char *D_0046C5E0[4];       /* the state names */
extern char D_004930D8[];         /* an empty string */
extern Pad2Socket D_00670040[16]; /* the sockets */

int sceDbcCreateSocket(Pad2DbcParam *p, void *buf0, void *buf1);
int sceDbcDeleteSocket(int s);
int sceDbcGetDepNumber(int s);
int sceDbcReceiveData(int s, int cmd, void *buf, void *data);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *d, int c, unsigned int n);
char *strcpy(char *d, const char *s);
void SyncDCache(void *a, void *b);
int scePad2DeleteSocket(int s);
int scePad2LinkDriver(int s);
Pad2Side *scePad2GetSide(int s);
int scePad2CheckDma(int s);
int scePad2SetButtonOrder(unsigned char *bits, Pad2Button *btn);

int scePad2Init(int mode)
{
    int i;

    D_0046C5D0 = 1;
    for (i = 0; i < 16; i++) {
        D_00670040[i].used = 0;
        D_00670040[i].linked = 0;
        D_00670040[i].dep = 0;
    }
    return 1;
}

int scePad2End(void)
{
    int i;
    int r;

    D_0046C5D0 = 0;
    for (i = 0; i < 16; i++) {
        if (D_00670040[i].used != 0) {
            r = scePad2DeleteSocket(i);
            if (r < 0) {
                return r;
            }
        }
    }
    return 1;
}

int scePad2CreateSocket(scePad2SocketParam *param, void *buf)
{
    Pad2DbcParam dp;
    Pad2Side *p;
    int s;
    int i;

    if ((int)buf & 0x3F) {
        return -1;
    }
    if (param != 0) {
        dp.option = param->option;
        dp.port = param->port;
        dp.slot = param->slot;
        dp.number = param->number;
        memcpy(dp.name, param->name, 16);
    } else {
        dp.option = 0;
        dp.port = 0;
        dp.slot = 0;
        dp.number = 0;
        dp.name[0] = 0;
    }
    dp.type = 1;
    dp.option |= 1;
    s = sceDbcCreateSocket(&dp, buf, (char *)buf + 0x80);
    if (s < 0) {
        return s;
    }
    D_00670040[s].used = 1;
    D_00670040[s].dma = buf;
    p = buf;
    for (i = 0; i < 2; i++) {
        p->state = 0;
        p->count = 0;
        p->unk1 = 0;
        p->unk3 = 0;
        p->len = 0;
        p->stat = 0;
        memset(p->data, 0xFF, 0x20);
        p++;
    }
    return s;
}

int scePad2DeleteSocket(int s)
{
    int r;

    r = sceDbcDeleteSocket(s);
    if (r < 0) {
        return r;
    }
    D_00670040[s].used = 0;
    D_00670040[s].linked = 0;
    D_00670040[s].dep = 0;
    return 1;
}

int scePad2Read(int s, unsigned char *data)
{
    Pad2Side *side;
    unsigned char *src;

    if (D_00670040[s].used == 0) {
        return -1;
    }
    if (D_00670040[s].linked == 0) {
        if (scePad2LinkDriver(s) < 0) {
            return -1;
        }
    }
    side = scePad2GetSide(s);
    if (side->len != 0) {
        src = side->data;
        if (src != 0) {
            memcpy(data, src, side->len);
            scePad2SetButtonOrder(&side->data[side->len], D_00670040[s].btn);
        }
    }
    if (side->stat == 0) {
        return -1;
    }
    return side->len;
}

int scePad2GetButtonProfile(int s, unsigned char *data)
{
    Pad2CmdU cmd;
    int ret;
    int r;

    if (D_00670040[s].linked == 0) {
        if (scePad2LinkDriver(s) < 0) {
            return -1;
        }
    }
    cmd.f.a = 2;
    cmd.f.b = 3;
    cmd.f.c = 2;
    cmd.f.d = 1;
    r = sceDbcReceiveData(s, cmd.i, &ret, data);
    if (r < 0) {
        return r;
    }
    scePad2SetButtonOrder(data, D_00670040[s].btn);
    return ret;
}

int scePad2GetState(int s)
{
    Pad2CmdU cmd;
    unsigned char state;
    int buf;
    Pad2Side *side;

    if (D_00670040[s].linked == 0) {
        if (scePad2LinkDriver(s) < 0) {
            return 0;
        }
    }
    if (scePad2CheckDma(s) != 0) {
        side = scePad2GetSide(s);
        if (side->stat == 0) {
            if (scePad2LinkDriver(s) < 0) {
                D_00670040[s].linked = 0;
                return 0;
            }
        }
        state = side->state;
    } else {
        cmd.f.a = 12;
        cmd.f.b = 2;
        cmd.f.c = 1;
        cmd.f.d = 1;
        if (sceDbcReceiveData(s, cmd.i, &buf, &state) < 0) {
            return 0;
        }
    }
    return state;
}

int scePad2GetButtonInfo(int s, unsigned char *data, int idx)
{
    Pad2Button b;
    int v;

    b = D_00670040[s].btn[idx];
    if (b.valid != 0) {
        switch (b.kind) {
        case 1:
            if ((data[b.offset] >> b.shift) & 1) {
                return 0;
            }
            return 1;
        case 8:
            v = (unsigned char)(data[b.offset] >> b.shift);
            if (b.shift != 0) {
                b.offset++;
                v = (unsigned char)(v | (data[b.offset] << (b.kind - b.shift)));
            }
            return v;
        }
        return -1;
    }
    return -1;
}

int scePad2LinkDriver(int s)
{
    int r;

    r = sceDbcGetDepNumber(s);
    if (r < 0) {
        return r;
    }
    D_00670040[s].dep = r;
    D_00670040[s].linked = 1;
    return r;
}

Pad2Side *scePad2GetSide(int s)
{
    Pad2Side *side[2];

    side[0] = D_00670040[s].dma;
    side[1] = D_00670040[s].dma + 1;
    SyncDCache(side[0], (char *)side[0] + 0x100);
    return side[side[0]->count < side[1]->count];
}

int scePad2CheckDma(int s)
{
    Pad2Side *side[2];

    side[0] = D_00670040[s].dma;
    side[1] = D_00670040[s].dma + 1;
    if (side[0]->count == 0) {
        return 0;
    }
    if (D_0046C5D8[0] == side[0]->count && D_0046C5D8[1] == side[1]->count) {
        return 0;
    }
    D_0046C5D8[0] = side[0]->count;
    D_0046C5D8[1] = side[1]->count;
    return 1;
}

int scePad2SetButtonOrder(unsigned char *bits, Pad2Button *btn)
{
    int shift = 0;
    int idx = 0;
    int i;
    int bitpos = 0;

    for (i = 0; i < 40; i++) {
        if ((*bits >> shift) & 1) {
            btn->valid = 1;
            btn->offset = idx;
            btn->shift = bitpos;
            if ((i >= 16 && i < 32) || (i >= 35 && i < 39)) {
                btn->kind = 8;
                idx++;
            } else {
                btn->kind = 1;
                bitpos++;
                if ((bitpos & 7) == 0) {
                    idx++;
                    bitpos = 0;
                }
            }
        } else {
            btn->valid = 0;
            btn->offset = 0;
            btn->shift = 0;
        }
        shift++;
        if ((shift & 7) == 0) {
            bits++;
            shift = 0;
        }
        btn++;
    }
    return 1;
}

void scePad2StateIntToStr(int state, char *str)
{
    if ((unsigned int)state < 4) {
        strcpy(str, D_0046C5E0[state]);
        return;
    }
    *str = D_004930D8[0];
}
