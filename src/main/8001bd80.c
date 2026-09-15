/* Main-exec range [8001BD80,8001BDA0) from the SLUS executable.
 * SHA256(span)=5ea0150c9ad5ea329c7abdec14a1c74744e7d911f2dde4a0209d244177aab93d.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80034B98();                                /* static */

s32 func_8001BD80(void) {
    return func_80034B98() != 0;
}
