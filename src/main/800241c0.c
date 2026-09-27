/* Main-exec range [800241C0,800242D0) from the SLUS executable.
 * SHA256(span)=a67732548c1586a9aa642082f6af8f6eb84157fc3b9c4303e35f4602af762372.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800636D8;
extern s32 D_80063818;
extern s32 D_80063870;

void func_800241C0(s16 arg0, u16 *arg1, s32 arg2) {
    s16 temp_a0;
    s16 var_t1;
    s32 temp_a2;
    s32 temp_lo;
    s32 var_a3;
    s32 var_t0;
    s32 var_v0;
    u16 *var_a1;

    var_a1 = arg1;
    var_t1 = arg0;
    temp_a2 = arg2 - 1;
    var_a3 = temp_a2;
    var_t0 = 0;
    if (!(temp_a2 & 0x8000)) {
        do {
            if ((var_a3 << 0x10) != 0) {
                *var_a1 = D_80063818;
            } else {
                *var_a1 = D_800636D8;
            }
            temp_a0 = *(((s32) (var_a3 << 0x10) >> 0xF) + D_80063870);
            temp_lo = var_t1 / temp_a0;
            if ((s16) temp_lo != 0) {
                var_t0 += 1;
                *var_a1 = *(((s16) temp_lo * 2) + D_800636D8);
                var_t1 %= temp_a0;
                goto block_9;
            }
            var_v0 = var_a3 - 1;
            if (var_t0 != 0) {
                *var_a1 = D_800636D8;
block_9:
                var_v0 = var_a3 - 1;
            }
            var_a3 = var_v0;
            var_a1 += 2;
        } while (!(var_v0 & 0x8000));
    }
    *var_a1 = -1U;
}
