/* Overlay range [8013E958,8013EA54) from MAIN.CD member 0012.
 * SHA256(span)=adc66e924550c08d86247483f3f1fb7e36079b576534264563ce5f4242806ca0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800D0488(s16);                             /* extern */
extern s32 D_8017F720;
void func_80139954();                                  /* static */
void func_80141C0C(s32, void *, s16, s32 (*)());           /* static */
void func_8014AA28();                                  /* static */
extern u8 D_80078EC0;
extern s8 D_800B9A15;
extern s32 *D_80115110;
extern s16 D_80115112;
extern s16 D_80115124;
extern s32 *D_80115188;

void func_8013E958(void) {
    s16 temp_v0_2;
    s16 temp_v1;
    s16 var_a2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a0;
    void *temp_a1;

    D_800B9A15 = 0;
    func_80139954();
    if ((D_80078EC0 != D_80115124) && (func_8014AA28(), temp_v0 = D_80078EC0 & 0x7F, temp_v0_2 = temp_v0 & 0xFF, (temp_v0 != 0))) {
        D_80115124 = temp_v0_2;
        if (temp_v0_2 != 0) {
            var_a2 = 0;
            if (func_800D0488(temp_v0_2) != 0) {
                goto block_4;
            }
        } else {
            goto block_5;
        }
    } else {
block_4:
        D_80115124 = 0;
block_5:
        var_a2 = 0;
    }
    var_a0 = 0 << 0x10;
    do {
        temp_v1 = var_a2 + 1;
        var_a2 = temp_v1;
        temp_a0 = var_a0 >> 0xE;
        temp_a1 = temp_a0 + &D_80115110;
        temp_v0_3 = (s32) *(temp_a0 + D_8017F720) >> 6;
        temp_a1->unk58 = temp_v0_3;
        *(&D_80115188 + temp_a0) = temp_v0_3;
        var_a0 = var_a2 << 0x10;
    } while (temp_v1 < 5);
    func_80141C0C(7, temp_a1, var_a2, D_8017F720);
    D_80115112 = 4;
}
