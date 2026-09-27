/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016951C,80169584).
 * Offset 0x413C4 at overlay base 80128158. SHA256(span)=f7f5c86a1a1be2b64f35278b5a3fb0a7b44290adcad609814fa934c2e89ecb79.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016951c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80169584();
void func_800D22E4();
void func_80146C3C();
typedef struct { u8 pad[0x14]; s32 u14; u8 pad18[4]; s32 u1c; } T;
void func_8016951C(T *p) {
    s32 v = p->u1c;
    p->u1c = v + 1;
    if (v < 10) {
        func_80169584();
        func_800D22E4(p);
        p->u14 += 0x8000;
    } else {
        func_80146C3C(p);
    }
}
