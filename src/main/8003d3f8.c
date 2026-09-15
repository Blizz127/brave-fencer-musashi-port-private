/* Main-exec range [8003D3F8,8003D424) from the SLUS executable.
 * SHA256(span)=03e99fbe55c4d1733ec3cb4384eb6851ce2257e08330c823088e1cb90ae72eeb.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern u8 *D_8006B54C;
extern s16 D_8006B100;
extern s16 D_8006B102;
void func_8003D3F8(s32 a0, s32 a1) {
    s16 *g = (s16 *)(D_8006B54C + 0x184);
    g[0] = a0;
    g[1] = a1;
    D_8006B100 = a0;
    D_8006B102 = a1;
}
