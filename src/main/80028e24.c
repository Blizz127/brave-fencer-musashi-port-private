/* Main-exec range [80028E24,80028E44) from the SLUS executable.
 * SHA256(span)=02168c8e464306707adc83641ddaacc1c3311728f8eed33940d53a87fb7a4096.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80029178();                               /* static */

s32 func_80028E24(void) {
    return func_80029178(0xE) & 0xFF;
}
