/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158548,801585A4).
 * Offset 0x303F0 at overlay base 80128158. SHA256(span)=9d133c7ee5234df3ca29f56be1643562d818dc5bff8ad85ffc1906c7ab54f4bc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158548.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801599A4();
void func_80159B3C();
void func_80161208();
typedef struct { u8 pad[0x44]; s32 flags; u8 pad48[0x70]; u16 f; } T;
void func_80158548(T *p) {
    p->flags |= 2;
    if (p->f & 0x8000) {
        func_801599A4(p);
        func_80159B3C(p);
    } else {
        func_80161208(p);
    }
}
