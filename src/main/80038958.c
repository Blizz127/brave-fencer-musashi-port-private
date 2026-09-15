/* Main-exec range [80038958,80038A00) from the SLUS executable.
 * SHA256(span)=9e6c3e4acab007ee005c23f68820d682fee0bb2e6a2236bc95d2ce6fa5a9050f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 *D_800762B0;
extern u8 D_800762B4;
extern s32 *D_800C6E2A;

void func_80038958(void) {
    void *var_a0;
    s32 var_a1;
    u8 *var_a2;
    u8 *var_a3;
    u8 temp_v0;

    var_a3 = D_800762B0;
    var_a2 = &D_800762B4;
    var_a1 = 0;
    var_a0 = &D_800C6E2A;
    do {
        temp_v0 = *var_a3;
        if (((temp_v0 == 0) || (temp_v0 == 3)) && (*var_a2 == 0)) {
            M2C_FIELD(var_a0, s8 *, 1) = 0;
            if (M2C_FIELD(var_a0, u8 *, 0) != 0) {
                M2C_FIELD((M2C_FIELD(var_a0, s32 *, -0xA) + (M2C_FIELD(var_a0, s16 *, -0x54) * 0x1A) + var_a1), s8 *, 0x23) = 0;
                M2C_FIELD(var_a0, u8 *, 0) = 0U;
            }
        }
        var_a1 += 1;
        var_a0 += 0x60;
        var_a3 += 1;
        var_a2 += 1;
    } while (var_a1 < 0x10);
}
