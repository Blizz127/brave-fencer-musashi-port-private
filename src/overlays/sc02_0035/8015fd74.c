/* SC02.CD member35 [8015FD74,8015FDCC): twin of main_0012 8015FD74 (src/overlays/main_0012/8015fd74.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void *func_8013767C();
void func_80147324();
void func_80146CA0();
extern void *D_80186EC8[];
typedef struct {
    u8 pad[0x198];
    void *ptr;
    u8 pad19C[4];
    u8 idx;
} T;
void func_8015FD74(T *p) {
    func_80147324(0x18);
    p->ptr = func_8013767C(D_80186EC8[p->idx]);
    func_80146CA0(p);
}
