/* Overlay range [8014A454,8014A4B4) from MAIN.CD member 0012.
 * SHA256(span)=19a35159056383a59b3ba346195d5428eb2c648001423ec9486505d767b1c6ba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012A60(s16, s32);                        /* extern */

s32 func_8014A454(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, u16 *, 0x3C) & 0x4000) {
        var_v0 = 1;
        if (func_80012A60(M2C_FIELD(arg0, s16 *, 0x42), (M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 0x12) + 0x800) & 0xFFF) >= 0x2AA) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
