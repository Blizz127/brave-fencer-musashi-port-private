/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154274,801542A4).
 * Offset 0x2C11C at overlay base 80128158. SHA256(span)=82d430b1cad67f8aa626804490cfbe2270f0b9f87ca1aa3c22f7c4bb126efd59.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154274.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801542A4();
typedef struct { u8 pad[0xB4]; s32 b4; } T;
void func_80154274(T *p, s32 a1) {
    if (p->b4 != a1) {
        func_801542A4(p, a1);
    }
}
