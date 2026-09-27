/* SC02.CD FILE_031 / ov_SC02_031 retail span [801683D8,80168430).
 * Offset 0x40280 at overlay base 80128158. SHA256(span)=4f29d729baabea89036f9ed6eddce7565e7457df57b5c6e4b7243e0903a814ca.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801683d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80166994();
s32 func_80166690();
void func_80146C3C();
typedef struct { u8 pad[0x28]; s16 a; u8 pad2A[2]; s16 b; } T;
void func_801683D8(T *p) {
    func_80166994(p, 2, p->b, 0);
    if ((s16)func_80166690(p->b, p->a) == 0) {
        func_80146C3C(p);
    }
}
