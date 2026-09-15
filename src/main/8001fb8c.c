/* Exact retail word export for [8001FB8C,8001FC08); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80063500;

void func_8001FB8C(void *arg0, s32 *arg1) {
    u16 temp_v1;

    if ((arg0->unk4 >= 0) && (arg0->unk0 == 1)) {
        temp_v1 = arg0->unk2;
        if (temp_v1 < 9U) {
            *(D_80063500 + (temp_v1 * 4))();
            *arg1 += 1;
        }
    }
}
