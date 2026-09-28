/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD834 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CD834(void *a0) {
    s32 v0 = *(s32 *)((s32)a0 + 0x20);
    *(s16 *)(v0 + 0x18) = *(s16 *)(v0 + 0x1A) = 0;
}
