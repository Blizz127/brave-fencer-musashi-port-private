/* Overlay range [80159464,801594E8) from MAIN.CD member 0012.
 * SHA256(span)=ac5778006c2faf45085b218661db535c6244eff0d158856fc6fa6f6e246f66a4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029A94(s32, s16);                          /* extern */
extern s32 D_80180758;
extern s16 D_800B9A08;

s16 func_80159464(s16 arg1) {
    s32 (*var_a0)();
    s16 var_a1;
    s16 var_v0;
    s32 var_v0_2;

    var_a1 = arg1;
    var_a0 = D_80180758;
    var_v0_2 = (u16) D_80180758 << 0x10;
    if (D_80180758 != 0) {
        var_a1 = D_800B9A08;
loop_2:
        if (var_a1 != (var_v0_2 >> 0x10)) {
            var_a0 += 4;
            var_v0_2 = (u16) *var_a0 << 0x10;
            if (*var_a0 == 0) {
                goto block_4;
            }
            goto loop_2;
        }
        var_v0 = var_a0->unk2;
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return var_v0;
    }
block_4:
    var_v0 = 0;
    if (func_80029A94(1, var_a1) == 0) {
        var_v0 = 0;
        if (func_80029A94(0) == 0) {
            return -1;
        }
    }
    return var_v0;
}
