/* Overlay range [8014BB24,8014BC0C) from MAIN.CD member 0012.
 * SHA256(span)=c5897073bde480e56521f69047990755701e63e5f452e11269e830f0a0724f5d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
extern s32 *D_80078E78;
extern u16 D_80078EB4;

void func_8014BB24(s32 arg1, s32 arg2) {
    u16 temp_v0;
    u16 temp_v0_2;
    u16 var_v0;

    if (arg2 != 0) {
        var_v0 = D_80078EB4 + arg1;
        goto block_8;
    }
    if (func_80029178(0x1B) & 0xFF) {
        temp_v0 = D_80078EB4 + arg1;
        if ((u16) D_80078EB4 < 0x3E7U) {
            D_80078EB4 = temp_v0;
            var_v0 = 0x3E7;
            if ((u32) (temp_v0 & 0xFFFF) >= 0x3E8U) {
                goto block_8;
            }
        }
    } else {
        temp_v0_2 = D_80078EB4 + arg1;
        if ((u16) D_80078EB4 < 0x1F4U) {
            D_80078EB4 = temp_v0_2;
            var_v0 = 0x1F4;
            if ((u32) (temp_v0_2 & 0xFFFF) >= 0x1F5U) {
block_8:
                D_80078EB4 = var_v0;
            }
        }
    }
    if ((u16) M2C_FIELD(&D_80078E78, u16 *, 0x3A) < (u16) M2C_FIELD(&D_80078E78, u16 *, 0x3C)) {
        M2C_FIELD(&D_80078E78, u16 *, 0x3C) = (u16) M2C_FIELD(&D_80078E78, u16 *, 0x3A);
    }
}
