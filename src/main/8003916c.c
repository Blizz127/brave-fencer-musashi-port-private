/* Exact retail word export for [8003916C,800391D4); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800C6DD0;

void func_8003916C(s16 arg0) {
    void *temp_a1;

    temp_a1 = (arg0 * 0x60) + &D_800C6DD0;
    if (M2C_FIELD(temp_a1, u8 *, 0x5A) != 0) {
        M2C_FIELD((M2C_FIELD(temp_a1, s32 *, 0x50) + (M2C_FIELD(temp_a1, s16 *, 6) * 0x1A) + arg0), s8 *, 0x23) = 0;
        M2C_FIELD(temp_a1, u8 *, 0x5A) = 0U;
    }
}
