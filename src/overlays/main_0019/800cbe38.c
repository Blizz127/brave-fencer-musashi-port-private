/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBE38 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_800CBF80(void *a0);
extern void func_80146E90(s32 *a0, s32 a1);

void func_800CBE38(u8 *arg0)
{
    s16 w;
    s32 s2;

    s2 = *(s32 *)((u8 *)arg0 + 0x20);
    func_800CBF80(arg0);
    w = *(u16 *)(s2 + 0x18) - 0x600;
    if (w < 0x1000) {
        w = 0x1000;
        func_80146E90((s32 *)arg0, 0x10);
        *(u16 *)(arg0 + 0x60) = w;
        func_80146CA0(arg0);
    }
    *(u16 *)(s2 + 0x1A) = w;
    *(u16 *)(s2 + 0x18) = w;
}
