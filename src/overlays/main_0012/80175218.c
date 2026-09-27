/* Overlay range [80175218,80175268) from MAIN.CD member 0012.
 * SHA256(span)=a9310ea5c1d153ab964b5b52099eb475cdd8a03a5cc9a4a59a75676ec0663fb6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80181A10;
void func_80146CA0(s32);                               /* static */
extern u8 D_80078EC0;

void func_80175218(s32 arg0) {
    *(D_80181A10 + ((D_80078EC0 - 1) * 4))();
    func_80146CA0(arg0);
}
