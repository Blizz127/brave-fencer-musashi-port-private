/* Overlay range [80163950,80163A58) from MAIN.CD member 0012.
 * SHA256(span)=5bf50b3adfff3d1ae737b428d8795cc7ad3b20231008a2832c17e23f7d0ebc8d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(void *, s32);              /* extern */
void func_80015978(s32, void *);              /* extern */
s32 func_80135A4C(s32, s32, void *, void *);  /* static */
extern u16 D_801202A0;
extern s32 *D_80126720;

s32 func_80163950(s32 arg0) {
    u16 sp1A;
    s32 sp18;
    u16 sp12;
    s32 sp10;
    s32 temp_a1;
    s32 temp_s0;
    u16 *var_s0;
    u16 *var_s1;

    temp_s0 = arg0 + 4;
    func_80015978(temp_s0, &sp10);
    func_80015978(temp_s0, &sp18);
    var_s1 = &D_801202A0;
    sp12 -= 0x20;
    sp1A += 8;
    if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
        var_s0 = &D_801202A0 + 0x20;
loop_2:
        if ((*var_s1 != 0) && (M2C_FIELD(var_s0, u16 *, 0x3C) & 0x400)) {
            temp_a1 = M2C_FIELD(var_s0, s32 *, 0x38);
            if (temp_a1 != 0) {
                var_s1 += 0x10C;
                if (func_80135A4C(M2C_FIELD(var_s0, s32 *, 0), temp_a1, &sp10, &sp18) != 0) {
                    func_80015954(&sp18, arg0 + 4);
                    return 1;
                }
                goto block_8;
            }
        }
        var_s1 += 0x10C;
block_8:
        var_s0 += 0x10C;
        if ((u32) var_s1 >= (u32) &D_80126720) {
            goto block_9;
        }
        goto loop_2;
    }
block_9:
    return 0;
}
