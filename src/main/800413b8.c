/* Main-exec range [800413B8,80041400) from the SLUS executable.
 * SHA256(span)=0bcbe23fcfe107a7ce2673bfd4539fbeb6ae19ea0b0c9eb2e04c284207d25f3c.
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

s16 func_800413B8(s16 arg0) {
    D_800B9B36 = arg0;
    return M2C_FIELD((*(&D_800C73D8 + ((arg0 & 0xFF) * 4)) + (((s32) (arg0 & 0xFF00) >> 8) * 0xB0)), s16 *, 0x58);
}
