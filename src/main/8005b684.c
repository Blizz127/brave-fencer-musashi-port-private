/* Retail word export [8005B684,8005B6AC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8007285C;
extern s32 *D_80078874;

void func_8005B684(u32 arg0) {
    *D_8007285C = arg0;
    *(&D_80078874 + (arg0 >> 0x18)) = (s8) arg0;
}
