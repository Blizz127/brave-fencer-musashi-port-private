/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80160A28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32, s32);

void func_80160A28(s32 a0) {
    s32 v0;
    func_801553C0(a0);
    v0 = *(s32 *)(a0 + 0x44);
    v0 &= ~0x40;
    v0 &= ~1;
    *(s32 *)(a0 + 0x44) = v0;
    func_80154A74(a0, 0x11);
}
