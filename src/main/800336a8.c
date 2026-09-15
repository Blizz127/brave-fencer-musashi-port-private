/* Exact retail word export for [800336A8,8003388C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AA30;
extern s32 D_80073140;
extern s32 D_8007319E;
extern s32 *D_8007321E;
extern s32 *D_800A4988;
extern u8 D_800A4F19;

void func_800336A8(void *arg0) {
    void *var_t1;
    s32 var_t2;
    s32 var_t3;
    s32 var_v1;
    u16 *var_a2;
    u32 temp_lo;
    u32 temp_v1;
    u32 var_a1;
    u32 var_v0;
    u8 temp_v0;
    u8 var_v1_2;
    void *temp_a3;

    var_t2 = 0;
    var_t3 = 0;
    var_t1 = &D_800A4988;
    do {
        if ((arg0 + var_t2)->unk3A != 0) {
            temp_a3 = var_t3 + (&D_800A4988 + 0x2A0);
            temp_a3->unk0 = (s32) *(D_80073140 + (var_t1->unkA * 4));
            var_a1 = (u32) (*(D_8006AA30 + (var_t1->unk34 * 2)) * D_800A4988.unk572) >> 7;
            if (arg0->unk16 != 0) {
                var_a1 = (u32) (var_a1 * arg0->unk18) >> 0xF;
            }
            var_a2 = arg0 + 0x1C;
            var_v1 = 2;
            do {
                temp_lo = var_a1 * *var_a2;
                var_v1 -= 1;
                var_a2 += 8;
                var_a1 = temp_lo >> 0xE;
            } while (var_v1 >= 0);
            var_v1_2 = var_t1->unk35;
            var_v0 = var_a1;
            if (var_v1_2 != 0) {
                temp_v0 = arg0->unk38;
                if (temp_v0 != 0) {
                    temp_v1 = var_v1_2 + temp_v0;
                    var_v1_2 = temp_v1 - 0x40;
                    if (temp_v1 >= 0x42U) {
                        if (var_v1_2 >= 0x80U) {
                            var_v1_2 = 0x7F;
                        }
                    } else {
                        var_v1_2 = 1;
                    }
                }
                var_t1->unk52 = var_v1_2;
                if (D_800A4F19 != 0) {
                    temp_a3->unkA = (s16) ((u32) (var_a1 * *((var_v1_2 * 2) + D_8007319E)) >> 0xE);
                    var_v0 = (u32) (var_a1 * *(((0x7F - var_v1_2) * 2) + (D_8007319E + 2))) >> 0xE;
                } else {
                    var_v0 = (u32) (var_a1 * D_8007321E) >> 0xE;
                    goto block_15;
                }
            } else {
block_15:
                temp_a3->unkA = (s16) var_v0;
            }
            temp_a3->unk8 = (s16) var_v0;
            temp_a3->unk40 = (s32) var_t1->unkA;
            if (temp_a3->unk44 != 0) {
                temp_a3->unk4 = (s32) (temp_a3->unk4 | 3);
            } else {
                temp_a3->unk4 = 3;
                temp_a3->unk44 = 1U;
            }
        }
        var_t3 += 0x48;
        var_t2 += 1;
        var_t1 += 0x54;
    } while (var_t2 < 8);
}
