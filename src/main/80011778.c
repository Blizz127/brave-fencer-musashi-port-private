/* Exact retail word export for [80011778,80011818); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

void func_80011778(void) {
    M2C_FIELD(&D_800AF630, u16 *, 0xA3AE) = (u16) (M2C_FIELD(&D_800AF630, u16 *, 0xA3AE) + 1);
    M2C_FIELD(&D_800AF630, s16 *, 0xA3B4) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3BA) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3B8) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3BE) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3B0) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3B6) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3BC) = 0;
}
