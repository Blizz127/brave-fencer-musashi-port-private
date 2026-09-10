/* SC02.CD FILE_031 / ov_SC02_031 retail span [801305CC,80130650).
 * Offset 0x8474 at overlay base 80128158. SHA256(span)=497342549df51509d656ec8a03689accee5d7413b2a14b524e0cf77c69c60027.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801305cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80131A34();
void func_80131CA8();
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    u8 pad20[0x78]; s16 u98;
    u8 pad9A[0x1A]; s32 uB4;
    u8 padB8[9]; u8 uC1;
    u8 padC2[2]; s32 uC4;
} T;
void func_801305CC(T *p) {
    p->uC1 = 0xC;
    if (p->uB4 & 0x1000) {
        p->u1C = 0x3C;
        p->uC4 &= -5;
        if (func_80131A34(p, 0x20)) {
            p->uC4 |= 4;
        } else {
            p->u98 = 0;
        }
    }
    func_80131CA8(p, 0x22);
}
