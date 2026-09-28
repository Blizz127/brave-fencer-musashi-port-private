/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE44 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAE44(void *a0) {

    extern void (*D_800CB458[])(void);
    *(u32 *)((s32)a0 + 0x44) |= 8;
    D_800CB458[*(u8 *)((s32)a0 + 0x197)]();
}
