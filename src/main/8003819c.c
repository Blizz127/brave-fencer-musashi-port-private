/* Exact retail word export for [8003819C,800381E4); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_800B9CD8[];

void func_8003819C(s32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    void *temp_v0;
    void *temp_v1;

    if (arg1 <= 0) {
        temp_v0 = &D_800B9CD8[arg0 * 0x1FC];
        temp_v1 = temp_v0 + (arg1 * 8);
        M2C_FIELD(temp_v1, s16 *, 0x16) = arg2;
        M2C_FIELD(temp_v1, s16 *, 0x14) = arg3;
        M2C_FIELD(temp_v1, s8 *, 0x18) = 1;
        M2C_FIELD(temp_v0, s8 *, 0x1F4) = 1;
    }
}
