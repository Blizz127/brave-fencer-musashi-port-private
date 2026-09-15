/* Exact retail word export for [8005E374,8005E3AC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005E374(void *arg0) {
    return (((s32) (M2C_FIELD(arg0, u8 *, 0xE3) + 1) >> 1) * 4) + ((((M2C_FIELD(arg0, u8 *, 0xE9) * 5) + 3) & 0xFFC) + 4) + M2C_FIELD(arg0, s32 *, 0xEC);
}
