/* Exact retail word export for [800415A8,8004162C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004162C(s32);                               /* static */
extern s32 *D_800B9B40;
extern u16 D_800C7CD8;
extern s32 *D_800C7CE0;

void func_800415A8(s16 arg0) {
    if (((u32) (arg0 & 0xFFFF) < 0x10U) && (*(&D_800B9B40 + arg0) == 1)) {
        func_8004162C(*(&D_800C7CE0 + (arg0 * 4)));
        *(&D_800B9B40 + arg0) = 0;
        D_800C7CD8 -= 1;
    }
}
