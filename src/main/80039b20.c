/* Main-exec range [80039B20,80039C5C) from the SLUS executable.
 * SHA256(span)=bf46d17a0ebb02ea228a545c7de09963b48cd0c71de6cf222c28707ab413430b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073140;
extern s32 D_800762B0;
extern s32 *D_800762B4;
extern s32 D_800A2B98;
extern s32 *D_800C6DD0;
extern s32 *D_800C6DD4;
extern s32 D_800C7D20;

void func_80039B20(u8 **arg0, s16 arg1) {
    s16 var_a2;
    s32 *temp_a0_2;
    s32 var_a3;
    u8 *temp_v1;
    void *temp_a0;

    var_a2 = 0;
    temp_v1 = *arg0;
    var_a3 = 0;
    *arg0 = temp_v1 + 1;
    do {
        if (((arg0 + (arg1 * 0x1A) + var_a2)->unk23 != 0) && (*(&D_800C6DD4 + var_a3) == *temp_v1)) {
            temp_a0 = (var_a2 * 0x60) + &D_800C6DD0;
            if (temp_a0->unk5A != 0) {
                (temp_a0->unk50 + (temp_a0->unk6 * 0x1A) + var_a2)->unk23 = 0;
                temp_a0->unk5A = 0U;
            }
            temp_a0_2 = (var_a2 * 4) + D_80073140;
            D_800C7D20 &= ~*temp_a0_2;
            D_800A2B98 |= *temp_a0_2;
            *(D_800762B0 + var_a2) = 2;
            *(&D_800762B4 + var_a2) = 0;
        }
        var_a2 += 1;
        var_a3 += 0x60;
    } while (var_a2 < 0x10);
}
