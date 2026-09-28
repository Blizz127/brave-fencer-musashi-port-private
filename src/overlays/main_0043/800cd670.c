/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD670 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800233CC(void *arg0, u16 arg1);

void func_800CD670(s32 arg0, void *arg1)
{
    s32 t;

    func_800233CC(arg1, 0x40);
    *(u8 *)(arg1 + 0) = 0;
    *(u8 *)(arg1 + 1) = 0;
    *(u8 *)(arg1 + 2) = 0;
    t = *(s16 *)(arg0 + 0x62) * 12;
    *(u8 *)(arg1 + 6) = 0;
    *(u8 *)(arg1 + 5) = t;
    *(u8 *)(arg1 + 4) = t;
}
