/* SC02.CD FILE_031 / ov_SC02_031 retail span [801601E4,80160244).
 * Offset 0x3808C at overlay base 80128158. SHA256(span)=1dde0f473f4b3807f65c2e506cf06a63cc0cae35744d30ffcc068bb90e1e76b4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801601e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154150();
void func_80154A74();
void func_80146CA0();
void func_80161208();
typedef struct { u8 pad[0xB8]; u16 f; } T;
void func_801601E4(T *p) {
    if (p->f == 0x8000) {
        func_80154150(p, 0x22);
        func_80154A74(p, 0x1A);
        func_80146CA0(p);
    } else {
        func_80161208(p);
    }
}
