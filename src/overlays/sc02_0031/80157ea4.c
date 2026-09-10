/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157EA4,80157F64).
 * Offset 0x2FD4C at overlay base 80128158. SHA256(span)=d003359fe39d381abf1d959f45ab41c716247a8b24504af6f3aede46562488e5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157ea4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801599A4();
void func_80159B3C();
s32 func_80157F64();
void func_80155FF8();
s16 *func_80156600();
void func_80146A6C();
typedef struct {
    u8 pad[0x44]; s32 flags;
    u8 pad48[0x70]; u16 b8;
    u8 padBA[0xF0]; u8 u1AA;
    u8 pad1AB[0x99]; s16 u244;
} T;
void func_80157EA4(T *p) {
    s16 *v;
    p->flags |= 2;
    if (p->b8 == 0x8000) {
        func_801599A4(p);
        func_80159B3C(p);
        return;
    }
    if (func_80157F64(p)) {
        return;
    }
    func_80155FF8(p, p->u1AA);
    v = func_80156600(p);
    if (v == 0) {
        return;
    }
    if (p->u244) {
        return;
    }
    p->u244 = 1;
    func_80146A6C(0x54, p, v[0], v[1], v[2], 0, 0);
}
