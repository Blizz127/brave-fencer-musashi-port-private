/* Main-exec range [800422E8,80042374) from the SLUS executable.
 * SHA256(span)=efec1a52509d6c00b9f4e1a8a12c428816b4ed4a70521dc1aa115618f3f4d859.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B564;
extern s32 D_8006B574;
extern s32 D_8006B580;
extern s32 D_8006B584;
void func_8003AE14(u32);                               /* static */
u16 func_8003AF4C(s32, s32);                          /* static */

u32 func_800422E8(u32 arg1) {
    s32 temp_s0;
    u32 var_s1;

    var_s1 = arg1;
    if (var_s1 > 0x7EFF0U) {
        var_s1 = 0x7EFF0;
    }
    temp_s0 = D_8006B564 << D_8006B574;
    func_8003AE14(var_s1);
    D_8006B564 = func_8003AF4C(-1, temp_s0 + var_s1);
    if (D_8006B584 == 0) {
        D_8006B580 = 0;
    }
    return var_s1;
}
