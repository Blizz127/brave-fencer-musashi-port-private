/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015773C,80157788).
 * Offset 0x2F5E4 at overlay base 80128158. SHA256(span)=3e0303712529cc93a98edcc4629307000d622035c90801fcd48eede1cb870b30.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015773c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154A74();
void func_801553C0();
void func_801553A8();
typedef struct {
    u8 pad_0[68];
    u32 flags;
} T;
void func_8015773C(T *p) {
    p->flags &= -3;
    func_80154A74(p, 17);
    func_801553C0(p);
    func_801553A8(p);
}
