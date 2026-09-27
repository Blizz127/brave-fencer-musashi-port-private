/* Overlay range [80163764,8016380C) from MAIN.CD member 0012.
 * SHA256(span)=fcda8251cf645e5c4183f8de62a9609ff48c449399d21112a15b7bd3493c3507.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C278(void *, void *, s32);      /* static */
void func_801506A4(s32, void *);              /* static */
extern s32 *D_801202A0;

s32 func_80163764(void *arg0) {
    void *var_s0;
    s32 temp_s3;
    u32 var_s1;

    var_s1 = 0;
    var_s0 = &D_801202A0;
    temp_s3 = M2C_FIELD(arg0, s32 *, 0x4C);
loop_1:
    if ((M2C_FIELD(var_s0, u16 *, 0) != 0) && (M2C_FIELD(var_s0, u16 *, 0x5C) & 0x100) && (func_8014C278(arg0, var_s0, 0x40) != 0)) {
        func_801506A4(temp_s3, var_s0);
        return 1;
    }
    var_s1 += 1;
    var_s0 += 0x10C;
    if (var_s1 >= 0x60U) {
        return 0;
    }
    goto loop_1;
}
