/* Overlay range [80150528,801505FC) from MAIN.CD member 0012.
 * SHA256(span)=ffcbf60abcad76d2e4ebb27f87f29a0b19b4b9f423f59193f08b58c72cee67a3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135A4C(s32, s32, s32, s32);      /* static */
extern u16 D_801202A0;

s32 func_80150528(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    u16 *temp_v1;
    u16 *var_s0;
    u16 *var_s1;

    var_s1 = &D_801202A0;
    temp_v1 = &D_801202A0 + 0x6480;
    if ((u32) &D_801202A0 < (u32) temp_v1) {
        var_s0 = &D_801202A0 + 0x20;
loop_2:
        if ((*var_s1 != 0) && (M2C_FIELD(var_s0, u16 *, 0x3C) & 0x80)) {
            temp_a1 = M2C_FIELD(var_s0, s32 *, 0x38);
            if ((temp_a1 != 0) && (func_80135A4C(M2C_FIELD(var_s0, s32 *, 0), temp_a1, arg1, arg2) != 0)) {
                M2C_FIELD(arg0, u16 **, 0x1A4) = var_s1;
                return 1;
            }
        }
        var_s1 += 0x10C;
        var_s0 += 0x10C;
        if ((u32) var_s1 >= (u32) temp_v1) {
            goto block_8;
        }
        goto loop_2;
    }
block_8:
    return 0;
}
