// Library code (Final Mix). One function at a time: replace an INCLUDE_ASM line with matching C.
// Data this file owns is still in the data segments: declare it extern here, do not define it.
#include "common.h"
#include <sifrpc.h>

int memcmp(const void*, const void*, unsigned int);
void* memcpy(void*, const void*, unsigned int);
void* memset(void*, int, unsigned int);
char* strncpy(char*, const char*, unsigned int);

/* eeloadfile.o's data, still in the data segments */
extern int D_00465374;              /* lf_bind_state: -1 until _lf_bind has bound the loadfile server */
extern char* D_00465378;            /* lf_stamp ("....") */
extern char D_00464B18[];           /* __ps2_klibinfo__ + 12: the library's version stamp */
extern char D_0066DB00[];           /* lf_buf[0x200], the RPC buffer */
extern sceSifClientData D_00667D00; /* lf_cd */
extern char D_0066DD28[];           /* lf_iopVersion[4] */

/* .rodata (0x00492340-0x00492350): lf_stamp's "....", then the "all" literal of sceSifLoadElf. In the original
   "...." was the literal of lf_stamp's initializer, but lf_stamp (D_00465378) has to stay in filestub's .data (it
   sits on a 4-byte boundary), so the string is a named array here. */
const char D_00492340[] = "....";

int _lf_bind(void) {
    int i;
    int r;
    int val;
    if (D_00465374 >= 0)
        goto ret0;
loop:
    r = sceSifBindRpc(&D_00667D00, 0x80000006, 0);
    if (r < 0)
        return -1;
    val = (int)D_00667D00.serve;
    if (val == 0)
        goto delay;
    D_00465374 = 0;
    r = sceSifCallRpc(&D_00667D00, 0xFF, 0, 0, 0, D_0066DB00, 4, 0, 0);
    if (r < 0)
        return 0xFFFEFFFF;
    __builtin_memcpy(D_0066DD28, D_0066DB00, 4);
    return 0;
delay:
    i = 0x100000;
    do {
        i--;
    } while (i != -1);
    goto loop;
ret0:
    return 0;
}

int _lf_version(void) {
    void* s3 = D_00464B18;
    void* s1 = D_0066DD28;
    int s2 = 0;
    char* v;
    if (memcmp(s1, s3, 4) == 0)
        goto done;
    v = D_00465378;
    if (memcmp(s1, v, 4) == 0)
        goto done;
    v = D_00465378;
    s2 = (0 < (unsigned int)memcmp(s3, v, 4));
done:
    return s2;
}

int sceSifLoadFileReset(void) {
    D_00465374 = -1;
    memset(D_0066DD28, 0, 4);
    return 0;
}

/* The request's 0xFC-byte argument block: a record assignment, expanded inline (movstrsi). */
typedef struct {
    char v[0xFC];
} SceLfArgBuf;

/* The loadfile RPC send buffer at lf_buf (0x200 bytes sent, 8 read back). */
typedef struct {
    int addr;
    int arglen;
    char name[0xFC];
    SceLfArgBuf args;
} SceLfRpcBuf;

