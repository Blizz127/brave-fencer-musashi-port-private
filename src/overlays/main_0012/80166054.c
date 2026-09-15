/* Overlay range [80166054,801661CC) from MAIN.CD member 0012.
 * SHA256(span)=2defca804b76cbfea19d647449bc35f816ca214f57e4bd2672759c85f2c60066.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004787C(s32);                             /* extern */
s32 func_80047948(s32);                             /* extern */
void func_800D1FC8(void *, s32);             /* extern */
void *func_800D21C4(void *, void *, s32);    /* extern */
void func_80128EA8(void *, void *, void *);   /* static */
void func_80146C3C(void *);                      /* static */
void func_80149374(void *, void *);              /* static */
void func_801661CC(void *);                      /* static */
extern s32 *D_800D387C;
extern s32 *D_800D3888;

void func_80166054(void *arg0) {
    s32 temp_a1;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_v1;
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s4;
    u16 var_v0;
    u32 temp_v0;
    void *temp_s0;
    void *temp_v0_2;

    temp_s0 = M2C_FIELD(arg0, void **, 0x34);
    func_80149374(temp_s0, arg0 + 4);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x2C);
    if (temp_v1 != 0) {
        var_s1 = 8;
        if (temp_v1 != 3) {
            var_s0 = M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x20), u16 *, 0x12) << 0x10;
        } else {
            temp_v0 = M2C_FIELD(arg0, u32 *, 0x30);
            var_s1 = (temp_v0 >> 0xC) & 0xF;
            var_s0 = (temp_v0 & 0xFFF) << 0x10;
        }
        temp_s0_2 = var_s0 >> 0x10;
        temp_s3 = func_8004787C(temp_s0_2) << var_s1;
        var_s4 = -temp_s3;
        temp_a1 = func_80047948(temp_s0_2) << var_s1;
        var_a0 = -temp_a1;
        if (M2C_FIELD(arg0, s32 *, 0x2C) == 2) {
            var_s4 = temp_s3;
            var_a0 = temp_a1;
        }
        M2C_FIELD(arg0, s32 *, 0x10) = var_s4;
        M2C_FIELD(arg0, s32 *, 0x18) = var_a0;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = 0xFFFF0000;
    func_800D1FC8(arg0, 6);
    temp_v0_2 = func_800D21C4(arg0, &D_800D387C, 0x9C);
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, void **, 0x20) = temp_v0_2;
        M2C_FIELD(temp_v0_2, s32 *, 4) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 4) | 0x50000040);
        var_v0 = 0x2000;
        if (M2C_FIELD(arg0, s32 *, 0x2C) == 3) {
            var_v0 = M2C_FIELD(arg0, u16 *, 0x32);
        }
        M2C_FIELD(temp_v0_2, u16 *, 0x18) = var_v0;
        M2C_FIELD(temp_v0_2, u16 *, 0x1A) = (u16) M2C_FIELD(temp_v0_2, u16 *, 0x18);
        func_80128EA8(temp_v0_2, arg0 + 0x24, &D_800D3888);
        func_801661CC(arg0);
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        return;
    }
    func_80146C3C(arg0);
}
