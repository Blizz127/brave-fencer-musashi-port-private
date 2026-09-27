/* Overlay range [800CEF60,800CEF94) from MAIN.CD member 0007.
 * SHA256(span)=7e35bec60c68bc836fdbf3ef441d782cf135e5fef584b6ca64f3f4fc1f136db8.
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
s32 func_800167F0();                               /* extern */

void func_800CEF60(void) {
    if (func_800167F0(0) & 0xFFFF) {
        func_800118AC();
    }
}
