/* Main-exec range [80019028,8001903C) from the SLUS executable.
 * SHA256(span)=8138ebde22ae6aca34659ef641bb7fbda0cbce7ef6bc8398e8876e7659a2290a.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_800747C8;

void func_80019028(void) {
    D_800747C8 = 1;
}
