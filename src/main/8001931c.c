/* Main-exec range [8001931C,80019378) from the SLUS executable.
 * SHA256(span)=49da17456b56669df18d3a0642201d3f6da54fb6da5d8d2a8ab0e814cfd2374a.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_800747E4;
extern s32 D_800747E8;
void func_8002D4C8(s32, s32);                              /* static */
extern s32 D_800BA1B4;

void func_8001931C(void) {
    if (D_800BA1B4 == 5) {
        if (D_800747E4 != 0) {
            func_8002D4C8(0x16, 0);
        }
        D_800BA1B4 = 0;
        D_800747E8 = 0;
        D_800747E4 = 0;
    }
}
