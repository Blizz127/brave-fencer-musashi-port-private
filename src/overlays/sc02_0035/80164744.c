/* SC02.CD member35 [80164744,801647A4): twin of main_0012 80164744 (src/overlays/main_0012/80164744.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80162D28();
typedef void (*CB)();
extern CB D_801870D4[];
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x1C]; void *inner;
} T;
void func_80164744(T *p) {
    void *in = p->inner;
    D_801870D4[p->u2](p);
    if (in) {
        func_80162D28(p);
    }
}
