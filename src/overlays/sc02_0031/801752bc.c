/* SC02.CD FILE_031 / ov_SC02_031 retail span [801752BC,80175308).
 * Offset 0x4D164 at overlay base 80128158. SHA256(span)=bb858f465f697208551f6f3f2bad431df41f79f65f32166659ebaefe37d6f3de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801752bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801553A8();
void func_80154A74();
typedef struct {
    u8 pad_0[68];
    u32 flags;
    u8 pad_48[174];
    s16 fF6;
} T;
void func_801752BC(T *p) {
    p->fF6 = 4096;
    func_801553A8(p);
    func_80154A74(p, 17);
    p->flags &= -3;
}
