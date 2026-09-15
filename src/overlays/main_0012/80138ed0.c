/* Overlay range [80138ED0,8013914C) from MAIN.CD member 0012.
 * SHA256(span)=4b48853132596548fa8ff83213576235ffc2dff704b0198f1419038abf0b2ac2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800599B8(u16 *, void *, void *, u8);         /* extern */
s32 func_8013914C(u16 *);                           /* static */
extern s32 D_80127548;
extern s32 *D_80127C0C;

s32 func_80138ED0(void *arg0, s32 arg1, s32 arg2) {
    s16 sp16;
    s16 sp14;
    u16 sp10;
    s16 temp_v1_3;
    s16 temp_v1_4;
    s16 temp_v1_5;
    s16 var_s0;
    s16 var_s0_3;
    s32 temp_s4;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_s0_2;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u16 temp_v0;
    u8 *var_a2;
    u8 var_a3;
    void *temp_a1;
    void *temp_t2;
    void *var_a0_5;
    void *var_a1;
    void *var_a1_2;
    void *var_a2_2;

    var_s0 = saved_reg_s0;
    temp_s4 = arg0->unk23 & 0xF & 0xFF;
    var_v0 = 1;
    if (func_8013914C(&sp10) == 0) {
        temp_v1 = sp10 - arg0->unk38;
        var_a2 = arg2 + ((arg1 & 0xFFFF) * 0xC);
        temp_t2 = ((temp_v1 & 0xFFFF) * 2) + &D_80127C0C;
        var_t0 = 0;
        if (((temp_v1 & 0xFFFF) % 3) & 0xFFFF) {
            temp_t1 = temp_s4 & 0xFFFF;
            var_a1 = temp_t2;
            do {
                var_a0 = 6;
                var_v0_2 = var_s0 & 0xFFFF;
loop_4:
                temp_v1_2 = var_v0_2 * 0x10;
                var_s0_2 = temp_v1_2 | temp_t1;
                if (!(((s32) *var_a2 >> var_a0) & 1)) {
                    var_s0_2 = temp_v1_2;
                }
                var_a0 += 1;
                var_v0_2 = var_s0_2 & 0xFFFF;
                if (var_a0 < 8) {
                    goto loop_4;
                }
                var_a0_2 = 2;
                var_a1->unk0 = (u16) (var_a1->unk0 | (var_s0_2 << 8));
                var_a3 = *var_a2;
                var_v0_3 = var_s0_2 & 0xFFFF;
loop_8:
                temp_v1_3 = var_v0_3 * 0x10;
                var_s0 = temp_v1_3 | temp_t1;
                if (!(((s32) var_a3 >> var_a0_2) & 1)) {
                    var_s0 = temp_v1_3;
                }
                var_a0_2 += 1;
                var_v0_3 = var_s0 & 0xFFFF;
                if (var_a0_2 < 6) {
                    goto loop_8;
                }
                var_a1->unk2 = var_s0;
                var_a1 = var_a1 + 2 + 0x6A;
                var_t0 += 1;
                var_a2 += 1;
            } while (var_t0 < 0xC);
            var_t0_2 = 0;
        } else {
            temp_t1_2 = temp_s4 & 0xFFFF;
            var_a1_2 = temp_t2;
            do {
                var_a0_3 = 4;
                var_v0_4 = var_s0 & 0xFFFF;
loop_15:
                temp_v1_4 = var_v0_4 * 0x10;
                var_s0_3 = temp_v1_4 | temp_t1_2;
                if (!(((s32) *var_a2 >> var_a0_3) & 1)) {
                    var_s0_3 = temp_v1_4;
                }
                var_a0_3 += 1;
                var_v0_4 = var_s0_3 & 0xFFFF;
                if (var_a0_3 < 8) {
                    goto loop_15;
                }
                var_a1_2->unk0 = var_s0_3;
                var_a0_4 = 2;
                var_a3 = *var_a2;
loop_19:
                temp_v1_5 = var_v0_4 * 0x10;
                var_s0 = temp_v1_5 | temp_t1_2;
                if (!(((s32) var_a3 >> var_a0_4) & 1)) {
                    var_s0 = temp_v1_5;
                }
                var_a0_4 += 1;
                var_v0_4 = var_s0 & 0xFFFF;
                if (var_a0_4 < 4) {
                    goto loop_19;
                }
                var_a1_2->unk2 = (s16) (var_s0 & 0xFF);
                var_a1_2 = var_a1_2 + 2 + 0x6A;
                var_t0 += 1;
                var_a2 += 1;
            } while (var_t0 < 0xC);
            var_t0_2 = 0;
        }
        var_a2_2 = temp_t2;
        temp_a1 = ((0x24 - D_80127548) * 0x30) + (&D_80127548 + 4);
        var_a0_5 = temp_a1;
        do {
            var_t0_2 += 1;
            var_a0_5->unk0 = (u16) var_a2_2->unk0;
            temp_v0 = var_a2_2->unk2;
            var_a2_2 = var_a2_2 + 2 + 0x6A;
            var_a0_5->unk2 = temp_v0;
            var_a0_5 = var_a0_5 + 2 + 2;
        } while (var_t0_2 < 0xC);
        sp14 = 2;
        sp16 = 0xC;
        func_800599B8(&sp10, temp_a1, var_a2_2, var_a3);
        var_v0 = 0;
    }
    return var_v0;
}
