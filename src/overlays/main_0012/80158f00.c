/* Overlay range [80158F00,80158FA4) from MAIN.CD member 0012.
 * SHA256(span)=e7ffd0059d4b96ceba056464a699b4e19d80847969872df5b150a4ea6671f6e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C49C(s32);                             /* extern */
extern s32 D_801806F0;
extern s32 D_80184294;
s32 func_8013767C(s32, s32);                        /* static */
void func_80146CA0(void *);                            /* static */

void func_80158F00(void *arg0) {
    s32 temp_ret;
    void *temp_v0;

    temp_v0 = arg0->unk20;
    temp_v0->unk12 = (u16) ((temp_v0->unk12 + 0x16) & 0xFFF);
    if (D_80184294 == 0) {
        temp_ret = func_8005C49C(D_80184294);
        arg0->unk198 = func_8013767C(*(D_801806F0 + ((temp_ret % 11) * 4)), MULT_HI(temp_ret, 0x2E8BA2E9));
        func_80146CA0(arg0);
    }
}
