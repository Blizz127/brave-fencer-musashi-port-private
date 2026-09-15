/* Overlay range [80146750,8014680C) from MAIN.CD member 0012.
 * SHA256(span)=41bb9a073aabd8da638ef6808116eb0452f7e7b1f3fd9aecc32ab41f297aa535.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8011F9D6;
extern s32 *D_8011F9DA;
extern s32 *D_8011F9DE;
extern s32 *D_8011FA1C;
extern s32 *D_8011FA20;
extern s32 *D_8011FA24;
extern u16 D_8011FD10;

u16 *func_80146750(void *arg0) {
    s32 var_a1;
    s32 var_a2;
    u16 *var_a3;
    u16 *var_v1;

    var_a2 = 8;
    var_a3 = &D_8011FD10;
    var_v1 = &D_8011FD10;
    var_a1 = 0x340;
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
    if (var_a2 >= 0x14) {
        return 0;
    }
    goto loop_1;
}
