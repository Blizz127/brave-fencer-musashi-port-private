/* Exact retail word export for [80016638,800166E8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                             /* static */

void func_80016638(void *arg0, s32 arg1, s32 arg2) {
    s32 *temp_s1_2;
    s32 temp_s1;
    void *temp_v0;

    temp_v0 = func_80010A08(8);
    temp_v0->unk3 = 1;
    temp_s1 = arg1 * 4;
    temp_v0->unk4 = (s32) (((arg2 << 5) & 0x9FF) | 0xE1000000);
    temp_v0->unk0 = (s32) ((temp_v0->unk0 & 0xFF000000) | (*(temp_s1 + arg0->unk4) & 0xFFFFFF));
    temp_s1_2 = temp_s1 + arg0->unk4;
    *temp_s1_2 = (*temp_s1_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
}
