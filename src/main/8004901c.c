/* Main-exec range [8004901C,80049140) from the SLUS executable.
 * SHA256(span)=6fa6bca1ebd36af6824a61f942ef870aa8600ab2b0d0bbc86ffa868c85a85629.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_8004901C(void *arg0, void *arg1) {
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t0_3;
    s32 temp_t0_4;
    s32 temp_t3;
    s32 temp_t4;
    s32 temp_t5;

    temp_t0 = M2C_FIELD(arg0, s32 *, 0);
    temp_t3 = M2C_FIELD(arg1, s32 *, 0);
    temp_t4 = M2C_FIELD(arg1, s32 *, 4);
    temp_t5 = M2C_FIELD(arg1, s32 *, 8);
    temp_t0_2 = M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((((s32) ((s16) (temp_t0 & 0xFFFF) * temp_t3) >> 0xC) & 0xFFFF) | (((s32) ((temp_t0 >> 0x10) * temp_t4) >> 0xC) << 0x10));
    temp_t0_3 = M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((((s32) ((s16) (temp_t0_2 & 0xFFFF) * temp_t5) >> 0xC) & 0xFFFF) | (((s32) ((temp_t0_2 >> 0x10) * temp_t3) >> 0xC) << 0x10));
    temp_t0_4 = M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 8) = (s32) ((((s32) ((s16) (temp_t0_3 & 0xFFFF) * temp_t4) >> 0xC) & 0xFFFF) | (((s32) ((temp_t0_3 >> 0x10) * temp_t5) >> 0xC) << 0x10));
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) ((((s32) ((s16) (temp_t0_4 & 0xFFFF) * temp_t3) >> 0xC) & 0xFFFF) | (((s32) ((temp_t0_4 >> 0x10) * temp_t4) >> 0xC) << 0x10));
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((s32) ((s16) (M2C_FIELD(arg0, s32 *, 0x10) & 0xFFFF) * temp_t5) >> 0xC);
    return arg0;
}
