/* Exact retail word export for [80018E9C,80018F20); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80028D78();                                 /* static */
void func_800291A0(s32, s32);                            /* static */
s32 func_800291B4();                               /* static */
extern s32 *D_80078D98;
extern u16 D_80078DCA;

void func_80018E9C(s32 arg0) {
    s32 var_a1;
    s32 var_s0;

    if (arg0 == &D_80078D98) {
        if (D_80078DCA & 0x100) {
            var_s0 = func_800291B4(0xE2) + 1;
            if ((u32) (var_s0 & 0xFF) >= 0x5AU) {
                var_s0 = 0;
                func_80028D78(1);
            }
            var_a1 = var_s0 & 0xFF;
        } else {
            var_a1 = 0;
        }
        func_800291A0(0xE2, var_a1);
    }
}
