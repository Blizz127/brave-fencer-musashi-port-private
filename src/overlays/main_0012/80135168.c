/* Overlay range [80135168,80135260) from MAIN.CD member 0012.
 * SHA256(span)=9035b674c398e0a3bc3692a308b7e4d347bd86411648131a32ea323b35e36b11.
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
extern s32 D_80184120;
extern s32 D_80184130;
s32 func_80134A74(s32, s16, s16, s32);              /* static */

s32 func_80135168(s32 arg0, void *arg1, void *arg2) {
    s32 var_v0;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;

    temp_v0 = M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(D_8017E914, u16 *, 0) = temp_v0;
    temp_v1 = M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(D_8017E910, u16 *, 0) = temp_v1;
    M2C_FIELD(D_8017E91C, s16 *, 0) = (s16) (temp_v0 - temp_v1);
    temp_v0_2 = M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(D_8017E914, u16 *, 2) = temp_v0_2;
    temp_v1_2 = M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(D_8017E910, u16 *, 2) = temp_v1_2;
    M2C_FIELD(D_8017E91C, s16 *, 2) = (s16) (temp_v0_2 - temp_v1_2);
    temp_v0_3 = M2C_FIELD(arg2, u16 *, 4);
    M2C_FIELD(D_8017E914, u16 *, 4) = temp_v0_3;
    temp_v1_3 = M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(D_8017E910, u16 *, 4) = temp_v1_3;
    M2C_FIELD(D_8017E91C, s16 *, 4) = (s16) (temp_v0_3 - temp_v1_3);
    D_80184130 = 0U;
    var_v0 = 0;
    if (func_80134A74(arg0 & 0xFFFF, (s16) M2C_FIELD(D_8017E910, u16 *, 0), (s16) M2C_FIELD(D_8017E910, u16 *, 4), D_80184120) != 0) {
        M2C_FIELD(arg2, u16 *, 0) = (u16) M2C_FIELD(D_8017E918, u16 *, 0);
        M2C_FIELD(arg2, u16 *, 2) = (u16) M2C_FIELD(D_8017E918, u16 *, 2);
        var_v0 = 1;
        M2C_FIELD(arg2, u16 *, 6) = (u16) D_80184130;
        M2C_FIELD(arg2, u16 *, 4) = (u16) M2C_FIELD(D_8017E918, u16 *, 4);
    }
    return var_v0;
}
