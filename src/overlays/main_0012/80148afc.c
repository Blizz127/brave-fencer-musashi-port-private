/* Overlay range [80148AFC,80148C18) from MAIN.CD member 0012.
 * SHA256(span)=8c22a26364ace265c0b6cbba89c9e763cb0be990cf80ae5875b5f8835069e13c.
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
extern s32 D_8017FE78;
extern void *D_801151D4;

s32 func_80148AFC(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 var_v0;
    u16 temp_a1_2;
    u16 temp_v1_2;
    u8 temp_v1;
    void *temp_s2;

    temp_s2 = arg0->unk20;
    temp_a2 = D_801151D4->unk44;
    temp_a1 = (func_8004CFEC(temp_a2 - D_801151D4->unk50, D_801151D4->unk48 - D_801151D4->unk3C, temp_a2) - 0x400) & 0xFFF;
    temp_v1 = arg0->unkA9;
    if (temp_v1 != 0x53) {
        if ((s32) temp_v1 < 0x54) {
            if (temp_v1 != 0x41) {
                return 0x41;
            }
            return *(D_8017FE78 + (((u16) arg0->unkAA >> 0xC) * 4))(arg0, temp_a1) & 0xFF;
        }
        if (temp_v1 != 0x73) {
            return 0x73;
        }
        goto block_7;
    }
block_7:
    temp_v1_2 = arg0->unkAE;
    temp_a0 = temp_v1_2 & 0xFF;
    if ((temp_a0 != 0x80) || (var_v0 = 0, ((temp_v1_2 >> 8) != temp_a0))) {
        temp_a1_2 = arg0->unkAE;
        var_v0 = 1;
        temp_s2->unk12 = (s16) ((temp_a1 + func_8004CFEC((temp_a1_2 & 0xFF) - 0x80, 0x80 - (temp_a1_2 >> 8))) & 0xFFF);
    }
    return var_v0;
}
