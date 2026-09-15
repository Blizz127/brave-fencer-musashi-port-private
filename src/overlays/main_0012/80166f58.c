/* Overlay range [80166F58,8016706C) from MAIN.CD member 0012.
 * SHA256(span)=08d02cee4615235bf789e19a6f1f18237b9fe126355f7d92b8f3002dc9931679.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(void *, s32);             /* extern */
extern s32 D_80184418;
void func_80146C3C(void *);                   /* static */
extern s32 *D_8011D030;

void func_80166F58(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    void *var_s0;
    s16 var_s2;
    s16 var_v0;
    u16 temp_v0;

    var_s2 = 0;
    var_s0 = &D_8011D030;
    do {
        var_v0 = var_s2 + 1;
        if ((var_s0 != arg0) && ((temp_v0 = M2C_FIELD(var_s0, u16 *, 0), (temp_v0 == arg1)) || (var_v0 = var_s2 + 1, (temp_v0 == arg2))) && ((arg1 != arg2) || (var_v0 = var_s2 + 1, (M2C_FIELD(var_s0, s32 *, 0x2C) == M2C_FIELD(arg0, s32 *, 0x2C))))) {
            func_80146C3C(var_s0);
            var_v0 = var_s2 + 1;
        }
        var_s2 = var_v0;
        var_s0 += 0x58;
    } while (var_v0 < 0x1E);
    func_80016714((arg3 * 0xC4) + D_80184418, 0xC4);
}
