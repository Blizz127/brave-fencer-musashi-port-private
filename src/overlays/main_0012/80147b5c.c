/* Overlay range [80147B5C,80147C30) from MAIN.CD member 0012.
 * SHA256(span)=0f6c41fa16716552d9a37b6282d157d9faff731657366a8a9d305c9bf1e20a92.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147B5C(void *arg0, void *arg1) {
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;

    if (M2C_FIELD(arg0, s32 *, 0x44) & 0x400000) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0x24);
    } else {
        var_v0 = M2C_FIELD(arg1, s32 *, 0);
    }
    D_80127090 = var_v0;
    if (M2C_FIELD(arg0, s32 *, 0x44) & 0x800000) {
        var_v0_2 = M2C_FIELD(arg0, s32 *, 0x28);
    } else {
        var_v0_2 = M2C_FIELD(arg1, s32 *, 4);
    }
    D_80127094 = var_v0_2;
    if (M2C_FIELD(arg0, s32 *, 0x44) & 0x01000000) {
        var_v0_3 = M2C_FIELD(arg0, s32 *, 0x2C);
    } else {
        var_v0_3 = M2C_FIELD(arg1, s32 *, 8);
    }
    D_80127098 = var_v0_3;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_80127090;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) D_80127094;
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
