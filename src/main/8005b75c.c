/* Exact retail word export for [8005B75C,8005B7B0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80072858;
extern s32 *D_8007285C;

s32 func_8005B75C(s32 arg0) {
    *D_8007285C = arg0 | 0x10000000;
    return *D_80072858 & 0xFFFFFF;
}
