/* Overlay range [8014E284,8014E434) from MAIN.CD member 0012.
 * SHA256(span)=378e223edfb69ff8b5afc22e1f25acb9379f63c733a50fa011127455e033e1a5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012A60(s16, s16);                        /* extern */
s16 func_8004CFEC(s16, s16);                        /* extern */
s32 func_80135A4C(s32, s32, void *, void *);        /* static */
extern u16 D_801202A0;
extern s32 *D_80126720;

s32 func_8014E284(void *arg0, void *arg1, void *arg2) {
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s1;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_a1;
    u16 *var_s2;
    u16 *var_s3;

    temp_v0 = M2C_FIELD(arg2, u16 *, 0) - M2C_FIELD(arg1, u16 *, 0);
    temp_v1 = M2C_FIELD(arg2, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
    if (((temp_v0 | temp_v1) << 0x10) != 0) {
        var_s3 = &D_801202A0;
        if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
            var_s2 = &D_801202A0 + 0xE;
loop_3:
            if (*var_s3 != 0) {
                temp_a1 = M2C_FIELD(var_s2, s32 *, 0x4A);
                if ((temp_a1 != 0) && (M2C_FIELD(var_s2, u16 *, 0x4E) & 0x1000) && (func_80135A4C(M2C_FIELD(var_s2, s32 *, 0x12), temp_a1, arg1, arg2) != 0)) {
                    temp_s1 = M2C_FIELD(var_s2, u16 *, -8) - M2C_FIELD(arg0, u16 *, 6);
                    temp_s0 = M2C_FIELD(var_s2, u16 *, 0) - M2C_FIELD(arg0, u16 *, 0xE);
                    temp_s0_2 = func_8004CFEC(temp_v1, temp_v0);
                    if (func_80012A60(temp_s0_2, func_8004CFEC(temp_s0, temp_s1)) < 0x400) {
                        M2C_FIELD(arg0, u16 **, 0x170) = var_s3;
                        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg2, u16 *, 0);
                        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg2, u16 *, 2) + 0x10);
                        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg2, u16 *, 4);
                        return 1;
                    }
                }
            }
            var_s3 += 0x10C;
            var_s2 += 0x10C;
            if ((u32) var_s3 >= (u32) &D_80126720) {
                goto block_10;
            }
            goto loop_3;
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return 0;
    }
block_10:
    return 0;
}
