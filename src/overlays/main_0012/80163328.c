/* Overlay range [80163328,801633A8) from MAIN.CD member 0012.
 * SHA256(span)=2f7f30733400879be4c0933bd8d062320c830c9bbb39deb88de7b52f3c21f66d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern void *D_80115100;
extern s32 *D_80115200;

void func_80163328(void) {
    s32 *var_t0;
    u32 var_t2;
    void **var_a3;
    void *temp_v0;

    var_t2 = 0;
    var_a3 = &D_80115100;
    var_t0 = &D_80115200;
    do {
        if (*var_t0 & 1) {
            temp_v0 = *var_a3;
            temp_v0->unk7F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            temp_v0->unk83 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            (*var_a3)->unk82 = 0;
        }
        var_a3 += 4;
        var_t2 += 1;
        var_t0 += 4;
    } while (var_t2 < 3U);
}
