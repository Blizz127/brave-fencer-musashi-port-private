/* Overlay range [80134510,801345F8) from MAIN.CD member 0012.
 * SHA256(span)=f9735b8563f746b870b474cf5f32aca3c29173ef8c2ed660cafecf5b6a8baeb6.
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
extern s32 D_80184120;
extern s32 D_80184130;
s32 func_801345F8(s32, void *, void *);             /* static */

s32 func_80134510(void *arg0) {
    s16 temp_v1;
    s32 var_s0;
    s32 var_v0;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(D_8017E910, u16 *, 0) = temp_v0;
    M2C_FIELD(D_8017E914, u16 *, 0) = temp_v0;
    temp_v0_2 = M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD(D_8017E910, s16 *, 2) = (s16) (temp_v0_2 - 4);
    M2C_FIELD(D_8017E914, s16 *, 2) = (s16) (temp_v0_2 + 0x2FC);
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 4);
    M2C_FIELD(D_8017E910, u16 *, 4) = temp_v0_3;
    M2C_FIELD(D_8017E914, u16 *, 4) = temp_v0_3;
    var_v0 = 0;
    if (func_801345F8(D_80184120, D_8017E910, D_8017E914) != 0) {
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(D_8017E918, u16 *, 2) - 2);
        temp_v1 = M2C_FIELD(D_8017E910, s16 *, 6);
        if (temp_v1 >= -0xBCB) {
            var_s0 = 0x8000;
            if (temp_v1 < -0x578) {
                var_s0 = 0x4000;
            }
        } else {
            var_s0 = 0x2000;
        }
        M2C_FIELD(D_8017E910, s16 *, 6) = (s16) D_80184130;
        var_v0 = var_s0;
    }
    return var_v0;
}
