/* Main-exec range [80028E44,80028E68) from the SLUS executable.
 * SHA256(span)=00c68427b849ce362f1c9bc09f59faf80d4cb4f4fac5cd66cda9233c49a09567.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80029124(s32, s32);                            /* static */

void func_80028E44(s32 arg0) {
    func_80029124(0xE, arg0 & 0xFF);
}
