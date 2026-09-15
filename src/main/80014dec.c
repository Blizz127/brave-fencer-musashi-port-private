/* Main-exec range [80014DEC,80014E24) from the SLUS executable.
 * SHA256(span)=9f5c886b45c1fda2c57d33e954db97d4acac5723fb4229f50f5b530f56095da8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80078D98;

u8 func_80014DEC(s32 arg0, s32 arg1) {
    return M2C_FIELD((((arg0 & 0xFF) * 0x4C) + &D_80078D98 + (arg1 & 0xFF)), u8 *, 0x32);
}
