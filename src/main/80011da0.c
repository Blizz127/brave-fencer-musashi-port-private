/* Main-exec range [80011DA0,80011DCC) from the SLUS executable.
 * SHA256(span)=d2cac3ace9f0176b2237c1015299e066a5645c7e115bf1bd495806f8a633338b.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

extern s32 D_80074780;

void func_80011DA0(void) {
    D_80074780 = 1;
}
