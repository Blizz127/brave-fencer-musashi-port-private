/* Main-exec range [80036D24,80036D58) from the SLUS executable.
 * SHA256(span)=d8fdd1214ca235c52358f116e909606fa2e2ad82862095e42caa8f88f95e0342.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_8006AEE8;
extern s32 D_80078F10;
extern s8 D_800A4F1A;

void func_80036D24(void) {
    D_80078F10 = 0;
    if (D_8006AEE8 < 2) {
        D_8006AEE8 = 0;
        D_800A4F1A = 0;
    }
}
