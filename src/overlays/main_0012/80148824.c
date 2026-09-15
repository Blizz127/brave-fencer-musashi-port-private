/* Overlay range [80148824,801488A8) from MAIN.CD member 0012.
 * SHA256(span)=0191bf98db38650cf3a148bccf2d1274051a2fb2d62398ea07cf56d43646b58a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047D3C(s32, s32);                        /* extern */

s32 func_80148824(void *arg0) {
    s32 temp_lo;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0xAE);
    temp_v1 = (temp_v0 >> 8) - 0x80;
    temp_v0_2 = (temp_v0 & 0xFF) - 0x80;
    if (temp_v1 == 0) {
        var_v0 = temp_v0_2 & 0xFF;
        if (temp_v0_2 < 0) {
            var_v0_2 = -temp_v0_2;
            goto block_7;
        }
    } else if (temp_v0_2 == 0) {
        var_v0 = temp_v1 & 0xFF;
        if (temp_v1 < 0) {
            var_v0_2 = -temp_v1;
            goto block_7;
        }
    } else {
        temp_lo = temp_v0_2 * temp_v0_2;
        var_v0_2 = func_80047D3C((temp_v1 * temp_v1) + temp_lo, temp_lo);
block_7:
        var_v0 = var_v0_2 & 0xFF;
    }
    return var_v0;
}
