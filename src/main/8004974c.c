/* Exact retail word export for [8004974C,8004978C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_8004974C(void *arg0, void *arg1) {
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t2;
    s32 temp_t3;

    temp_t1 = M2C_FIELD(arg0, s32 *, 0);
    temp_t2 = M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(arg1, s32 *, 4) = temp_t1;
    M2C_FIELD(arg1, s32 *, 0) = temp_t2;
    M2C_FIELD(arg1, s32 *, 0) = (s16) temp_t1;
    temp_t3 = M2C_FIELD(arg0, s32 *, 8);
    temp_t1_2 = M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg1, s32 *, 0xC) = temp_t3;
    M2C_FIELD(arg1, s32 *, 8) = temp_t1_2;
    M2C_FIELD(arg1, s32 *, 0xC) = (s16) temp_t2;
    M2C_FIELD(arg1, s32 *, 8) = (s16) temp_t3;
    M2C_FIELD(arg1, s32 *, 4) = (s16) temp_t1_2;
    M2C_FIELD(arg1, s16 *, 0x10) = (s16) M2C_FIELD(arg0, s16 *, 0x10);
    return arg1;
}
