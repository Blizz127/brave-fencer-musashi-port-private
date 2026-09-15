/* Main-exec range [8003D98C,8003D9CC) from the SLUS executable.
 * SHA256(span)=b5b8ccf5614b2e72cf30d84333b80242a118698042ac9d6c2db4c6ca201eda0c.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8006B8F0;
extern CB D_8006B8EC;
void func_8003D98C(void) {
    if (D_8006B8F0)
        D_8006B8F0();
    D_8006B8EC();
}
