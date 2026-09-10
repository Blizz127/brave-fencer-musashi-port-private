/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160A28,80160A74).
 * Offset 0x388D0 at overlay base 80128158. SHA256(span)=a15a6f109b91ba48ca65ebb307de7ff6c5ac90e3e3e3f03216f707f2fdb93bc4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160a28.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801553C0();
void func_80154A74();
typedef struct { u8 pad_0[68]; u32 flags; } T;
void func_80160A28(T *p) {
    func_801553C0(p);
    p->flags &= -65;
    p->flags &= -2;
    func_80154A74(p, 17);
}
