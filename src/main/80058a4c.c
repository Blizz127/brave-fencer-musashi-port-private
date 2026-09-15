/* Native retail instruction export [80058A4C,80058B04).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80043078();                                /* static */

void func_80058A4C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    s32 temp_v0;
    s8 var_v0;

    temp_v0 = func_80043078();
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s8 *, 0x19) = 0;
    M2C_FIELD(arg0, s8 *, 0x1A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1B) = 0;
    M2C_FIELD(arg0, s8 *, 0x16) = 1;
    M2C_FIELD(arg0, s16 *, 6) = (s16) arg4;
    if (temp_v0 != 0) {
        var_v0 = arg4 < 0x121;
    } else {
        var_v0 = arg4 < 0x101;
    }
    M2C_FIELD(arg0, s8 *, 0x17) = var_v0;
    M2C_FIELD(arg0, s16 *, 8) = arg1;
    M2C_FIELD(arg0, s16 *, 0xA) = arg2;
    M2C_FIELD(arg0, s16 *, 0x14) = 0xA;
    M2C_FIELD(arg0, s8 *, 0x18) = 0;
}
