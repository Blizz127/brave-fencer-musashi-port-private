/* Overlay range [8013E6AC,8013E814) from MAIN.CD member 0012.
 * SHA256(span)=987b57a99c44db5041a78875480632fa97931d199b34a7c086f5b79c3aae54aa.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

u32 func_80029504(s32);                             /* extern */
extern s32 D_8017F6FA;
extern s32 D_8017F720;
void func_8013E83C();                                  /* static */
extern u8 D_80078EC0;
extern s16 D_800B9A08;
extern s32 *D_80115110;
extern u16 D_80115112;
extern s16 D_8011511A;
extern s16 D_80115124;
extern s32 *D_80115140;
extern s32 *D_80115148;
extern s32 *D_80115188;
extern s16 D_8017F6F8;

void func_8013E6AC(void) {
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_a3;
    s16 var_a3_2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_v0;

    func_8013E83C();
    var_a3 = 0;
    D_8011511A = 0;
    D_80115124 = (s16) D_80078EC0;
    var_v0 = 0 << 0x10;
    do {
        temp_v1 = var_a3 + 1;
        var_a3 = temp_v1;
        temp_v0 = var_v0 >> 0x10;
        temp_a0 = temp_v0 * 2;
        *(&D_80115148 + temp_a0) = 0;
        *(&D_80115140 + temp_v0) = 0;
        var_v0 = var_a3 << 0x10;
    } while (temp_v1 < 8);
    if ((func_80029504(temp_a0) >= 5U) && (D_800B9A08 != 0x302A)) {
        var_a3_2 = 0;
        if (D_800B9A08 != 0x3073) {
            var_a1 = 0 << 0x10;
            do {
                temp_v1_2 = var_a3_2 + 1;
                var_a3_2 = temp_v1_2;
                temp_a1 = var_a1 >> 0xE;
                temp_v0_2 = (s32) (*(temp_a1 + D_8017F720) * 3) >> 2;
                (temp_a1 + &D_80115110)->unk58 = temp_v0_2;
                *(&D_80115188 + temp_a1) = temp_v0_2;
                var_a1 = var_a3_2 << 0x10;
            } while (temp_v1_2 < 5);
            D_8017F6F8 = 2;
            D_8017F6FA = 1;
            D_80115112 += 1;
            return;
        }
    }
    func_8013E83C();
    D_8011511A = 7;
    D_8017F6FA = 0;
    D_8017F6F8 = 0;
    D_80115112 = 6;
}
