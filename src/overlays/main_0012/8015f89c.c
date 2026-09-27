/* Overlay range [8015F89C,8015F948) from MAIN.CD member 0012.
 * SHA256(span)=71bb9524117d7daf2f481bf15f4700e1aab262ddf70ef60f948e5357477802b0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180A1C;
void func_801466F0(s32, void *, s32, s32, s32, s32, s32, s32); /* static */
void func_80147078(void *, s32);                         /* static */
void func_80159B70(void *);                            /* static */
void func_80161208(void *);                            /* static */

void func_8015F89C(void *arg0) {
    u16 temp_v1;

    temp_v1 = arg0->unkB8;
    if (!(temp_v1 & 0x4000)) {
        if (temp_v1 & 0x8000) {
            *(D_80180A1C + (arg0->unk0 * 4))(arg0);
            func_80147078(arg0, 0);
            func_80159B70(arg0);
            return;
        }
        goto block_4;
    }
    func_801466F0(1, arg0, 0, -0x1E, 0, 0, 0, 0);
block_4:
    func_80161208(arg0);
}
