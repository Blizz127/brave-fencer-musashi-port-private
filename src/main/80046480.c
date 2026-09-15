/* Exact retail word export for [80046480,8004654C); EXE-verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CFBC;
s32 func_8004239C();                         /* static */
void func_8004357C(s32, s32);            /* static */
void func_800460CC();                     /* static */

s32 func_80046480(s32 arg0, s32 arg1) {
    s32 var_s0;

loop_1:
    var_s0 = -1;
    if ((M2C_FIELD(D_8006CFBC, s32 *, 0) + 0x4B0) >= func_8004239C(-1)) {
        if ((M2C_FIELD(D_8006CFBC, s32 *, -8) < 0) || ((M2C_FIELD(D_8006CFBC, s32 *, -4) + 0x3C) < func_8004239C(-1))) {
            func_800460CC(1);
            var_s0 = M2C_FIELD(D_8006CFBC, s32 *, -0x1C);
        } else {
            var_s0 = M2C_FIELD(D_8006CFBC, s32 *, -8);
        }
    }
    if ((arg0 == 0) && (var_s0 > 0)) {
        goto loop_1;
    }
    func_8004357C(1, arg1);
    return var_s0;
}
