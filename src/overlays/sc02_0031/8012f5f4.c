/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F5F4,8012F68C).
 * Offset 0x749C at overlay base 80128158. SHA256(span)=af1e3713369234d96d66abbe8d747c4c9d3872a74f96415ce9fb3a9a92c19543.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f5f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80131B14();
void func_80131E00();
s32 func_80131A34();
void func_80131CA8();
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    u8 pad20[0x56]; s16 u76;
    u8 pad78[0x20]; s16 u98;
    u8 pad9A[0x27]; u8 uC1, uC2;
    u8 padC3; s32 uC4;
} T;
void func_8012F5F4(T *p) {
    p->uC1 = 1;
    if (p->uC4 & 2) {
        func_80131CA8(p, 3);
        return;
    }
    func_80131B14(p);
    if (p->u76 <= 0) {
        func_80131E00(p, 0xC);
        return;
    }
    if (func_80131A34(p, 4)) {
        p->uC2 = 0;
    } else {
        p->u98 = 0;
        p->uC2 = 1;
        p->u1C = 0x10;
    }
    func_80131CA8(p, 3);
}
