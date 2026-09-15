/* Main-exec range [80036FB0,80037004) from the SLUS executable.
 * SHA256(span)=9f0ac1fa75fe1f713fb010f1ea046a09060bec5ba909c9e75ae9867d4732329e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEE8;
extern s32 *D_80078F10;

void func_80036FB0(s32 arg0, s32 arg1) {
    s32 *var_v1;
    s32 var_a2;

    var_a2 = 0;
    if (D_8006AEE8 > 0) {
        var_v1 = &D_80078F10;
        do {
            if (*var_v1 == arg0) {
                *var_v1 = arg1;
            }
            var_a2 += 1;
            var_v1 += 4;
        } while (var_a2 < D_8006AEE8);
    }
}
