/* Main-exec range [800624F4,8006252C) from the SLUS executable.
 * SHA256(span)=58c3817f3f2a35be2a6df19053f8727435acfd443b8c0061f0627dbca7ae3595.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_800626DC();
void func_800626A8();
void func_800625A4();
extern s32 func_80072A24;
void func_800624F4(void) {
    func_800626DC();
    func_800626A8();
    func_800625A4();
    func_80072A24 = 0;
}
