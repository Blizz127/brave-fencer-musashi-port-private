/* Overlay range [801424E4,801425CC) from MAIN.CD member 0012.
 * SHA256(span)=f3425942c3d13023eb85a2fb9ef1daa59929c7c09d711e8c54db78a6ca2ffc53.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017F7A4;
void func_8012C218(void *);                            /* static */

void func_801424E4(void *arg0) {
    s16 var_v0;
    void *temp_a0;
    void *temp_a0_2;

    *(D_8017F7A4 + (arg0->unk2 * 4))();
    if (arg0->unk0 != 0) {
        if (arg0->unk70 != 0) {
            temp_a0 = arg0->unk64;
            if (temp_a0 != 0) {
                arg0->unk4 = (s32) temp_a0->unk4;
                var_v0 = temp_a0->unkA + arg0->unkFC;
                goto block_7;
            }
        } else {
            temp_a0_2 = arg0->unk64;
            if ((temp_a0_2 != 0) && (temp_a0_2->unk36 == arg0->unkFE)) {
                arg0->unk4 = (s32) temp_a0_2->unk4;
                var_v0 = arg0->unk64->unkA + arg0->unkFC;
block_7:
                arg0->unkA = var_v0;
                arg0->unkC = (s32) arg0->unk64->unkC;
                return;
            }
            func_8012C218(arg0);
        }
    }
}
