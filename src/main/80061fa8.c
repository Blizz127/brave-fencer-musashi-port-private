/* Main-exec range [80061FA8,80062144) from the SLUS executable.
 * SHA256(span)=2a0508db5cbe6784a6e51ffa78074cde66840dca6eea04ac085e7946915486fd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80062144;
s32 func_8005C4DC(s32, u8 *);                       /* static */
s32 func_80062248(s8 *, s32);                         /* static */
extern s32 D_80078CD8;
extern u8 D_80078CE0;

s32 func_80061FA8(s8 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_v1_2;
    s8 *var_v1;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_s0;
    u32 var_s0_2;
    u8 *var_a0;
    u8 temp_v0;

    var_a0 = &D_80078CE0;
    var_v1 = arg0;
    if (*arg0 >= 0x3B) {
        do {
            temp_v0 = *var_v1;
            var_v1 += 1;
            *var_a0 = temp_v0;
            var_a0 += 1;
        } while (*var_v1 >= 0x3B);
    }
    *var_a0 = 0;
    var_s0 = *(u32 *)0x150;
    temp_v1 = var_s0 + ((*(s32 *)0x154 / 80) * 0x50);
    if (var_s0 < temp_v1) {
loop_4:
        temp_a0 = var_s0->unk0;
        if ((temp_a0 == 0) || (func_8005C4DC(temp_a0, &D_80078CE0) != 0)) {
            var_s0 += 0x50;
            if (var_s0 >= temp_v1) {
                goto block_7;
            }
            goto loop_4;
        }
        D_80078CD8 = var_s0->unk34;
        var_v1_2 = 1;
    } else {
block_7:
        var_v1_2 = 0;
    }
    if (var_v1_2 == 0) {
        return 0;
    }
    var_s0_2 = *(void *)0x150;
    temp_v1_2 = var_s0_2 + ((*(void *)0x154 / 80) * 0x50);
    if (var_s0_2 < temp_v1_2) {
loop_14:
        temp_a0_2 = var_s0_2->unk0;
        if ((temp_a0_2 == 0) || (func_8005C4DC(temp_a0_2, &D_80078CE0) != 0)) {
            var_s0_2 += 0x50;
            if (var_s0_2 < temp_v1_2) {
                goto loop_14;
            }
        } else {
            var_s0_2->unk34 = &D_80062144;
        }
    }
    return func_80062248(arg0, arg1);
}
