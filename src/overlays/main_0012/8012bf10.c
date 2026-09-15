/* Overlay range [8012BF10,8012BF4C) from MAIN.CD member 0012.
 * SHA256(span)=af1a7f322858054394ee8ff5c6fcb0b7001c7cc42f88c03fee372fcf47fd5c28.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012BF10(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C);
    temp_v0_2 = temp_v0 - 1;
    if (temp_v0 == 0) {
        var_v0 = 1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
        var_v0 = temp_v0_2 == 0;
    }
    if (var_v0 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = arg1;
    return 1;
}
