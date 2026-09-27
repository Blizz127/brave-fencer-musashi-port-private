/* Main-exec range [8005903C,80059074) from the SLUS executable.
 * SHA256(span)=99da0c1e4c21acae4c348682d809ea425eeac362d3c98e3723f6fdc81a553e0d.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005903C(void *arg0, void *arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 3) + M2C_FIELD(arg1, u8 *, 3) + 1;
    if (temp_v1 < 0x11) {
        M2C_FIELD(arg0, u8 *, 3) = (u8) temp_v1;
        M2C_FIELD(arg1, s32 *, 0) = 0;
        return 0;
    }
    return -1;
}
