/* Main-exec range [80041354,800413B8) from the SLUS executable.
 * SHA256(span)=80b44d0e8d4b4e8a8d7f647596ee37309a9267021f2df081a8d1a7db9b20e36a.
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

s16 func_80041354(s16 arg0, u16 *arg1, u16 *arg2) {
    void *temp_v1;

    D_800B9B36 = arg0;
    temp_v1 = *(&D_800C73D8 + ((arg0 & 0xFF) * 4)) + (((s32) (arg0 & 0xFF00) >> 8) * 0xB0);
    *arg1 = M2C_FIELD(temp_v1, u16 *, 0x58);
    *arg2 = M2C_FIELD(temp_v1, u16 *, 0x5A);
    return D_800B9B36;
}
