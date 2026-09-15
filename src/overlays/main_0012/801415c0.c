/* Overlay range [801415C0,8014168C) from MAIN.CD member 0012.
 * SHA256(span)=6301d48d84a1a1ee6a47424522d6b169b5bb5c8132fbc84fc438b386aa374de9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800291A0(s32, s32);                          /* extern */
s32 func_800291B4(s32);                             /* extern */
void func_800291C8(s32, s16);                          /* extern */
s16 func_800291DC(s32);                             /* extern */

void func_801415C0(s16 arg0, s16 arg1) {
    s16 temp_s4_2;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;

    temp_s3 = arg0 + 0x2F;
    temp_s4 = func_800291B4(temp_s3) & 0xFF;
    temp_s2 = arg1 + 0x2F;
    func_800291A0(temp_s3, func_800291B4(temp_s2) & 0xFF);
    func_800291A0(temp_s2, temp_s4);
    temp_s1 = (arg0 * 2) + 0x14;
    temp_s4_2 = func_800291DC(temp_s1);
    temp_s0 = (arg1 * 2) + 0x14;
    func_800291C8(temp_s1, func_800291DC(temp_s0));
    func_800291C8(temp_s0, temp_s4_2);
}
