/* Main-exec range [800391D4,80039300) from the SLUS executable.
 * SHA256(span)=9e6eecc7e97ebe88b9f07da51a1dc2762c5c2496d31911efa7d4e4c105af2af9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073140[];
extern s32 D_800762B0[];
extern s32 *D_800762B4;
extern s32 D_800A2B98;
extern s32 *D_800C6DD0;
extern s32 *D_800C6DD4;
extern s32 D_800C7D20;

void func_800391D4(s32 arg0, s16 arg1, s16 arg2) {
    s16 var_a3;
    s32 temp_a0_2;
    s32 var_t0;
    s32 var_v0;
    void *temp_a0;

    var_a3 = 0;
    var_t0 = 0;
    do {
        if ((M2C_FIELD((arg0 + (arg2 * 0x1A) + var_a3), u8 *, 0x23) != 0) && (*(&D_800C6DD4 + var_t0) == arg1)) {
            temp_a0 = (var_a3 * 0x60) + &D_800C6DD0;
            var_v0 = var_a3 * 4;
            if (M2C_FIELD(temp_a0, u8 *, 0x5A) != 0) {
                M2C_FIELD((M2C_FIELD(temp_a0, s32 *, 0x50) + (M2C_FIELD(temp_a0, s16 *, 6) * 0x1A) + var_a3), s8 *, 0x23) = 0;
                M2C_FIELD(temp_a0, u8 *, 0x5A) = 0U;
                var_v0 = var_a3 * 4;
            }
            temp_a0_2 = *(D_80073140 + var_v0);
            D_800C7D20 &= ~temp_a0_2;
            D_800A2B98 |= temp_a0_2;
            *(D_800762B0 + var_a3) = 2;
            *(&D_800762B4 + var_a3) = 0;
        }
        var_a3 += 1;
        var_t0 += 0x60;
    } while (var_a3 < 0x10);
}
