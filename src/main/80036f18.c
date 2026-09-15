/* Exact retail word export for [80036F18,80036F98); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AEE8;
void func_80034DFC(s16);                               /* static */
extern s16 D_80078F10;
extern s32 D_800A63E8;
extern s32 D_800C6D28;

void func_80036F18(void) {
    s16 *var_s0;
    s32 var_s1;

    if (D_8006AEE8 != 0) {
        D_800C6D28 = D_800A63E8;
        var_s1 = 0;
        if (D_8006AEE8 > 0) {
            var_s0 = &D_80078F10;
            do {
                var_s1 += 1;
                func_80034DFC(*var_s0);
                *var_s0 = 0;
                var_s0 += 4;
            } while (var_s1 < D_8006AEE8);
        }
        D_8006AEE8 = 0;
    }
}
