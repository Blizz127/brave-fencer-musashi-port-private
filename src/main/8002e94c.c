/* Exact retail word export for [8002E94C,8002EA10); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A9EC;
void func_8002EAB0(u16);                               /* static */
extern u16 D_800A4E8C;
extern u16 D_800A4E8E;
extern u16 D_800A4EE2;
extern s16 D_800A4EE4;
extern u8 D_800A4EE6;

void func_8002E94C(s32 arg0) {
    s32 var_s0;
    u8 temp_a0;

    var_s0 = arg0;
    if ((D_800A4E8E & 4) && (D_800A4E8C == 0x3E) && (D_800A4E8E & 0x10)) {
        func_8002EAB0(D_800A4E8E);
    }
    temp_a0 = D_800A4EE6 & 0xFB;
    if (D_800A4EE6 & 4) {
        D_800A4EE6 = temp_a0;
        if (!(D_800A4EE6 & 2)) {
            if ((u32) (var_s0 & 0xFFFF) >= 5U) {
                var_s0 = 4;
            }
            D_800A4EE4 = 0x4000;
            D_800A4EE6 = temp_a0 | 1;
            D_800A4EE2 = *(D_8006A9EC + ((var_s0 & 0xFFFF) * 2));
        }
    }
}
