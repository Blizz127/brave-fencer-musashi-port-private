/* Main-exec range [8001E7E0,8001EA14) from the SLUS executable.
 * SHA256(span)=536a228ca052a316aad9cb7feb535776ba84001b6e46c7cf52a739eafa400749.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80052460(u32 *, void *, s32, s32);     /* static */
extern s32 *D_800A6518;
extern u16 D_800B9A02;

void func_8001E7E0(void *arg0) {
    void *sp48;
    u16 sp40;
    u16 sp38;
    s8 sp26;
    s8 sp25;
    s8 sp24;
    s16 sp22;
    s16 sp20;
    s8 sp1F;
    s8 sp1E;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp16;
    s16 sp14;
    u32 sp10;
    s16 temp_a1_2;
    s16 var_v1_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_fp;
    s32 temp_s4;
    s32 temp_s6;
    s32 var_v0;
    s32 var_v1;
    s8 temp_v1;
    u16 *var_s2;
    u16 temp_s5;
    u32 temp_s3;
    u32 temp_s7;
    void *var_s0;

    temp_s7 = M2C_FIELD(arg0, u16 *, 0x2C) & 0x3FFF;
    if (temp_s7 < 0x1000U) {
        var_s2 = M2C_FIELD(arg0, u16 **, 0x20);
        var_s0 = var_s2 + 3;
        sp38 = M2C_FIELD(arg0, u16 *, 8);
        temp_s3 = M2C_FIELD(arg0, u32 *, 4);
        temp_a0 = (temp_s3 >> 0x18) & 3;
        temp_s6 = 2 - temp_a0;
        sp48 = (D_800B9A02 * 0x14) + &D_800A6518;
        temp_fp = temp_s3 & 0x40000000;
        temp_s4 = temp_a0 << 7;
        sp40 = M2C_FIELD(arg0, u16 *, 0xA);
        do {
            temp_s5 = *var_s2;
            temp_a1 = M2C_FIELD(arg0, u16 *, 0x28) + ((s16) M2C_FIELD(var_s0, s16 *, 1) >> temp_s6);
            temp_a0_2 = M2C_FIELD(arg0, u16 *, 0x2A) + M2C_FIELD(var_s0, u16 *, 3);
            if (temp_fp != 0) {
                var_v1 = temp_s4 | ((temp_s3 >> 0x17) & 0x60) | ((u32) (temp_a0_2 & 0x100) >> 4) | ((u32) (temp_a1 & 0x3C0) >> 6);
                var_v0 = (temp_a0_2 & 0x200) * 4;
            } else {
                var_v0 = temp_s4 | (((u32) (temp_a0_2 & 0x100) >> 4) | 0x20) | ((u32) (temp_a1 & 0x3C0) >> 6);
                var_v1 = (temp_a0_2 & 0x200) * 4;
            }
            temp_a1_2 = var_v0 | var_v1;
            sp10 = temp_s3;
            sp14 = M2C_FIELD(var_s0, u16 *, 5) + (sp38 + M2C_FIELD(arg0, u16 *, 0x2E));
            sp16 = M2C_FIELD(var_s0, u16 *, 7) + (sp40 + M2C_FIELD(arg0, u16 *, 0x30));
            sp18 = (s16) M2C_FIELD(var_s0, u8 *, -1);
            sp1E = ((temp_a1 & 0xFFFF) - ((temp_a1_2 & 0xF) << 6)) << temp_s6;
            temp_v1 = temp_a0_2 & 0xFFFF;
            sp1C = temp_a1_2;
            sp1A = (s16) M2C_FIELD(var_s0, u8 *, 0);
            if (temp_a1_2 & 0x10) {
                sp1F = temp_v1 - 0x100;
            } else {
                sp1F = temp_v1;
            }
            var_v1_2 = 0x100;
            if ((u8) M2C_FIELD(arg0, u8 *, 0x27) < 0xE0U) {
                var_v1_2 = 0x160;
            }
            var_s0 += 0xC;
            var_s2 += 0xC;
            sp20 = var_v1_2;
            sp26 = 0x80;
            sp25 = 0x80;
            sp24 = 0x80;
            sp22 = M2C_FIELD(arg0, u8 *, 0x27) + 0x100;
            func_80052460(&sp10, sp48, temp_s7 & 0xFFFF, temp_a0_2);
        } while ((temp_s5 & 0xFF) != 0xFF);
    }
}
