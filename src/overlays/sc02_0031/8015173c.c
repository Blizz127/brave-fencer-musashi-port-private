/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015173C,80151780).
 * Offset 0x295E4 at overlay base 80128158. SHA256(span)=e12301285dbfe740e0f90fe08b7a6910bebe15ff65bb64756de46772bf9fcc72.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015173c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014C8F0();
void func_80147078();
void func_80151780();
typedef struct {
    u16 f0;
    u8 pad_2[220];
    u8 fDE;
} T;
void func_8015173C(T *p) {
    func_8014C8F0(p);
    p->fDE = (u8) p->f0;
    func_80147078(p, 25);
    func_80151780(p);
}
