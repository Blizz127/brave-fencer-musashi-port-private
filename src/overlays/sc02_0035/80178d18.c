/* SC02.CD member35 [80178D18,80178D40): twin of main_0012 80178D18 (src/overlays/main_0012/80178d18.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80174714();                                  /* static */
extern s16 D_801BEA44;

void func_80178D18(void) {
    D_801BEA44 = 0;
    func_80174714();
}
