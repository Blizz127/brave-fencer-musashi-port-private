/* SC02.CD FILE_031 / ov_SC02_031 retail span [801735EC,80173648).
 * Offset 0x4B494 at overlay base 80128158. SHA256(span)=b8d619da6480954f46b7f22568d0abc45af20086e5a9ff503d30f5c3c51287d9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801735ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801477E8();
void func_80171A1C();
extern s16 D_80126B40;
extern s16 D_80126B32;
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_801735EC(T *p) {
    if (D_80126B40) {
        p->flags |= 0x40000;
    }
    func_801477E8(p, D_80126B32 << 16);
    func_80171A1C(p);
}
