/* Exact retail word export for [8002E8DC,8002E94C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A9E0;
extern u16 D_800A4EE2;
extern s16 D_800A4EE4;
extern u8 D_800A4EE6;

void func_8002E8DC(s32 arg0) {
    s32 var_a0;
    u8 temp_a1;

    var_a0 = arg0;
    temp_a1 = D_800A4EE6 & 0xFD;
    if (D_800A4EE6 & 2) {
        D_800A4EE6 = temp_a1;
        if (!(D_800A4EE6 & 4)) {
            if ((u32) (var_a0 & 0xFFFF) >= 5U) {
                var_a0 = 4;
            }
            D_800A4EE4 = 0x4000;
            D_800A4EE6 = temp_a1 | 1;
            D_800A4EE2 = *(D_8006A9E0 + ((var_a0 & 0xFFFF) * 2));
        }
    }
}
