/* Main-exec range [8001B374,8001B384) from the SLUS executable.
 * SHA256(span)=68a2ef9db1d6570154dcd9b446555e795c333fff75305303e7a9084f80d30492.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_800A654C;

s32 func_8001B374(void) {
    return D_800A654C;
}
