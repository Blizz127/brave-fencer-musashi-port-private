/* Overlay range [8014A850,8014AA04) from MAIN.CD member 0012.
 * SHA256(span)=8459524c2e114a2e55532fbb540adc832fa50ba25c1b5129af84e4ae1ed3f4ef.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(void *, void *, u32);      /* extern */
s32 func_80029AF4();                                /* extern */
void func_8014C4AC(void *, s32, s32, void *, s32); /* static */
extern s32 *D_801202A0;

s32 func_8014A850(void *arg0) {
    s16 sp26;
    s32 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 temp_a0;
    s32 var_a1;
    u32 var_a2;
    void *temp_s0;
    void *var_a0;

    var_a2 = 0;
    var_a1 = 0;
loop_1:
    temp_s0 = var_a1 + &D_801202A0;
    if ((M2C_FIELD(temp_s0, u16 *, 0) != 0) && (M2C_FIELD(temp_s0, s32 *, 0x58) != 0) && (M2C_FIELD(temp_s0, u16 *, 0x5C) & 0x8000) && (M2C_FIELD(temp_s0, u8 *, 0xC1) == 7)) {
        temp_a0 = M2C_FIELD(arg0, u16 *, 6) - M2C_FIELD(temp_s0, u16 *, 6);
        sp18 = temp_a0;
        sp1A = M2C_FIELD(arg0, u16 *, 0xA) - (M2C_FIELD(temp_s0, u16 *, 0xA) + 0x40);
        sp1C = M2C_FIELD(arg0, u16 *, 0xE) - M2C_FIELD(temp_s0, u16 *, 0xE);
        if (temp_a0 >= 0) {
            if (temp_a0 >= 0x40) {
                var_a2 += 1;
                goto block_19;
            }
            goto block_9;
        }
        if (-temp_a0 < 0x40) {
block_9:
            if (sp1C >= 0) {
                if (sp1C >= 0x40) {
                    var_a2 += 1;
                    goto block_19;
                }
                goto block_13;
            }
            if (-sp1C < 0x40) {
block_13:
                if (sp1A >= 0) {
                    var_a0 = arg0 + 4;
                    if (sp1A >= 0x40) {
                        var_a2 += 1;
                        goto block_19;
                    }
                    goto block_17;
                }
                var_a0 = arg0 + 4;
                if (-sp1A < 0x40) {
block_17:
                    M2C_FIELD(arg0, void **, 0x18C) = temp_s0;
                    func_80015978(var_a0, &sp20, var_a2);
                    sp26 = 0;
                    func_8014C4AC(temp_s0, 0x1B, func_80029AF4(), &sp20, (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12));
                    return 1;
                }
                goto block_18;
            }
            goto block_18;
        }
        goto block_18;
    }
block_18:
    var_a2 += 1;
block_19:
    var_a1 += 0x10C;
    if (var_a2 >= 0x60U) {
        return 0;
    }
    goto loop_1;
}
