/* Main-exec range [80044CE8,80044D38) from the SLUS executable.
 * SHA256(span)=4fb21ac1a22ffcfd566a7296d5872ceecda3bdfc710ca165c5c87e0043bacbc9.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80042580();
void func_800425B0();
void func_80045290();
extern s32 D_8006CC88, D_8006CC84, D_8006CC98, D_8006CC94;
void func_80044CE8(void) {
    D_8006CC88 = 0;
    D_8006CC84 = 0;
    D_8006CC98 = 0;
    D_8006CC94 = 0;
    func_80042580();
    func_800425B0(2, func_80045290);
}
