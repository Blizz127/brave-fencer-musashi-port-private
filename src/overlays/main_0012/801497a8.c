/* Overlay range [801497A8,80149864) from MAIN.CD member 0012.
 * SHA256(span)=1630b703df402c56365905e67a3cea5e2241cebaeb0afbea6b00eec964dc878b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C088(void *, s32);                 /* static */
s32 func_8014CB7C();                                /* static */
s32 func_80165658(void *, u8);                      /* static */
extern s32 *D_80078E78;
extern u8 D_80078EC1;

s32 func_801497A8(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (M2C_FIELD(arg0, u16 *, 0) != 0x1A) {
        var_v0 = 0;
        if ((func_8014CB7C() == 0) && ((D_80078EC1 != 0xF) || (var_v0 = 0, (func_8014C088(arg0, 0xA) == 0)))) {
            var_v0 = 0;
            if (!(M2C_FIELD(arg0, s32 *, 0x44) & 0x404)) {
                var_v0 = 0;
                if (!(func_80165658(arg0, M2C_FIELD(&D_80078E78, u8 *, 0x49)) & 0x80)) {
                    var_v0 = 1;
                    if (!(M2C_FIELD(arg0, u16 *, 0xAC) & 0x20)) {
                        var_v0 = 0;
                    }
                }
            }
        }
    }
    return var_v0;
}
