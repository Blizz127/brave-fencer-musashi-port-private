/* Main-exec range [8003EBB0,8003EC10) from the SLUS executable.
 * SHA256(span)=d57cbf3c5f28a5ace3a3caa42f86925a99196619401460e1f39cc7aeefdb0c51.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800C73D8;

void func_8003EBB0(s32 arg0, s16 arg1) {
    s32 *temp_a0;
    s32 temp_v0;
    void *temp_v0_2;

    temp_a0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_v0 = arg1 * 0xB0;
    M2C_FIELD((*temp_a0 + temp_v0), s8 *, 0x14) = 1;
    temp_v0_2 = temp_v0 + *temp_a0;
    M2C_FIELD(temp_v0_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 0x98) & ~8);
}
