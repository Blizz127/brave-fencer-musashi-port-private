/* Overlay range [801518D8,80151924) from MAIN.CD member 0012.
 * SHA256(span)=77393231992d0f9820e76ebc707139d83f4090f54db5349d5d5041394acec2c8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801518D8(void *arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x3E);
    if ((temp_v1 == 0x1B) || (temp_v1 == 0x1C) || (temp_v1 == 0xF) || (temp_v1 == 0x10) || (temp_v1 == 3) || (temp_v1 == 0x13)) {
        return 1;
    }
    return temp_v1 == 0x17;
}
