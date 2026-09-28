/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB30C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB358(void);

void func_800CB30C(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x20);
    s16 v = *(u16 *)(p + 0x1A) - 0x300;
    *(u16 *)(p + 0x1A) = v;
    *(u16 *)(p + 0x18) = v;
    if (v < 0) {
        ((void (*)(s32))func_800CB358)(a0);
    }
}
