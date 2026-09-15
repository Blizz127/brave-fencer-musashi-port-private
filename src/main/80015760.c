/* Exact retail word export for [80015760,80015908); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062B78;
u16 *func_80015908(u8, s32, s32);                   /* static */
u32 func_80015A74(u32, u16);                        /* static */
extern s32 D_800A5E60;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;

void func_80015760(void *arg0, s32 *arg1) {
    s32 sp18;
    s32 sp10;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;
    s32 var_v1_2;
    u16 temp_a1;
    u32 temp_a0;
    u32 var_s7;
    u8 temp_a0_2;
    u8 temp_s6;
    void *var_s0;

    temp_a1 = arg0->unk2;
    temp_s6 = arg0->unkC;
    var_s3 = temp_a1 - ((u16) D_800AF7BC >> 1);
    temp_a0 = arg0->unk8;
    temp_s0 = arg0->unk4 - ((u16) D_800AF7BE >> 1);
    temp_v0 = temp_s6 & 0xF;
    var_s2 = temp_v0;
    if (temp_v0 == 0) {
        var_s2 = 8;
    }
    var_s7 = temp_a0;
    if (temp_s6 & 0x40) {
        var_s4 = 8;
        var_s7 = func_80015A74(temp_a0, temp_a1);
    } else {
        var_s4 = 8;
    }
    var_v1 = 8 & 0xFF;
    if (temp_s6 & 0x80) {
        var_s4 = 0x10;
        var_v1 = 0x10 & 0xFF;
    }
    var_v1_2 = 0x7C000000;
    if (var_v1 == 8) {
        var_v1_2 = 0x74000000;
    }
    var_s1 = D_800A5E60;
    if (var_s2 & 0xFF) {
        sp18 = temp_s0 << 0x10;
        var_s0 = var_s1 + 0xC;
        sp10 = var_v1_2 | 0x808080;
        do {
            temp_v1 = var_s3 & 0xFFFF;
            var_s3 += var_s4;
            temp_a0_2 = *(D_80062B78 + ((var_s7 >> (((var_s2 & 0xFF) - 1) * 4)) & 0xF));
            var_s2 -= 1;
            var_s0->unk-8 = sp10;
            var_s0->unk-4 = (s32) (temp_v1 | sp18);
            var_s0->unk0 = (s32) (*func_80015908(temp_a0_2, temp_s6 & 0xFFFF, sp18) | 0x40560000);
            var_s0 += 0x10;
            temp_v1_2 = var_s1 & 0xFFFFFF;
            *var_s1 = (s32) ((*arg1 & 0xFFFFFF) | 0x03000000);
            var_s1 += 0x10;
            *arg1 = temp_v1_2;
        } while (var_s2 & 0xFF);
    }
    D_800A5E60 = var_s1;
}
