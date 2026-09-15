/* Overlay range [80149DD8,80149E94) from MAIN.CD member 0012.
 * SHA256(span)=e13625fbcb45d73e7bb2e8985d196b4ec144a3b241395b3ae731e7344ed0f04f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80149F2C(void *, u32);                     /* static */
extern s32 *D_801202A0;

s32 func_80149DD8(void *arg0) {
    void *var_s0;
    void *temp_v1;

    if ((M2C_FIELD(arg0, s32 *, 0x178) == 0) && !(M2C_FIELD(arg0, s32 *, 0x44) & 0x404)) {
        if (!(M2C_FIELD(arg0, u16 *, 0xAC) & 0x80)) {
            return 0;
        }
        var_s0 = &D_801202A0;
        temp_v1 = &D_801202A0 + 0x6480;
        M2C_FIELD(arg0, s32 *, 0x190) = 0;
        if ((u32) &D_801202A0 < (u32) temp_v1) {
loop_7:
            var_s0 += 0x10C;
            if (func_80149F2C(arg0, (u32) var_s0) == 0) {
                if ((u32) var_s0 >= (u32) temp_v1) {
                    goto block_9;
                }
                goto loop_7;
            }
            return 1;
        }
block_9:
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
