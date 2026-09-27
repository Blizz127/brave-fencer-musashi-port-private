/* Exact retail word export for [800414E4,800415A8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A5ED8;
extern s32 *D_800A5F20;
extern s32 *D_800A60B0;
extern s16 D_800A6540;
extern s32 D_800A6578;
extern s32 D_800A6580;
extern s32 D_800A6584;
extern s8 D_800B9B21;
extern s8 D_800B9B26;
extern s8 D_800B9B27;
extern s32 *D_800B9B40;

s32 func_800414E4(s16 arg0, s16 arg1) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v0;

    if ((u32) (arg0 & 0xFFFF) < 0x10U) {
        var_v0 = -1;
        if (*(&D_800B9B40 + arg0) == 1) {
            temp_v0 = arg0 * 4;
            if (arg1 >= D_800A6540) {
                goto block_3;
            }
            temp_a0 = *(&D_800A5ED8 + temp_v0);
            D_800B9B21 = (s8) arg0;
            D_800B9B26 = (s8) arg1;
            var_v0 = 0;
            D_800A6580 = *(&D_800A5F20 + temp_v0);
            D_800A6578 = temp_a0;
            D_800A6584 = *(&D_800A60B0 + temp_v0);
            D_800B9B27 = (s8) M2C_FIELD(((arg1 * 0x10) + temp_a0), s32 *, 8);
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return var_v0;
        }
        return var_v0;
    }
block_3:
    return -1;
}
