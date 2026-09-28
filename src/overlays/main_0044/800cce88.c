/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCE88 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC


void func_800CCE88(s32 param_1) {
    s32 s2 = *(s32 *)(param_1 + 0x4C);
    s32 a0 = *(s32 *)(s2 + 0x20);
    s32 s1 = *(s32 *)(param_1 + 0x20);
    s32 s0 = s1 + 0x34;
    *(s16 *)(param_1 + 0x6) = *(s32 *)(a0 + 0x48);
    *(s16 *)(param_1 + 0xA) = *(s32 *)(a0 + 0x4C) - 0x20;
    *(s16 *)(param_1 + 0xE) = *(s32 *)(a0 + 0x50);
    func_80013F3C((void *)s0);
    RotMatrixY(*(s16 *)(s1 + 0x12), (void *)s0);
    func_80048D9C((void *)s0, (void *)(*(s32 *)(s2 + 0x20) + 0x34));
    func_80020F34(s0, s1 + 0x18);
    *(u16 *)(s1 + 0x2C) |= 1;
}
