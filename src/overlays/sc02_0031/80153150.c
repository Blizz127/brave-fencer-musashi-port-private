/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153150,801531BC).
 * Offset 0x2AFF8 at overlay base 80128158. SHA256(span)=28fd7c08f3b6b2a5a13835e6048a1283a4087af7d184f1936c6e1c052e2019d6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_801470B4();
void func_8015369C();
void func_80146CA0();
typedef struct {
    u8 pad[0x60]; s16 a, b, c;
    u8 pad66[0x78]; u8 de;
} T;
void func_80153150(T *p) {
    s16 v;
    func_80149020(p);
    v = p->c - 0x100;
    p->c = v;
    p->b = v;
    p->a = v;
    if (v <= 0) {
        p->de = 0x10;
        func_801470B4(p);
        func_8015369C(p);
        func_80146CA0(p);
    }
}
