/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154218,80154274).
 * Offset 0x2C0C0 at overlay base 80128158. SHA256(span)=02c277c9895b4fde7e273dca2cd3510def43301999cd0df02712512d91e4200a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154218.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801549F8();
void func_80154418();
typedef struct {
    u8 pad[0xB0]; s32 *t; s32 b4; s16 b8, ba; u8 bc, bd;
    u8 padBE[0x1E]; u8 dc;
} T;
void func_80154218(T *p, s32 a1, u8 a2) {
    s32 v = p->t[a1];
    p->ba = 1;
    p->b8 = 1;
    p->bc = a2;
    p->bd = a2;
    p->b4 = v;
    p->dc = func_801549F8(p);
    func_80154418(p);
}
