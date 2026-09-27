/* Exact retail word export for [8005AD34,8005ADB8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005AD34(void *arg0) {
    s32 spC;
    s32 sp8;
    u32 sp4;
    u32 sp0;
    s32 temp_a2;
    s32 temp_v1;
    u32 temp_a1;
    u32 temp_v0;

    if (arg0 == 0) {
        return 0;
    }
    temp_a1 = (u8) M2C_FIELD(arg0, u8 *, 0) >> 3;
    sp0 = temp_a1;
    temp_a2 = (s32) (-M2C_FIELD(arg0, s16 *, 4) & 0xFF) >> 3;
    sp8 = temp_a2;
    temp_v0 = (u8) M2C_FIELD(arg0, u8 *, 2) >> 3;
    sp4 = temp_v0;
    temp_v1 = (s32) (-M2C_FIELD(arg0, s16 *, 6) & 0xFF) >> 3;
    spC = temp_v1;
    return (temp_v0 << 0xF) | ((temp_a1 << 0xA) | 0xE2000000) | (temp_v1 << 5) | temp_a2;
}
