/* SC02.CD FILE_031 / ov_SC02_031 retail span [80130278,80130314).
 * Offset 0x8120 at overlay base 80128158. SHA256(span)=464edec72f197a55b1fcb8d5500698f0436cf94d108c085237dea266f8d8a833.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80130278.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80131170();
s32 func_80131CA8();
void func_80131E00();
typedef struct {
    u8 pad[0xB4]; s32 uB4;
    u8 padB8[9]; u8 uC1;
    u8 padC2[2]; s32 uC4;
} T;
void func_80130278(T *p) {
    s32 s1 = 0;
    p->uC1 = 0xB;
    if (p->uC4 & 1) {
        func_80131E00(p, 0xE);
        return;
    }
    if (p->uB4 & 0x800) {
        func_80131170(p, 0, 0);
        s1 = 1;
    }
    if (func_80131CA8(p, 0x2C)) {
        s1 = 1;
    }
    if (s1 == 0) {
        func_80131E00(p, 6);
    }
}
