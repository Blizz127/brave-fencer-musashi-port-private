/* Overlay range [8016AA50,8016AB30) from MAIN.CD member 0012.
 * SHA256(span)=f892d13d0dda0a76cffb2a4071d04ed703c73a617b834307c185dff5ab190257.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146A6C(s32, void *, s16, s16, s32); /* static */
void func_80146C3C(u16 *, s16);                  /* static */
extern u16 D_8011D030;
extern s16 D_80126B5E;
extern u16 D_80126B62;
extern s16 D_80126B66;

void func_8016AA50(void *arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_v0;
    u16 *var_a0;
    u16 temp_v1;

    if (arg1 >= 0) {
        var_a2 = M2C_FIELD(arg0, s16 *, 0x7C);
        var_a3 = M2C_FIELD(arg0, s16 *, 0x7E);
        var_v0 = M2C_FIELD(arg0, s16 *, 0x80);
        goto block_7;
    }
    var_a1 = 0;
    var_a0 = &D_8011D030;
loop_3:
    temp_v1 = *var_a0;
    if ((temp_v1 == 0) || (temp_v1 == 3) || (temp_v0 = var_a1 + 1, (temp_v1 == 9))) {
        func_80146C3C(var_a0, var_a1);
        var_a2 = D_80126B5E;
        var_v0 = D_80126B66;
        var_a3 = D_80126B62 - 0x20;
block_7:
        func_80146A6C(0x1D, arg0, var_a2, var_a3, (s32) var_v0);
        return;
    }
    var_a1 = temp_v0;
    var_a0 += 0x58;
    if (temp_v0 >= 0x1E) {
        return;
    }
    goto loop_3;
}
