/* Main-exec range [80041A50,80041A80) from the SLUS executable.
 * SHA256(span)=1f723cd9db4a38ae61c4b8cf1cc82822a4afb853e136009c74744a0894675841.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_80041AB0();
s16 func_80041A50(void *p, s16 a1, s32 a2) {
    return func_80041AB0(p, a1, 1, a2);
}
