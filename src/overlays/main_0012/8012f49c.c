/* Overlay range [8012F49C,8012F568) from MAIN.CD member 0012.
 * SHA256(span)=b48f1cb83ceaedd705135e532b0fef235821a4da7fe5a1fb065b1a8c2a3b8d03.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004914C(void *);                   /* extern */
void func_800491AC(void *);                   /* extern */
void func_8004945C(s32, void *, s32 *);   /* extern */
void func_8004955C(void *, s32 *, void *, s32 *); /* extern */
extern s32 *D_800AF648;

void func_8012F49C(s32 *arg0, void *arg1, s32 arg2) {
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp18;
    s32 sp10;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg1, s32 *, 0x20) + 0x34;
    func_8004914C(temp_s0);
    func_800491AC(temp_s0);
    func_8004945C(arg2, &sp10, &sp18);
    sp20 = 0;
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    func_8004955C(&sp10, &sp20, &sp24, &sp28);
    if (sp28 < 0) {
        sp20 = 0;
        sp18 = 0;
    } else {
        sp18 = sp20;
    }
    *arg0 = sp18;
}
