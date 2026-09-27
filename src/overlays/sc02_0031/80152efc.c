/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152EFC,80152F44).
 * Offset 0x2ADA4 at overlay base 80128158. SHA256(span)=b4e0e0850664001251e336a14153896e02d9a233c0b4c827e284a10650c755e1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152efc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
s32 func_801536DC();
void func_80146CA0();
typedef struct { u8 pad[0xDE]; u8 a, b; } T;
void func_80152EFC(T *p) {
    func_80149020(p);
    if (func_801536DC(p) == 0) {
        p->a = 1;
        p->b = 0;
        func_80146CA0(p);
    }
}
