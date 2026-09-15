/* Overlay range [8014AC10,8014ACC0) from MAIN.CD member 0012.
 * SHA256(span)=efa92082737fa88553c026514006c59ae3efc5abfb2eadb838b145dbfc8717e1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(u16 *, s32);              /* extern */
extern u16 D_8011D030;

void func_8014AC10(s32 arg0) {
    s32 var_a1;
    u16 *temp_a0;
    u16 *temp_v1;
    u16 *var_s0;

    var_s0 = &D_8011D030;
    temp_v1 = &D_8011D030 + 0xA50;
    if ((u32) &D_8011D030 < (u32) temp_v1) {
        do {
            if (M2C_FIELD(var_s0, u16 *, 0) == arg0) {
                temp_a0 = M2C_FIELD(var_s0, u16 **, 0x20);
                if (temp_a0 != 0) {
                    var_a1 = 0x38;
                    if (*temp_a0 == 1) {
                        var_a1 = 0x84;
                    }
                    func_80016714(temp_a0, var_a1);
                }
                func_80016714(var_s0, 0x58);
            }
            var_s0 += 0x58;
        } while ((u32) var_s0 < (u32) temp_v1);
    }
}
