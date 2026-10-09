/* SC02.CD member35 [80164BA0,80164BDC): twin of main_0012 80164BA0 (src/overlays/main_0012/80164ba0.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801870E0[];
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80164BA0(T *p) {
    D_801870E0[p->idx](p);
}
