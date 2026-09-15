/* Overlay range [8014A738,8014A830) from MAIN.CD member 0012.
 * SHA256(span)=aa4b990f2613b720adab343799213226cc04518ca1330f5e1e6062f9c97b3730.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
extern s32 *D_801202A0;

s32 func_8014A738(void *arg0) {
    s16 sp14;
    void *var_a1;
    s16 temp_a0;
    s32 var_v0;
    u32 var_a2;

    var_v0 = 0;
    if (func_80029178(0x83) & 0xFF) {
        var_a2 = 0;
        var_a1 = &D_801202A0;
loop_2:
        if (M2C_FIELD(var_a1, u8 *, 0xC1) == 7) {
            temp_a0 = M2C_FIELD(arg0, u16 *, 6) - M2C_FIELD(var_a1, u16 *, 6);
            sp14 = M2C_FIELD(arg0, u16 *, 0xE) - M2C_FIELD(var_a1, u16 *, 0xE);
            if (temp_a0 >= 0) {
                if (temp_a0 >= 0x40) {
                    var_a2 += 1;
                    goto block_12;
                }
                goto block_7;
            }
            if (-temp_a0 < 0x40) {
block_7:
                if (sp14 >= 0) {
                    var_v0 = 1;
                    if (sp14 >= 0x40) {
                        var_a2 += 1;
                        goto block_12;
                    }
                } else {
                    var_v0 = 1;
                    if (-sp14 >= 0x40) {
                        goto block_11;
                    }
                }
            } else {
                goto block_11;
            }
        } else {
block_11:
            var_a2 += 1;
block_12:
            var_a1 += 0x10C;
            if (var_a2 >= 0x60U) {
                var_v0 = 0;
            } else {
                goto loop_2;
            }
        }
    }
    return var_v0;
}
