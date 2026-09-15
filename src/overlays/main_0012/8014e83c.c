/* Overlay range [8014E83C,8014E934) from MAIN.CD member 0012.
 * SHA256(span)=d18515b0629d26caedba23bf18627bd2549268e7ae183a287091db4a53b954fd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135888(s32, s32, s32, s32);      /* static */
extern u16 D_801202A0;

s32 func_8014E83C(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    u16 *temp_v1;
    u16 *var_s0;
    u16 *var_s1;

    var_s1 = &D_801202A0;
    temp_v1 = &D_801202A0 + 0x6480;
    if ((u32) &D_801202A0 < (u32) temp_v1) {
        var_s0 = &D_801202A0 + 0xE;
loop_2:
        if ((*var_s1 != 0) && (M2C_FIELD(var_s0, u16 *, 0x4E) & 0x20)) {
            temp_a1 = M2C_FIELD(var_s0, s32 *, 0x4A);
            if ((temp_a1 != 0) && (func_80135888(M2C_FIELD(var_s0, s32 *, 0x12), temp_a1, arg1, arg2) != 0)) {
                M2C_FIELD(arg0, u16 **, 0x180) = var_s1;
                M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(var_s0, u16 *, -8);
                M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(var_s0, u16 *, -4);
                M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(var_s0, u16 *, 0);
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
