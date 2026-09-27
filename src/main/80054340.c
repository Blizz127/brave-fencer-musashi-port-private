/* Exact retail word export for [80054340,80054430); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80054430();                                /* static */
s32 func_800544F8(s32);                             /* static */

void func_80054340(void *arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_v0 = func_800544F8(func_80054430());
    temp_v1 = temp_v0 - 0xF;
    if (temp_v0 >= 0x10) {
        M2C_FIELD(arg1, s32 *, 0) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0) >> temp_v1);
        M2C_FIELD(arg1, s32 *, 4) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 4) >> temp_v1);
        M2C_FIELD(arg1, s32 *, 8) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 8) >> temp_v1);
        M2C_FIELD(arg1, s32 *, 0xC) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0xC) >> temp_v1);
        M2C_FIELD(arg1, s32 *, 0x10) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 0x10) >> temp_v1);
        var_v0 = (s32) M2C_FIELD(arg0, s32 *, 0x14) >> temp_v1;
    } else {
        M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(arg1, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
        M2C_FIELD(arg1, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        var_v0 = M2C_FIELD(arg0, s32 *, 0x14);
    }
    M2C_FIELD(arg1, s32 *, 0x14) = var_v0;
}
