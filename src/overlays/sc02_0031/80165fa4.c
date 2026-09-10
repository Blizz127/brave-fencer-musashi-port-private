/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165FA4,80166018).
 * Offset 0x3DE4C at overlay base 80128158. SHA256(span)=81f495dda49f3a40bbf8b781f0b22848cfa1ac171e6e4d912469af14baad94a3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165fa4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80013F3C();
void func_80020F34();
void func_80048FBC();
typedef struct { u8 pad[0x20]; u8 *inner; } T;
void func_80165FA4(T *p, void *a1, void *a2) {
    s16 mtx[16];
    func_80013F3C(mtx);
    func_80020F34(mtx, p->inner + 0x18);
    func_80048FBC(mtx, a1, a1);
    func_80048FBC(mtx, a2, a2);
}
