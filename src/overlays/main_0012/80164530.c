/* Overlay range [80164530,80164744) from MAIN.CD member 0012.
 * SHA256(span)=a1e1cbc2d42d0f9a7ac7ab0f6fa334e736cb261833911050c802dba1dfce41a9.
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
s16 func_80012DBC(s16, s16, s32, s32);                  /* extern */
s16 func_80047D3C(s32, s32);                        /* extern */
s32 func_8004CFEC(s32, s16);                        /* extern */
s16 func_8014C59C(void *, void *);                     /* static */
extern s32 D_800AF630;
extern s32 *D_801202A0;
extern s32 *D_80126720;

void func_80164530(void *arg0) {
    void *var_s1;
    void *var_s5;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 var_s2;
    s16 var_s6;
    s32 temp_lo;
    s32 temp_s0;
    u32 temp_v1;
    u32 temp_v1_2;
    void *temp_s4;

    var_s5 = saved_reg_s5;
    var_s6 = saved_reg_s6;
    var_s1 = &D_801202A0;
    temp_s4 = arg0->unk20;
    var_s2 = 0x1000;
    if ((u32) &D_801202A0 < (u32) (&D_801202A0 + 0x6480)) {
        do {
            if (var_s1->unk5C & 0x2000) {
                temp_v0 = func_8014C59C(arg0, var_s1);
                temp_v0_2 = func_80012A60(temp_v0, temp_s4->unk12);
                if ((temp_v0_2 < 0x200) && (temp_v0_2 < var_s2)) {
                    var_s6 = temp_v0;
                    var_s2 = temp_v0_2;
                    var_s5 = var_s1;
                }
            }
            var_s1 += 0x10C;
        } while ((u32) var_s1 < (u32) &D_80126720);
    }
    if (var_s2 != 0x1000) {
        arg0->unk20->unk12 = func_80012DBC(temp_s4->unk12, var_s6, 0xA, 1);
        if (D_800AF630.unkA3D8 == 0x30A0) {
            temp_s0 = var_s5->unk58 & 0x0FFFFFFF;
            if (temp_s0 != 0) {
                temp_v1 = temp_s0->unkC + temp_s0->unkE;
                temp_v0_3 = (var_s5->unkE + ((s32) (temp_v1 + (temp_v1 >> 0x1F)) >> 1)) - arg0->unkE;
                temp_lo = temp_v0_3 * temp_v0_3;
                temp_v1_2 = temp_s0->unk4 + temp_s0->unk6;
                temp_v0_4 = (var_s5->unk6 + ((s32) (temp_v1_2 + (temp_v1_2 >> 0x1F)) >> 1)) - arg0->unk6;
                arg0->unk20->unk10 = (s16) (func_8004CFEC((var_s5->unkA + ((s32) (temp_s0->unk8 + temp_s0->unkA) / 2)) - arg0->unkA, func_80047D3C(temp_lo + (temp_v0_4 * temp_v0_4), temp_lo)) & 0xFFF);
            }
        }
    }
}
