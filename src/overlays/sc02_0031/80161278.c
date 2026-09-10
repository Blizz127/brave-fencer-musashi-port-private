/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161278,801612B8).
 * Offset 0x39120 at overlay base 80128158. SHA256(span)=96c8f045866426223cd93b06e1345479f82a730b5d587f49d58d3f4299f4695e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161278.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801152BC;
s32 func_801612B8();
void func_80161374();
void func_80161278(void *p) {
    D_801152BC = 0;
    func_80161374(p, func_801612B8(p, 1));
}
