/* Main-exec range [80041448,800414E4) from the SLUS executable.
 * SHA256(span)=9922420ca2929de3529aa1dbf318748aea600297c77e305987079796876414f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80040868();                                 /* static */
extern s32 *D_80079596;
extern u8 D_800AE614;
extern s16 D_800B9B3A;

void func_80041448(s16 arg0) {
    s32 var_s0;
    s32 var_v0;

    var_s0 = 0;
    if (D_800AE614 != 0) {
        var_v0 = 0 & 0xFF;
        do {
            if (*(&D_80079596 + (var_v0 * 0x34)) == arg0) {
                D_800B9B3A = var_s0 & 0xFF;
                func_80040868(0);
            }
            var_s0 += 1;
            var_v0 = var_s0 & 0xFF;
        } while ((u32) (var_s0 & 0xFF) < (u8) D_800AE614);
    }
}
