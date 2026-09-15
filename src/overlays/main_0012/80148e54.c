/* Overlay range [80148E54,80148F60) from MAIN.CD member 0012.
 * SHA256(span)=4d04462e5a1aabfc2d23f9efb915fced1d3926a5a33dac2edf43af258d09a1dc.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004CFEC(s32, s32, s32);                   /* extern */
extern s32 D_8017FEF8;
extern void *D_801151D4;

s16 func_80148E54(void *arg0) {
    s16 var_v0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;
    u16 temp_a1;
    u16 temp_v1_2;
    u8 temp_v1;

    temp_a2 = D_801151D4->unk44;
    temp_a0 = (func_8004CFEC(temp_a2 - D_801151D4->unk50, D_801151D4->unk48 - D_801151D4->unk3C, temp_a2) - 0x400) & 0xFFF;
    temp_v1 = arg0->unkA9;
    if (temp_v1 != 0x53) {
        if ((s32) temp_v1 < 0x54) {
            if (temp_v1 != 0x41) {
                return 0x41;
            }
            return *(D_8017FEF8 + (((u16) arg0->unkAA >> 0xC) * 4))(temp_a0);
        }
        if (temp_v1 != 0x73) {
            return 0x73;
        }
        goto block_7;
    }
block_7:
    temp_v1_2 = arg0->unkAE;
    temp_a0_2 = temp_v1_2 & 0xFF;
    if ((temp_a0_2 != 0x80) || (var_v0 = -1, ((temp_v1_2 >> 8) != temp_a0_2))) {
        temp_a1 = arg0->unkAE;
        var_v0 = (temp_a0 + func_8004CFEC((temp_a1 & 0xFF) - 0x80, 0x80 - (temp_a1 >> 8))) & 0xFFF;
    }
    return var_v0;
}
