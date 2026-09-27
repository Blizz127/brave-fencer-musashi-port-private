/* Overlay range [8014C6F4,8014C860) from MAIN.CD member 0012.
 * SHA256(span)=d32599df553d6b756106898c2cbcbb8ab3a14a98d506da6a533bd1d406033a9a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(u16 *, void *);                     /* extern */
s32 func_8016F1AC();                               /* static */
extern s32 D_80078E78;
extern u16 D_8011F9D0;

void func_8014C6F4(void *arg0) {
    s32 temp_a0;
    s32 temp_v1;
    u16 *temp_v1_2;
    u16 *var_a0;
    u16 *var_a0_2;
    u16 *var_v0;

    if (arg0->unk44 & 2) {
        arg0->unk1C3 = 1U;
    }
    temp_v1 = arg0->unk44;
    if ((temp_v1 ^ arg0->unk48) & temp_v1 & 0x200) {
        arg0->unk1C3 = 0U;
    }
    temp_a0 = M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    arg0->unk167 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    arg0->unk16B = (unaligned s32) temp_a0;
    if ((func_8016F1AC(temp_a0) != 0) || ((arg0->unk44 & 0x200) && (arg0->unk1C3 == 0))) {
        arg0->unk162 = 1;
    } else {
        if (D_80078E78.unk49 == 0x17) {
            var_a0 = &D_8011F9D0;
            temp_v1_2 = &D_8011F9D0 + 0xC30;
            if ((u32) &D_8011F9D0 < (u32) temp_v1_2) {
loop_10:
                var_v0 = var_a0;
                if (*var_a0 != 0x22) {
                    var_a0 += 0x68;
                    if ((u32) var_a0 >= (u32) temp_v1_2) {
                        goto block_12;
                    }
                    goto loop_10;
                }
            } else {
block_12:
                var_v0 = 0;
            }
            var_a0_2 = var_v0 + 4;
            if (var_v0 == 0) {
                goto block_14;
            }
            goto block_15;
        }
block_14:
        var_a0_2 = arg0 + 4;
        if (arg0->unk0 != 0x19) {
block_15:
            func_80015978(var_a0_2, arg0 + 0x15C);
        }
        arg0->unk162 = 0;
    }
    if (arg0->unk15A == 0) {
        arg0->unk154 = (u16) arg0->unk6;
        arg0->unk156 = (u16) arg0->unkA;
        arg0->unk158 = (u16) arg0->unkE;
    }
    arg0->unk15A = 0;
}
