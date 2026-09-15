/* Main-exec range [80020248,80020598) from the SLUS executable.
 * SHA256(span)=6f975ac578355506c6becfd1a0c06f6dee0e375d34332c36cb803215b91d0b39.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80020290(s32);                               /* extern */

void func_80020248(s32 arg1, s32 arg2, s32 arg3) {
    func_80020290(arg2);
}
