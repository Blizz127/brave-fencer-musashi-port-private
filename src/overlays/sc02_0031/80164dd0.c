/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164DD0,80164E40).
 * Offset 0x3CC78 at overlay base 80128158. SHA256(span)=e8a53def3071ef38290d72f1c5a2128f7002dbbfe5b7c09ef1a03ddbe33ce57c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164dd0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80148534();
void func_80015954();
void func_80149374();
typedef struct {
    u8 pad[4]; s16 pad4; u8 pad6[4]; s16 uA;
    u8 padC[0x40]; void *u4C;
} T;
void func_80164DD0(T *p) {
    s16 a[4];
    s16 b[4];
    void *q = p->u4C;
    func_80148534(a, b);
    func_80015954(a, (u8 *)p + 4);
    func_80149374(q, (u8 *)p + 4);
    p->uA -= 0x40;
}
