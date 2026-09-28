/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80180E64[])(void);

void func_80164EA4(void *a0) {
    D_80180E64[*(u16 *)((s32)a0 + 0x2)]();
}
