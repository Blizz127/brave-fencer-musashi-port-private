/* Overlay range [8016E95C,8016E9EC) from MAIN.CD member 0012.
 * SHA256(span)=8068f8b9b0b9a4d94620711713dcc8230346992e8a5a7e0f422dd4dabf9ea8b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018174C;
extern s32 *D_80115218;

void func_8016E95C(void) {
    void *var_s0;
    void *temp_v1;

    var_s0 = &D_80115218;
    temp_v1 = &D_80115218 + 0x80;
    if ((u32) &D_80115218 < (u32) temp_v1) {
        do {
            if (var_s0->unk0 != 0) {
                *((var_s0->unk1 * 4) + D_8018174C)(var_s0);
            }
            var_s0 += 0x20;
        } while ((u32) var_s0 < (u32) temp_v1);
    }
}
