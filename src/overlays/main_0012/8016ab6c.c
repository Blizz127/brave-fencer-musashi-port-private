/* Overlay range [8016AB6C,8016AE5C) from MAIN.CD member 0012.
 * SHA256(span)=770cb9b5d39fcfbf5e3a46ad5fb53b6863f0903f1d533eb1c3141da6a9b76658.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CE28(void *, s32 (*)());       /* extern */
s32 func_80024054(s32 (*)(), s32 (*)());    /* extern */
u32 func_8005C49C(s32);                             /* extern */
void func_800D20C0(u16 *, void *, s32);   /* extern */
extern s32 D_801814AC;
extern s32 D_801814BC;
extern s32 D_80184668;
extern s32 D_80184690;
void *func_801465C0(s32);                           /* static */
void func_80146C3C(void *);                      /* static */
s32 func_801783D0(s32, s32);                    /* static */

void func_8016AB6C(void *arg0) {
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 (*var_s0_2)();
    s16 var_s3;
    s16 var_v1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s8 var_s0_3;
    u32 temp_v0_3;
    u32 temp_v1;
    void *temp_v0_4;

    var_s0 = 3;
    temp_v0 = func_801783D0(M2C_FIELD(arg0, s32 *, 0x30), 0);
    var_v1 = -0x1000;
    M2C_FIELD(arg0, s32 *, 0x30) = temp_v0;
loop_1:
    temp_v0_2 = var_s0 - 1;
    if (!(temp_v0 & var_v1)) {
        var_s0 = temp_v0_2;
        var_v1 = (s16) ((s32) (var_v1 << 0x10) >> 0x14);
        if (!(temp_v0_2 & 0x8000)) {
            goto loop_1;
        }
    }
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x2C);
    switch (temp_v1) {
    case 0:
        M2C_FIELD(arg0, s16 *, 0x26) = 1;
        M2C_FIELD(arg0, s16 *, 0x24) = 0x60;
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - 0x20);
    default:
block_18:
        M2C_FIELD(arg0, s16 *, 0x2A) = (s16) (4 - ((s32) (var_s0 << 0x10) >> 0xE));
        M2C_FIELD(arg0, s16 *, 0x28) = (s16) var_s0;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0xB;
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        return;
    case 1:
    case 5:
        M2C_FIELD(arg0, s32 *, 0x14) = 0xFFF60000;
        temp_v0_3 = func_8005C49C(temp_v0);
        temp_a0 = var_s0 + 1;
        var_s0 = temp_a0;
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) ((((temp_v0_3 >> 4) & 0xF) - 8) << 0xF);
        M2C_FIELD(arg0, s16 *, 0x26) = 4;
        M2C_FIELD(arg0, s16 *, 0x24) = 0x80;
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) (((temp_v0_3 & 0xF) - 8) << 0xF);
        M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) | (0xA << ((s32) (temp_a0 << 0x10) >> 0xE)));
        goto block_18;
    case 2:
    case 4:
        M2C_FIELD(arg0, s16 *, 0x26) = 4;
        M2C_FIELD(arg0, s16 *, 0x24) = 0x80;
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - 0x18);
        goto block_18;
    case 3:
        temp_a0_2 = var_s0 + 1;
        var_s0 = temp_a0_2 + 1;
        M2C_FIELD(arg0, s16 *, 0x26) = 4;
        M2C_FIELD(arg0, s16 *, 0x24) = 0x80;
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) - 0x18);
        M2C_FIELD(arg0, s32 *, 0x30) = (s32) ((M2C_FIELD(arg0, s32 *, 0x30) | (0xF << ((s32) (temp_a0_2 << 0x10) >> 0xE))) * 0x10);
        goto block_18;
    case 6:
    case 7:
        temp_v0_4 = func_801465C0(temp_v0);
        if (temp_v0_4 == 0) {
            func_80146C3C(arg0);
            return;
        }
        sp10 = M2C_FIELD(arg0, u16 *, 6);
        sp12 = M2C_FIELD(arg0, u16 *, 0xA) - 0x18;
        sp14 = M2C_FIELD(arg0, u16 *, 0xE);
        func_800D20C0(&sp10, &sp18, 6);
        M2C_FIELD(arg0, u16 *, 6) = sp10;
        M2C_FIELD(arg0, u16 *, 0xA) = sp12;
        M2C_FIELD(arg0, u16 *, 0xE) = sp14;
        if (M2C_FIELD(arg0, u32 *, 0x2C) == 6) {
            var_s0_2 = D_80184668;
            var_s3 = func_80024054(D_801814AC, D_80184668) + 3;
        } else {
            var_s0_2 = D_80184690;
            var_s3 = func_80024054(D_801814BC, D_80184690) + 9;
        }
        func_8001CE28(temp_v0_4, var_s0_2);
        M2C_FIELD(temp_v0_4, s16 *, 0xE) = var_s3;
        M2C_FIELD(temp_v0_4, s32 *, 4) = (s32) (M2C_FIELD(temp_v0_4, s32 *, 4) | 0x04000000);
        if (M2C_FIELD(arg0, u32 *, 0x2C) == 6) {
            M2C_FIELD(temp_v0_4, s8 *, 0x27) = 0xB5;
            var_s0_3 = 0x70;
        } else {
            M2C_FIELD(temp_v0_4, s8 *, 0x27) = 0xAE;
            var_s0_3 = 0xB0;
        }
        var_s0 = (s32) (var_s3 << 0x10) >> 0x12;
        M2C_FIELD(temp_v0_4, s16 *, 0x2E) = -8;
        M2C_FIELD(temp_v0_4, s16 *, 0x30) = 0;
        M2C_FIELD(temp_v0_4, s8 *, 0x26) = var_s0_3;
        M2C_FIELD(temp_v0_4, s8 *, 0x25) = var_s0_3;
        M2C_FIELD(temp_v0_4, s8 *, 0x24) = var_s0_3;
        M2C_FIELD(arg0, void **, 0x20) = temp_v0_4;
        goto block_18;
    }
}
