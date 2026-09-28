/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173B4C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_801812FC[])(void);

void func_80173B4C(void *a0) {
    D_801812FC[*(u8 *)((s32)a0 + 0x214)]();
}
