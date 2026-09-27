/* Main-exec range [8001923C,8001931C) from the SLUS executable.
 * SHA256(span)=1f4a3473294ae3e9bfc78e596c52a53568080d16aa3bbfb57643bf82d1e99f27.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#if defined(__mips__)
__asm__(
    ".set	noreorder
"
    ".globl	func_8001923C
"
    ".ent	func_8001923C
"
    ".type	func_8001923C, @function
"
    "func_8001923C:
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
"
"
"
    ".end	func_8001923C
"
    ".size	func_8001923C, .-func_8001923C
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

s32 func_8001923C(s32 arg0) {
    if ((arg0 == 0xB3) || (arg0 == 0xB4) || (arg0 == 0x12E) || (arg0 == 0x12F) || (arg0 == 0x150) || (arg0 == 0x152) || (arg0 == 0x16E) || (arg0 == 0x16F) || (arg0 == 0xB9) || (arg0 == 0xA1) || (arg0 == 0xA2) || (arg0 == 0xA3) || (arg0 == 0x10B) || (arg0 == 0x10C) || (arg0 == 0x10D) || (arg0 == 0x10F) || (arg0 == 0x110) || (arg0 == 0x111) || (arg0 == 0x112) || (arg0 == 0x113) || (arg0 == 0x114) || (arg0 == 0xAA) || (arg0 == 0x115) || (arg0 == 0x116) || (arg0 == 0x117)) {
        return 0;
    }
    return arg0 != 0x118;
}
#endif

