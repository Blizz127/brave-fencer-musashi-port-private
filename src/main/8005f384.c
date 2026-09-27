/* Exact retail word export for [8005F384,8005F394); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005F384(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x36);
    M2C_FIELD(arg0, u8 *, 0x36) = 0U;
    M2C_FIELD(arg0, u8 *, 0x37) = temp_v0;
}
