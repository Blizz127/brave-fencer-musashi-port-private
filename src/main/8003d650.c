/* Exact retail word export [8003D650,8003D6E4); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003C598(s32 *, s32);                        /* static */

void func_8003D650(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp34;
    s32 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp10;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v1;

    if (!(arg0 & 0xFF)) {
        temp_v1 = arg1 & 0xFF;
        if (temp_v1 == 0) {
            sp10 = 0x200;
            sp28 = arg2 & 0xFF;
        }
        if (temp_v1 == 1) {
            sp10 = 0x100;
            sp24 = arg2 & 0xFF;
        }
    }
    temp_a0 = arg0 & 0xFF;
    temp_a1 = arg1 & 0xFF;
    if (temp_a0 == 1) {
        if (temp_a1 == 0) {
            sp10 = 0x2000;
            sp34 = arg2 & 0xFF;
        }
        if (temp_a1 == temp_a0) {
            sp10 = 0x1000;
            sp30 = arg2 & 0xFF;
        }
    }
    func_8003C598(&sp10, temp_a1);
}
