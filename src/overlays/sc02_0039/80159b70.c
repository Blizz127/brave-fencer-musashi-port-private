/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80159B70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_801818E0[])(void);

void func_80159B70(void *a0) {
    D_801818E0[*(u16 *)((s32)a0 + 0x2)]();
}
