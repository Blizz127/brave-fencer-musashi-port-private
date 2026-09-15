/* Exact retail word export for [80015908,80015954); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062A78;
extern s32 D_80062AF8;

s32 func_80015908(s32 arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_a1 = arg1 & 0x80;
    temp_v0 = arg0 & 0xFF;
    if (temp_a1 != 0) {
        temp_v0_2 = temp_v0 - 0x20;
        if (temp_a1 == 0) {
            return temp_v0_2;
        }
        return (s32) ((temp_v0_2 * 2) + D_80062AF8);
    }
    return (s32) (((temp_v0 - 0x20) * 2) + D_80062A78);
}
