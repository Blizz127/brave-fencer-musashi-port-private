/* Overlay range [801628F4,80162968) from MAIN.CD member 0012.
 * SHA256(span)=40639445fe72781923afa85337553da894fa3c270fc17be929216ea6cb2abd3c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80162968(void *, void *);              /* static */

void func_801628F4(void *arg0) {
    s32 var_v0;
    void *temp_a1;
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 4);
    temp_a1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_a2, s16 *, 0x7E) != 0) {
        var_v0 = M2C_FIELD(temp_a1, s32 *, 4) | 0x80000000;
    } else {
        var_v0 = M2C_FIELD(temp_a1, s32 *, 4) & 0x7FFFFFFF;
    }
    M2C_FIELD(temp_a1, s32 *, 4) = var_v0;
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(temp_a2, s16 *, 0x78);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(temp_a2, s16 *, 0x7A);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(temp_a2, s16 *, 0x7C);
    func_80162968(temp_a1, temp_a2);
}
