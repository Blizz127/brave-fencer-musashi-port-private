/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165BFC,80165C58).
 * Offset 0x3DAA4 at overlay base 80128158. SHA256(span)=2619bd2a8c94798365122ec3c81adec5061772228f5768340c25d2d5ff0cebcd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165bfc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161208();
void func_80165C58();
void func_801599A4();
void func_80159B3C();
typedef struct { u8 pad[0xB8]; u16 f; } T;
void func_80165BFC(T *p) {
    if (func_80161208(p) == 0 && (p->f & 0x8000)) {
        func_80165C58(p);
        func_801599A4(p);
        func_80159B3C(p);
    }
}
