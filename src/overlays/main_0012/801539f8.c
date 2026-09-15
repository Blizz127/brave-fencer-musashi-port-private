/* Overlay range [801539F8,80153B58) from MAIN.CD member 0012.
 * SHA256(span)=8b5ec0fc8b06bb2c6bb8b8ac2470e056d7630c60514cbe9e450abe90e52b6db5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80133784(s32, u16 *, u16 *);                 /* static */

s32 func_801539F8(void *arg0, void *arg1) {
    u16 sp20;
    s32 sp1F;
    s32 sp1B;
    s8 sp1A;
    u16 sp18;
    s32 sp17;
    s32 sp13;
    s8 sp12;
    u16 sp10;
    s32 temp_v0;
    s32 temp_v0_2;

    sp13 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp17 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp12 = (u16) sp12 - 4;
    temp_v0 = func_80133784(0, &sp10, &sp18);
    if (temp_v0 == 0x2000) {
        sp13 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp17 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        sp1A = (u16) sp1A + 8;
        temp_v0_2 = func_80133784(0, &sp10, &sp18);
        if (temp_v0_2 == temp_v0) {
            if (func_80133784(2, &sp18, &sp20) == temp_v0_2) {
                arg0->unk88 = sp18;
                arg0->unk8A = (u16) sp1A;
                arg0->unk8C = sp1C;
                arg0->unk93 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                arg0->unk97 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                return 0;
            }
            /* Duplicate return node #5. Try simplifying control flow for better match */
            return 1;
        }
    }
    return 1;
}
