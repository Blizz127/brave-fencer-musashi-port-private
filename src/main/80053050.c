/* Exact retail word export for [80053050,80053178); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800484EC(s32, s32 *);                        /* static */
void func_80048D9C(void *, s32);                       /* static */

void func_80053050(void *arg0, s32 arg1) {
    s32 sp10;

    func_800484EC(arg1 + 0x14, &sp10);
    func_80048D9C(arg0, arg1);
    arg0->unk14 = (s32) (sp10 + arg0->unk14);
    arg0->unk18 = (s32) (sp14 + arg0->unk18);
    arg0->unk1C = (s32) (sp18 + arg0->unk1C);
}
