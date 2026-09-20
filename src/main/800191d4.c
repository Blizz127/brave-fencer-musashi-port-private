/* Exact retail word export [800191D4,8001923C); verified against pinned EXE and asm. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_800191D4
"
    ".ent	func_800191D4
"
    ".type	func_800191D4, @function
"
    "func_800191D4:
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
"
    ".end	func_800191D4
"
    ".size	func_800191D4, .-func_800191D4
"
);
#else
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8001923C(s32);                             /* static */
extern s32 D_80078E30;

s32 func_800191D4(s32 arg0) {
    if ((D_80078E30 < 0) || (func_8001923C(arg0) != 0)) {
        return 1;
    }
    return D_80078E30 != arg0;
}
#endif

