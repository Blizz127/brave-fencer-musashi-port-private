/* Exact retail word export for [80037CD8,80037D74); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_8006AEF4;
extern s32 (*D_800BA0F8)();

s32 func_80037CD8(s32 (*arg0)()) {
    if ((D_8006AEF4 & 2) && (D_800BA0F8 != 0)) {
        if (D_800BA0F8() != 0) {
            D_800BA0F8 = arg0;
            goto block_6;
        }
        return 0;
    }
    D_800BA0F8 = arg0;
block_6:
    D_8006AEF4 &= 0xFD;
    return 1;
}
