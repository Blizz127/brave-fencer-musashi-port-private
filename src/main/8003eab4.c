/* Main-exec range [8003EAB4,8003EBB0) from the SLUS executable.
 * SHA256(span)=313b5eea33364601805618768eeebb9b89b12e51c5c28924b994c4d6d3bb166b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800C73D8;

void func_8003EAB4(s32 arg0, s16 arg1) {
    s32 *temp_a0;
    s32 temp_a2;
    void *temp_a2_2;
    void *temp_a3;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;

    temp_a0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_a2 = arg1 * 0xB0;
    temp_a3 = *temp_a0 + temp_a2;
    M2C_FIELD(temp_a3, s8 *, 0x20) = 1;
    M2C_FIELD(temp_a3, s8 *, 0x21) = 0;
    temp_v1 = temp_a2 + *temp_a0;
    M2C_FIELD(temp_v1, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1, s32 *, 0x98) & ~0x100);
    temp_v1_2 = temp_a2 + *temp_a0;
    M2C_FIELD(temp_v1_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_2, s32 *, 0x98) & ~8);
    temp_v1_3 = temp_a2 + *temp_a0;
    M2C_FIELD(temp_v1_3, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_3, s32 *, 0x98) & ~2);
    temp_v1_4 = temp_a2 + *temp_a0;
    M2C_FIELD(temp_v1_4, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_4, s32 *, 0x98) & ~4);
    temp_v1_5 = temp_a2 + *temp_a0;
    M2C_FIELD(temp_v1_5, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_5, s32 *, 0x98) & ~0x200);
    M2C_FIELD(temp_a3, s8 *, 0x14) = 1;
    M2C_FIELD(temp_a3, s32 *, 0) = (s32) M2C_FIELD(temp_a3, s32 *, 4);
    temp_a2_2 = temp_a2 + *temp_a0;
    M2C_FIELD(temp_a2_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_a2_2, s32 *, 0x98) | 1);
}
