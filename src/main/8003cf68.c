/* Main-exec range [8003CF68,8003CFF8) from the SLUS executable.
 * SHA256(span)=a5ee5da0f80f5cf64408b981436a6907dd58464eea7346a124ad29914483de5f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u32 func_8003CF68(s32 arg0, u32 arg1) {
    s32 sp8;
    s32 var_a2;
    s32 var_lo;
    s32 var_t0;
    u32 temp_a3;
    u32 var_v1;

    var_v1 = 0x103B;
    var_t0 = arg0 << 0xC;
    var_a2 = 0;
    temp_a3 = arg1 >> 5;
    sp8 = arg0 * 0x103B;
    if (temp_a3 != 0) {
        var_lo = arg0 * 0x103B;
        do {
            var_t0 = var_lo;
            var_v1 = (u32) (var_v1 * 0x103B) >> 0xC;
            var_lo = arg0 * var_v1;
            var_a2 += 1;
            sp8 = var_lo;
        } while (var_a2 < (s32) temp_a3);
    }
    return (u32) (var_t0 + (((u32) (sp8 - var_t0) >> 5) * (arg1 & 0x1F))) >> 0xC;
}
