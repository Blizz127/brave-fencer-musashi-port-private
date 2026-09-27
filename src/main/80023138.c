/* Main-exec range [80023138,800233CC) from the SLUS executable.
 * SHA256(span)=f9d7c1f840c8dc4a5dd3de33f812607ad2553866e88ee00557d6c37c1680164a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A5E60;

void func_80023138(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s32 *temp_v1;
    s32 *temp_v1_2;
    s32 *var_a1;
    s32 *var_t0_2;
    s32 *var_t2;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 var_t3;
    s32 var_t3_2;
    s8 var_t5;
    u16 temp_v0;
    u32 temp_t6;
    void *temp_a0_2;
    void *temp_a0_4;
    void *var_t0;
    void *var_t1;

    var_t2 = D_800A5E60;
    temp_t6 = arg0->unk4;
    D_800A5E60 = var_t2 + 0x1B0;
    var_t5 = 0x38;
    if (temp_t6 & 0x40000000) {
        var_t5 = 0x3A;
    }
    var_t3 = 0;
    var_t0 = var_t2 + 0x22;
    var_t1 = arg2;
    do {
        var_t0->unk-1F = 8;
        var_t0->unk-1B = var_t5;
        var_t0->unk-1E = (u8) arg1->unk4;
        var_t0->unk-1D = (u8) arg1->unk5;
        var_t0->unk-1C = (u8) arg1->unk6;
        var_t0->unk-16 = (u8) arg1->unk4;
        var_t0->unk-15 = (u8) arg1->unk5;
        var_t0->unk-14 = (u8) arg1->unk6;
        var_t0->unk-E = (u8) arg1->unk0;
        var_t0->unk-D = (u8) arg1->unk1;
        var_t0->unk-C = (u8) arg1->unk2;
        var_t0->unk-6 = (u8) arg1->unk0;
        var_t0->unk-5 = (u8) arg1->unk1;
        var_t0->unk-4 = (u8) arg1->unk2;
        var_t0->unk-1A = (u16) var_t1->unk4C;
        var_t0->unk-18 = (u16) var_t1->unk4E;
        var_t0->unk-12 = (u16) var_t1->unk50;
        temp_a0 = var_t3 >> 1;
        var_t0->unk-10 = (u16) var_t1->unk52;
        var_t3 += 1;
        var_t0->unk-A = (u16) var_t1->unk4;
        var_t0->unk-8 = (u16) var_t1->unk6;
        temp_a0_2 = (temp_a0 * 4) + arg2;
        var_t0->unk-2 = (u16) var_t1->unk8;
        temp_v0 = var_t1->unkA;
        var_t1 += 4;
        var_t0->unk0 = temp_v0;
        var_t0 += 0x24;
        *var_t2 = (*var_t2 & 0xFF000000) | (*((temp_a0_2->unk34 * 4) + arg3) & 0xFFFFFF);
        temp_v1 = (temp_a0_2->unk34 * 4) + arg3;
        *temp_v1 = (*temp_v1 & 0xFF000000) | ((s32) var_t2 & 0xFFFFFF);
        var_t2 += 0x24;
    } while (var_t3 < 0xC);
    var_t2->unk-14 = (u16) arg2->unk4C;
    var_t2->unk-12 = (u16) arg2->unk4E;
    var_t2->unk-4 = (u16) arg2->unk4;
    var_t2->unk-2 = (u16) arg2->unk6;
    var_t0_2 = var_t2;
    if (temp_t6 & 0x40000000) {
        var_t3_2 = 0;
        var_a1 = var_t0_2 + 4;
        D_800A5E60 += 0x60;
        do {
            temp_a0_3 = var_t3_2 >> 1;
            var_t3_2 += 1;
            temp_a0_4 = (temp_a0_3 * 4) + arg2;
            var_a1->unk-1 = 1;
            var_a1->unk0 = ((temp_t6 >> 0x17) & 0x60) | 0xE1000000;
            var_a1 += 8;
            *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*((temp_a0_4->unk34 * 4) + arg3) & 0xFFFFFF);
            temp_v1_2 = (temp_a0_4->unk34 * 4) + arg3;
            *temp_v1_2 = (*temp_v1_2 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
            var_t0_2 += 8;
        } while (var_t3_2 < 0xC);
    }
}
