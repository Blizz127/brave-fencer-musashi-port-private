/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E410,8013E448).
 * Offset 0x162B8 at overlay base 80128158. SHA256(span)=5747f55c211b729438027f8db9372596b483e2569b430901eca2ef51c0e21a12.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e410.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_801202A0[];
typedef struct { u16 id; u8 pad[0x10A]; } S;
S *func_8013E410(void) {
    S *s;
    s32 i;
    s = (S *)D_801202A0;
    for (i = 0; i < 0x60; i++, s++) {
        if (s->id == 0) {
            return s;
        }
    }
    return 0;
}
