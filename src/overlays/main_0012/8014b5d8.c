/* Overlay range [8014B5D8,8014B6F0) from MAIN.CD member 0012.
 * SHA256(span)=89f6bbaae7e07b248c0ae0fffe56c216c3c47107d339882a8bf392f04e096554.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
void func_8014BC80(void *, s32);             /* static */
s32 func_8016F1C4();                                /* static */
extern s32 *D_80078E78;

void func_8014B5D8(void *arg0) {
    s32 temp_v0;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_v0;
    u16 temp_v1;

    if ((func_8016F1C4() == 0) && (temp_v1 = M2C_FIELD(arg0, u16 *, 0), (temp_v1 != 0x1E)) && (temp_v1 != 0x1A) && (temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x44), ((temp_v1_2 & 0x10) == 0))) {
        var_a0 = 0x16C;
        if (temp_v1_2 & 0x80) {
            var_a0 = 0x5B0;
            if (func_80029178(0x1B) & 0xFF) {
                var_a0 = 0x2D8;
            }
        }
        if (M2C_FIELD(&D_80078E78, u8 *, 0x49) == 0x12) {
            var_a0 *= 2;
        }
        temp_v0 = M2C_FIELD(&D_80078E78, s32 *, 0x24) - var_a0;
        M2C_FIELD(&D_80078E78, s32 *, 0x24) = temp_v0;
        if (temp_v0 < 0) {
            M2C_FIELD(&D_80078E78, s32 *, 0x24) = 0;
            if (M2C_FIELD(arg0, s32 *, 0x44) & 0x80) {
                var_v0 = M2C_FIELD(&D_80078E78, s32 *, 0x28) + 0xAAA8;
            } else {
                var_v0 = M2C_FIELD(&D_80078E78, s32 *, 0x28) + 0x1555;
            }
            M2C_FIELD(&D_80078E78, s32 *, 0x28) = var_v0;
            if (M2C_FIELD(&D_80078E78, s16 *, 0x2A) >= 0x3C) {
                M2C_FIELD(&D_80078E78, s32 *, 0x28) = 0;
                func_8014BC80(arg0, 4);
            }
        } else {
            M2C_FIELD(&D_80078E78, s32 *, 0x28) = 0;
            M2C_FIELD(&D_80078E78, s8 *, 0x43) = 0;
        }
    }
}
