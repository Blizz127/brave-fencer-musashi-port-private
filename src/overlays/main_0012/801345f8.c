/* Overlay range [801345F8,801347A0) from MAIN.CD member 0012.
 * SHA256(span)=59485f6423eb86cde93db1ac7ed4701f0104984fa6d718b4cabe87ba2e4f091f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017E910;
extern s32 D_80184130;
s32 func_801347A0(s16, u16 *, s32, s32);            /* static */

s32 func_801345F8(void *arg0) {
    s16 temp_v0_4;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v0_2;
    u16 *var_s0;
    u16 *var_s2;
    u16 temp_a2;
    u16 temp_v1;
    u16 var_s1;
    void *temp_v0_3;

    temp_a2 = M2C_FIELD(arg0, u16 *, 4);
    temp_v0 = (((s32) (M2C_FIELD(D_8017E910, u16 *, 0) + 0x8000) >> 7) & 0x1FF) - M2C_FIELD(arg0, u16 *, 0);
    if ((u32) (temp_v0 & 0xFFFF) < temp_a2) {
        temp_v0_2 = (((s32) (M2C_FIELD(D_8017E910, u16 *, 4) + 0x8000) >> 7) & 0x1FF) - M2C_FIELD(arg0, u16 *, 2);
        if ((u32) (temp_v0_2 & 0xFFFF) >= (u16) M2C_FIELD(arg0, u16 *, 6)) {
            return 0;
        }
        temp_s6 = M2C_FIELD(arg0, s32 *, 0xC);
        temp_s5 = M2C_FIELD(arg0, s32 *, 0x10);
        temp_s4 = M2C_FIELD(arg0, s32 *, 0x18);
        temp_s3 = M2C_FIELD(arg0, s32 *, 0x1C);
        temp_v0_3 = ((((((temp_v0_2 & 0xFFFF) * temp_a2) + (temp_v0 & 0xFFFF)) * 2) & 0xFFFF) * 2) + M2C_FIELD(arg0, s32 *, 8);
        var_s1 = M2C_FIELD(temp_v0_3, u16 *, 2);
        var_s2 = (M2C_FIELD(arg0, s32 *, 0x14) + M2C_FIELD(temp_v0_3, u16 *, 0) + (var_s1 * 2)) - 2;
loop_9:
        var_s1 -= 1;
        if (!(var_s1 & 0xFFFF)) {
            /* Duplicate return node #11. Try simplifying control flow for better match */
            return 0;
        }
        temp_v1 = *var_s2;
        temp_v0_4 = temp_v1 & 0x8000;
        if (temp_v0_4 == 0) {
            var_s0 = temp_s4 + (temp_v1 * 0x12);
        } else {
            var_s0 = temp_s3 + ((temp_v1 & 0x7FFF) * 0x16);
        }
        var_s2 -= 2;
        if (func_801347A0(temp_v0_4, var_s0, temp_s5, temp_s6) == 0) {
            goto loop_9;
        }
        D_80184130 = (u16) *var_s0;
        return 1;
    }
    return 0;
}
