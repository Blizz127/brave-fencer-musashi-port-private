/* Overlay range [801469C8,80146A6C) from MAIN.CD member 0012.
 * SHA256(span)=c4836c177105a5204f60f31530f958e3537ff43bd3878b6156afe0abc41c4601.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80146A6C(s32, s16, s16, s32, s32, s32);    /* static */
extern u16 D_8011D030;

s32 func_801469C8(s32 arg0, s16 arg2, s16 arg3, u16 arg4, s32 arg5, s32 arg6, u32 arg7) {
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
    if (var_t0 >= arg7) {
        return 0;
    }
    return func_80146A6C(arg0 & 0xFFFF, arg2, arg3, (s32) (s16) arg4, arg5, arg6);
}
