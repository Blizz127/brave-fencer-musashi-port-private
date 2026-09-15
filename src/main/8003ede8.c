/* Exact retail word export for [8003EDE8,8003EEE4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003C598(s32 *, s16);                        /* static */

void func_8003EDE8(s32 arg0, s16 arg1, s16 arg2) {
    s16 sp2E;
    s16 sp2C;
    s16 sp22;
    s16 sp20;
    s32 sp10;
    s16 var_a3;
    s16 var_t0;

    var_a3 = arg1;
    var_t0 = arg2;
    if (!(arg0 & 0xFF)) {
        sp10 = 0xC0;
        if (arg1 >= 0x80) {
            var_a3 = 0x7F;
        }
        if (arg2 >= 0x80) {
            var_t0 = 0x7F;
        }
        sp20 = var_a3 * 0x102;
        sp22 = var_t0 * 0x102;
    }
    if ((arg0 & 0xFF) == 1) {
        sp10 = 0xC00;
        if (var_a3 >= 0x80) {
            var_a3 = 0x7F;
        }
        if (var_t0 >= 0x80) {
            var_t0 = 0x7F;
        }
        sp2C = var_a3 * 0x102;
        sp2E = var_t0 * 0x102;
    }
    func_8003C598(&sp10, var_a3);
}
