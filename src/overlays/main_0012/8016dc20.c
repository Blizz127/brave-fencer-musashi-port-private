/* Overlay range [8016DC20,8016DEA4) from MAIN.CD member 0012.
 * SHA256(span)=eec8a55e72f54d5e8341091f21634044394ded1504bc76e6dcde0a17f24ed9d6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D1FC8(void *, s32);             /* extern */
void func_800D20C0(u16 *, u16 *, s32);       /* extern */
void *func_800D21C4(void *, s32 (*)(), s32); /* extern */
void func_800D23D0(u16 *);                       /* extern */
extern s32 D_80181684;
extern s32 D_80181690;
extern s32 D_80184EF0;
extern s32 D_80184EF4;
void func_80128EA8(void *, void *, s32 (*)()); /* static */
void func_80128ED8(void *, void *);              /* static */
void *func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146C3C(void *);                      /* static */
void func_80149374(void *, void *);              /* static */
s32 func_801619D0(void *);                          /* static */
extern u16 D_8011D030;

void func_8016DC20(void *arg0) {
    u16 sp2A;
    u16 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    s16 temp_v0;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_v0;
    s16 var_v0_2;
    u16 *var_v1;
    u16 *var_v1_2;
    void *temp_s0;
    void *temp_s3;
    void *temp_v0_2;
    void *temp_v0_3;

    var_s1 = 0;
    var_v1 = &D_8011D030;
    temp_s3 = M2C_FIELD(arg0, void **, 0x34);
loop_1:
    var_v0 = var_s1 + 1;
    if ((var_v1 == arg0) || (var_v0 = var_s1 + 1, (*var_v1 != 0x34))) {
        var_s1 = var_v0;
        var_v1 += 0x58;
        if (var_v0 >= 0x1E) {
            func_80149374(temp_s3, arg0 + 4);
            var_s1_2 = 0;
            if (func_801619D0(temp_s3) != 0) {
                var_v1_2 = &D_8011D030;
loop_6:
                temp_v0 = var_s1_2 + 1;
                if (*var_v1_2 != 0x11) {
                    var_s1_2 = temp_v0;
                    var_v1_2 += 0x58;
                    if (temp_v0 >= 0x1E) {
                        var_s1_3 = 0;
                        func_80146A6C(0x11, arg0, M2C_FIELD(arg0, s16 *, 6), (s16) (M2C_FIELD(arg0, u16 *, 0xA) - 8), (s32) M2C_FIELD(arg0, s16 *, 0xE), 0, 0);
                        sp20 = (u16) M2C_FIELD(arg0, s16 *, 6);
                        sp22 = M2C_FIELD(arg0, u16 *, 0xA);
                        sp24 = (u16) M2C_FIELD(arg0, s16 *, 0xE);
                        func_800D20C0(&sp20, &sp28, 0);
                        sp2A = 0;
                        func_800D23D0(&sp28);
                        do {
                            temp_v0_2 = func_80146A6C(0x12, arg0, M2C_FIELD(temp_s3, s16 *, 6), M2C_FIELD(temp_s3, s16 *, 0xA), (s32) M2C_FIELD(temp_s3, s16 *, 0xE), (s32) var_s1_3, 0);
                            var_v0_2 = var_s1_3 + 2;
                            if (temp_v0_2 != 0) {
                                M2C_FIELD(temp_v0_2, u16 *, 0x12) = sp28;
                                M2C_FIELD(temp_v0_2, s16 *, 0x1A) = 0;
                                M2C_FIELD(temp_v0_2, u16 *, 0x16) = sp2A;
                                var_v0_2 = var_s1_3 + 2;
                            }
                            var_s1_3 = var_v0_2;
                        } while (var_v0_2 < 3);
                        goto block_17;
                    }
                    goto loop_6;
                }
                goto block_13;
            }
block_13:
            if ((D_80184EF0 != M2C_FIELD(temp_s3, s16 *, 6)) || (D_80184EF4 != M2C_FIELD(temp_s3, s16 *, 0xE))) {
                temp_v0_3 = func_800D21C4(arg0, D_80181684, 0x18);
                if (temp_v0_3 != 0) {
                    D_80184EF0 = (s16) (u16) M2C_FIELD(temp_s3, s16 *, 6);
                    D_80184EF4 = (s16) (u16) M2C_FIELD(temp_s3, s16 *, 0xE);
                    func_800D1FC8(arg0, 7);
                    temp_s0 = arg0 + 0x24;
                    M2C_FIELD(arg0, void **, 0x20) = temp_v0_3;
                    M2C_FIELD(temp_v0_3, s16 *, 0x1A) = 0x3000;
                    M2C_FIELD(temp_v0_3, s16 *, 0x18) = 0x3000;
                    M2C_FIELD(temp_v0_3, s8 *, 0x26) = 0xFF;
                    M2C_FIELD(temp_v0_3, s32 *, 4) = (s32) (M2C_FIELD(temp_v0_3, s32 *, 4) | 0x50000000);
                    func_80128EA8(temp_v0_3, temp_s0, D_80181690);
                    func_80128ED8(temp_v0_3, temp_s0);
                    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
                    return;
                }
            }
            goto block_17;
        }
        goto loop_1;
    }
block_17:
    func_80146C3C(arg0);
}
