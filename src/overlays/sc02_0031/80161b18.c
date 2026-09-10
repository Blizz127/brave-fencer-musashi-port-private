/* SC02 resident retail span [80161B18,80161B84). Offset 0x399C0 at base 80128158.
 * SHA256(span)=7f0fa660fd707b5e73f78ad4a3d9c3183ed896b89a83775198b2ceed39ff8e7a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_80161B18 shape (h_exact 574a62a2); its D_800AE6B0 already matches this member; oracle MATCH 27/27.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_800AE6B0;
void func_801599A4(void *a0);
void func_8015FA78(s32 *a0);

s32 func_80161B18(void *a0) {
    if ((D_800AE6B0 & 0x80FFFFFF) != 0) return 0;
    if (*(s32 *)((u8 *)a0 + 0x44) & 0x10) {
        func_801599A4(a0);
        func_8015FA78((s32 *)a0);
        return 1;
    }
    return 0;
}
