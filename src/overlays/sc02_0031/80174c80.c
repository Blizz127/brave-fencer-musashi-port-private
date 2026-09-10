/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174C80,80174CB0).
 * Offset 0x4CB28 at overlay base 80128158. SHA256(span)=4676fc7d5f9f937d902ae3e715d7f5d61302d658d0422950b26315d5c4b7dd26.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174c80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80174CB0();
typedef struct { u8 pad[0xA0]; u16 f; } T;
void func_80174C80(T *p) {
    u16 v = (p->f - 0x16) & 0xFFF;
    p->f = v;
    func_80174CB0(p, v);
}
