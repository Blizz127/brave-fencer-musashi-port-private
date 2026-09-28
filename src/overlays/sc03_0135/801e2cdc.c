/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2CDC - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;
extern void func_800D2624(void);

void func_801E2CDC(void) {

    extern short D_800B9A02;
    extern u16 D_80115114;
    extern u16 D_80115112;
    u16 v0 = (*(u16 *)&D_800B9A02);
    u16 v1 = D_80115114;

    v0 ^= 0x1;

    if (v1 == v0) {
        func_800D2624();
    } else {
        D_80115112++;
    }
}
