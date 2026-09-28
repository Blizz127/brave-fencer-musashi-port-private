/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80160DEC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80154A74(int, int);
extern void func_80154A74(s32, s32);

void func_80160DEC(u8 *a0) {
    *(s32 *)(a0 + 0x1AC) = 0;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = 0;
    func_801553C0((s32)a0);
    *(s32 *)(a0 + 0x44) = *(s32 *)(a0 + 0x44) & -0x181;
    func_80154A74((s32)a0, 0x11);
}
