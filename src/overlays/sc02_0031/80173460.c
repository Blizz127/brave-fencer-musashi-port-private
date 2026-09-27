/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173460,801734BC).
 * Offset 0x4B308 at overlay base 80128158. SHA256(span)=d05d1dfe7ebc34358953f46e1ebc87fcf88bbb9418216055ea2bca33059436d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173460.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { s16 x, y, z, pad; } S;
extern S D_80126B38;
void func_801734BC();
void func_80173460(void *p, S *q) {
    func_801734BC(p);
    D_80126B38 = *q;
    D_80126B38.pad = 1;
}
