/* Main-exec range [8002AEE4,8002AEF8) from the SLUS executable.
 * SHA256(span)=f6b8c020cc182011d0c9df210ead3d05091f5526a3fdcc0af162ef74828a39be.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_800760C8;

void func_8002AEE4(void) {
    D_800760C8 = 2;
}
