/* Exact retail word export for [8001534C,800153A4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800153A4(void *, s16, s16, s32, s32);        /* static */
extern s32 *D_800AF630;

void func_8001534C(s32 arg0, s16 arg2, s16 arg3, u8 arg4, u8 arg5) {
    func_800153A4(((s32) (arg0 << 0x10) >> 0xC) + 0x9DA8 + &D_800AF630, arg2, arg3, (s32) arg4, (s32) arg5);
}
