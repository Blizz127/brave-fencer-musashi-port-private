/* Overlay range [8014D820,8014DCE0) from MAIN.CD member 0012.
 * SHA256(span)=8f19265c113a71de8553a530a6d8d2126b654b7b1f37f0f9dc6159dfe995c03a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012A60(s16, s16);                        /* extern */
void func_800139C8(s16, s32 (*)(), u16 *);               /* extern */
s16 func_8004CFEC(s16, s16, u16, u16);              /* extern */
extern s32 D_8017FFD0;
s32 func_80133784(s32, u16 *, s16 *);                 /* static */
void func_80135888(s32, s32, u16 *, s16 *);            /* static */
s32 func_80135A4C(s32, s32, void *, void *);        /* static */
s32 func_8014DCE0(u16 *, u16 *, u16 *);             /* static */
extern s16 D_800B9A08;
extern u16 D_801152A8;
extern u16 D_801152AC;
extern u16 D_801202A0;

s32 func_8014D820(void *arg0, void *arg1, void *arg2) {
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp37;
    u16 sp34;                                       /* compiler-managed */
    u16 sp32;
    s16 sp30;
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_a0;
    s16 temp_a1_2;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s1;
    s16 temp_s1_2;
    s16 temp_s1_3;
    s16 temp_t0;
    s32 temp_a1;
    s32 temp_a1_3;
    s32 temp_v0_2;
    u16 *temp_v1;
    u16 *temp_v1_2;
    u16 *var_s0;
    u16 *var_s0_2;
    u16 *var_s1;
    u16 *var_s1_2;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v1_3;
    u16 var_v0;
    void *temp_s2;

    temp_s0 = arg2->unk0 - arg1->unk0;
    temp_s1 = arg2->unk4 - arg1->unk4;
    if (((temp_s0 | temp_s1) << 0x10) != 0) {
        sp30 = temp_s0;
        sp32 = arg2->unk2 - arg1->unk2;
        sp34 = arg2->unk4 - arg1->unk4;
        temp_s2 = arg0->unk170;
        if ((temp_s2->unk0 != 0) && (temp_s2->unk5C & 0x1000)) {
            temp_a1 = temp_s2->unk58;
            if ((temp_a1 != 0) && (func_80135A4C(temp_s2->unk20, temp_a1, arg1, arg2) != 0)) {
                temp_s1_2 = temp_s2->unk6 - arg0->unk6;
                temp_s0_2 = temp_s2->unkE - arg0->unkE;
                temp_s0_3 = func_8004CFEC(temp_s1, temp_s0);
                if (func_80012A60(temp_s0_3, func_8004CFEC(temp_s0_2, temp_s1_2)) < 0x400) {
                    sp50 = 0;
                    sp4C = 0;
                    sp48 = 0;
                    temp_a2 = temp_s2->unk6;
                    temp_t0 = temp_a2 + (u16) sp30;
                    sp28 = temp_a2;
                    temp_v0 = temp_s2->unkA;
                    sp2A = temp_v0;
                    temp_a3 = temp_s2->unkE;
                    sp32 = temp_v0 + sp32 + 8;
                    temp_a1_2 = temp_a3 + sp34;
                    sp30 = temp_t0;
                    sp2C = temp_a3;
                    sp34 = temp_a1_2;
                    if (D_800B9A08 != 0x3008) {
                        var_s1 = &D_801202A0;
                        temp_v1 = &D_801202A0 + 0x6480;
                        if ((u32) &D_801202A0 < (u32) temp_v1) {
                            var_s0 = &D_801202A0 + 0x20;
                            do {
                                if ((var_s1 != temp_s2) && (*var_s1 != 0) && (var_s0->unk3C != 0)) {
                                    temp_a1_3 = var_s0->unk38;
                                    if (temp_a1_3 != 0) {
                                        func_80135888(var_s0->unk0, temp_a1_3, &sp28, &sp30);
                                    }
                                }
                                var_s1 += 0x10C;
                                var_s0 += 0x10C;
                            } while ((u32) var_s1 < (u32) temp_v1);
                        }
                    } else {
                        temp_s1_3 = func_8004CFEC((s16) temp_a2 - temp_t0, (s16) temp_a3 - temp_a1_2, temp_a2, temp_a3) & 0xFFF;
                        func_800139C8(temp_s1_3, D_8017FFD0, &sp10);
                        func_800139C8((s16) (temp_s1_3 - 0x155), D_8017FFD0, &sp18);
                        func_800139C8(temp_s1_3 + 0x155, D_8017FFD0, &sp20);
                        sp10 += sp28;
                        sp14 += sp2C;
                        var_s1_2 = &D_801202A0;
                        sp12 = sp2A;
                        sp1A = sp2A;
                        sp22 = sp2A;
                        sp18 += sp28;
                        sp1C += sp2C;
                        sp24 += sp2C;
                        temp_v1_2 = &D_801202A0 + 0x6480;
                        sp20 += sp28;
                        if ((u32) &D_801202A0 < (u32) temp_v1_2) {
                            var_s0_2 = &D_801202A0 + 0x58;
                            do {
                                if ((var_s1_2 != temp_s2) && (*var_s1_2 != 0) && (var_s0_2->unk4 != 0) && (var_s0_2->unk0 != 0) && (func_8014DCE0(var_s1_2, &sp28, &sp10) != 0)) {
                                    unksp33 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                                    sp37 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                                }
                                var_s1_2 += 0x10C;
                                var_s0_2 += 0x10C;
                            } while ((u32) var_s1_2 < (u32) temp_v1_2);
                        }
                    }
                    temp_v0_2 = func_80133784(0, &sp28, &sp30);
                    if ((temp_v0_2 == 0) || ((temp_v0_2 == 0x2000) && ((D_801152A8 | D_801152AC) == 0))) {
                        temp_s2->unk6 = (u16) ((u16) sp30 - sp48);
                        temp_s2->unkA = sp32;
                        temp_s2->unkE = (u16) ((u16) sp34 - sp50);
                        temp_a0 = (u16) sp30 - sp28;
                        temp_v1_3 = (u16) sp34 - sp2C;
                        sp30 = temp_a0;
                        sp34 = temp_v1_3;
                        temp_v0_3 = sp32 - sp2A;
                        sp32 = temp_v0_3;
                        arg0->unk6 = (u16) (arg1->unk0 + temp_a0);
                        arg0->unkA = (s16) (arg1->unk2 + (temp_v0_3 + 0x10));
                        var_v0 = arg1->unk4 + temp_v1_3;
                    } else {
                        arg0->unk6 = (u16) arg1->unk0;
                        arg0->unkA = (s16) (arg1->unk2 + 0x10);
                        var_v0 = arg1->unk4;
                    }
                    arg0->unkE = var_v0;
                    return 1;
                }
            }
        }
    }
    arg0->unk170 = 0;
    return 0;
}
