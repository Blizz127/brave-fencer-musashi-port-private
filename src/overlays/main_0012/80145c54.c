/* Overlay range [80145C54,80145CEC) from MAIN.CD member 0012.
 * SHA256(span)=33df775a473edcbd3f2feda0f8359bf32bd7198724e9702f1327bc65e09df524.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800291A0(s32, s32);                            /* extern */
s32 func_800291B4();                               /* extern */

void func_80145C54(void) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_s0;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_a1;
    u32 var_a1_2;

    temp_a1 = func_800291B4(0x4A) & 0xFF;
    temp_v1 = temp_a1 + 1;
    if (temp_a1 >= 0x20) {
        var_a1 = temp_v1;
        if (!(temp_v1 & 0xF)) {
            var_a1 = temp_v1 >> 4;
        }
        temp_s0 = var_a1 & 0xFF;
        func_800291A0(0x4A, temp_s0);
        func_800291A0(0x50, temp_s0);
    }
    temp_a1_2 = func_800291B4(0x4D) & 0xFF;
    temp_v1_2 = temp_a1_2 + 1;
    if (temp_a1_2 >= 0x20) {
        var_a1_2 = temp_v1_2;
        if (!(temp_v1_2 & 0xF)) {
            var_a1_2 = temp_v1_2 >> 4;
        }
        func_800291A0(0x4D, var_a1_2 & 0xFF);
    }
}
