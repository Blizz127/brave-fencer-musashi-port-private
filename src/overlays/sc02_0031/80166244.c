/* SC02.CD FILE_031 / ov_SC02_031 retail span [80166244,8016629C).
 * Offset 0x3E0EC at overlay base 80128158. SHA256(span)=1c5f1abf69e9df6a51bc82b68ebbb790770d1f78a4dbc3836442222b5cb3eadc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80166244.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146A6C();
void func_80166244(s16 *p) {
    func_80146A6C(3, p, p[3], (s16)((u16)p[5] - 0x10), p[7], 0x08F8FFF8, 0xE000B000);
}
