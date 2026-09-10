/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E9B8,8015EA3C).
 * Offset 0x36860 at overlay base 80128158. SHA256(span)=8544cdb0da4e05fbb2929d0e712165486b20e223f2984669ee1d9a8d7ccb8375.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e9b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80160818();
void func_80154150();
void func_80149034();
void func_801553A8();
s32 func_80149184();
void func_80146CA0();
extern u8 D_80078EC0;
extern s16 D_801152A0;
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_8015E9B8(T *p) {
    if (D_80078EC0 & 0x80) {
        func_80160818();
        return;
    }
    func_80154150(p, 0x1D);
    p->flags |= 1;
    func_80149034(p);
    func_801553A8(p);
    D_801152A0 = func_80149184(p);
    func_80146CA0(p);
}
