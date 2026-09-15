/* Overlay range [8015AB7C,8015ABD4) from MAIN.CD member 0012.
 * SHA256(span)=3bc84c7b269a48e95fbb703a2c4d8dec3454c02b34cf02ce0a03a390b37d1790.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800D48DC;

u8 func_8015AB7C(void *arg0) {
    u8 temp_v1;
    u8 var_v0;

    if (M2C_FIELD(arg0, s32 *, 0xB4) == &D_800D48DC) {
        temp_v1 = M2C_FIELD(arg0, u8 *, 0xDC);
        var_v0 = 0x10;
        if (temp_v1 >= 6U) {
            if (temp_v1 < 0xBU) {
                return 0x12U;
            }
            var_v0 = 9;
            if (temp_v1 < 0x10U) {
                return 7U;
            }
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return var_v0;
        }
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = M2C_FIELD(arg0, u8 *, 0xBC);
    return var_v0;
}
