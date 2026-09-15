/* Exact retail word export for [80011A3C,80011ADC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

void func_80011A3C(void) {
    M2C_FIELD(&D_800AF630, u16 *, 0xA3C0) = (u16) (M2C_FIELD(&D_800AF630, u16 *, 0xA3C0) + 1);
    M2C_FIELD(&D_800AF630, s16 *, 0xA3C6) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CC) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CA) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3D0) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3C2) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3C8) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CE) = 0;
}
