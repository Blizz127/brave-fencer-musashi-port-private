/* Overlay range [8016C49C,8016C74C) from MAIN.CD member 0012.
 * SHA256(span)=f72bd8402af00f6af34dcf739df3747dbd9dfc41f90be21d9dfb7e779368ba1b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016714(s32 (*)(), s32);      /* extern */
void func_8001CD9C(void *, void *);           /* extern */
void func_800233CC(void *, s32);             /* extern */
void func_80047E98(u16 *, u16 *);                /* extern */
void func_80048EAC(void *, void *);           /* extern */
void func_80048FBC(void *, u16 *, u16 *);     /* extern */
void func_80049A1C(u16 *, void *);            /* extern */
s32 func_8005C49C();                                /* extern */
void func_800D23D0(u16 *);                       /* extern */
extern s32 D_80184811;
extern s32 D_80184812;
extern s32 D_80184815;
extern s32 D_80184816;
extern s32 D_801848D0;
void *func_801465C0();                              /* static */
void func_80146A6C(s32, void *, s32, s32, s32, s32, void *); /* static */
void func_80146C3C(u16 *);                       /* static */
void func_8016CF04(void *, s32);             /* static */
extern u16 D_8011D030;
extern s32 *D_80184810;
extern s8 D_80184814;

void func_8016C49C(void *arg0) {
    s32 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    s16 var_s2;
    s16 var_v0;
    s32 temp_v0_2;
    u16 *var_s0;
    u16 var_v0_2;
    void *temp_s3;
    void *temp_s4;
    void *temp_v0;

    temp_s3 = M2C_FIELD(arg0, void **, 0x30);
    temp_s4 = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(arg0, u16 *, 0x28) = (u16) M2C_FIELD(temp_s3, u16 *, 0x36);
    if (!(M2C_FIELD(arg0, s32 *, 0x2C) & 0x8000)) {
        var_s2 = 0;
        var_s0 = &D_8011D030;
        do {
            var_v0 = var_s2 + 1;
            if (var_s0 != arg0) {
                var_v0 = var_s2 + 1;
                if (*var_s0 == 0x30) {
                    func_80146C3C(var_s0);
                    var_v0 = var_s2 + 1;
                }
            }
            var_s2 = var_v0;
            var_s0 += 0x58;
        } while (var_v0 < 0x1E);
        M2C_FIELD(D_80184811, s8 *, 0) = 0xFF;
        D_80184812 = 0x10;
        M2C_FIELD(D_80184811, s8 *, -1) = 0x10;
        D_80184816 = 0;
        D_80184815 = 0;
        D_80184814 = 0;
        func_800233CC(D_80184811 - 1, 0xA);
        sp20 = M2C_FIELD(temp_s3, u16 *, 6) - M2C_FIELD(temp_s4, u16 *, 6);
        sp22 = M2C_FIELD(temp_s3, u16 *, 0xA) - (M2C_FIELD(temp_s4, u16 *, 0xA) + 0x28);
        sp24 = M2C_FIELD(temp_s3, u16 *, 0xE) - M2C_FIELD(temp_s4, u16 *, 0xE);
        func_80047E98(&sp20, &sp20);
        M2C_FIELD(arg0, s16 *, 6) = (s16) (M2C_FIELD(temp_s3, u16 *, 6) + ((s32) (sp20 << 0x10) >> 0x19));
        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(temp_s3, u16 *, 0xA) + (((s32) (sp22 << 0x10) >> 0x19) - 0x28));
        M2C_FIELD(arg0, s16 *, 0xE) = (s16) (M2C_FIELD(temp_s3, u16 *, 0xE) + ((s32) (sp24 << 0x10) >> 0x19));
        func_800D23D0(&sp20);
        sp20 = 0;
        func_80049A1C(&sp20, arg0 + 0x38);
        func_80016714(D_801848D0, 0x620);
        func_80146A6C(0x32, arg0, 0, 0, 0, 0, M2C_FIELD(arg0, void **, 0x30));
        var_v0_2 = 5;
        goto block_9;
    }
    temp_v0 = func_801465C0();
    if (temp_v0 != 0) {
        func_8001CD9C(temp_v0, &D_80184810);
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) | 0x50000000);
        temp_v0_2 = func_8005C49C();
        sp20 = ((temp_v0_2 & 0x7F) * 8) - 0x80;
        sp22 = ((u32) (temp_v0_2 & 0x7F00) >> 4) - 0x400;
        sp24 = 0;
        func_80049A1C(&sp20, &sp28);
        func_80048EAC(arg0 + 0x38, &sp28);
        sp22 = 0;
        sp20 = 0;
        sp24 = 0xB;
        func_80048FBC(&sp28, &sp20, &sp20);
        M2C_FIELD(arg0, u16 *, 0x12) = sp20;
        M2C_FIELD(arg0, u16 *, 0x16) = sp22;
        M2C_FIELD(arg0, void **, 0x20) = temp_v0;
        M2C_FIELD(arg0, s32 *, 0x1C) = 8;
        M2C_FIELD(arg0, u16 *, 0x1A) = sp24;
        func_8016CF04(arg0, 0);
        M2C_FIELD(arg0, s32 *, 0x2C) = 0;
        var_v0_2 = M2C_FIELD(arg0, u16 *, 2) + 1;
block_9:
        M2C_FIELD(arg0, u16 *, 2) = var_v0_2;
    }
}
