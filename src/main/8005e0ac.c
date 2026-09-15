/* Exact retail word export for [8005E0AC,8005E13C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800729BC;
extern s32 D_800729C0;
s32 func_8005FBC8();                                /* static */

s32 func_8005E0AC(void) {
    s32 var_v0;

    *D_800729BC = -0x81;
    if (M2C_FIELD(D_800729C0, u16 *, 4) & 0x80) {
loop_1:
        var_v0 = 0;
        if (func_8005FBC8() == 0) {
            if (!(M2C_FIELD(D_800729C0, u16 *, 4) & 0x80)) {
                goto block_3;
            }
            goto loop_1;
        }
    } else {
block_3:
        var_v0 = 1;
        M2C_FIELD(D_800729C0, u16 *, 0xA) = (u16) (M2C_FIELD(D_800729C0, u16 *, 0xA) | 0x10);
    }
    return var_v0;
}
