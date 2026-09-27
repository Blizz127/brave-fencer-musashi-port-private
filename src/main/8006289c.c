/* Main-exec range [8006289C,8006291C) from the SLUS executable.
 * SHA256(span)=8c0a09acdea68ea35583f6365f0e6d6a4440860d0d87ca7c91a9c577620ed5c6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072A34;
extern s32 D_80074734;
void func_8005C604(s32 (*)(), s32);                      /* static */
extern s32 *D_80078D44;
extern s32 *D_80078D78;

void func_8006289C(s32 arg0) {
    s32 *var_v1;
    s32 temp_a2;
    s32 var_a1;

    temp_a2 = D_80072A34 + 1;
    if (temp_a2 >= 4) {
        func_8005C604(D_80074734, temp_a2);
        return;
    }
    var_a1 = 3;
    var_v1 = (temp_a2 * 0x10) + &D_80078D44;
    D_80072A34 = temp_a2;
    *(&D_80078D78 + (temp_a2 * 4)) = arg0;
    do {
        *var_v1 = 0;
        var_a1 -= 1;
        var_v1 -= 4;
    } while (var_a1 >= 0);
}
