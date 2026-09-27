/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151F38,80151FB4).
 * Offset 0x29DE0 at overlay base 80128158. SHA256(span)=b65a3ec89e629583f5354bfb6bcd643fda8248d0cf8ec26aaea71f596e7ec204.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151f38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80151FB4();
void func_80159B3C();
void func_80165718();
void func_80172630();
typedef struct { u8 pad[0x64]; s16 u64; u8 pad66[0x78]; u8 de; } T;
void func_80151F38(T *p) {
    func_80149020(p);
    p->u64 -= p->de << 6;
    p->de += 8;
    if (p->u64 < 0x1000) {
        func_80151FB4(p);
        func_80159B3C(p);
        func_80165718(p);
    } else {
        func_80172630(p);
    }
}
