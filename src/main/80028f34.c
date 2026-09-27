/* Main-exec range [80028F34,80028F54) from the SLUS executable.
 * SHA256(span)=f1a0a86dd5a5222d866048191a4f0f22cd06f0092060c44d619070bb0d6da2db.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80029178();                               /* static */

s32 func_80028F34(void) {
    return func_80029178(0x12) & 0xFF;
}
