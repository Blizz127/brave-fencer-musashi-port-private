/* Main-exec range [80029CD4,80029D3C) from the SLUS executable.
 * SHA256(span)=38f4910da98a96176d0f34245c0da6a8217c56bb0b9a3fab6914a2fcc584e65b.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_8005C49C();
s32 func_80029CD4(s32 a0) {
    if (a0 == 0) {
        return 0;
    }
    return func_8005C49C() % a0;
}
