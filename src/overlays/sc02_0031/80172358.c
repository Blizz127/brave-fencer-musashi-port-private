/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172358,801723C4).
 * Offset 0x4A200 at overlay base 80128158. SHA256(span)=29e6be43b2991cb20320bff3558bba4503861d4808e5195d89a9f851c0096aca.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172358.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
typedef struct { u16 x, y, z; } H;
typedef struct {
    u8 pad[6];
    u16 a;
    u8 pad8[2];
    u16 b;
    u8 padC[2];
    u16 c;
    u8 padE[0x88-0x10];
    S s88;
    S s90;
} T;
void func_80172358(T *p, H *q) {
    p->a = q->x;
    p->b = q->y;
    p->c = q->z;
    p->s90 = *(S *)q;
    p->s88 = p->s90;
}
