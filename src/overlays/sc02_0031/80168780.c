/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168780,801687CC).
 * Offset 0x40628 at overlay base 80128158. SHA256(span)=8d0a6a092ea1277f24d3e1132a05917a0e928c8320dff713de379f962c112283.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168780.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80168BDC();
void func_801687CC();
typedef struct { u16 a, b; } T;
void func_80168780(T *p) {
    func_80168BDC(p, 8, 0, 2);
    func_801687CC(p);
    p->b += 1;
}
