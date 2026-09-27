/* Main-exec range [80056F18,80057094) from the SLUS executable.
 * SHA256(span)=ffe902702687804447e1ebd9230ec77755e7d752c7e80417d8c356bc201314c2.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073E50;
void func_8005C604(s32 (*)(), u32);          /* static */

void func_80056F18(s32 arg0, void *arg1, s32 arg2) {
    s16 var_s2;
    s32 temp_v1;
    s32 var_v0;
    u32 *var_s0;
    u32 *var_s5;
    u32 temp_a0_2;
    u32 temp_s6;
    u32 temp_v0;
    u32 var_s1;
    u32 var_s3;
    u32 var_s4;
    void *temp_a0;

    var_s3 = 0;
    var_s1 = 0;
    var_s4 = 0;
    var_s2 = 0;
    temp_a0 = arg0 + (arg2 * 0x1C);
    M2C_FIELD(arg1, void **, 8) = temp_a0;
    var_s0 = M2C_FIELD(temp_a0, u32 **, 0x10);
    temp_s6 = M2C_FIELD(temp_a0, u32 *, 0x14);
    var_s5 = var_s0;
    if (temp_s6 != 0) {
        do {
            temp_v0 = *var_s0;
            temp_a0_2 = var_s1;
            temp_v1 = var_s3 & 0xFF;
            var_s3 = temp_v0 >> 0x18;
            var_s1 = temp_v0 >> 0x10;
            if (temp_v1 != 0) {
                if ((var_s3 != temp_v1) || (var_v0 = var_s3 & 0xFD, ((var_s1 & 0xFF) != (temp_a0_2 & 0xFF)))) {
                    *var_s5 = var_s2;
                    var_s2 = 0;
                    var_s5 = var_s0;
                    goto block_5;
                }
            } else {
block_5:
                var_v0 = var_s3 & 0xFD;
            }
            switch (var_v0) {
            case 0x20:
                if (var_s1 & 4) {
                case 0x24:
                case 0x31:
block_9:
                    var_s0 += 0x18;
                } else {
                case 0x21:
                case 0x29:
                    var_s0 += 0x10;
                }
                break;
            case 0x30:
                if (var_s1 & 4) {
                case 0x25:
                case 0x34:
                case 0x39:
                    var_s0 += 0x1C;
                } else {
block_14:
                    var_s0 += 0x14;
                }
                break;
            case 0x28:
                if (var_s1 & 4) {
                case 0x2C:
                case 0x2D:
                    var_s0 += 0x20;
                } else {
                    goto block_14;
                }
                break;
            case 0x3D:
                var_s0 += 0x2C;
                break;
            case 0x38:
                if (var_s1 & 4) {
                case 0x35:
                case 0x3C:
                    var_s0 += 0x24;
                } else {
                    goto block_9;
                }
                break;
            default:
                func_8005C604(D_80073E50, var_s3);
                break;
            }
            var_s4 += 1;
            var_s2 += 1;
        } while (var_s4 < temp_s6);
    }
    *var_s5 = var_s2;
}
