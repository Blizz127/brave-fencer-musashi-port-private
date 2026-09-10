/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164A74,80164ACC).
 * Offset 0x3C91C at overlay base 80128158. SHA256(span)=d5da36fdb2a5b311939ab45717c6ce17d84b255a2cc2900674dbbbd619e0516b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80164a74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80148534();
void func_80015954();
void func_80149374();
typedef struct { u8 pad[0x4C]; void *u4C; } T;
void func_80164A74(T *p) {
    s16 a[4];
    s16 b[4];
    void *q = p->u4C;
    func_80148534(a, b);
    func_80015954(a, (u8 *)p + 4);
    func_80149374(q, (u8 *)p + 4);
}
