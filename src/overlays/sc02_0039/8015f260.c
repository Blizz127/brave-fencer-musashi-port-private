/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F260 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149048(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32, s32);

void func_8015F260(s32 *a0) {
    s32 v;
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    v = a0[0x11];
    v &= -0x3;
    v &= -0x2;
    a0[0x11] = v;
    func_80149048(a0);
    *(s16 *)((u8 *)a0 + 0xF6) = 0x1000;
}
