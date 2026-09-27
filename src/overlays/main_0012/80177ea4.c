/* Overlay range [80177EA4,80177F84) from MAIN.CD member 0012.
 * SHA256(span)=d7fb449042e542cb0ac033500bef4b588ad7bbf0fc460385ea10330ca863d134.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 *func_80177EA4(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_v0;
    s16 var_t2;
    s32 *var_t1;
    s32 temp_a3;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_t3;
    s32 var_v0;
    void *var_t0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_t1 = arg0;
    var_t3 = 0x01000000;
    var_t2 = 0;
    temp_a3 = arg3 << 0x10;
    var_t0 = var_t1 + 0xC;
    do {
        *var_t1 = ((var_t1 - 0x14) & 0xFFFFFF) | 0x03000000;
        var_t0->unk-8 = 0x74808080;
        if (var_t2 != 0) {
            if (var_t2 == 6) {
                var_a0 = 1;
                var_t3 = 0;
            } else {
                var_a0 = ((var_a1 >> 0x10) & 0xF) + 1;
                var_a1 *= 0x10;
            }
            if (var_a0 != 1) {
                var_t3 = 0;
            }
            var_v0 = temp_a3 | (var_a2 & 0xFFFF) | var_t3;
        } else {
            var_a0 = 0;
            var_v0 = temp_a3 | (var_a2 & 0xFFFF);
        }
        var_t0->unk-4 = var_v0;
        var_t0->unk0 = (s32) ((var_a0 * 8) | 0x6B564000);
        var_t0 += 0x14;
        var_t1 += 0x14;
        temp_v0 = var_t2 + 1;
        var_t2 = temp_v0;
        var_a2 += 8;
    } while (temp_v0 < 7);
    return var_t1;
}
