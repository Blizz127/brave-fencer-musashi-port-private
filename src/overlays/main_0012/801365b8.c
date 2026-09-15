/* Overlay range [801365B8,80136824) from MAIN.CD member 0012.
 * SHA256(span)=a43b3a23b4b666a54546ece220d7688c24817096acd75abcbe001be1c74227bd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017E910;
extern s32 D_8017E914;
extern s32 D_8017E918;
extern s32 D_8017E91C;
extern s16 D_801152A8;
extern s16 D_801152AA;
extern s16 D_801152AC;
extern s16 D_80126720;
extern s16 D_80126722;
extern s16 D_80126724;

s32 func_801365B8(void *arg0, s32 arg1, s16 arg2) {
    s16 temp_v0;
    s16 temp_v1;
    s16 var_a3;
    s16 var_v0_3;
    s32 temp_a1;
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;

    if (!(arg1 & 1)) {
        var_v1 = arg2 - M2C_FIELD(D_8017E910, s16 *, 0);
        var_a1 = var_v1;
        var_a3 = -M2C_FIELD(D_8017E91C, s16 *, 0);
    } else {
        var_a3 = M2C_FIELD(D_8017E91C, s16 *, 0);
        var_v1 = M2C_FIELD(D_8017E910, s16 *, 0) - arg2;
        var_a1 = -var_v1;
    }
    M2C_FIELD(D_8017E918, s16 *, 0) = (u16) M2C_FIELD(D_8017E910, s16 *, 0) + var_a1;
    temp_a1 = -var_v1;
    M2C_FIELD(D_8017E918, s16 *, 2) = (s16) (M2C_FIELD(D_8017E910, u16 *, 2) + ((s32) (temp_a1 * M2C_FIELD(D_8017E91C, s16 *, 2)) / var_a3));
    temp_v0 = M2C_FIELD(D_8017E910, u16 *, 4) + ((s32) (temp_a1 * M2C_FIELD(D_8017E91C, s16 *, 4)) / var_a3);
    M2C_FIELD(D_8017E918, s16 *, 4) = temp_v0;
    var_v0 = 0;
    if (temp_v0 >= M2C_FIELD(arg0, s16 *, 0xC)) {
        var_v0 = 0;
        if (M2C_FIELD(arg0, s16 *, 0xE) >= temp_v0) {
            temp_v1 = M2C_FIELD(D_8017E918, s16 *, 2);
            var_v0 = 0;
            if (temp_v1 >= M2C_FIELD(arg0, s16 *, 8)) {
                var_v0 = 0;
                if (M2C_FIELD(arg0, s16 *, 0xA) >= temp_v1) {
                    var_v0_2 = arg1 & 1;
                    if (arg1 & 0x8000) {
                        M2C_FIELD(D_8017E918, s16 *, 2) = (s16) M2C_FIELD(D_8017E914, u16 *, 2);
                        M2C_FIELD(D_8017E918, s16 *, 4) = (s16) M2C_FIELD(D_8017E914, u16 *, 4);
                        var_v0_2 = arg1 & 1;
                    }
                    D_801152AC = 0;
                    D_801152AA = 0;
                    if (var_v0_2 != 0) {
                        D_801152A8 = 0xFFF;
                        var_v0_3 = arg2 + 2;
                    } else {
                        D_801152A8 = -0xFFF;
                        var_v0_3 = arg2 - 2;
                    }
                    M2C_FIELD(D_8017E918, s16 *, 0) = var_v0_3;
                    D_80126720 = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 4) + M2C_FIELD(arg0, s16 *, 6)) >> 1);
                    D_80126722 = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0xA)) >> 1);
                    var_v0 = 1;
                    D_80126724 = (s16) ((s32) (M2C_FIELD(arg0, s16 *, 0xC) + M2C_FIELD(arg0, s16 *, 0xE)) >> 1);
                }
            }
        }
    }
    return var_v0;
}
