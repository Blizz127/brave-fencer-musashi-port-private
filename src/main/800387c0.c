/* Exact retail word export for [800387C0,80038838); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800387C0(void **arg0) {
    void *temp_a3;

    temp_a3 = *arg0;
    *arg0 = temp_a3 + 1;
    *arg0 = temp_a3 + 2;
    *arg0 = temp_a3 + 3;
    *arg0 = temp_a3 + 4;
    if ((M2C_FIELD(temp_a3, u8 *, 0) | (M2C_FIELD(temp_a3, u8 *, 1) << 8) | (M2C_FIELD(temp_a3, u8 *, 2) << 0x10) | (M2C_FIELD(temp_a3, u8 *, 3) << 0x18)) == 0x6B72544D) {
        *arg0 = temp_a3 + 8;
        return 0;
    }
    return -1;
}
