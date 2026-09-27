/* SC02.CD FILE_031 / ov_SC02_031 retail span [801735B8,801735EC).
 * Offset 0x4B460 at overlay base 80128158. SHA256(span)=3bcb58e8c956be7beaa0f9466eaea1bc3a94626a153e0b4ef931bd41b65b1616.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801735b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171A1C();
typedef struct { u8 pad[170]; u16 a; u16 b; } T;
void func_801735B8(T *p) {
    p->b |= 64;
    p->a |= 64;
    func_80171A1C(p);
}
