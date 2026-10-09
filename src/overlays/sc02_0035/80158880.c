/* SC02.CD member35 [80158880,801588CC): twin of main_0012 80158880 (src/overlays/main_0012/80158880.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018686C[];
void func_80149020();
typedef struct { u8 pad[0x4F]; u8 idx; } T;
void func_80158880(T *p) {
    func_80149020(p);
    D_8018686C[p->idx](p);
}
