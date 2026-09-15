/* Main-exec range [800439B4,800439D4) from the SLUS executable.
 * SHA256(span)=7c9be71e8bab724eb22bed4e2031683f062c190c8d8df6d6c06c49b3b108ae29.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80045190();                                /* static */

s32 func_800439B4(void) {
    return func_80045190() == 0;
}
