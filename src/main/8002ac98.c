/* Main-exec range [8002AC98,8002AE60) from the SLUS executable.
 * SHA256(span)=6486f3e5c60efab611ca2ba456ef578c3bb9c885ec65d93f558a259cbaca869f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800291B4(s32);                             /* static */
s32 func_8005C49C();                                /* static */
extern u8 D_80078EBA;
extern s32 *D_800A6588;
extern s32 *D_8010F46C;

void func_8002AC98(void) {
    s16 temp_a2;
    s16 var_s3;
    s16 var_v0_2;
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;

    var_s2 = saved_reg_s2;
    if (D_80078EBA == 0) {
        var_s3 = 0;
        var_v0 = 0 << 0x10;
        do {
            temp_s1 = var_v0 >> 0x10;
            temp_s0 = func_800291B4(temp_s1 + 0x63) & 0xF;
            var_v0_2 = var_s3 + 1;
            if (temp_s0 != 0) {
                temp_v1 = func_8005C49C() & 0x1F;
                if (temp_s0 != 2) {
                    if (temp_s0 < 3) {
                        if (temp_s0 != 1) {
                            var_v0_3 = var_s3 << 0x10;
                        } else {
                            if ((temp_v1 == 0) || (var_v0_4 = temp_s1 * 2, (temp_v1 == 0xB))) {
                                var_s2 = (s32) (*(((s32) (var_s3 << 0x10) >> 0xF) + &D_800A6588) << 0x10) >> 0x11;
                            } else {
                                goto block_16;
                            }
                            goto block_18;
                        }
                    } else if (temp_s0 != 3) {
                        var_v0_3 = var_s3 << 0x10;
                    } else {
                        if (temp_v1 != 0) {
                            var_v0_4 = temp_s1 * 2;
                            if (temp_v1 != 0xB) {
                                goto block_16;
                            }
                        }
                        var_s2 = *(((s32) (var_s3 << 0x10) >> 0xF) + &D_800A6588) * 2;
                        goto block_18;
                    }
                } else {
                    var_v0_3 = var_s3 << 0x10;
                    if (temp_v1 != 0) {
                        var_v0_4 = temp_s1 * 2;
block_16:
                        var_s2 = temp_v1 + (*(var_v0_4 + &D_800A6588) - 0xB);
block_18:
                        var_v0_3 = var_s3 << 0x10;
                    }
                }
                temp_a0 = var_v0_3 >> 0x10;
                temp_a2 = *(&D_8010F46C + ((temp_a0 + 1) * 8));
                if ((s16) var_s2 < temp_a2) {
                    *((temp_a0 * 2) + &D_800A6588) = temp_a2;
                } else {
                    temp_v0 = temp_a0 * 2;
                    if ((temp_a2 * 4) < (s16) var_s2) {
                        *(temp_v0 + &D_800A6588) = temp_a2 * 4;
                    } else {
                        *(temp_v0 + &D_800A6588) = (s16) var_s2;
                    }
                }
                var_v0_2 = var_s3 + 1;
            }
            var_s3 = var_v0_2;
            var_v0 = var_s3 << 0x10;
        } while (var_v0_2 < 0x40);
    }
}
