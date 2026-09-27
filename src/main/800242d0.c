/* Main-exec range [800242D0,800243EC) from the SLUS executable.
 * SHA256(span)=dbaf9f93feba204363bde06ff94a2aba533095cd11c14519dbc0968ac03d9e83.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80063858;
extern s32 D_8006386C;
extern s32 D_80063870;

void func_800242D0(s32 arg0, u16 *arg1, s32 arg2) {
    s16 temp_a0;
    s16 temp_v0;
    s16 var_t0_2;
    s16 var_v0;
    s32 temp_a2;
    s32 temp_lo;
    s32 var_t0;
    s32 var_t1;
    s32 var_v1;
    u16 *var_a1;

    var_a1 = arg1;
    var_t0 = arg2 & 0xFFAF;
    temp_a2 = arg2 & 0x80;
    var_t1 = arg0;
    if (temp_a2 != 0) {
        var_t0 = 4;
    }
    temp_v0 = var_t0 - 1;
    var_t0_2 = temp_v0;
    if (!(temp_v0 & 0x8000)) {
        var_v1 = var_t1 << 0x10;
        do {
            temp_a0 = *(((s32) (var_t0_2 << 0x10) >> 0xF) + D_80063870);
            temp_lo = (s32) (var_v1 >> 0x10) / temp_a0;
            if ((s16) temp_lo != 0) {
                *var_a1 = *(((s16) temp_lo * 2) + D_80063858);
                var_t1 -= temp_lo * temp_a0;
            } else {
                *var_a1 = D_80063858;
            }
            var_a1 += 2;
            if (temp_a2 != 0) {
                var_v0 = var_t0_2 - 1;
                if (var_t0_2 == 2) {
                    *var_a1 = D_8006386C;
                    var_a1 += 2;
                    goto block_10;
                }
            } else {
block_10:
                var_v0 = var_t0_2 - 1;
            }
            var_t0_2 = var_v0;
            var_v1 = var_t1 << 0x10;
        } while (!(var_v0 & 0x8000));
    }
    *var_a1 = -1U;
}
