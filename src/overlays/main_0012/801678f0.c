/* Overlay range [801678F0,80167A9C) from MAIN.CD member 0012.
 * SHA256(span)=277b2cabb4a17e90e76064a4743c9f84860703bfcbbcbbaadfbe9b9bc8dadfa0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048EAC(s32, void *);                 /* extern */
void func_80049A1C(s16 *, void *);               /* extern */
s32 func_8005C49C();                                /* extern */
void *func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146C3C(void *);                      /* static */
void func_801670E4(void *, s32, s32, s32); /* static */
extern u16 D_800B99DA;

void func_801678F0(void *arg0) {
    s16 sp24;
    s16 sp22;
    s16 sp20;
    s32 temp_a0;
    s32 var_v0;
    void *temp_s0;
    void *temp_s2;
    void *temp_v0;

    temp_s2 = M2C_FIELD(arg0, void **, 0x34);
    if (M2C_FIELD(temp_s2, s32 *, 0x44) & 0x10) {
        if (M2C_FIELD(arg0, s16 *, 0x10) < M2C_FIELD(arg0, s16 *, 0x12)) {
            if (M2C_FIELD(arg0, s32 *, 0x1C) > 0) {
                M2C_FIELD(arg0, s16 *, 0x10) = (s16) (func_8005C49C() & 0x30);
                var_v0 = -0x30;
                goto block_6;
            }
        } else if (M2C_FIELD(arg0, s32 *, 0x1C) < 0) {
            M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((func_8005C49C() & 0x30) + 0x40);
            var_v0 = 0x30;
block_6:
            M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
        }
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x30);
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x12) + M2C_FIELD(arg0, s32 *, 0x1C));
        if (temp_a0 != 0) {
            M2C_FIELD(arg0, s32 *, 0x30) = (s32) (temp_a0 - 0xC0);
        }
        temp_s0 = arg0 + 0x38;
        sp20 = 0x400;
        sp22 = 0;
        sp24 = D_800B99DA << 8;
        func_80049A1C(&sp20, temp_s0);
        func_80048EAC(M2C_FIELD(temp_s2, s32 *, 0x20) + 0x34, temp_s0);
        func_801670E4(arg0, -6, -0x44, -0x18);
        temp_v0 = func_80146A6C(0xE, arg0, M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg0, s16 *, 0xA), (s32) M2C_FIELD(arg0, s16 *, 0xE), 0, 0);
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, s32 *, 0x38) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
            M2C_FIELD(temp_v0, s32 *, 0x3C) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
            M2C_FIELD(temp_v0, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
            M2C_FIELD(temp_v0, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
            M2C_FIELD(temp_v0, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
            M2C_FIELD(temp_v0, s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
            M2C_FIELD(temp_v0, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
            M2C_FIELD(temp_v0, s32 *, 0x54) = (s32) M2C_FIELD(arg0, s32 *, 0x54);
        }
    } else {
        func_80146C3C(arg0);
    }
}
