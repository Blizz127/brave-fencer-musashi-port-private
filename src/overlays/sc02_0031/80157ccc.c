/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157CCC,80157D20).
 * Offset 0x2FB74 at overlay base 80128158. SHA256(span)=4cb91a9e7a139e8979194ea2d951ef833e8986505de01c8ef14645cf99ef1057.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157ccc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154A74();
void func_801553C0();
void func_801553A8();
typedef struct {
    u8 pad_0[68];
    u32 flags;
    u8 pad_48[0x223-0x48];
    u8 f223;
} T;
void func_80157CCC(T *p) {
    p->f223 = 16;
    p->flags &= -3;
    func_80154A74(p, 17);
    func_801553C0(p);
    func_801553A8(p);
}
