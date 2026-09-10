/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168AE4,80168B70).
 * Offset 0x4098C at overlay base 80128158. SHA256(span)=a2dbe0f71d1873558b4da8cd9dac55e7dcbb6f690e81102a4631ed910b34760e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168ae4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80168BDC();
void func_80146A6C();
typedef struct { s16 a, b; u8 pad4[0x18]; s32 u1c; } T;
void func_80168AE4(T *p) {
    func_80168BDC(p, 9, 3, 2);
    func_80168BDC(p, 9, 2, 1);
    func_80146A6C(3, p, ((s16 *)p)[3], ((s16 *)p)[5], ((s16 *)p)[7], -5, 0xC0009C00);
    p->u1c = 1;
    p->b++;
}
