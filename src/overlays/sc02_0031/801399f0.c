/* SC02.CD FILE_031 / ov_SC02_031 retail span [801399F0,80139A34).
 * Offset 0x11898 at overlay base 80128158. SHA256(span)=20d7f3eee4937e63065a404f6a6729db355f111a4b017605c9825b8029bbde80.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801399f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct {
    void *u0;
    s16 u4;
    u8 pad6[0x19]; s8 u1F;
} T;
s32 func_801399F0(T *p) {
    if (p->u0 == 0 || p->u4 == 0 || p->u4 == 0xE) {
        return -1;
    }
    if (p->u4 != 0xD) {
        return 0;
    }
    return p->u1F;
}
