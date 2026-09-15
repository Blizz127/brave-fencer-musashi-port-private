/* Overlay range [80133784,80133AB0) from MAIN.CD member 0012.
 * SHA256(span)=bb1d419a28302257af8d974325d80186d6c89fe78bf44e7d14cc8424df976002.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047D3C(s32, s16, s32, void *);           /* extern */
extern s32 D_8017E910;
extern s32 D_8017E914;
extern s32 D_80184120;
extern s32 D_8018412C;
extern s32 D_80184130;
s32 func_80133AB0(s16, s16, s16, s32);              /* static */

s32 func_80133784(s16 arg0, void *arg1, void *arg2) {
    s16 temp_a1;
    s16 temp_v1_2;
    s16 var_s3;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s1;
    s32 var_s2;
    s32 var_s4;
    s32 var_v0;
    s32 var_v1;

    var_s1 = 0;
    var_s3 = 0;
    var_s4 = 0;
    M2C_FIELD(D_8017E910, s16 *, 6) = -0x7FFF;
    M2C_FIELD(D_8017E914, s16 *, 6) = 0x7FFF;
    var_s2 = 0;
    M2C_FIELD(D_8017E910, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(D_8017E910, u16 *, 4) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(D_8017E914, u16 *, 0) = (u16) M2C_FIELD(arg2, u16 *, 0);
    D_80184130 = 0U;
    D_8018412C = 0;
    M2C_FIELD(D_8017E914, u16 *, 4) = (u16) M2C_FIELD(arg2, u16 *, 4);
    if (arg0 == 0) {
        temp_v1 = M2C_FIELD(arg2, u16 *, 0) - M2C_FIELD(arg1, u16 *, 0);
        temp_a2 = M2C_FIELD(arg2, u16 *, 2) - M2C_FIELD(arg1, u16 *, 2);
        temp_a1 = M2C_FIELD(arg2, u16 *, 4) - M2C_FIELD(arg1, u16 *, 4);
        if ((temp_v1 << 0x10) == 0) {
            var_v0 = temp_v1 << 0x10;
            if ((temp_a2 << 0x10) == 0) {
                var_s2 = (temp_a1 << 0x10) == 0;
                goto block_4;
            }
        } else {
block_4:
            var_v0 = temp_v1 << 0x10;
        }
        temp_v0 = var_v0 >> 0x10;
        M2C_FIELD(D_8017E910, u16 *, 2) = (u16) (M2C_FIELD(arg1, u16 *, 2) - 4);
        var_v1 = func_80047D3C((temp_v0 * temp_v0) + (temp_a1 * temp_a1), temp_a1, temp_a2, arg1);
        if (var_v1 < 3) {
            var_v1 = 4;
        } else if (var_v1 < 5) {
            var_v1 += 1;
        }
        M2C_FIELD(D_8017E914, u16 *, 2) = (u16) (M2C_FIELD(arg2, u16 *, 2) + var_v1 + 1);
    } else {
        M2C_FIELD(D_8017E910, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
        if (arg0 == 2) {
            M2C_FIELD(D_8017E914, u16 *, 0) = (u16) M2C_FIELD(D_8017E910, u16 *, 0);
            M2C_FIELD(D_8017E914, u16 *, 2) = (u16) (M2C_FIELD(D_8017E910, u16 *, 2) + 6);
            var_s2 = 1;
            M2C_FIELD(D_8017E914, u16 *, 4) = (u16) M2C_FIELD(D_8017E910, u16 *, 4);
        } else {
            M2C_FIELD(D_8017E914, u16 *, 2) = (u16) M2C_FIELD(arg2, u16 *, 2);
        }
    }
loop_13:
    temp_v0_2 = func_80133AB0(arg0, (s16) M2C_FIELD(D_8017E910, u16 *, 0), (s16) M2C_FIELD(D_8017E910, u16 *, 4), D_80184120);
    if (temp_v0_2 != 0) {
        var_s4 |= temp_v0_2;
        if (var_s2 == 0) {
            var_s3 += 1;
            if (var_s3 >= 5) {
                M2C_FIELD(D_8017E914, u16 *, 0) = (u16) M2C_FIELD(D_8017E910, u16 *, 0);
                M2C_FIELD(D_8017E914, u16 *, 2) = (u16) M2C_FIELD(D_8017E910, u16 *, 2);
                var_s1 = 0x2000;
                M2C_FIELD(D_8017E914, u16 *, 4) = (u16) M2C_FIELD(D_8017E910, u16 *, 4);
                goto block_25;
            }
            goto loop_13;
        }
    }
    if (((var_s4 << 0x10) != 0) || (D_8018412C != 0)) {
        temp_v1_2 = M2C_FIELD(D_8017E910, s16 *, 6);
        if (temp_v1_2 >= -0xBCB) {
            if (temp_v1_2 < -0x578) {
                var_s1 = 0x4000;
            } else {
                var_s1 = 0x8000;
            }
        }
        if (M2C_FIELD(D_8017E914, s16 *, 6) < -0xBCB) {
            var_s1 |= 0x2000;
        }
block_25:
        M2C_FIELD(arg2, u16 *, 0) = (u16) M2C_FIELD(D_8017E914, u16 *, 0);
        M2C_FIELD(arg2, u16 *, 2) = (u16) M2C_FIELD(D_8017E914, u16 *, 2);
        M2C_FIELD(arg2, u16 *, 6) = (u16) D_80184130;
        M2C_FIELD(arg2, u16 *, 4) = (u16) M2C_FIELD(D_8017E914, u16 *, 4);
        return var_s1 & 0xFFFF;
    }
    M2C_FIELD(arg2, u16 *, 6) = (u16) D_80184130;
    return 0;
}
