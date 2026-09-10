/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E1CC,8016E26C).
 * Offset 0x46074 at overlay base 80128158. SHA256(span)=5d26c9c3a12e9f10d94b3efb7b5fd50a0402ef7b7ad2b4b83b8a16629a94d8aa.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e1cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016E3CC();
void func_80146A6C();
typedef struct Inner { u8 pad[0x18]; s16 a, b; } Inner;
typedef struct { u8 pad[2]; s16 u2; u8 pad4[0x18]; s32 t; Inner *inner; } T;
void func_8016E1CC(T *p) {
    Inner *in = p->inner;
    func_8016E3CC(p);
    p->t--;
    if (p->t != 0) {
        func_80146A6C(0x48, p, 0, 0, 0, 0x8000, 0);
        in->a += 0x100;
        in->b += 0x140;
    } else {
        p->t = 0x20;
        p->u2++;
    }
}
