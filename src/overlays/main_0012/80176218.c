/* Overlay range [80176218,80176734) from MAIN.CD member 0012.
 * SHA256(span)=6d6719e8e7cfc6304153166f1bcc46c9b353a9670e1f4a95940030e54d605508.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80024054(s32, void *);              /* extern */
void func_8005A600(s32 *, s32, s32, s32, s32); /* extern */
extern s32 D_80181AA0[];
extern s32 D_80181B1C[];
void func_80176FF4(s32, u16);                    /* static */
void func_80177340(s32, u16);                    /* static */
void func_80177AD4(s32, s16);                    /* static */
void func_80177DA8(s32, s16, u8);                /* static */
void func_80177F84(s32, s16);                    /* static */
s32 *func_80178298(s32, void *, s16, s16);       /* static */
s16 func_801783D0(s32, s32);                    /* static */
extern s32 *D_80078E78;
extern u16 D_80078EB2;
extern u16 D_80078EB4;
extern s32 *D_8011F7A8;
extern u16 D_8011F82A;
extern u16 D_8011F82C;
extern u16 D_8011F8C4;

void func_80176218(s32 arg0) {
    s32 sp18;
    s16 temp_s0_2;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 var_v0_4;
    s32 *temp_v0_7;
    s32 temp_s1_2;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1_2;
    s32 var_v0_3;
    u16 temp_v1;
    u16 temp_v1_3;
    u16 var_a0;
    u16 var_v0;
    u16 var_v0_2;
    void *temp_a0;
    void *temp_s0;
    void *temp_s0_3;
    void *temp_s1;
    void *temp_s2;

    temp_s1 = &D_8011F7A8 + 0x48;
    temp_s2 = &D_8011F7A8 + 0xE0;
    temp_v0 = D_80078EB2 != D_8011F82A;
    if (D_8011F82C == D_80078EB4) {
        if (temp_v0 == 0) {
            if (D_8011F8C4 != 0) {
                if (temp_v0 != 0) {
                    goto block_14;
                }
                M2C_FIELD(&D_8011F7A8, s16 *, 0x11C) = 0;
                goto block_16;
            }
        } else {
block_14:
            M2C_FIELD(&D_8011F7A8, u16 *, 0x82) = (u16) D_80078EB2;
            M2C_FIELD(&D_8011F7A8, s16 *, 0x11C) = 1;
            goto block_16;
        }
    } else {
        temp_v0_2 = D_8011F82C - D_80078EB4;
        if (temp_v0_2 < 0) {
            if (temp_v0_2 < -0xA) {
                var_v0 = D_8011F82C + 2;
            } else {
                var_v0 = D_8011F82C + 1;
            }
        } else if (temp_v0_2 >= 0xB) {
            var_v0 = D_8011F82C - 2;
        } else {
            var_v0 = D_8011F82C - 1;
        }
        D_8011F82C = var_v0;
        M2C_FIELD(temp_s2, s16 *, 0x3C) = 1;
        M2C_FIELD(temp_s1, u16 *, 0x3A) = (u16) M2C_FIELD(&D_80078E78, u16 *, 0x3A);
block_16:
        func_80176FF4(M2C_FIELD((((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8), s32 *, 0x18), D_80078EB2);
    }
    temp_v1 = M2C_FIELD(temp_s1, u16 *, 0x40);
    temp_v0_3 = M2C_FIELD(&D_80078E78, u16 *, 0x3E) != M2C_FIELD(temp_s1, u16 *, 0x3E);
    if (temp_v1 == M2C_FIELD(&D_80078E78, u16 *, 0x40)) {
        if (temp_v0_3 == 0) {
            if (M2C_FIELD(temp_s2, u16 *, 0x40) != 0) {
                if (temp_v0_3 != 0) {
                    goto block_28;
                }
                M2C_FIELD(temp_s2, u16 *, 0x40) = 0U;
                goto block_30;
            }
        } else {
block_28:
            M2C_FIELD(temp_s1, u16 *, 0x3E) = (u16) M2C_FIELD(&D_80078E78, u16 *, 0x3E);
            M2C_FIELD(temp_s2, u16 *, 0x40) = 1U;
            goto block_30;
        }
    } else {
        temp_v0_4 = temp_v1 - M2C_FIELD(&D_80078E78, u16 *, 0x40);
        if (temp_v0_4 < 0) {
            var_v0_2 = temp_v1 + 2;
            if (temp_v0_4 >= -0xA) {
                var_v0_2 = temp_v1 + 1;
            }
        } else {
            var_v0_2 = temp_v1 - 1;
            if (temp_v0_4 >= 0xB) {
                var_v0_2 = temp_v1 - 2;
            }
        }
        M2C_FIELD(temp_s1, u16 *, 0x40) = var_v0_2;
        M2C_FIELD(temp_s2, u16 *, 0x40) = 1U;
        M2C_FIELD(temp_s1, u16 *, 0x3E) = (u16) M2C_FIELD(&D_80078E78, u16 *, 0x3E);
block_30:
        temp_s0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8;
        func_80177340(M2C_FIELD(temp_s0, s32 *, 0x18) + 0x104, M2C_FIELD(&D_80078E78, u16 *, 0x3E));
        temp_a0 = M2C_FIELD(temp_s0, void **, 0x28);
        if ((u16) M2C_FIELD(temp_s1, u16 *, 0x40) < 0x64U) {
            M2C_FIELD(temp_a0, u8 *, 0x5D) = (u8) *(D_80181B1C + ((M2C_FIELD(temp_s1, u16 *, 0x40) / 5) & 0xFFFF));
        } else {
            M2C_FIELD(temp_a0, u8 *, 0x5D) = 0U;
        }
    }
    temp_v1_2 = M2C_FIELD(temp_s1, s32 *, 0x14);
    temp_v0_5 = M2C_FIELD(&D_80078E78, s32 *, 0x14) - temp_v1_2;
    if (temp_v1_2 == M2C_FIELD(&D_80078E78, s32 *, 0x14)) {
        if (M2C_FIELD(temp_s2, s32 *, 0x14) != 0) {
            M2C_FIELD(temp_s2, s32 *, 0x14) = 0;
            goto block_42;
        }
    } else {
        if (temp_v0_5 > 0) {
            var_v0_3 = temp_v1_2 + 1;
            if (temp_v0_5 >= 0xA) {
                var_v0_3 = temp_v1_2 + 0xA;
            }
        } else {
            var_v0_3 = temp_v1_2 - 0xA;
            if (temp_v0_5 >= -9) {
                var_v0_3 = temp_v1_2 - 1;
            }
        }
        M2C_FIELD(temp_s1, s32 *, 0x14) = var_v0_3;
        M2C_FIELD(temp_s2, s32 *, 0x14) = 1;
block_42:
        func_80177F84(M2C_FIELD((((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8), s32 *, 0x18) + 0x208, func_801783D0(M2C_FIELD(temp_s1, s32 *, 0x14), 0));
    }
    if (M2C_FIELD(&D_80078E78, u16 *, 0x34) != M2C_FIELD(temp_s1, u16 *, 0x34)) {
        M2C_FIELD(temp_s1, u16 *, 0x34) = (u16) M2C_FIELD(&D_80078E78, u16 *, 0x34);
        M2C_FIELD(temp_s2, u16 *, 0x34) = 1U;
        M2C_FIELD(temp_s1, u8 *, 0x42) = (u8) M2C_FIELD(&D_80078E78, u8 *, 0x42);
        goto block_47;
    }
    if (M2C_FIELD(temp_s2, u16 *, 0x34) != 0) {
        M2C_FIELD(temp_s2, u16 *, 0x34) = 0U;
block_47:
        temp_v1_3 = M2C_FIELD(temp_s1, u16 *, 0x34);
        var_a0 = 0x3E7;
        if (temp_v1_3 < 0x3E8U) {
            var_a0 = temp_v1_3;
        }
        func_80177DA8(M2C_FIELD((((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8), s32 *, 0x18) + 0x294, func_801783D0((s32) (s16) var_a0, 4), M2C_FIELD(temp_s1, u8 *, 0x42));
    }
    if (M2C_FIELD(temp_s1, s16 *, 0x1A) != M2C_FIELD(&D_80078E78, s16 *, 0x1A)) {
        M2C_FIELD(temp_s1, s16 *, 0x1A) = (s16) M2C_FIELD(&D_80078E78, s16 *, 0x1A);
        M2C_FIELD(temp_s2, s16 *, 0x1A) = 1;
        goto block_54;
    }
    if (M2C_FIELD(temp_s2, s16 *, 0x1A) != 0) {
        M2C_FIELD(temp_s2, s16 *, 0x1A) = 0;
block_54:
        var_v0_4 = 0x200;
        if (!((u16) M2C_FIELD(temp_s1, s16 *, 0x1A) & 1)) {
            var_v0_4 = M2C_FIELD(&D_8011F7A8, u16 *, 0x16) + 0x65;
        }
        M2C_FIELD(M2C_FIELD((((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8), void **, 0x18), s16 *, 0x32A) = var_v0_4;
        temp_v0_6 = M2C_FIELD(temp_s1, s16 *, 0x1A) / 15;
        temp_s0_2 = func_801783D0((s32) (temp_v0_6 << 0x10) >> 0x12, 8);
        func_80177AD4(M2C_FIELD((((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8), s32 *, 0x18) + 0x320, (s16) (temp_s0_2 + func_801783D0((s32) (s16) ((temp_v0_6 & 3) * 0xF), 0)));
    }
    if (M2C_FIELD(&D_80078E78, u8 *, 0x4A) != M2C_FIELD(temp_s1, u8 *, 0x4A)) {
        M2C_FIELD(temp_s1, u8 *, 0x4A) = (u8) (M2C_FIELD(&D_80078E78, u8 *, 0x4A) & 0x7F);
        M2C_FIELD(temp_s2, u8 *, 0x4A) = 1U;
        goto block_61;
    }
    if (M2C_FIELD(temp_s2, u8 *, 0x4A) != 0) {
        M2C_FIELD(temp_s2, u8 *, 0x4A) = 0U;
block_61:
        temp_s0_3 = ((s32) (arg0 << 0x10) >> 0xE) + &D_8011F7A8;
        temp_s1_2 = M2C_FIELD(temp_s0_3, s32 *, 0x18) + 0x384;
        func_80024054(*(D_80181AA0 + (M2C_FIELD(temp_s1, u8 *, 0x4A) * 4)), &sp18);
        temp_v0_7 = func_80178298(temp_s1_2, &sp18, (s16) (M2C_FIELD(&D_8011F7A8, u16 *, 0x14) + 0x39), (s16) (M2C_FIELD(&D_8011F7A8, u16 *, 0x16) + 0x5B));
        func_8005A600(temp_v0_7, 0, 0, 0x15, 0);
        *temp_v0_7 = ((s32) (temp_v0_7 - 0x14) & 0xFFFFFF) | 0x02000000;
        M2C_FIELD(temp_s0_3, s32 **, 0x20) = temp_v0_7;
    }
}
