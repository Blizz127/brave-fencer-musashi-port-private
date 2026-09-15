/* Overlay range [8015094C,80150A70) from MAIN.CD member 0012.
 * SHA256(span)=2ede149de45b3534d7fe2acce9e4efdc2d1c28969b1affa688d7697068a35543.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80021174(s32, s32 *);                      /* extern */
extern s32 D_8017FFF8;
extern s32 D_801836B0;
extern s32 *D_80126948;
extern s32 D_80126990;
extern s32 D_80126994;

s32 func_8015094C(void *arg0) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_v0_2;
    s16 var_v0_4;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_v0;
    s32 var_v0_3;

    sp40 = M2C_FIELD(D_801836B0, s32 *, 0);
    sp44 = M2C_FIELD(D_801836B0, s32 *, 4);
    sp48 = M2C_FIELD(D_801836B0, s32 *, 8);
    sp4C = M2C_FIELD(D_801836B0, s32 *, 0xC);
    sp10 = (s32) M2C_FIELD(arg0, s16 *, 6);
    sp14 = D_80126994;
    sp18 = (s32) M2C_FIELD(arg0, s16 *, 0xE);
    if (func_80021174(D_8017FFF8, &sp10) == 0) {
        temp_v1 = M2C_FIELD(arg0, s16 *, 6);
        temp_a0 = D_80126990 - temp_v1;
        var_v0 = temp_a0;
        if (temp_a0 < 0) {
            var_v0 = -temp_a0;
        }
        if (var_v0 >= 5) {
            if (temp_a0 >= 0) {
                var_v0_2 = temp_v1 + 4;
            } else {
                var_v0_2 = temp_v1 - 4;
            }
            M2C_FIELD(arg0, s16 *, 6) = var_v0_2;
        }
        temp_v1_2 = M2C_FIELD(arg0, s16 *, 0xE);
        temp_a0_2 = M2C_FIELD(&D_80126948, s32 *, 0x50) - temp_v1_2;
        var_v0_3 = temp_a0_2;
        if (temp_a0_2 < 0) {
            var_v0_3 = -temp_a0_2;
        }
        if (var_v0_3 >= 5) {
            if (temp_a0_2 >= 0) {
                var_v0_4 = temp_v1_2 + 4;
            } else {
                var_v0_4 = temp_v1_2 - 4;
            }
            M2C_FIELD(arg0, s16 *, 0xE) = var_v0_4;
        }
        return 1;
    }
    return 0;
}
