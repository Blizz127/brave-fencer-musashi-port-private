/* Main-exec range [80018450,800184F0) from the SLUS executable.
 * SHA256(span)=ea5e2dab68bfb101f9f7b8c3e1ba2e30a01cad837550a7f4e27ae675fd25b874.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

s32 func_80018450(void *arg0, s32 arg1) {
    void *var_v1;
    s32 var_a2;
    s32 var_a3;

    var_a3 = 0;
    var_a2 = 0;
    var_v1 = &D_800AF630;
loop_1:
    if (M2C_FIELD(var_v1, s16 *, 0xA1A8) == 0) {
        M2C_FIELD(var_v1, s16 *, 0xA1A8) = 1;
        M2C_FIELD(var_v1, s32 *, 0xA1AC) = arg1;
        M2C_FIELD(var_v1, s8 *, 0xA1B5) = 0;
        M2C_FIELD(var_v1, u16 *, 0xA1B0) = (u16) M2C_FIELD(arg0, u16 *, 0x28);
        M2C_FIELD(var_v1, u16 *, 0xA1B2) = (u16) M2C_FIELD(arg0, u16 *, 0x2A);
        M2C_FIELD(var_v1, u8 *, 0xA1B4) = (u8) M2C_FIELD(arg0, u8 *, 0x27);
        var_a3 = 1;
    } else {
        var_a2 += 1;
        var_v1 += 0x10;
        if (var_a2 < 0x20) {
            goto loop_1;
        }
    }
    return var_a3;
}
