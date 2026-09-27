/* Main-exec range [80061524,800615BC) from the SLUS executable.
 * SHA256(span)=f06792eec86644ab5b78a846bead497c39b0869fe4d8c995e8d8bb0681dce9b5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80074610;
void func_8005C604(s32 (*)());                           /* static */
s32 func_80061678(s32);                             /* static */
void func_80061770(void *);                               /* static */
void func_80061B58();                                  /* static */
s32 func_80061D3C();                                /* static */
void func_80061F78(void *);                               /* static */
extern s32 D_80078C7C;
extern s32 D_80078C80;
extern s32 D_80078C8C;

s32 func_80061524(void) {
    s32 sp10;
    if (D_80078C80 == 0) {
        D_80078C7C |= 1 << D_80078C8C;
        func_80061770(&sp10);
        func_80061B58();
        func_80061F78(&sp10);
        return func_80061678(func_80061D3C());
    }
    func_8005C604(D_80074610);
    return -1;
}
