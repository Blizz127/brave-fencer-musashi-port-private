/* SC02.CD FILE_031 / ov_SC02_031 retail span [80169FE0,8016A020).
 * Offset 0x41E88 at overlay base 80128158. SHA256(span)=50c24680d5777a282834017a8c9c8bc83c5579d9eaedf5a6caf2b8ea79848e48.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80169fe0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80128ED8();
void func_80146C3C();
typedef struct { u8 pad[0x20]; void *inner; } T;
void func_80169FE0(T *p) {
    if (func_80128ED8(p->inner, (u8 *)p + 0x24)) {
        func_80146C3C(p);
    }
}
