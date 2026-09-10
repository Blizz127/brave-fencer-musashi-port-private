/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F260,8015F2BC).
 * Offset 0x37108 at overlay base 80128158. SHA256(span)=2aba4b6eb2b4c366ffd1f3a23e0353c922bd8debc23d9ea89938333ba62ea365.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f260.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801553A8();
void func_80154A74();
void func_80149048();
typedef struct {
    u8 pad[0x44];
    u32 flags;
    u8 pad48[0xF6-0x48];
    s16 fF6;
} T;
void func_8015F260(T *p) {
    func_801553A8(p);
    func_80154A74(p, 0x11);
    p->flags &= -3;
    p->flags &= -2;
    func_80149048(p);
    p->fF6 = 0x1000;
}
