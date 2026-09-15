/* Exact retail word export for [8005DBD8,8005DCA0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8007295C();                                     /* static */
extern s32 D_800729A0;
extern s32 D_800729E0;
s32 func_8005E0AC();                                /* static */
void func_8005FBA8();                                 /* static */

void func_8005DBD8(void) {
    s32 (*temp_v0)(s32 (*)());
    s32 temp_v0_2;

    temp_v0 = *(D_800729E0 + (D_800729A0 * 4));
    D_800729A0 = (s32) (D_800729A0 + 1);
    temp_v0_2 = temp_v0(D_800729A0);
    if (temp_v0_2 >= 0) {
        if (D_800729A0 != 0) {
            func_8005FBA8(0x3C);
            if (func_8005E0AC() == 0) {
                D_8007295C(-3);
            }
        }
        if (D_800729A0 >= 5) {
            D_800729A0 = (s32) (D_800729A0 - 1);
        }
    } else {
        D_8007295C(temp_v0_2);
    }
}
