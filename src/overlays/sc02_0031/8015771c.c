/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015771C,8015773C).
 * Offset 0x2F5C4 at overlay base 80128158. SHA256(span)=8d2d7fba10193f2840a200c82164b521dafe6c9ae893648aedb45697fac29966.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015771c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8015773C();
typedef struct { u8 pad[0x1AA]; u8 f; } T;
void func_8015771C(T *p) {
    p->f = 0;
    func_8015773C(p);
}
