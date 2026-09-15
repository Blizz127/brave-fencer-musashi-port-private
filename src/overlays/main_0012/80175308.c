/* Overlay range [80175308,80175414) from MAIN.CD member 0012.
 * SHA256(span)=fe4680409f3f90f92997216a185f7f9a2f0940703e5b69d066fe61a9957dcf29.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(s8 *, s32, void *, s8 *); /* extern */
void func_800596F4();                     /* extern */
void func_801757A0(s16);                         /* static */
extern s32 *D_80078E78;
extern s16 D_800B9A02;
extern s8 D_8011F7A8;
extern s8 D_8011F7A9;
extern s8 D_8011F7AE;
extern s16 D_8011F7B4;
extern s16 D_8011F7B6;
extern s16 D_8011F7B8;
extern s16 D_8011F7BA;
extern s16 D_8011F7BC;
extern s16 D_8011F7BE;

void func_80175308(void) {
    void *var_a2;
    s8 *var_a3;

    var_a3 = &D_8011F7A8 + 0x48;
    var_a2 = &D_80078E78;
    D_8011F7A8 = 1;
    D_8011F7A9 = 2;
    D_8011F7AE = 0x37;
    D_8011F7B8 = -0x37;
    D_8011F7B4 = -0x37;
    D_8011F7BE = 0x37;
    D_8011F7BA = 0x37;
    D_8011F7B6 = 0x37;
    D_8011F7BC = 0x37;
    do {
        M2C_FIELD(var_a3, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
        M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
        M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
        M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (&D_80078E78 + 0x90));
    M2C_FIELD(var_a3, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
    M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
    func_80016714(&D_8011F7A8 + 0xE0, 0x98, var_a2, var_a3);
    func_801757A0(D_800B9A02);
    func_800596F4(0);
    func_801757A0((s16) ((u16) D_800B9A02 ^ 1));
}
