/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BF50,8016BFA8).
 * Offset 0x43DF8 at overlay base 80128158. SHA256(span)=751fdee7319faff357bf3b3134d29d9883c72ad27b9e68c9602cf4b3e9312fbb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016bf50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149350();
void func_80015954();
typedef struct {
    u8 pad[0x12]; s16 u12;
    u8 pad14[2]; s16 u16;
    u8 pad18[2]; s16 u1A;
    u8 pad1C[0x18]; void *u34;
} T;
void func_8016BF50(T *p) {
    s16 v[4];
    void *m = p->u34;
    v[0] = p->u12;
    v[1] = p->u16;
    v[2] = p->u1A;
    func_80149350(m, v, v);
    func_80015954(v, (u8 *)p + 4);
}
