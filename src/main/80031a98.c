/* Exact retail word export for [80031A98,80031B7C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030D80(void *, s32);          /* static */
extern u8 D_800A46B0;
extern s32 *D_800A4988;
extern s32 *D_800C5328;
extern s32 *D_800C532A;

void func_80031A98(void) {
    void *var_s1;
    s16 var_v0;
    s32 var_s2;
    u16 temp_v1;
    void *var_s0;

    var_s1 = &D_800A4988;
    var_s2 = 0;
    var_s0 = &D_800A4988 + 0xE;
    do {
        if (M2C_FIELD(var_s0, u8 *, 0x40) != 0) {
            if (M2C_FIELD(var_s0, u8 *, 0x28) != 0) {
                var_v0 = *(&D_800C532A + (M2C_FIELD(var_s0, u16 *, 0) * 4));
                goto block_8;
            }
            temp_v1 = M2C_FIELD(var_s0, u16 *, 0);
            if (temp_v1 & 0x80) {
                if (D_800A46B0 != 0) {
                    goto block_9;
                }
            } else {
                var_v0 = *(&D_800C5328 + (temp_v1 * 4));
block_8:
                if (var_v0 < 0) {
block_9:
                    func_80030D80(var_s1, 1);
                }
            }
        }
        var_s2 += 1;
        var_s0 += 0x54;
        var_s1 += 0x54;
    } while (var_s2 < 8);
}
