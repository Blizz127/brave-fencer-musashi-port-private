/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164BA0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181D0C[])(void);

void func_80164BA0(void *a0) {
    D_80181D0C[*(u16 *)((s32)a0 + 0x2)]();
}
