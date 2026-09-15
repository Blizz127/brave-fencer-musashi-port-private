/* Overlay range [80146924,80146994) from MAIN.CD member 0012.
 * SHA256(span)=630377113f611dff15c5a153e78e8932795531eaf951a27197fe9b678ffa718f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80146994(s32);                             /* static */
extern u16 D_8011D030;

s32 func_80146924(s32 arg0, u32 arg4) {
    s32 var_v0;
    u16 *temp_t2;
    u16 *var_v1;
    u32 var_t0;

    var_t0 = 0;
    var_v1 = &D_8011D030;
    temp_t2 = &D_8011D030 + 0xA50;
    if ((u32) &D_8011D030 < (u32) temp_t2) {
        do {
            if (*var_v1 == (arg0 & 0xFFFF)) {
                var_t0 += 1;
            }
            var_v1 += 0x58;
        } while ((u32) var_v1 < (u32) temp_t2);
    }
    var_v0 = 0;
    if (var_t0 < arg4) {
        var_v0 = func_80146994(arg0 & 0xFFFF);
    }
    return var_v0;
}
