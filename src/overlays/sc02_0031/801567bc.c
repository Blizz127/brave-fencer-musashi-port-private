/* SC02.CD FILE_031 / ov_SC02_031 retail span [801567BC,80156848).
 * Offset 0x2E664 at overlay base 80128158. SHA256(span)=e28d8092d0bb074dabc3c1effa7aff62320fc6b27ff9ffff14ac94e84e2d6985.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801567bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8014C568();
extern s32 D_801151E0[];
extern s32 D_8011DAD8[];
typedef struct { u8 pad[0x12]; s16 u12; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_801567BC(T *p) {
    u32 i;
    for (i = 0; i < 3; i++) {
        if (D_801151E0[i] & 1) {
            p->inner->u12 = func_8014C568(p, &D_8011DAD8[i * 2]);
        }
    }
}
