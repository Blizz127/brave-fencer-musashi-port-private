/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016D5EC,8016D64C).
 * Offset 0x45494 at overlay base 80128158. SHA256(span)=a169b503007cc316306e76312d479dbe3e4f8cd410936e367970a8ffc7e835bf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016d5ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8016CF04();
void func_80146C3C();
typedef struct Inner { u8 pad[0x18]; u16 a, b; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_8016D5EC(T *p) {
    Inner *in = p->inner;
    in->a -= 0x60;
    in->b -= 0x60;
    if (func_8016CF04(p, 2) << 16) {
        func_80146C3C(p);
    }
}
