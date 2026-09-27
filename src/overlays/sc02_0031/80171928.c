/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171928,8017196C).
 * Offset 0x497D0 at overlay base 80128158. SHA256(span)=5a853247f7d161379160f826f14cd29b985cb6003260335164255e2ef1dcb1dc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171928.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171A1C();
typedef struct {
    u8 pad[0x1F8]; s32 u1F8;
    s32 *u1FC;
    u8 pad200[0x14]; u8 u214;
} T;
void func_80171928(T *p) {
    p->u1F8 = p->u1FC[p->u214] | (p->u1F8 & 0x7F000000);
    func_80171A1C(p);
}
