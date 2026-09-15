/* Exact retail word export [80011D54,80011DA0); verified against pinned EXE and asm. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

void func_80011D54(u16 arg0) {
    u16 sp0;

    sp0 = arg0;
    M2C_FIELD(&D_800AF630, u16 *, 0xA3CC) = sp0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CE) = 0;
}
