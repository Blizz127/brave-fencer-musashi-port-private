/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174630,80174650).
 * Offset 0x4C4D8 at overlay base 80128158. SHA256(span)=d97f95b71f70c5308d0fc5cc8db38c8636b98223c2eabcce72edfc4b840e2f09.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174630.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801270BC;

void func_80174630(void) {
    D_801270BC |= 1;
}
