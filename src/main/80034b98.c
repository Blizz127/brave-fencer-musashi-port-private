/* Exact retail word export for [80034B98,80034C24); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEF8;
extern s32 D_8006AEFC;
extern u8 D_8007620C;
extern u8 D_80076214;

s32 func_80034B98(void) {
    s32 var_v0;

    if (D_8006AEF8 != D_8006AEFC) {
        if (D_80076214 == 0) {
            if (D_8007620C & 0x80) {
                return 2;
            }
            var_v0 = 1;
            if (D_8007620C & 0x20) {
                return 4;
            }
            /* Duplicate return node #8. Try simplifying control flow for better match */
            return var_v0;
        }
        goto block_7;
    }
    D_8007620C = 0;
    var_v0 = 0;
    if (D_80076214 != 0) {
block_7:
        D_80076214 = 0;
        var_v0 = 8;
    }
    return var_v0;
}
