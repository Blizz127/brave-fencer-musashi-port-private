/* Overlay range [80167714,801678B4) from MAIN.CD member 0012.
 * SHA256(span)=a333a41b9d3dd6768d0c0aa78ad54cfb0e9d6ea2472d2c3a6be4bc90638cdc1b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C49C();                                /* extern */
void func_80146C3C(void *);                      /* static */
void func_80147324();                     /* static */
void func_801670E4(void *, s32, s32, s32); /* static */

void func_80167714(void *arg0) {
    s32 temp_v0;
    s32 var_v0;
    s32 var_v0_2;
    void *temp_s1;
    void *temp_v0_2;

    temp_s1 = M2C_FIELD(arg0, void **, 0x34);
    if (M2C_FIELD(temp_s1, u16 *, 0) == 1) {
        if (M2C_FIELD(arg0, s16 *, 0x10) < M2C_FIELD(arg0, s16 *, 0x12)) {
            if (M2C_FIELD(arg0, s32 *, 0x1C) > 0) {
                M2C_FIELD(arg0, s16 *, 0x10) = (s16) (func_8005C49C() & 0x30);
                var_v0 = -0x20;
                goto block_6;
            }
        } else if (M2C_FIELD(arg0, s32 *, 0x1C) < 0) {
            M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((func_8005C49C() & 0x30) + 0x40);
            var_v0 = 0x20;
block_6:
            M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
        }
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x12) + M2C_FIELD(arg0, s32 *, 0x1C));
        if (M2C_FIELD(arg0, s32 *, 0x2C) & 8) {
            var_v0_2 = M2C_FIELD(arg0, s32 *, 0x30) + 0x80;
        } else {
            var_v0_2 = M2C_FIELD(arg0, s32 *, 0x30) - 0x40;
        }
        M2C_FIELD(arg0, s32 *, 0x30) = var_v0_2;
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x2C);
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (temp_v0 + 1);
        if (!(temp_v0 & 0xF)) {
            func_80147324(0x44E);
        }
        temp_v0_2 = M2C_FIELD(temp_s1, void **, 0x20);
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x34);
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x38);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x44);
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x48);
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x4C);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0x50);
        func_801670E4(arg0, 0, 0, 0);
        if (!(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x4C), s32 *, 0x44) & 0x20)) {
            M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) - 1);
        }
    } else {
        func_80146C3C(arg0);
    }
}
