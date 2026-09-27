/* Exact retail word export for [80046630,8004674C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004239C(s32, s32);                            /* static */
s32 func_80043830(s32, s32, u8 *);                      /* static */

s32 func_80046630(s32 arg0) {
    u8 sp10;
    s32 var_a1;
    s32 var_s0;
    s32 var_v0;

    func_80043830(1, 0, &sp10);
    var_v0 = 0x10;
    if (!(sp10 & 0x10)) {
        var_a1 = func_80043830(0x13, 0, &sp10);
        if (arg0 == 1) {
            var_v0 = 5;
            if ((sp10 == 2) && (var_a1 != 0)) {
                return 2;
            }
            /* Duplicate return node #13. Try simplifying control flow for better match */
            return var_v0;
        }
        var_s0 = 0;
loop_6:
        if (sp10 & 2) {
            if ((sp10 != 2) || (var_v0 = 2, (var_a1 == 0))) {
                do {
loop_9:
                    func_8004239C(0x1E, var_a1);
                    var_a1 = func_80043830(0x13, 0, &sp10);
                    if (sp10 != 2) {
                        goto loop_9;
                    }
                } while (var_a1 == 0);
                return 2;
            }
            /* Duplicate return node #13. Try simplifying control flow for better match */
            return var_v0;
        }
        func_8004239C(0x1E, var_a1);
        var_a1 = func_80043830(0x13, 0, &sp10);
        var_s0 += 1;
        var_v0 = 5;
        if (var_s0 >= 0xA) {
            /* Duplicate return node #13. Try simplifying control flow for better match */
            return var_v0;
        }
        goto loop_6;
    }
    return var_v0;
}
