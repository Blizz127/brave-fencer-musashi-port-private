/* Overlay range [801775E0,801776EC) from MAIN.CD member 0012.
 * SHA256(span)=d8d21964ce3b9ba75342fce9751fcf3e2077b7dde02ca55d3d882a902965177a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801776EC(void *);                      /* static */
extern s32 *D_8011F7F0;
extern u8 D_8011F837;
extern u8 D_8011F83B;

void func_801775E0(void *arg0, s16 arg1) {
    s8 var_v0;
    u32 temp_v1;
    void *temp_s0;

    if (D_8011F83B != 0) {
        if (((s32) D_8011F83B >= 0) && ((s32) D_8011F83B < 0xF7)) {
            if ((s32) D_8011F83B >= 0xF3) {
                goto block_7;
            }
            goto block_9;
        }
block_9:
        M2C_FIELD(arg0, s8 *, 5) = 0xFF;
        M2C_FIELD(arg0, s8 *, 6) = 0x10;
        M2C_FIELD(arg0, s8 *, 4) = 0x10;
    } else if (D_8011F837 != 0x80) {
        M2C_FIELD(arg0, s8 *, 4) = 0xFF;
        M2C_FIELD(arg0, s8 *, 6) = 0x10;
        M2C_FIELD(arg0, s8 *, 5) = 0x10;
    } else {
block_7:
        func_801776EC(arg0);
    }
    temp_v1 = (u32) (M2C_FIELD(&D_8011F7F0, u8 *, 0x47) * 9) >> 4;
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) temp_v1;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) ((arg1 + 0x48) - temp_v1);
    temp_s0 = arg0 + 0x14;
    if (M2C_FIELD(&D_8011F7F0, u8 *, 0x47) != 0) {
        var_v0 = 0xA0;
    } else {
        var_v0 = 0x40;
    }
    M2C_FIELD(temp_s0, s8 *, 6) = var_v0;
    M2C_FIELD(temp_s0, s16 *, 0xA) = arg1;
}
