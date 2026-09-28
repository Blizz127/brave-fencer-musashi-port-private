/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC298 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CC298(void *a0) {

    extern u8 D_80078EC1;
    extern void (*D_800CCA24[])(void *);
    extern void func_800CC6A4();
    extern void func_800CC968(void *a0);
    extern void func_800CC9AC(void *a0);
    if (D_80078EC1 != 0x10) {
        func_800CC6A4();
    } else {
        func_800CC968(a0);
        func_800CC9AC(a0);
        D_800CCA24[*(u16 *)((s32)a0 + 0x2)](a0);
    }
}
