/* Overlay range [8014C4AC,8014C568) from MAIN.CD member 0012.
 * SHA256(span)=78845b0ec30547710191ba15ef8bc27fd7f529fb5106416cb69efbef14e67e28.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_801152B8;
extern u16 D_8012693A;
extern s32 D_80126CD0;

void *func_8014C4AC(void *arg0, s16 arg1, s16 arg2, void *arg3, u16 arg4) {
    if (arg0 != 0) {
        if (arg0->unk0 != 0) {
            if ((arg1 == 9) || (arg1 == 0x11) || (arg1 == 0x29) || (arg1 == 0xA) || (D_80126CD0 != arg0)) {
                arg0->unk5E = arg1;
                arg0->unk62 = arg4;
                arg0->unk60 = arg2;
                arg0->unk5C = (u16) (arg0->unk5C | 1);
                arg0->unk7F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                arg0->unk83 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                arg0->unkC9 = (s8) D_8012693A;
                arg0->unkC8 = (s8) D_801152B8;
                return arg0;
            }
            /* Duplicate return node #9. Try simplifying control flow for better match */
            return 0;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
