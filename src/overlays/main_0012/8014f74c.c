/* Overlay range [8014F74C,8014FA04) from MAIN.CD member 0012.
 * SHA256(span)=ce0f359ad05ded980e5a6df6c82bd82232897bf5fd7ae54be00aec95176765d0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                               /* extern */
s32 func_80133784(s32, u16 *, u16 *);                 /* static */
extern s32 D_801152B0;
extern s32 D_801152BC;

s32 func_8014F74C(void *arg0) {
    u16 sp24;
    u16 sp22;
    u16 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 var_s1;
    s32 var_v0;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_v1;

    sp10 = arg0->unk88;
    sp12 = arg0->unk8A;
    sp14 = arg0->unk8C;
    temp_v1 = arg0->unk6;
    sp20 = temp_v1;
    sp18 = temp_v1;
    temp_a0 = arg0->unkA;
    sp22 = temp_a0;
    sp1A = temp_a0;
    temp_a1 = arg0->unkE;
    sp24 = temp_a1;
    sp1C = temp_a1;
    if (arg0->unk146 != 0) {
        sp18 = temp_v1 + arg0->unk140;
        sp1A = temp_a0 + arg0->unk142;
        sp1C = temp_a1 + arg0->unk144;
    }
    var_s1 = func_80133784(0, &sp10, &sp18);
    if (var_s1 != 0) {
        arg0->unk6 = sp18;
        arg0->unkA = sp1A;
        arg0->unkE = sp1C;
        if (sp1E != 0) {
            arg0->unk16C = (u16) sp1E;
        }
        arg0->unk16E = (s16) ((u16) sp1E >> 0xD);
        if (var_s1 == 0x2000) {
            arg0->unk123 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            arg0->unk127 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        } else if (var_s1 == 0x4000) {
            arg0->unk123 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
            arg0->unk127 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        }
        var_v0 = var_s1;
        if (arg0->unk16C == 0x1D) {
            if (!(func_80029178(0x21) & 0xFF)) {
                var_s1 = (var_s1 & ~0x2000) | 0x4000;
                D_801152B0.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                D_801152B0.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                D_801152BC = 1;
            }
            return var_s1;
        }
        /* Duplicate return node #23. Try simplifying control flow for better match */
        return var_v0;
    }
    arg0->unk123 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    arg0->unk127 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    if (sp1E != 0) {
        arg0->unk16C = (u16) sp1E;
    }
    if ((s16) sp10 == (s16) sp20) {
        if (((s16) sp12 != (s16) sp22) || (var_v0 = 0, ((s16) sp14 != (s16) sp24))) {
            goto block_19;
        }
    } else {
block_19:
        var_v0 = 0;
        if ((s16) sp10 == (s16) sp18) {
            var_v0 = 0;
            if ((s16) sp12 == (s16) sp1A) {
                var_v0 = 0;
                if ((s16) sp14 == (s16) sp1C) {
                    var_v0 = 0x8000;
                }
            }
        }
    }
    return var_v0;
}
