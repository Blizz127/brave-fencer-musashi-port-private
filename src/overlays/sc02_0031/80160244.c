/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160244,801602A4).
 * Offset 0x380EC at overlay base 80128158. SHA256(span)=7f82185de7ff01dbb06d8ffd46e4f90ee3282e43dff8c84385bd29fc87d856dc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160244.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154150();
void func_80154A74();
void func_80146CA0();
void func_80161208();
typedef struct { u8 pad[0xB8]; u16 f; } T;
void func_80160244(T *p) {
    if (p->f == 0x8000) {
        func_80154150(p, 0x23);
        func_80154A74(p, 0x1B);
        func_80146CA0(p);
    } else {
        func_80161208(p);
    }
}
