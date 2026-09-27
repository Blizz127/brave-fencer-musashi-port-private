/* Overlay range [8012C218,8012C284) from MAIN.CD member 0012.
 * SHA256(span)=daf5c1d2fe46c0319a8a0853e1af410059d9dabc900161d45717c961b83a2afb.
 * Word export for the native seam; the body below is a
 * verified MATCH (27/27 words at 0x8012C218, -O2). */
#include "psx_types.h"
#include "m2c_macros.h"

/* Dispatch at vram 0x8012C218: run func_80016714 on the structure at byte
 * offset 0x20 with 0x84 (halfword == 1) or 0x38 (halfword == 2), then always
 * run it on arg0 with 0x10C.
 *
 * Written with the negative inner test. Testing `== 2` with a goto to the
 * shared call emits beq where retail has bne and fills the jump delay slot
 * differently (24/27 words, first diff at 0x8012C248).
 *
 * Signatures and types here are the loosest that reproduce the bytes; they are
 * not evidence of the original declaration.
 */

void func_80016714(u16 *, s32);              /* extern */

void func_8012C218(u16 *arg0) {
    s32 var_a1;
    u16 *temp_a0;
    u16 temp_v1;

    temp_a0 = M2C_FIELD(arg0, u16 **, 0x20);
    if (temp_a0 != 0) {
        temp_v1 = *temp_a0;
        if (temp_v1 != 1) {
            var_a1 = 0x38;
            if (temp_v1 != 2) {
                goto skip;
            }
        } else {
            var_a1 = 0x84;
        }
        func_80016714(temp_a0, var_a1);
    }
skip:
    func_80016714(arg0, 0x10C);
}
