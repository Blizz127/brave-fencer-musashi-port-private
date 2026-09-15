/* Overlay range [8014D610,8014D738) from MAIN.CD member 0012.
 * SHA256(span)=f19233fcc979de7dcd6986961f041ebc316f459977a0ee1c8f9ccb2ab871792e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135A4C(s32, s32, s32, void *);       /* static */
s32 func_8014C918(void *, u8);                      /* static */
extern u16 D_801202A0;
extern s32 *D_80126720;

s32 func_8014D610(void *arg0, s32 arg1, void *arg2) {
    s32 temp_a1;
    u16 *var_s1;
    void *var_s0;

    var_s1 = &D_801202A0;
    if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
        var_s0 = &D_801202A0 + 0x75;
loop_2:
        if ((*var_s1 != 0) && (M2C_FIELD(var_s0, u16 *, -0x19) & 0x400)) {
            temp_a1 = M2C_FIELD(var_s0, s32 *, -0x1D);
            if ((temp_a1 != 0) && (M2C_FIELD(var_s0, s16 *, -0x6B) >= M2C_FIELD(arg0, s16 *, 0xA)) && (func_80135A4C(M2C_FIELD(var_s0, s32 *, -0x55), temp_a1, arg1, arg2) != 0)) {
                M2C_FIELD(arg0, u16 **, 0x174) = var_s1;
                M2C_FIELD(var_s0, s8 *, -1) = 1;
                M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg2, u16 *, 0);
                M2C_FIELD(arg0, s16 *, 0xA) = (s16) M2C_FIELD(arg2, u16 *, 2);
                M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg2, u16 *, 4);
                M2C_FIELD(arg0, s16 *, 0x16E) = (s16) (func_8014C918(arg0, M2C_FIELD(var_s0, u8 *, 0)) & 0xFF);
                return 1;
            }
        }
        var_s1 += 0x10C;
        var_s0 += 0x10C;
        if ((u32) var_s1 >= (u32) &D_80126720) {
            goto block_9;
        }
        goto loop_2;
    }
block_9:
    return 0;
}
