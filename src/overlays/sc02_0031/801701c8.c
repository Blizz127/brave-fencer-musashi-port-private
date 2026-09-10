/* SC02.CD FILE_031 / ov_SC02_031 retail span [801701C8,80170240).
 * Offset 0x48070 at overlay base 80128158. SHA256(span)=485604e7b70fd9c92e481de6f91aa3f90a39bdaa6e25fc35e41344cfdabd7159.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801701c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80012B04();
void func_80171928();
extern s16 D_8011F738;
typedef struct Inner { u8 pad[0x12]; s16 a; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_801701C8(T *p) {
    s32 d = func_80012B04(p->inner->a, D_8011F738, 4);
    if ((s16)d == 0) {
        func_80171928(p);
    }
    p->inner->a = (p->inner->a + d) & 0xFFF;
}
