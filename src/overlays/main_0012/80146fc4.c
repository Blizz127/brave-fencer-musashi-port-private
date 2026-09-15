/* Overlay range [80146FC4,8014704C) from MAIN.CD member 0012.
 * SHA256(span)=1208dcc4ebc086ed5e41362066948abbd49685a7cdbb133cafc64dfc3ab4bbc8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(void *, void *);                       /* extern */
extern s32 *D_80126DB0;
extern u16 D_80126DB6;

void func_80146FC4(void *arg0) {
    if (arg0->unkA >= 0x401) {
        func_80015954(&D_80126DB0, arg0 + 4);
        arg0->unk8B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk8F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        arg0->unk20->unk12 = (u16) D_80126DB6;
    }
}
