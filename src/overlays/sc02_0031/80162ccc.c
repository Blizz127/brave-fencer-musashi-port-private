/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162CCC,80162D28).
 * Offset 0x3AB74 at overlay base 80128158. SHA256(span)=b9c604c87d723b19bc300a1453a69ef97983918ec72e5dec6fa67ad21953bf56.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162ccc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80016714();
typedef struct { u16 kind; } Inner;
typedef struct { u8 pad[0x20]; Inner *inner; } T;
void func_80162CCC(T *p) {
    if (p->inner) {
        func_80016714(p->inner, p->inner->kind == 1 ? 0x84 : 0x38);
    }
    func_80016714(p, 0x68);
}
