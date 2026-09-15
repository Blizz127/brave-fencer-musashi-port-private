/* Exact retail word export for [800184F0,80018714); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80053D44(s32, void *);                          /* static */
void func_80058890(s32, s32, s32, s16, s32, s32, s32);     /* static */
void func_800599B8(s32, s32, u16, u16);                  /* static */
extern s16 D_800B97D8;

void func_800184F0(void) {
    s32 sp20;
    s16 *var_s2;
    s16 *var_s5;
    s32 var_s4;
    s32 var_s6;
    u16 *var_s3;
    u16 temp_v1;
    u16 var_v0;
    void *var_s0;

    var_s6 = 0;
    var_s5 = &D_800B97D8;
    var_s2 = &D_800B97D8 + 0xA;
    do {
        if (*var_s5 != 0) {
            var_s3 = var_s2->unk-6;
            var_s4 = 0;
            var_s0 = var_s3 + 0xC;
            do {
                temp_v1 = *var_s3;
                if (temp_v1 != 9) {
                    if ((s32) temp_v1 < 0xA) {
                        if (temp_v1 != 0) {
                            if (temp_v1 != 5) {
                                var_s4 = 1;
                                goto block_21;
                            }
                            func_80053D44(var_s0->unk0, &sp20);
                            *(u16 *)0x1F800000 = sp24;
                            *(u16 *)0x1F800002 = sp26;
                            *(u16 *)0x1F800004 = sp28;
                            *(u16 *)0x1F800006 = sp2A;
                            func_800599B8(0x1F800000, sp2C, sp28, sp2A);
                            var_s0 += 0x10;
                        } else {
                            if (var_s2->unk3 == 0) {
                                *(u16 *)0x1F800000 = var_s0->unk-8;
                                *(u16 *)0x1F800002 = var_s0->unk-6;
                            } else {
                                *(u16 *)0x1F800000 = var_s2->unk-2;
                                var_v0 = (u16) var_s2->unk0;
                                goto block_17;
                            }
                            goto block_18;
                        }
                    } else if (temp_v1 != 0xB) {
                        if ((s32) temp_v1 >= 0xB) {
                            var_s4 = 1;
                        }
block_21:
                        var_s0 += 0x10;
                    } else {
                        func_80058890(var_s0->unk0, 1, 0, (s16) var_s0->unk-8, (s32) (s16) var_s0->unk-6, var_s0->unk-4 * 2, (s32) var_s0->unk-2);
                        var_s0 += 0x10;
                    }
                } else {
                    if (var_s2->unk3 == 0) {
                        *(u16 *)0x1F800000 = var_s0->unk-8;
                        *(u16 *)0x1F800002 = var_s0->unk-6;
                    } else {
                        *(u16 *)0x1F800000 = ((u8) var_s2->unk2 >= 0x21U) << 8;
                        var_v0 = var_s2->unk2 | 0x1E0;
block_17:
                        *(u16 *)0x1F800002 = var_v0;
                    }
block_18:
                    *(u16 *)0x1F800004 = (u16) var_s0->unk-4;
                    *(u16 *)0x1F800006 = (u16) var_s0->unk-2;
                    func_800599B8(0x1F800000, var_s0->unk0);
                    var_s0 += 0x10;
                }
                var_s3 += 0x10;
            } while (var_s4 == 0);
            *var_s5 = 0;
        }
        var_s6 += 1;
        var_s2 += 0x10;
        var_s5 += 0x10;
    } while (var_s6 < 0x20);
}
