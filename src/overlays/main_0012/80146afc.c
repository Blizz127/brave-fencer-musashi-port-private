/* Overlay range [80146AFC,80146B9C) from MAIN.CD member 0012.
 * SHA256(span)=abb974d6d9abe4e3d6c428d737ea780e122bca15ed107aae953f303858f70768.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_8011D030;

u16 *func_80146AFC(void *arg0) {
    u16 *temp_v1;
    u16 *var_a1;
    u16 *var_a2;

    var_a2 = &D_8011D030;
    temp_v1 = &D_8011D030 + 0xA50;
    if ((u32) &D_8011D030 < (u32) temp_v1) {
        var_a1 = &D_8011D030 + 0x30;
loop_2:
        if (*var_a2 == 0) {
            M2C_FIELD(var_a1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 8);
            *var_a2 = M2C_FIELD(arg0, u16 *, 0);
            M2C_FIELD(var_a1, u16 *, -0x2A) = (u16) M2C_FIELD(arg0, u16 *, 2);
            M2C_FIELD(var_a1, u16 *, -0x26) = (u16) M2C_FIELD(arg0, u16 *, 4);
            M2C_FIELD(var_a1, u16 *, -0x22) = (u16) M2C_FIELD(arg0, u16 *, 6);
            M2C_FIELD(var_a1, s32 *, -4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
            M2C_FIELD(var_a1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
            return var_a2;
        }
        var_a2 += 0x58;
        var_a1 += 0x58;
        if ((u32) var_a2 >= (u32) temp_v1) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_2;
    }
    return 0;
}
