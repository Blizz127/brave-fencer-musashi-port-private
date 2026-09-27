/* Main-exec range [80044F24,80045090) from the SLUS executable.
 * SHA256(span)=dd30bee97c2a3f112b4ef65b2f9eacf20155137d9ac5c63e76f62e5a7f991f7c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CCA5;
extern s32 D_8006CCAC;
extern s32 D_8006CD2C;
extern s32 *D_8006CF90;
extern s32 D_80073758;
extern s32 D_80073768;
extern s32 D_80073860;
s32 func_8004239C();                               /* static */
void func_80044B14();                                  /* static */
void func_8005C604(s32 (*)(), s32 (*)(), s32, s32, s32);   /* static */
void func_8005CD48(s32 (*)());                           /* static */
extern s32 D_8006CF64;
extern s32 D_800763F0;
extern s32 D_800763F4;
extern s32 (*D_800763F8)();

s32 func_80044F24(s32 arg0) {
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;

    D_800763F0 = func_8004239C(-1) + 0x3C0;
    D_800763F4 = 0;
    D_800763F8 = D_80073860;
loop_1:
    if ((D_800763F0 < func_8004239C(-1)) || (temp_v1 = D_800763F4, D_800763F4 = temp_v1 + 1, ((temp_v1 > 0x3C0000) != 0))) {
        func_8005CD48(D_80073758);
        func_8005C604(D_80073768, D_800763F8, *((D_8006CCA5 * 4) + D_8006CCAC), *((D_8006CF64.unk0 * 4) + D_8006CD2C), *((D_8006CF64.unk1 * 4) + D_8006CD2C));
        func_80044B14();
        var_v0_2 = -1;
    } else {
        var_v0_2 = 0;
    }
    var_v0 = -1;
    if (var_v0_2 == 0) {
        var_v0 = 0;
        if (*D_8006CF90 & 0x01000000) {
            var_v0 = 1;
            if (arg0 == 0) {
                goto loop_1;
            }
        }
    }
    return var_v0;
}
