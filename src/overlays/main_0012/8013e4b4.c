/* Overlay range [8013E4B4,8013E558) from MAIN.CD member 0012.
 * SHA256(span)=2093ec3ff40c8c16819b72dab3f861b82dd4656b6405cddd7ee1c01ef0b8332d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012C750(void *);                      /* static */
extern void *D_801274C8;
extern void *D_801274CC;

void func_8013E4B4(void) {
    u16 *var_a0;
    void *var_s0;

    var_s0 = D_801274C8;
    if ((var_s0 != 0) && (M2C_FIELD(var_s0, u16 *, 6) != 0)) {
        do {
            func_8012C750(var_s0);
            var_s0 += 0x14;
        } while (M2C_FIELD(var_s0, u16 *, 6) != 0);
    }
    if (D_801274CC != 0) {
        var_a0 = D_801274CC + 6;
        if (M2C_FIELD(D_801274CC, u16 *, 6) != 0) {
            do {
                M2C_FIELD(var_a0, u16 *, 4) = (u16) (M2C_FIELD(var_a0, u16 *, 4) & 0x7FFF);
                var_a0 += 0x14;
            } while (*var_a0 != 0);
        }
    }
}
