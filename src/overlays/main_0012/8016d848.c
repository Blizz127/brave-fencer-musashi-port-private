/* Overlay range [8016D848,8016D984) from MAIN.CD member 0012.
 * SHA256(span)=50cc4b871bb534c3e2faa7fd3970d3a8cb385f09443b8e4d96ab2929e13bd494.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D20C0(u16 *, void *, s32);   /* extern */
void func_80146A6C(s32, void *, s32, s32, s32, s32, s32); /* static */
void func_80146C3C();                            /* static */

void func_8016D848(void *arg0) {
    s32 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    s16 temp_v0_2;
    s16 var_s1;
    s32 temp_v0;
    s32 var_s2;
    u16 var_v0;
    u16 var_v1;
    void *temp_a0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
    M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0;
    if (temp_v0 == 0) {
        func_80146C3C();
        return;
    }
    var_s2 = -0xC00;
    if (temp_v0 >= 4) {
        var_s2 = 0x800;
        var_s1 = 0;
        do {
            func_80146A6C(0x33, arg0, 0, 0, 0, 0x8000, 0);
            temp_v0_2 = var_s1 + 1;
            var_s1 = temp_v0_2;
        } while (temp_v0_2 < 5);
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    if ((var_s2 << 0x10) == 0) {
        var_v0 = M2C_FIELD(temp_a0, u16 *, 0x18) ^ 0x400;
        var_v1 = M2C_FIELD(temp_a0, u16 *, 0x1A) ^ 0x200;
    } else {
        var_v0 = M2C_FIELD(temp_a0, u16 *, 0x18) + var_s2;
        var_v1 = M2C_FIELD(temp_a0, u16 *, 0x1A) + var_s2;
    }
    M2C_FIELD(temp_a0, u16 *, 0x18) = var_v0;
    M2C_FIELD(temp_a0, u16 *, 0x1A) = var_v1;
    sp20 = M2C_FIELD(arg0, u16 *, 0x12);
    sp22 = M2C_FIELD(arg0, u16 *, 0x16);
    sp24 = M2C_FIELD(arg0, u16 *, 0x1A);
    func_800D20C0(&sp20, &sp28, 6);
    M2C_FIELD(arg0, u16 *, 6) = sp20;
    M2C_FIELD(arg0, u16 *, 0xA) = sp22;
    M2C_FIELD(arg0, u16 *, 0xE) = sp24;
}
