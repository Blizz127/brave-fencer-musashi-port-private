/* Overlay range [8013F138,8013F1BC) from MAIN.CD member 0012.
 * SHA256(span)=7e9c38c9ed5b5858ec6d12c232df20eda51b6258908c8376b8fcef80fbcd4e9e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017F6FC;
void func_801376E8(s32, s32 (*)());                      /* static */
s32 func_80141CA4();                                /* static */
extern u16 D_80115110;
extern u16 D_80115112;
extern u16 D_80115118;

void func_8013F138(void) {
    u16 temp_v0;

    temp_v0 = D_80115118 + 0x10;
    D_80115118 = temp_v0;
    if ((u32) (temp_v0 & 0xFFFF) >= 0x40U) {
        if (D_80115110 == 0) {
            func_801376E8(func_80141CA4(), D_8017F6FC);
        }
        D_80115112 += 1;
    }
}
