/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801472B4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801472B4(void *a0) {
    *(u16 *)((s32)a0 + 0x7E) &= 0xFFFD;
}
