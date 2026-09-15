/* Exact retail word export for [80044A8C,80044B14); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006CF4C;
extern s32 *D_8006CF50;
extern s32 *D_8006CF54;
extern s32 *D_8006CF58;

s32 func_80044A8C(void *arg0) {
    *D_8006CF4C = 2;
    *D_8006CF54 = M2C_FIELD(arg0, u8 *, 0);
    *D_8006CF58 = M2C_FIELD(arg0, u8 *, 1);
    *D_8006CF4C = 3;
    *D_8006CF50 = M2C_FIELD(arg0, u8 *, 2);
    *D_8006CF54 = M2C_FIELD(arg0, u8 *, 3);
    *D_8006CF58 = 0x20;
    return 0;
}
