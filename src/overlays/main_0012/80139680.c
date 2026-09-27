/* Overlay range [80139680,80139788) from MAIN.CD member 0012.
 * SHA256(span)=f97fdc6c11149dde48f3d035a644c12aaef48d524bf7880ce80e4cec460e4450.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80052460(s32 *, s32, u16);         /* extern */
s16 func_80058B40(s32, s32, s32, s32); /* extern */

void func_80139680(void *arg0, s32 arg1) {
    s8 sp26;
    s8 sp25;
    s8 sp24;
    u16 sp22;
    u16 sp20;
    s8 sp1F;
    s8 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    s16 sp14;
    s32 sp10;
    s16 temp_a0;
    s16 temp_v0;
    s16 var_v0;
    s32 var_s1;
    u16 temp_v1;

    var_s1 = M2C_FIELD(arg0, u16 *, 0x12) - M2C_FIELD(arg0, u16 *, 0x16);
    if (var_s1 < 0) {
        var_s1 += 4;
    }
    sp10 = 0;
    sp1C = func_80058B40(0, 1, 0x1C0, 0x100);
    sp20 = M2C_FIELD(arg0, u16 *, 0x3C);
    sp26 = 0x80;
    sp25 = 0x80;
    sp24 = 0x80;
    sp22 = M2C_FIELD(arg0, u16 *, 0x3E);
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x14);
    temp_a0 = M2C_FIELD(arg0, s16 *, 0x30);
    if (temp_v1 < 0x24U) {
        var_v0 = (temp_v1 * 6) + temp_a0;
    } else {
        var_v0 = temp_a0 + 0xD2;
    }
    sp14 = var_v0;
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x32) + (var_s1 * 0xC);
    sp16 = temp_v0;
    if (var_s1 != 0) {
        sp16 = temp_v0 + (var_s1 * 2);
    }
    sp18 = 0xC;
    sp1A = 0xC;
    sp1E = 0xF0;
    sp1F = 0;
    func_80052460(&sp10, arg1, M2C_FIELD(arg0, u16 *, 0x1A));
}
