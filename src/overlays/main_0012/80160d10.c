/* Overlay range [80160D10,80160DEC) from MAIN.CD member 0012.
 * SHA256(span)=ab6efa723fac9a80f29b99a7454d2cc1f5e0f54a8b60f6db748e81024b9a5fca.
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
void func_80147078(void *, s32);                         /* static */
s32 func_80148800(void *);                          /* static */
void func_80159B70(void *);                            /* static */
void func_80161208(void *);                            /* static */

void func_80160D10(void *arg0) {
    s32 (*var_v0)();
    s32 temp_v0;
    s32 temp_v1;

    if (arg0->unk44 & 0x10) {
        var_v0 = *(D_80180A1C + (arg0->unk0 * 4));
        goto block_7;
    }
    temp_v1 = arg0->unk1AC;
    if (temp_v1 == 0) {
        if (func_80148800(arg0) & 0xF0) {
            goto block_6;
        }
        goto block_8;
    }
    temp_v0 = temp_v1 + 0xFFFF5558;
    arg0->unk1AC = temp_v0;
    if (temp_v0 < 0) {
block_6:
        var_v0 = *(D_80180A1C + (arg0->unk0 * 4));
block_7:
        var_v0(arg0);
        func_80147078(arg0, 0);
        func_80159B70(arg0);
        return;
    }
block_8:
    func_80161208(arg0);
}
