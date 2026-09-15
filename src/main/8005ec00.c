/* Exact retail word export for [8005EC00,8005ECC0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800729A8;
extern s32 D_800729D4;
extern s32 D_800729DC;
s32 func_8005DE78(void *, s32);                     /* static */
void func_80072974();                            /* static */

s32 func_8005EC00(void *arg0) {
    s32 temp_v0;
    s32 var_a1;
    s32 var_v0;

    if (D_800729DC != 0) {
        func_80072974(M2C_FIELD(arg0, s32 *, 0xC) + 0x1E0);
        func_80072974(M2C_FIELD(arg0, s32 *, 0xC) + 0x2D0);
    }
    var_a1 = 0;
    if (M2C_FIELD(arg0, u8 *, 0x36) == 0) {
        var_a1 = D_800729A8;
    }
    var_v0 = func_8005DE78(arg0, var_a1);
    if (var_v0 >= 0) {
        if (!(var_v0 & 0xF0)) {
            return -9;
        }
        temp_v0 = (var_v0 & 0xF) * 2;
        D_800729D4 = temp_v0;
        var_v0 = 0;
        if (temp_v0 == 0) {
            D_800729D4 = 0x20;
            var_v0 = 0;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
