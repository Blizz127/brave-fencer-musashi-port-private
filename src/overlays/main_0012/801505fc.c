/* Overlay range [801505FC,801506A4) from MAIN.CD member 0012.
 * SHA256(span)=4d4082974a3e2797ed3d963da182e74eeb684b2bbab29aab1248dff25a92781f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C278(s32, void *, s32);         /* static */
void func_801506A4(s32, void *);              /* static */
extern s32 *D_801202A0;

s32 func_801505FC(s32 arg0) {
    void *var_s0;
    void *temp_v1;

    var_s0 = &D_801202A0;
    temp_v1 = &D_801202A0 + 0x6480;
    if ((u32) &D_801202A0 < (u32) temp_v1) {
loop_2:
        if ((M2C_FIELD(var_s0, u16 *, 0) != 0) && (M2C_FIELD(var_s0, u16 *, 0x5C) & 0x100) && (func_8014C278(arg0, var_s0, 0x30) != 0)) {
            func_801506A4(arg0, var_s0);
            return 1;
        }
        var_s0 += 0x10C;
        if ((u32) var_s0 >= (u32) temp_v1) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}
