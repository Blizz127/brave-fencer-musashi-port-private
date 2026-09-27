/* Main-exec range [80028E68,80028E88) from the SLUS executable.
 * SHA256(span)=80c5e262d6bb38ed888ade7fe0b6d418c05021117639a05df20682478030b010.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80029178();                               /* static */

s32 func_80028E68(void) {
    return func_80029178(0xF) & 0xFF;
}
