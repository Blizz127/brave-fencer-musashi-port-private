/* SC02.CD FILE_031 / ov_SC02_031 retail span [80133060,801330E0).
 * Offset 0xAF08 at overlay base 80128158. SHA256(span)=45f95579d65472d3c3998dddcba375b41bcac46cff5ffacb786afc394bd5e2e6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80133060.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801330E0();
typedef struct { s32 x, y, z; } V;
void func_80133060(s16 *p, V *q, s32 a2) {
    s16 tmp[3];
    tmp[0] = p[1];
    tmp[1] = p[3];
    tmp[2] = p[5];
    func_801330E0(tmp, tmp, (s16)a2);
    q->x = tmp[0] << 16;
    q->y = tmp[1] << 16;
    q->z = tmp[2] << 16;
}
