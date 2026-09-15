/* Overlay range [80175268,801752BC) from MAIN.CD member 0012.
 * SHA256(span)=b1020d0db82e67f7463dfb697689df5caf8527f60f36f4e4e9191ae81186e7af.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181A28;
extern u8 D_80078EC0;

void func_80175268(void *arg0) {
    arg0->unk44 = (s32) (arg0->unk44 | 2);
    *(D_80181A28 + ((D_80078EC0 - 1) * 4))();
}
