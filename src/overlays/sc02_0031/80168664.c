/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168664,80168744).
 * Offset 0x4050C at overlay base 80128158. SHA256(span)=fe3a878b894bafa188d170c720151a21db2d02ec54690ae7c1feaaf4e53dc223.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168664.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80049F3C();
void func_80048EAC();
void func_801670E4();
typedef struct { s32 a, b, c, d, e, f, g, h; } M;
extern M D_800AE620;
typedef struct { u8 pad[0x20]; u8 *inner; } Q;
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0xC]; u16 u10, u12;
    u8 pad14[8]; s32 u1C;
    u8 pad20[0x10]; s32 u30;
    Q *u34;
    M m;
} T;
void func_80168664(T *p) {
    Q *q = p->u34;
    p->u1C = 0x20;
    p->u10 = 0x80;
    p->u12 = 0;
    p->u30 = 0x1800;
    p->m = D_800AE620;
    func_80049F3C(0x400, &p->m);
    func_80048EAC(q->inner + 0x34, &p->m);
    func_801670E4(p, -6, -0x44, -0x18);
    p->u2 = p->u2 + 1;
}
