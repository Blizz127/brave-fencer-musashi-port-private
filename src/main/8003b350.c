/* Main-exec range [8003B350,8003B3D0) from the SLUS executable.
 * SHA256(span)=7b07e72e3c307deb9852178fe091cbf6224147ea96282ca27513224e18b7ed5e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B5B0;

s32 func_8003B350(u32 arg0) {
    s32 temp_v1;
    s32 var_v0;
    u32 temp_v1_2;
    void *var_a1;

    if (D_8006B5B0 == 0) {
        return 0;
    }
    var_a1 = D_8006B5B0;
loop_3:
    temp_v1 = M2C_FIELD(var_a1, s32 *, 0);
    if (temp_v1 & 0x80000000) {
block_7:
        var_a1 += 8;
        goto loop_3;
    }
    temp_v1_2 = temp_v1 & 0x0FFFFFFF;
    if (!(temp_v1 & 0x40000000)) {
        var_v0 = 1;
        if (temp_v1_2 < arg0) {
            var_v0 = 1;
            if (arg0 >= (u32) (temp_v1_2 + M2C_FIELD(var_a1, s32 *, 4))) {
                goto block_7;
            }
        }
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
