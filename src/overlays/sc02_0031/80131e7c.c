/* SC02.CD FILE_031 / ov_SC02_031 retail span [80131E7C,80131EE4).
 * Offset 0x9D24 at overlay base 80128158. SHA256(span)=db892807018af6377fb97dd9a6217bbf7ac6b22a3ab248302960728094d9731f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80131e7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8012E470();
void func_8012E4C8();
void func_80131E00();
void func_80131CA8();
typedef struct { u8 pad[0xB4]; s32 uB4; } T;
void func_80131E7C(T *p) {
    if (p->uB4 & 0x40000) {
        if (func_8012E470(p)) {
            func_8012E4C8(p);
            func_80131E00(p, 1);
        }
    }
    func_80131CA8(p, 0x3A);
}
