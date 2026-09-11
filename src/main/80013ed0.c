/* Main-exec helper [80013ED0,80013F3C): interleaves three u16 triples.
 * SHA256(span)=0adba29b1ddfd12cac90b885bed5a9dee2458b3f0185597a9c8d9a6e34f7e8e4. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80013ED0(u16 *arg0, u16 *arg1, u16 *arg2, u16 *arg3) {
    arg0[0] = arg1[0];
    arg0[1] = arg2[0];
    arg0[2] = arg3[0];
    arg0[3] = arg1[1];
    arg0[4] = arg2[1];
    arg0[5] = arg3[1];
    arg0[6] = arg1[2];
    arg0[7] = arg2[2];
    arg0[8] = arg3[2];
}
