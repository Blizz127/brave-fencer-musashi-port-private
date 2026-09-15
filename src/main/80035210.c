/* Main-exec range [80035210,80035270) from the SLUS executable.
 * SHA256(span)=820cc2e556d7aff76bb316ece9a0666f242be0505455c8dd1f6a3dbf6abeb2a8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003C438(s32, s32);                          /* static */
void func_8003C498(s32);                               /* static */
extern s32 D_80076218;

void func_80035210(s32 arg0, s32 arg1) {
    func_8003C498(D_80076218);
    func_8003C438(arg0, arg1);
    D_80076218 += arg1;
}
