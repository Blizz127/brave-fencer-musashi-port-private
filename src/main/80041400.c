/* Main-exec range [80041400,80041448) from the SLUS executable.
 * SHA256(span)=b414e7f891d997590d94459b3e1af123475cc7c2ff89064304b237df97a94f8b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s16 D_800B9B36;
extern s32 *D_800C73D8;

s16 func_80041400(s16 arg0) {
    D_800B9B36 = arg0;
    return M2C_FIELD((*(&D_800C73D8 + ((arg0 & 0xFF) * 4)) + (((s32) (arg0 & 0xFF00) >> 8) * 0xB0)), s16 *, 0x5A);
}
