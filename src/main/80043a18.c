/* Exact retail word export for [80043A18,80043B1C); EXE-verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80043A18(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s8 *, 2) = (s8) (((((arg0 + 0x96) % 75) / 10) * 0x10) + (((arg0 + 0x96) % 75) % 10));
    M2C_FIELD(arg1, s8 *, 1) = (s8) ((((((arg0 + 0x96) / 75) % 60) / 10) * 0x10) + ((((arg0 + 0x96) / 75) % 60) % 10));
    M2C_FIELD(arg1, s8 *, 0) = (s8) ((((((arg0 + 0x96) / 75) / 60) / 10) * 0x10) + ((((arg0 + 0x96) / 75) / 60) % 10));
}
