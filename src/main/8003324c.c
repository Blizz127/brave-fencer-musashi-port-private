/* Exact retail word export for [8003324C,80033324); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030D80(void *, s32);             /* static */
void func_80034650(u16 *, s32);              /* static */
extern s32 *D_800A46E8;

void func_8003324C(s32 arg0) {
    s32 temp_v1;
    s32 var_s1;
    u16 *temp_s2;
    void *temp_v1_2;
    void *var_s0;

    temp_s2 = ((arg0 & 0xFFFF) * 0x54) + &D_800A46E8;
    temp_v1 = *temp_s2 & 0x3F;
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_s1 = 0;
        var_s0 = &D_800A46E8 + 0x2A0;
        do {
            temp_v1_2 = temp_s2 + var_s1;
            if (M2C_FIELD(temp_v1_2, u8 *, 0xE) != 0) {
                M2C_FIELD(temp_v1_2, u8 *, 0xE) = 0U;
                M2C_FIELD(var_s0, s32 *, 0x40) = 0;
                if (M2C_FIELD(var_s0, u8 *, 0x4E) != 0) {
                    func_80030D80(var_s0, 0);
                }
            }
            var_s1 += 1;
            var_s0 += 0x54;
        } while (var_s1 < 8);
        *temp_s2 = 0;
        return;
    case 5:
        func_80034650(temp_s2, 0);
        return;
    }
}
