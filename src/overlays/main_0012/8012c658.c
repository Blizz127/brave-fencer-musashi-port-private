/* Overlay range [8012C658,8012C724) from MAIN.CD member 0012.
 * SHA256(span)=7c88806187c34718caedaa7fa8ed6474baa69da635407d1f74aecb88c630a8d9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012C890(u16 *, u16 *);                    /* static */
extern s32 *D_80126720;

s32 func_8012C658(s16 arg0, s16 arg1, void *arg2) {
    s32 sp20;
    s16 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 var_v0;
    u16 *var_a1;

    if ((arg2 != 0) && (M2C_FIELD(arg2, u16 *, 0) != 0)) {
        sp10 = M2C_FIELD(arg2, u16 *, 6);
        sp12 = M2C_FIELD(arg2, u16 *, 0xA);
        sp14 = M2C_FIELD(arg2, u16 *, 0xE);
    } else {
        sp14 = 0;
        sp12 = 0;
        sp10 = 0;
    }
    sp16 = arg0;
    sp18 = arg1;
    sp1A = 0;
    sp20 = 0;
    sp1E = 0;
    sp1C = 0x7FFF;
    if (arg2 == 0) {
        var_a1 = &D_80126720 - 0x6480;
    } else {
        var_a1 = arg2 + 0x10C;
    }
    if (var_a1 != &D_80126720) {
loop_8:
        if (*var_a1 != 0) {
            var_a1 += 0x10C;
            if (var_a1 == &D_80126720) {
                goto block_10;
            }
            goto loop_8;
        }
    } else {
block_10:
        var_a1 = 0;
    }
    var_v0 = 0;
    if (var_a1 != 0) {
        var_v0 = func_8012C890(&sp10, var_a1);
    }
    return var_v0;
}
