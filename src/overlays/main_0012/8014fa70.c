/* Overlay range [8014FA70,8014FBC0) from MAIN.CD member 0012.
 * SHA256(span)=3d3ce00fdb94c3d029b8733b36017704a42d6f875dda8f4f59dd5be7825252c4.
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

s32 func_8014FA70(void *arg0) {
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 var_s1;
    s32 var_v0;

    sp10 = arg0->unk88;
    sp12 = arg0->unk8A;
    sp14 = arg0->unk8C;
    sp18 = arg0->unk6;
    sp1A = arg0->unkA;
    sp1C = arg0->unkE;
    var_s1 = func_80133784(1, &sp10, &sp18);
    if (var_s1 != 0) {
        arg0->unk6 = sp18;
        arg0->unkA = sp1A;
        arg0->unkE = sp1C;
        if (sp1E != 0) {
            arg0->unk16C = (u16) sp1E;
        }
        arg0->unk16E = (s16) ((u16) sp1E >> 0xD);
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
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_v0;
    }
    if (sp1E != 0) {
        arg0->unk16C = (u16) sp1E;
    }
    var_v0 = 0;
    return var_v0;
}
