/* Main-exec range [800141AC,800141F0) from the SLUS executable.
 * SHA256(span)=88c68ea15e7e114370141d22e28d89a0d20b00d42b69e79f0dc95c6e318b88b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800484EC(s32 *, void *, s32);          /* static */

void func_800141AC(void *arg1) {
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_a3;

    temp_a3 = M2C_FIELD(arg1, s32 *, 0xC);
    sp10 = M2C_FIELD(arg1, s32 *, 0);
    sp14 = M2C_FIELD(arg1, s32 *, 4);
    sp18 = M2C_FIELD(arg1, s32 *, 8);
    sp1C = temp_a3;
    func_800484EC(&sp10, arg1, temp_a3);
}
