/* Main-exec range [80013294,800132BC) from the SLUS executable.
 * SHA256(span)=cff54305588bdf00b31a4655d16c87d33482d1f85b391bcc16df83b3632767f5.
 * Word export for the native seam; the C body below keeps its
 * own oracle match claim. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_800132BC();                                /* static */
s32 func_80047D3C(s32);                               /* static */

/* returns func_80047D3C's result: callers test v0 after the jal (retail leaves it there). */
s32 func_80013294(void) {
    return func_80047D3C(func_800132BC());
}
