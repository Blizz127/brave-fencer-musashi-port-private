/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BF68 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8012BF68(void *a0) {
    *(u16 *)((s32)a0 + 0x5C) &= 0x7FFF;
}
