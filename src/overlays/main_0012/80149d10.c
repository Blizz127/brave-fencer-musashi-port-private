/* Overlay range [80149D10,80149D9C) from MAIN.CD member 0012.
 * SHA256(span)=3a3e1884c88b5fef65d770085ff326fbac06fbafa935280f0a52a25bc8d92ad9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014B5B8();                                /* static */
extern u8 D_80078EBF;
extern u8 D_80078EC0;

s32 func_80149D10(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0x44) & 0x400)) {
        var_v0 = 0;
        if (D_80078EBF == 0x80) {
            var_v0 = 0;
            if (D_80078EC0 & 0x7F) {
                if (M2C_FIELD(arg0, u16 *, 0xAC) & 0x10) {
                    var_v0 = 1;
                    if (func_8014B5B8() & 0xFF) {
                        return 2;
                    }
                    /* Duplicate return node #7. Try simplifying control flow for better match */
                    return var_v0;
                }
                var_v0 = 0;
                /* Duplicate return node #7. Try simplifying control flow for better match */
                return var_v0;
            }
        }
    }
    return var_v0;
}
