/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151E78,80151ECC).
 * Offset 0x29D20 at overlay base 80128158. SHA256(span)=8e25c49b8c2379243f96df8cb326e5b5d14f5b390b6aed6d99d2560f7a9ecab0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151e78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80146CA0();
void func_80172630();
typedef struct { u8 pad[0xDE]; u8 uDE; } T;
void func_80151E78(T *p) {
    func_80149020(p);
    if (p->uDE-- == 0) {
        p->uDE = 0x10;
        func_80146CA0(p);
    }
    func_80172630(p);
}
