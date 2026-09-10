/* SC02.CD FILE_031 / ov_SC02_031 retail span [801619D0,80161A00).
 * Offset 0x39878 at overlay base 80128158. SHA256(span)=c10f9f7068306da70fe8022caa7f7ed835d5627813998edeb79e3f9ba06764f0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801619d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80078EC0;
typedef struct { u8 pad[0x1C8]; s16 u1C8; } T;
s32 func_801619D0(T *p) {
    if (p->u1C8) {
        return (D_80078EC0 & 0x7F) == 3;
    }
    return 0;
}
