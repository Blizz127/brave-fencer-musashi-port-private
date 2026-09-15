/* Exact retail word export for [800424E4,80042580); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CBB8;
extern s32 D_80073514;
void func_8005CD48(s32 (*)(), s32);                      /* static */
void func_8005CF48();                                 /* static */
void func_8005CF58(s32, s32);                              /* static */

void func_800424E4(s32 arg0, s32 arg1) {
    s32 sp10;
    s32 temp_a1;
    s32 temp_v0;

    temp_a1 = arg1 << 0xF;
    sp10 = temp_a1;
    if (D_8006CBB8 < arg0) {
loop_2:
        temp_v0 = sp10 - 1;
        sp10 = temp_v0;
        if (temp_v0 == -1) {
            func_8005CD48(D_80073514, temp_a1);
            func_8005CF48(0);
            func_8005CF58(3, 0);
            return;
        }
        if (D_8006CBB8 >= arg0) {

        } else {
            goto loop_2;
        }
    }
}
