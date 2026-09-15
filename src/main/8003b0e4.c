/* Native retail instruction export [8003B0E4,8003B14C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003B12C();                                  /* extern */

void func_8003B0E4(void) {
    s32 sp4;
    s32 sp0;

    sp4 = 0xD;
    sp0 = 0;
    func_8003B12C();
}
