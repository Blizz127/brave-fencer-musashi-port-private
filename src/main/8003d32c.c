/* Main-exec range [8003D32C,8003D3B4) from the SLUS executable.
 * SHA256(span)=e8c46efaac053e5fa91e53d45868efb43026f12e9203ebd84bfb4686561cbcc0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E4;
extern s32 D_8006B54C;

void func_8003D32C(s8 *arg0) {
    s32 var_a2;
    s8 *var_a1;
    u16 temp_v0;

    var_a2 = 0;
    var_a1 = arg0;
    do {
        temp_v0 = M2C_FIELD(((var_a2 * 0x10) + D_8006B54C), u16 *, 0xC);
        if (D_8006B0E4 & (1 << var_a2)) {
            if (temp_v0 != 0) {
                *var_a1 = 1;
            } else {
                *var_a1 = 3;
            }
        } else if (temp_v0 != 0) {
            *var_a1 = 2;
        } else {
            *var_a1 = 0;
        }
        var_a2 += 1;
        var_a1 += 1;
    } while (var_a2 < 0x18);
}
