/* Overlay range [8016F1C4,8016F250) from MAIN.CD member 0012.
 * SHA256(span)=ab815254984cefdd2f02ba20632d2ebc514987359243a5b8c8845f7bed83d7f3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018175C;
extern s16 D_800B9A08;
extern s32 *D_80126B58;

s32 func_8016F1C4(void) {
    s32 *var_v0;
    s32 var_v1;

    var_v1 = D_8018175C;
    var_v0 = D_8018175C + 4;
    if (var_v1 != 0) {
loop_2:
        if (D_800B9A08 != var_v1) {
            var_v1 = *var_v0;
            var_v0 += 4;
            if (var_v1 == 0) {
                goto block_4;
            }
            goto loop_2;
        }
        return 1;
    }
block_4:
    if ((M2C_FIELD(&D_80126B58, s32 *, 0x1F8) & 0x80FFFFFF) && (M2C_FIELD(&D_80126B58, s32 *, 0x1F8) & 0x10000000)) {
        return 0;
    }
    return M2C_FIELD(&D_80126B58, s32 *, 0x1F8) & 0x80FFFFFF;
}
