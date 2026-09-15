/* Overlay range [80150EC4,80150F78) from MAIN.CD member 0012.
 * SHA256(span)=9e40e1c33fbb4f4dfff6aad0f3f3824c1a8df05d729259996e0e37289c38c520.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800AE6B0;
extern s8 D_800AE6BE;
extern s8 D_800AE6C0;
extern s32 D_800AE6C4;
extern u16 D_800AE6C8;
extern u16 D_800AE6CA;
extern u16 D_800AE6CC;
extern u16 D_800AE6CE;
extern s32 *D_801201F8;
extern s32 *D_80126948;

void func_80150EC4(void *arg0, s32 arg1) {
    s32 *var_a2;
    s32 *var_a3;

    D_800AE6C0 = 1;
    D_800AE6C8 = M2C_FIELD(arg0, u16 *, 6);
    var_a3 = &D_801201F8;
    D_800AE6CA = M2C_FIELD(arg0, u16 *, 0xA);
    var_a2 = &D_80126948;
    D_800AE6CC = M2C_FIELD(arg0, u16 *, 0xE);
    D_800AE6CE = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 0x12);
    D_800AE6BE = arg1 + 1;
    D_800AE6B0 = M2C_FIELD(((arg1 * 4) + D_800AE6C4), s32 *, 4);
    do {
        M2C_FIELD(var_a3, s32 *, 0) = M2C_FIELD(var_a2, s32 *, 0);
        M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
        M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
        M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (&D_80126948 + 0xA0));
    *var_a3 = *var_a2;
}
