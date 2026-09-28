/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148D24 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80148D24(void *a0, int a1) {
    int p = *(int *)((char *)a0 + 0x20);
    *(short *)(p + 0x12) = (a1 - 0x800) & 0xFFF;
    return 1;
}
