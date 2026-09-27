/* Main-exec range [8002A4C8,8002A4D8) from the SLUS executable.
 * SHA256(span)=a4965f9647bdadff743017c1274f2abf671acd4d7c3e912a249be2603f0b38f0.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80078EF0;

s32 func_8002A4C8(void) {
    return D_80078EF0;
}
