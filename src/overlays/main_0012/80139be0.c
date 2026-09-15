/* Overlay range [80139BE0,80139C7C) from MAIN.CD member 0012.
 * SHA256(span)=7b8a9866ce4a7b5531597372b73283e05bc955ebd4a8c580af1ec71695472958.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017E94C;

void func_80139BE0(void *arg0) {
    s16 temp_v1_2;
    u16 temp_v1;
    u8 var_v1;

    if (!(arg0->unk8 & 0x2000)) {
        temp_v1 = arg0->unk18;
        if (((s32) temp_v1 < 7) && ((s32) temp_v1 >= 2)) {
            var_v1 = *(D_8017E94C + ((u32) (arg0->unk22 & 0x60 & 0xFF) >> 5));
        } else {
            var_v1 = D_8017E94C;
        }
        arg0->unk2E = 3;
        arg0->unk2C = (s16) var_v1;
    }
    temp_v1_2 = arg0->unk2E;
    arg0->unk34 = (s16) (arg0->unk2C * 6);
    arg0->unk36 = (s16) ((temp_v1_2 * 0xC) + ((temp_v1_2 - 1) * 2));
}
