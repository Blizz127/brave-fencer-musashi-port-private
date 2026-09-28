/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801292C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);

void func_801292C8(u8 *a0) {
    u16 *p = *(u16 **)(a0 + 0x20);
    if (p != 0) {
        func_80016714(p, (p[0] == 1) ? 0x84 : 0x38);
    }
    *(s16 *)a0 = 0;
}
