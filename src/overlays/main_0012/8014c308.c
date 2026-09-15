/* Overlay range [8014C308,8014C3A4) from MAIN.CD member 0012.
 * SHA256(span)=983efa82dadac635e524d6235ac71916b2d0df65eac78365ac555f6365de4d79.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C308(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg1, u16 *, 0) != 0) {
        var_v0 = 0;
        if (M2C_FIELD(arg1, s32 *, 0x58) != 0) {
            if (M2C_FIELD(arg1, u16 *, 0x5E) != arg2) {
                var_v0 = 0;
                if ((M2C_FIELD(arg1, s32 *, 0x5C) & 0xC100) == 0x8000) {
                    if (!(M2C_FIELD(arg1, s16 *, 0xAE) & (arg3 & 0xFFFF))) {
                        var_v0 = 1;
                        if ((arg2 != 9) && (arg2 != 0x11) && (arg2 != 0x29) && (arg2 != 0xA)) {
                            return M2C_FIELD(arg0, s32 *, 0x178) != (s32) arg1;
                        }
                        /* Duplicate return node #11. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    goto block_10;
                }
                /* Duplicate return node #11. Try simplifying control flow for better match */
                return var_v0;
            }
block_10:
            var_v0 = 0;
            /* Duplicate return node #11. Try simplifying control flow for better match */
            return var_v0;
        }
    }
    return var_v0;
}
