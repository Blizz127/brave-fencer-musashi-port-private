/* Overlay range [8016DF5C,8016E1CC) from MAIN.CD member 0012.
 * SHA256(span)=cd6dc2a177638756d310fa7db96027160a97ef80feb21f45c38f326a9a366cac.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CD50(void *, s8 *);                /* extern */
void func_800233CC(s8 *, s32);               /* extern */
void func_80048FBC(s32 *, u16 *, u16 *);         /* extern */
void func_8004A0DC(u32, s32 *);                  /* extern */
s32 func_8005C49C(s32, void *);                  /* extern */
extern s32 D_80184EF9;
extern s32 D_80184EFA;
extern s32 D_80184EFD;
extern s32 D_80184EFE;
void *func_801465C0();                              /* static */
void func_80146C3C(u16 *);                       /* static */
void func_8016E3CC(void *);                      /* static */
extern s32 *D_800AE620;
extern u16 D_8011D030;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s8 D_80184EF8;
extern s8 D_80184EFC;

void func_8016DF5C(void *arg0) {
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    u16 sp14;
    s16 sp12;
    u16 sp10;
    s32 temp_v0_3;
    s32 var_s1;
    u16 *var_s0;
    u16 temp_v0;
    u16 var_v0;
    void *temp_s3;
    void *temp_v0_2;

    temp_s3 = M2C_FIELD(arg0, void **, 0x34);
    if (!(M2C_FIELD(arg0, s32 *, 0x2C) & 0x8000)) {
        var_s1 = 0;
        var_s0 = &D_8011D030;
        do {
            if ((var_s0 != arg0) && ((temp_v0 = *var_s0, (temp_v0 == 0x41)) || (temp_v0 == 0x48))) {
                func_80146C3C(var_s0);
            }
            var_s1 += 1;
            var_s0 += 0x58;
        } while ((u32) (var_s1 & 0xFFFF) < 0x1EU);
        temp_v0_2 = func_801465C0();
        if (temp_v0_2 != 0) {
            D_80184EFA = 0xC0;
            D_80184EF8 = 0xC0;
            D_80184EF9 = 0;
            D_80184EFE = 0;
            D_80184EFD = 0;
            D_80184EFC = 0;
            func_800233CC(&D_80184EF8, 0x40);
            func_8001CD50(temp_v0_2, &D_80184EF8);
            M2C_FIELD(temp_v0_2, void **, 0x34) = (void *) (arg0 + 0x38);
            M2C_FIELD(temp_v0_2, s16 *, 0x1A) = 0;
            M2C_FIELD(temp_v0_2, s16 *, 0x18) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 4) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 4) | 0x50000000);
            func_8016E3CC(arg0);
            M2C_FIELD(arg0, void **, 0x20) = temp_v0_2;
            M2C_FIELD(arg0, s32 *, 0x1C) = 0x10;
            var_v0 = M2C_FIELD(arg0, u16 *, 2) + 1;
            goto block_10;
        }
    } else {
        sp10 = 0;
        sp12 = 0;
        sp14 = 0x20;
        sp38 = M2C_FIELD(&D_800AE620, s32 *, 0);
        sp3C = M2C_FIELD(&D_800AE620, s32 *, 4);
        sp40 = M2C_FIELD(&D_800AE620, s32 *, 8);
        sp44 = M2C_FIELD(&D_800AE620, s32 *, 0xC);
        sp48 = M2C_FIELD(&D_800AE620, s32 *, 0x10);
        sp4C = M2C_FIELD(&D_800AE620, s32 *, 0x14);
        sp50 = M2C_FIELD(&D_800AE620, s32 *, 0x18);
        sp54 = M2C_FIELD(&D_800AE620, s32 *, 0x1C);
        temp_v0_3 = func_8005C49C(M2C_FIELD(&D_800AE620, s32 *, 0x14), &D_800AE620);
        func_8004A0DC((u32) (temp_v0_3 & 0x7F00) >> 3, &sp38);
        func_80048FBC(&sp38, &sp10, &sp10);
        M2C_FIELD(arg0, s16 *, 6) = (s16) (D_80126B5E + sp10);
        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (D_80126B62 - (temp_v0_3 & 0x3F));
        M2C_FIELD(arg0, s16 *, 0xE) = (s16) (D_80126B66 + sp14);
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(temp_s3, s32 *, 0x38);
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_s3, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_s3, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(temp_s3, s32 *, 0x44);
        M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(temp_s3, s32 *, 0x48);
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_s3, s32 *, 0x4C);
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(temp_s3, s32 *, 0x50);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(temp_s3, s32 *, 0x54);
        M2C_FIELD(arg0, s32 *, 0x2C) = 0x1000;
        M2C_FIELD(arg0, s32 *, 0x30) = 0xFF;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0x10;
        var_v0 = 4;
block_10:
        M2C_FIELD(arg0, u16 *, 2) = var_v0;
    }
}
