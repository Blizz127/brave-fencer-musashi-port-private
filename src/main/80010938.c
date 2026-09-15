/* Main-exec range [80010938,8001094C) from the SLUS executable.
 * SHA256(span)=b83875baf4d20f898459ac773bb45f161e3cdc99b712c9eaeabfa99322330aad.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80010204();                                  /* extern */
void func_80042610();                                 /* static */

void func_80010938(void) {
    func_80042610(0);
    func_80010204();
}
