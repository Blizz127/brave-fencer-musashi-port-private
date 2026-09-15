/* Overlay range [80149E94,80149F2C) from MAIN.CD member 0012.
 * SHA256(span)=d330357cc69b701bc3176ce7308884c80b10aaaedeae83f6a8d450c55aeaf2eb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80149F2C(void *, u32);                     /* static */
s32 func_8016F1AC();                                /* static */
extern s32 *D_801202A0;

s32 func_80149E94(void *arg0) {
    void *var_s0;
    void *temp_v1;

    if ((func_8016F1AC() == 0) && (M2C_FIELD(arg0, u8 *, 0x1C5) != 0)) {
        var_s0 = &D_801202A0;
        temp_v1 = &D_801202A0 + 0x6480;
        M2C_FIELD(arg0, u8 *, 0x1C5) = 0U;
        if ((u32) &D_801202A0 < (u32) temp_v1) {
loop_4:
            var_s0 += 0x10C;
            if (func_80149F2C(arg0, (u32) var_s0) != 0) {
                return 1;
            }
            if ((u32) var_s0 >= (u32) temp_v1) {
                goto block_7;
            }
            goto loop_4;
        }
block_7:
        /* Duplicate return node #8. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
