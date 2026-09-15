/* Overlay range [8014E98C,8014EA4C) from MAIN.CD member 0012.
 * SHA256(span)=10ad443f7a69d34cde9ecb18bf85d103d1caa6505aed446be46e954dbf94d5e0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014EA4C(void *, u16 *, u16 *, s32);       /* static */

s32 func_8014E98C(void *arg0) {
    u16 sp1C;
    s16 sp1A;
    u16 sp18;
    u16 sp14;
    s16 sp12;
    u16 sp10;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;

    var_s2 = 0;
    var_s1 = 2;
    if (!(M2C_FIELD(arg0, s32 *, 0x44) & 0x80000)) {
        var_v0 = 0;
        if (!(M2C_FIELD(arg0, s32 *, 0x1F8) & 0x04000000)) {
            do {
                sp10 = M2C_FIELD(arg0, u16 *, 0x88);
                var_s1 -= 1;
                sp12 = M2C_FIELD(arg0, u16 *, 0x8A) - 0x10;
                sp14 = M2C_FIELD(arg0, u16 *, 0x8C);
                sp18 = M2C_FIELD(arg0, u16 *, 6);
                sp1A = M2C_FIELD(arg0, u16 *, 0xA) - 0x10;
                sp1C = M2C_FIELD(arg0, u16 *, 0xE);
                var_s2 |= func_8014EA4C(arg0, &sp10, &sp18, var_s1);
            } while (var_s1 != 0);
            goto block_3;
        }
    } else {
block_3:
        var_v0 = var_s2;
    }
    return var_v0;
}
