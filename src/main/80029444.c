/* Main-exec range [80029444,80029504) from the SLUS executable.
 * SHA256(span)=d87446017e116b46ea20dbbde71435298790b685750b7db408222e40b5d3f0e8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80078E7C;

void func_80029444(void) {
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;

    temp_v0 = M2C_FIELD(&D_80078E7C, u8 *, 0) + 1;
    M2C_FIELD(&D_80078E7C, u8 *, 0) = temp_v0;
    if ((u32) (temp_v0 & 0xFF) >= 0x1EU) {
        M2C_FIELD(&D_80078E7C, u8 *, 0) = 0U;
        temp_v0_2 = M2C_FIELD(&D_80078E7C, u8 *, 1) + 1;
        M2C_FIELD(&D_80078E7C, u8 *, 1) = temp_v0_2;
        if ((u32) (temp_v0_2 & 0xFF) >= 0x3CU) {
            M2C_FIELD(&D_80078E7C, u8 *, 1) = 0U;
            temp_v0_3 = M2C_FIELD(&D_80078E7C, u8 *, 2) + 1;
            M2C_FIELD(&D_80078E7C, u8 *, 2) = temp_v0_3;
            if ((u32) (temp_v0_3 & 0xFF) >= 0x3CU) {
                M2C_FIELD(&D_80078E7C, u8 *, 2) = 0U;
                temp_v0_4 = M2C_FIELD(&D_80078E7C, u8 *, 3) + 1;
                M2C_FIELD(&D_80078E7C, u8 *, 3) = temp_v0_4;
                if ((u32) (temp_v0_4 & 0xFF) >= 0x64U) {
                    M2C_FIELD(&D_80078E7C, u8 *, 0) = 0x633B3B00;
                }
            }
        }
    }
}
