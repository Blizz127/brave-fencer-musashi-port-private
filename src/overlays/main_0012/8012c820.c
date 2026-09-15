/* Overlay range [8012C820,8012C890) from MAIN.CD member 0012.
 * SHA256(span)=9afdf98da44754df35af4b84593410e22aa0ec9c759195af15cfbc626f517241.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012C890(u16 *, s32);                  /* static */
extern s32 *D_80120194;

s32 func_8012C820(void *arg0) {
    u16 *var_a1;

    var_a1 = &D_80120194 + 0x6480;
    if (var_a1 != &D_80120194) {
loop_1:
        if (*var_a1 != 0) {
            var_a1 -= 0x10C;
            if (var_a1 == &D_80120194) {
                goto block_3;
            }
            goto loop_1;
        }
    } else {
block_3:
        var_a1 = 0;
    }
    if (var_a1 != 0) {
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) | 0x8000);
        return func_8012C890(var_a1, 0);
    }
    return 0;
}
