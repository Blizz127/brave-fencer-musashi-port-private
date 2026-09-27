/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E28C,8012E32C).
 * Offset 0x6134 at overlay base 80128158. SHA256(span)=188ac574d0b148b6b66ad16e4ca6bae4c0b1db1e906f5262083330221f36a64b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e28c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void *func_80010A08();
s32 func_80058B40();
void func_8005A600();
void func_80058C6C();
extern u16 D_800B9A02;
typedef struct { u8 *p; u8 pad[16]; } Slot;
extern Slot D_800A651C[];
void func_8012E28C(s32 n, void *src) {
    u8 *slot;
    void *tmp;
    s32 v;
    if (n <= 0) {
        return;
    }
    slot = D_800A651C[D_800B9A02].p + n * 4;
    tmp = func_80010A08(0xC);
    v = func_80058B40(0, src, 0, 0);
    func_8005A600(tmp, 0, 0, (u16)v, 0);
    func_80058C6C(slot, tmp);
}
