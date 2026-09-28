/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBBB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBEB8(void);

void func_800CBBB8(void *arg0) {

    extern u8 D_80078EC1;
    extern void (*D_800CC030[])(void);
    if (D_80078EC1 == 0x1a) {
        u16 v0 = *(u16 *)((u8 *)arg0 + 2);
        D_800CC030[v0]();
    } else {
        func_800CBEB8();
    }
}
