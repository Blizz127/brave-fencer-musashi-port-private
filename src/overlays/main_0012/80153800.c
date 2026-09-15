/* Overlay range [80153800,80153978) from MAIN.CD member 0012.
 * SHA256(span)=ccd049fe8f32081141aa0447ee97b9355e7c6abf9791397cec365d3a6a4cf4fa.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800139C8(s32, u16 *, u16 *);                 /* extern */
void func_80015954(void *, void *);                       /* extern */
void func_80015978(s32, s32);                          /* extern */
s32 func_80153978(void *, s16 *);                   /* static */
extern s32 D_8011DB28;
extern s32 *D_80126DB0;
extern u16 D_80126DB6;

s32 func_80153800(void *arg0) {
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    u16 sp14;
    s16 sp12;
    u16 sp10;
    s32 var_a0;
    s32 var_s0;
    u16 temp_v1_2;
    u8 temp_v1;

    if (D_8011DB28 != 0) {
        func_80015978(arg0 + 4, arg0 + 0x88);
        arg0->unk93 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk97 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        goto block_2;
    }
    temp_v1 = arg0->unkDE;
    temp_v1_2 = temp_v1 * 4;
    if (temp_v1 >= 0x21U) {
        func_80015954(&D_80126DB0, arg0 + 4);
        arg0->unk8B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk8F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk93 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk97 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk20->unk12 = (u16) D_80126DB6;
        return 0;
    }
    var_s0 = 0;
    sp1A = arg0->unkA2 - temp_v1_2;
    var_a0 = 0 << 0x15;
loop_6:
    sp10 = 0;
    sp12 = 0;
    sp14 = temp_v1_2;
    func_800139C8(var_a0 >> 0x10, &sp10, &sp10);
    sp18 = arg0->unkA0 + sp10;
    sp1C = arg0->unkA4 + sp14;
    var_s0 += 1;
    if (func_80153978(arg0, &sp18) != 0) {
        var_a0 = var_s0 << 0x15;
        if (var_s0 >= 0x80) {
            arg0->unkDE = (u8) (arg0->unkDE + 1);
            return 1;
        }
        goto loop_6;
    }
block_2:
    return 0;
}
