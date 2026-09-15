/* Main-exec range [8003AE9C,8003AF04) from the SLUS executable.
 * SHA256(span)=7b51165c077050f90cb0bb0e30aa6a3acbead310880328d43514673459002dde.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_8003AB84();
extern u16 D_8006B564;
extern s32 D_8006B574;
s32 func_8003AE9C(s32 a0, s32 a1) {
    func_8003AB84(2, D_8006B564 << D_8006B574);
    func_8003AB84(0);
    func_8003AB84(3, a0, a1);
    return a1;
}
