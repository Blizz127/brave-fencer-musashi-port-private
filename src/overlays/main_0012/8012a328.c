/* Overlay range [8012A328,8012A418) from MAIN.CD member 0012.
 * SHA256(span)=f2b6d56a500b4a422709470398fcb81a3f0b056297a4ff6cb8895ef507021207.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012F74(s16, s16, s32, s32);      /* extern */
extern u8 D_801152C0;
extern s16 D_801152C2;
extern u16 D_80126940;
extern s16 D_80126942;
extern u16 D_80126944;
extern s32 *D_80126B58;
extern s16 D_80126CAE;
extern s16 D_80127080;

void func_8012A328(void) {
    s16 var_a1;
    s32 temp_v1;

    if (D_801152C0 != 0) {
        temp_v1 = D_80127080 - D_80126CAE;
        if (temp_v1 >= 0) {
            if (D_801152C2 < temp_v1) {
                goto block_5;
            }
            goto block_6;
        }
        if (D_801152C2 < (D_80126CAE - D_80127080)) {
block_5:
            var_a1 = M2C_FIELD(&D_80126B58, s16 *, 0x156);
        } else {
block_6:
            var_a1 = D_80127080;
        }
    } else {
        var_a1 = D_80126CAE;
    }
    D_80126942 = func_80012F74(D_80126942, var_a1, 4, 1);
    D_80126940 = M2C_FIELD(&D_80126B58, u16 *, 0x154);
    D_80126944 = M2C_FIELD(&D_80126B58, u16 *, 0x158);
}
