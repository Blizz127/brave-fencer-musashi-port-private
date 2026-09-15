/* Main-exec range [8001C14C,8001C1E4) from the SLUS executable.
 * SHA256(span)=51c5bfb6e4cc0e1887bff6cce570eaf306259298d87d20368ab93cf1c10a64e4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(u32, s32);                            /* static */
extern s32 *D_800AF630;

void func_8001C14C(void) {
    void *temp_v1;
    void *temp_v1_2;
    void *var_a0;
    void *var_a0_2;
    void *var_s0;
    void *var_s0_2;

    var_s0 = &D_800AF630 + 0x65A8;
    temp_v1 = &D_800AF630 + 0x6688;
    if ((u32) var_s0 < (u32) temp_v1) {
        var_a0 = var_s0;
        do {
            func_80016714((u32) var_a0, 0x38);
            var_s0 += 0x38;
            var_a0 = var_s0;
        } while ((u32) var_s0 < (u32) temp_v1);
    }
    var_s0_2 = &D_800AF630 + 0x2A8;
    temp_v1_2 = &D_800AF630 + 0x4B8;
    if ((u32) var_s0_2 < (u32) temp_v1_2) {
        var_a0_2 = var_s0_2;
        do {
            func_80016714((u32) var_a0_2, 0x84);
            var_s0_2 += 0x84;
            var_a0_2 = var_s0_2;
        } while ((u32) var_s0_2 < (u32) temp_v1_2);
    }
}
