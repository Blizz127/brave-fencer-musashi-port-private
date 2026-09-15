/* Overlay range [8012CC88,8012CE2C) from MAIN.CD member 0012.
 * SHA256(span)=7fb02279dcbb59647c77d9020f773b5a301468125a6f7d612fbdb2289b49b9fb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012CEB0(u16 *, u16 *, s32, s32);  /* static */

s32 func_8012CC88(void *arg0, s32 arg1, void *arg2) {
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_v0;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a1_3;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u16 temp_v1_4;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x3A);
    sp10 = temp_v1;
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x3E);
    sp12 = temp_a0;
    temp_a1 = M2C_FIELD(arg0, u16 *, 0x42);
    sp14 = temp_a1;
    sp10 = temp_v1 + M2C_FIELD(arg2, u16 *, 0);
    sp12 = temp_a0 + M2C_FIELD(arg2, u16 *, 2);
    sp14 = temp_a1 + M2C_FIELD(arg2, u16 *, 4);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + M2C_FIELD(arg0, s32 *, 0x44));
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + M2C_FIELD(arg0, s32 *, 0x48));
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x4C));
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + M2C_FIELD(arg0, s32 *, 0x10));
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + M2C_FIELD(arg0, s32 *, 0x14));
    temp_a0_2 = M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) + M2C_FIELD(arg0, s32 *, 0x18));
    sp18 = temp_a0_2;
    temp_v1_2 = M2C_FIELD(arg0, u16 *, 0xA);
    sp1A = temp_v1_2;
    temp_a1_2 = M2C_FIELD(arg0, u16 *, 0xE);
    sp1C = temp_a1_2;
    sp18 = temp_a0_2 + M2C_FIELD(arg2, u16 *, 0);
    sp1A = temp_v1_2 + M2C_FIELD(arg2, u16 *, 2);
    sp1C = temp_a1_2 + M2C_FIELD(arg2, u16 *, 4);
    temp_v0 = func_8012CEB0(&sp10, &sp18, arg1, arg1);
    temp_a1_3 = sp18 - M2C_FIELD(arg2, u16 *, 0);
    sp18 = temp_a1_3;
    temp_v1_3 = sp1A - M2C_FIELD(arg2, u16 *, 2);
    sp1A = temp_v1_3;
    temp_v1_4 = sp1C - M2C_FIELD(arg2, u16 *, 4);
    sp1C = temp_v1_4;
    M2C_FIELD(arg0, u16 *, 6) = temp_a1_3;
    M2C_FIELD(arg0, u16 *, 0xA) = temp_v1_3;
    M2C_FIELD(arg0, u16 *, 0xE) = temp_v1_4;
    if (temp_v0 & 0x6000) {
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
    }
    return temp_v0;
}
