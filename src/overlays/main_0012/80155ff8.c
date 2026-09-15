/* Overlay range [80155FF8,80156044) from MAIN.CD member 0012.
 * SHA256(span)=5c14daaabcf08990f47fc15d7c5f8379bb91c4eac1b5d9c88775a0c1ca58ff09.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80156044();                                  /* static */

void func_80155FF8(void) {
    **(void ***)0x1F8003FC = sp;
    func_80156044();
}
