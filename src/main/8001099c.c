/* Exact retail word export for [8001099C,80010A08); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004239C();                         /* static */
extern s32 *D_800AE810;
extern s32 *D_800AF630;

void func_8001099C(void) {
    *((M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) * 4) + &D_800AE810) = func_8004239C(1);
}
