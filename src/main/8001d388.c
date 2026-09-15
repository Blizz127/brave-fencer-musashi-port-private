/* Exact retail word export for [8001D388,8001D3FC); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006351C;

void func_8001D388(void *arg0) {
    u16 temp_v1;

    if ((arg0->unk4 >= 0) && (arg0->unk20 != 0) && (arg0->unk0 == 2)) {
        temp_v1 = arg0->unk2;
        if (temp_v1 < 0xBU) {
            *(D_8006351C + (temp_v1 * 4))();
        }
    }
}
