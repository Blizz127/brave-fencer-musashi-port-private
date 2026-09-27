/* Exact retail word export for [80034A54,80034A9C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_800A4F17;

void func_80034A54(void *arg0) {
    u8 temp_a0;

    if (M2C_FIELD(arg0, u8 *, 0x37) & 1) {
        temp_a0 = D_800A4F17;
        D_800A4F17 = 1;
        M2C_FIELD(arg0, s8 *, 0x32) = 1;
        M2C_FIELD(arg0, s16 *, 0x2E) = 0x3FF;
        M2C_FIELD(arg0, s16 *, 0x30) = 0xFFF;
        D_800A4F17 = temp_a0;
    }
}
