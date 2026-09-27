/* Overlay range [8012E364,8012E470) from MAIN.CD member 0012.
 * SHA256(span)=28a311a5ad9a3da9fbc8fc9c09e28f8aa85077e824619bf7cc87e72b3a5b0760.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801840C8;
extern s32 D_801840CC;
extern s16 D_80126CE0;

void func_8012E364(void *arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    void *temp_a0;
    void *temp_a0_2;

    M2C_FIELD(arg0, s16 *, 0x5C) = 0;
    if (D_80126CE0 == 0) {
        D_801840C8 = 0x1000;
        D_801840CC = 0x1000;
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) + 1);
    temp_v0 = D_801840C8 - (((0x90 - D_80126CE0) << 0xC) / 144);
    if (temp_v0 > 0) {
        var_v0 = D_801840C8 - (temp_v0 >> 2);
        goto block_6;
    }
    if (temp_v0 < 0) {
        var_v0 = D_801840C8 + ((s32) -temp_v0 / 4);
block_6:
        D_801840C8 = var_v0;
    }
    temp_a1 = D_801840CC;
    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    D_801840CC = 0x1000;
    temp_v1 = (D_801840C8 - temp_a1) + 0x1000;
    D_801840C8 = temp_v1;
    M2C_FIELD(temp_a0, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x2C) | 0x10);
    temp_a0_2 = M2C_FIELD(arg0, void **, 0x20);
    var_v0_2 = temp_v1;
    if (temp_v1 < 0) {
        var_v0_2 = -var_v0_2;
    }
    M2C_FIELD(temp_a0_2, s16 *, 0x1C) = (s16) var_v0_2;
    M2C_FIELD(temp_a0_2, s16 *, 0x18) = (s16) var_v0_2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x1A) = 0x1000;
}
