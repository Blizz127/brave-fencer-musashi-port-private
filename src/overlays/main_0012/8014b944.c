/* Overlay range [8014B944,8014BB0C) from MAIN.CD member 0012.
 * SHA256(span)=52641c4e5ddf6da66af09b88dd47eb697b9b96f1029adaeafa1fb3c7226566e3.
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
extern s32 D_80078EA4;
extern s16 D_80078EA6;

void func_8014B944(s32 arg1, s32 arg2) {
    s32 var_v0;

    if (arg2 != 0) {
        D_80078EA4 += arg1;
        var_v0 = 0xA00000;
        if (D_80078EA6 >= 0xA1) {
            goto block_8;
        }
    } else if (func_80029178(0x1B) & 0xFF) {
        D_80078EA4 += arg1;
        var_v0 = 0xA00000;
        if (D_80078EA6 >= 0xA1) {
            goto block_8;
        }
    } else if (D_80078EA6 < 0x80) {
        D_80078EA4 += arg1;
        var_v0 = 0x800000;
        if (D_80078EA6 >= 0x81) {
block_8:
            D_80078EA4 = var_v0;
        }
    }
    if (arg2 != 0) {
        M2C_FIELD(&D_80078E78, s32 *, 0x60) = (s32) (M2C_FIELD(&D_80078E78, s32 *, 0x60) + arg1);
        if (M2C_FIELD(&D_80078E78, s16 *, 0x62) >= 0xA1) {
            M2C_FIELD(&D_80078E78, s32 *, 0x60) = 0xA00000;
        }
    } else if (func_80029178(0x1B) & 0xFF) {
        M2C_FIELD(&D_80078E78, s32 *, 0x60) = (s32) (M2C_FIELD(&D_80078E78, s32 *, 0x60) + arg1);
        if (M2C_FIELD(&D_80078E78, s16 *, 0x62) >= 0xA1) {
            M2C_FIELD(&D_80078E78, s32 *, 0x60) = 0xA00000;
        }
    } else if (M2C_FIELD(&D_80078E78, s16 *, 0x62) < 0x80) {
        M2C_FIELD(&D_80078E78, s32 *, 0x60) = (s32) (M2C_FIELD(&D_80078E78, s32 *, 0x60) + arg1);
        if (M2C_FIELD(&D_80078E78, s16 *, 0x62) >= 0x81) {
            M2C_FIELD(&D_80078E78, s32 *, 0x60) = 0x800000;
        }
    }
}
