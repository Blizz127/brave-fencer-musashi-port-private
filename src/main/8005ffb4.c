/* Main-exec range [8005FFB4,80060030) from the SLUS executable.
 * SHA256(span)=d3727214946fec8e3983a8a210373271ab990453c1982bde94d3c915c8e18bbf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80060030;
extern s32 D_800744C0;
void func_8005C604(s32 (*)(), s32);                      /* static */
void func_8006289C(void *, s32);                          /* static */
extern s32 D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078C8C;

s32 func_8005FFB4(s32 arg0) {
    if (D_80078C80 == 0) {
        D_80078C80 = 2;
        D_80078C84 = 0;
        D_80078C88 = 0;
        D_80078C8C = arg0;
        func_8006289C(&D_80060030, arg0);
        return 1;
    }
    func_8005C604(D_800744C0, arg0);
    return 0;
}
