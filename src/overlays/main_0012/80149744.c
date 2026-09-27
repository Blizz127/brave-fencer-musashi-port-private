/* Overlay range [80149744,80149788) from MAIN.CD member 0012.
 * SHA256(span)=588ee66645385c6a0f7ca3757be4eea0b8937daf9fd46d9d2ae7e96fe1d21206.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_80078EBF;

s32 func_80149744(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0x44) & 4) && ((u8) D_80078EBF >= 0x80U)) {
        var_v0 = (M2C_FIELD(arg0, u16 *, 0xAC) & 0x80) != 0;
    }
    return var_v0;
}
