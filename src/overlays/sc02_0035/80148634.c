/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148634 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80148634(void *a0) {
    *(u16 *)((s32)a0 + 0xAA) = 0;
    *(u16 *)((s32)a0 + 0xAC) = 0;
    *(u16 *)((s32)a0 + 0xAE) = 0x8080;
}
