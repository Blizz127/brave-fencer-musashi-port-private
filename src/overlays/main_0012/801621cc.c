/* Overlay range [801621CC,801622C4) from MAIN.CD member 0012.
 * SHA256(span)=1393dde51c3837f73e63fc6569ed782e9a4afe5e3c37abe901cb5c56e0897524.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800291DC();                         /* extern */
extern s32 D_80180EBC;
extern s32 *D_80078E78;
extern u8 D_80078EB0;
extern u8 D_80078EB1;

s32 func_801621CC(s32 arg0) {
    s32 temp_v0;
    s32 var_a1;
    s8 var_a0;
    s8 var_v0;
    u32 temp_a2;

    temp_v0 = func_800291DC(8);
    temp_a2 = temp_v0 & 0x7FFF;
    if (temp_v0 & 0x8000) {
        if (((temp_a2 >> 8) != D_80078EB1) || ((u8) D_80078EB0 < (u32) (temp_a2 & 0xFF))) {
            var_a1 = 0;
            var_a0 = M2C_FIELD(&D_80078E78, u8 *, 0x39) - 1;
            if (arg0 > 0) {
loop_5:
                var_v0 = var_a0;
                if (var_a0 & 0x80) {
                    var_a0 = 0x17;
                    var_v0 = 0x17;
                }
                if (((temp_a2 >> 8) & 0xFF) == var_v0) {
                    if ((var_a1 != (arg0 - 1)) || (var_a1 += 1, (((u8) M2C_FIELD(&D_80078E78, u8 *, 0x38) < (u32) (temp_a2 & 0xFF)) != 0))) {
                        goto block_10;
                    }
                    goto block_12;
                }
                var_a1 += 1;
block_12:
                var_a0 -= 1;
                if (var_a1 >= arg0) {
                    goto block_13;
                }
                goto loop_5;
            }
            goto block_13;
        }
block_10:
        return D_80180EBC;
    }
block_13:
    return 0;
}
