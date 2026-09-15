/* Overlay range [801502EC,80150460) from MAIN.CD member 0012.
 * SHA256(span)=38ce7ed37ba95ad398e2d7698414eff5266772650b9ce1c78524b7162508be88.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135D20(s32, s32, void *);                   /* static */
extern u16 D_801202A0;
extern s32 *D_80126720;

s32 func_801502EC(void *arg1, void *arg2) {
    s32 sp1F;
    s32 sp1B;
    s32 sp18;
    s32 sp17;
    s32 sp13;
    s32 var_s3;
    u16 *var_s0;
    u16 *var_s1;

    sp13 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp17 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    var_s1 = &D_801202A0;
    arg1->unk2 = 0x7FFF;
    var_s3 = 0;
    if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
        var_s0 = &D_801202A0 + 0x58;
        do {
            if ((*var_s1 != 0) && (var_s0->unk4 & 0x400) && (var_s0->unk0 != 0)) {
                sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                if (func_80135D20(var_s0->unk-38, var_s0->unk0, &sp18) != 0) {
                    var_s3 = 1;
                    if ((s16) sp1A < arg1->unk2) {
                        arg1->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                        arg1->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                        arg2->unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                        arg2->unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                    }
                }
            }
            var_s1 += 0x10C;
            var_s0 += 0x10C;
        } while ((u32) var_s1 < (u32) &D_80126720);
    }
    return var_s3;
}
