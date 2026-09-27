/* Main-exec range [8005CF68,8005D004) from the SLUS executable.
 * SHA256(span)=0a4b6d79b7147a7f722e19a8efddb178c13f9d784ae9562b9afbdcb6ddce3428.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072938;

s32 func_8005CF68(s32 arg0, s16 arg1, s32 arg2) {
    s16 var_a3;
    s32 temp_t0;
    s32 var_v0;
    void *temp_v1;

    temp_t0 = arg0 & 0xFFFF;
    var_a3 = 0x48;
    if (temp_t0 >= 3) {
        return 0;
    }
    temp_v1 = (temp_t0 * 0x10) + D_80072938;
    M2C_FIELD(temp_v1, s16 *, 4) = 0;
    M2C_FIELD(temp_v1, s16 *, 8) = arg1;
    if ((u32) temp_t0 < 2U) {
        if (arg2 & 0x10) {
            var_a3 = 0x49;
        }
        var_v0 = arg2 & 0x1000;
        if (!(arg2 & 1)) {
            var_a3 |= 0x100;
        }
    } else {
        var_v0 = arg2 & 0x1000;
        if (temp_t0 == 2) {
            var_v0 = arg2 & 0x1000;
            if (!(arg2 & 1)) {
                var_a3 = 0x248;
            }
        }
    }
    if (var_v0 != 0) {
        var_a3 |= 0x10;
    }
    M2C_FIELD(((temp_t0 * 0x10) + D_80072938), s16 *, 4) = var_a3;
    return 1;
}
