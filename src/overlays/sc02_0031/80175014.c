/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175014,8017509C).
 * Offset 0x4CEBC at overlay base 80128158. SHA256(span)=7945687738986a1d4ff367f59c1cf379a7ee4ab4fc305fde037dd72b5482e98f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175014.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { s16 a, b, c, d, e, f, g; } S;
typedef struct {
    u8 pad[0x3C]; s32 u3C, u40, u44, u48, u4C, u50, u54;
} T;
s32 func_80175014(T *p, S *tab, s32 idx) {
    S *s = (S *)((u8 *)tab + (s16)idx * 14);
    if (s->g == 0x7FFF) {
        return 1;
    }
    p->u3C = s->a;
    p->u40 = s->b;
    p->u44 = s->c;
    p->u48 = s->d;
    p->u4C = s->e;
    p->u50 = s->f;
    p->u54 = s->g << 5;
    return 0;
}
