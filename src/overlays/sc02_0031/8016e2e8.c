/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E2E8,8016E358).
 * Offset 0x46190 at overlay base 80128158. SHA256(span)=9cf1ecf73699eb8d35160b98901bbb97999c2c59b5798965ee52e7cbd272ff0f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e2e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016E3CC();
void func_80146C3C();
typedef struct Inner { u8 pad[0x18]; s16 a, b; } Inner;
typedef struct { u8 pad[0x1C]; s32 t; Inner *inner; } T;
void func_8016E2E8(T *p) {
    Inner *in = p->inner;
    func_8016E3CC(p);
    p->t--;
    if (p->t != 0) {
        in->a -= 0x100;
        in->b -= 0x120;
    } else {
        func_80146C3C(p);
    }
}
