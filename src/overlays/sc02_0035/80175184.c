/* SC02.CD member35 [80175184,801751D8): twin of main_0012 80175184 (src/overlays/main_0012/80175184.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187B58[];
void func_80175268();
void func_80175184(u16 *p) {
    u16 idx = p[1];
    if (idx < 2)
        D_80187B58[idx](p);
    else
        func_80175268();
}
