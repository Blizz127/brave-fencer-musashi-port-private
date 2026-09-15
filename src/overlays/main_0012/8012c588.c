/* Overlay range [8012C588,8012C658) from MAIN.CD member 0012.
 * SHA256(span)=34a26b7250a53782d970c26dd3362b0af8c768269cdb76c490e6dcf56d7bcd81.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012C890(u16 *, u16 *, void *);            /* static */
extern s32 *D_80126720;

s32 func_8012C588(s16 arg0, void *arg1) {
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

    if ((arg1 != 0) && (M2C_FIELD(arg1, u16 *, 0) != 0)) {
        sp10 = M2C_FIELD(arg1, u16 *, 6);
        sp12 = M2C_FIELD(arg1, u16 *, 0xA);
        sp14 = M2C_FIELD(arg1, u16 *, 0xE);
    } else {
        sp14 = 0;
        sp12 = 0;
        sp10 = 0;
    }
    sp16 = arg0;
    sp1A = 0;
    sp18 = 0;
    sp20 = 0;
    sp1E = 0;
    sp1C = 0x7FFF;
    if (arg1 == 0) {
        var_a1 = &D_80126720 - 0x6480;
    } else {
        var_a1 = arg1 + 0x10C;
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
        var_v0 = func_8012C890(&sp10, var_a1, arg1);
    }
    return var_v0;
}
