/* Main-exec range [80052F04,80052F38) from the SLUS executable.
 * SHA256(span)=03988a86a63b6d7e70a5299ed4f6eee02cfd7e753ea1b80add5ac685ab9d6c92.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80048EAC(void *, s32);                        /* static */
void func_8004917C(s32);                               /* static */
extern s32 *D_800A63F0;

void func_80052F04(s32 arg0) {
    func_8004917C(func_80048EAC(&D_800A63F0, arg0));
}
