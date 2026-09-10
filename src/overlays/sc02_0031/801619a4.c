/* SC02 resident retail span [801619A4,801619D0). Offset 0x3984C at base 80128158.
 * SHA256(span)=6555e7c26f2be1e10876539ab4d55d9c63c6dd500735d6ab0d18a2b6328ff24b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_801619A4 shape (h_exact 97f3cab9); its D_80078EC0 already matches this member; oracle MATCH 11/11.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u8 D_80078EC0;

s32 func_801619A4(s32 *a0) {
    if (*(s16 *)((s32)a0 + 0x1C8) == 0) {
        return 0;
    }
    return D_80078EC0 & 0x7F;
}
