/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E40C,8015E4B0).
 * Offset 0x362B4 at overlay base 80128158. SHA256(span)=aae7b5ccea1320e9c9f79660205bb7c43e5986251a0c622fb4fdf3c57b18f2ee.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e40c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80148534();
void func_80149374();
typedef struct Inner { u8 pad[0xC]; u16 c, e, ten; } Inner;
typedef struct {
    u16 kind; u8 pad2[2]; s16 pad4; s16 u6; u8 pad8[2]; s16 uA; u8 padC[2]; s16 uE;
    u8 pad10[0x68]; Inner *p78;
} U;
typedef struct { u8 pad[0x18C]; U *u18C; } T;
void func_8015E40C(T *p) {
    s16 a[4];
    s16 b[4];
    U *q = p->u18C;
    if (q != 0 && q->kind != 0) {
        func_80148534(a, b);
        q->u6 = b[0] + q->p78->c;
        q->uA = b[1] + q->p78->e;
        q->uE = b[2] + q->p78->ten;
        func_80149374(p, (u8 *)q + 4);
    }
}
