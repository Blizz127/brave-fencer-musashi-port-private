/* Overlay range [80178744,801787D4) from MAIN.CD member 0012.
 * SHA256(span)=b3a12e4bd639082008c908b1d91e5619f8bf79d6f47baf9b8b813f85676a8d25.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80178744(void *arg0, s16 arg1) {
    s16 var_v0;
    void *temp_a0;
    void *temp_v0;

    temp_a0 = arg0->unk6C;
    if (temp_a0 != 0) {
        func_80178744(temp_a0);
    }
    temp_v0 = arg0->unk20;
    temp_v0->unk1C = arg1;
    temp_v0->unk1A = arg1;
    temp_v0->unk18 = arg1;
    if (arg1 == 0x1000) {
        var_v0 = arg0->unk20->unk2C & 0xFFEF;
    } else {
        var_v0 = arg0->unk20->unk2C | 0x10;
    }
    arg0->unk20->unk2C = var_v0;
}
