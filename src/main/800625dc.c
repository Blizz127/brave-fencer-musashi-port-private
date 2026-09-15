/* Main-exec range [800625DC,80062644) from the SLUS executable.
 * SHA256(span)=3c95915e73024968e96edc12cded07cc429a4eca2e5124e6b5abe4afb06e7fa8.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072A28;

s32 func_800625DC(void) {
    s32 sp0;
    s32 temp_v0;

    M2C_FIELD(D_80072A28, s16 *, 0xA) = 0;
    sp0 = 0xA;
    sp0 = 9;
    if (sp0 != -1) {
        do {
            temp_v0 = sp0 - 1;
            sp0 = temp_v0;
        } while (temp_v0 != -1);
    }
    return 0;
}
