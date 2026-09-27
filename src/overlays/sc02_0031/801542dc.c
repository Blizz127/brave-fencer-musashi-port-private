/* SC02.CD FILE_031 / ov_SC02_031 retail span [801542DC,8015430C).
 * Offset 0x2C184 at overlay base 80128158. SHA256(span)=23dcabe53be5cdca552d4649db53b460cb313fcc1d7b90a5c10b82d558204ad6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801542dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8015430C();
typedef struct { u8 pad[0xB4]; s32 b4; } T;
void func_801542DC(T *p, s32 a1) {
    if (p->b4 != a1) {
        func_8015430C(p, a1);
    }
}
