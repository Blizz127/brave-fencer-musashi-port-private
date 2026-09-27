/* Main-exec range [800615BC,80061678) from the SLUS executable.
 * SHA256(span)=3126b5613526824b48c0539a38120a09053152e272a6732efb5627777acfe356.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80074610;
void func_8005C604(s32 (*)());               /* static */
void func_80061B58();                            /* static */
s32 func_80061D3C();                                /* static */
void func_80062278(s32, s32, void *);         /* static */
void func_80062288();                            /* static */
extern s32 D_80078C80;

s32 func_800615BC(s32 arg0) {
    s8 sp8F;
    s32 sp10;
    s32 var_s0;
    s32 var_s0_2;
    s8 *var_v0;

    if (D_80078C80 != 0) {
        func_8005C604(D_80074610);
        return -1;
    }
    var_s0 = 0x7F;
    var_v0 = &sp8F;
    do {
        *var_v0 = 0xFF;
        var_s0 -= 1;
        var_v0 -= 1;
    } while (var_s0 >= 0);
    var_s0_2 = 0;
loop_6:
    func_80061B58();
    func_80062288();
    func_80062278(arg0, var_s0_2, &sp10);
    var_s0_2 += 1;
    if (func_80061D3C() == 0) {
        if (var_s0_2 >= 0xF) {
            return 1;
        }
        goto loop_6;
    }
    return 0;
}
