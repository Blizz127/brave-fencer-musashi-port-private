/* Overlay range [8017CEB8,8017CF3C) from MAIN.CD member 0012.
 * SHA256(span)=5db86f8dbba23722320af2967b4803f7f4c86e91f2e3ae7fa7c0361ba93361b8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80115158;

s32 func_8017CEB8(s32 arg0, s16 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    s32 temp_v1;
    s32 var_t0;
    s32 var_v0;

    *arg4 = 0x808080;
    var_t0 = 0;
    if (arg1 < 5) {
        if (arg1 <= 0) {
            if (arg1 != 0) {
                var_v0 = arg3 << 0x10;
                goto block_6;
            }
        } else {
            goto block_5;
        }
    } else if (arg1 != 5) {
block_5:
        var_v0 = arg3 << 0x10;
block_6:
        temp_v1 = var_v0 >> 0x10;
        if (temp_v1 < (s32) *(&D_80115158 + ((s32) (arg2 << 0x10) >> 0xF))) {
            var_t0 = *((temp_v1 * 4) + arg0);
        }
    }
    return var_t0;
}
