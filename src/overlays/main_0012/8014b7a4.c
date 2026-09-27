/* Overlay range [8014B7A4,8014B944) from MAIN.CD member 0012.
 * SHA256(span)=b6f5748aa24628c122d0a8652caacc1d5292d78a97b8b30a1e0d9ba4ec574210.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
void func_8014B944(void *, s32, s32);    /* static */
s32 func_8016F1C4();                                /* static */
extern s32 *D_80078E78;
extern s32 D_80078EA4;
extern s32 *D_800AF630;
extern s16 D_800B9A08;

void func_8014B7A4(void *arg0) {
    s32 var_a1;
    s32 temp_v1_2;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_v1;

    if (func_8016F1C4() == 0) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0);
        if ((temp_v1 != 0x1E) && (temp_v1 != 0x1A)) {
            temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x44);
            if (!(temp_v1_2 & 0x10)) {
                if (temp_v1_2 & 0x80) {
                    if (func_80029178(0x1B) & 0xFF) {
                        var_a1 = 0x2D80;
                    } else {
                        var_a1 = 0x16C0;
                    }
                    func_8014B944(arg0, var_a1, 0);
                } else if ((D_800B9A08 != 0x3024) && (D_800B9A08 != 0x3042) && (D_800B9A08 != 0x3067) && (D_800B9A08 != 0x3075)) {
                    if (func_80029178(0x21) & 0xFF) {
                        var_v0 = D_80078EA4 - 0xF2;
                    } else {
                        var_v0 = D_80078EA4 - 0x16C;
                    }
                    D_80078EA4 = var_v0;
                }
                if (M2C_FIELD(&D_80078E78, s32 *, 0x2C) < 0) {
                    M2C_FIELD(&D_80078E78, s32 *, 0x2C) = 0;
                    if (M2C_FIELD(arg0, s32 *, 0x44) & 0x80) {
                        var_v0_2 = M2C_FIELD(&D_80078E78, s32 *, 0x30) + 0xAAA8;
                    } else {
                        var_v0_2 = M2C_FIELD(&D_80078E78, s32 *, 0x30) + 0x1555;
                    }
                    M2C_FIELD(&D_80078E78, s32 *, 0x30) = var_v0_2;
                    if (M2C_FIELD(&D_80078E78, s16 *, 0x32) >= 0x3C) {
                        M2C_FIELD(&D_80078E78, s32 *, 0x30) = 0;
                        if (M2C_FIELD(&D_800AF630, s16 *, 0xA3D8) != 0x3051) {
                            M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 0x100);
                        }
                    }
                }
            }
        }
    }
}
