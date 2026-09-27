/* Overlay range [8016C998,8016CB84) from MAIN.CD member 0012.
 * SHA256(span)=1e092e4f215f327cb844cea642c985f86cba371c4e0f7bee424fd07ad71b6553.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801848D0[];
void *func_80146A6C(s32, u16 *, s32, s32, s32, s32, void *); /* static */
void func_8016CBC0();                            /* static */
extern s32 D_80126B9C;
extern s16 D_80126CE0;

void func_8016C998(void *arg0) {
    s16 temp_v0;
    s16 var_s0;
    s32 temp_a0;
    s32 var_v0;
    s32 var_v0_2;
    u16 *temp_s3;
    void *temp_v0_2;

    temp_s3 = M2C_FIELD(arg0, u16 **, 0x34);
    if (*temp_s3 != 1) {
        M2C_FIELD(arg0, s16 *, 2) = 6;
    }
    func_8016CBC0();
    if ((M2C_FIELD(arg0, s16 *, 0x28) == M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x36)) && (D_80126B9C & 0x20)) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x1C);
        if ((temp_a0 == 0) || (var_v0 = temp_a0 - 1, ((M2C_FIELD(arg0, s16 *, 0x12) < D_80126CE0) != 0))) {
            var_s0 = 0;
            M2C_FIELD(arg0, s16 *, 0x12) = (s16) (u16) D_80126CE0;
            var_v0_2 = 0 << 0x10;
loop_7:
            temp_v0 = var_s0 + 1;
            if (*(D_801848D0 + ((var_v0_2 >> 0x10) * 0xC4)) != 0) {
                var_s0 = temp_v0;
                var_v0_2 = var_s0 << 0x10;
                if (temp_v0 < 8) {
                    goto loop_7;
                }
            }
            if (var_s0 < 8) {
                temp_v0_2 = func_80146A6C(0x30, temp_s3, 0, 0, 0, 0x8000, M2C_FIELD(arg0, void **, 0x30));
                if (temp_v0_2 != 0) {
                    *(D_801848D0 + (var_s0 * 0xC4)) = 1;
                    M2C_FIELD(temp_v0_2, s32 *, 0x38) = (s32) M2C_FIELD(arg0, s32 *, 0x38);
                    M2C_FIELD(temp_v0_2, s32 *, 0x3C) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
                    M2C_FIELD(temp_v0_2, s32 *, 0x40) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
                    M2C_FIELD(temp_v0_2, s32 *, 0x44) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
                    M2C_FIELD(temp_v0_2, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x48);
                    M2C_FIELD(temp_v0_2, s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s32 *, 0x4C);
                    M2C_FIELD(temp_v0_2, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s32 *, 0x50);
                    M2C_FIELD(temp_v0_2, s32 *, 0x54) = (s32) M2C_FIELD(arg0, s32 *, 0x54);
                    M2C_FIELD(temp_v0_2, s16 *, 0x2A) = var_s0;
                    M2C_FIELD(temp_v0_2, u16 *, 6) = (u16) M2C_FIELD(arg0, u16 *, 6);
                    M2C_FIELD(temp_v0_2, u16 *, 0xA) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
                    M2C_FIELD(temp_v0_2, u16 *, 0xE) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
                    var_v0 = 0x10;
                    goto block_12;
                }
            }
        } else {
block_12:
            M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
        }
    }
}
