/* Main-exec range [80028F78,80028F98) from the SLUS executable.
 * SHA256(span)=17113288e9513791f45e3317c796ea7ad33e6af4d3021864c54e9714a8aac7cb.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80029178();                               /* static */

s32 func_80028F78(void) {
    return func_80029178(0x13) & 0xFF;
}
