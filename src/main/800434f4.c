/* Main-exec range [800434F4,80043528) from the SLUS executable.
 * SHA256(span)=5ee39bc9dc45c1507e3dddddbcea3f6c5bf84cfc280c2f88a3063229373073f2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CCAC[];
extern s32 D_80073614;

s32 func_800434F4(s32 arg0) {
    u32 temp_a0;

    temp_a0 = arg0 & 0xFF;
    if (temp_a0 < 0x1CU) {
        return *(D_8006CCAC + (temp_a0 * 4));
    }
    return D_80073614;
}
