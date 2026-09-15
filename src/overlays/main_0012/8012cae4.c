/* Overlay range [8012CAE4,8012CB64) from MAIN.CD member 0012.
 * SHA256(span)=ec3a569833e3ce8ee8e9b2945e0fdb6194bbfe711a03cfd6ecda2403e56bb67f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(u16 *, s32);              /* extern */
extern u16 D_801274E4;

void func_8012CAE4(u16 *arg0) {
    s32 var_a1;
    u16 *temp_a0;
    u16 temp_v1;

    D_801274E4 |= 1;
    temp_a0 = M2C_FIELD(arg0, u16 **, 0x20);
    if (temp_a0 != 0) {
        temp_v1 = *temp_a0;
        if (temp_v1 != 1) {
            var_a1 = 0x38;
            if (temp_v1 == 2) {
                goto block_5;
            }
        } else {
            var_a1 = 0x84;
block_5:
            func_80016714(temp_a0, var_a1);
        }
    }
    func_80016714(arg0, 0x10C);
}
