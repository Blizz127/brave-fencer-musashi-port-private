/* Main-exec range [800193A8,800193B8) from the SLUS executable.
 * SHA256(span)=71c4e2769ec978136179db7069fa9034fe5013b64ace51cd058054dded52eb45.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_800747D4;

void func_800193A8(s32 arg0) {
    D_800747D4 = arg0;
}
