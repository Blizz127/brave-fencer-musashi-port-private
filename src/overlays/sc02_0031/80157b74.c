/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157B74,80157BC8).
 * Offset 0x2FA1C at overlay base 80128158. SHA256(span)=bd58fa93d676cce3b5c5d32877df358e330426ec24dc9e82faece2d45f35190d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157b74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801599A4();
void func_80159B3C();
void func_80161208();
typedef struct { u8 pad[0xB8]; u16 f; } T;
void func_80157B74(T *p) {
    if (p->f == 0x8000) {
        func_801599A4(p);
        func_80159B3C(p);
    } else {
        func_80161208(p);
    }
}
