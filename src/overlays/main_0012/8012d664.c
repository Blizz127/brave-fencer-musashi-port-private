/* Overlay range [8012D664,8012D714) from MAIN.CD member 0012.
 * SHA256(span)=c231a14ec0c5321ffdf04b84a496655f3e7931cf9102a8b21d6134012992c2f6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800132BC(u16 *);                           /* extern */
extern s32 D_8017E6BC;
void func_8012F568(s32, s32, s32, s32, s32, s32 (*)());          /* static */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;

s32 func_8012D664(s32 arg0, s32 arg1, s32 arg2) {
    u16 sp1C;
    s16 sp1A;
    u16 sp18;
    s32 temp_s0;

    sp18 = D_80126B5E;
    sp1C = D_80126B66;
    sp1A = D_80126B62 - 0x40;
    temp_s0 = arg1 + 0x20;
    if (func_800132BC(&sp18) >= (temp_s0 * temp_s0)) {
        return 0;
    }
    func_8012F568(1, 1, 0, arg2, arg0, D_8017E6BC);
    return 1;
}
