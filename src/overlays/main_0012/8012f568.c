/* Overlay range [8012F568,8012F5F4) from MAIN.CD member 0012.
 * SHA256(span)=d6fe3270eca1c5737b148e6710b23dac07a1e0288fbd7954a37dcdd7f566ba84.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_80126B94;
extern s16 D_80126B96;
extern s16 D_80126B98;
extern s16 D_80126B9A;
extern s32 D_80126C38;
extern s32 D_80126C40;

void func_8012F568(s32 arg0, s16 arg1, s16 arg2, s16 arg3, void *arg4, void *arg5) {
    D_80126C38.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126C38.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126C40.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126C40.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126B96 = arg1;
    D_80126B9A = arg2;
    D_80126B98 = arg3;
    D_80126B94 |= arg0;
}