int _sceSifLoadModuleBuffer(void* addr, int arglen, int args, void* ret) {
    SceLfRpcBuf* p;
    int r;

    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    p = (SceLfRpcBuf*)D_0066DB00;
    ((SceLfRpcBuf*)D_0066DB00)->addr = (int)addr;
    if (args != 0) {
        if (arglen >= 0xFD) {
            p->args = *(SceLfArgBuf*)args;
            ((SceLfRpcBuf*)D_0066DB00)->arglen = 0xFC;
        } else {
            memcpy(&p->args, (char*)args, arglen);
            p->arglen = arglen;
        }
    } else {
        p->arglen = 0;
    }
    if (sceSifCallRpc(&D_00667D00, 6, 0, D_0066DB00, 0x200, D_0066DB00, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = ((SceLfRpcBuf*)D_0066DB00)->addr;
    *(int*)ret = ((SceLfRpcBuf*)D_0066DB00)->arglen;
    return r;
}

int sceSifStopModule(int modid, int arglen, int args, void* ret) {
    SceLfRpcBuf* p;
    int r;

    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    p = (SceLfRpcBuf*)D_0066DB00;
    ((SceLfRpcBuf*)D_0066DB00)->addr = modid;
    if (args != 0) {
        if (arglen >= 0xFD) {
            p->args = *(SceLfArgBuf*)args;
            ((SceLfRpcBuf*)D_0066DB00)->arglen = 0xFC;
        } else {
            memcpy(&p->args, (char*)args, arglen);
            p->arglen = arglen;
        }
    } else {
        p->arglen = 0;
    }
    if (sceSifCallRpc(&D_00667D00, 7, 0, D_0066DB00, 0x200, D_0066DB00, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = ((SceLfRpcBuf*)D_0066DB00)->addr;
    *(int*)ret = ((SceLfRpcBuf*)D_0066DB00)->arglen;
    return r;
}

int sceSifUnloadModule(int modid) {
    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    *(int*)D_0066DB00 = modid;
    if (sceSifCallRpc(&D_00667D00, 8, 0, D_0066DB00, 4, D_0066DB00, 4, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return *(int*)D_0066DB00;
}

int sceSifSearchModuleByName(const char* name) {
    char* buf;

    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    strncpy((D_0066DB00 + 8), name, 252);
    buf = (D_0066DB00 + 8) - 8;
    buf[0x103] = 0;
    if (sceSifCallRpc(&D_00667D00, 9, 0, buf, 0x200, buf, 4, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return *(int*)buf;
}

int sceSifSearchModuleByAddress(const void* addr) {
    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    *(int*)D_0066DB00 = (int)addr;
    if (sceSifCallRpc(&D_00667D00, 10, 0, D_0066DB00, 4, D_0066DB00, 4, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return *(int*)D_0066DB00;
}

void sceSifLoadModuleBuffer(void* addr, int arglen, int args) {
    int local[4];
    _sceSifLoadModuleBuffer(addr, arglen, args, &local);
}

int sceSifLoadStartModuleBuffer(void* addr, int arglen, int args, void* ret) {
    return _sceSifLoadModuleBuffer(addr, arglen, args, ret);
}

int _sceSifLoadModule(void* name, int arglen, int args, int ret, int rpcno) {
    char* buf;
    int r;

    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    strncpy((D_0066DB00 + 8), (char*)name, 252);
    buf = (D_0066DB00 + 8) - 8;
    buf[0x103] = 0;
    if (args != 0) {
        if (arglen >= 0xFD) {
            *(SceLfArgBuf*)(buf + 0x104) = *(SceLfArgBuf*)args;
            *(int*)D_0066DB00 = 0xFC;
        } else {
            memcpy(buf + 0x104, (char*)args, arglen);
            *(int*)buf = arglen;
        }
    } else {
        buf[0x104] = 0;
        *(int*)buf = 0;
    }
    if (sceSifCallRpc(&D_00667D00, rpcno, 0, D_0066DB00, 0x200, D_0066DB00, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = *(int*)(D_0066DB00 + 0);
    *(int*)ret = *(int*)(D_0066DB00 + 4);
    return r;
}

int sceSifLoadModule(const char* name, int arglen, const char* args) {
    int local;
    return _sceSifLoadModule((void*)name, arglen, (int)args, (int)&local, 0);
}

int _sceSifLoadStartModule(void* name, int arglen, int args, int ret) {
    return _sceSifLoadModule(name, arglen, args, ret, 0);
}

int _sceSifLoadElfPart(void* name, int sec, int out, int rpcno) {
    char* buf;
    int r;

    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if (_lf_version() != 0) {
        return 0xFFFEFFFC;
    }
    strncpy((D_0066DB00 + 8), (char*)name, 252);
    buf = (D_0066DB00 + 8) - 8;
    buf[0x103] = 0;
    strncpy((D_0066DB00 + 8) + 252, (char*)sec, 252);
    buf[0x1FF] = 0;
    if (sceSifCallRpc(&D_00667D00, rpcno, 0, buf, 0x200, buf, 0x10, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    r = *(int*)buf;
    if (r == 0) {
        return 0xFFFEFFFD;
    }
    ((int*)out)[0] = r;
    ((int*)out)[1] = *(int*)(buf + 4);
    return 0;
}

int sceSifLoadElfPart(void* name, int sec, int out) {
    return _sceSifLoadElfPart(name, sec, out, 1);
}

int sceSifLoadElf(void* name, int out) {
    return _sceSifLoadElfPart(name, (int)"all", out, 1);
}

int sceSifGetIopAddr(int addr, void* data, int type) {
    int r;
    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    if ((unsigned int)type >= 3) {
        return 0xFFFEFFFE;
    }
    *(int*)(D_0066DB00 + 0) = addr;
    *(int*)(D_0066DB00 + 4) = type;
    r = sceSifCallRpc(&D_00667D00, 3, 0, D_0066DB00, 0x20, D_0066DB00, 0x20, 0, 0);
    if (r < 0) {
        return 0xFFFEFFFF;
    }
    if (type == 0) {
        *(unsigned char*)data = *(unsigned char*)D_0066DB00;
    } else if (type == 1) {
        *(unsigned short*)data = *(unsigned short*)D_0066DB00;
    } else if (type == 2) {
        *(int*)data = *(int*)D_0066DB00;
    } else {
        return 0xFFFEFFFE;
    }
    return 0;
}

int sceSifSetIopAddr(int addr, void* data, int type) {
    if (_lf_bind() < 0) {
        return 0xFFFF0000;
    }
    *(int*)(D_0066DB00 + 0) = addr;
    *(int*)(D_0066DB00 + 4) = type;
    if (type == 0) {
        *(unsigned char*)(D_0066DB00 + 8) = *(unsigned char*)data;
    } else if (type == 1) {
        *(unsigned short*)(D_0066DB00 + 8) = *(unsigned short*)data;
    } else if (type == 2) {
        *(int*)(D_0066DB00 + 8) = *(int*)data;
    } else {
        return 0xFFFEFFFE;
    }
    if (sceSifCallRpc(&D_00667D00, 2, 0, D_0066DB00, 0x20, D_0066DB00, 0x10, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    return 0;
}
