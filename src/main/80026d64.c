/* Main-exec range [80026D64,80027058) from the SLUS executable.
 * SHA256(span)=ff46bad029d055eb59fe44ee85573a465c755efe108a961f0c557aab615b1dc3.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80027058(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_80027200(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_800273F4(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_800275BC(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_800277DC(u32 *, s32, s32, s32, s32, s32, s32); /* static */
s32 func_800279AC(u32 *, s32, s32, s32, s32, s32, s32); /* static */
extern s32 D_800A5E60;

void func_80026D64(void *arg0, void *arg1, s32 arg2) {
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 var_s1;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_v0_4;
    u16 temp_v0_5;
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
            temp_v0_3 = (temp_v0_2 >> 0x18) & 0xFD;
            temp_v1 = (temp_v0_2 >> 0x10) & 4;
            switch (temp_v0_3) {
            case 0x20:
                if (temp_v1 != 0) {
                    D_800A5E60 = func_800273F4(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v1_2 = (u16) *var_s0;
                    var_s1 -= temp_v1_2;
                    var_v0 = temp_v1_2 * 0x18;
                } else {
                    D_800A5E60 = func_80027058(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v0_4 = (u16) *var_s0;
                    var_s1 -= temp_v0_4;
                    var_v0 = temp_v0_4 * 0x10;
                }
block_18:
                var_s0 += var_v0;
                break;
            case 0x28:
                if (temp_v1 != 0) {
                    var_v0_2 = func_800275BC(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
block_16:
                    D_800A5E60 = var_v0_2;
                case 0x2C:
                    temp_v0_5 = (u16) *var_s0;
                    var_s1 -= temp_v0_5;
                    var_v0 = temp_v0_5 << 5;
                } else {
                    D_800A5E60 = func_80027200(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                    temp_v1_3 = (u16) *var_s0;
                    var_s1 -= temp_v1_3;
                    var_v0 = temp_v1_3 * 0x14;
                }
                goto block_18;
            case 0x24:
                temp_v1_4 = (u16) *var_s0;
                var_s1 -= temp_v1_4;
                var_v0 = temp_v1_4 * 0x18;
                goto block_18;
            case 0x30:
                temp_v1_5 = (u16) *var_s0;
                var_s1 -= temp_v1_5;
                var_v0 = temp_v1_5 * 0x14;
                goto block_18;
            case 0x38:
                temp_v1_6 = (u16) *var_s0;
                var_s1 -= temp_v1_6;
                var_v0 = temp_v1_6 * 0x18;
                goto block_18;
            case 0x34:
                temp_v1_7 = (u16) *var_s0;
                var_s1 -= temp_v1_7;
                var_v0 = temp_v1_7 * 0x1C;
                goto block_18;
            case 0x3C:
                temp_v1_8 = (u16) *var_s0;
                var_s1 -= temp_v1_8;
                var_v0 = temp_v1_8 * 0x24;
                goto block_18;
            case 0x25:
                D_800A5E60 = func_800277DC(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                temp_v1_9 = (u16) *var_s0;
                var_s1 -= temp_v1_9;
                var_v0 = temp_v1_9 * 0x1C;
                goto block_18;
            case 0x2D:
                var_v0_2 = func_800279AC(var_s0, temp_s3, temp_s2, D_800A5E60, (s32) (u16) *var_s0, arg2, M2C_FIELD(arg1, s32 *, 4));
                goto block_16;
            }
        } while (var_s1 != 0);
    }
}
