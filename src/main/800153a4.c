/* Exact retail word export for [800153A4,800153CC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800153A4(void *arg0, s32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    M2C_FIELD(arg0, s16 *, 0) = 1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, u8 *, 0xC) = arg4;
    M2C_FIELD(arg0, u8 *, 0xD) = arg5;
}
