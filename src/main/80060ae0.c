/* Main-exec range [80060AE0,80060BEC) from the SLUS executable.
 * SHA256(span)=54e0239f9cc5894e02f3ff6b19a37f897389d18d8cdf814594beb616b17ac88c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80060BEC;
extern s32 D_800745EC;
extern s32 D_80074610;
void func_8005C604(s32 (*)());                           /* static */
void func_80061770(s32, s32 *);                        /* static */
void func_80061E90(s32 *, s32);                          /* static */
void func_8006289C(void *);                               /* static */
extern s32 D_80078C80;
extern s32 D_80078C84;
extern s32 D_80078C88;
extern s32 D_80078C8C;
extern s32 D_80078C94;
extern s32 D_80078C98;
extern s32 D_80078C9C;

s32 func_80060AE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 (*var_a0)();
    s32 *temp_s0;

    if (D_80078C80 != 0) {
        var_a0 = D_80074610;
        goto block_5;
    }
    if (!(arg4 & 0x7F)) {
        temp_s0 = &D_80078C80 + 0x20;
        func_80061770(arg0, temp_s0);
        func_80061E90(temp_s0, arg1);
        D_80078C80 = 4;
        D_80078C84 = 0;
        D_80078C88 = 0;
        D_80078C94 = arg3;
        D_80078C9C = arg2;
        D_80078C98 = arg4;
        D_80078C8C = arg0;
        func_8006289C(&D_80060BEC);
        return 1;
    }
    var_a0 = D_800745EC;
block_5:
    func_8005C604(var_a0);
    return 0;
}
