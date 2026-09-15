/* Main-exec range [8005D138,8005D184) from the SLUS executable.
 * SHA256(span)=022c1c5944ee1bd02e274fad9579bd683bd8cbcf6dc9d146e8c6b03b5ce05305.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072990;
extern s32 D_800729A8;

s32 func_8005D138(s32 arg0) {
    if (D_800729A8 == 0) {
        return 0;
    }
    return M2C_FIELD((((arg0 >> 4) * 0xF0) + D_80072990), u8 *, 0xE8) == 8;
}
