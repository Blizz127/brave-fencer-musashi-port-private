/* Exact retail word export for [8002DC68,8002DF80); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006451C;
void func_8002F248(u8 *, s32);                   /* static */
s32 func_8002F4E4(u8 *);                            /* static */
s32 func_80032048(s32, u8 *, s32);                  /* static */
extern s16 D_800A4EFC;
extern u8 D_800A4F17;
extern u8 D_800A4F1B;

s32 func_8002DC68(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s3;
    s32 var_v0;
    u8 *var_s0;
    u8 temp_s4;

    if (D_800A4EFC == 0) {
        var_s0 = ((arg0 & 0xFFFF) * 4) + D_8006451C;
        if ((D_800A4F1B != 0) || (var_v0 = 0, ((*var_s0 & 0x80) != 0))) {
            if ((*var_s0 & 0x3F) == 6) {
                temp_v0 = func_8002F4E4(var_s0) & 0xFFFF;
                if (temp_v0 == 0) {
                    goto block_5;
                }
                var_s0 = (temp_v0 * 4) + D_8006451C;
                goto block_7;
            }
block_7:
            temp_s4 = D_800A4F17;
            D_800A4F17 = 1;
            temp_v0_2 = *var_s0 & 0x3F;
            var_s3 = 0;
            if ((u32) (temp_v0_2 - 1) < 0x12U) {
                switch (temp_v0_2) {
                case 3:
                case 4:
                    break;
                case 1:
                    var_s3 = func_80032048(arg0, var_s0, arg1 & 0xFFFF);
                    break;
                case 2:
                    func_8002F248(var_s0, arg1 & 0xFFFF);
                    break;
                }
            }
            D_800A4F17 = temp_s4;
            var_v0 = var_s3;
            /* Duplicate return node #33. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    }
block_5:
    return 0;
}
