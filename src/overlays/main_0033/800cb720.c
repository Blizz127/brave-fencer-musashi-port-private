/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB720 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);

void func_800CB720(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x20);
    s16 x = *(u16 *)(p + 0x1A) - 0x300;
    *(u16 *)(p + 0x1A) = x;
    *(u16 *)(p + 0x18) = x;
    if (x < 0) {
        ((void (*)(void *))func_80146C3C)(arg0);
    }
}
