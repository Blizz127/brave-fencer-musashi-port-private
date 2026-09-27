/* Overlay range [80149FB0,8014A048) from MAIN.CD member 0012.
 * SHA256(span)=c0b00bc1387cc6482062e6cc6d51d5b3ca133b621846f50ef3e8f0ae67e2732a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017FF38;
extern s32 *D_80078E78;
extern s16 D_800B9A08;

s32 func_80149FB0(void *arg0) {
    s32 *var_v0_2;
    s32 var_v0;
    s32 var_v1;

    var_v1 = D_8017FF38;
    var_v0_2 = D_8017FF38 + 4;
    if (var_v1 != 0) {
loop_2:
        if (D_800B9A08 != var_v1) {
            var_v1 = *var_v0_2;
            var_v0_2 += 4;
            if (var_v1 == 0) {
                goto block_4;
            }
            goto loop_2;
        }
        goto block_7;
    }
block_4:
    var_v0 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0x44) & 0x400)) {
        var_v0 = 0;
        if (M2C_FIELD(arg0, s16 *, 0x1C8) == 0) {
            var_v0 = 1;
            if (!(M2C_FIELD(arg0, u16 *, 0xAC) & 0x100)) {
block_7:
                return 0;
            }
            M2C_FIELD(&D_80078E78, u8 *, 0x48) = (u8) (M2C_FIELD(&D_80078E78, u8 *, 0x48) ^ 0x80);
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return var_v0;
        }
    }
    return var_v0;
}
