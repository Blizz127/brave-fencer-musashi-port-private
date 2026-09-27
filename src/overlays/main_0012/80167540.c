/* Overlay range [80167540,80167714) from MAIN.CD member 0012.
 * SHA256(span)=2fbd76279d631426fe631cc88435d2a84ad064c5f7efaf51204970a1261e6c2c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C49C(void *);                          /* extern */
void *func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146C3C(void *);                      /* static */
void func_801670E4(void *, s32, s32, s32); /* static */

void func_80167540(void *arg0) {
    s32 var_v0;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_s1 = M2C_FIELD(arg0, void **, 0x34);
    if (M2C_FIELD(temp_s1, u16 *, 0) == 1) {
        if (M2C_FIELD(arg0, s16 *, 0x10) < M2C_FIELD(arg0, s16 *, 0x12)) {
            if (M2C_FIELD(arg0, s32 *, 0x1C) > 0) {
                M2C_FIELD(arg0, s16 *, 0x10) = (s16) (func_8005C49C(arg0) & 0x30);
                var_v0 = -0x30;
                goto block_6;
            }
        } else if (M2C_FIELD(arg0, s32 *, 0x1C) < 0) {
            M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((func_8005C49C(arg0) & 0x30) + 0x40);
            var_v0 = 0x30;
block_6:
            M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
        }
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((u16) M2C_FIELD(arg0, s16 *, 0x12) + M2C_FIELD(arg0, s32 *, 0x1C));
        temp_v0 = M2C_FIELD(temp_s1, void **, 0x20);
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0, s32 *, 0x38);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(temp_v0, s32 *, 0x3C);
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(temp_v0, s32 *, 0x40);
        M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(temp_v0, s32 *, 0x44);
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(temp_v0, s32 *, 0x48);
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(temp_v0, s32 *, 0x4C);
        M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(temp_v0, s32 *, 0x50);
        func_801670E4(arg0, 0, 0, 0);
        temp_v0_2 = func_80146A6C(0xE, arg0, M2C_FIELD(temp_s1, s16 *, 6), M2C_FIELD(temp_s1, s16 *, 0xA), (s32) M2C_FIELD(temp_s1, s16 *, 0xE), 0, 0);
        if (temp_v0_2 != 0) {
            temp_v0_3 = M2C_FIELD(temp_s1, void **, 0x20);
            M2C_FIELD(temp_v0_2, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x34);
            M2C_FIELD(temp_v0_2, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x38);
            M2C_FIELD(temp_v0_2, s32 *, 0x40) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x3C);
            M2C_FIELD(temp_v0_2, s32 *, 0x44) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x40);
            M2C_FIELD(temp_v0_2, s32 *, 0x48) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x44);
            M2C_FIELD(temp_v0_2, s32 *, 0x4C) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x48);
            M2C_FIELD(temp_v0_2, s32 *, 0x50) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x4C);
            M2C_FIELD(temp_v0_2, s32 *, 0x54) = (s32) M2C_FIELD(temp_v0_3, s32 *, 0x50);
        }
        if (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x4C), s32 *, 0x44) & 0x20) {
            M2C_FIELD(arg0, s32 *, 0x30) = 0x600;
            M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        }
    } else {
        func_80146C3C(arg0);
    }
}
