/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E26C,8016E2E8).
 * Offset 0x46114 at overlay base 80128158. SHA256(span)=b093ceb5b4fc658124bda579c01aa73c71ccda264676ce7928ea721b0c1a1db8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e26c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016E3CC();
void func_80146A6C();
typedef struct { u8 pad[2]; s16 u2; u8 pad4[0x18]; s32 t; } T;
void func_8016E26C(T *p) {
    func_8016E3CC(p);
    p->t--;
    if (p->t != 0) {
        func_80146A6C(0x48, p, 0, 0, 0, 0x8000, 0);
    } else {
        p->t = 0x10;
        p->u2++;
    }
}
