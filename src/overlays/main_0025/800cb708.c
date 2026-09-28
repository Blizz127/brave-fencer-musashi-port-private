/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB708 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80162CCC();
extern s32 func_80146E98(s32 a0);

void func_800CB708(void *a0) {
    if (func_80146E98((s32)a0) != 0) {
        func_80162CCC(a0);
        return;
    }
    *(u16 *)((s32)a0 + 0xA) += 2;
}
