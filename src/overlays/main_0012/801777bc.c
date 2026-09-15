/* Overlay range [801777BC,801778A8) from MAIN.CD member 0012.
 * SHA256(span)=0fa2e36925478fcd70f5a30475877df57f8ce80e1ec1511e0fccc63a80380e4e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 *func_801777BC(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    s16 temp_v0;
    s16 var_t3;
    s32 *var_t1;
    s32 var_a1;
    s32 var_a2;
    s32 var_t4;
    u32 temp_v0_2;
    void *var_t0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_t1 = arg0;
    var_t4 = 0x01000000;
    var_t3 = 0;
    if (arg4 > 0) {
        var_t0 = arg0 + 0xC;
        do {
            temp_v0_2 = (u32) (var_a1 << 0x10) >> 0x1C;
            if ((temp_v0_2 != 0) || (var_t3 == (arg4 - 1)) || (var_t3 == (s16) arg6)) {
                var_t4 = 0;
            }
            *var_t1 = ((var_t1 - 0x14) & 0xFFFFFF) | 0x03000000;
            var_t0->unk-4 = (s32) ((arg3 << 0x10) | (var_a2 & 0xFFFF) | var_t4);
            var_t0->unk-8 = 0x74808080;
            var_t0->unk0 = (s32) (((((arg5 + 0x100) << 6) | 0x16) << 0x10) | (((temp_v0_2 * 8) + 8) | 0x4000));
            var_t0 += 0x14;
            var_t1 += 0x14;
            var_a2 += 8;
            temp_v0 = var_t3 + 1;
            var_t3 = temp_v0;
            var_a1 *= 0x10;
        } while (temp_v0 < arg4);
    }
    return var_t1;
}
