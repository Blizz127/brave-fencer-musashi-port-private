/* Overlay range [8013895C,80138AB4) from MAIN.CD member 0012.
 * SHA256(span)=846c8c8be63514dd260a88be084b9265b482bdfacf64ebb8cefd9d991a2dce5b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);            /* extern */
void func_80138B88(void *);                      /* static */
s32 func_80138DB8(void *, s32, s32);        /* static */
extern s32 D_80127524;

void func_8013895C(void *arg0) {
    s32 var_a0;
    u8 temp_v0;
    u8 temp_v0_2;

    if ((D_80127524 == arg0) || (M2C_FIELD(arg0, s32 *, 8) & 0x2000)) {
        if ((func_80138DB8(arg0, 0, 0x40) << 0x10) != 0) {
            M2C_FIELD(arg0, u8 *, 0x1F) = (u8) (M2C_FIELD(arg0, u8 *, 0x1F) + 1);
            func_80138B88(arg0);
            var_a0 = 0x630;
            goto block_15;
        }
        if ((func_80138DB8(arg0, 0, 0x1000) << 0x10) != 0) {
            temp_v0 = M2C_FIELD(arg0, u8 *, 0x1F) - 1;
            M2C_FIELD(arg0, u8 *, 0x1F) = temp_v0;
            var_a0 = 0x62F;
            if (temp_v0 & 0x80) {
                M2C_FIELD(arg0, u8 *, 0x1F) = (u8) (M2C_FIELD(arg0, u8 *, 0x21) - 1);
            }
            goto block_15;
        }
        if ((func_80138DB8(arg0, 0, 0x4000) << 0x10) != 0) {
            temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x1F) + 1;
            M2C_FIELD(arg0, u8 *, 0x1F) = temp_v0_2;
            var_a0 = 0x62F;
            if ((s8) temp_v0_2 >= (s32) M2C_FIELD(arg0, u8 *, 0x21)) {
                M2C_FIELD(arg0, u8 *, 0x1F) = 0U;
            }
            goto block_15;
        }
        if (M2C_FIELD(arg0, s32 *, 8) & 2) {
            var_a0 = 0x62F;
            if ((func_80138DB8(arg0, 0, 0x30) << 0x10) != 0) {
                M2C_FIELD(arg0, u8 *, 0x1F) = (u8) (M2C_FIELD(arg0, u8 *, 0x21) - 1);
block_15:
                func_8002D4C8(var_a0, 0);
            }
        }
    }
}
