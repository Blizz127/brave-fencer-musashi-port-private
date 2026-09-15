/* Main-exec range [8001544C,80015498) from the SLUS executable.
 * SHA256(span)=e8771b3bc7695c76e57cb1aada32825b4a9fbfee917b949db5e7cb258023a312.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s16 D_800B93D8;
extern s32 *D_800B97D8;

s16 *func_8001544C(void) {
    s16 *var_v0;
    s16 *var_v1;

    var_v1 = &D_800B93D8;
    if ((u32) &D_800B93D8 < (u32) &D_800B97D8) {
loop_1:
        var_v0 = var_v1;
        if (*var_v1 != 0) {
            var_v1 += 0x10;
            if ((u32) var_v1 >= (u32) &D_800B97D8) {
                goto block_3;
            }
            goto loop_1;
        }
    } else {
block_3:
        var_v0 = 0;
    }
    return var_v0;
}
