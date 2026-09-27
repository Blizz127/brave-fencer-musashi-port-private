/* Exact retail word export for [8002E818,8002E8DC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006A9D4[];
void func_8002EA10();                            /* static */
extern u16 D_800A4E8C;
extern u16 D_800A4E8E;
extern s16 D_800A4EE0;
extern u16 D_800A4EE2;
extern s16 D_800A4EE4;
extern u8 D_800A4EE6;

void func_8002E818(s32 arg0) {
    s32 var_s0;
    u8 temp_a0;
    u8 temp_v0;

    var_s0 = arg0;
    if ((D_800A4E8E & 4) && (D_800A4E8C == 0x3E)) {
        func_8002EA10();
    }
    temp_a0 = D_800A4EE6;
    temp_v0 = temp_a0 | 4;
    if (!(temp_a0 & 4)) {
        D_800A4EE6 = temp_v0;
        if (!(temp_v0 & 2)) {
            if ((u32) (var_s0 & 0xFFFF) >= 5U) {
                var_s0 = 4;
            }
            D_800A4EE0 = 0x4000;
            D_800A4EE4 = 0x2000;
            D_800A4EE6 = temp_a0 | 5;
            D_800A4EE2 = *(D_8006A9D4 + ((var_s0 & 0xFFFF) * 2));
        }
    }
}
