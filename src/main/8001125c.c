/* Exact retail word export for [8001125C,800112A8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800CEDFC();                            /* extern */
extern s32 *D_800AF630;

void func_8001125C(void) {
    M2C_FIELD(&D_800AF630, s8 *, 0xA434) = 0;
    func_800CEDFC();
}
