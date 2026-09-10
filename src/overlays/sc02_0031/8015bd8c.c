/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BD8C,8015BDD0).
 * Offset 0x33C34 at overlay base 80128158. SHA256(span)=4ebabc071ea817185d3c396cefde9a13df1978a54c9fcb1b670a3bd7a7897107.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bd8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801553A8();
void func_80154A74();
typedef struct {
    u8 pad_0[68];
    u32 flags;
} T;
void func_8015BD8C(T *p) {
    func_801553A8(p);
    func_80154A74(p, 17);
    p->flags &= -3;
}
