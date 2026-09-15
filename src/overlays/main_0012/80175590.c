/* Overlay range [80175590,80175624) from MAIN.CD member 0012.
 * SHA256(span)=895672119a341e9208ae72b866491331b5f6c9113feb1a06359e96b4176be4b9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801757A0(s16);                         /* static */
extern s16 D_800B9A02;

void func_80175590(void *arg0) {
    s16 temp_v1;
    u8 temp_a0;
    u8 temp_v0;
    u8 temp_v0_2;

    temp_a0 = M2C_FIELD(arg0, u8 *, 5);
    temp_v0 = M2C_FIELD(arg0, u8 *, 6) - temp_a0;
    temp_v1 = -(temp_v0 & 0xFF);
    M2C_FIELD(arg0, u8 *, 6) = temp_v0;
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg0, u8 *, 5) = (u8) (temp_a0 + 0xFF);
    M2C_FIELD(arg0, s16 *, 0x10) = temp_v1;
    M2C_FIELD(arg0, s16 *, 0xC) = temp_v1;
    M2C_FIELD(arg0, s16 *, 0x16) = (s16) temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0x14) = (s16) temp_v0_2;
    func_801757A0(D_800B9A02);
    if (M2C_FIELD(arg0, u8 *, 5) == 0) {
        M2C_FIELD(arg0, s8 *, 8) = 0;
        M2C_FIELD(arg0, u8 *, 1) = (u8) (M2C_FIELD(arg0, u8 *, 1) + 1);
    }
}
