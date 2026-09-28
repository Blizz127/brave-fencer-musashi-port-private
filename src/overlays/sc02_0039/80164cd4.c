/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164CD4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80164E40(void);

void func_80164CD4(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x20);
    u16 v1;
    func_80164E40();
    v1 = *(u16 *)(a0 + 0x60) + *(u16 *)(a0 + 0x62);
    *(u16 *)(a0 + 0x60) = v1;
    *(u16 *)(s0 + 0x1A) = *(u16 *)(s0 + 0x1A) + v1;
    *(u16 *)(s0 + 0x18) = *(u16 *)(s0 + 0x1A);
    if (*(s16 *)(a0 + 0x60) < 0) {
        func_80146CA0(a0);
    }
}
