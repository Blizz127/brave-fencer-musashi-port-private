/* Main-exec range [8001D3FC,8001D70C) from the SLUS executable.
 * SHA256(span)=105f74153eb2a817bcb9f1c0d7c2de185911d9e989fb7f1cbcf742ca91fc9957.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001D70C(s32);                         /* static */
void func_8001D8C4(void *, u16 *, void *, s32);  /* static */
extern void *D_800A5E60;
extern s32 *D_800A6610;
extern u16 D_800B9A02;

void func_8001D3FC(void *arg0) {
    s32 sp10;
    s16 temp_a1_2;
    s16 var_v0_2;
    s32 *temp_s6;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    s8 temp_v1_2;
    s8 temp_v1_3;
    s8 var_a0;
    s8 var_v1_2;
    s8 var_v1_3;
    u16 *var_s3;
    u16 temp_s4;
    u32 temp_s5;
    u32 temp_v1;
    u8 temp_v1_4;
    void *temp_s0_2;
    void *var_s2;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0x2C) & 0x3FFF;
    if (temp_v1 < 0x1000U) {
        temp_s5 = M2C_FIELD(arg0, u32 *, 4);
        var_s3 = M2C_FIELD(arg0, u16 **, 0x20);
        temp_s0 = (temp_s5 >> 0x18) & 3;
        temp_a1 = D_800B9A02 << 0xE;
        sp10 = 2 - temp_s0;
        temp_s6 = temp_a1 + ((temp_v1 * 4) + &D_800A6610);
        func_8001D70C(temp_a1);
        temp_fp = temp_s0 << 7;
        var_s2 = var_s3 + 3;
        do {
            temp_s0_2 = D_800A5E60;
            temp_s4 = *var_s3;
            D_800A5E60 = temp_s0_2 + 0x28;
            M2C_FIELD(temp_s0_2, s8 *, 3) = 9;
            temp_a2 = M2C_FIELD(arg0, u16 *, 0x2A) + M2C_FIELD(var_s2, u16 *, 3);
            M2C_FIELD(temp_s0_2, u8 *, 7) = 0x2CU;
            temp_a0 = M2C_FIELD(arg0, u16 *, 0x28) + ((s16) M2C_FIELD(var_s2, s16 *, 1) >> sp10);
            if (temp_s5 & 0x40000000) {
                M2C_FIELD(temp_s0_2, u8 *, 7) = 0x2EU;
                var_v1 = temp_fp | ((temp_s5 >> 0x17) & 0x60) | ((u32) (temp_a2 & 0x100) >> 4) | ((u32) (temp_a0 & 0x3C0) >> 6);
                var_v0 = (temp_a2 & 0x200) * 4;
            } else {
                var_v0 = temp_fp | (((u32) (temp_a2 & 0x100) >> 4) | 0x20) | ((u32) (temp_a0 & 0x3C0) >> 6);
                var_v1 = (temp_a2 & 0x200) * 4;
            }
            temp_a1_2 = var_v0 | var_v1;
            M2C_FIELD(temp_s0_2, s16 *, 0x16) = temp_a1_2;
            M2C_FIELD(temp_s0_2, u8 *, 7) = (u8) (M2C_FIELD(temp_s0_2, u8 *, 7) | ((u32) (temp_s5 & 0x40) >> 6));
            temp_v1_2 = ((temp_a0 & 0xFFFF) - ((temp_a1_2 & 0xF) << 6)) << sp10;
            var_v1_2 = (temp_v1_2 + M2C_FIELD(var_s2, u8 *, -1)) - 1;
            if ((u32) (var_v1_2 & 0xFFFF) >= 0x100U) {
                var_v1_2 = 0xFF;
            }
            if (temp_s4 & 0x100) {
                M2C_FIELD(temp_s0_2, s8 *, 0x24) = temp_v1_2;
                M2C_FIELD(temp_s0_2, s8 *, 0x14) = temp_v1_2;
                M2C_FIELD(temp_s0_2, s8 *, 0x1C) = var_v1_2;
                M2C_FIELD(temp_s0_2, s8 *, 0xC) = var_v1_2;
            } else {
                M2C_FIELD(temp_s0_2, s8 *, 0x1C) = temp_v1_2;
                M2C_FIELD(temp_s0_2, s8 *, 0xC) = temp_v1_2;
                M2C_FIELD(temp_s0_2, s8 *, 0x24) = var_v1_2;
                M2C_FIELD(temp_s0_2, s8 *, 0x14) = var_v1_2;
            }
            temp_v1_3 = temp_a2 & 0xFFFF;
            if (temp_a1_2 & 0x10) {
                var_a0 = temp_v1_3 - 0x100;
            } else {
                var_a0 = temp_v1_3;
            }
            var_v1_3 = (var_a0 + M2C_FIELD(var_s2, u8 *, 0)) - 1;
            if ((u32) (var_v1_3 & 0xFFFF) >= 0x100U) {
                var_v1_3 = 0xFF;
            }
            if (temp_s4 & 0x200) {
                M2C_FIELD(temp_s0_2, s8 *, 0x25) = var_a0;
                M2C_FIELD(temp_s0_2, s8 *, 0x1D) = var_a0;
                M2C_FIELD(temp_s0_2, s8 *, 0x15) = var_v1_3;
                M2C_FIELD(temp_s0_2, s8 *, 0xD) = var_v1_3;
            } else {
                M2C_FIELD(temp_s0_2, s8 *, 0x15) = var_a0;
                M2C_FIELD(temp_s0_2, s8 *, 0xD) = var_a0;
                M2C_FIELD(temp_s0_2, s8 *, 0x25) = var_v1_3;
                M2C_FIELD(temp_s0_2, s8 *, 0x1D) = var_v1_3;
            }
            temp_v1_4 = M2C_FIELD(arg0, u8 *, 0x27);
            temp_v0 = (temp_v1_4 + 0x100) << 6;
            if (temp_v1_4 < 0xE0U) {
                var_v0_2 = temp_v0 | 0x16;
            } else {
                var_v0_2 = temp_v0 | 0x10;
            }
            M2C_FIELD(temp_s0_2, s16 *, 0xE) = var_v0_2;
            var_s2 += 0xC;
            M2C_FIELD(temp_s0_2, u8 *, 4) = (u8) M2C_FIELD(arg0, u8 *, 0x24);
            M2C_FIELD(temp_s0_2, u8 *, 5) = (u8) M2C_FIELD(arg0, u8 *, 0x25);
            M2C_FIELD(temp_s0_2, u8 *, 6) = (u8) M2C_FIELD(arg0, u8 *, 0x26);
            func_8001D8C4(arg0, var_s3, temp_s0_2, temp_a0);
            M2C_FIELD(temp_s0_2, s32 *, 0) = (s32) ((M2C_FIELD(temp_s0_2, s32 *, 0) & 0xFF000000) | (*temp_s6 & 0xFFFFFF));
            *temp_s6 = (*temp_s6 & 0xFF000000) | ((s32) temp_s0_2 & 0xFFFFFF);
            var_s3 += 0xC;
        } while ((temp_s4 & 0xFF) != 0xFF);
    }
}
