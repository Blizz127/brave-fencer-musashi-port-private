/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168B70,80168BDC).
 * Offset 0x40A18 at overlay base 80128158. SHA256(span)=3853f87d5db961f4b971d01b213ad4a24a7222964da67a0056fd245cf304dac5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168b70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80168BDC();
void func_80146C3C();
typedef struct { u8 pad[0x1C]; s32 t; } T;
void func_80168B70(T *p) {
    p->t--;
    if (p->t != -1) {
        func_80168BDC(p, 9, 3, 1);
    } else {
        func_80168BDC(p, 9, 2, 1);
        func_80146C3C(p);
    }
}
