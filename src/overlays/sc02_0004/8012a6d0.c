/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A6D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 func_80047D3C(s32 a0);
extern s32 ratan2(s32 a0, s32 a1);

s32 func_8012A6D0(void* a0, void* a1)
{
    s32 s0 = a0;
    s32 s1 = a1;
    s32 dy = *(s16 *)(s0 + 0x4) - *(s16 *)(s1 + 0x4);
    s32 dx = *(s16 *)(s0 + 0x0) - *(s16 *)(s1 + 0x0);
    s32 d;
    d = func_80047D3C(dy * dy + dx * dx);
    return (s16)ratan2(*(s16 *)(s0 + 0x2) - *(s16 *)(s1 + 0x2), (s16)d);
}
