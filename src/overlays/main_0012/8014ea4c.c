/* Overlay range [8014EA4C,8014ED28) from MAIN.CD member 0012.
 * SHA256(span)=9861e52193c782169f6e4e90795065f0e1492c5c50b90b2380eb6e4b315a22a2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135A4C(s32, s32, void *, void *);        /* static */
extern u16 D_800B99DA;
extern s32 D_801150D8;
extern s16 D_801152AA;
extern u16 D_801202A0;
extern s16 D_80126720;
extern s16 D_80126724;

s32 func_8014EA4C(void *arg0, void *arg1, void *arg2) {
    s16 temp_v1_2;
    s16 temp_v1_3;
    s16 var_v0_4;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_v0;
    u16 *var_s2;
    u16 *var_s3;
    u16 var_v0_2;
    u16 var_v0_3;
    u16 var_v0_5;
    u16 var_v0_6;
    u32 temp_v1;

    var_s6 = 0;
    var_s5 = 8;
    temp_v1 = (u32) (D_800B99DA & 0x60) >> 5;
    var_s4 = 8;
    if ((s32) temp_v1 >= 0) {
        if ((s32) temp_v1 >= 2) {
            if (temp_v1 != 2) {

            } else {
                var_s4 = 7;
            }
        } else {
            var_s5 = 7;
        }
    }
    var_s3 = &D_801202A0;
    var_v0 = 0;
    if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
        var_s2 = &D_801202A0 + 0x58;
        do {
            if ((*var_s3 != 0) && (M2C_FIELD(var_s2, s32 *, 0) != 0) && (var_s3 != M2C_FIELD(arg0, s32 *, 0x178)) && (var_s3 != M2C_FIELD(arg0, s32 *, 0x174)) && (M2C_FIELD(var_s2, s32 *, 4) & 0x1800)) {
                D_801150D8 = 0;
                if (func_80135A4C(M2C_FIELD(var_s2, s32 *, -0x38), M2C_FIELD(var_s2, s32 *, 0), arg1, arg2) != 0) {
                    if (D_801150D8 & 1) {
                        if (!((u16) M2C_FIELD(var_s2, s32 *, 4) & 0x10)) {
                            if ((D_80126720 - M2C_FIELD(arg1, s16 *, 0)) >= 0) {
                                var_v0_2 = M2C_FIELD(arg2, u16 *, 0) - var_s5;
                            } else {
                                var_v0_2 = M2C_FIELD(arg2, u16 *, 0) + var_s5;
                            }
                            M2C_FIELD(arg0, u16 *, 6) = var_v0_2;
                            if ((D_80126724 - M2C_FIELD(arg1, s16 *, 4)) >= 0) {
                                var_v0_3 = M2C_FIELD(arg2, u16 *, 4) - var_s4;
                            } else {
                                var_v0_3 = M2C_FIELD(arg2, u16 *, 4) + var_s4;
                            }
                            M2C_FIELD(arg0, u16 *, 0xE) = var_v0_3;
                        }
                        var_s6 |= 2;
                    } else {
                        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg2, u16 *, 0);
                        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg2, u16 *, 2) + 0x10);
                        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg2, u16 *, 4);
                        var_s6 |= 1;
                        if (M2C_FIELD(var_s2, s32 *, 0) < 0) {
                            var_v0_4 = D_801152AA;
                            if (var_v0_4 < 0) {
                                var_v0_4 = -var_v0_4;
                            }
                            if (var_v0_4 >= 0x801) {
                                temp_v1_2 = (s16) M2C_FIELD(arg2, u16 *, 0);
                                if ((D_80126720 - temp_v1_2) >= 0) {
                                    var_v0_5 = temp_v1_2 - var_s5;
                                } else {
                                    var_v0_5 = temp_v1_2 + var_s5;
                                }
                                M2C_FIELD(arg0, u16 *, 6) = var_v0_5;
                                temp_v1_3 = (s16) M2C_FIELD(arg2, u16 *, 4);
                                if ((D_80126724 - temp_v1_3) >= 0) {
                                    var_v0_6 = temp_v1_3 - var_s4;
                                } else {
                                    var_v0_6 = temp_v1_3 + var_s4;
                                }
                                M2C_FIELD(arg0, u16 *, 0xE) = var_v0_6;
                            }
                        }
                    }
                }
            }
            var_s3 += 0x10C;
            var_s2 += 0x10C;
        } while ((u32) var_s3 < (u32) &D_80126720);
        var_v0 = var_s6;
    }
    return var_v0;
}
