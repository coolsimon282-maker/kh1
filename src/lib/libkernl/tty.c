// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"

/* the receive queue: a 16-byte header (the ring's size, the bytes queued, the read and write pointers) and the ring */
typedef struct {
    int size;
    int count;
    char* rp;
    char* wp;
    char buf[256];
} TtyQueue;

/* the tty socket record sceTtyInit hands DECI2 for sceTtyHandler */
typedef struct {
    volatile int s;    /* 0x00 the DECI2 socket */
    volatile int wlen; /* 0x04 bytes left to send */
    volatile int rlen; /* 0x08 bytes received into rbuf */
    volatile int busy; /* 0x0C set while a send is outstanding */
    char* wbuf;        /* 0x10 */
    char* rbuf;        /* 0x14 */
    TtyQueue* q;       /* 0x18 the receive queue */
} TtyRec;

/* tty.o's .bss (still in the data segments) */
extern TtyQueue D_0066AAC0; /* tty_queue */
extern TtyRec D_0066ABD0;   /* tty_rec */
extern char D_0066AC00[];   /* tty_sbuf, 320 bytes */
extern char D_0066AD40[];   /* tty_rbuf, 320 bytes */
/* tty.o's strings */
extern char D_004920F8[]; /* "TTY: packet size larger than expect\n" */
extern char D_00492120[]; /* "TTY: receive error" */
extern char D_00492138[]; /* "TTY: send err %d\n" */
extern char D_00492150[]; /* "TTY: err ti->wlen=%08x\n" */

void kprintf(char* fmt, ...);
int sceDeci2ExRecv(int s, void* buf, unsigned short len);
int sceDeci2ExSend(int s, void* buf, unsigned short len);
int sceDeci2Open(unsigned short protocol, void* opt, void* handler);
void sceDeci2Poll(int s);
int sceDeci2ReqSend(int s, signed char a1);
int DIntr(void);
int EIntr(void);
int FlushCache(int op);

void* QueueInit(int size) {
    D_0066AAC0.size = size;
    D_0066AAC0.count = 0;
    D_0066AAC0.wp = D_0066AAC0.buf;
    D_0066AAC0.rp = D_0066AAC0.buf;
    return &D_0066AAC0;
}

void QueuePeekWriteDone(TtyQueue* q) {
    int count = q->count + 1;
    char* wp = q->wp + 1;
    int cap = q->size;
    q->count = count;
    cap += 0x10;
    {
        char* end = (char*)q + cap;
        q->wp = wp;
        if (wp == end) {
            q->wp = q->buf;
        }
    }
}

void QueuePeekReadDone(TtyQueue* q) {
    q->count--;
    q->rp++;
    if (q->rp == (char*)q + (q->size + 0x10)) {
        q->rp = q->buf;
    }
}

void sceTtyHandler(int event, int param, void* opt) {
    TtyRec* tty = opt;
    int n;
    int i;
    char* hdr;

    switch (event) {
    case 1:
    case 2:
        if (param != 0) {
            if (320 < (unsigned int)(tty->rlen + param)) {
                kprintf(D_004920F8);
            }
            i = sceDeci2ExRecv(tty->s, tty->rbuf + tty->rlen, (unsigned short)param);
            if (i < 0) {
                kprintf(D_00492120);
            }
            tty->rlen = tty->rlen + i;
            return;
        }
        hdr = tty->rbuf;
        for (i = 12; i < *(unsigned short*)hdr; i++) {
            *tty->q->wp = tty->rbuf[i];
            QueuePeekWriteDone(tty->q);
        }
        tty->rlen = 0;
        return;

    case 3:
        n = sceDeci2ExSend(tty->s, tty->wbuf, (unsigned short)tty->wlen);
        if (n < 0) {
            kprintf(D_00492138, n);
            break;
        }
        tty->wbuf = tty->wbuf + n;
        tty->wlen = tty->wlen - n;
        return;

    case 4:
        if (tty->wlen != 0) {
            kprintf(D_00492150, tty->wlen);
        }
        break;

    default:
        return;
    }
    tty->busy = 0;
}

int sceTtyWrite(const char* buf, int len) {
    char* hdr;
    char* out;
    int n = 0;
    int i = 0;

    if (D_0066ABD0.busy != 0) {
        return -1;
    }
    DIntr();
    D_0066ABD0.busy = 1;
    hdr = (char*)((unsigned int)D_0066AC00 | 0x20000000);
    D_0066ABD0.wbuf = hdr;
    out = hdr + 12;
    while (len-- != 0) {
        if (*buf == '\n') {
            *out = '\r';
            n++;
            out++;
            if (n >= 256) {
                break;
            }
        }
        *out = *buf;
        n++;
        buf++;
        out++;
        i++;
        if (n >= 256) {
            break;
        }
    }
    D_0066ABD0.wlen = n + 12;
    *(short*)hdr = D_0066ABD0.wlen;
    if (sceDeci2ReqSend(D_0066ABD0.s, hdr[7]) < 0) {
        *(int*)&D_0066ABD0.busy = 0;
        EIntr();
        return -1;
    }
    while (D_0066ABD0.busy != 0) {
        sceDeci2Poll(D_0066ABD0.s);
    }
    EIntr();
    return i;
}

int sceTtyRead(void* buf, int size) {
    int i;
    char* p;

    for (i = 0; i < size; i++) {
        p = (char*)buf + i;
        while (((volatile TtyQueue*)D_0066ABD0.q)->count == 0) {}
        *p = *D_0066ABD0.q->rp;
        QueuePeekReadDone(D_0066ABD0.q);
        if (*p == '\n' || *p == '\r') {
            return i + 1;
        }
    }
    return i;
}

int sceTtyInit(void) {
    char* snd;
    char* rcv;

    FlushCache(0);
    D_0066ABD0.s = sceDeci2Open(0x210, &D_0066ABD0, sceTtyHandler);
    if (D_0066ABD0.s < 0) {
        return 0;
    }
    D_0066ABD0.busy = 0;
    rcv = (char*)((unsigned int)D_0066AD40 | 0x20000000);
    snd = (char*)((unsigned int)D_0066AC00 | 0x20000000);
    D_0066ABD0.wlen = 0;
    D_0066ABD0.rlen = 0;
    D_0066ABD0.rbuf = rcv;
    D_0066ABD0.wbuf = snd;
    *(short*)(snd + 4) = 0x210;
    snd[6] = 'E';
    snd[7] = 'H';
    *(short*)(snd + 2) = 0;
    *(int*)(snd + 8) = 0;
    D_0066ABD0.q = QueueInit(256);
    return 1;
}
