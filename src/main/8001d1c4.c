/* Exact retail word export for [8001D1C4,8001D388); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001D388(u32, s32 *);                        /* static */
extern s32 *D_800B5CB8;
extern s32 *D_800B5D28;
extern s32 *D_800B60A8;
extern s32 *D_800B6968;
extern s32 *D_800B7768;
extern u8 D_800B9A11;

void func_8001D1C4(void) {
    s32 sp10;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a0_4;
    void *var_a0_5;
    void *var_a0_6;
    void *var_s0_2;
    void *var_s0_3;
    void *var_s0_4;
    void *var_s0_5;
    void *var_s0_6;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    u8 *temp_a0;
    u8 *var_a0;
    u8 *var_s0;
    u8 temp_s2;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;

    var_s0 = &D_800B9A11 - 0x3E39;
    temp_a0 = &D_800B9A11 - 0x3D59;
    sp10 = 0;
    temp_s2 = D_800B9A11;
    var_v0 = temp_s2 & 4;
    if ((u32) var_s0 < (u32) temp_a0) {
        var_a0 = var_s0;
        do {
            func_8001D388((u32) var_a0, &sp10);
            var_s0 += 0x38;
            var_a0 = var_s0;
        } while ((u32) var_s0 < (u32) temp_a0);
        var_v0 = temp_s2 & 4;
    }
    var_v0_2 = temp_s2 & 0x10;
    if (var_v0 == 0) {
        var_s0_2 = &D_800B5CB8;
        temp_v1 = &D_800B5CB8 + 0x70;
        var_v0_2 = temp_s2 & 0x10;
        if ((u32) &D_800B5CB8 < (u32) temp_v1) {
            var_a0_2 = &D_800B5CB8;
            do {
                func_8001D388((u32) var_a0_2, &sp10);
                var_s0_2 += 0x38;
                var_a0_2 = var_s0_2;
            } while ((u32) var_s0_2 < (u32) temp_v1);
            var_v0_2 = temp_s2 & 0x10;
        }
    }
    var_v0_3 = temp_s2 & 0x20;
    if (var_v0_2 == 0) {
        var_s0_3 = &D_800B5D28;
        temp_v1_2 = &D_800B5D28 + 0x380;
        var_v0_3 = temp_s2 & 0x20;
        if ((u32) &D_800B5D28 < (u32) temp_v1_2) {
            var_a0_3 = &D_800B5D28;
            do {
                func_8001D388((u32) var_a0_3, &sp10);
                var_s0_3 += 0x38;
                var_a0_3 = var_s0_3;
            } while ((u32) var_s0_3 < (u32) temp_v1_2);
            var_v0_3 = temp_s2 & 0x20;
        }
    }
    var_v0_4 = temp_s2 & 0x40;
    if (var_v0_3 == 0) {
        var_s0_4 = &D_800B60A8;
        temp_v1_3 = &D_800B60A8 + 0x8C0;
        var_v0_4 = temp_s2 & 0x40;
        if ((u32) &D_800B60A8 < (u32) temp_v1_3) {
            var_a0_4 = &D_800B60A8;
            do {
                func_8001D388((u32) var_a0_4, &sp10);
                var_s0_4 += 0x38;
                var_a0_4 = var_s0_4;
            } while ((u32) var_s0_4 < (u32) temp_v1_3);
            var_v0_4 = temp_s2 & 0x40;
        }
    }
    var_v0_5 = temp_s2 & 0x80;
    if (var_v0_4 == 0) {
        var_s0_5 = &D_800B6968;
        temp_v1_4 = &D_800B6968 + 0xE00;
        var_v0_5 = temp_s2 & 0x80;
        if ((u32) &D_800B6968 < (u32) temp_v1_4) {
            var_a0_5 = &D_800B6968;
            do {
                func_8001D388((u32) var_a0_5, &sp10);
                var_s0_5 += 0x38;
                var_a0_5 = var_s0_5;
            } while ((u32) var_s0_5 < (u32) temp_v1_4);
            var_v0_5 = temp_s2 & 0x80;
        }
    }
    if (var_v0_5 == 0) {
        var_s0_6 = &D_800B7768;
        temp_v1_5 = &D_800B7768 + 0x1C70;
        if ((u32) &D_800B7768 < (u32) temp_v1_5) {
            var_a0_6 = &D_800B7768;
            do {
                func_8001D388((u32) var_a0_6, &sp10);
                var_s0_6 += 0x38;
                var_a0_6 = var_s0_6;
            } while ((u32) var_s0_6 < (u32) temp_v1_5);
        }
    }
}
