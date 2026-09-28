/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162834 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181CA4[])(void);

void func_80162834(void *a0) {
    D_80181CA4[*(u8 *)((s32)a0 + 0x1)]();
}
