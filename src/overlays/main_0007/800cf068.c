/* Overlay range [800CF068,800CF0B8) from MAIN.CD member 0007.
 * SHA256(span)=28cb3a6a8199c4324c5ca2b99d29c5e0988c508e4e0568a6c2f2be5f2aa78fe2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800118AC();                                  /* extern */
void func_800167B8();                                 /* extern */
void func_8001AA98(s32 (*)());                           /* extern */
extern s32 D_800CEDFC;
extern s32 D_800D1368;
extern s32 D_800D1370;
extern s32 D_800D1374;

void func_800CF068(void) {
    func_8001AA98(D_800CEDFC);
    D_800D1368 = 0;
    D_800D1370 = 0;
    D_800D1374 = 0;
    func_800167B8(0);
    func_800118AC();
}
