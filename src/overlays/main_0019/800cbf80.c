/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBF80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_800B99DA;
extern s32 D_800CC830;

void func_800CBF80(void *a0) {
    s32 v;

    v = 0xFF0000;
    if (!(D_800B99DA & 3)) {
        v = 0xFFFF;
    }
    D_800CC830 = v;
}
