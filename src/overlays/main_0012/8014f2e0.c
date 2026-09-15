/* Overlay range [8014F2E0,8014F3E8) from MAIN.CD member 0012.
 * SHA256(span)=2715f0361ffae8cf26ee32c39ea38abcd4f788fad022e1263302aa70d8cb03ca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135A4C(s32, s32, s32, s32);      /* static */
extern s32 D_801150D8;
extern u16 D_801202A0;

s32 func_8014F2E0(void *arg0, s32 arg1, s32 arg2) {
    s32 var_s3;
    u16 *temp_v1;
    u16 *var_s0;
    u16 *var_s1;

    var_s3 = 0;
    var_s0 = &D_801202A0;
    temp_v1 = &D_801202A0 + 0x6480;
    if ((u32) &D_801202A0 < (u32) temp_v1) {
        var_s1 = &D_801202A0 + 0x58;
        do {
            if ((*var_s0 != 0) && (M2C_FIELD(var_s1, s32 *, 0) != 0) && (var_s0 != M2C_FIELD(arg0, s32 *, 0x178)) && (var_s0 != M2C_FIELD(arg0, s32 *, 0x174)) && (M2C_FIELD(var_s1, s32 *, 4) & 0x1800)) {
                D_801150D8 = 0;
                if (func_80135A4C(M2C_FIELD(var_s1, s32 *, -0x38), M2C_FIELD(var_s1, s32 *, 0), arg1, arg2) != 0) {
                    var_s3 = 1;
                }
            }
            var_s0 += 0x10C;
            var_s1 += 0x10C;
        } while ((u32) var_s0 < (u32) temp_v1);
    }
    return var_s3;
}
