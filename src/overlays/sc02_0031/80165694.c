/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165694,801656D0).
 * Offset 0x3D53C at overlay base 80128158. SHA256(span)=3de3cbc9ceed77e0328d8715d6716d9711f231be62239daf8e884599bc74c747.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165694.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80078EC8;
typedef struct { u8 pad[0x1F8]; s32 u1F8; } T;
void func_80165694(T *p) {
    if ((p->u1F8 & 0x80FFFFFF) == 0 && D_80078EC8) {
        D_80078EC8 = D_80078EC8 - 1;
    }
}
