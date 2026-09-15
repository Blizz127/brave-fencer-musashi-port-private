/* Overlay range [801416D4,80141788) from MAIN.CD member 0012.
 * SHA256(span)=28cbd8a32d2ba355ac7d6718bef12b2e82b6571ef0f23dc08b6a3683b82c36ea.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800D11F0(s32, s32, s32, s32);                /* extern */
s32 func_800D1658(s32, s32, s32, s32);                /* extern */
void func_80141C0C(s32, s32, s32, s32);                    /* static */
extern u8 D_8011514C;
extern u8 D_8011514D;
extern u8 D_8011515C;

s32 func_801416D4(s16 arg0) {
    s32 temp_a1;
    s32 temp_lo;
    s32 var_v0;
    s32 var_v1;

    temp_lo = D_8011514D * D_8011515C;
    temp_a1 = D_8011514C + temp_lo;
    if (arg0 != 1) {
        if (arg0 < 2) {
            if (arg0 != 0) {
                var_v0 = 0 << 0x10;
            } else {
                var_v1 = func_800D11F0(temp_a1 & 0xFF, temp_a1, 2, temp_lo);
                goto block_9;
            }
        } else if (arg0 != 2) {
            var_v0 = 0 << 0x10;
        } else {
            func_80141C0C(6, temp_a1, 2, temp_lo);
            var_v1 = 1;
            goto block_9;
        }
    } else {
        var_v1 = func_800D1658(temp_a1 & 0xFF, temp_a1, 2, temp_lo);
block_9:
        var_v0 = var_v1 << 0x10;
    }
    return var_v0 >> 0x10;
}
