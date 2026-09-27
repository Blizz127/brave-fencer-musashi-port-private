/* Overlay range [8013D8FC,8013D9B0) from MAIN.CD member 0012.
 * SHA256(span)=d0c956ff69cc28d2bf174ad4a8406af376d275da1c8484ce9db8ee3ce0179917.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800599B8(u16 *, s32);                  /* extern */
extern s32 D_801841AC;

void func_8013D8FC(void) {
    u16 sp16;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    u16 *var_s1;
    u16 var_a0;
    void *var_s0;

    var_s1 = D_801841AC;
    if (var_s1 != 0) {
        var_a0 = *var_s1;
        if ((var_a0 & 0xFFFF) != 0xFF) {
            var_s0 = var_s1 + 0xA;
            do {
                if (var_a0 == 9) {
                    sp10 = M2C_FIELD(var_s0, u16 *, -6);
                    sp12 = M2C_FIELD(var_s0, u16 *, -4);
                    sp14 = (u16) M2C_FIELD(var_s0, s16 *, -2);
                    sp16 = M2C_FIELD(var_s0, u16 *, 0);
                    func_800599B8(&sp10, M2C_FIELD(var_s0, s32 *, 2) + (M2C_FIELD(var_s0, s16 *, -2) * 2));
                }
                var_s1 += 0x10;
                var_a0 = *var_s1;
                var_s0 += 0x10;
            } while (var_a0 != 0xFF);
        }
    }
}
