/* Main-exec range [800112C8,80011320) from the SLUS executable.
 * SHA256(span)=ee4f0d655a0771f83889b33ebbf30b4a10343a454b7c30367e6c86c77ebc2440.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80072C70;
void func_80011778();                                  /* static */
s32 func_80019A24(void *, s32, s32, s32);                  /* static */
extern s32 *D_800AE870;

void func_800112C8(void) {
    if (func_80019A24(&D_800AE870, D_80072C70, 0, 0) != 0) {
        func_80011778();
    }
}
