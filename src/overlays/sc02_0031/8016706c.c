/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016706C,801670E4).
 * Offset 0x3EF14 at overlay base 80128158. SHA256(span)=18fc729174a54e8d10762126e3d3659fa4585811110d0a02f8c3cfc9a827a99d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016706c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146C3C();
typedef struct { u16 id; u8 pad[0x56]; } S;
extern S D_8011D030[];
void func_8016706C(s16 id) {
    s16 i = 0;
    S *s = D_8011D030;
    for (; i < 0x1E; i++, s++) {
        if (s->id == id) {
            func_80146C3C(s);
        }
    }
}
