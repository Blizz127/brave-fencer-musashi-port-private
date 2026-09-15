/* Overlay range [8014680C,801468C8) from MAIN.CD member 0012.
 * SHA256(span)=46400f2b1710c9a2eab8e09f99c041e41eccbc4ed4f2e455ebe99fde9e250ad9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_8011F9D0;
extern s32 *D_8011F9D6;
extern s32 *D_8011F9DA;
extern s32 *D_8011F9DE;
extern s32 *D_8011FA1C;
extern s32 *D_8011FA20;
extern s32 *D_8011FA24;

u16 *func_8014680C(void *arg0) {
    s32 var_a1;
    s32 var_a2;
    u16 *var_a3;
    u16 *var_v1;

    var_a2 = 0;
    var_a3 = &D_8011F9D0;
    var_v1 = &D_8011F9D0;
    var_a1 = 0;
loop_1:
    if (*var_v1 == 0) {
        *(&D_8011FA1C + var_a1) = M2C_FIELD(arg0, s32 *, 8);
        *var_v1 = M2C_FIELD(arg0, u16 *, 0);
        *(&D_8011F9D6 + var_a1) = M2C_FIELD(arg0, u16 *, 2);
        *(&D_8011F9DA + var_a1) = M2C_FIELD(arg0, u16 *, 4);
        *(&D_8011F9DE + var_a1) = M2C_FIELD(arg0, u16 *, 6);
        *(&D_8011FA20 + var_a1) = M2C_FIELD(arg0, s32 *, 0xC);
        *(&D_8011FA24 + var_a1) = M2C_FIELD(arg0, s32 *, 0x10);
        return var_a3;
    }
    var_a3 += 0x68;
    var_v1 += 0x68;
    var_a2 += 1;
    var_a1 += 0x68;
    if (var_a2 >= 8) {
        return 0;
    }
    goto loop_1;
}
