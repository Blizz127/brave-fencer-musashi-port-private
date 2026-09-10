/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165064,801650C4).
 * Offset 0x3CF0C at overlay base 80128158. SHA256(span)=cc0cb54e291320a5d4d4717ec81d6cbb8726bb772e775eecc7bcd02c81a3126e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165064.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146CA0();
void func_80165124();
void func_801651B8();
typedef struct { u8 pad[0x62]; s16 u62; } T;
void func_80165064(T *p) {
    s16 v = p->u62 + 16;
    p->u62 = v;
    if (v >= 256) {
        p->u62 = 255;
        func_80146CA0(p);
    }
    func_80165124(p);
    func_801651B8(p);
}
