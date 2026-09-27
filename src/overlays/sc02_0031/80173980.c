/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173980,801739D8).
 * Offset 0x4B828 at overlay base 80128158. SHA256(span)=77b78cf7a68c889af5d1295439765eaf54f70362d5e2a81505efd0a285e980ea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173980.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171A1C();
extern s16 D_80126B30;
typedef struct { u8 pad[0xAA]; u16 a, b; } T;
void func_80173980(T *p) {
    if (D_80126B30 == 0) {
        p->b |= 0x80;
        p->a |= 0x80;
    } else {
        p->b |= 0x10;
    }
    func_80171A1C(p);
}
