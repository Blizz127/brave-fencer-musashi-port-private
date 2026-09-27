/* Main-exec range [80059F88,80059FC0) from the SLUS executable.
 * SHA256(span)=a1cdb61cc37c078714aa969cfa91de15e1bb8a287a8e8780129f5d6a9380619b.
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
void func_8005C324();
extern s32 D_80072798;
void *func_80059F88(void *p) {
    func_8005C324(p, &D_80072798, 0x5C);
    return p;
}
