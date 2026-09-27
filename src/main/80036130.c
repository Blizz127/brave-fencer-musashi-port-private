/* Main-exec range [80036130,800361CC) from the SLUS executable.
 * SHA256(span)=6e572294a4267cd7b195e6cd0813a4ffa5691f2a037af27e83b8e2defbbfe3d8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8007610C;
extern u8 D_800A63E4;
extern s32 D_800A63E8;

void func_80036130(s32 arg0, void *arg1) {
    u8 temp_a0;

    if ((D_800A63E4 == 0xC) && ((arg0 & 0xFF) == 1)) {
        if (D_8007610C < 0xA) {
            D_8007610C += 1;
            return;
        }
        if (!(M2C_FIELD(arg1, u8 *, 4) & 0x80)) {
            temp_a0 = M2C_FIELD(arg1, u8 *, 1);
            if ((((temp_a0 >> 4) * 0xA) + (temp_a0 & 0xF)) != D_800A63E8) {
                D_800A63E4 = 0xD;
            }
        }
    }
}
