/* Overlay range [80148D44,80148E54) from MAIN.CD member 0012.
 * SHA256(span)=b7a38aaabe7342c5e69a5d82881fe62f8ea69aef450153a7357d972d094dbab4.
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
extern s32 D_8017FEB8;
extern void *D_801151D4;
extern u8 D_80126C01;
extern u16 D_80126C02;
extern u16 D_80126C06;

s16 func_80148D44(void) {
    s16 var_v0;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2;

    temp_a2 = D_801151D4->unk44;
    temp_a0 = (func_8004CFEC(temp_a2 - D_801151D4->unk50, D_801151D4->unk48 - D_801151D4->unk3C, temp_a2) - 0x400) & 0xFFF;
    if (D_80126C01 != 0x53) {
        if ((s32) D_80126C01 < 0x54) {
            if (D_80126C01 != 0x41) {
                return 0x41;
            }
            return *(D_8017FEB8 + (((u16) D_80126C02 >> 0xC) * 4))(temp_a0);
        }
        if (D_80126C01 != 0x73) {
            return 0x73;
        }
        goto block_7;
    }
block_7:
    temp_a0_2 = D_80126C06 & 0xFF;
    if ((temp_a0_2 != 0x80) || (var_v0 = -1, (((u16) D_80126C06 >> 8) != temp_a0_2))) {
        var_v0 = (temp_a0 + func_8004CFEC((D_80126C06 & 0xFF) - 0x80, 0x80 - ((u16) D_80126C06 >> 8))) & 0xFFF;
    }
    return var_v0;
}
