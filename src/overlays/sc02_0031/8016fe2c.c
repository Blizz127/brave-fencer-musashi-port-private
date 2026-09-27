/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FE2C,8016FE78).
 * Offset 0x47CD4 at overlay base 80128158. SHA256(span)=2341240524aa161bc2d3a60bc01d479e869d9c377251c096d7b90e9464d9c35a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fe2c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80172658();
void func_80171990();
typedef struct { u8 pad[0xAA]; u16 a, b; } T;
void func_8016FE2C(T *p) {
    if (func_80172658(p)) {
        p->b |= 0x40;
        p->a |= 0x40;
        func_80171990(p);
    }
}
