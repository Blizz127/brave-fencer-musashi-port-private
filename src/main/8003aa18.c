/* Main-exec range [8003AA18,8003AAD8) from the SLUS executable.
 * SHA256(span)=b71cc5cd15293ae294f80dca4d0e0161a1a2b2b798ffe22b9205b63d44d4ca53.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
void D_8006B584();                               /* static */
extern s32 D_8006B59C;
void func_8003B0E4();                            /* static */
void func_8005CE68(s32, s32);            /* static */

void func_8003AA18(void) {
    u32 var_v1;

    if (D_8006B59C == 0) {
        func_8003B0E4();
    }
    M2C_FIELD(D_8006B54C, u16 *, 0x1AA) = (u16) (M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0xFFCF);
    if (M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0x30) {
        var_v1 = 1;
loop_4:
        if (var_v1 < 0xF01U) {
            var_v1 += 1;
            if (!(M2C_FIELD(D_8006B54C, u16 *, 0x1AA) & 0x30)) {

            } else {
                goto loop_4;
            }
        }
    }
    if (D_8006B584 != 0) {
        D_8006B584(0xF0000000);
        return;
    }
    func_8005CE68(0xF0000009, 0x20);
}
