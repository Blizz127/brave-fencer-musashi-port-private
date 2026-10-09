/* Main-exec range [80027BF0,80027C10) from the SLUS executable.
 * SHA256(span)=5d7c0966ff3ab6b18cd31fd9034fcbab417216ff41490832782c32be19df96dd.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80027C10(s32 a0, s32 a1, s32 a2);            /* static */

/* Retail forwards a0-a2 untouched (jal with no argument setup); the only
 * caller (8001FC08) passes three. */
void func_80027BF0(s32 a0, s32 a1, s32 a2) {
    func_80027C10(a0, a1, a2);
}
