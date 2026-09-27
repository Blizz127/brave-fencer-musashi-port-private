/* Exact retail word export for [8002EED8,8002EFD0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006451C;
s16 func_8002F4E4(u8 *);                            /* static */
void func_80033398(s16);                         /* static */
extern u8 D_800A4F17;

void func_8002EED8(s16 arg0) {
    s16 temp_v0;
    s32 temp_v0_2;
    u8 *var_a0;
    u8 temp_s1;

    if (arg0 >= 0x100) {
        var_a0 = (arg0 * 4) + D_8006451C;
        if ((*var_a0 & 0x7F) == 6) {
            temp_v0 = func_8002F4E4(var_a0);
            if (temp_v0 != 0) {
                var_a0 = (temp_v0 * 4) + D_8006451C;
                goto block_4;
            }
        } else {
block_4:
            temp_s1 = D_800A4F17;
            D_800A4F17 = 1;
            temp_v0_2 = *var_a0 & 0x3F;
            if ((u32) (temp_v0_2 - 1) < 0x12U) {
                switch (temp_v0_2) {
                case 2:
                case 3:
                case 4:
                    break;
                case 1:
                    func_80033398(arg0);
                    break;
                }
            }
            D_800A4F17 = temp_s1;
        }
    }
}
