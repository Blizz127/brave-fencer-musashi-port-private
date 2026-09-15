/* Main-exec range [80028F98,80028FBC) from the SLUS executable.
 * SHA256(span)=c066152a4be9bf30f15e6c82c24e9251c2932c01739f0fc9fafea08b3205f73f.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80029124(s32, s32);                            /* static */

void func_80028F98(s32 arg0) {
    func_80029124(0x13, arg0 & 0xFF);
}
