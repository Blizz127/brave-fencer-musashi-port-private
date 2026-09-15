/* Overlay range [8012B0B4,8012B14C) from MAIN.CD member 0012.
 * SHA256(span)=c09c5dbc239a729e1c5e2886118b949d331e05ac400a04bc5d26e41c1cabb228.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004787C(s32);                             /* extern */
s32 func_80047948(s32);                             /* extern */

void func_8012B0B4(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s3;

    temp_s0 = (arg1 - 0x400) & 0xFFF;
    temp_s3 = (saved_reg_s3 & 0xFFFF0000) | (((s32) (func_80047948(temp_s0) * arg2) >> 0xC) & 0xFFFF);
    *arg0 = (temp_s3 & 0xFFFF) | (((s32) (func_8004787C(temp_s0) * -arg2) >> 0xC) << 0x10);
}
