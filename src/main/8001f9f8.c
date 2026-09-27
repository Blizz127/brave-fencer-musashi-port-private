/* Exact retail word export for [8001F9F8,8001FB8C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001FB8C(void *, s32 *);                        /* static */
extern s32 *D_800AF8D8;
extern s32 *D_800AFB6C;
extern s32 *D_800AFBF0;
extern s32 *D_800B0430;
extern s32 *D_800B0C70;
extern s32 *D_800B3DF0;
extern u8 D_800B9A11;

void func_8001F9F8(void) {
    s32 sp10;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;
    void *var_s0_4;
    void *var_s0_5;
    void *var_s0_6;
    void *var_s0_7;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_s1_7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    u8 temp_s2;

    temp_s2 = D_800B9A11;
    var_s1 = 0;
    var_s0 = &D_800AF8D8;
    sp10 = 0;
    do {
        func_8001FB8C(var_s0, &sp10);
        var_s1 += 1;
        var_s0 += 0x84;
    } while (var_s1 < 4);
    var_v0 = temp_s2 & 8;
    if (!(temp_s2 & 2)) {
        var_s1_2 = 0;
        var_s0_2 = &D_800AF8D8 + 0x210;
        do {
            func_8001FB8C(var_s0_2, &sp10);
            var_s1_2 += 1;
            var_s0_2 += 0x84;
        } while (var_s1_2 <= 0);
        var_v0 = temp_s2 & 8;
    }
    var_v0_2 = temp_s2 & 0x10;
    if (var_v0 == 0) {
        var_s1_3 = 0;
        var_s0_3 = &D_800AFB6C;
        do {
            func_8001FB8C(var_s0_3, &sp10);
            var_s1_3 += 1;
            var_s0_3 += 0x84;
        } while (var_s1_3 <= 0);
        var_v0_2 = temp_s2 & 0x10;
    }
    var_v0_3 = temp_s2 & 0x20;
    if (var_v0_2 == 0) {
        var_s1_4 = 0;
        var_s0_4 = &D_800AFBF0;
        do {
            func_8001FB8C(var_s0_4, &sp10);
            var_s1_4 += 1;
            var_s0_4 += 0x84;
        } while (var_s1_4 < 0x10);
        var_v0_3 = temp_s2 & 0x20;
    }
    var_v0_4 = temp_s2 & 0x40;
    if (var_v0_3 == 0) {
        var_s1_5 = 0;
        var_s0_5 = &D_800B0430;
        do {
            func_8001FB8C(var_s0_5, &sp10);
            var_s1_5 += 1;
            var_s0_5 += 0x84;
        } while (var_s1_5 < 0x10);
        var_v0_4 = temp_s2 & 0x40;
    }
    var_v0_5 = temp_s2 & 0x80;
    if (var_v0_4 == 0) {
        var_s1_6 = 0;
        var_s0_6 = &D_800B0C70;
        do {
            func_8001FB8C(var_s0_6, &sp10);
            var_s1_6 += 1;
            var_s0_6 += 0x84;
        } while (var_s1_6 < 0x60);
        var_v0_5 = temp_s2 & 0x80;
    }
    var_s1_7 = 0;
    if (var_v0_5 == 0) {
        var_s0_7 = &D_800B3DF0;
        do {
            func_8001FB8C(var_s0_7, &sp10);
            var_s1_7 += 1;
            var_s0_7 += 0x84;
        } while (var_s1_7 < 0x3A);
    }
}
