/* Main-exec range [80041A20,80041A50) from the SLUS executable.
 * SHA256(span)=2a20534261d06aa38b466fb77374006e38257b719d665e5b1b0e095ae7cb31eb.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_80041AB0();
s16 func_80041A20(void *p, s16 a1) {
    return func_80041AB0(p, a1, 0, 0);
}
