/* Overlay range [80176734,80176D00) from MAIN.CD member 0012.
 * SHA256(span)=901e48d6b5fc0b412a61aa3b2274c24a08d931db38b9f6c93a34024c752e6b3e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800183E0(void *, void *);                       /* extern */
extern s32 D_80181A8E;
extern s32 D_80181A9C;
extern s32 D_80181B30;
extern s32 D_80181B3C;
extern s32 D_80181B48;
s32 func_801619D0(void *);                             /* static */
s32 func_80161A00(void *);                             /* static */
s32 func_80161A30(void *);                             /* static */
s32 func_80161A60(void *);                             /* static */
void func_801775E0(void *, s16, s32);                  /* static */
extern s32 D_80078E78;
extern u8 D_800B9A13;
extern s32 *D_800D43D4;
extern s32 *D_800D4414;
extern s32 *D_800D45D4;
extern u8 D_80115214;
extern s16 D_801152BA;
extern s32 D_8011F7A8;
extern u8 D_8011F7B0;
extern s32 *D_80126B58;
extern s16 D_80126CE0;
extern s16 D_80126D20;

void func_80176734(s32 arg0) {
    void *var_a0;
    void *var_a0_2;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1_12;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 var_a0_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s5;
    s32 var_v0_3;
    s32 var_v0_4;
    s8 var_v0;
    u16 var_a1;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 temp_v1_10;
    u8 temp_v1_11;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u8 temp_v1_9;
    u8 var_v0_2;
    u8 var_v0_5;
    void *temp_a0;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s1;
    void *temp_s2;

    temp_s1 = &D_8011F7A8 + 0x48;
    temp_s2 = &D_8011F7A8 + 0xE0;
    temp_a1 = (((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8)->unk28;
    if (D_801152BA != 0) {
        var_v0 = D_8011F7B0 - 0x80;
        if ((u32) (D_8011F7B0 & 0xFF) >= 0x80U) {
            var_v0 = ~D_8011F7B0 - 0x80;
        }
        (temp_a1 + 0x3C)->unk4 = var_v0;
        temp_a1->unk4 = var_v0;
        D_8011F7A8.unk8 = (u8) (D_8011F7A8.unk8 + D_80115214);
    } else {
        temp_a1->unk40 = 0x80;
        temp_a1->unk4 = 0x80;
    }
    temp_v1 = temp_s2->unk48;
    if (temp_v1 != 0) {
        temp_a0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8;
        temp_a0->unk28->unkD = (u8) *(D_80181B3C + temp_v1);
        temp_v1_2 = temp_s2->unk48;
        var_v0_2 = temp_v1_2 + 1;
        if (temp_v1_2 >= 4U) {
            temp_v1_3 = temp_s1->unk48;
            temp_a1_2 = temp_a0->unk28;
            temp_v0 = temp_v1_3 & 0xFF;
            if (temp_v1_3 & 0x80) {
                var_a0 = &D_800D45D4;
                temp_a1_2->unk20 = (u16) D_80181A9C;
                goto block_11;
            }
            if (temp_v0 != 0) {
                temp_a1_2->unk20 = (u16) *(D_80181A8E + (temp_v0 * 2));
                var_a0 = *(D_80181B48 + (temp_s1->unk48 * 4));
block_11:
                func_800183E0(var_a0, temp_a1_2);
            }
            temp_v1_4 = temp_s2->unk48;
            temp_a0_2 = temp_v1_4 & 0xFF;
            if (temp_a0_2 == 5) {
                var_v0_2 = temp_v1_4 + 1;
                if (temp_s1->unk48 != 0) {
                    goto block_17;
                }
                goto block_16;
            }
            var_v0_2 = temp_v1_4 + 1;
            if (temp_a0_2 == 0xA) {
block_16:
                temp_s2->unk48 = 0U;
            } else {
                goto block_17;
            }
        } else {
block_17:
            temp_s2->unk48 = var_v0_2;
        }
    } else {
        temp_v0_2 = temp_s1->unk48;
        if (temp_v0_2 != D_80078E78.unk48) {
            if ((temp_v0_2 == 0) && (D_80078E78.unk48 != 0)) {
                temp_s2->unk48 = 5U;
            } else {
                temp_s2->unk48 = 0U;
            }
            temp_s1->unk48 = (u8) D_80078E78.unk48;
            temp_v1_5 = temp_s2->unk48;
            temp_s2->unk48 = (u8) (temp_v1_5 + 1);
            (((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8)->unk28->unkD = (u8) *(D_80181B3C + (temp_v1_5 & 0xFF));
        }
    }
    if (temp_s1->unk2E == D_80078E78.unk2E) {
        if (temp_s2->unk2E != 0) {
            temp_s2->unk2E = 0;
            goto block_28;
        }
    } else {
        temp_s1->unk2E = (s16) D_80078E78.unk2E;
        temp_s2->unk2E = 1;
block_28:
        temp_a0_3 = (((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8)->unk28;
        temp_v1_6 = (u16) temp_s1->unk2E << 0x10;
        if (temp_v1_6 != 0) {
            temp_a0_3->unk49 = (u8) *(D_80181B30 + (temp_v1_6 >> 0x14));
        } else {
            temp_a0_3->unk49 = 0xA0U;
        }
    }
    temp_v1_7 = temp_s1->unk1E & 0x8000;
    if (temp_v1_7 != (D_80078E78.unk1E & 0x8000)) {
        if (temp_v1_7 != 0) {
            var_a0_2 = &D_800D43D4;
            temp_s1->unk1E = 0;
        } else {
            temp_s1->unk1E = -0x8000;
            var_a0_2 = &D_800D4414;
        }
        func_800183E0(var_a0_2);
    }
    temp_v1_8 = D_800B9A13 & 0xFF;
    if (temp_v1_8 != 3) {
        temp_v0_3 = D_8011F7A8.unk7 != temp_v1_8;
        var_s5 = temp_v0_3;
        if (temp_v0_3 != 0) {
            D_8011F7A8.unk7 = (u8) D_800B9A13;
        }
    } else {
        var_s5 = 0;
    }
    if (D_80078E78.unk48 != 4) {
        if ((s32) D_80078E78.unk48 < 5) {
            var_v0_3 = 0;
            if (D_80078E78.unk48 != 3) {

            } else {
                var_v0_4 = func_801619D0(&D_80126B58);
                goto block_50;
            }
        } else if (D_80078E78.unk48 != 5) {
            var_v0_3 = 0;
            if (D_80078E78.unk48 != 6) {

            } else {
                var_v0_3 = 0;
                if (func_80161A60(&D_80126B58) != 0) {
                    var_s0 = 0xBA;
                    goto block_54;
                }
            }
        } else {
            var_v0_4 = func_80161A30(&D_80126B58);
            goto block_50;
        }
    } else {
        var_v0_4 = func_80161A00(&D_80126B58);
block_50:
        var_v0_3 = 0;
        if (var_v0_4 != 0) {
            var_s0 = 0xFF;
block_54:
            var_v0_3 = var_s0;
        }
    }
    if (var_v0_3 != 0) {
        temp_s2->unk47 = 1U;
        temp_s1->unk4B = (u8) (D_80078E78.unk48 | 0xF0);
        temp_s1->unk47 = (u8) ((s32) (D_80126D20 << 7) / var_v0_3);
        goto block_82;
    }
    if ((u8) temp_s1->unk4B >= 0xF0U) {
        temp_s1->unk4B = 0U;
    }
    var_a1 = (u16) D_80126CE0;
    if (D_80126CE0 != 0) {
        temp_s1->unk4B = (u8) var_a1;
        var_s0_2 = temp_s1->unk47 != (var_a1 & 0xFF);
    } else {
        var_a1 = (u16) D_80078E78.unk47;
        temp_v1_9 = temp_s1->unk47;
        var_s0_2 = 0;
        if ((temp_v1_9 != var_a1) || (temp_v1_9 == 0x80)) {
            var_s0_2 = 1;
        }
        if ((D_80078E78.unk47 != 0) && (temp_s1->unk4B != 0)) {
            temp_s1->unk4B = 0U;
            temp_s1->unk47 = (u8) D_80078E78.unk47;
        }
    }
    if ((var_s0_2 == 0) && (var_s5 == 0)) {
        var_a0_3 = arg0 << 0x10;
        if (temp_s2->unk47 != 0) {
            if (var_s5 != 0) {
                goto block_71;
            }
            temp_s2->unk47 = 0U;
            goto block_82;
        }
    } else {
block_71:
        temp_v1_10 = temp_s1->unk47;
        if ((s32) temp_v1_10 >= (s16) var_a1) {
            var_v0_5 = temp_v1_10 - 3;
            if ((s16) var_a1 == 0) {
                var_v0_5 = temp_v1_10 - 8;
            }
            temp_s1->unk47 = var_v0_5;
            temp_v1_11 = temp_s1->unk47;
            if ((temp_v1_11 == 0) || (temp_v1_11 >= 0x81U)) {
                temp_s1->unk47 = 0U;
                temp_s1->unk4B = 0U;
            } else if ((s32) temp_v1_11 < (s16) var_a1) {
                goto block_78;
            }
        } else {
block_78:
            temp_s1->unk47 = (u8) var_a1;
        }
        temp_s2->unk47 = 1U;
block_82:
        var_a0_3 = arg0 << 0x10;
    }
    temp_a0_4 = (var_a0_3 >> 0xE) + &D_8011F7A8;
    temp_v1_12 = (D_8011F7A8.unk7 != 0) << 8;
    temp_a2 = temp_v1_12 + 5;
    temp_a0_4->unk28->unk32 = (s16) (D_8011F7A8.unk12 + temp_a2);
    func_801775E0(temp_a0_4->unk28 + 0x64, (s16) (D_8011F7A8.unk12 + (temp_v1_12 + 9)), temp_a2);
}
