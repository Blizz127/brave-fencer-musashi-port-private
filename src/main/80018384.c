/* Main-exec range [80018384,800183E0) from the SLUS executable.
 * SHA256(span)=8ea31fbd6b652e3f89806eab129ab02cdc782e93690058f7ae7c74a2055c31b7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_80018384
"
    ".ent	func_80018384
"
    ".type	func_80018384, @function
"
    "func_80018384:
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
    ".end	func_80018384
"
    ".size	func_80018384, .-func_80018384
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

extern s32 *D_800AE610;

void func_80018384(u32 arg0, s32 *arg1) {
    if ((u32) &D_800AE610 < arg0) {
loop_1:
        goto loop_1;
    }
    *arg1 = (*arg1 & 0xFF000000) | (*arg0 & 0xFFFFFF);
    *arg0 = (s32) ((*arg0 & 0xFF000000) | ((s32) arg1 & 0xFFFFFF));
}
#endif

