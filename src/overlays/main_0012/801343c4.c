/* Overlay range [801343C4,80134510) from MAIN.CD member 0012.
 * SHA256(span)=ebc18f9d47195bcde796825d84405a2d336d8f97994d35c5d88eea48a7df0254.
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
extern s32 D_80184120;
extern s32 D_8018412C;
extern s32 D_80184130;
s32 func_80133AB0(s16, s16, s16, s32);              /* static */

s32 func_801343C4(s16 arg0, void *arg1, void *arg2) {
    s16 temp_a1;

    M2C_FIELD(D_8017E910, u16 *, 0) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(D_8017E910, u16 *, 2) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(D_8017E910, u16 *, 4) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(D_8017E914, u16 *, 0) = (u16) M2C_FIELD(arg2, u16 *, 0);
    M2C_FIELD(D_8017E914, u16 *, 2) = (u16) M2C_FIELD(arg2, u16 *, 2);
    M2C_FIELD(D_8017E914, u16 *, 4) = (u16) M2C_FIELD(arg2, u16 *, 4);
    D_80184130 = 0U;
    D_8018412C = 0;
    if (func_80133AB0(arg0, (s16) M2C_FIELD(D_8017E910, u16 *, 0), (s16) M2C_FIELD(D_8017E910, u16 *, 4), D_80184120) != 0) {
        goto block_1;
    }
    temp_a1 = (s16) M2C_FIELD(D_8017E914, u16 *, 0);
    if (((((s16) M2C_FIELD(D_8017E910, u16 *, 0) & 0xFF80) == (temp_a1 & 0xFF80)) && (((s16) M2C_FIELD(D_8017E910, u16 *, 4) & 0xFF80) == ((s16) M2C_FIELD(D_8017E914, u16 *, 4) & 0xFF80))) || (func_80133AB0(arg0, temp_a1, (s16) M2C_FIELD(D_8017E914, u16 *, 4), D_80184120) == 0)) {
        return 0;
    }
block_1:
    M2C_FIELD(arg2, u16 *, 0) = (u16) M2C_FIELD(D_8017E914, u16 *, 0);
    M2C_FIELD(arg2, u16 *, 2) = (u16) M2C_FIELD(D_8017E914, u16 *, 2);
    M2C_FIELD(arg2, u16 *, 6) = (u16) D_80184130;
    M2C_FIELD(arg2, u16 *, 4) = (u16) M2C_FIELD(D_8017E914, u16 *, 4);
    return 1;
}
