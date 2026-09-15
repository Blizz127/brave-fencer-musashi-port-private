/* Main-exec range [8002959C,800295D4) from the SLUS executable.
 * SHA256(span)=c331090ee2dd148e22714a2f4f998d6cb8f387d1c28d9f6ee2f2f23ffd51af82.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8002A544();                                 /* static */
extern s32 D_80078E88;

void func_8002959C(void) {
    func_8002A544(0x32);
    D_80078E88 += 1;
}
