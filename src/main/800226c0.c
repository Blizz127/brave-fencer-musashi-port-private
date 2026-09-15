/* Main-exec range [800226C0,80023138) from the SLUS executable.
 * SHA256(span)=ec0335578cbe480057ff6aa1171521852cca361a6dcfd46eae6ba6676985cabd.
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

void func_800226C0(void *arg0, void *arg1, void *arg2, s32 *arg3) {
    s16 temp_v1_4;
    s16 temp_v1_5;
    s32 *temp_a0_4;
    s32 *temp_a0_6;
    s32 *temp_a0_8;
    s32 *temp_v1;
    s32 *temp_v1_10;
    s32 *temp_v1_12;
    s32 *temp_v1_3;
    s32 *var_a1;
    s32 *var_a1_7;
    s32 *var_a1_8;
    s32 *var_t0;
    s32 *var_t0_2;
    s32 *var_t2;
    s32 *var_v0;
    s32 temp_a0;
    s32 temp_a0_9;
    s32 temp_lo;
    s32 temp_t9;
    s32 temp_v0;
    s32 temp_v1_11;
    s32 temp_v1_2;
    s32 temp_v1_9;
    s32 var_s1;
    s32 var_t3;
    s32 var_t3_2;
    s32 var_t3_3;
    s32 var_t3_4;
    s32 var_t3_5;
    s32 var_t3_6;
    s32 var_t3_7;
    s32 var_t5_2;
    s32 var_t6;
    s32 var_t6_2;
    s32 var_v0_2;
    s8 var_t8;
    u32 temp_s3;
    void *temp_a0_10;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_5;
    void *temp_a0_7;
    void *temp_v1_6;
    void *temp_v1_7;
    void *temp_v1_8;
    void *var_a0;
    void *var_a1_2;
    void *var_a1_3;
    void *var_a1_4;
    void *var_a1_5;
    void *var_a1_6;
    void *var_a2;
    void *var_t2_2;
    void *var_t2_3;
    void *var_t4;
    void *var_t5;

    var_a2 = arg2;
    temp_s3 = arg0->unk4;
    temp_t9 = arg0->unk1E & 0x8000;
    var_s1 = 0;
    if (temp_s3 & 0x800000) {
        var_t0 = D_800A5E60;
        var_s1 = 1;
        if (temp_t9 != 0) {
            if ((saved_reg_s2 << 0x10) != 0) {
                D_800A5E60 = var_t0 + 0x60;
                var_t3 = 0;
                var_a1 = var_t0 + 4;
                do {
                    temp_a0 = var_t3 >> 1;
                    var_t3 += 1;
                    temp_a0_2 = (temp_a0 * 4) + var_a2;
                    var_a1->unk-1 = 1;
                    var_a1->unk0 = 0xE1000000;
                    var_a1 += 8;
                    *var_t0 = (*var_t0 & 0xFF000000) | (*((temp_a0_2->unk34 * 4) + arg3) & 0xFFFFFF);
                    temp_v1 = (temp_a0_2->unk34 * 4) + arg3;
                    *temp_v1 = (*temp_v1 & 0xFF000000) | ((s32) var_t0 & 0xFFFFFF);
                    var_t0 += 8;
                } while (var_t3 < 0xC);
            } else {
                D_800A5E60 = var_t0 + 0x30;
                var_t3_2 = 0;
                var_t2 = var_t0 + 4;
                var_a1_2 = var_a2;
                do {
                    var_t3_2 += 1;
                    var_t2->unk-1 = 1;
                    var_t2->unk0 = 0xE1000000;
                    var_t2 += 8;
                    *var_t0 = (*var_t0 & 0xFF000000) | (*((var_a1_2->unk34 * 4) + arg3) & 0xFFFFFF);
                    temp_v1_2 = var_a1_2->unk34;
                    var_a1_2 += 4;
                    temp_v1_3 = (temp_v1_2 * 4) + arg3;
                    *temp_v1_3 = (*temp_v1_3 & 0xFF000000) | ((s32) var_t0 & 0xFFFFFF);
                    var_t0 += 8;
                } while (var_t3_2 < 6);
            }
        } else {
            D_800A5E60 = var_t0 + 8;
            var_t0->unk3 = 1;
            var_t0->unk4 = 0xE1000000;
            var_t0->unk0 = (var_t0->unk0 & 0xFF000000) | (*arg3 & 0xFFFFFF);
            *arg3 = (*arg3 & 0xFF000000) | ((s32) var_t0 & 0xFFFFFF);
        }
    }
    var_t0_2 = D_800A5E60;
    temp_v0 = arg0->unk1E & 0x1FFF;
    if (temp_v0 != 0) {
        var_v0 = var_t0_2 + 0x1B0;
    } else {
        var_v0 = var_t0_2 + 0xD8;
    }
    D_800A5E60 = var_v0;
    var_t8 = 0x38;
    if (temp_s3 & 0x40000000) {
        var_t8 = 0x3A;
    }
    var_t3_3 = 0;
    if (temp_v0 != 0) {
        var_a1_3 = sp;
        var_a0 = var_a2;
        do {
            temp_v1_4 = var_a2->unk0;
            var_a1_3->unk0 = (s16) (temp_v1_4 + ((s32) ((var_a0->unk4 - temp_v1_4) * temp_v0) >> 0xC));
            temp_v1_5 = var_a2->unk2;
            temp_lo = (var_a0->unk6 - temp_v1_5) * temp_v0;
            var_t3_3 += 1;
            var_a0 += 4;
            var_a1_3->unk2 = (s16) (temp_v1_5 + (temp_lo >> 0xC));
            var_a1_3 += 4;
        } while (var_t3_3 < 0xC);
        var_t3_4 = 0;
        var_a1_4 = var_t0_2 + 0x22;
        var_t6 = 4;
        var_t5 = sp;
        var_t2_2 = var_a2;
        do {
            var_a1_4->unk-1F = 8;
            var_a1_4->unk-1B = var_t8;
            var_a1_4->unk-1E = (u8) arg1->unk4;
            var_a1_4->unk-1D = (u8) arg1->unk5;
            var_a1_4->unk-1C = (u8) arg1->unk6;
            var_a1_4->unk-16 = (u8) arg1->unk4;
            var_a1_4->unk-15 = (u8) arg1->unk5;
            var_a1_4->unk-14 = (u8) arg1->unk6;
            var_a1_4->unk-E = (u8) arg1->unk0;
            var_a1_4->unk-D = (u8) arg1->unk1;
            var_a1_4->unk-C = (u8) arg1->unk2;
            var_a1_4->unk-6 = (u8) arg1->unk0;
            var_a1_4->unk-5 = (u8) arg1->unk1;
            var_a1_4->unk-4 = (u8) arg1->unk2;
            var_a1_4->unk-1A = (u16) var_t2_2->unk4;
            var_a1_4->unk-18 = (u16) var_t2_2->unk6;
            var_a1_4->unk-12 = (u16) var_t2_2->unk8;
            var_a1_4->unk-10 = (u16) var_t2_2->unkA;
            var_a1_4->unk-A = (u16) var_t5->unk0;
            temp_v1_6 = sp + var_t6;
            var_a1_4->unk-8 = (u16) var_t5->unk2;
            var_a1_4->unk-2 = (u16) temp_v1_6->unk0;
            var_a1_4->unk0 = (u16) temp_v1_6->unk2;
            if (temp_t9 != 0) {
                temp_a0_3 = ((var_t3_4 >> 1) * 4) + var_a2;
                *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*((temp_a0_3->unk34 * 4) + arg3) & 0xFFFFFF);
                temp_a0_4 = (temp_a0_3->unk34 * 4) + arg3;
                *temp_a0_4 = (*temp_a0_4 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
            } else {
                *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*arg3 & 0xFFFFFF);
                *arg3 = (*arg3 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
            }
            var_t6 += 4;
            var_t5 += 4;
            var_t2_2 += 4;
            var_t3_4 += 1;
            var_a1_4 += 0x24;
            var_t0_2 += 0x24;
        } while (var_t3_4 < 0xC);
        var_t0_2->unk-14 = (u16) var_a2->unk4;
        var_t0_2->unk-12 = (u16) var_a2->unk6;
        var_t0_2->unk-4 = sp0;
        var_t0_2->unk-2 = sp2;
        if (arg0->unk1E & 0x4000) {
            var_t3_5 = 0;
            var_t6_2 = 8;
            var_t5_2 = 4;
            var_t0_2 = D_800A5E60;
            var_t4 = sp;
            var_a1_5 = var_t0_2 + 0x22;
            D_800A5E60 = var_t0_2 + 0xD8;
            do {
                var_a1_5->unk-1F = 8;
                var_a1_5->unk-1B = var_t8;
                var_a1_5->unk-1E = (u8) arg1->unkC;
                var_a1_5->unk-1D = (u8) arg1->unkD;
                var_a1_5->unk-1C = (u8) arg1->unkE;
                var_a1_5->unk-16 = (u8) arg1->unkC;
                var_a1_5->unk-15 = (u8) arg1->unkD;
                var_a1_5->unk-14 = (u8) arg1->unkE;
                var_a1_5->unk-E = (u8) arg1->unk8;
                var_a1_5->unk-D = (u8) arg1->unk9;
                var_a1_5->unk-C = (u8) arg1->unkA;
                var_a1_5->unk-6 = (u8) arg1->unkC;
                var_a1_5->unk-5 = (u8) arg1->unkD;
                var_a1_5->unk-4 = (u8) arg1->unkE;
                var_a1_5->unk-1A = (u16) var_t4->unk0;
                temp_v1_7 = sp + var_t5_2;
                var_a1_5->unk-18 = (u16) var_t4->unk2;
                var_a1_5->unk-12 = (u16) temp_v1_7->unk0;
                var_a1_5->unk-10 = (u16) temp_v1_7->unk2;
                var_a1_5->unk-A = (u16) var_a2->unk0;
                temp_v1_8 = sp + var_t6_2;
                var_a1_5->unk-8 = (u16) var_a2->unk2;
                var_a1_5->unk-2 = (u16) temp_v1_8->unk0;
                var_a1_5->unk0 = (u16) temp_v1_8->unk2;
                if (temp_t9 != 0) {
                    temp_a0_5 = ((var_t3_5 >> 1) * 4) + sp;
                    *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*((temp_a0_5->unk34 * 4) + arg3) & 0xFFFFFF);
                    temp_a0_6 = (temp_a0_5->unk34 * 4) + arg3;
                    *temp_a0_6 = (*temp_a0_6 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
                } else {
                    *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*arg3 & 0xFFFFFF);
                    *arg3 = (*arg3 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
                }
                var_t6_2 += 8;
                var_t5_2 += 8;
                var_t4 += 8;
                var_t3_5 += 2;
                var_a1_5 += 0x24;
                var_t0_2 += 0x24;
            } while (var_t3_5 < 0xC);
            var_t0_2->unk-4 = sp0;
            var_t0_2->unk-2 = sp2;
        }
    } else {
        var_t3_6 = 1;
        var_a1_6 = var_t0_2 + 0x22;
        var_t2_3 = var_a2 + 4;
        do {
            var_a1_6->unk-1F = 8;
            var_a1_6->unk-1B = var_t8;
            var_a1_6->unk-1E = (u8) arg1->unk4;
            var_a1_6->unk-1D = (u8) arg1->unk5;
            var_a1_6->unk-1C = (u8) arg1->unk6;
            var_a1_6->unk-16 = (u8) arg1->unk4;
            var_a1_6->unk-15 = (u8) arg1->unk5;
            var_a1_6->unk-14 = (u8) arg1->unk6;
            var_a1_6->unk-E = (u8) arg1->unk0;
            var_a1_6->unk-D = (u8) arg1->unk1;
            var_a1_6->unk-C = (u8) arg1->unk2;
            var_a1_6->unk-6 = (u8) arg1->unk4;
            var_a1_6->unk-5 = (u8) arg1->unk5;
            var_a1_6->unk-4 = (u8) arg1->unk6;
            var_a1_6->unk-1A = (u16) var_t2_3->unk0;
            var_a1_6->unk-18 = (u16) var_t2_3->unk2;
            var_a1_6->unk-12 = (u16) var_t2_3->unk4;
            var_a1_6->unk-10 = (u16) var_t2_3->unk6;
            var_a1_6->unk-A = (u16) var_a2->unk0;
            var_a1_6->unk-8 = (u16) var_a2->unk2;
            var_a1_6->unk-2 = (u16) var_t2_3->unk8;
            var_a1_6->unk0 = (u16) var_t2_3->unkA;
            if (temp_t9 != 0) {
                temp_a0_7 = ((var_t3_6 >> 1) * 4) + var_a2;
                *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*((temp_a0_7->unk34 * 4) + arg3) & 0xFFFFFF);
                temp_a0_8 = (temp_a0_7->unk34 * 4) + arg3;
                *temp_a0_8 = (*temp_a0_8 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
            } else {
                *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*arg3 & 0xFFFFFF);
                *arg3 = (*arg3 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
            }
            var_t2_3 += 8;
            var_t3_6 += 2;
            var_a1_6 += 0x24;
            var_t0_2 += 0x24;
        } while (var_t3_6 < 0xD);
        var_t0_2->unk-4 = (u16) var_a2->unk4;
        var_t0_2->unk-2 = (u16) var_a2->unk6;
    }
    if (temp_s3 & 0x40000000) {
        temp_v1_9 = (temp_s3 >> 0x17) & 0x60;
        if (temp_t9 != 0) {
            var_t3_7 = 0;
            if (temp_v0 != 0) {
                var_a1_7 = var_t0_2 + 4;
                D_800A5E60 += 0x60;
                do {
                    var_a1_7->unk-1 = 1;
                    if (var_s1 != 0) {
                        var_a1_7->unk0 = temp_v1_9 | 0xE1000200;
                    } else {
                        var_a1_7->unk0 = temp_v1_9 | 0xE1000000;
                    }
                    temp_a0_9 = var_t3_7 >> 1;
                    var_t3_7 += 1;
                    temp_a0_10 = (temp_a0_9 * 4) + var_a2;
                    var_a1_7 += 8;
                    *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*((temp_a0_10->unk34 * 4) + arg3) & 0xFFFFFF);
                    temp_v1_10 = (temp_a0_10->unk34 * 4) + arg3;
                    *temp_v1_10 = (*temp_v1_10 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
                    var_t0_2 += 8;
                } while (var_t3_7 < 0xC);
                return;
            }
            var_a1_8 = var_t0_2 + 4;
            D_800A5E60 += 0x30;
            do {
                var_a1_8->unk-1 = 1;
                if (var_s1 != 0) {
                    var_a1_8->unk0 = temp_v1_9 | 0xE1000200;
                } else {
                    var_a1_8->unk0 = temp_v1_9 | 0xE1000000;
                }
                var_t3_7 += 1;
                var_a1_8 += 8;
                *var_t0_2 = (*var_t0_2 & 0xFF000000) | (*((var_a2->unk34 * 4) + arg3) & 0xFFFFFF);
                temp_v1_11 = var_a2->unk34;
                var_a2 += 4;
                temp_v1_12 = (temp_v1_11 * 4) + arg3;
                *temp_v1_12 = (*temp_v1_12 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
                var_t0_2 += 8;
            } while (var_t3_7 < 6);
            return;
        }
        D_800A5E60 += 8;
        var_t0_2->unk3 = 1;
        if (var_s1 != 0) {
            var_v0_2 = 0xE1000200;
        } else {
            var_v0_2 = 0xE1000000;
        }
        var_t0_2->unk4 = (s32) (temp_v1_9 | var_v0_2);
        var_t0_2->unk0 = (var_t0_2->unk0 & 0xFF000000) | (*arg3 & 0xFFFFFF);
        *arg3 = (*arg3 & 0xFF000000) | ((s32) var_t0_2 & 0xFFFFFF);
    }
}
