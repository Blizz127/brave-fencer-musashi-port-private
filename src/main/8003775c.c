/* Exact retail word export for [8003775C,800377D8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800373D0();                                  /* static */
s32 func_8003C4F0();                               /* static */
extern u8 D_8006AEF4;
extern u8 D_80076242;

s32 func_8003775C(void) {
    s32 var_v0;

    if (D_80076242 != 0) {
        var_v0 = 0;
        if (func_8003C4F0(0) != 0) {
            D_80076242 = 0;
            goto block_4;
        }
    } else {
block_4:
        D_8006AEF4 &= 0xFC;
        func_800373D0();
        var_v0 = 1;
    }
    return var_v0;
}
