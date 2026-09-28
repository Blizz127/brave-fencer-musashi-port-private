/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE5C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAE5C(void *a0) {

    extern void (*D_800CBE7C[])(void);
    *(u32 *)((s32)a0 + 0x44) |= 8;
    D_800CBE7C[*(u8 *)((s32)a0 + 0x197)]();
}
