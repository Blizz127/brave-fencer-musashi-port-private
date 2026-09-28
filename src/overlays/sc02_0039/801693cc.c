/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801693CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80182118[])(void);

void func_801693CC(void *a0) {
    D_80182118[*(u16 *)((s32)a0 + 0x2)]();
}
