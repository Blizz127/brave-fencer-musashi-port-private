/* Main-exec range [80011EB4,800120C4) from the SLUS executable.
 * SHA256(span)=8ce37486f205bce88e1e1fc8e905ae1fef2674455643c410173997a432390e23.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800629D0;
extern s32 D_80074788;
extern s32 D_80074790;
extern s32 D_80074794;
extern s32 D_80074798;
void func_800120C4(void *);                               /* static */
u16 func_800149E0();                               /* static */
u16 func_80014B10();                               /* static */
extern s32 *D_80700000;

void func_80011EB4(void *arg0) {
    u16 sp10;
    void *var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;

    var_a0 = arg0;
    if (D_800629D0 != 1) {
        if (D_800629D0 < 2) {
            if (D_800629D0 != 0) {
                func_800120C4();
                return;
            }
            sp10 = func_80014B10(0);
            *((D_80074788 * 2) + &D_80700000) = sp10;
            D_80074788 = (s32) (D_80074788 + 1);
            sp10 = func_800149E0(0);
            *((D_80074788 * 2) + &D_80700000) = sp10;
            D_80074788 = (s32) (D_80074788 + 1);
            func_800120C4();
            return;
        }
        if (D_800629D0 != 2) {
            func_800120C4();
            return;
        }
        temp_v0 = D_80074788;
        D_80074788 = (s32) (temp_v0 + 1);
        D_80074794 = (u16) *((temp_v0 * 2) + &D_80700000);
        temp_v0_2 = D_80074788;
        D_80074788 = (s32) (temp_v0_2 + 1);
        D_80074798 = (u16) *((temp_v0_2 * 2) + &D_80700000);
        func_800120C4(&D_80700000);
        return;
    }
    if (D_80074790 != 0) {
        temp_v0_3 = D_80074788;
        D_80074788 = (s32) (temp_v0_3 + 1);
        D_80074794 = (u16) *((temp_v0_3 * 2) + D_80074790);
        temp_v0_4 = D_80074788;
        D_80074788 = (s32) (temp_v0_4 + 1);
        var_a0 = D_80074790;
        D_80074798 = (u16) *((temp_v0_4 * 2) + var_a0);
    } else {
        D_80074794 = 0U;
        D_80074798 = 0U;
    }
    func_800120C4(var_a0);
}
