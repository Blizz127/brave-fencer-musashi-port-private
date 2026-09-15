/* Main-exec range [8003E248,8003E2E4) from the SLUS executable.
 * SHA256(span)=44e908b0224ffcbb18b50177e85747fbd148f6c531eb05e307ee60d97f101e47.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80041448(s16, s32);                    /* static */
extern s32 *D_800C73D8;

void func_8003E248(s32 arg0, s16 arg1) {
    s32 *temp_s2;
    s32 temp_a1;
    s32 temp_s0;
    void *temp_s0_2;
    void *temp_s1;

    temp_s2 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_s0 = arg1 * 0xB0;
    temp_a1 = arg1 << 8;
    temp_s1 = *temp_s2 + temp_s0;
    func_80041448((s16) (arg0 | temp_a1), temp_a1);
    M2C_FIELD(temp_s1, s8 *, 0x14) = 0;
    temp_s0_2 = temp_s0 + *temp_s2;
    M2C_FIELD(temp_s0_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_s0_2, s32 *, 0x98) & ~2);
}
