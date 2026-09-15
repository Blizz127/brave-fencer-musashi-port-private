/* Main-exec range [80018194,8001820C) from the SLUS executable.
 * SHA256(span)=3eae54476c1a0728f9d7b74f960d5ec1172ea9e20168d925f2bdf18079f1ada1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80058C6C(s32, void *, s32, void *);    /* static */
extern s32 *D_800A651C;
extern u16 D_800B9A02;

void func_80018194(void *arg0, u32 arg1, s32 arg2) {
    s32 temp_a2;
    u32 var_a1;

    var_a1 = arg1;
    temp_a2 = arg2 & 0x40000000;
    if (temp_a2 != 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x02000000);
    }
    if (var_a1 >= 0x1000U) {
        var_a1 = 0xFFF;
    }
    func_80058C6C(*(&D_800A651C + (D_800B9A02 * 0x14)) + (var_a1 * 4), arg0, temp_a2, arg0);
}
