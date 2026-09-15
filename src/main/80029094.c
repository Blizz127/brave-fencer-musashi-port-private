/* Main-exec range [80029094,800290BC) from the SLUS executable.
 * SHA256(span)=b3a78cf21a98fb8af2cb9f8c412f864969da8f17efd46b8100ab6f5d8b0515f0.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80016714(void *, s32);                            /* static */
extern s32 *D_800BA2B8;

void func_80029094(void) {
    func_80016714(&D_800BA2B8, 0x60);
}
