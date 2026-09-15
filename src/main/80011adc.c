/* Main-exec range [80011ADC,80011B7C) from the SLUS executable.
 * SHA256(span)=2cc10f926daacfb0f81c0479ee10ea91a3450d43b1d16a3489f3491bd8cf17d5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AF630;

void func_80011ADC(void) {
    M2C_FIELD(&D_800AF630, u16 *, 0xA3C0) = (u16) (M2C_FIELD(&D_800AF630, u16 *, 0xA3C0) - 1);
    M2C_FIELD(&D_800AF630, s16 *, 0xA3C6) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CC) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CA) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3D0) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3C2) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3C8) = 0;
    M2C_FIELD(&D_800AF630, s16 *, 0xA3CE) = 0;
}
