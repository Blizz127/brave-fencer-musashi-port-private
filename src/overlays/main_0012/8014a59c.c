/* Overlay range [8014A59C,8014A638) from MAIN.CD member 0012.
 * SHA256(span)=76c429ebbaab223fc884191c260f9b1f094fa8f8720875b22cd3dd0380b542e5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
extern u8 D_80078EBF;

void func_8014A59C(void *arg0) {
    s32 var_v1;
    u8 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x44) & 1) {
        if (M2C_FIELD(arg0, u16 *, 0xAA) & 8) {
            var_v1 = 3;
            if (func_80029178(0x20) & 0xFF) {
                var_v1 = 6;
            }
            temp_v0 = D_80078EBF + var_v1;
            D_80078EBF = temp_v0;
            if ((u32) (temp_v0 & 0xFF) >= 0x81U) {
                D_80078EBF = 0x80;
            }
        }
    } else {
        D_80078EBF = 0;
    }
}
