/* Exact retail word export for [80053B20,80053BD8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_8004787C(s32);                             /* static */
s16 func_80047948(s32, s32);                        /* static */
void func_80048D9C(s32, s16 *);                  /* static */

void func_80053B20(s32 arg0, s32 arg1) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s16 sp20;
    s16 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 temp_s0_2;
    s16 temp_v0;
    s16 temp_v1;
    s32 temp_s0;

    temp_s0 = arg1 / 360;
    temp_s0_2 = func_80047948(temp_s0, MULT_HI(arg1, 0xB60B60B7));
    temp_v0 = func_8004787C(temp_s0);
    temp_v1 = temp_v0;
    if (arg1 != 0) {
        sp12 = -temp_v0;
        sp10 = temp_s0_2;
        sp14 = 0;
        sp16 = temp_v1;
        sp18 = temp_s0_2;
        sp1A = 0;
        sp1C = 0;
        sp1E = 0;
        sp20 = 0x1000;
        sp24 = 0;
        sp28 = 0;
        sp2C = 0;
        func_80048D9C(arg0, &sp10);
    }
}
