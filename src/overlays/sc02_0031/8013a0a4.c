/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013A0A4,8013A164).
 * Offset 0x11F4C at overlay base 80128158. SHA256(span)=c3064f7562d2197a6bf2ea4b2fd03f748347a5116a56440094686c4e9036d6d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013a0a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80139A8C();
void func_80139B18();
typedef struct {
    u8 pad[4]; s16 u4;
    u8 pad6[2]; s32 u8;
    u8 padC[0xA]; u16 u16;
    u8 pad18[6]; u8 u1E;
    u8 pad1F[0xF]; s16 u2E;
} T;
void func_8013A0A4(T *p) {
    if (p->u1E == 0) {
        p->u1E = 4;
    } else {
        p->u1E += 5;
    }
    if (p->u1E >= 0xC) {
        p->u16 = (p->u16 + 1) % (p->u2E + 1);
        p->u1E = 0;
        if (p->u8 & 0x100) {
            p->u4 = 6;
        } else {
            p->u4 = 2;
        }
    }
    func_80139A8C(p);
    func_80139B18(p);
}
