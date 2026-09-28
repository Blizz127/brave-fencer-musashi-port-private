/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFE8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAFE8(void *arg0) {

    extern u8 D_80078EC1;
    extern void (*D_800CB8BC[])(void);
    extern void func_800CB3A4(void);
    extern void func_800CB384(void);
    if (D_80078EC1 == 0xb) {
        D_800CB8BC[*(u16 *)((s32)arg0 + 2)]();
        ((void (*)(s32))func_800CB3A4)(arg0);
    } else {
        ((void (*)(s32))func_800CB384)(arg0);
    }
}
