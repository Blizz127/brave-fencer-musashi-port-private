/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E728,8016E778).
 * Offset 0x465D0 at overlay base 80128158. SHA256(span)=6c78f27465f36b6ba62da57935256230dad239de3854736ed04a7b3e7ca2433d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e728.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146C3C();
void func_8016E778();
typedef struct { u8 pad[0x12]; u16 a; u8 pad14[2]; s16 b; } T;
void func_8016E728(T *p) {
    p->a += 0x400;
    p->b -= 8;
    if (p->b <= 0) {
        func_80146C3C(p);
    } else {
        func_8016E778(p);
    }
}
