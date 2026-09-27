/* Main-exec range [8002955C,8002957C) from the SLUS executable.
 * SHA256(span)=d95235edeec8bdceeeb7d24b7b93e6b7df4b90bbfe16891fd32c3aeab9a976ee.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80078E84;

void func_8002955C(void) {
    D_80078E84 += 1;
}
