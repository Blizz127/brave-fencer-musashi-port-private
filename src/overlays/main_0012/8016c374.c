/* Overlay range [8016C374,8016C49C) from MAIN.CD member 0012.
 * SHA256(span)=47d5df870e93bcd4f78333cc1cecde9e2bf6224ca2a1922de966c1d7e1327826.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_8016C374(void *arg1, void *arg2, void *arg3) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v0_6;

    temp_v0 = M2C_FIELD(arg1, u16 *, 0) - 0xA;
    M2C_FIELD(arg1, u16 *, 0) = temp_v0;
    if (temp_v0 & 0x8000) {
        M2C_FIELD(arg1, u16 *, 0) = 0U;
    }
    temp_v0_2 = M2C_FIELD(arg1, u16 *, 2) - 0xA;
    M2C_FIELD(arg1, u16 *, 2) = temp_v0_2;
    if (temp_v0_2 & 0x8000) {
        M2C_FIELD(arg1, u16 *, 2) = 0U;
    }
    temp_v0_3 = M2C_FIELD(arg1, u16 *, 4) - 0xA;
    M2C_FIELD(arg1, u16 *, 4) = temp_v0_3;
    if (temp_v0_3 & 0x8000) {
        M2C_FIELD(arg1, u16 *, 4) = 0U;
    }
    temp_v0_4 = M2C_FIELD(arg2, u16 *, 0) - 0xA;
    M2C_FIELD(arg2, u16 *, 0) = temp_v0_4;
    if (temp_v0_4 & 0x8000) {
        M2C_FIELD(arg2, u16 *, 0) = 0U;
    }
    temp_v0_5 = M2C_FIELD(arg2, u16 *, 2) - 0xA;
    M2C_FIELD(arg2, u16 *, 2) = temp_v0_5;
    if (temp_v0_5 & 0x8000) {
        M2C_FIELD(arg2, u16 *, 2) = 0U;
    }
    temp_v0_6 = M2C_FIELD(arg2, u16 *, 4) - 0xA;
    M2C_FIELD(arg2, u16 *, 4) = temp_v0_6;
    if (temp_v0_6 & 0x8000) {
        M2C_FIELD(arg2, u16 *, 4) = 0U;
    }
    M2C_FIELD(arg3, s8 *, 0) = (s8) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg3, s8 *, 1) = (s8) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg3, s8 *, 2) = (s8) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(arg3, s8 *, 4) = (s8) M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(arg3, s8 *, 5) = (s8) M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(arg3, s8 *, 6) = (s8) M2C_FIELD(arg2, u16 *, 4);
    return (s16) (M2C_FIELD(arg2, u16 *, 4) | (M2C_FIELD(arg2, u16 *, 0) | M2C_FIELD(arg2, u16 *, 2)));
}
