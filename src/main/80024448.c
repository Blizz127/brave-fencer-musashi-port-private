/* Main-exec range [80024448,800249F0) from the SLUS executable.
 * SHA256(span)=ff81ac9b9f82924653a5474d03f75218cfb73158612272926d93e719bd569e71.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800249F0(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80024BC0(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80024DE8(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80025000(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_8002528C(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80025504(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80025818(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80025A30(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80025CBC(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80025EB8(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80026128(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_800262D8(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80026514(u32 *, s32, s32, s32, s32, s32, s32, s32); /* static */
s32 func_800268D0(u32 *, s32, s32, s32, s32, s32, s32, s32); /* static */
extern s32 D_80078D88;
extern s32 D_800A5E60;

void func_80024448(void *arg0, void *arg1, s32 arg2) {
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v0_6;
    u16 temp_v1_10;
    u16 temp_v1_11;
    u16 temp_v1_12;
    u16 temp_v1_13;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u16 temp_v1_8;
    u16 temp_v1_9;
    u32 *var_s0;
    u32 temp_v0_2;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 8);
    var_s0 = M2C_FIELD(temp_v0, u32 **, 0x10);
    var_s1 = M2C_FIELD(temp_v0, s32 *, 0x14);
    temp_s3 = M2C_FIELD(temp_v0, s32 *, 0);
    temp_s2 = M2C_FIELD(temp_v0, s32 *, 8);
    if (var_s1 != 0) {
        do {
            temp_v0_2 = *var_s0;
            temp_v0_3 = (temp_v0_2 >> 0x18) & 0xFC;
            temp_v1 = (temp_v0_2 >> 0x10) & 4;
            switch (temp_v0_3) {
            case 0x20:
                if (temp_v1 != 0) {
                    D_800A5E60 = func_80024DE8(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v1_2 = (u16) *var_s0;
                    var_s1 -= temp_v1_2;
                    var_v0 = temp_v1_2 * 0x18;
                } else {
                    D_800A5E60 = func_800249F0(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v0_4 = (u16) *var_s0;
                    var_s1 -= temp_v0_4;
                    var_v0 = temp_v0_4 * 0x10;
                }
block_30:
                var_s0 += var_v0;
                break;
            case 0x28:
                if (temp_v1 != 0) {
                    D_800A5E60 = func_80025000(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v0_5 = (u16) *var_s0;
                    var_s1 -= temp_v0_5;
                    var_v0 = temp_v0_5 << 5;
                } else {
                    D_800A5E60 = func_80024BC0(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v1_3 = (u16) *var_s0;
                    var_s1 -= temp_v1_3;
                    var_v0_2 = temp_v1_3 * 4;
block_28:
                    var_v0_3 = var_v0_2 + (u16) *var_s0;
block_29:
                    var_v0 = var_v0_3 * 4;
                }
                goto block_30;
            case 0x24:
                D_800A5E60 = func_80025CBC(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                temp_v1_4 = (u16) *var_s0;
                var_s1 -= temp_v1_4;
                var_v0 = temp_v1_4 * 0x18;
                goto block_30;
            case 0x2C:
                D_800A5E60 = func_80025EB8(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                temp_v0_6 = (u16) *var_s0;
                var_s1 -= temp_v0_6;
                var_v0 = temp_v0_6 << 5;
                goto block_30;
            case 0x30:
                if (temp_v1 != 0) {
                    D_800A5E60 = func_80025818(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v1_5 = (u16) *var_s0;
                    var_s1 -= temp_v1_5;
                    var_v0_3 = temp_v1_5 * 7;
                } else {
                    if (D_80078D88 & 0x10000) {
                        D_800A5E60 = func_80026514(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4), 0);
                        temp_v1_6 = (u16) *var_s0;
                        var_s1 -= temp_v1_6;
                        var_v0_2 = temp_v1_6 * 4;
                    } else if (D_80078D88 & 0x20000) {
                        D_800A5E60 = func_80026514(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4), 1);
                        temp_v1_7 = (u16) *var_s0;
                        var_s1 -= temp_v1_7;
                        var_v0_2 = temp_v1_7 * 4;
                    } else {
                        D_800A5E60 = func_8002528C(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                        temp_v1_8 = (u16) *var_s0;
                        var_s1 -= temp_v1_8;
                        var_v0_2 = temp_v1_8 * 4;
                    }
                    goto block_28;
                }
                goto block_29;
            case 0x38:
                if (temp_v1 != 0) {
                    var_v0_4 = func_80025A30(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
block_27:
                    D_800A5E60 = var_v0_4;
                    temp_v1_9 = (u16) *var_s0;
                    var_s1 -= temp_v1_9;
                    var_v0_2 = temp_v1_9 * 8;
                    goto block_28;
                }
                if (D_80078D88 & 0x10000) {
                    D_800A5E60 = func_800268D0(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4), 0);
                    temp_v1_10 = (u16) *var_s0;
                    var_s1 -= temp_v1_10;
                    var_v0 = temp_v1_10 * 0x18;
                } else if (D_80078D88 & 0x20000) {
                    D_800A5E60 = func_800268D0(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4), 1);
                    temp_v1_11 = (u16) *var_s0;
                    var_s1 -= temp_v1_11;
                    var_v0 = temp_v1_11 * 0x18;
                } else {
                    D_800A5E60 = func_80025504(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v1_12 = (u16) *var_s0;
                    var_s1 -= temp_v1_12;
                    var_v0 = temp_v1_12 * 0x18;
                }
                goto block_30;
            case 0x34:
                D_800A5E60 = func_80026128(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                temp_v1_13 = (u16) *var_s0;
                var_s1 -= temp_v1_13;
                var_v0_3 = temp_v1_13 * 7;
                goto block_29;
            case 0x3C:
                var_v0_4 = func_800262D8(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                goto block_27;
            }
        } while (var_s1 != 0);
    }
}
