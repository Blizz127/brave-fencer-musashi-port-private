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
/* a0/a1 pass straight through to func_800132BC (the retail words leave them
 * untouched before the jal), so they are parameters here. */
s32 func_80013294(void *a, void *b) {
    return func_80047D3C(func_800132BC(a, b));
}
