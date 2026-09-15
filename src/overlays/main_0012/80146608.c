/* Overlay range [80146608,801466B4) from MAIN.CD member 0012.
 * SHA256(span)=d2d0ffd32e6251c88c592f54927eba47e8d7777990fdb5231b6a4bab7f61e122.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801466F0(s32, s16, s16, s32, s32, s32, s32); /* static */
extern u16 D_8011F9D0;

s32 func_80146608(s32 arg0, s16 arg2, s16 arg3, u16 arg4, s32 arg5, s32 arg6, u32 arg7, s32 arg8) {
    u16 *temp_t2;
    u16 *var_v1;
    u32 var_t0;

    var_t0 = 0;
    var_v1 = &D_8011F9D0;
    temp_t2 = &D_8011F9D0 + 0x820;
    if ((u32) &D_8011F9D0 < (u32) temp_t2) {
        do {
            if (*var_v1 == (arg0 & 0xFFFF)) {
                var_t0 += 1;
            }
            var_v1 += 0x68;
        } while ((u32) var_v1 < (u32) temp_t2);
    }
    if (var_t0 >= arg7) {
        return 0;
    }
    return func_801466F0(arg0 & 0xFFFF, arg2, arg3, (s32) (s16) arg4, arg5, arg6, arg8);
}
