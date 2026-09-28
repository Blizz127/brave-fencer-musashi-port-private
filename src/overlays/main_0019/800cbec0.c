/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 a0);
extern void func_800CBF80(void *a0);
extern void func_800CBF60();
extern u16 D_800B99DA;

void func_800CBEC0(u8 *arg0)
{
    s32 s1;
    s32 w;
    s16 r;

    s1 = *(s32 *)((u8 *)arg0 + 0x20);
    if (func_80146E98((s32)arg0) != 0) {
        func_800CBF60(arg0);
        return;
    }
    func_800CBF80(arg0);
    w = *(u16 *)(arg0 + 0x60) - 0x100;
    *(u16 *)(arg0 + 0x60) = w;
    if (D_800B99DA & 1) {
        r = (s16)w / 2;
    } else {
        r = w;
    }
    *(u16 *)(s1 + 0x1A) = r;
    *(u16 *)(s1 + 0x18) = r;
}
