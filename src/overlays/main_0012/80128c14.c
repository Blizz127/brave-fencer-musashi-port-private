/* Overlay range [80128C14,80128C98) from MAIN.CD member 0012.
 * SHA256(span)=6f02e31fe8bb0f8493d19d5a91c5a5ec7d00e8a3d0254c8ad4e63c82ec7ba66c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80010AE0();                                 /* extern */
extern s16 D_800B9A08;

void func_80128C14(void) {
    s32 var_a0;
    if (D_800B9A08 != 0x3081) {
        if (D_800B9A08 < 0x3082) {
            if (D_800B9A08 != 0x3023) {
                var_a0 = 0x480;
                if (D_800B9A08 != 0x3067) {
                    var_a0 = 0x3E0;
                }
            } else {
                var_a0 = 0x4E0;
            }
        } else if (D_800B9A08 != 0x3093) {
            var_a0 = 0xFFB;
            if (D_800B9A08 != 0x30A5) {
                var_a0 = 0x3E0;
            }
        } else {
            var_a0 = 0xFFB;
        }
    } else {
        var_a0 = 0x420;
    }
    func_80010AE0(var_a0);
}
