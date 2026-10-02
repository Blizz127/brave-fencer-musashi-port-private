/* Main-exec range [800133BC,800133E4) from the SLUS executable.
 * SHA256(span)=f4c60116b8a191c5530ebbb8a8f8bf5e2821967183d26cfcdae2824d0afd1495.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_800133E4();                                /* static */
void func_80047D3C(s32);                               /* static */

/* a0/a1 pass straight through to func_800133E4 (the retail words leave them
 * untouched before the jal), so they are parameters here. */
void func_800133BC(void *a, void *b) {
    func_80047D3C(func_800133E4(a, b));
}
