/* Native retail instruction export [80043450,800434BC).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80044BF4();                                /* static */
void func_80044CE8();                                  /* static */
s32 func_80044D38();                                /* static */

s32 func_80043450(s32 arg0) {
    s32 var_v0;

    if (arg0 == 2) {
        func_80044CE8();
        return 1;
    }
    var_v0 = 0;
    if (func_80044D38() == 0) {
        var_v0 = 1;
        if (arg0 == 1) {
            var_v0 = 0;
            if (func_80044BF4() == 0) {
                var_v0 = 1;
            }
        }
    }
    return var_v0;
}
