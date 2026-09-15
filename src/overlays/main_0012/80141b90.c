/* Overlay range [80141B90,80141C04) from MAIN.CD member 0012.
 * SHA256(span)=cf1a2a2bd684069512140c012eb258f575344f7e3f22df5e56a9f7134b55b461.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8013FAF8(s32, s32);                              /* static */
extern u16 D_800B9A02;
extern s8 D_800B9A15;
extern u16 D_80115112;
extern u16 D_80115116;
extern s32 *D_801151C8;
extern s32 D_801151D0;

void func_80141B90(void) {
    D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4));
    func_8013FAF8(2, 3);
    if (D_80115116 == 0) {
        D_800B9A15 = 0;
        D_80115112 += 1;
    }
}
