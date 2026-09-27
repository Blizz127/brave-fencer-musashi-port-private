/* Overlay range [80138C60,80138D58) from MAIN.CD member 0012.
 * SHA256(span)=06c15678d5b582e4b6c8bfe78c85a0a5494eb8eecc5ef23bf652049ef7be6ad0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80139BE0(void *);                            /* static */
void func_80139C7C(void *);                            /* static */
s32 func_8013A8FC(void *);                          /* static */

s32 func_80138C60(void *arg0) {
    s32 temp_a0;
    s32 var_v0;
    u16 temp_v0;
    u8 temp_v1;

    var_v0 = 1;
    if (!(arg0->unk8 & 0x2000)) {
        temp_v0 = arg0->unk22 & 7 & 0xFF;
        arg0->unk18 = temp_v0;
        if (temp_v0 < 2U) {
            arg0->unk20 = 0;
        }
        temp_a0 = arg0->unk8;
        if (temp_a0 & 0x40) {
            arg0->unk22 = (u8) ((arg0->unk22 & 0x67) | (temp_a0 & ~0x67));
        }
        temp_v1 = arg0->unk22;
        if (temp_v1 & 0x80) {

        } else if (temp_v1 & 0x60) {
            arg0->unk1C = 0;
        }
        arg0->unk27 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
        func_80139BE0(arg0);
        func_80139C7C(arg0);
        var_v0 = func_8013A8FC(arg0);
    }
    return var_v0;
}
