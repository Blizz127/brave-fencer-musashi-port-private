/* Exact retail word export for [8004674C,8004689C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073A9C;
extern s32 D_80073AAC;
s32 func_8004357C(s32, u8 *);                         /* static */
void func_800435CC(s32, void *, u8 *);                      /* static */
void func_80043994(void *, s32);                            /* static */
void func_80043A18(s32, void *);                            /* static */
s32 func_8005C584(void *, s32 (*)(), s32);                 /* static */
void func_8005C604(s32 (*)());                           /* static */

s32 func_8004674C(void) {
    u8 sp818;
    s32 sp19;
    s32 sp18;
    s32 sp10;
    s32 temp_v0;
    s32 var_s0;
    s32 var_v0;

    func_800435CC(1, 0, &sp818);
    var_v0 = 0x10;
    if (!(sp818 & 0x10)) {
        func_80043A18(0x10, &sp10);
        func_800435CC(0x1B, &sp10, 0);
        var_s0 = 0;
loop_2:
        temp_v0 = func_8004357C(0, &sp818);
        var_s0 += 1;
        if ((temp_v0 != 1) && (var_s0 < 0xA)) {
            func_800435CC(0x1B, &sp10, 0);
            goto loop_2;
        }
        if (temp_v0 != 1) {
            var_v0 = 0x10;
            if (!(sp818 & 0x10)) {
                if ((sp818 & 1) && (sp819 & 0x40)) {
                    func_8005C604(D_80073A9C);
                    return 1;
                }
                return (sp818 & 2) != 0;
            }
            /* Duplicate return node #13. Try simplifying control flow for better match */
            return var_v0;
        }
        func_800435CC(9, 0, 0);
        func_80043994(&sp18, 0x200);
        var_v0 = 1;
        if (func_8005C584(&sp19, D_80073AAC, 5) == 0) {
            var_v0 = 2;
        }
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
