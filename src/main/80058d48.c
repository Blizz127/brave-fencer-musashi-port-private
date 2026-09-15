/* Main-exec range [80058D48,80058D70) from the SLUS executable.
 * SHA256(span)=b57ebdd5a532fc24e09757426347624f95745cb149031c9715950a8fc2281fa0.
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
typedef struct { u8 pad[7]; u8 flags; } T;
void func_80058D48(T *p, s32 on) {
    if (on) p->flags |= 1;
    else p->flags &= ~1;
}
