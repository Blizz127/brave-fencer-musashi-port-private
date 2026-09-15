/* Exact retail word export for [8002E79C,8002E818); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A9C8;
extern s16 D_800A4EE0;
extern u16 D_800A4EE2;
extern s16 D_800A4EE4;
extern u8 D_800A4EE6;

void func_8002E79C(s32 arg0) {
    s32 var_a0;
    u8 temp_a1;
    u8 temp_v0;

    var_a0 = arg0;
    temp_a1 = D_800A4EE6;
    temp_v0 = temp_a1 | 2;
    if (!(temp_a1 & 2)) {
        D_800A4EE6 = temp_v0;
        if (!(temp_v0 & 4)) {
            if ((u32) (var_a0 & 0xFFFF) >= 5U) {
                var_a0 = 4;
            }
            D_800A4EE0 = 0x4000;
            D_800A4EE4 = 0x2FFF;
            D_800A4EE6 = temp_a1 | 3;
            D_800A4EE2 = *(D_8006A9C8 + ((var_a0 & 0xFFFF) * 2));
        }
    }
}
