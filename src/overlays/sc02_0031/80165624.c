/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165624,80165658).
 * Offset 0x3D4CC at overlay base 80128158. SHA256(span)=951d2fc74a3be56930d257431a63cb0f1e90f7c17d719986f12cef6774ce6f4e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165624.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80165658();
extern u8 D_80078EC1;
extern u16 D_80078EB8;
s32 func_80165624(s32 a0) {
    u32 v = func_80165658(a0, D_80078EC1 & 0x7F) & 0x7F;
    return D_80078EB8 < v;
}
